#pragma once
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <memory>
#include <algorithm>
class Cache{
public:
    class Entry {
    public:
        enum class State {
            FULL,
            PART,
            IN_PROCESS
        };
    private:
        State state;
        size_t size;
        std::vector<char> data;
    public:
        Entry(size_t maxEntrySize) : state(State::IN_PROCESS), size(0), data(maxEntrySize) {
        }
        State getState() const {
            return state;
        }
        State append(const std::vector<char>& newData, size_t offset, size_t size) {
            if (state == State::IN_PROCESS) {
                ptrdiff_t addOffset = 0;
                if (offset < this->size) {
                    if (offset + size < this->size) {
                        return State::IN_PROCESS;
                    } else {
                        addOffset = this->size - offset;
                    }
                } else if (offset > this->size) {
                    return state = State::PART;
                }
                std::copy_n(newData.begin() + addOffset, size - addOffset, data.begin() + offset);
            } else {
                return state;
            }
        }

        void setComplete() {
            state = State::FULL;
        }
    };
private:
    size_t cacheSize = 1024;
    size_t insertPosition = 0;
    size_t maxEntrySize = 65536;
    std::unordered_map<std::string, std::shared_ptr<Entry>> cache;
    std::vector<std::string>requests;
public:
    Cache() : requests(cacheSize){
    }
    std::shared_ptr<Entry> get(std::string request) {
        auto entry = cache.find(request);
        if (entry == cache.end()) {
            cache.erase(requests[insertPosition]);
            requests[insertPosition] = request;
            return cache[request];
        } else {
            return entry->second;
        }
    }

};

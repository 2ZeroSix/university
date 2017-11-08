#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
typedef struct _ListNode {
    char* data;
    struct _ListNode* next;
} ListNode;

ListNode* initListNode() {
    ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
    return node;
}

void freeListNode(ListNode* node) {
    if (!node) return;
    free(node);
}

typedef struct _List {
    ListNode* head;
    ListNode* tail;
} List;

List* initList() {
    List* list = (List*)calloc(1, sizeof(List));
    return list;
}

void pushList(List* list, char* data) {
    if (!list)                                      return;
    if (!list->head) {
        list->head = list->tail = initListNode();
    } else {
        list->tail = list->tail->next = initListNode();
    }
    list->tail->data = data;
    pthread_mutex_unlock(&(list->mutex));
}

char* popList(List* list) {
    if (!list)                                      return NULL;
    if (!list->head)                                return NULL;
    char* retVal = list->head->data;
    ListNode* tmp = list->head;
    if (list->head == list->tail) list->tail = NULL;
    list->head = list->head->next;
    free(tmp);
    pthread_mutex_unlock(&(list->mutex));
    return retVal;
}

void freeList(List* list) {
    if (!list)                                      return;
    ListNode *cur = list->head;
    while(cur) {
        ListNode *tmp = cur;
        cur = cur->next;
        free(tmp->data);
        free(tmp);
    }
    pthread_mutex_t mutex = list->mutex;
    free(list);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

void sortList(List* list, int (*cmp)(const char*, const char*)) {
    if (!list)                                      return;
    int count = 0;
    for (ListNode* cur = list->head; cur->next != NULL; cur = cur->next, ++count) {}
    for (int j = 0; j < count; ++j) {
        int flag = 0;
        ListNode* cur = list->head;
        ListNode* prev = NULL;
        for (int i = 0; i < count - j; ++i) {
            if (cmp(cur->data, cur->next->data) > 0) {
                if (prev) {
                    prev->next = cur->next;
                } else {
                    list->head = cur->next;
                }
                prev = cur->next;
                cur->next = cur->next->next;
                prev->next = cur;
                if (i == count - 1) {
                    list->tail = cur;
                }
                flag = 1;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (!flag) break;
    }
}

void printList(List* list) {
    if (!list)                                      return;
    for (ListNode* cur = list->head; cur != NULL; cur = cur->next) {
        printf("%s\n", cur->data);
    }
    pthread_mutex_unlock(&(list->mutex));
}

char* readString(FILE* fin) {
    size_t length = 255;
    size_t offset = 0;
    char* str = calloc(length, sizeof(char));
    while(1) {
        if (!fgets(str + offset, length - offset, fin))  {
            free(str);
            return NULL;
        }
        size_t realLength = strlen(str + offset) + offset;
        if ( realLength == length - 1 &&
             str[realLength - 1] != '\n' &&
             !feof(fin)) {
            offset = length-1;
            length = length * 3 / 2;
            str = realloc(str, length);
        } else {
            if (str[realLength - 1] == '\n') str[realLength - 1] = '\0';
            break;
        }
    }
    return str;
}
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* routine(void* list_p) {
    List* list = (List*)list_p;
    while (1) {
        pthread_testcancel();
        sleep(5);
        pthread_mutex_lock(&mutex);
        sortList(list, strcmp);
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char** argv) {
    List* list = initList();
    char* str;
    pthread_t thread;
    pthread_create(&thread, NULL, routine, (void*)list);
    while((str = readString(stdin))) {
        if(str[0] == '\0') {
            pthread_mutex_lock(&mutex);
            printList(list);
            pthread_mutex_unlock(&mutex);
            continue;
        };
        pthread_mutex_lock(&mutex);
        pushList(list, str);
        pthread_mutex_unlock(&mutex);
    }
    pthread_cancel(thread);
    pthread_join(thread, NULL);
    freeList(list);
    pthread_exit(0);
}

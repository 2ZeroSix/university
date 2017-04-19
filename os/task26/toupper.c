#include <unistd.h>
#include <ctype.h>

#define BUF_LENGTH 256

void strtoupper(char* dest, const char* src) {
    for (size_t i = 0; src[i] != '\0'; ++i) {
        dest[i] = toupper(src[i]);
    }
}

int main() {
    char str[BUF_LENGTH];
    ssize_t len;
    while((len = read(0, str, BUF_LENGTH - 1)) > 0) {
        str[len] = 0;
        strtoupper(str, str);
        write(1, str, len);
    }
    return 0;
}
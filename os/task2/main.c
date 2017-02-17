#include <time.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    setenv("TZ","PST-7PDT", 1);
    size_t len = 255;
    char *timeStr = (char*)calloc(len, sizeof(char));
    time_t curTime = time(NULL);
    struct tm* cur = localtime(&curTime);
    while (strftime(timeStr, len, "%H:%M:%S %d.%m.%Y", cur) == 0) {
        len = len*2 + 1;
        free(timeStr);
        timeStr = (char*)calloc(len, sizeof(char));
    }
    printf("%s\n", timeStr);
    free(timeStr);
    return 0;
}

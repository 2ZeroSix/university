#include <unistd.h>
#include <stdio.h>

#define BUF_LENGTH 256

int main() {
    char str[BUF_LENGTH];
    ssize_t len;
    FILE* toupper = popen("./toupper", "w");
    while((len = read(0, str, BUF_LENGTH - 1)) > 0) {
        str[len] = 0;
        fprintf(toupper, "%s", str);
        fflush(toupper);
    }
    pclose(toupper);
    return 0;
}
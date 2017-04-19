#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
    if (argc == 2) {
        FILE* wc = popen("wc -l", "w");
        FILE* inFile = fopen(argv[1], "r");
        char buffer[256] = {0};
        char prevlast = '\n';
        while(fgets(buffer, 255, inFile) != NULL && buffer[0] != 0) {
            if (buffer[0] == '\n' && prevlast == '\n') {
                fputs("\n", wc);
            } else {
                prevlast = buffer[strlen(buffer) - 1];
            }
        }
        if (prevlast == '\n') {
            fputs("\n", wc);
        }
        pclose(wc);
        return 0;
    } else {
        printf("using: %s <filename>\n", argv[0]);
        return 1;
    }
}
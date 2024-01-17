#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char path[1000];
    scanf("%s", path);
    FILE *file;
    file = fopen(path, "w");
    if (file == NULL) {
        printf("File is null");
        exit(1);
    }
    for (int i = 0; i < 10; ++i) {
        char s[40] = {0};
        strftime(s, 80, "%d.%m.%Y", local);
        fprintf(file, "%s\n", s);
        now += 86400;
        local = localtime(&now);
    }
    fclose(file);
    getch();
    return 0;
}
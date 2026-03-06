#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;
    char ch;

    int characters = 0;
    int spaces = 0;
    int tabs = 0;
    int lines = 1;

    fp = fopen("file.txt", "r");

    if(fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    ch = fgetc(fp);

    while(ch != EOF) {

        characters++;

        if(ch == ' ')
            spaces++;

        if(ch == '\t')
            tabs++;

        if(ch == '\n')
            lines++;

        ch = fgetc(fp);
    }

    printf("Total Characters : %d\n", characters);
    printf("Total Spaces     : %d\n", spaces);
    printf("Total Tabs       : %d\n", tabs);
    printf("Total Lines      : %d\n", lines);

    fclose(fp);

    return 0;
}

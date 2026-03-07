#include <stdio.h>
#include <string.h>

int main() {

    char keywords[32][10] = {
        "auto","double","int","struct","break","else","long",
        "switch","case","enum","register","typedef","char",
        "extern","return","union","const","float","short",
        "unsigned","continue","for","signed","void","default",
        "goto","sizeof","volatile","do","if","static","while"
    };

    char str[20];
    int i, flag = 0;

    printf("Enter a word: ");
    scanf("%s", str);

    for(i = 0; i < 32; i++) {
        if(strcmp(str, keywords[i]) == 0) {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("%s is a Keyword\n", str);
    else
        printf("%s is an Identifier\n", str);

    return 0;
}

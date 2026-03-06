#include<stdio.h>
#include<string.h>

int main() {

    char string[50];
    int flag = 0, i;

    printf("Grammar : S -> aS | Sb | ab\n");

    printf("Enter the string : ");
    scanf("%s", string);

    if(string[0] == 'a') {

        for(i = 1; string[i] != '\0'; i++) {

            if(string[i] == 'b') {
                flag = 1;
            }

            else if(flag == 1 && string[i] == 'a') {
                printf("String not accepted\n");
                return 0;
            }
        }

        if(string[strlen(string)-1] == 'b')
            printf("String Accepted\n");
        else
            printf("String Not Accepted\n");
    }
    else {
        printf("String Not Accepted\n");
    }

    return 0;
}

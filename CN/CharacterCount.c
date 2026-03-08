#include <stdio.h>
#include <string.h>

int main()
{
    char data[5][50];
    int i, j, count;

    printf("Enter data for 5 frames:\n");

    for(i = 0; i < 5; i++)
    {
        printf("Frame %d: ", i + 1);
        scanf("%s", data[i]);
    }

    printf("\nSender Side\n");

    for(i = 0; i < 5; i++)
    {
        count = strlen(data[i]);
        printf("Frame %d sent: %d %s\n", i + 1, count, data[i]);
    }

    printf("\nReceiver Side\n");

    for(i = 0; i < 5; i++)
    {
        count = strlen(data[i]);

        for(j = 0; j < count; j++)
        {
            printf("%c", data[i][j]);
        }

        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char data[50], div[20], temp[50];
    int i, j, n, dlen;

    printf("Data: ");
    scanf("%s", data);

    printf("Divisor: ");
    scanf("%s", div);

    dlen = strlen(data);
    n = strlen(div);

    // append zeros
    for(i = 0; i < n-1; i++)
        data[dlen+i] = '0';
    data[dlen+n-1] = '\0';

    strcpy(temp, data);

    // division
    for(i = 0; i <= strlen(data)-n; i++) {
        if(temp[i] == '1') {
            for(j = 0; j < n; j++)
                temp[i+j] = (temp[i+j] == div[j]) ? '0' : '1';
        }
    }

    // print CRC
    printf("CRC bits: ");
    for(i = dlen; i < dlen+n-1; i++)
        printf("%c", temp[i]);
    // receiver side same logic send actual data + crc bits and same divisor
    // for(i = dlen; i < dlen+n-1; i++){
    //     if(temp[i] != '0'){
    //         printf("Error");
    //         return 0;
    //     }
    // }
    // printf("No error");

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char data[50], divisor[20], temp[50], recv[50];
    int i, j, data_len, div_len;

    printf("SENDER SIDE\n");

    printf("Enter Data: ");
    scanf("%s", data);

    printf("Enter Divisor: ");
    scanf("%s", divisor);

    data_len = strlen(data);
    div_len = strlen(divisor);

    // Append zeros
    for (i = 0; i < div_len - 1; i++)
        data[data_len + i] = '0';

    data[data_len + div_len - 1] = '\0';

    strcpy(temp, data);

    // CRC Division
    for (i = 0; i <= strlen(data) - div_len; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < div_len; j++) {
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    printf("CRC bits: ");
    for (i = data_len; i < data_len + div_len - 1; i++)
        printf("%c", temp[i]);

    printf("\nData to send: ");

    for (i = 0; i < data_len; i++)
        printf("%c", data[i]);

    for (i = data_len; i < data_len + div_len - 1; i++)
        printf("%c", temp[i]);

    printf("\n\n RECEIVER SIDE \n");

    printf("Enter Received Data: ");
    scanf("%s", recv);

    strcpy(temp, recv);

    // Receiver division
    for (i = 0; i <= strlen(recv) - div_len; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < div_len; j++) {
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Check remainder
    int error = 0;
    for (i = strlen(recv) - (div_len - 1); i < strlen(recv); i++) {
        if (temp[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error == 0)
        printf("No Error Detected \n");
    else
        printf("Error Detected \n");

    return 0;
}
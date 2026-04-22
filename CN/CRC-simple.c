#include<stdio.h>
#include<string.h>


int main() {
	char data[50];
	char temp[50];
	char divisor[20];
	int datalen, divlen;
	int i, j;


	printf("Enter data: ");
	scanf("%s", data);

	printf("Enter divisor: ");
	scanf("%s", divisor);

	datalen = strlen(data);
	divlen = strlen(divisor);

	for(i = 0; i<divlen-1; ++i) {
		data[datalen+i] = '0';
	}
	data[datalen+divlen-1] = '\0';

	strcpy(temp, data);
	
    // XOR Division
	for(i = 0; i<=strlen(data) - divlen; ++i) {
		if(temp[i] == '1') {
			for(j= 0; j<divlen; ++j) {
				if(temp[i+j] == divisor[j])
					temp[i+j] = '0';
				else
					temp[i+j] = '1';
			}
		}
	}
	printf("CRC bits: ");
	printf("%s", temp);

	return 0;
}

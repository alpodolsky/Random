#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
//dynamically creates input instead of statically
char* createInput(){
	char* input = NULL;
	char buff[2];
	size_t inputlen = 0, templen = 0;
	do{
		fgets(buff,2,stdin);
		templen = strlen(buff);
		input = realloc(input, inputlen+templen+1);
		strcpy(input+inputlen,buff);
		inputlen += templen;
	} while(templen ==1&&buff[0]!='\n');
	input[strlen(input)-1]='\0';
	return input;
}

//right now i can't think of a way to dynamically create a data type basically
uint64_t aton(char*buff){
    uint64_t number=0;
    uint64_t i = 0;
    for (i=0;buff[i]!='\0';i++){
        number=(number*10)+(buff[i]-'0');
    }

    return number;
}

uint64_t addition(uint32_t firstNum, uint32_t secondNum){
    uint64_t prod = 0;
    while(firstNum>0){
        firstNum-=((uint64_t)1);
        prod+=secondNum;
    }
    return prod;
}

//main
int main(){
    printf("Enter first multiple: ");
    uint32_t firstNum = 0;
    char *buffer;
    buffer = createInput();
    firstNum = aton(buffer);
    free(buffer);

    printf("Enter second multiple: ");
    uint32_t secondNum = 0;
    buffer = createInput();
    secondNum = aton(buffer);
    free(buffer);

    uint64_t product = addition(firstNum, secondNum);
    printf("\nProduct: %llu", (unsigned long long)product);
    return 0;
}
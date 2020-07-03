#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main(int argc){
    if(argc>1){
        printf("error, I don't take arguments");
        return 0;
    }
    float quizAvg = atof(createInput())*0.15;
    float midterm1 = atof(createInput());
    float midterm2 = atof(createInput());
    float final = atof(createInput());

    float possible1 = quizAvg+((midterm1*.2)+(midterm2*.2)+(final*.45));
    float possible2 = quizAvg+((midterm2*.25)+(final*.65));

    if(possible1>possible2){
        printf("%f\n", possible1);
    }
    if(possible1<possible2){
        printf("%f\n", possible2);
    }
    else{
        printf("%f\n", possible1);
    }
    return 0;
    
}
#include <stdio.h>
#include <string.h>

int main(){
    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");

    char fileString[100];
    fgets(fileString,100,inputFile);
    rewind(inputFile);
    char c = fgetc(inputFile);
    char maxVowelWord[100];
    int maxVowelCount = 0;
    int minVowelCount = 0;
    char string[100];
    char finalString[100];
    char finalMin[100];
    int length,end,minLength,minEnd;
    int total = 0;
    int x = 0;
    while(c != EOF){
        int vowelCount = 0;
        int i = 0;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            
            while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                fputc(c,outputFile);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                    vowelCount += 1;
                }
                i += 1;
                x += 1;
                c = getc(inputFile);
                total += 1;
            }
            
                if (vowelCount > maxVowelCount){
                    maxVowelCount = vowelCount;
                    end = x;
                    length = i;
                }
                if (vowelCount <= minVowelCount){
                    minVowelCount = vowelCount;
                    minEnd = x;
                    minLength = i;
                } 
                if (vowelCount == 0){
                    minVowelCount = vowelCount;
                    minEnd = x;
                    minLength = total;
                }
                fprintf(outputFile," vowels: %d \n", vowelCount);
                
            }  else{
                
                total += 1;
                c = getc(inputFile);
        }
    }
    int a,b = 0;
    end -= 1;
    for(a=end;a<end+length;a++){
        finalString[b] = fileString[a];
        b += 1;
    }
    b = 0;
    printf("%d %d", minEnd,minLength);
    for(a=minLength-1;a<minLength-1+minEnd;a++){
        finalMin[b] = fileString[a];
        b += 1;
    } 
    fprintf(outputFile,"Most vowels: %d \nThe word with the most vowels is: %s\n",maxVowelCount,finalString);
    fprintf(outputFile,"Least vowels: %d \nThe word with the least vowels is: %s", minVowelCount,finalMin);
    fclose(inputFile);
    fclose(outputFile);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    FILE *inputFile = fopen("in1.txt","r");
    FILE *outputFile = fopen("out1.txt","w");
    if(inputFile == NULL){
        printf("Error, no input file.");
        exit(1);
    }


    // 329 from 10 words * 32 characters + 9 space characters that arent part of the words
    char words[10][329];
    int index = 0;
    int c;
    while(fgets(words[index],sizeof(words),inputFile)){
        index++;
    }
    
    int i;
    for(i=index;i<10;i++){
        words[i][0] = ' ';
        words[i][1] = '\n';
        words[i][2] = '\0';
    }


    

    char command[128];
    char str[128];
    command[0] = ')';
    int m,n;
    while(command[0] != 'E'){
        printf("\nEnter a command: ");
        fgets(command,sizeof(command),stdin);
        
        switch(command[0]){
            case 'I':
                m = command[2] - '0';
                for(i=4;i<strlen(command);i++){
                    str[i-4] = command[i];
                }
                str[i-4] = '\0';
                
                for(i=index-1;i>=m+1;i--){
                    if(i < 9){
                        strcpy(words[i+1],words[i]);
                    }
                }
                index++;
                strcpy(words[m+1],str);
                break;
            case 'D':
                m = command[2] - '0';
                n = command[4] - '0';
                c = 0;
                for(i=0;i<index;i++){
                    //delete lines between m and n
                    //n - m + 1 lines to be deleted
                    if(n+1+i<index){
                        strcpy(words[m+i],words[n+1+i]);//starting position is m; from position is n + 1;
                        c++;
                    }
                }
                //to empty the shifted indexes
                for(i=m+c;i<index;i++){
                    words[i][0] = ' ';
                    words[i][1] = '\n';
                    words[i][2] = '\0';
                }
                break;
            case 'R':
                m = command[2] - '0';
                n = command[4] - '0';
                for(i=m;i<=n;i++){
                    printf("Enter a string: ");
                    fgets(str,sizeof(str),stdin);
                    strcpy(words[i],str);
                    
                }
                break;
            case 'E':

                break;
            default:
                break;
        }

    }

    for(i=0;i<10;i++){
        printf("%s",words[i]);
        fprintf(outputFile,"%s",words[i]);
    }
    fclose(inputFile);   
    fclose(outputFile); 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stringStruct{
        long int length;
        char * string;
};



int main(){
        struct stringStruct myStr;
        char *str = "Hello";
        printf("What will be passed out is the question : pointer %p, as a char %s\n",*str,str);
        myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(300*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        strcpy(myStr.string,str);

        printf("What will be passed out is the question : digit  %d, as a char %s\n",myStr.length,myStr.string);
        //success. Now return a pointer         
        return(0);

}
~  

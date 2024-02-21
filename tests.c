
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stringStruct {
        long int length;
        char * string;
};



void * setString(char *str){
        static struct stringStruct array[100];
        static int numarray=0;
        numarray += 1;
        struct stringStruct myStr;
        printf("What will be passed out is the question : pointer %p, as a char %s\n",*str,str);
        myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(30*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        strcpy(myStr.string,str);
        struct stringStruct * mystringPointer;
        printf("What will be passed out is the question : digit  %d, as a char %s\n",myStr.length,myStr.string);
        /*success. Now return a pointer*/
        array[numarray]=myStr;
        return(&array[numarray]); }
void print(void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        printf("The values are ; digit : %d & string : %s\n",myStr.length,myStr.string);
}

char *new_print(void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        return(myStr.string);

}
void copy(void **destination, void * source){
        if (!((*destination)=(void *)malloc(sizeof(source)+1))){
                printf("Insufficient memory\n");
                exit(1);
        }
        struct stringStruct destStr = *(struct stringStruct *)destination;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        destStr.string = sourceStr.string;
        free(*destination);
}
long int length (void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        return(myStr.length);
}


int main(){
        void * stringptr = setString("hello");
        void * stringptr2 = setString("meheehe");
        void * stringptr3 = setString("mlwaswe");
        printf("Show me my value for stringptr : %p and its contents ",stringptr);
        print(stringptr);
        printf("Show me my value %p and its contents: %s\n ",stringptr2, new_print(stringptr2));
        copy(stringptr2,stringptr3);
        printf("Test for copy: Show me my value %p and its contents: %s\n ",stringptr2, new_print(stringptr2));
             printf("The length of the frist mstring is %d\n",length(stringptr));
        return(0);
        return(0);
} 

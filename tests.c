#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stringStruct {
        long int *length;
        char * string;
};



void * setString(char *str){
        static struct stringStruct array[100];
        static int numarray=0;
        numarray += 1;
        struct stringStruct myStr;
        printf("What will be passed out is the question : pointer %p, as a char %s\n",*str,str);
         if (!(myStr.length = (long int *)malloc(30*sizeof(long int)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        *(long int *)myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(30*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        strcpy(myStr.string,str);
        struct stringStruct * mystringPointer;
        printf("What will be passed out is the question : digit  %d, as a char %s\n",*(long int *)myStr.length,myStr.string);
        /*success. Now return a pointer*/
        array[numarray]=myStr;
        return(&array[numarray]); }
void print(void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        printf("The values are ; digit : %d & string : %s\n",*(long int *)myStr.length,myStr.string);
}

char *new_print(void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        return(myStr.string);

}
void copy(void * *destination, void * source){

        void * ptr;
        if (!((ptr)=(void *)malloc(sizeof(source)+1))){
                printf("Insufficient memory\n");
                exit(1);
        }
        ptr = *destination;

        struct stringStruct destStr = *(struct stringStruct *)ptr;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        printf("what is in destString is : %s\n",destStr.string);
        printf("What is is source string is : %s\n",sourceStr.string);
        strcpy(destStr.string, sourceStr.string);
        *(long int *)destStr.length = strlen(sourceStr.string);

}

void concatenate(void * *destination, void * source){
        void * ptr;
        if (!((ptr)=(void *)malloc(sizeof(source)+1))){
                printf("Insufficient memory\n");
                exit(1);
        }
        ptr = *destination;
        struct stringStruct destStr = *(struct stringStruct *)ptr;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        printf("what is in destString is : %s\n",destStr.string);
        printf("What is is source string is : %s\n",sourceStr.string);
        strcat(destStr.string, sourceStr.string);
        *(long int *)destStr.length = *(long int*)destStr.length + *(long int *)sourceStr.length;
}
long int length (void * ptr){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        long int number = *(long int *)myStr.length;
        return(number);
}

int compare (void * ptr1, void * ptr2){
        int i = strcmp(new_print(ptr1),new_print(ptr2));
        if (i == 0){
                return(0);
        } else {return(1);}

}
int compareString(void * ptr, char *str){
        int i = strcmp(new_print(ptr),str);
        if (i == 0){
                return(0);
        } else {return(1);}
}
static void msError(char *str){
        printf("there has been an error with the string : %s\n");
        exit(1);
}
int main(){
        void * stringptr = setString("hello");
        void * stringptr2 = setString("meheehe");
        void * stringptr3 = setString("mlwasw");
        printf("Show me my value for stringptr : %p and its contents ",stringptr);
        print(stringptr);
        printf("Show me my value %p and its contents: %s\n",stringptr2, new_print(stringptr2));
        copy(&stringptr2,stringptr3);
        printf("Test for copy: show me my value %p and its contents: %s |%d\n ",stringptr2, new_print(stringptr2),length(stringptr2));
        concatenate(&stringptr,stringptr3);
        printf("Test for concatenate using hello and mlwasw: she me the value of %p amd its content %s and length %d\n",stringptr,new_print(stringptr),length(stringptr));
        printf("The length of the frist mstring is %d\n",length(stringptr));
        printf("Test for compare using string 1 and 2 : %d\n",compare(stringptr,stringptr2));
        printf("Test for compareString using string 1 and Hello : %d\n",compareString(stringptr,"Hello"));
        return(0);
}

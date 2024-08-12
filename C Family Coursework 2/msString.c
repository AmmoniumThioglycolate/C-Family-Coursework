#include <msString.h>

/*INTRODUICNG A storage made up of piinters to store the information of the msString"*/
struct stringStruct{
        long int * length;/*these are made pointers to help with passing*/
        char * string;
};
extern msString  msSetString (char *str){
   /*the char str saves perfectly as a string so not much to worry about in that regard*/
  /*an msString is meant to be a pointer that leads to a memory address that stores a long int and characters. Maybe use an array
*/      static struct stringStruct array[100]; /*a static array is used to save all the msStrings created*/
        static int numarray=0; /*this is used to help keep track of the msStrings made that will be stored in the array*/
        numarray += 1;
        struct stringStruct myStr;
        /*memory is allocated otherwise i got a core dump*/
        if (!(myStr.length = (long int *)malloc(sizeof(long int)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        *(long int *)myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(30*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }

        strcpy(myStr.string,str);
        /*success. Now return a pointer*/
        array[numarray]=myStr; /*storing the newly created structure in the array*/
        /*Note the memory is not free'd as it causes a lose of the structure and derails the whoel program. The static array is maintained and only minimal memory is retained after. There are no other memory leaks detected by valgrind. I just have to not free it otherwise the programe losed information, as the array stores the string structure and then the address to the spot in the array is stored*/
        return(&array[numarray]);
 }

extern char *msGetString (msString str){
        struct stringStruct  myStr = *(struct stringStruct *)str; /*the mstring is cast to a stringStruct to male it usuable */
        return(myStr.string);
}
extern void  msCopy (msString *destination, msString source){
        void * ptr;
        /*If the destination is null, make it an empy string first to make it easier to work with*/
        if (*destination == NULL){
                *destination = msSetString("");
        }
        ptr = *destination;
        /*some casting is necessary to use the functions from the void pointers*/
        struct stringStruct destStr = *(struct stringStruct *)ptr;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        strcpy(destStr.string,sourceStr.string);
        *(long int *)destStr.length = strlen(sourceStr.string);
}
extern void msConcatenate (msString *destination, msString source){
        void * ptr;

        if (*destination == NULL){
                *destination = msSetString("");
        }
        ptr = *destination;
        struct stringStruct destStr = *(struct stringStruct *)ptr;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        printf("what is in destString is : %s\n",destStr.string);
        printf("What is is source string is : %s\n",sourceStr.string);
        strcat(destStr.string, sourceStr.string);
        *(long int *)destStr.length = *(long int*)destStr.length + *(long int *)sourceStr.length;
}
extern long int  msLength (msString str){
        struct stringStruct  myStr = *(struct stringStruct *)str;
        long int number = *(long int *)myStr.length;

        return(number);
}
extern int  msCompare       (msString str1, msString str2){
        int i = strcmp(msGetString(str1),msGetString(str2));
        if (i == 0){
                return(0);
        }
        else {
        return(1);
        }
}
extern int msCompareString (msString str1, char *standardStr){
        struct stringStruct  myStr = *(struct stringStruct *)str1;
        int i = strcmp(myStr.string,standardStr);
        if (i == 0){
                return(0);
        } else {return(1);}
}


static void msError  (char *standardStr){

        printf("there has been an error with the string : %s\n",standardStr);
        exit(1);

}

                                                                                                                     97,0-1        Bot


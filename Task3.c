struct stringStruct{
        long int length;
        char * string;
};
extern msString  msSetString (char *str){
   //the char str saves perfectly as a string so not much to worry about in that regard
  //an msString is meant to be a pointer that leads to a memory address that stores a long int and characters. Maybe use an array
        static struct stringStruct array[100];
        static int numarray=0;
        numarray += 1;
        struct stringStruct myStr;
        myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(30*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        strcpy(myStr.string,str);
        /*success. Now return a pointer*/
        array[numarray]=myStr;
        return(&array[numarray]); }
}
extern char *msGetString (msString str){
        struct stringStruct  myStr = *(struct stringStruct *)ptr;
        return(myStr.string);
}
extern void  msCopy (msString *destination, msString source){
        if (!((*destination)=(void *)malloc(sizeof(source)+1))){
                printf("Insufficient memory\n");
                exit(1);
        }
        struct stringStruct destStr = *(struct stringStruct *)destination;
        struct stringStruct sourceStr = *(struct stringStruct *)source;
        destStr.string = sourceStr.string;
        free(*destination);
}
extern void msConcatenate (msString *destStr, msString sourceStr){
        
}
extern long int  msLength (msString str){
        struct stringStruct  myStr = *(struct stringStruct *)str;
        return(myStr.length);
}
extern int  msCompare       (msString str1, msString str2){
        int i = strcmp(msGetString(ptr1),msGetString(ptr2));
        if (i == 0){
                return(0);
        } else {return(1);}
}
extern int       msCompareString (msString str1, char *standardStr){
        struct stringStruct  myStr = *(struct stringStruct *)str1;
        int i = strcmp(myStr.string,standardStr);
        if (i == 0){
                return(0);
        } else {return(1);}
}


static void      msError         (char *standardStr){
        printf("there has been an error with the string : %s\n",standardStr)
        exit(1);
 
}

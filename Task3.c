#include <msString.h>


struct stringStruct{
        long int length;
        char * string;
};
extern msString  msSetString (char *str){
   //the char str saves perfectly as a string so not much to worry about in that regard
  //an msString is meant to be a pointer that leads to a memory address that stores a long int and characters. Maybe use an array
        struct stringStruct myStr;
        myStr.length = strlen(str);
        if (!(myStr.string = (char *)malloc(300*sizeof(char)))){
                printf("Insufficient memeory\n");
                exit(1);
        }
        strcpy(myStr.string,str);
        free(myStr.string);
        //I'm return the address of myStr as msString will just point to that
        return &myStr

}

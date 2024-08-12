#include <msString.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



void printBytes(void* ptr, int numBytes){
        printf("Starting at memory address %p\n", ptr);
        unsigned short int i;
        for (i=0;i<numBytes; i++){
                printf("%03d: %3d\n",(i+1),*(int *)ptr);
                ptr++;
        }



}

int main(int argc, char **argv){
        FILE *infp;
        FILE *outfp;
        char *filestring;
        if(!( filestring = (char *)malloc(300*sizeof(char)))){
                printf("Insufficient memory");
                exit(1);
        }



        /*The file in comes from the terminal, so i'll use the second*/
        /*First check there are atleast 2 arguments*/
        int i=0;
        if(argc != 3){ /*making sure there are three arguments*/
                printf("There are too many or not enough file arguments.\n");
                exit(1);
        }
        /*File opening process for reading file*/
        if ((infp = fopen(argv[1],"r")) == NULL){
                printf("Unable to open file for read access.\n");
                fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
                exit(1);
        }
        /*File opening process for the file to be written to*/
        if ((outfp = fopen(argv[2],"w+")) == NULL){
                printf("Unable to open file for read access.\n");
                fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
                exit(1);
        }

        /*read in file and store in a variable*/
        /*reverse the string. hopefully.*/
        while(!feof(infp)){
                fgets(filestring,1000,infp);
        }

        i=strlen(filestring);
        i = i -1;
        int j=0;
        /*To reverse the file using a while loop and starting at th eend and working back and forth*/
        char filestring_reversed[i];
        while(i>0){
                i=i-1;
                filestring_reversed[j]=filestring[i];
                j= j+1;

        }
        /*writes the reversed string into the file*/
        fprintf(outfp,"%s",filestring_reversed);


        /*close output files*/
        fclose(infp);
        fclose(outfp);
        /*Test for print Bytes*/
        int array2[]={9,3,223,4,23,34,53};
        void *p;
        p = &array2[1];
        printBytes(p,4);

        /*tests for msString*/
        msString ms = msSetString("Hello");
        msString ms2 = msSetString(" World!");
        msString mscopy = NULL;

        printf("String |%s| is %d characters long (%p).\n",msGetString(ms),msLength(ms),ms);
        msCopy(&mscopy,ms);
        printf("Copied string |%s| is %d characters long (%p).\n",msGetString(mscopy),msLength(mscopy),mscopy);
        printf("Compare ms with mscopy: %d\n",msCompare(ms,mscopy));
        printf("Compare ms with ms2 : %d\n",msCompare(ms,ms2));
        printf("Compare ms with Hello : %d\n",msCompareString(ms,"Hello"));
        printf("Compare ms with HelloX: %d\n",msCompareString(ms,"HelloX"));
        printf("Compare ms with Hella : %d\n",msCompareString(ms,"Hella"));
        msConcatenate(&mscopy,ms2);
        printf("Concatenated string |%s| is %d characters long (%p).\n",msGetString(mscopy),msLength(mscopy),mscopy);
        free(filestring);
        /*When i ran the code through valgrabd i did not encounter a memory leak in this region.*/

        return EXIT_SUCCESS;

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
        FILE *infp;
        FILE *outfp;
        char *filestring;
        if(!( filestring = (char *)malloc(1000*sizeof(char)))){
                printf("Insufficient memory");
                exit(1);
        }

        /*allocate memory for the files*/
        if (!(infp = (FILE *)malloc(10000000*sizeof(FILE)))){
                printf("Out of memory for the input file: %d: %s\n",errno,strerror(errno));
                exit(1);
        }
        if (!(outfp = (FILE*)malloc(1000000*sizeof(FILE)))){
                printf("Out of memory for the output file: %d: %s\n",errno,strerror(errno));
                exit(1);
        }

        /*The file in comes from the terminal, so i'll use the second*/
        /*First check there are atleast 2 arguments*/
        int i=0;
        if(argc != 3){ /*making sure there are three arguments*/
                printf("There are too mnay file arguments.\n");
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

        /*read in file and store in a stack, so I cam use the last in first out principle to help*/
        /*reverse the string. hopefully.*/
        while(!feof(infp)){
                fgets(filestring,1000,infp);
                printf("The current character is: %s\n",filestring);
        }

        i=strlen(filestring);
        i = i -1;
        printf("The length of the filestring %d\n",i);
        int j=0;
        /*To reverse the file using a while loop and starting at th eend and working back and forth*/
        char filestring_reversed[i];
        while(i>0){
                i=i-1;
                filestring_reversed[j]=filestring[i];
                j= j+1;
        }
        fprintf(outfp,"%s",filestring_reversed);
        /*THINGS TO BE DONE*/

        /*write to output file using stack*/
        /*check output file*/
        /*debug*/

        fclose(infp);
        fclose(outfp);
        return EXIT_SUCCESS;

}

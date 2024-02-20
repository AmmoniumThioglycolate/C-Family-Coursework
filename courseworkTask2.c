
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
        FILE *infp=NULL;
        FILE *outfp=NULL;
        char ch;

        //allocate memory for the files
        if (!(infp = (FILE *)malloc(10000000*sizeof(FILE)))){
                printf("Out of memory for the input file: %d: %s\n",errno,strerror(errno));
                exit(1);
        }
        if (!(outfp = (FILE*)malloc(1000000*sizeof(FILE)))){
                printf("Out of memory for the output file: %d: %s\n",errno,strerror(errno));
                exit(1);
        }

        //The file in comes from the terminal, so i'll use the second
        //First check there are atleast 2 arguments
        int i=0;
        if(argc != 3){ //making sure there are three arguments
                printf("There are too mnay file arguments.\n")
                exit(1);
        }
        //File opening process for reading file
        if ((infp = fopen(argv[1],"r")) == NULL){
                printf("Unable to open file for read access.\n")
                fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
                exit(1);
        }
        //File opening process for the file to be written to
        if ((outfp = fopen(argv[2],"w")) == NULL){
                printf("Unable to open file for read access.\n")
                fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
                exit(1);
        }

        //read in file and store in a stack, so I cam use the last in first out principle to help
        //reverse the string. hopefully.
        while(!feof(fp)){
                ch=fgetc(infp);
                //implement stack
        }

        //THINGS TO BE DONE
        //implement stack
        //write to output file using stack
        //check output file
        //debug
        return EXIT_SUCCESS;

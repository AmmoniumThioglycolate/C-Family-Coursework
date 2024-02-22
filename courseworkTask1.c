#include <stdio.h>

void printBytes(void*,int);

int main(){

        int array2[]={9,3,223,4,23,34,53};
        void *p;
        p = &array2[1];
        float *p2;
        p2 = p;


        printf("The value of array2[1] is %d and as a float %f.The memory address of p is %p\n and th next memory address is %x. The value of p is %d and of p2 is %f\n",array2[1],(float)array2[1],p,&array2[2],*(int *)p,*p2);
        printBytes(p,4);



        return 0;
}

void printBytes(void* ptr, int numBytes){
        printf("Starting at memory address %p\n", ptr);
        unsigned short int i;
        for (i=0;i<numBytes; i++){
                printf("%03d: %3d\n",(i+1),*(int *)ptr);
                printf("The memory address is %x\n",ptr);
                ptr++;
        }



}








#include <stdio.h>

void printBytes(void*,int);

int main(){

        int array2[]={9,3,4,2,4,23,37,53};
        void *p;
        p = &array2[1];
        float *p2;
        p2 = p;


        printf("The value of array2[1] is %f and a float as an integer : %d.The memory address of p is %p\n and th next memory address is %x. The value of p is %d and of p2 is %f\n",array2[1],(float)array2[1],p,&array2[2],*(int *)p,*p2);
        printBytes(p,7);



        return 0;
}

void printBytes(void* ptr, int numBytes){
        printf("Starting at memory address %p\n", ptr);
        unsigned short int i;
        for (i=0;i<numBytes; i++){
                printf("%03d: %3d\n",(i+1),*(int *)ptr);
                ptr++;
        }



}

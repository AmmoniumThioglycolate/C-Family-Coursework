
int main(){
        char array2[]={9,3,223,3.4,23,34,53};
        float *p;
        p = &array2[1];
        printBytes(p,4);



        return 0;
}

void printBytes(void* ptr, int numBytes){
        printf("Starting at memory address %p\n", ptr);
        unsigned short int i;
        for (i=0;i<numBytes; i++){
                printf("%03d: %4f\n",(i+1),*(float *)ptr);
        }





}

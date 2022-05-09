#include <stdio.h>

int main(int argc,char **argv){

    argc --;
    argv ++;

    int nums[4] = {0};

    int k = 0;
    for(int i = 0;argv[0][i] != '\0'; ++i){
        if(argv[0][i] == '.'){
            k ++;
        }
        else{
            nums[k] = nums[k]*10 + argv[0][i] - '0';
        }

    }
    

    for(int i = 0;i < 4; ++i){
        printf("%-3d: ",nums[i]);
        int bx[8] = {0};
        for(int j = 0;j < 8; ++j){
            bx[j] = nums[i] & 1;
            nums[i] >>= 1;
        }

        for(int i = 7;i >= 0; --i){
            printf("%2d",bx[i]);
        }
        putchar(10);

    }

    return 0;
}

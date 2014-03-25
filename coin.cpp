#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int[2] coinarray = {0};
    int mycoin;
    srand( time( NULL ) );
    for(int i = 1,i<=50,++i){
           mycoin = flip();
            if(mycoin == 1){
                    ++coinarray[mycoin];
            }else if(mycoin == 0){
                    ++coinarray[mycoin];
            }else{
                    printf("bug");
            }
    }
    
    
    for(int j= 0,j<=1,++j){
            printf("%d",coinarray[j]);    
    }
    
    system("pause");
    return 0;
    
}
int flip(void){
    int coin;
    coin = 1+(rand()%2);
    if(coin == 1){
            printf("heads");
    }else if(coin == 0){
            printf("tails");
    }else{
            printf("none");
    }
    return coin;
    
}

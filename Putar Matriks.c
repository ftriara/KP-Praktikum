#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int r,c;
    scanf("%d %d",&r,&c);
    
    int matriks [r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&matriks[i][j]);
        }
    }
    
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            printf("%d ",matriks[r-j-1][i]);
        }
        printf("\n");
    }
    
    return 0;
}

#include<stdio.h>
int main(){
    int n,x=1;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    int f1 = 0,f2 = 1;

    while(x <= n){
        printf("%d ",f1);
        int next = f1 + f2;
        f1 = f2;
        f2 = next;
        x++;
    }
    return 0;
}
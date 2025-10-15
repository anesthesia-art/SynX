#include<stdio.h>
int main(){
    int n,i;
    long long x;
    printf("enter the number:");
    scanf("%d",&n);
    for (i=1,x=1;i<=n;i++)
        x*=i;
    printf("%d!=%lld\n",n,x);
    return 0;
}



#include<stdio.h>
int fib(int n){
    if (n<=0){
    }
    else if (n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int main(){
    int n;
    printf("请输入要显示的斐波那契数列项数：");
    scanf("%d",&n);
    if(n<=0){
        printf("输入的数值不合法！");
        return 1;
    }
    printf("斐波那契数列前%d项为：",n);
    for(int i=1;i<=n;i++){
        printf("%d ",fib(i));
    }
    printf("\n");
    return 0;
}

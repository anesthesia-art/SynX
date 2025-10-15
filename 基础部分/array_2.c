#include<stdio.h>
int main(){
    int n,sum=0;
    printf("enter the number of the students:");
    scanf("%d",&n);
    int array_1[n];
    for(int i = 0; i < n; i++){
        printf("enter the marks of student %d:",i+1);
        scanf("%d",&array_1[i]);
    }
    for(int i = 0; i < n; i++){
        sum += array_1[i];}
    printf("the average marks of the %d students is: %f",n,(float)sum/n);
    return 0;
}


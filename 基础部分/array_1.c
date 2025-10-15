#include<stdio.h>
int main(){
    int arr[5],sum=0;
    for(int i = 0;i<5;i++){
        printf("enter the grade of student %d :",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    printf("the average grade of the %d students is: %f",5,(float)sum/5);
    return 0;
}

#include<stdio.h>
int main(){
    int n,sum=0;
    printf("enter the number of the students:");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        printf("enter the grade of student %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int max_grade = 100;
    int count[max_grade + 1];
    for(int i = 0;i <= max_grade;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=0 && arr[i]<=max_grade){
            count[arr[i]]++;
        }
    }
    printf("the average grade of the %d students is: %.2f",n,(float)sum/n);
    printf("\nGrade Distribution:\n");
    for(int i=0;i<=max_grade;i++){
        if(count[i]>0){
            printf("Grade %d: %d students\n",i,count[i]);
        }
    }
    return 0;
}

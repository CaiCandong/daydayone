#include<stdio.h>
int main(){
    const int n=10;
    int a[10]={1,-2,-3,4,0,-1,2,3,5,-2};
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    solution(a)
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void solution(int *array,int length){
    int i,j=0,length;
    while(i<j){
        if(a[i]>0){
            i++;
        }
        if(a[j]<0){
            j--;
        }
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

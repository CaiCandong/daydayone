#include<stdio.h>
#include<string.h>
#include<malloc.h>

int binarySearch(int target,int *times){
    int length=10;
    int array[]={-36 ,-25 ,0 ,12, 14, 29, 35, 47, 76, 100};
    int i=0,j=length-1;
    while(i<=j){
        *times=*times+1;
        int mid=(i+j)/2;
        // printf("%d,%d\n",mid,array[mid]) ;
        if (array[mid]<target){
            //在右半区域
            i=mid+1;
        }else if(array[mid]>target){
            //在左半区域
            j=mid-1;
        }else{
            return mid+1;
        }
    }
    return -1;
}
int main()
{
    int *times=(int*)malloc(sizeof(int));
    (*times)=0;
    int num=-25;
    scanf("%d",&num);
    int res=binarySearch(num,times);
    if(res==-1){
        printf("查找失败。");
    }else{
        printf("%d是第%d个数，查找次数为%d。",num,res,*times);
    }
    printf("%d %d",res,*times);

}

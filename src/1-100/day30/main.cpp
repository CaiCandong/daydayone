#include<stdio.h>
int kMax(int nums1[],int nums1Size,int nums2[],int nums2Size,int k){
    //归并排序思路
    int i=0,j=0;
    int ret;
    while(i+j<k-1&&i<nums1Size&&j<nums2Size){
        if(nums1[i]<nums2[j]){
            i++;
        }else{
            j++;
        }
    }
    while(i+j<k-1&&i<nums1Size){
        i++;
    }
    while(i+j<k-1&&j<nums2Size){
        j++;
    }
    printf("i=%d,j=%d\n",i,j);
    if(i<nums1Size&&j<nums2Size){
        if(nums1[i]<nums2[j]){
            return nums1[i];
        }else{
            return nums2[j];
        }
    }
    if(i<nums1Size){
        return nums1[i];
    }else{
        return nums2[j];
    }
}
int main(){
//    int A[]={1,3,4,5,6};
//    int B[]={3,4,5,6};
//    int k=4;
    int A[]={1,2};
    int B[]={3,4};
    int k=2;
    int ret=kMax(A,2,B,2,k);
    printf("%d",ret);
}

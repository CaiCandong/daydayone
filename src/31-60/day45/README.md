#### [寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

``` c
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
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if((nums1Size+nums2Size)%2==1){
        return kMax(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1);
    }else{
        double  a=kMax(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1);
        double  b=kMax(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2);
        return (a+b)/2;
    }

}
```


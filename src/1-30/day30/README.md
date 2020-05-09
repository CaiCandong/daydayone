## 武大933

**2018武汉大学933**

两个整数递增有序序列 A，B 分别有 n 和 m 个元素，求第 k 大的数（1≤K≤n+m）， 要求最佳时间空间复杂度。

函数原型：int kMax(int[] A,int[] B,int k)

例子：

**输入**

A[1,3,4,5,6]

B[3,4,5,6]

k=4

**输出**

**4**

## 解法1：归并排序思路

``` c
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
```



## 解法2：二分查找思路



对于有序数组A[a1,a2,a3.......] 长度为m 有序数组B[b1,b2,b3.....]长度为n

求第K个数字：

**证明**:

#### 1.从A,B数组中各取出较小的k/2个数 

$A[a1,a2,a3......a_m]$       $ B[b1,b2,b3.....b_n]$

划分：

$A1[a1,a2,.....a_{k/2-1}]$ |$A2[a_{k/2},a_{k/2+1}......a_m]$

$B1[b1,b2,.....b_{k/2-1}]$  | $A2[a_{k/2},a_{k/2+1}......a_n]$

#### 2.分别按照第k个数字可能存在的位置进行讨论

####  2.1第k个数位于A1或者B1数组中：

```  c
A1=[1,3,5,7] A2=[9,11,13,15]
B1[2,4,6,8]  B2=[10,12,14,16]
```

​	A1和B1总共就k个数字，第K大的数要么是$a_{k/2-1}$要么就是$b_{k/2-1}$。如果$a_{k/2-1}$>$b_{k/2-1}$,  那么第k个数肯定不在$B1$中。从而可以排除B1

**即：当第K个数位于A1或者B1中时：可以排除的数组是A1和B1中较小的数组**

#### 2.2第K个数位于A2或者B2数组中：

``` c
A1=[1,2,3,4] A2=[5,6,7,8]
B1=[9,10,11,12] B2=[13,14,15,16]
```

第K个数不在A1和B1中，理论上我们排除A1和B1哪个都行。

**即：当第K个数不位于A1和B1中时：可以排除的数组是A1和B1**

问题的难点在于如何区分这两种情况，但是我们根本就不需要区别这两种情况。

两种情况能够进行的操作取交集就可以。也就是说无论是哪种情况，都按照第一种情况：把较小的部分丢掉，就可以把问题缩小。

**c语言的实现**：

``` c
#include <stdio.h>

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int getKth(int nums1[], int nums1Size, int nums2[], int nums2Size, int k) {
    //1.确保nums1Size小于nums2Size
    if (nums1Size > nums2Size) {
        return getKth(nums2, nums2Size, nums1, nums1Size, k);
    }
    //2.小数组为空 直接返回
    if (nums1Size == 0) {
        return nums2[k - 1];
    }
    //3.k等于1
    if (k == 1) {
        return min(nums1[0], nums2[0]);
    }
    //4.把问题缩小
    int temp = k / 2-1;
    int i = min(nums1Size - 1, temp);
    int j = min(nums2Size - 1, temp);
    if (nums1[i] < nums2[j]) {
        return getKth(&nums1[i + 1], nums1Size - i - 1, nums2, nums2Size, k - i - 1);
    } else {
        return getKth(nums1, nums1Size, &nums2[j + 1], nums2Size - j - 1, k - j - 1);
    }
}
int main(){
//    int nums1[2] = {1, 2};
//    int nums2[2] = {3, 4};
//    int ret=getKth(nums1,2,nums2,2,4);
    int A[]={1,3,4,5,6};
    int B[]={3,4,5,6};
    int k=8;
    int ret=getKth(A,5,B,4,k);
    printf("%d",ret);
}
```


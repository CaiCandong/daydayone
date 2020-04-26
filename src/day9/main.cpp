#include <stdio.h>
#include <malloc.h>
float solution(int N,int T,float discount[],int limit[])
{
    //贪心算法,优先使用最低折扣
    //不使用排序,使用flag数组
    bool *flag=(bool*)malloc(sizeof(bool)*N);
    for(int i=0;i<N;i++){
        flag[i]=false;
    }
    float res=0;
    for(int i=0;i<N&&T>0;i++){
        //寻找最低折扣
        float minCount=1.0;
        int index=-1;
        for(int j=0;j<N&&!flag[j];j++){
            // printf("%f,%f\n",minCount,discount[j]);
            if(discount[j]<minCount){
               minCount=discount[j]; 
               index=j;
            }
        }
        //标记已经打过折
        flag[index]=true;
        //进行打折
        if(T>limit[index]){
            //额度不够
            T-=limit[index];
            res+=limit[index]*discount[index];
        }else{
            //完成打折
            res+=T*discount[index];
            T=0;
        }
    } 
    // 加上额度不够部分
    return res+T;
}
// 测试样例
typedef struct
{
    int N;
    int T;
    float*discount;
    int *limit;
}Data;

int main()
{
    Data d;
    d.N=2;
    d.T=100;
    d.discount=(float*)malloc(sizeof(float)*d.T);
    d.discount[0]=0.7; 
    d.discount[1]=0.6; 
    d.limit=(int*)malloc(sizeof(int)*d.T);
    d.limit[0]=70;
    d.limit[1]=50;
    int res=(int)solution(d.N,d.T,d.discount,d.limit);
    printf("%d",res);
}

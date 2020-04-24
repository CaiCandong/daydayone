#include<stdio.h>
int maxProfit(int* prices, int pricesSize){
   //思想:无论何时我都是以已知的最低价买入的股票 
   int minPrice=prices[0];
   int profix=0;
   for(int i=1;i<pricesSize;i++){
       if(prices[i]<minPrice){//现在的价钱比之前低？我之前买的不作数了,现在买入
           minPrice=prices[i];
       }
       if(prices[i]-minPrice>profix){//现在的利润最高？我之前卖出的不作数了,现在卖出
            profix=prices[i]-minPrice;
       }
   }
   return profix;
}
int main(){
    int prices[6]={7,1,5,3,6,4};
    int res=maxProfit(prices,6);
    printf("%d",res);
}


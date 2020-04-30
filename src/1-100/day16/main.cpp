#include<stdio.h>
const int pace[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int result=0;

void backtrack(bool dp[5][5],int x,int y,int count){
//    printf("%d,%d,%d\n",x,y,count);
//    for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            printf("%d ",dp[i][j]);
//        }
//        printf("\n");
//    }
    if (count==25){
        result++;
        return;
    }
    //访问路径
    for(int i=0;i<8;i++){
        int x_=x+pace[i][0];
        int y_=y+pace[i][1];
        if (x_<5&&x_>=0&&y_<5&&y_>=0&&!dp[x_][y_]){//位置有效并且没用被访问过
            dp[x_][y_]=true;
            backtrack(dp,x_,y_,count+1);
            dp[x_][y_]=false;
        }
    }
}
int solution(){
    bool dp[5][5];//标记是否访问过
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dp[i][j]=false;
        }
    }
    //马的初始位置
    dp[0][0]=true;
    backtrack(dp,0,0,1);
    return result;
}

int main(){
    int res=solution() ;
    printf("%d",res);
    return 0;
}
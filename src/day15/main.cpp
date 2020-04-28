#include<stdio.h>
#include<malloc.h>

typedef struct {
    int hour; //小时
    int min;  //分
    int sec;  //秒
    int timestamp;//时间戳
} Time;

Time *NewTime(int hour, int min, int sec) {
    Time *that = (Time *) malloc(sizeof(Time));
    that->hour = hour;
    that->min = min;
    that->sec = sec;
    that->timestamp = hour * 60 * 60 + min * 60 + sec;
    return that;
}

typedef struct {
    char *Id;
    Time *start;//上班时间
    Time *end;//下班时间
    int duration;//持续时间
} Employee;

//employee构造方法
Employee *NewEmployee( char *id,Time *start, Time *end) {
    Employee *that=(Employee*)malloc(sizeof(Employee));
    that->Id=id;
    that->start = start;
    that->end = end;
    that->duration = end->timestamp - start->timestamp;
    return that;
}

void solution(Employee **employees,int length){
    //1.找到最早的
    int index=0;
    for(int i=0;i<length;i++){
        if(employees[i]->start->timestamp<employees[index]->start->timestamp){
            index=i;
        }
    }
    printf("OPEN:%s %.2d:%.2d:%.2d\n",employees[index]->Id, employees[index]->start->hour,
           employees[index]->start->min, employees[index]->start->sec);

    //2.找到最晚的
    // index=0;
    for(int i=0;i<length;i++){
        if(employees[i]->end->timestamp>employees[index]->end->timestamp){
            index=i;
        }
    }
    printf("CLOSE:%s %.2d:%.2d:%.2d\n",employees[index]->Id, employees[index]->end->hour,
           employees[index]->end->min, employees[index]->end->sec);

    //3.工作最长的

    // index=0;
    for(int i=0;i<length;i++){
        if(employees[i]->duration>employees[index]->duration){
            index=i;
        }
    }
    printf("LONGEST WORK TIME ID:%s %.2d:%.2d:%.2d\n",employees[index]->Id, employees[index]->start->hour,
           employees[index]->start->min, employees[index]->start->sec);
}
// 程序问题:内存全部动态分配,但是没有实现析构方法,可能导致内存泄漏
int main() {
    int n=3;
    Employee  **employees=(Employee**)malloc(sizeof(Employee*)*n);
    employees[0]=NewEmployee("ID100001",NewTime(7,0,0),NewTime(17,0,0));
    employees[1]=NewEmployee("ID100002",NewTime(8,0,0),NewTime(18,0,0));
    employees[2]=NewEmployee("ID100003",NewTime(9,0,0),NewTime(21,0,0));

    solution(employees,3);
}
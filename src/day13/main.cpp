#include<stdio.h>
#include<malloc.h>

typedef struct node {
    char *Name;//姓名
    int score[3];
    int total;//总分
} Student;

//构造方法
Student *construct( char *Name, int score1, int score2, int score3, int total) {
    Student *that = (Student *) malloc(sizeof(Student));

    that->Name = Name;
    that->score[0] = score1;
    that->score[1] = score2;
    that->score[2] = score3;
    that->total = total;
    return that;
}

bool isFail(Student *stu) {
    for (int i = 0; i < 3; i++) {
        if (stu->score[i] < 60) {
            return true;
        }
    }
    return false;
}

void solution(Student **stu, int length) {
    Student *temp;
    //1.打印挂科学生成绩
    for (int i = 0; i < length; i++) {
        if (isFail(stu[i])) {
            printf("*[%s] %d %d %d\n", stu[i]->Name, stu[i]->score[0], stu[i]->score[1], stu[i]->score[2]);
        }
    }
    //2.排序
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (stu[j]->total < stu[j + 1]->total) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    //3.打印全部成绩
    for (int i = 0; i < length; i++) {
        printf("[%s] %d %d %d\n", stu[i]->Name, stu[i]->score[0], stu[i]->score[1], stu[i]->score[2]);
    }

}

int main() {
    int n=5;
    Student **stu=(Student**)malloc(sizeof(Student*)*n);//指针数组

    stu[0] = construct("zhaoyi", 70, 80, 90, 240);
    stu[1] = construct("qianer", 65, 32, 77, 174);
    stu[2] = construct("sunsan", 100, 55, 68, 223);
    stu[3] = construct("lisi", 86, 77, 90, 253);
    stu[4] = construct("wangwu", 100, 59, 66, 225);

    solution(stu, n);
}

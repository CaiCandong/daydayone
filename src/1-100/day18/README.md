####（2018南开大学初试）

两个有序的无头结点的链表La，Lb。编写函数：如何以最优的方式找出二者的交集，并且把结果存在一个新链表中返回。

单链表的类型定义如下： 
``` c
Typeddf struct LNode{ 

Element Type data;  

Struct LNode *next; 

 }LNode, *ListNode; 
``` 
函数原型： ListNode* intersection(ListNode *A, ListNode *B) 

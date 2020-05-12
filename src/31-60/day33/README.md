#### [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)

#### 解法1  双栈

``` go
type MinStack struct {
	Stack []int
	minStack []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		Stack:    make([]int,0),
		minStack: make([]int,0),
	}
}


func (this *MinStack) Push(x int)  {
	if len(this.Stack)==0||this.minStack[len(this.minStack)-1]>=x{
		this.minStack= append(this.minStack, x)
	}
	this.Stack=append(this.Stack,x)
}


func (this *MinStack) Pop()  {
	if len(this.Stack)==0{
		return
	}
	if this.minStack[len(this.minStack)-1]==this.Stack[len(this.Stack)-1]{
		this.minStack=this.minStack[:len(this.minStack)-1]
	}
	this.Stack=this.Stack[:len(this.Stack)-1]
}


func (this *MinStack) Top() int {
	return this.Stack[len(this.Stack)-1]
}


func (this *MinStack) GetMin() int {
	return this.minStack[len(this.minStack)-1]
}
```



#### 解法2:使用指针指向最小的节点(链表实现)

``` c
//链表实现
typedef struct node {
    int val;        //节点的值
    struct node *Min;//存储当前最小值的地址
    struct node *next;//下一个节点
} ListNode, *ListLink;

ListLink NewNode(int val) {
    ListLink ret = (ListLink) malloc(sizeof(ListNode));
    ret->val = val;
    ret->next = NULL;
    return ret;
}

typedef struct {
    ListLink top;
    int length;
} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate() {
    MinStack *ret = (MinStack *) malloc(sizeof(MinStack));
    ret->length = 0;
    ret->top = NULL;
    return ret;
}

void minStackPush(MinStack *obj, int x) {
    ListLink tmp = NewNode(x);
    if (obj->top == NULL || tmp->val < obj->top->Min->val) {
        tmp->Min = tmp;
    } else {
        tmp->Min = obj->top->Min;
    }
    tmp->next = obj->top;
    obj->top = tmp;
    obj->length++;
}

void minStackPop(MinStack *obj) {
    if(obj->top==NULL){
        //无法出栈
        return;
    }
    obj->top = obj->top->next;
    obj->length--;
}

int minStackTop(MinStack *obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack *obj) {
    return obj->top->Min->val;
}

void minStackFree(MinStack *obj) {
    ListLink p = obj->top;
    ListLink q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(obj);
}
```


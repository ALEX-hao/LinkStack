// DateStructure LinkStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 1.0链式存储栈

#include <iostream>
using namespace std;
static int amount = 0;
#define Max 100;
#define ERROR -0x3f3f3f;

class node
{
public:
	node() { amount++; }
	int date;
	node *next = NULL;
	~node() { amount--; }
};

class List
{
public:
	node Head;
	node *head = &Head;
	node *top = head;
	List();
	bool in(int a);
	int out();
	void print();
	//~List();释放链表占用内存，制空所调用的指针.
};
List::List() {
	Head.date = -0x3f3f3f;
	cout << "建立链表" << head << endl;
}
bool List::in(int a) {
	if (amount >= 100) {
		cout << "栈已满" << endl;
		return false;
	}
	node *p = head;
	node *s = new node;
	s->date = a;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = s;
	top = s;
	return 1;
}
int List::out() {
	if (top == head)
	{
		printf("栈为空\n");
		return ERROR;
	}
	node *p = head;
	int temp = top->date;
	while (p->next != top)
	{
		p = p->next;
	}
	delete top;//出栈回收之前栈顶所指向的内存
	top = p;
	return temp;
}
void List::print() {
	node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p << '\t' << p->date << endl;
	}
}
/*List::~List() {
	node *p = head;
	node *s;
	while (p->next != NULL)
	{
		s = p;
		p = p->next;
		delete s;
	}
}*/

int main()
{
	List l;
	for (int i = 0; i < 10; i++) {
		l.in(i);
	}
	l.print();
	cout << l.out() << endl;
    return 0; 
}


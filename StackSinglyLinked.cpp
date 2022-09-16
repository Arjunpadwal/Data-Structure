#include<iostream>
using namespace std;

template<class T>		//program 225
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

		Stack();
        void push(T);		//Insert Last
		void pop();			//Delete first
		void Display();
        int CountNode();
};

template<class T>
 Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}



template<class T>
void Stack<T>::push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next=Head;		//this Line imp
	Head=newn;				//this Line imp
    Count++;
}
template <class T>
void Stack<T>::pop()	//Delete first
{
	T no;	//int no;
	if(Count==0)
	{
		cout<<"Stack is empty"<<endl;
		return ;
	}
	if(Count==1)
	{
		no=Head->data;
		delete Head;
		Head=NULL;
		
	}
	
	no=Head->data;
	struct node<T> *temp=Head;
	Head=Head->next;
	delete temp;
		
	
	Count--;
	cout<<"Remove element from Stack is:"<<no<<endl;
}
template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Linked list are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

int main()
{
    Stack<char>obj1;
	obj1.push('A');
	obj1.push('B');
	obj1.push('C');
	obj1.push('D');
	
	obj1.Display();
	
	
	obj1.pop();
	obj1.pop();
	
	obj1.Display();
	
	obj1.push('Z');
	obj1.Display();
	
    return 0;
}
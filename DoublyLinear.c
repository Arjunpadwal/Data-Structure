#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	struct node*prev;	//*
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display()
{
	int count(PNODE head)
	{
		printf("Data from Linked list is:");
		
		while(head!=NULL)
		{
			printf("|%d|->",head->data);
			head=head->next;
		}
		
		printf("NULL\n");
	}
}

int count(PNODE head)
{
	int icnt=0;
	while(head!=NULL)
	{
		icnt++;
		head=head->next;
	}
	return icnt;
}
void InsertFirst(PPNODE head, int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;	//*
	
	if(*head==NULL)
	{
		*head=newn;
	}
	
	else	//LL contains atlest one node
	{
		newn->next=*head;
		(*head)->prev=newn;	//*
		*head=newn;
	}
	
}

void InsertLast(PPNODE head ,int no)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;	//*
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else	//LL contains atlest one node
	{
		temp=*head;
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;		//temp->next->prev=temp;
	}
}

void DeleteFirst(PPNODE head)
{
	PNODE newn=NULL;
	if(*head==NULL)
	{
		*head=newn;
	}
	
	if((*head)->next==NULL)		//single node
	{
		free(*head);
		*head=NULL;
	}
	
	else
	{
		*head=(*head)->next;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
}

void DeleteLast(PPNODE head)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	
	if(*head==NULL)
	{
		*head=newn;
	}
	
	if((*head)->next==NULL)		//single node
	{
		free(*head);
		*head=NULL;
	}
	else		//multiple node
	{
		temp=*head;
		
		while(temp->next->next !=NULL)
		{
			temp=temp->next;
		}
		
		free(temp->next);
		temp->next=NULL;
	}
}

void InsertAtPos(PPNODE head,int no, int pos)
{
	PNODE temp=NULL;
	PNODE newn=NULL;
	
	int size=0, icnt=0;
	size=count(*head);
	
	if((pos<1)||(pos>(size+1)))
	{
		printf("Invalid Position\n");
		return;
	}
	
	else if(pos==(size+1))
	{
		InsertLast(head,no);
	}
	
	else
	{
		temp=*head;
		
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		for(icnt=1; icnt<(pos-1); icnt++)
		{
			temp=temp->next;
		}
		
		newn->next=temp->next;
		temp->next->prev=newn;
		newn->prev=temp;
	}
}

void DeleteAtPos(PPNODE head,int pos)
{
	
}
int main()
{
	PNODE first=NULL;
	int ret=0;
	
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	
	InsertLast(&first,51);
	InsertLast(&first,101);
	
	Display(first);
	ret=count(first);
	
	printf("Number of nodes are:%d\n",ret);
	
	DeleteFirst(&first);
	
	
	DeleteLast(&first);
	Display(first);
	ret=count(first);
	
	printf("Number of nodes are:%d\n",ret);
	
	
	InsertAtPos(&first,24,3);
	Display(first);
	ret=count(first);
	
	printf("Number of nodes are:%d\n",ret);
	
	return 0;
}
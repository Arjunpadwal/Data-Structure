#include"HeaderDouCir.h"
int main()
{
	Doubly CLL obj;
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,21);
	InsertFirst(&first,51);
	
	Display(first);
	iRet=Count(first);
	cout<<"Number of Nodes are:"<<iRet<<endl;
	
	InsertLast(&first,27);
	InsertLast(&first,80);
	
	Display(first);
	iRet=Count(first);
	cout<<"Number of Nodes are:"<<iRet<<endl;
	
	
	InsertAtPos(&first,24,3);
	
	Display(first);
	iRet=Count(first);
	cout<<"Number of Nodes are:"<<iRet<<endl;
	
	DeleteFirst(&first);
	DeleteLast(&first);
	
	Display(first);
	iRet=Count(first);
	cout<<"Number of Nodes are:"<<iRet<<endl;
	
	DeleteAtPos();
	
	Display(first);
	iRet=Count(first);
	cout<<"Number of Nodes are:"<<iRet<<endl;
	
	
	return 0;
}
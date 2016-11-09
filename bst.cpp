#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{	public:
	int data;
	node *l,*r;
}*root;

class bst:public node
{
	public :
		
		node *insert(node* t,int s);
		node *del(node* t,int s);
		void inorder(node*);
		bst(){root=NULL;}
};


node *bst::insert(node* t,int s)
{
	if(t==NULL)
	{
		t = new node;
		t->l=t->r=NULL;
		t->data=s;
		return t;
	}

	if(t->data>s)
		t->l=insert(t->l,s);
		
	else if(t->data<s)
		t->r=insert(t->r,s);

	
	return t;
}



void bst ::inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->l);
		
		inorder( t->r);
		cout<<"\n "<<t->data;
	}
}

int main()
{
	int s;
	bst b;
	int c;
while(1)
{
	cout<<"\n1.insert \n2.display\n3.exit:  ";
	cin>>c;


	switch(c)
	{
		case 1: cout<<"\n enter the data to be inserted: ";
			cin>>s;
			root=b.insert(root,s);
			break;
			
		case 2:b.inorder(root);
			break;
		
		case 3:exit(0);
	}
}
return 0;
}

















	

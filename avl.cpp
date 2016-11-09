#include<iostream>
using namespace std;
#include<stdlib.h>
#include<math.h>
class node
{               public:
			 int data;
			 node *l,*r;
			 int h;
 }*root;
class avl
{	public:
		node *insert(node *,int );
		void inorder(node *);
		void preorder(node *);
		node *r_rotate(node *froot);
		node *l_rotate(node *froot);
		int height(node *);
		int bf(node *);
		avl()
		{root=NULL;}
};
node* avl::r_rotate(node *froot)
{
	cout<<"\nright rotation at work zzzZZZ";
	node *newroot;
	newroot=froot->l;
	froot->l=newroot->r;
	newroot->r=froot;
	froot->h=height(froot);
	newroot->h=height(newroot);
	return(newroot);
}
node* avl::l_rotate(node *froot)
{
	cout<<"\nleft rotation at work zzzZZZ";
	node *newroot;
	newroot=froot->r;
	froot->r=newroot->l;
	newroot->l=froot;
	froot->h=height(froot);
	newroot->h=height(newroot);
	return(newroot);
}
void avl::inorder(node *T)
{	if(T!=NULL)
	{	inorder(T->l);
		cout<<" "<<T->data;
		inorder(T->r);
	}
}
void avl::preorder(node *T)
{	if(T!=NULL)
	{	cout<<" "<<T->data;
		preorder(T->l);
		preorder(T->r);
	}
}
int avl:: height(node *temp)
{	if(temp==NULL)
	return 0;
	else return (max(height(temp->l),height(temp->r))+1);
}
int avl :: bf(node *temp)
{	if(temp->r==NULL) return(height(temp)-1);
	if(temp->l==NULL) return(1-height(temp));
	else return((temp->l->h)-(temp->r->h));
}
node *avl::insert(node* t,int x)
{	int b;
	if(t==NULL)
	{	t=new node;
		t->data=x;
		t->r=t->l=NULL;
		t->h=1;
		cout<<"\ninserted successfully";
		return t;
	}
	else {
			if(t->data>x)
			{	t->l=insert(t->l,x);	
				t->h=height(t);
				cout<<"\n"<<bf(t);
				if(bf(t)==2)
				{	if(x<t->l->data)
						t=r_rotate(t);
					else 
					{	t->l=l_rotate(t->l);
						t=r_rotate(t);
					}
				}
			}
			else if (t->data<x)
			{	t->r=insert(t->r,x);	
				t->h=height(t);
				cout<<"\n"<<t->data<<" "<<bf(t);
				b=bf(t);
				if(b==-2)
				{	if(x>t->r->data)
						t=l_rotate(t);
					else 
					{	t->r=r_rotate(t->r);
						t=l_rotate(t);
					}
				}
			}
		}
	return t;
}
int main()
{	int choice,data,n; avl a;
	while(1)
	{	cout<<"\n1.INSERT\n2.DISPLAY INORDER\n3.DISPLAY PREORDER\n4.EXIT: ";
		cin>>choice;
		switch(choice)
		{	case 1: cout<<"\n how many ??: ";
				cin>>n;
				for(int i =0;i<n;i++)
				{
					cout<<"\nEnter the data: ";
					cin>>data;
					root=a.insert(root,data);
				} break;
			case 2: a.inorder(root);          break;
			case 3: a.preorder(root); 	  break;
			case 4: exit(0);
			default:cout<<"\n wrong choice!!";
		}
	}
return 0;
}
		
		

















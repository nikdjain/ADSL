#include <iostream>
using namespace std;

class node
{
	int lbit,rbit,flag;
	node* lc;
	node* rc;
	char data;

public:
	node()
	{
		lc=rc=this;
		lbit=rbit=1;
		flag=-1;
	}

	node(char x)
		{
			data=x;
			lc=rc=this;
			lbit=rbit=1;
			flag=-1;
		}

	friend class tbt;
};

class tbt{
	node* head;

public:
	tbt()
	{
		head=new node();
		head->lc=head->rc=head;
		head->lbit=head->rbit=1;
		head->flag=-1;
	}

	void create()
	{
		rec_insert(head,0);
		cout<<"Tree created.\n";
	}

	void rec_insert(node*,int);

	void preorder()
	{
		node* t=head;
		do{
			t=t->lc;
			cout<<t->data<<" ";
		}while(t->lbit==0);

		while(t!=head)
		{
			t=pre_succ(t);
			if(t==head)
				break;
			cout<<t->data<<" ";
		}

	}

	node* pre_succ(node*);

	void inorder()
	{
		node* t=head;

			t=t->lc;
		while(t->lbit==0)
		{
			t=t->lc;
		}

		while(t!=head)
		{
			cout<<t->data<<" ";
			t=in_succ(t);
		}

	}

	node* in_succ(node*);

};

void tbt::rec_insert(node* dad,int flag)
{
	char x;
	cout<<"Enter the data or - to stop \n";
	cin>>x;

	if(x=='-')
		return;
	node* t;

	if(flag==0)
	{
		t=new node(x);
		dad->lbit=0;
		t->lc=dad->lc;
		dad->lc=t;
		t->rc=dad;
		t->lbit=t->rbit=1;
		t->flag=0;
	}

	else if(flag==1)
	{
		t=new node(x);
		dad->rbit=0;
		t->rc=dad->rc;
		dad->rc=t;
		t->lc=dad;
		t->lbit=t->rbit=1;
		t->flag=1;
	}

	cout<<"For left child of "<<x<<endl;
	rec_insert(t,0);
	cout<<"For right child of "<<x<<endl;
	rec_insert(t,1);
}


node* tbt::pre_succ(node* t)
{
	if(t->lbit==0)
		return t->lc;
	else if(t->rbit==0)
		return t->rc;
	else{

		while(t->rbit==1)
		{
			if(t==head)
				return t;
			t=t->rc;
		}
		return t->rc;
	}
}

node* tbt::in_succ(node* t)
{
	if(t->rbit==1)
		return t=t->rc;
	else{
		t=t->rc;
		while(t->lbit==0)
			t=t->lc;
		return t;
	}
}

void choices()
{
	cout<<"1.Create.\n"
			<<"2.Preorder.\n"
			<<"3.Inorder.\n";
}

int main()
{
	int ch;
	char yes='y';
	tbt T;

	do{
		choices();
		cin>>ch;

		switch(ch)
		{
		case 1:
			T.create();
			break;

		case 2:
			T.preorder();
			break;

		case 3:
			T.inorder();
			break;

		default:
			cout<<"Wrong choice.";
		}
		cout<<"Do you want to continue ? (y/n)\n";
		cin>>yes;
	}while(yes=='y');

	return 0;
}

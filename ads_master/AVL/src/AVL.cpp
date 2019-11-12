#include <iostream>
#include <cstring>
using namespace std;

class node{
	string data;
	string mean;
	node* left;
	node* right;

public:
	node(string a,string b)
	{
		data=a;
		mean=b;
		left=NULL;
		right=NULL;
	}

	friend class AVL;
};

class AVL{
	node* root;
	node* insert(node*,string,string);
	int bf(node*);
	int height(node* t);
	node* LL(node*);
	node* LR(node*);
	node* RR(node*);
	node* RL(node*);
	void rec_inorder(node*);
	node* rec_update(node*,string);
	node* remove1(node*,string);
	node* rotateright(node*);
	node* rotateleft(node*);


public:
	AVL()
	{
		root=NULL;
	}

	void create();
	void add();
	void remove();
	void inorder();
	void update();
};

void AVL::create()
{
	int n;
	cout<<"Enter the no of nodes .\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		add();
	}
}

void AVL::add()
{
	string str,str1;
	cout<<"Enter the word : ";
	cin>>str;
	cout<<"Enter the meaning : ";
	cin>>str1;

	root=insert(root,str,str1);
}

node* AVL::insert(node* t,string word,string mean)
{
	if(t==NULL)
	{
		node* p=new node(word,mean);
		return p;
	}

	if(word>t->data)
	{
		t->right=insert(t->right,word,mean);

		if(bf(t)==-2)
		{
			if(word >t->right->data)
			{
				t=RR(t);
			}
			else
				t=RL(t);
		}
		return t;
	}
	else if(word<t->data)
	{
		t->left=insert(t->left,word,mean);

		if(bf(t)==2)
		{
			if(word <t->left->data)
			{
				t=LL(t);
			}
			else
				t=LR(t);
		}

		return t;
	}
	else{
		cout<<"Duplicate entry!\n";
		return NULL;
	}
}

int AVL::bf(node* t)
{
	return height(t->left)-height(t->right);
}

int AVL::height(node* t)
{
	if(t==NULL)
	{
		return 0;
	}

	int h1 = 1+height(t->left);
	int h2 = 1+height(t->right);

	if(h1>h2)
		return h1;
	else
		return h2;
}

node* AVL::LL(node* t)
{
	t=rotateright(t);
	return t;

}
node* AVL::LR(node* t)
{
	t->left=rotateleft(t->left);
	t=rotateright(t);
	return t;
}
node* AVL::RR(node* t)
{
	t=rotateleft(t);
	return t;
}
node* AVL::RL(node* t)
{
	t->right=rotateright(t->right);
	t=rotateleft(t);
	return t;
}

void AVL::inorder()
{
	rec_inorder(root);
}

void AVL::rec_inorder(node* t)
{
	if(t!=NULL)
	{
		rec_inorder(t->left);
		cout<<"Word: "<<t->data<<"\tMeaning: "<<t->mean<<endl;
		rec_inorder(t->right);
	}
}

void AVL::update()
{
	string str;
	cout<<"Enter the word: ";
	cin>>str;
	root=rec_update(root,str);
}

node* AVL::rec_update(node* t,string word)
{
	if(t==NULL)
		return NULL;
	if(word<t->data)
	{
		t->left=rec_update(t->left,word);
		return t;
	}
	else if(word>t->data)
	{
		t->right=rec_update(t->right,word);
		return t;
	}
	else{
		cout<<"Found.\n";
		cout<<"Enter new meaning: ";
		cin>>t->mean;
		return t;
	}
}

void AVL::remove()
{
	string str;
	cout<<"Enter the word: ";
	cin>>str;
	root=remove1(root,str);
}

node* AVL::remove1(node* t,string word)
{
	if(t==NULL)
		return NULL;
	if(word<t->data)
	{
		t->left=remove1(t->left,word);
	}

	else if(word>t->data)
	{
		t->right=remove1(t->right,word);
	}
	else{

		if(t->left==NULL)
		{
			node* p=t->right;
			delete t;
			return p;
		}
		else if(t->right==NULL)
		{
			node* p=t->left;
			delete t;
			return p;
		}

		else{

			node* tmp=t->right;
			while(tmp->left!=NULL)
			{
				tmp=tmp->left;
			}
			t->data=tmp->data;
			t->mean=tmp->mean;
			t->right=remove1(t->right,t->data);
		}


		if(bf(t)==2 && bf(t->left)>=0)
		{
			t=LL(t);
		}
		if(bf(t)==2 && bf(t->left)<0)
		{
			t=LR(t);
		}
		if(bf(t)==-2 && bf(t->right)<0)
		{
			t=RR(t);
		}
		if(bf(t)==-2 && bf(t->right)>=0)
		{
			t=RL(t);
		}
	}
	return t;
}

node* AVL::rotateleft(node* r)
{
	node* p=r->right;
	r->right=p->left;
	p->left=r;
	return p;
}

node* AVL::rotateright(node* r)
{
	node* p=r->left;
	r->left=p->right;
	p->right=r;
	return p;
}



int main()
{
	int ch;
	char yes='y';
	AVL T;

	do{
		cout<<"1.Create.\n2.Insert.\n3.Delete.\n4.Ascending.\n5.Update.\n";
		cin>>ch;

		switch(ch)
		{
		case 1:
			T.create();
			break;
		case 2:
			T.add();
			break;
		case 3:
			T.remove();
			break;
		case 4:
			T.inorder();
			break;
		case 5:
			T.update();
			break;
		default:
			cout<<"Wrong choice.\n";
		}
		cout<<"Do you want to continue ? (y/n)\n";
		cin>>yes;
	}while(yes=='y');

	return 0;
}

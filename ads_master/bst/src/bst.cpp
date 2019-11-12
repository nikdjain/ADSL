#include <iostream>
#include <cstring>
using namespace std;

class node{
	string data;
	string m;
	node* left;
	node* right;

public:
	node(string data,string m)
	{
		this->data=data;
		this->m=m;
		left=NULL;
		right=NULL;
	}

	node()
	{
		data="";
		m="";
		left=NULL;
		right=NULL;
	}

	friend class bst;
};

class stack {
	node* d[15];
	int top1;
public:
	stack() {
		for (int i = 0; i < 15; i++)
			d[i] = NULL;
		top1 = -1;
	}

	bool isFull() {
		if (top1 == 14)
			return true;
		return false;
	}

	bool isEmpty() {
		if (top1 == -1)
			return true;
		return false;
	}

	void push(node* p) {
		if (!isFull())
			d[++top1] = p;
		else
			cout << "Stack Full";
	}

	node* pop() {
		if (!isEmpty())
			return d[top1--];
		else
			cout << "Stack Empty";
	}

	node* top() {
		if (!isEmpty())
			return d[top1];
		else
			cout << "Stack Empty";

	}
};

class bst{
	node* root;
	int total;

public:
	bst()
	{
		root=NULL;
		total=0;
	}


	void create()
	{
		int n;
		cout<<"Enter the no. of nodes: \n";
		cin>>n;
		string word,mean;

		for(int i=0;i<n;i++)
		{
			cout<<"Enter the word \n";
			cin>>word;
			cout<<"Enter the meaning \n";
			cin>>mean;
			root=insert(root,word,mean);
		}

		cout<<"Tree created.\n";
	}

	node* insert(node*,string,string);

	void insertkey()
	{
		string word,mean;
		cout<<"Enter the word.\n";
		cin>>word;
		cout<<"Enter the meaning.\n";
		cin>>mean;

		root=insert(root,word,mean);

	}

	void searchkey()
	{
		string word;
		cout<<"Enter the word.\n";
		cin>>word;

		node* p;
		p=search(root,word);

		if(p==NULL)
		{
			cout<<"Entry not found.";
		}
		else{
			cout<<"Entry found.\nWord: ";
			cout<<p->data<<"\nMeaning: "<<p->m;
		}
	}

	node* search(node*,string);

	void update()
	{
		string word;
		cout<<"Enter the word:\n";
		cin>>word;

		node* p;
		p=search(root,word);

		if(p==NULL)
		{
			cout<<"Entry not found.";
			return;
		}
		else{
			cout<<"Entry found.\nWord: ";
			cout<<p->data<<"\nMeaning: "<<p->m;
		}

		string mean;
		cout<<"\nEnter the new meaning\n";
		cin>>mean;
		p->m=mean;
		cout<<"Entry updated\n";

	}

	void asc()
	{
		stack s;
		node* p=root;

		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}

		while(!s.isEmpty())
		{
			p=s.pop();
			cout<<p->data<<" ";
			p=p->right;

			while(p!=NULL)
			{
				s.push(p);
				p=p->left;
			}
		}
	}

	void desc()
	{
		stack s;
		node* p=root;

		while(p!=NULL)
		{
			s.push(p);
			p=p->right;
		}

		while(!s.isEmpty())
		{
			p=s.pop();
			cout<<p->data<<" ";
			p=p->left;

			while(p!=NULL)
			{
				s.push(p);
				p=p->right;
			}
		}
	}

	void deletekey()
	{
		string word;
		cout<<"Enter the word.\n";
		cin>>word;
		node* p;
		p=search(root,word);

		if(p==NULL)
		{
			cout<<"Entry not found.";
		}
		else{
			root=del(root,word);
			cout<<"Deletion successfull.\n";
		}

	}

	node* del(node*,string);


};

node* bst::insert(node* p,string word,string mean)
{
	if(p==NULL)
	{
		p=new node(word,mean);
		return p;
	}

	if(p->data>word)
	{
		p->left=insert(p->left,word,mean);
		return p;
	}

	else if(p->data<word)
	{
		p->right=insert(p->right,word,mean);
		return p;
	}
	else{
		cout<<"Wrong input\n";
		return NULL;
	}

}

node* bst::search(node* t,string word)
{
	node* p=t;
	if(t==NULL)
		return NULL;
	if(t->data==word)
	{
		return t;
	}
	else
	{
		if(t->data>word)
		{
			p=search(t->left,word);
		}
		else if(t->data<word)
		{
			p=search(t->right,word);
		}
		return p;
	}
}

node* bst::del(node* t,string word)
{
	if(t->data>word)
	{
		t->left=del(t->left,word);
	}
	else if(t->data<word)
	{
		t->right=del(t->right,word);
	}
	else{
		if(t->right==NULL)
		{
			node* temp=t->left;
			delete t;
			return temp;
		}
		else if(t->left==NULL)
		{
			node* temp=t->right;
			delete t;
			return temp;
		}
		else{
			node* tmp;
			tmp=t->right;
			while(tmp!=NULL)
				tmp=tmp->left;
			t->data=tmp->data;
			t->m=tmp->m;
			t->right=del(t->right,tmp->data);
		}
	}
}


void choices()
{
	cout<<"1.Create.\n"
			<<"2.Insert.\n"
			<<"3.Update.\n"
			<<"4.Descending.\n"
			<<"5.Ascending.\n"
			<<"6.Search.\n"
			<<"7.Delete an entry.\n";
}

int main()
{
	int ch;
	char yes='y';
	bst T;

	do{
		choices();
		cin>>ch;
		switch(ch)
		{
		case 1:
			T.create();
			break;

		case 2:
			T.insertkey();
			break;

		case 3:
			T.update();
			break;

		case 4:
			T.desc();
			break;

		case 5:
			T.asc();
			break;

		case 6:
			T.searchkey();
			break;

		case 7:
			T.deletekey();
			break;

		default:
			cout<<"Wrong choice.\n";
		}
		cout<<"\nDo you want to continue? (y/n)";
		cin>>yes;
	}while(yes=='y');
}

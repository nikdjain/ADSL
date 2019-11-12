#include <iostream>
using namespace std;
int count = 0;
class node {
	char data;
	node* left;
	node* right;

public:
	node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}

	friend class btree;
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

class btree {
	node* root;

public:
	btree() {
		root = NULL;
	}

	void create() {
		cout << "For root of tree \n";
		root = insert();
		cout << "Tree successfully created.\n";
	}

	node* insert();
	void preorder() {
		rec_preorder(root);
	}
	void rec_preorder(node*);

	void postorder() {
		rec_postorder(root);
	}
	void rec_postorder(node*);

	void inorder() {
		rec_inorder(root);
	}
	void rec_inorder(node*);

	void height() {
		cout << "The hight of the tree is " << rec_height(root);
	}
	int rec_height(node*);

	void nodes() {
		int leaves;
		leaves = rec_leaf(root);
		cout << "Total leaves are " << leaves
				<< " and total interior nodes are " << count - leaves;
	}

	int rec_leaf(node*);

	void mirror() {
		rec_mirror(root);
	}

	void rec_mirror(node*);

	void del() {
		rec_del(root);
		cout << "Tree deleted.\n";
	}
	void rec_del(node*);

	void non_rec_pre()
	{
		stack s;
		node* p;
		p=root;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p=p->left;
		}

		while(!s.isEmpty())
		{
			p=s.pop();

			p=p->right;

			while(p!=NULL)
			{
				cout<<p->data<<" ";
				s.push(p);
				p=p->left;
			}

		}

	}

	void non_rec_inorder()
	{
		stack s;
		node* p;
		p=root;

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

	void non_rec_postorder()
	{
		stack s,s1;
		node* p=root;

		s.push(p);
		while(!s.isEmpty())
		{
			p=s.pop();
			s1.push(p);

			if(p->left!=NULL)
			{
				s.push(p->left);
			}

			if(p->right!=NULL)
			{
				s.push(p->right);
			}
		}

		while(!s1.isEmpty())
		{
			p=s1.pop();
			cout<<p->data<< " ";
		}

	}

};

node* btree::insert() {
	char x;
	node* temp;
	cout << "Enter the data or - to stop.\n";
	cin >> x;

	if (x == '-') {
		return NULL;
	}
	else{
	count++;

	temp=new node(x);

	cout << "For the left element of " << x << endl;
	temp->left = insert();

	cout << "For the right element of " << x << endl;
	temp->right = insert();
	}
	return temp;
}

void btree::rec_preorder(node* t) {
	if (t != NULL) {
		cout << t->data << " ";
		rec_preorder(t->left);
		rec_preorder(t->right);
	}
}

void btree::rec_postorder(node* t) {
	if (t != NULL) {
		rec_postorder(t->left);
		rec_postorder(t->right);
		cout << t->data << " ";
	}
}
void btree::rec_inorder(node* t) {
	if (t != NULL) {
		rec_inorder(t->left);
		cout << t->data << " ";
		rec_inorder(t->right);
	}
}

int btree::rec_height(node* t) {
	if (t == NULL)
		return 0;
	int h1, h2;
	h1 = rec_height(t->right);
	h2 = rec_height(t->left);

	return 1 + max(h1, h2);
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int btree::rec_leaf(node* t) {
	if (t == NULL) {
		return 0;
	}

	if (t->left == NULL && t->right == NULL) {
		return 1;
	}

	return rec_leaf(t->left) + rec_leaf(t->right);
}

void btree::rec_mirror(node* t) {
	node* temp;

	if (t == NULL)
		return;
	rec_mirror(t->left);
	rec_mirror(t->right);

	temp = t->left;
	t->left = t->right;
	t->right = temp;
}

void btree::rec_del(node* t) {
	if (t == NULL)
		return;
	rec_del(t->left);
	rec_del(t->right);
	count--;
	delete t;
}

void choices() {
	cout << "1.Create.\n" << "2.Preorder recursive.\n"
			<< "3.Postorder recursive.\n" << "4.Inorder recursive.\n"
			<< "5.Height of the tree.\n" << "6.Leaves and interior nodes.\n"
			<< "7.Mirror of the tree.\n" << "8.Delete tree.\n";
}

int main(int argc, char const *argv[]) {
	int ch;
	char yes;
	yes = 'y';
	btree T;

	do {
		choices();

		cin >> ch;

		switch (ch) {
		case 1: {
			T.create();
			break;
		}
		case 2: {
			//T.preorder();
			T.non_rec_pre();
			break;
		}

		case 3: {
			//T.postorder();
			T.non_rec_postorder();
			break;
		}

		case 4: {
			//T.inorder();
			T.non_rec_inorder();
			break;
		}

		case 5: {
			T.height();
			break;
		}

		case 6: {
			T.nodes();
			break;
		}

		case 7: {
			T.mirror();
			T.preorder();
			break;
		}

		case 8: {
			T.del();
			break;
		}

		default:
			cout << "Wrong choice enter again.\n";
		}

		cout << "Do you want to cotinue(y/n)";
		cin >> yes;
	} while (yes == 'y');
	return 0;
}

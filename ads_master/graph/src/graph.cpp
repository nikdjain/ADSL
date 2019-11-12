#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

class node{
	string city;
	int time;
	node* next;
public:
	node(string c,int t)
	{
		city=c;
		time=t;
		next=NULL;
	}

	friend class graph;
};

class queue
{
	string data[MAX];
	int front;
	int rear;
public:
	queue()
	{
		front=-1;
		rear=-1;
	}

	void enqueue(string str)
	{
		if(rear<MAX-1)
		{
			if(rear==-1)
			{
				front++;
				rear++;
				data[rear]=str;
			}
			else{
				rear++;
				data[rear]=str;
			}

		}
		else{
			cout<<"Queue Full";
		}
	}

	string dequeue()
	{
		
			/*sif(front==-1)
			{
				cout<<"Queue empty";
				return;
			}
			else */if(front==rear)
			{
				string p=data[front];
				rear=-1;
				front=-1;
				return p;
			}
			else{
				string p=data[front];
				front++;
				return p;
			}
	}

	bool empty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		else 
			return false;
	}
};

class graph{
	node* head[MAX];
	int visited[MAX];

public:
	graph()
	{
		for(int i=0;i<MAX;i++)
			head[i]=NULL;
	}

	void create()
	{
		int n;
		cout<<"Enter the no. of cities.";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			addcity();
		}

		cout<<"Enter the no. of flights .";
		cin>>n;

		for(int i=0;i<n;i++)
		{
			addflight();
		}
	}

	int index(string city)
	{
		for(int i=0;i<MAX;i++)
		{
			if(head[i]!=NULL && head[i]->city==city)
			{
				return i;
			}
		}
		return -1;
	}

	void addcity()
	{
		string city;
		cout<<"Enter the city name: ";
		cin>>city;
		int ind=index(city);
		if(ind!=-1)
		{
			cout<<"City already present.\n";
			return;
		}
		for(int i=0;i<MAX;i++)
		{
			if(head[i]==NULL)
			{
				head[i]=new node(city,-1);
				return;
			}
		}

		cout<<"Array full.\n";
		return;
	}

	void addflight()
	{
		string city1,city2;
		int t;
		cout<<"Enter the source city.\n";
		cin>>city1;
		cout<<"Enter the dest city.\n";
		cin>>city2;
		cout<<"Enter the time.\n";
		cin>>t;

		int ind=index(city1);

		if(ind==-1)
		{
			cout<<"City not present.\n";
			return;
		}

		node* dest=new node(city2,t);
		node* source=head[ind];

		while(source->next!=NULL)
		{
			source=source->next;
			if(source->city==city2)
			{
				cout<<"Flight already present.\n";
				return;
			}
		}

		source->next=dest;
		return;

	}

	void display()
	{
		for(int i=0;i<MAX;i++)
		{
			if(head[i]!=NULL)
			{
				node* source=head[i];
				source=source->next;
				while(source!=NULL)
				{
					cout<<"Source: "<<head[i]->city<<endl;
					cout<<"Dest: "<<source->city<<endl;
					cout<<"Time: "<<source->time<<endl<<endl;
					source=source->next;
				}
			}
		}
	}

	void delflight()
	{
		string city1,city2;
		cout<<"Enter the source. ";
		cin>>city1;
		cout<<"Enter the dest. ";
		cin>>city2;

		int ind=index(city1);

		if(ind==-1)
		{
			cout<<"Source not present.\n";
			return;
		}

		node* source=head[ind];
		node* tmp;
		while(source->next!=NULL && source->city!=city2)
		{
			tmp=source;
			source=source->next;
		}

		if(source->city==city2)
		{
			tmp->next=source->next;
			delete source;
			return;
		}

		cout<<"Dest not present.\n";
		return;
	}

	void delcity()
	{
		string city1;
		cout<<"Enter the city. ";
		cin>>city1;

		int ind=index(city1);
		if(ind!=-1)
		{
			head[ind]=NULL;

			for(int i=0;i<MAX;i++)
			{
				node* source=head[i];
				node* tmp;
				if(source!=NULL)
				{
					while(source->next!=NULL && source->city!=city1)
					{
						tmp=source;
						source=source->next;
					}

					if(source->city==city1)
					{
						tmp->next=source->next;
						delete source;
					}
				}
			}
		}
		else{
			cout<<"city not present.\n";
			return;
		}

	}

	void indegree()
	{
		string city1;
		cout<<"Enter the city name. ";
		cin>>city1;
		int count=0;

		for(int i=0;i<MAX;i++)
		{
			node* source=head[i];
			if(source!=NULL)
			{
				while(source->next!=NULL)
				{
					source=source->next;
					if(source->city==city1)
						count++;
				}
			}
		}
		cout<<"Indegree of "<<city1<<" is "<<count<<endl;

	}

	void outdegree()
	{
		string city1;
		cout<<"Enter the city name. ";
		cin>>city1;
		int count=0;

		int ind=index(city1);

		node* source=head[ind];
		while(source->next!=NULL)
		{
			source=source->next;
			count++;
		}

		cout<<"Outdegree of "<<city1<<" is "<<count<<endl;

	}

	void degree()
	{
		string city1;
		cout<<"Enter the city name. ";
		cin>>city1;



//		cout<<"Degree of "<<city1<<" is "<<count<<endl;

	}

	void DFS()
	{
		for(int i=0;i<MAX;i++)
			visited[i]=0;
		cout<<"DFS traversal : ";
		rec_DFS(head[0]->city);
		cout<<endl;
	}

	void rec_DFS(string city1)
	{
		int ind=index(city1);

		visited[ind]=1;
		cout<<" "<<city1;


		for(node* q=head[ind]->next;q!=NULL;q=q->next)
		{
			if(visited[index(q->city)]==0)
			rec_DFS(q->city);
		}
	}

	void BFS()
	{
		string str=head[0]->city;
		for(int i=0;i<MAX;i++)
		{
			visited[i]=0;
		}

		queue Q;
		cout<<"BFS traversal : ";
		cout<<" "<<str<<" ";
		int ind=index(str);
		visited[ind]=1;
		Q.enqueue(str);

		while(!Q.empty())
		{
			string p=Q.dequeue();
			int i=index(p);
			for(node* t=head[i]->next;t!=NULL;t=t->next)
			{
				string str1=t->city;
				if(visited[index(str1)]==0)
				{
					cout<<" "<<str1<<" ";
					visited[index(str1)]=1;
					Q.enqueue(str1);
				}
			}
		}
	}
};

void choices()
{
	cout<<"1.Create. \n"
			<<"2.Add city. \n"
			<<"3.Add flight. \n"
			<<"4.Delete city. \n"
			<<"5.Delete flight. \n"
			<<"6.Display.\n"
			<<"7.Indegree.\n"
			<<"8.Outdegree.\n"
			<<"9.Degree. \n"
			<<"10.BFS. \n"
			<<"11.DFS. \n";

}

int main()
{
	graph T;

	int ch;
	char yes='y';

	do{
		choices();
		cin>>ch;

		switch(ch)
		{
		case 1:
			T.create();

			break;
		case 2:
			T.addcity();
			break;
		case 3:
			T.addflight();
			break;
		case 4:
			T.delcity();
			break;
		case 5:
			T.delflight();
			break;
		case 6:
			T.display();
			break;
		case 7:
			T.indegree();
			break;
		case 8:
			T.outdegree();
			break;
		case 9:
			T.degree();
			break;
		case 10:
			T.BFS();
			break;
		case 11:
			T.DFS();
			break;
		default:

			cout<<"Wrong choice";
		}
		cout<<"\nDo you want to continue ?\n";
		cin>>yes;
	}while(yes=='y');

	return 0;
}

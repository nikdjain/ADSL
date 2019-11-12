#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

class hash{
	string k[MAX];
	string v[MAX];
	int flag[MAX];
public:
	hash()
	{
		for(int i=0;i<MAX;i++)
		{
			k[i]="#";
			v[i]="#";
			flag[i]=0;
		}
	}

	int hashf(string key)
	{
		int ascii=0;
		for(int i=0;i<key.length();i++)
			ascii=ascii+key[i];
		return ascii%MAX;
	}

	void display()
	{
		for(int i=0;i<MAX;i++)
		{
			cout<<"Index: "<<i<<"\tKey: "<<k[i]<<"\tValue: "<<v[i]<<endl;
		}
	}

	void insertWOR()
	{
		string key,val;
		cout<<"Enter the key. ";
		cin>>key;
		cout<<"Enter the value. ";
		cin>>val;

		int index=hashf(key);

		if(flag[index]==0)
		{
			k[index]=key;
			v[index]=val;
			flag[index]=1;
			cout<<"Insertion successful.\n";
			return;
		}
		else{
			for(int i=index+1;i!=index;i=(i+1)%MAX)
			{
				if(flag[i]==0)
				{
					k[i]=key;
					v[i]=val;
					flag[i]=1;
					cout<<"Insertion successful.\n";
					return;
				}
			}
			cout<<"Table is full.\n";
			return;
		}
	}

	void insertWR()
	{
		string key,val;
		cout<<"Enter the key. ";
		cin>>key;
		cout<<"Enter the value. ";
		cin>>val;

		int index=hashf(key);

		if(flag[index]==0)
		{
			k[index]=key;
			v[index]=val;
			flag[index]=1;
			cout<<"Insertion successful.\n";
			return;
		}
		else{

			if(hashf(k[index])==index)
			{
				for(int i=index+1;i!=index;i=(i+1)%MAX)
				{
					if(flag[i]==0)
					{
						k[i]=key;
						v[i]=val;
						flag[i]=1;
						cout<<"Insertion successful.\n";
						return;
					}
				}
				cout<<"Table is full.\n";
				return;
			}

			else{
				string tempk=k[index];
				string tempv=v[index];
				k[index]=key;
				v[index]=val;

				for(int i=index+1;i!=index;i=(i+1)%MAX)
				{
					if(flag[i]==0)
					{
						k[i]=tempk;
						v[i]=tempv;
						flag[i]=1;
						cout<<"Insertion successful.\n";
						return;
					}
				}
				k[index]=tempk;
				v[index]=tempv;

				cout<<"Table Full.\n";
				return;
			}
		}
	}

	void find()
	{
		string key;
		cout<<"Enter the key. ";
		cin>>key;

		int index=hashf(key);
		for(int i=index;i!=index-1;i=(i+1)%MAX)
		{
			if(k[i]==key)
			{
				cout<<"Key found .\n"<<"Index: "<<i<<"\tKey: "<<k[i]<<"\tValue: "<<v[i]<<endl;
				return;
			}
		}

		cout<<"Key not found.\n";
	}

	void delkey()
	{
		string key;
		cout<<"Enter the key. ";
		cin>>key;
		int index=hashf(key);

		for(int i=index;i!=index-1;i=(i+1)%MAX)
		{
			if(k[i]==key)
			{
				k[i]="#";
				v[i]="#";
				flag[i]=0;
				cout<<"Deletion successful.\n";
				return;
			}
		}

		cout<<"Entry not found.\n";
	}
};

void choices()
{
	cout<<"1.Insert without replacement.\n"
			<<"2.Insert with replacement.\n"
			<<"3.Find.\n"
			<<"4.Delete entry.\n"
			<<"5.Display hash table.\n";
}

int main()
{
	int ch;
	char yes='y';
	hash T;

	do{
		choices();
		cin>>ch;

		switch(ch)
		{
		case 1:
			T.insertWOR();
			break;
		case 2:
			T.insertWR();
			break;
		case 3:
			T.find();
			break;
		case 4:
			T.delkey();
			break;
		case 5:
			T.display();
			break;
		default:
			cout<<"Wrong choice.\n";
		}
		cout<<"Do you want to continue? (y/n)";
		cin>>yes;
	}while(yes=='y');

	return 0;
}

#include <iostream>
#define MAX 50
using namespace std;

template<class T>
class set
{
	T data[MAX];
	int n;
public:
	set()
	{
		n=-1;
	}
	void input(int);
	bool insert(T);
	bool remove(T);
	set unions(set);
	set intersect(set);
	void print();
	set diff(set);
	int size();
	bool contains(T);
	bool subset(set);

};

template<class T>
void set<T>::input(int m)
{

	T element;
	cout<<"Enter the elements\n";
	for(int i=0;i<m;i++)
	{
		cin>>element;
		insert(element);
	}
}

template<class T>
bool set<T>::insert(T element)
{
	if(n>=MAX)
	{
		cout<<"Set full.\n";
		return false;
	}

	n++;
	data[n]=element;
	return true;
}

template<class T>
void set<T>::print()
{
	if(n!=-1)
	{
		for(int i=0;i<=n;i++)
		{
			cout<<data[i]<<"  ";
		}
		cout<<endl;
		return;
	}
	cout<<"-"<<endl;
}

template<class T>
bool set<T>::contains(T element)
{

	for(int i=0;i<=n;i++)
	{
		if(data[i]==element)
		{
			return true;
		}
	}
	return false;
}

template<class T>
bool set<T>::remove(T element)
{
	if(n==-1)
	{
		cout<<"Underflow. Cannot delete";
		return false;
	}

	int j;
	for(int i=0;i<=n;i++)
	{
		if(data[i]==element)
		{
			j=i;
			break;
		}
	}

	for(int i=j;i<n;i++)
	{
		data[i]=data[i+1];
	}
	n--;
	return true;
}

template<class T>
int set<T>::size()
{
	return n+1;
}

template<class T>
set<T> set<T>::unions(set<T> s2)
{
	set<T> s3;

	for(int i=0;i<=n;i++)
	{
		s3.insert(data[i]);
	}

	for(int i=0;i<=s2.n;i++)
	{
		int flag=0;
		for(int j=0;j<=n;j++)
		{
			if(s2.data[i]==data[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			s3.insert(s2.data[i]);
	}

	return s3;
}

template<class T>
set<T> set<T>::intersect(set<T> s2)
{
	set<T> s3;

	for(int i=0;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<=s2.n;j++)
		{
			if(s2.data[j]==data[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			s3.insert(data[i]);
	}

	return s3;
}

template<class T>
set<T> set<T>::diff(set<T> s2)
{
	set<T> s3;

	for(int i=0;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<=s2.n;j++)
		{
			if(s2.data[j]==data[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			s3.insert(data[i]);
	}

	return s3;
}

template<class T>
bool set<T>::subset(set<T> s2)
{
	if(n>s2.n)
	{
		for(int i=0;i<=s2.n;i++)
		{
			int flag=0;
			for(int j=0;j<=n;j++)
			{
				if(s2.data[i]==data[j])
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
				return false;
		}
		return true;
	}
	return false;
}

void choices()
{
	cout	<<"\n1.Insert  \n"
			<<"2.Remove  \n"
			<<"3.Contains  \n"
			<<"4.Union \n"
			<<"5.Intersection \n"
			<<"6.Difference\n"
			<<"7.Size \n"
			<<"8.Subset \n"
			<<"9.Display sets.\n";
}

int main()
{
	int ch;
	char yes='y';

	set<int>s1,s2,s3;
	int n1,n2;

	cout<<"Enter the no. of elements in set 1. ";
	cin>>n1;
	s1.input(n1);
	cout<<"Enter the no. of elements in set 2. ";
	cin>>n2;
	s2.input(n2);

	do{

		choices();
		cin>>ch;

		switch(ch)
		{
		case 1:
		{
			int element;
			cout<<"Enter the element. ";
			cin>>element;
			if(s1.insert(element))
				cout<<"Insertion successfull.";
		}
		break;
		case 2:
		{
			int element;
			cout<<"Enter the element. ";
			cin>>element;
			if(s1.remove(element))
				cout<<"Deleted. ";
		}
		break;
		case 3:
		{
			int element;
			cout<<"Enter the element";
			cin>>element;
			if(s1.contains(element))
				cout<<"Element present.";
			else
				cout<<"Element not present.";
			break;
		}
		case 4:
		{
			s3=s1.unions(s2);
			cout<<"Elements of s1 are ";
			s1.print();
			cout<<"Elements of s2 are ";
			s2.print();
			cout<<"Elements of s3 are ";
			s3.print();

		}
		break;
		case 5:
		{
			s3=s1.intersect(s2);
			cout<<"Elements of s1 are ";
			s1.print();
			cout<<"Elements of s2 are ";
			s2.print();
			cout<<"Elements of s3 are ";
			s3.print();

		}

		break;
		case 6:
		{
			s3=s1.diff(s2);
			cout<<"Elements of s1 are ";
			s1.print();
			cout<<"Elements of s2 are ";
			s2.print();
			cout<<"Elements of s3 are ";
			s3.print();

		}

		break;
		case 7:
		{
			cout<<"\nSize of s1 is "<<s1.size();
			cout<<"\nSize of s2 is "<<s2.size();
			cout<<"\nSize of s3 is "<<s3.size();
		}
		break;
		case 8:
		{
			if(s1.subset(s2))
				cout<<"s2 is a subset of s1.\n";
			else if(s2.subset(s1))
				cout<<"s1 is a subset of s2.\n";
			else
				cout<<"Neither of s1 or s2 is a subset of other.\n";
		}

			break;
		case 9:

			cout<<"Elements of s1 are ";
			s1.print();
			cout<<"Elements of s2 are ";
			s2.print();
			cout<<"Elements of s3 are ";
			s3.print();
			break;

		default:
			cout<<"Wrong choice.\n";
		}
		cout<<"\nDo you want to continue? (y/n)";
		cin>>yes;
	}while(yes=='y');

	return 0;
}

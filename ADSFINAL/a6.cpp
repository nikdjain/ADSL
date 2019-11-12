#include<iostream>
#define max 10
using namespace std;

class dictionary
{
	private:
		string word;
		string mean;
	public:	
		dictionary()
		{
			word = " ";
			mean = " ";
		}
		friend class hashing;
};

class hashing
{
	private:
		dictionary arr[10];
		int p;
	public:
		void create(int q)
		{
			p = 0;
			string key, value;
			char ans;
			do
			{
				cout << "Enter keyword" << endl;
				cin >> key;
				cout << "Enter value" << endl;
				cin >> value;
				if(q == 1)
				{
					insert1(key, value);
				}
				if(q == 2)
				{
					insert2(key, value);
				}
				cout << "Do you want to enter more data(y/n)" << endl;
				cin >> ans;
				if(ans == 'n')
				{
					break;
				}
				else
				{
					continue;
				}
				p++;
			}while(p < 10);
			if(p == 10)
			{
				cout << "Cannot enter more data" << endl;
				return;
			}
		}	
		
		int hf(string key)
		{
			char ch;
			ch = key.at(0);
			return int(ch);	
		}
		void insert1(string key, string value)
		{
			int index;
			index = hf(key) % 10;
			if(arr[index].word == " ")
			{
				arr[index].word = key;
				arr[index].mean = value;
			}
			else
			{
				int q = 0;
				while(arr[index].word != " ")
				{
					index = (index + 1) % max;
					q++;
					if(q == 10)
					{
						cout << "No space!" << endl;
						return;
					}
				}
				arr[index].word = key;
				arr[index].mean = value;
			}
		}
		
		void insert2(string key, string value)
		{
			int index;
			index = hf(key) % 10;
			if(arr[index].word == " ")
			{
				arr[index].word = key;
				arr[index].mean = value;
			}
			else
			{
				int q = 0;
				int p = hf(arr[index].word) % 10;
				if(p == index)
				{
					while(arr[index].word != " ")
					{
						index = (index + 1) % max;
						q++;
						if(q >= 10)
						{
							cout << "No space!" << endl;
							return;
						}
					}
					arr[index].word = key;
					arr[index].mean = value;
				}
				else
				{
					dictionary s = arr[index];
					arr[index].word = key;
					arr[index].mean = value;
					while(arr[index].word != " ")
					{
						index = (index + 1) % 10;
						q++;
						if(q == 10)
						{
							cout << "No space" << endl;
							return;
						}
					}
					arr[index] = s;
				}
			}
		}
		
		void display()
		{
			for(int i = 0; i < max; i++)
			{
				if(arr[i].word == " ")
				{
					cout << "Empty!" << endl;
				}
				else
				{
					cout << arr[i].word << " " << arr[i].mean << endl;
				}
			}
		}
		
		int find(string x)
		{
			int index = hf(x) % 10;
			if(arr[index].word == x)
			{
				return index;
			}
			else
			{
				int q = 0;
				while(arr[index].word != x)
				{
					index = (index + 1) % max;
					q++;
					if(q == 10)
					{
						break;
					}
				}
				if(arr[index].word != x)
				{
					return -1;
				}
				return index;
			}
		}
		void found(int index)
		{
			cout << "Data found!" << endl;
			cout << arr[index].word << " " << arr[index].mean << endl;
		}
		
		void delete_data()
		{
			string x;
			cout << "Enter word you wish to delete :" << endl;
			cin >> x;
			int index = find(x);
			if(index == -1)
			{
				cout << "Data not present!" << endl;
				return;
			}
			arr[index].word = " ";
			arr[index].mean = " ";
		}
};

int main()
{
	int ch, q = 0;
	hashing obj;
	cout << "1. Enter Information" << endl;
	cout << "2. Find" << endl;
	cout << "3. Delete" << endl;
	do
	{
		cout << "Enter your choice :" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				int z;
				cout << "1. Linear probing without replacement" << endl;
				cout << "2. Linear probing with replacement" << endl;
				cin >> z;
				obj.create(z);
				cout << "Display Information :" << endl;
				obj.display();
				break;
			}
			case 2:
			{
				string x;
				cout << "Enter word you want to find" << endl;
				cin >> x;
				int n;
				n = obj.find(x);
				if(n == -1)
				{
					cout << "Not found" << endl;
				}
				else
				{
					obj.found(n);
				}
				break;
			}
			case 3:
			{
				obj.delete_data();
				cout << "List now is :" << endl;
				obj.display();
				break;
			}
		}
		cout << "Do you wish to continue?(1/0)" << endl;
		cin >> q;
	}while(q == 1);
	return 0;
}

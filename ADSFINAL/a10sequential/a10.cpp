#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class student
{
	private:
		int roll;
		char name[20];
	public:
		student()
		{
			roll = -1;
			name[0] = '$';
		}
		friend class fop;
};

class fop
{
	private:
		student sg = student(), sp = student();
	public:
		fop()
		{
			//TODO
		}
		
		void init()
		{
			fstream fout("a.txt", ios::out | ios::binary);
			for(int i = 0; i < 10; i++)
			{
				fout.write((char *)&sp, sizeof(sp));	
			}	
			fout.close();
		}	
		
		void display()
		{
			fstream fout;
			fout.open("a.txt", ios::in | ios::out | ios::binary);
			for(int i = 0; i < 10; i++)
			{
				fout.seekg((sizeof(sg))*i, ios::beg);
				fout.read((char *)&sg, sizeof(sg));
				cout << sg.roll << setw(15) << sg.name << endl;
			}
		}
		
		void create()
		{
			fstream fout("a.txt", ios::in | ios::out | ios::binary);
			cin.ignore(1);
			cout << "Enter name :" << endl;
			cin.getline(sp.name, 9);
			cout << "Enter roll no. :" << endl;
			cin >> sp.roll;
			
			int index = (sp.roll) % 10;
			fout.seekg((sizeof(sg))*index, ios::beg);
			fout.read((char *)&sg, sizeof(sg));
			
			if(sg.roll == -1)
			{
				fout.seekp((sizeof(sp))*index, ios::beg);
				fout.write((char *)&sp, sizeof(sp));
			}
			else
			{
				int i = (index + 1) % 10;
				while(sg.roll != -1 && i != index)
				{
					fout.seekg((sizeof(sg))*i, ios::beg);
					fout.read((char *)&sg, sizeof(sg));
					i = (i + 1) % 10;
				}
				int f = i;
				fout.seekp((sizeof(sp))*f, ios::beg);
				fout.write((char *)&sp, sizeof(sp));
			}
		}
		
		int find()
		{
			int r;
			cout << "Enter roll no. to find :" << endl;
			cin >> r;
			int index = r % 10;
			fstream fout("a.txt", ios::in | ios::out | ios::binary);
			fout.seekg((sizeof(sg))*index, ios::beg);
			fout.read((char *)&sg, sizeof(sg));
			
			if(r == sg.roll)
			{
				cout << "Found!" << endl;
				cout << sg.roll << setw(15) << sg.name;
				return index;
			}
			else
			{
				int ind = (r + 1) % 10;
				while(ind != index && sg.roll != r)
				{
					ind = (ind + 1) % 10;
					fout.seekg((sizeof(sg))*ind, ios::beg);
					fout.read((char *)&sg, sizeof(sg));
				}
				if(sg.roll == r)
				{
					cout << "Found!" << endl;
					return ind;
				}
				else
				{
					cout << "Not Found!" << endl;
					return -1;
				}
			}
		}
};

int main()
{
	fop f;
	int ch, q = 0;
	do
	{
		cout << "1. Initialize" << endl;
		cout << "2. Display" << endl;
		cout << "3. Create" << endl;
		cout << "4. Find" << endl;
		cout << "5. Modify" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				f.init();
				break;
			}
			case 2:
			{
				f.display();
				break;
			}
			case 3:
			{
				f.create();
				break;
			}
			case 4:
			{
				f.find();
				break;
			}
			/*case 5:
			{
				f.modify();
				break;
			}*/
		}
		cout << "(1/0)";
		cin >> q;
	}while(q == 1);
	return 0;
}

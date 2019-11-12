#include <iostream>
#include <cstring>
#include <fstream>
#define MAX 10
using namespace std;

class student
{
	int roll;
	char name[10];
	
	public:
		student()
		{
			roll=-1;
			name[0]='#';
		}
		
		void getdata()
		{
			cout<<"Enter the name of student : ";
			cin>>name;
			cout<<"Enter the roll no. : ";
			cin>>roll;
		}
		
		void display()
		{
			cout<<"Name: "<<name<<"\tRoll no.: "<<roll<<endl;
		}
		
		friend class hash;
};

class hash
{
	student sp,sg;
	
	public:
		
		
		void init()
		{
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			
			for(int i=0;i<MAX;i++)
			{
				fout.write((char*)&sp,sizeof(sp));
			}
			fout.close();
		}
		
		void create()
		{
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			int rp,rg;
			sp=student();
			sg=student();
			sp.getdata();
			rp=sp.roll;
			rp=rp%MAX;
			
			int r=rp;
			fout.seekg(sizeof(sg)*rp,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			rg=sg.roll;
			
			while(rg!=-1)
			{
				r=(r+1)%MAX;
				fout.seekg(sizeof(sg)*r,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			rg=sg.roll;
				
				
			}
			fout.seekp(sizeof(sp)*r,ios::beg);
			fout.write((char*)&sp,sizeof(sp));
			
			fout.close();
		}
		
		void display1()
		{
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			int r=0;
			for(int i=0;i<MAX;i++)
			{
				fout.seekg(sizeof(sg)*i,ios::beg);
				fout.read((char*)&sg,sizeof(sg));
				sg.display();
			}
			fout.close();
		}
		
		void find()
		{
			int r;
			cout<<"Enter the roll no of the student : ";
			cin>>r;
			int r1=r%MAX;
			int flag=0;
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			int i=0;
			while(i<MAX)
			{
			fout.seekg(sizeof(sg)*r1,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			
			if(sg.roll==r)
			{
				flag=1;
				break;
			}
			r1=(r1+1)%MAX;
			i++;
		}
		if(flag==1)
		{
			cout<<"Found\n";
			sg.display();
		}
		else{
			cout<<"Not found.\n";
		}
		fout.close();
	}
	
		void update()
		{
			int r;
			cout<<"Enter the roll no of the student : ";
			cin>>r;
			int r1=r%MAX;
			int flag=0;
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			int i=0;
			while(i<MAX)
			{
			fout.seekg(sizeof(sg)*r1,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			
			if(sg.roll==r)
			{
				flag=1;
				break;
			}
			r1=(r1+1)%MAX;
			i++;
		}
		if(flag==1)
		{
			cout<<"Found\n";
			sg.display();
			cout<<"Enter new name : ";
			cin>>sg.name;
			fout.seekp(sizeof(sg)*r1,ios::beg);
			fout.write((char*)&sg,sizeof(sg));
		}
		else{
			cout<<"Not found.\n";
		}
		fout.close();
	}
	
	void del()
		{
			int r;
			cout<<"Enter the roll no of the student : ";
			cin>>r;
			int r1=r%MAX;
			int flag=0;
			fstream fout;
			fout.open("data.txt",ios::in | ios::out | ios::binary);
			int i=0;
			while(i<MAX)
			{
			fout.seekg(sizeof(sg)*r1,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			
			if(sg.roll==r)
			{
				flag=1;
				break;
			}
			r1=(r1+1)%MAX;
			i++;
		}
		if(flag==1)
		{
			cout<<"Deleted.\n";
			sg=student();
			fout.seekp(sizeof(sg)*r1,ios::beg);
			fout.write((char*)&sg,sizeof(sg));
		}
		else{
			cout<<"Not found.\n";
		}
		fout.close();
	}
	
	
};

int main()
{
	hash H;
	H.init();
	int ch;
	char yes='y';
	
	do{
		cout<<"1.Create.\n2.Add.\n3.Update.\n4.Remove\n5.Display\n6.Find.\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
				
				int n;
				cout<<"Enter the no entries to enter: ";
				cin>>n;
				for(int i=0;i<n;i++)
				H.create();
				break;
			}
			case 2:
				H.create();
				break;
			case 3:
				H.update();
				break;
			case 4:
				H.del();
				break;
			case 5:
				H.display1();
				break;
			case 6:
				H.find();
				break;
			default:
					cout<<"Wrong choice";
		}
		cout<<"Continue?(y/n)\n";
		cin>>yes;
	}while(yes=='y');
	return 0;
}















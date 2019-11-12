package Definition;

import Declaration.Interface;
import java.util.*;

class node{
	public int data;
	public node link;

node(int x)
	{
		data=x;
		link=null;
	}

}

public class SLL implements Interface{
	node head;
	node end;
	int size;


	SLL()
	{
		head=null;
		end=null;
		size=0;
	}

	public boolean isEmpty()
	{
		if(head==null)
			return true;
		return false;
	}

	public void insert(int x)
	{
		node temp=new node(x);
		size++;
		if(head==null)
		{
			head=temp;
			end=head;
		}
		else{
			end.link=temp;
			end=temp;
		}
	}

	public int size()
	{
		return size;
	}

	public void display()
	{
		if(head==null)
		{
			System.out.println("List is empty.\n");
			return;
		}
		node temp=head;
		while(temp.link!=null)
		{
			System.out.print(+temp.data+" -> ");
			temp=temp.link;
		}
		System.out.println(temp.data);
	}

	public void delete(int x)
	{
		if(head.data==x)
		{
			size--;
			node temp=head;
			head=head.link;
			temp=null;
			System.gc();
		}
		else{
			node p=head;
			node temp=head;
			int flag=0;
			while(temp.link!=null && temp.data!=x )
			{
				p=temp;
				temp=temp.link;
				if(temp.data==x)
					flag=1;
			}

			if(flag==0)
			{
				System.out.println("Data not present");
				return;
			}
			else{
				size--;
				p.link=temp.link;
				temp=null;
				System.gc();
			}
		}
	}

	public static void main(String[] args) {
		SLL s=new SLL();
		int flag=0;
		Scanner sc=new Scanner(System.in);
		int ch;
		while(flag!=1)
		{
			System.out.println("1.Insert\n2.Delete\n3.Display\n4.Size\n5.Is empty?\n");
			ch=sc.nextInt();

			switch(ch)
			{
				case 1:
				{
					System.out.println("Enter the element.\n");
					int e;
					e=sc.nextInt();
					s.insert(e);
				}

				break;

				case 2:
				{
					System.out.println("Enter the element.\n");
					int e;
					e=sc.nextInt();
					s.delete(e);
				}

				break;

				case 3:
				{
					s.display();
				}

				break;

				case 4:
				{
					System.out.println("Size of list is "+s.size()+"\n");
				}
				break;
				
				case 5:
				{
					if(s.isEmpty())
					{
						System.out.println("List is empty.\n");
					}
					else
						System.out.println("List is not empty.\n");
				}
				break;

				default:
				System.out.println("Wrong choice.");
			}
			System.out.println("Exit? (1/0)\n");
			flag=sc.nextInt();
		}
	}
}

import java.util.*;

abstract class stack
{
	stack()
	{
		
	}

	public final void myFunc()
	{
		int flag=1;
		int op;
		
		while(flag==1)
		{
			System.out.print("1.Push\n2.Pop\n3.Top\n4.Display\n");
			Scanner sc=new Scanner(System.in);
			op=sc.nextInt();

			switch(op)
			{
				case 1:
				{
					if(push())
						System.out.println("Data pushed.");
				}
				break;
				case 2:
				{
					if(pop())
						System.out.println("Data popped.");
				}
				break;
				case 3:
				{
					if(top())
						System.out.print(" is at the top.");
				}
				break;
				case 4:
				{
					System.out.println("Stack is  ");
					display();
				}
				break;
				default:
					System.out.println("Invalid choice.");
			}

			System.out.println("Do you want to continue.");
			flag=sc.nextInt();
		}


	}

	abstract protected boolean push();
	abstract protected boolean pop();
	abstract protected boolean top();
	abstract protected void display();
}


class IntStack extends stack
{
	int[] stack = new int[5];
	int top;
	Scanner sc = new Scanner(System.in);

	IntStack()
	{
		top=-1;
	}

	protected boolean push()
	{
		System.out.print("Enter the data. ");
		int data=sc.nextInt();
		try{
			RuntimeException re=new RuntimeException("Overflow!!");
			if(top==4)
				throw re;
			else
			{
				stack[++top]=data;
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected boolean pop()
	{
		try{
			RuntimeException re=new RuntimeException("Underflow!!");
			if(top==-1)
				throw re;
			else
			{
				top--;
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected boolean top()
	{
		try{
			RuntimeException re=new RuntimeException("Underflow!!");
			if(top==-1)
				throw re;
			else
			{
				System.out.print(stack[top]);
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected void display()
	{
		int tmp=top;

		while(tmp!=-1)
		{
			System.out.println(stack[tmp]);
			tmp--;
		}
	}
}

class CharStack extends stack
{
	char[] stack = new char[5];
	int top;
	Scanner sc = new Scanner(System.in);

	CharStack()
	{
		top=-1;
	}

	protected boolean push()
	{
		System.out.print("Enter the data. ");
		char data=sc.next().charAt(0);
		try{
			RuntimeException re=new RuntimeException("Overflow!!");
			if(top==4)
				throw re;
			else
			{
				stack[++top]=data;
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected boolean pop()
	{
		try{
			RuntimeException re=new RuntimeException("Underflow!!");
			if(top==-1)
				throw re;
			else
			{
				top--;
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected boolean top()
	{
		try{
			RuntimeException re=new RuntimeException("Underflow!!");
			if(top==-1)
				throw re;
			else
			{
				System.out.print(stack[top]);
				return true;
			}
		}

		catch(RuntimeException re)
		{
			System.out.println("Exception caught : "+re);
			return false;
		}
	}

	protected void display()
	{
		int tmp=top;

		while(tmp!=-1)
		{
			System.out.println(stack[tmp]);
			tmp--;
		}
	}
}



class MainStack{

	public static void main(String[] args) {
		int op;
		int flag=1;
		Scanner sc= new Scanner(System.in);

		do{
			System.out.println("1.IntStack\n2.CharStack.");
			op=sc.nextInt();

			if(op==1)
			{
				stack T = new IntStack();
				T.myFunc();
			}

			else if(op==2)
			{
				stack T = new CharStack();
				T.myFunc();
			}

			else
				System.out.println("Invalid choice.");

			System.out.println("Do you want to continue ? (1/0)");
			flag=sc.nextInt();
		}while(flag==1);
	}
}
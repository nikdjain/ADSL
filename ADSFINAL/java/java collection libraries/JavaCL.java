import java.util.*;

class JavaCL{
 Scanner sc= new Scanner(System.in);
	 void main_func()
	{
		 int op;
		 
		  int flag=1;

		  while(flag==1)
		  {
		  	System.out.println("1.Linked List \n2.Stack \n3.HashSet \n4.Priority Queue \n5.Deque");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			Linked();
		  		}
		  		break;

		  		case 2:
		  		{
		  			stack();
		  		}
		  		break;

		  		case 3:
		  		{
		  			hashset();
		  		}
		  		break;

		  		case 4:
		  		{
		  			priorityQ();
		  		}
		  		break;

		  		case 5:
		  		{
		  			Dqueue();
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}
	

	public void Linked()
	{
			 int op;
		  // Scanner sc= new Scanner(System.in);
		  int flag=1;
		  LinkedList<Integer> l=new LinkedList<Integer>();

		  while(flag==1)
		  {
		  	System.out.println("1.Add first \n2.Add last \n3.Remove First \n4.Remove last \n5.Display");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.addFirst(data);
		  		}
		  		break;

		  		case 2:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.addLast(data);
		  		}
		  		break;

		  		case 3:
		  		{
		  			
		  			l.removeFirst();
		  		}
		  		break;

		  		case 4:
		  		{
		  			l.removeLast();
		  		}
		  		break;

		  		case 5:
		  		{
		  			System.out.println("Elements of list are  "+l);
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}
	

	public void stack()
	{
		 int op;
		  // Scanner sc= new Scanner(System.in);
		  int flag=1;
		  Stack<Integer> l=new Stack<Integer>();

		  while(flag==1)
		  {
		  	System.out.println("1.Push \n2.Pop \n3.Top \n4.Size \n5.Display");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.push(data);
		  		}
		  		break;

		  		case 2:
		  		{
		  			System.out.println("Element popped is "+l.pop());
		  			
		  		}
		  		break;

		  		case 3:
		  		{
		  			System.out.println("Element at top is "+l.peek());
		  		}
		  		break;

		  		case 4:
		  		{
		  			System.out.println("Size of stack is "+l.size());
		  		}
		  		break;

		  		case 5:
		  		{
		  			System.out.println("Elements of stack are  "+l);
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}

	

	public void priorityQ()
	{
			 int op;
		  // Scanner sc= new Scanner(System.in);
		  int flag=1;
		  PriorityQueue<Integer> l=new PriorityQueue<Integer>();

		  while(flag==1)
		  {
		  	System.out.println("1.Add \n2.Pop \n3.head \n4.Size \n5.Display");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.add(data);
		  		}
		  		break;

		  		case 2:
		  		{
		  			System.out.println("Element popped is "+l.poll());
		  			
		  		}
		  		break;

		  		case 3:
		  		{
		  			System.out.println("Element at top is "+l.peek());
		  		}
		  		break;

		  		case 4:
		  		{
		  			System.out.println("Size of stack is "+l.size());
		  		}
		  		break;

		  		case 5:
		  		{
		  			System.out.println("Elements of stack are  "+l);
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}

	public void hashset()
	{
		int op;
		  // Scanner sc= new Scanner(System.in);
		  int flag=1;
		  HashSet<Integer> l=new HashSet<Integer>();

		  while(flag==1)
		  {
		  	System.out.println("1.ADD \n2.Remove \n3. \n4.Size \n5.Display");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.add(data);
		  		}
		  		break;

		  		case 2:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.remove(data);
		  			
		  		}
		  		break;

		  		case 3:
		  		{
		  			// System.out.println("Element at top is "+l.peek());
		  		}
		  		break;

		  		case 4:
		  		{
		  			System.out.println("Size of hash set is "+l.size());
		  		}
		  		break;

		  		case 5:
		  		{
		  			System.out.println("Elements of hash set are  "+l);
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}

	public void Dqueue()
	{
			 int op;
		  // Scanner sc= new Scanner(System.in);
		  int flag=1;
		  ArrayDeque<Integer> l=new ArrayDeque<Integer>();

		  while(flag==1)
		  {
		  	System.out.println("1.Add first \n2.Add last \n3.head \n4.Size \n5.Display \n6.tail\n7.remove first\n8.removelast");
		  	op=sc.nextInt();

		  	switch(op)
		  	{
		  		case 1:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.addFirst(data);
		  		}
		  		break;

		  		case 2:
		  		{
		  			System.out.println("Enter the element. ");
		  			int data=sc.nextInt();
		  			l.addLast(data);
		  			//System.out.println("Element popped is "+l.pop());
		  			
		  		}
		  		break;

		  		case 3:
		  		{
		  			System.out.println("Element at top is "+l.peekFirst());
		  		}
		  		break;

		  		case 4:
		  		{
		  			System.out.println("Size of stack is "+l.size());
		  		}
		  		break;

		  		case 5:
		  		{
		  			System.out.println("Elements of stack are  "+l);
		  		}
		  		break;

		  		case 6:
		  		{
		  			System.out.println("Element at top is "+l.peekLast());
		  		}
		  		break;
		  		case 7:
		  		{
		  			System.out.println("Element popped is "+l.pollFirst());
		  			
		  		}
		  		break;
		  		case 8:
		  		{
		  			System.out.println("Element popped is "+l.pollLast());
		  			
		  		}
		  		break;

		  		default:
		  			System.out.println("Invalid input.");
		  	}
		  	System.out.println("Do you want to continue?(1/0)");
		  	flag=sc.nextInt();
		  }
	}

	public static void main(String[] args) {

		JavaCL T=new JavaCL();
		T.main_func();
}
}

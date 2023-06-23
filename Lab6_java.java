import java.util.Scanner;

class InvalidAgeException extends Exception  
{  
    public InvalidAgeException (String str)  
    {  
         
        super(str); 
	//System.out.println("hello"); 
    }  
} 

class Father {
	int age;
	Father() throws InvalidAgeException {
		
		Scanner ss=new Scanner(System.in);
		System.out.println("Enter Father's Age: ");
		age=ss.nextInt();
		if(age<0) {
			throw new InvalidAgeException("age is negative");
		}
		else {
			System.out.println("Proper Age");
		}
	}
}
class Son extends Father {
	int sage;
	Son() throws InvalidAgeException {
		Scanner ss=new Scanner(System.in);
		
		System.out.println("Enter Son's Age: ");
		age=ss.nextInt();
		if(sage>=age) {
			throw new InvalidAgeException("Son's Age is Wrong");
		}
		else {
			System.out.println("Proper Age");
		}
	}
}

class fsmain {
	public static void main(String xx[]) {
		try {
			
			Son s1=new Son();
		}
		catch(InvalidAgeException ex) {
			System.out.println(ex);
		}
	}
}















///// try1

import java.util.Scanner;

class InvalidSAgeException extends Exception  
{  
    public InvalidSAgeException (String str)  
    {  
         
        super(str); 
	//System.out.println("hello"); 
    }  
} 

class InvalidAgeException extends Exception  
{  
    public InvalidAgeException (String str)  
    {  
         
        super(str); 
	//System.out.println("hello"); 
    }  
} 

class Father {
	int age;
	Father() throws InvalidAgeException {
		
		Scanner ss=new Scanner(System.in);
		System.out.println("Enter Father's Age: ");
		age=ss.nextInt();
		if(age<0) {
			throw new InvalidAgeException("age is negative");
		}
		else {
			System.out.println("Proper Age");
		}
	}
}
class Son extends Father {
	int sage;
	Son() throws InvalidSAgeException {
		Scanner ss=new Scanner(System.in);
		
		System.out.println("Enter Son's Age: ");
		age=ss.nextInt();
		if(sage>=age) {
			throw new InvalidSAgeException("Son's Age is Wrong");
		}
		else {
			System.out.println("Proper Age");
		}
	}
}

class fsmain {
	public static void main(String xx[]) {
		try {
			
			Son s1=new Son();
		}
		catch(InvalidSAgeException ex) {
			System.out.println(ex);
		}
		try {
			Father f1=new Father();
		}
		catch(InvalidAgeException exx) {
			System.out.println(exx);
		}
	}
}

package cie;

import java.util.Scanner;

class student {  //rename the file as student.java make it public and execute
	String sname=new String();
	String usn=new String();
	int sem;

	public student() {
		Scanner s=new Scanner(System.in);

		System.out.println("Enter your name: ");
		sname=s.next();
		System.out.println("Enter your usn: ");
		usn=s.next();
		System.out.println("Enter your sem: ");
		sem=s.nextInt();
	}		
}

public class internal extends student {  //when this is public, save the file as internal.java and save it
	protected float marks[]=new float[5];
	public internal() {
		Scanner ss=new Scanner(System.in);
		for(int i=0;i<5;i++) {
			marks[i]=ss.nextInt();
		}
	}
}

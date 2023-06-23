import java.util.Scanner;
import java.lang.Math;

public class QuadEq {
	public static void main (String ss[]) {
	Scanner x = new Scanner(System.in);
	System.out.print("Enter the value of a: ");
	double a;
	do {
		System.out.println("make sure it is not 0");
		a=x.nextDouble();
	}while(a==0);
	

	System.out.print("Enter the value of b: ");
	double b=x.nextDouble();
	System.out.print("Enter the value of c: ");
	double c=x.nextDouble();

	double d=b*b-(4*a*c);
	double r1,r2;

	
	
	

	if(d>0) {
		r1=(-b + Math.sqrt(d))/(2*a);
		r2=(-b - Math.sqrt(d))/(2*a);
		System.out.println("Roots are real and distinct");
		System.out.println("Roots are: "+r1+" and "+r2);
	}
	
	else if(d==0) {
		r1=r2=-b/(2*a);
		System.out.println("Root is real and unique");
		System.out.println("Root is: "+r1);
	}
	else {
		r1=-b/(2*a);
		r2=Math.sqrt(Math.abs(d)/(2*a));
		System.out.println("There are no real solutions");
		System.out.println("Roots are imaginary and distinct");
		System.out.println("Root 1 is: "+r1+" + i"+r2);
		System.out.println("Root 2 is: "+r1+" - i"+r2);
	}
	
}
}

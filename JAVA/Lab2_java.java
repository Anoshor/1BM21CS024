import java.util.Scanner;

class student {
	String usn;
	String name;
	int credits[];
	double marks[];

	student() {
		Scanner s=new Scanner(System.in);
		int n;
		System.out.println("Enter no. of subjects: ");
		n=s.nextInt();
		this.credits=new int[n];
		this.marks=new double[n];
		
	}
	
	void getsd() {
		Scanner x=new Scanner(System.in);
		System.out.println("enter usn, name, credits, marks for subjects");
		usn=x.nextLine();
		name=x.nextLine();
		for(int i=0;i<6;i++) {
			credits[i]=x.nextInt();
		}
		for(int i=0;i<6;i++) {
			marks[i]=x.nextDouble();
		}
	
	}
	
	void putsd() {
		System.out.println("USN: "+this.usn);
		System.out.println("Name: "+this.name); 
		System.out.println("Marks: ");
		for(int i=0;i<6;i++) {
			System.out.print(this.marks[i]+" ");
		}
		System.out.println("\nCredits: "); 
		for(int i=0;i<6;i++) {
			System.out.print(this.credits[i]+" ");
		}
	}
	
	void sgpa() {
		double marks=0;
		double t_credits=0;
		for(int i=0;i<6;i++) {
			if(this.marks[i]>=90) { 
				marks=marks+(10*(this.credits[i]));
			}
			else if(this.marks[i]>=80) {
				marks=marks+(9*(this.credits[i]));
			}
			else if(this.marks[i]>=70) {
				marks=marks+(8*(this.credits[i]));
			}
			else if(this.marks[i]>=60) {
				marks=marks+(7*(this.credits[i]));
			}
			else if(this.marks[i]>=50) {
				marks=marks+(6*(this.credits[i]));
			}
			else if(this.marks[i]>=40) {
				marks=marks+(5*(this.credits[i]));
			}
			else if(this.marks[i]>=30) {
				marks=marks+(4*(this.credits[i]));
			}
			else {
				marks=marks+0;
			}
			t_credits=t_credits+(this.credits[i]);
		}
		double sgp=(marks/t_credits);
		System.out.println("\nYour SGPA is: "+sgp);
	}
}

class smain {
	public static void main(String xx[]) {
		student s1=new student();
		s1.getsd();
		s1.putsd();
		s1.sgpa();
	}
}
	

import java.util.Scanner;

abstract class Figure {
	int no_para;
	double area;
	abstract void printArea();
	abstract void calc_perimeter();
}
class Rectangle extends Figure {
	
	int sides[]=new int[4];
	
	Rectangle() {
		System.out.println("Figure is a Rectangle");
		no_para=4;
		Scanner ss=new Scanner(System.in);
		
		System.out.println("Enter the 2 adjacent sides: ");
		for(int i=0;i<2;i++) {
			sides[i]=ss.nextInt();
			sides[i+2]=sides[i];
		}
	}
	void printArea() {
		area=sides[0]*sides[1];
		System.out.println("Area of Rectangle is "+area);
	}
	void calc_perimeter() {
		double sum=0;
		for(int i=0;i<4;i++) {
			sum=sum+sides[i];
		}
		System.out.println("Perimeter of Rectangle is: "+sum);
	}
}

class Triangle extends Figure {
	int sides[]=new int[3];

	Triangle() {
		System.out.println("Figure is a Triangle");
		no_para=3;
		Scanner ss=new Scanner(System.in);
		System.out.println("Enter the 3 sides: ");
		for(int i=0;i<3;i++) {
			sides[i]=ss.nextInt();
		}
	}
	void printArea() {
		double s=(sides[0]+sides[1]+sides[2])/2;
		if((sides[0]+sides[1]<=sides[2])||(sides[0]+sides[2]<=sides[1])||(sides[2]+sides[1]<=sides[0])) {
			System.out.println("Invalid Inputs\n");
		}
		else {
			area=(double)Math.sqrt(s*(s-sides[0])*(s-sides[1])*(s-sides[2]));
			System.out.println("Area of Triangle is "+area);
		}
	}
	void calc_perimeter() {
		double sum=0;
		for(int i=0;i<3;i++) {
			sum=sum+sides[i];
		}
		System.out.println("Perimeter of Triangle is: "+sum);
	}
}

class Circle extends Figure {
	int sides[]=new int[1];

	Circle() {
		System.out.println("Figure is a circle");
		no_para=1;
		Scanner ss=new Scanner(System.in);
		System.out.println("Enter the circle radius: ");
		sides[0]=ss.nextInt();
	}
	void printArea() {
		area=(3.14)*sides[0]*sides[0];
		System.out.println("Area of circle is "+area);
	}
	void calc_perimeter() {
		double sum=2*(3.14)*sides[0];
		System.out.println("Circumference is: "+sum);
	}
}

class fmain {
	public static void main(String ss[]) {
		Rectangle r1=new Rectangle();
		Triangle t1=new Triangle();
		Circle c1=new Circle();
		r1.printArea();
		r1.calc_perimeter();
		t1.printArea();
		t1.calc_perimeter();
		c1.printArea();
		c1.calc_perimeter();
	}
}

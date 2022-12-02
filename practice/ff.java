import java.util.Scanner;

abstract class Figure {
	int no_para;
	abstract void calc_area();
	abstract void calc_perimeter();
}
class Rectangle extends Figure {
	
	
	Rectangle() {
		System.out.println("Figure is a Rectangle");
		no_para=4;
		Scanner ss=new Scanner(System.in);
		int sides[]=new int[4];
		System.out.println("Enter the 2 sides");
		for(int i=0;i<2;i++) {
			sides[i]=ss.nextInt();
			sides[i+2]=sides[i];
		}
	}
	void calc_area() {
		int area=sides[0]*sides[1];
		System.out.println("Area is "+area);
	}
	void calc_perimeter() {
		int sum=0;
		for(int i=0;i<4;i++) {
			sum=sum+sides[i];
		}
	}
}

class fmain {
	public static void main(String ss[]) {
		Rectangle r1=new Rectangle();
		r1.calc_area();
	}
}

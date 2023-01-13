package see;

import java.util.Scanner;
import cie.internal;

public class external extends internal {
	float marks2[]=new float[5];
	public external() {
		Scanner ss=new Scanner(System.in);
		for(int i=0;i<5;i++) {
			marks2[i]=ss.nextFloat();
		}
	}
	public void calc() {
		for(int i=0;i<5;i++) {
			System.out.println(marks[i]+marks2[i]);
		}
	}
}

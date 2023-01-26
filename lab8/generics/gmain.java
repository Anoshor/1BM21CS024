import java.util.Scanner;

class gen1<T1, T2> {
	int x;
	private T1 t1;
	private T2 t2;

	gen1(T1 t1,T2 t2) {
		this.t1=t1;
		this.t2=t2;
	}
	
	void getvaltype () {
		System.out.println("t1 is of type "+t1.getClass().getName()+" and has value "+t1);
		System.out.println("t2 is of type "+t2.getClass().getName()+" and has value "+t2);
	}
}

class gmain {
	public static void main(String sss[]) {
		gen1<Integer,String> g1=new gen1<Integer,String>(10,"Anoshor");
		g1.getvaltype();
	}
}

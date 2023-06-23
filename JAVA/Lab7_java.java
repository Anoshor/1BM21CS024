class thread1 implements Runnable {
	Thread t;
	thread1(String ss) {
		t=new Thread(this,"New Thread");
		//System.out.println(t);
	}
	public void run() {
		try {
			for(int i=5;i>0;i--) {
				System.out.println("BMS College of Engineering");
				Thread.sleep(10000);
			}
		}
		catch(InterruptedException ie) {
			System.out.println("Thread interrupted");
		}
		//System.out.println("CT exiting");
	}
}

class thread2 implements Runnable {
	Thread t;
	thread2(String ss) {
		t=new Thread(this,"BMS Thread");
		//System.out.println(t);
	}
	public void run() {
		try {
			for(int i=5;i>0;i--) {
				System.out.println("CSE");
				Thread.sleep(2000);
			}
		}
		catch(InterruptedException ie) {
			System.out.println("Thread interrupted");
		}
		//System.out.println("CT exiting");
	}
}
class threadmain {
	public static void main(String xx[]) {
		thread1 t1 = new thread1("Thread");
		thread2 t2 = new thread2("Thread");
		t1.t.start();
		t2.t.start();
	}	
}

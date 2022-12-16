import java.util.Scanner;

class Customer {
	private int Customer_no;
	private String Customer_name;
	private int Qty;
	private float Price;
	private float TotalPrice;
	private float Discount;
	private float Netprice;

	public Customer(int n,String name) {
		this.Customer_no=n;
		this.Customer_name=name;
	}
	
	
	

	public void Input() {
		Scanner x=new Scanner(System.in);
		Customer_no=x.nextInt();
		Customer_name=x.next();
		Qty=x.nextInt();
		Price=x.nextFloat();
		this.caldiscount();
	}

	void caldiscount() {
		TotalPrice=Price*Qty;
		if(TotalPrice>=50000) {
			Discount=TotalPrice/4;
		}
		else if(TotalPrice>=25000) {
			Discount=TotalPrice/10;
		}
		Netprice=TotalPrice-Discount;
	}
	
	public void show() {
		System.out.println("Customer No: "+Customer_no);
		System.out.println("Customer Name: "+Customer_name);
		System.out.println("Qty of items purchased: "+Qty);
		System.out.println("Total price prior discount: "+TotalPrice);
		System.out.println("Discount: "+Discount);
		System.out.println("Final Price: "+Netprice);
	}
}

class cmain {
	public static void main(String ss[]) {
		Scanner s=new Scanner(System.in);
		Customer c1=new Customer(0,"New");
		c1.Input();
		c1.show();
	}
}
		

import java.util.Scanner;

class book {

    String name, author;
    double price;
    int num_pages;
    
    void book () {
        this.name="THIS IS A BOOK";
        this.author=null;
        this.price=0.0;
        this.num_pages=0;
    }

    void setd (){

        Scanner ss = new Scanner(System.in);
        System.out.println("Enter the book name, author, price and number of pages: ");

        this.name = ss.nextLine();
        this.author = ss.nextLine();
        this.price = ss.nextDouble();
        this.num_pages = ss.nextInt();

        
    }

    public String toString() {
        return name+" "+author+" "+price+" "+num_pages;
    }
}

class bmain {
    public static void main(String ss[]) {
        int n;
        Scanner x=new Scanner(System.in);
        System.out.println("Enter the number of books: ");
        n=x.nextInt();
	  

        book books[]=new book[n];

        for (int i=0; i<n; i++){
            books[i] = new book();
        }

        int m=n;

	 book b1=new book();
	 b1.book();

        for (int i=0; i<n; i++){
            System.out.println("Type information of book "+(i+1));
            books[i].setd();
        }

        
        for (int i=0; i<n; i++){
            System.out.println("\nBook "+(i+1)+"Details: Name   Author   Price   no_of_pages");
            System.out.println(books[i]);
        }

    }
}

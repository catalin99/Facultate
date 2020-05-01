import Store.Account;
import Store.Employee;

public class Main {

    public static void main(String[] args) {
        Employee angajat = new Employee();
        angajat.addNewProducts();
        Account user = new Account( 1 , 20 , "Mihai");
        user.newShopCart();
        System.out.println( user.getBalance());
        System.out.println("Hello World!");
    }
}

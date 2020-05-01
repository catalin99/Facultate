package Store;

import java.io.*;
import java.util.Scanner;
import java.lang.Byte;
import java.lang.String;

public class Employee {
    public void addNewProducts() {
        String name;
        int price;
        try (BufferedReader in = new BufferedReader(new FileReader("./resources/produse.txt"))) {
            String str;
            while( (str = in.readLine()) != null ) {
                name = str;
                price = Integer.parseInt(in.readLine());
                System.out.println(str);
                System.out.println(price);
                Products.addNewProduct(name, price);
            }
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Products.ExceptionProducts exceptionProducts) {
            exceptionProducts.printStackTrace();
        }
    }
}

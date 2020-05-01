package Store;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

enum Cumparatori {
    PERSOANAFIZICA,
    PERSOANAJURIDICA;
}

public class Account {
    private int id;
    private float balance;
    private String owner;
    private Cumparatori tipClient;

    public Account() {
        id = 0;
        balance = 0;
        owner = "No owner";
    }

    public Account( int id , float balance , String owner ) {
        if( balance > 0 ) {
            this.id = id;
            this.balance = balance;
            this.owner = owner;
        }
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getBalance() {
        return balance;
    }

    public void setBalance(float balance) {
        this.balance = balance;
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public Cumparatori getTipClient() {
        return tipClient;
    }

    public void setTipClient(Cumparatori tipClient) {
        this.tipClient = tipClient;
    }

    public void newShopCart() {
        ShopCart SC = new ShopCart();
        Scanner reader = new Scanner(System.in);
        String command;
        int productId;
        int amount;
        try (BufferedReader in = new BufferedReader(new FileReader("./resources/achizitionari.txt"))) {
            String str;
            while( (str = in.readLine()) != null ) {
                productId = Integer.parseInt(str);
                amount = Integer.parseInt(in.readLine());
                System.out.println(productId);
                System.out.println(amount);
                SC.addProduct(Products.getProductById( productId ) , amount );
            }
            in.close();
            SC.checkOut(this);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

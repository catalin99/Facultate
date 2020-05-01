package com.company;

public class Main {

    private String[] languages = new String[10];
    public void fill()
    {
        languages[0]="C++";
        languages[1]="Java";
        languages[2]="Ruby";
    }
    public static void main(String[] args) {
        fill();
        for (int i=0; i<languages.length; i++) {
            System.out.println(languages[i]);
            System.out.println(' ');
        }

    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author catal
 */
public class methods {
    String languages[]={"C", "C++", "C#", "Go", "JavaScript", "Perl", "PHP", "Python", "Swift", "Java"};
    int n;
    int temp;
    void p1()
    {
        System.out.print("P1: ");
        System.out.println("Hello Guys");
    }
    void p2()
    {
        //languages[]={"C", "C++", "C#", "Go", "JavaScript", "Perl", "PHP", "Python", "Swift", "Java"};
        for(Integer i=0; i<languages.length; i++)
        {
            System.out.print(languages[i]);
            System.out.print(' ');
        }
        System.out.println();
    }
    void p3()
    {
        n=(int)(Math.random()*1000000);
        System.out.print("P3: ");
        System.out.println(n);
    }
    void p4()
    {
        n*=3;
        n+=0b10101;
        n+=0xFF;
        n*=6;
        System.out.print("P4: ");
        System.out.println(n);
    }
    void p5()
    {
        int newnumber=0;
        while(n>0)
        {
            newnumber+=(n%10);
            n/=10;
        }
        
        do{
            temp=0;
            while(newnumber>=10)
            {
                temp+=(newnumber%10);
                newnumber/=10;
            }
            newnumber=temp;
        }
        while(temp>=10);
        System.out.print("P5: ");
        System.out.println(temp);
    }
    void p6()
    {
        String p6="Willy-nilly, this semester I will learn ";
        p6+=languages[temp];
        System.out.print("P6: ");
        System.out.println(p6);
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1java;

/**
 *
 * @author catal
 */
public class Lab1Java {

    /**
     * @param args the command line arguments
     */
    public static int cifraControl(int n)
    {
        if(n<10)
            return n;
        else
        {   
            int result=0;
            while(n>0)
            {
                result=result+(n%10);
                n/=10;
            }
            if(result<10)
                return result;
            else
            {
                return cifraControl(result);
            }
        }
    }
    public static void main(String[] args) {
        final int max;
        max = 1_000_000;
        System.out.println("Hello world!");
        String languages[]={"C", "C++", "C#", "Go", "JavaScript", "Perl", "PHP", "Python", "Swift", "Java"};
        int n = (int) (Math.random() * max);
        System.out.println(n);
        n=n*3;
        System.out.println(n);
        n+=0b10101;
        System.out.println(n);
        n+=0xFF;
        System.out.println(n);
        n*=6;
        System.out.println(n);
        int finalResult=cifraControl(n);
        System.out.println(finalResult);
        System.out.println( "Willy-nilly, this semester I will learn " + languages[finalResult]);
    }
    
}

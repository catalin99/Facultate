/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;

/**
 *
 * @author catal
 * OOP
 * -mostenire - clasa parinte/copil - state/behavior (atribute/metode)
 * -polimorfism - oveloading, overriding (virtual-java)
 * -incapsulare - ascunderea implementării - CQS 
 * -abstractizare - abstract -> metoda abstracta (minim 1), nu se pot face instante
 * interfață - clasa abstracta pura, toate metodele abstracte
 * -asociere - clasa A și clasa B -> A știe de B
 -agregare - asociere între o clasă A și o colecție de clase B
 -composition - agregare: A știe de o colecție de clase B, dacă moare A mor toate clasele B (moare părintele, mor și copiii)
 -Employee - id, first name, last name, age, Role
  -developer
  -tech lead
  -arhitect
 */
public class Lab1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Arhitect one=new Arhitect("Marius", "Andrei", 27, 8000);
        one.getInfo();
        System.out.println();
        Developer two=new Developer("Biga", "Vali", 43, 9000.25);
        two.getInfo();
        System.out.println();
        TechLead three=new TechLead("Vinte", "Adrian", 13, 4500);
        three.getInfo();
        System.out.println();
        Employee[] test= new Employee[3];
        test[0]= new Arhitect("Jhon","Snow",34,543);
        test[1]= new Developer("Vasile","Popescu",45,7654);
        test[2]= new TechLead("Georgescu","Florin",19,376);
 
        //test[0].getRole();
        test[0].getInfo();
        System.out.println();
        //test[1].getRole();
        test[1].getInfo();
        System.out.println();
        //test[2].getRole();
        test[2].getInfo();
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;

/**
 *
 * @author catal
 */
public abstract class Employee {
    static int start=0;
    int id, age;
    double salary;
    String firstName, lastName;
    
    /*public void fill(String firstNameIn, String lastNameIn, Integer ageIn, double salaryIn)
    {
        id=start++;
        firstName=firstNameIn;
        lastName=lastNameIn;
        age=ageIn;
        salary=salaryIn;
    }*/
    public abstract void getRole();
    public abstract void getInfo();
}

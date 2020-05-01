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
public class Developer extends Employee{
    public void getRole()
    {
        System.out.println("This is an Developer");
    }
    public void getInfo()
    {
        System.out.print("Informații despre angajatul cu id-ul ");
        System.out.println(id);
        System.out.println(firstName);
        System.out.println(lastName);
        System.out.println(age);
        System.out.println(salary);
        System.out.println("Role: Developer");
    }
    public Developer(String firstNameIn, String lastNameIn, Integer ageIn, double salaryIn)
    {
        id=Employee.start++;
        firstName=firstNameIn;
        lastName=lastNameIn;
        age=ageIn;
        salary=salaryIn;
    }
}

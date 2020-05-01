/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
//import java.io.*; 
import java.util.*;
/**
 *
 * @author catal
 */
public class Student {
    String name;
    int yearOfStudy;
    Project preferedProjects[];
    Project assignedProject;
    public Student(String nume, int year)
    {
        this.name=nume;
        this.yearOfStudy=year;
    }
    public  void setStudentName(String nume)
    {
        this.name=nume;
    }
    public void setStudentYearOfStudy(short year)
    {
        this.yearOfStudy=year;
    }
    public String getStudentName()
    {
        return this.name;
    }

    public Project[] getPreferedProjects() {
        return preferedProjects;
    }
    public int getStudentYearOfStudy()
    {
        return this.yearOfStudy;
    }
    public void setPreferences(Project ... args)
    {
        this.preferedProjects=new Project[args.length];
        for(int i=0; i<args.length; i++)
        {
            boolean ok=true;
            for (Project preferedProject : preferedProjects) {
                if (args[i].equals(preferedProject)) {
                    ok=false;
                }
            }
            if(ok==true)
                preferedProjects[i]=args[i];
        }
    }
    @Override
    public String toString() {
        String projectsFinal=Arrays.toString(preferedProjects);
        return "Student{" + "name=" + name + ", yearOfStudy=" + yearOfStudy + ", projects=" + projectsFinal + ", assignedProject=" + assignedProject + '}' + '\n';
    }


    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Student other = (Student) obj;
        if (this.yearOfStudy != other.yearOfStudy) {
            return false;
        }
        if (!Objects.equals(this.name, other.name)) {
            return false;
        }
        if (!Arrays.deepEquals(this.preferedProjects, other.preferedProjects)) {
            return false;
        }
        if (!Objects.equals(this.assignedProject, other.assignedProject)) {
            return false;
        }
        return true;
    }

    
        
    
}

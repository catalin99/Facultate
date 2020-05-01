package university;

import java.util.ArrayList;
import java.util.List;

public class Student extends Person {
    private Project enrollment;
    private List<Project> preferences;

    /* Constructor, invoca super() pentru clasa de la baza */
    public Student(String n, String e) {
        super(n, e);

        enrollment = new Project(null, 0);
        preferences = new ArrayList<Project>();
    }

    /* Returneaza proiectul pe care il are studentul */
    public Project getEnrollment() {
        return enrollment;
    }

    /* Seteaza proiectul pe care il are studentul */
    public void setEnrollment(Project e) {
        enrollment = e;
    }

    /* Adauga un proiect la lista de preferinte a studentului */
    public void addPreference(Project p) {
        preferences.add(p);
    }

    /* Adauga trei proiecte in preferintele studentului */
    public void setPreferences(Project p1, Project p2, Project p3) {
        preferences.add(p1);
        preferences.add(p2);
        preferences.add(p3);
    }

    /* Adauga un proiect pe lista preferintelor */
    public void setPreferences(Project p1) {
        preferences.add(p1);
    }

    /* Returneaza preferintele studentului */
    public List<Project> getPreferences(){
        return preferences;
    }
    /* Suprascriem toString() */
    public String toString() {
        String s = "Nume: " + getName() + " - Email: " + getEmail() + " - Enrollment: " + enrollment.getName() + " - preferences: ";

        for(Project p : preferences) {
            if(preferences.indexOf(p)==(preferences.size()-1))
                s += p.getName() + ".\n";
            else
                s += p.getName() + ",";
        }

        return s;
    }

    @Override
    public boolean equals(Object obj) {
        if( obj == null )
            return false;
        if( !(obj instanceof Student))
            return false;
        Student Student = (Student)obj;
        return (this.hashCode() == Student.hashCode());
    }

    @Override
    public int hashCode() {
        int hash = 1;
        hash = hash*13 + getName().hashCode();
        hash = hash*29 + getEmail().hashCode();
        return hash;
    }
}
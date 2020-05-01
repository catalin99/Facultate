package university;

import java.util.ArrayList;
import java.util.List;

public class Teacher extends Person {
    private List<Student> preferences;
    private Project project;

    /* Constructor, invoca super() pentru clasa de la baza */
    public Teacher(String n, String e) {
        super(n, e);

        preferences = new ArrayList<Student>();
        project = new Project(null, 0);
    }

    /* Adauga un student la lista de preferinte a unui profesor */
    public void addStudentToPreference(Student s) {
        preferences.add(s);
    }

    /* Returneaza proiectul profesorului */
    public Project getProject() {
        return project;
    }

    /* Seteaza proiectul profesorului */
    public void setProject(Project p) {
        project = p;
    }

    /* Creaza un proiect si il asigniaza profesorului */
    public Project createProject(String string, int i) {
        Project p = new Project(string, i);
        project = p;

        return p;
    }

    /* Seteaza preferintele unui profesor */
    public void setPreferences(Student s1, Student s2, Student s3, Student s4) {
        preferences.add(s1);
        preferences.add(s2);
        preferences.add(s3);
        preferences.add(s4);
    }

    public List<Student> getPreferences(){
        return preferences;
    }

    @Override
    public boolean equals(Object obj) {
        if( obj == null )
            return false;
        if( !(obj instanceof Teacher))
            return false;
        Teacher Teacher = (Teacher)obj;
        return (this.hashCode() == Teacher.hashCode());
    }

    @Override
    public int hashCode() {
        int hash = 1;
        hash = hash*17 + getName().hashCode();
        hash = hash*31 + getEmail().hashCode();
        return hash;
    }
}

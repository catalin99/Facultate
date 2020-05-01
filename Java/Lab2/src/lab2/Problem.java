/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

import java.util.Arrays;

/**
 *
 * @author catal
 */
public class Problem {
    Student students[];
    public void setStudents(Student ... args)
    {
        this.students=new Student[args.length];
        for(int i=0; i<args.length; i++)
        {
            boolean ok=true;
            for (Student student : students) {
                if (args[i].equals(student)) {
                    ok=false;
                }
            }
            if(ok==true)
                students[i]=args[i];
        }
    }
    
    private void sortStudents()
    {
        for(int i=0; i<students.length-1; i++)
            for(int j=i+1; j<students.length; j++)
                if(students[i].preferedProjects.length>students[j].preferedProjects.length)
                {
                    Student temp=students[i];
                    students[i]=students[j];
                    students[j]=temp;
                }            
    }
    public boolean assignedProject(Project proj)
    {
        for(int i=0; i<students.length; i++)
            if(proj.equals(students[i].assignedProject))
                return true;
        return false;
    }
    
    public void assignProjectsAlgorithm()
    {
        sortStudents();
        for(int i=0; i<students.length; i++)
        {
            for(int j=0; j<students[i].preferedProjects.length; j++)
                if(assignedProject(students[i].preferedProjects[j])==false)
                {
                    students[i].assignedProject=students[i].preferedProjects[j];
                    break;
                }
        }
    }
    private boolean checkAssign()
    {
        for (Student student : students) {
            if (student.assignedProject == null) {
                return false;
            }
        }
        return true;
    }
    private void emptyAllocatedProjects()
    {
        for (Student student : students) {
            student.assignedProject = null;
        }
    }
    
    private void sortProjectsAlgorithm()
    {
        //
    }
    
    public void assignProjects()
    {
        short counter=0;
        while(checkAssign()==false && counter<30)
        {
            sortProjectsAlgorithm();
            emptyAllocatedProjects();
            assignProjectsAlgorithm();
            counter++;
        }
    }
    @Override
    public String toString() {
        String problemsFinal=Arrays.toString(students);
        return "Problem{" + "students=" + problemsFinal + '}';
    }
    
    public Project[] getProjects()
    {
        Project preferedProjectsFinal[]=new Project[5];
        int count=0;
        for (Student student : students) {
            //String preferedProjectsPerStudent=Arrays.toString(students[i].preferedProjects);
            for (Project preferedProject : student.preferedProjects) {    
                boolean check=true;
                for (Project preferedProjectsFinal1 : preferedProjectsFinal) {
                    if (preferedProject.equals(preferedProjectsFinal1)) {
                        check=false;
                    }
                }
                if (check==true) {
                    preferedProjectsFinal[count++] = preferedProject;
                }
            }
        }
        return preferedProjectsFinal;
    }
    
    
}

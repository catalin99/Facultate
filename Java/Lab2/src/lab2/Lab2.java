/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
import java.time.LocalDate;
import java.time.Month;
/**
 *
 * @author catal
 */
public class Lab2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Student s1 = new Student("S1", 2);
        Student s2 = new Student("S2", 5);
        Student s3 = new Student("S3", 4);
        Student s4 = new Student("S4", 8);
        Application a1 = new Application("A1", LocalDate.of(2019, Month.JUNE, 1), Languages.JAVA);
        Application a2 = new Application("A2", LocalDate.of(2019, Month.APRIL, 17), Languages.C);
        Application a3 = new Application("A3", LocalDate.of(2019, Month.DECEMBER, 19), Languages.PYTHON);
        Application a4 = new Application("A4", LocalDate.of(2019, Month.DECEMBER, 17), Languages.RUBY);
        Essay e1 = new Essay("E1", LocalDate.parse("2019-06-01"), Topic.ALGORITHMS);
        Essay e2 = new Essay("E2", LocalDate.parse("2017-05-01"), Topic.DATA_STRUCTURES);
        s1.setPreferences(a1, a2, a3);
        s2.setPreferences(e1, a1);
        s3.setPreferences(a2, a3, e1);
        s4.setPreferences(a3, e2);
        Problem problem = new Problem();
        problem.setStudents(s1, s2, s3, s4);
        System.out.println(problem);
        Project projectList[]=problem.getProjects();
        for(int i=0; i<projectList.length; i++)
        {
            System.out.println(projectList[i]);
        }
        problem.assignProjectsAlgorithm();
        System.out.println(problem);
    }
    
}

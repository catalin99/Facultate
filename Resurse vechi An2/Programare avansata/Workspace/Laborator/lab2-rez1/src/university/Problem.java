package university;

import java.util.ArrayList;
import java.util.List;

public class Problem {
    private List<Student> students;
    private List<Teacher> teachers;

    public Problem() {
        students = new ArrayList<Student>();
        teachers = new ArrayList<Teacher>();
    }

    /* Setam studentii acestei probleme */
    public void setStudents(Student s1, Student s2, Student s3, Student s4) {
        students.add(s1);
        students.add(s2);
        students.add(s3);
        students.add(s4);
    }

    /* Setam profesorii acestei probleme */
    public void setTeachers(Teacher t1, Teacher t2, Teacher t3) {
        teachers.add(t1);
        teachers.add(t2);
        teachers.add(t3);
    }

    /* Returneaza participantii la problema */
    public List<Person> getParticipants(){
        List<Person> participants = new ArrayList<Person>();
        System.out.println("\nToti participantii sunt:");
        for(Student st : students)
            participants.add(st);
        for(Teacher t : teachers )
            participants.add(t);
        return participants;
    }

    /* Suprascriem toString() */
    public String toString() {
        String s = new String();

        s += "Aceasta problema are urmatorii studenti: ";

        for(Student st : students)
            if(students.indexOf(st)==students.size()-1)
                s += st.getName() + ".";
            else
                s += st.getName() + ",";

        s += "\nProblema are de asemenea urmatorii profesori: ";

        for(Teacher t : teachers)
            if(students.indexOf(t)==students.size()-1)
                s += t.getName() + ".";
            else
                s += t.getName() + ",";

        return s;
    }
}
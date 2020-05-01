package ComparatorExemple;

import java.util.Arrays;
import java.util.Comparator;

public class ComparatorExample {

    public static void main ( String args []) {
        Persoana p[] = new Persoana [4];
        p[0] = new Persoana (3, " Ionescu ");
        p[1] = new Persoana (1, " Vasilescu ");
        p[2] = new Persoana (2, " Georgescu ");
        p[3] = new Persoana (4, " Popescu ");
        Arrays . sort (p, new Comparator() {
            public int compare (Object o1 , Object o2) {
                Persoana p1 = (Persoana) o1;
                Persoana p2 = (Persoana) o2;
                return (p1.nume.compareTo(p2.nume));
            }
        });
        System . out. println (" Persoanele ordonate dupa nume :");
        for (int i=0; i<p. length ; i++)
            System . out. println (p[i]);
    }
}

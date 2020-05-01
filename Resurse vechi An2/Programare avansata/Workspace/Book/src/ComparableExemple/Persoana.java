package ComparableExemple;

public class Persoana implements Comparable<Object> {
    int cod;
    String nume;

    public Persoana (int cod, String nume) {
        this.cod = cod;
        this.nume = nume;
    }

    public String toString () {
        return cod + "\t" + nume ;
    }

    public boolean equals (Object o) {
        if (!( o instanceof Persoana ))
            return false ;
        Persoana p = ( Persoana ) o;
        return (cod == p.cod) && ( nume.equals(p.nume));
    }

    @Override
    public int compareTo(Object o) {
        if (o == null )
            throw new NullPointerException();
        if (!( o instanceof Persoana ))
            throw new ClassCastException ("Nu pot compara !");
        Persoana p = (Persoana) o;
        return (cod - p.cod );
    }
}

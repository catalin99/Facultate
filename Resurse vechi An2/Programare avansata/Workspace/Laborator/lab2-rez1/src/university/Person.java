package university;

public class Person {
    private String name;
    private String email;

    /* Constructor */
    public Person(String n, String e) {
        name = n;
        email = e;
    }

    /* Getter pentru nume */
    public String getName() {
        return name;
    }

    /* Setter pentru nume */
    public void setName(String n) {
        name = n;
    }

    /* Getter pentru mail */
    public String getEmail() {
        return email;
    }

    /* Setter pentru mail */
    public void setEmail(String e) {
        email = e;
    }

    /* Suprascriem toString() */
    public String toString() {
        return "Nume: " + name + " - Email: " + email + "\n";
    }
}

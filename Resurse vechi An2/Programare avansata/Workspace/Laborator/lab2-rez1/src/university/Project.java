package university;

public class Project {
    private int capacity;
    private String name;

    /*
     * Constructor
     */
    public Project(String n, int c) {
        name = n;
        capacity = c;
    }

    /*
     * Getter pentru capacitate
     */
    public int getCapacity() {
        return capacity;
    }

    /*
     * Setter pentru capacitate
     */
    public void setCapacity(int c) {
        capacity = c;
    }

    /*
     * Getter pentru nume
     */
    public String getName() {
        return name;
    }

    /*
     * Setter pentru nume
     */
    public void setName(String n) {
        name = n;
    }
}
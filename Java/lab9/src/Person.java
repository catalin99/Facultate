public abstract class Person {
    private int id;
    private String name;
    public String type;

    public Person(int id, String name, String type) {
        this.id = id;
        this.name = name;
        this.type = type;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    private void setType(String type){
        this.type=type;
    };

    @Override
    public String toString()
    {
        return "id: " + this.id + "\nname: " + this.name + "\ntype: " + this.type+ "\n";
    }
}

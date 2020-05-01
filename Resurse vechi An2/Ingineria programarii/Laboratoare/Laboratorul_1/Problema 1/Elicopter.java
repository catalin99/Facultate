public class Elicopter implements Aeronava {

    enum tip{
        Agrement,
        SMURD,
        Militar
    };

    private String nume;
    private int noCapacity;
    private tip model;

    Elicopter(tip numeModel, int noCapacity) {
        this.model = numeModel;
        this.noCapacity = noCapacity;
    }

    Elicopter(tip numeModel) {
        this(numeModel,6);
    }

    @Override
    public String getNume() {
        return this.nume;
    }

    @Override
    public void setNume(String nume) {
        this.nume=nume;
    }

    @Override
    public void changeCapacity(int newValue) {
        this.noCapacity=newValue;
    }

    public tip getModel() {
        return this.model;
    }

    public void setModel(tip model) {
        this.model = model;
    }
}

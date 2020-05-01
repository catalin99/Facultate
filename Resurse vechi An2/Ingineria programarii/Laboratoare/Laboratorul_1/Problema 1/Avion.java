public class Avion implements Aeronava {

    enum tip {
        Pasageri,
        Marfa,
        Militar
    };

    private String nume;
    private int noCapacity;
    private tip model;

    Avion(tip numeModel, int noCapacity) {
        this.model = numeModel;
        this.noCapacity = noCapacity;
    }

    Avion(tip numeModel) {
        this(numeModel,15);
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

    public tip getModel()  {
        return this.model;
    }

    public void setModel(tip model) {
        this.model = model;
    }
}

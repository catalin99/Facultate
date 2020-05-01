public class Pista implements Aeroport {

    private int capacity;
    private int currentNo;
    private StringBuffer currentModel;

    Pista(int x) {
        this.capacity=x;
        this.currentNo=0;
        this.currentModel= new StringBuffer("");
    }

    Pista() {
        this(0);
    }

    @Override
    public void changeCapacity(int newValue) {
        this.capacity=newValue;
    }

    @Override
    public void printCapacity() {
        System.out.println(capacity);
    }

    @Override
    public void addOne(String numeModel) {
        if(currentNo<capacity) {
            this.currentNo++;
            this.currentModel.insert(currentModel.length(), numeModel + " ");
        }
        else
            System.out.println("Pista este plina!");
    }

    @Override
    public void removeOne(String numeModel) {
        this.currentNo--;
        int position = currentModel.lastIndexOf(numeModel);
        currentModel.delete(position, position+numeModel.length()+1);
    }

    @Override
    public void printCurrentNo() {
        System.out.println(currentNo);
    }

    @Override
    public void printCurrentTip() {
        System.out.println(currentModel);
    }
}
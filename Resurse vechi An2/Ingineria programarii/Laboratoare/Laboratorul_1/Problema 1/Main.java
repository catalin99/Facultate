public class Main {

    public static void main(String[] args) {

        Hangar Hangar1 = new Hangar(10);
        Pista Pista1 = new Pista(2);

        Avion airbus1 = new Avion(Avion.tip.Pasageri);
        airbus1.setNume("A380");
        airbus1.changeCapacity(55);

        Avion raptor1 = new Avion(Avion.tip.Militar);
        raptor1.setNume("F22");

        Elicopter smurd1 = new Elicopter(Elicopter.tip.SMURD);
        smurd1.setNume("EC135");
        smurd1.changeCapacity(6);

        Elicopter guardian1 = new Elicopter(Elicopter.tip.Militar);
        guardian1.setNume("AH64E");
        guardian1.changeCapacity(12);

        Pista1.addOne(guardian1.getNume());

        Pista1.printCurrentTip();

        Pista1.addOne(smurd1.getNume());
        Pista1.addOne(airbus1.getNume());

        Hangar1.addOne(smurd1.getNume());
        Hangar1.addOne(raptor1.getNume());

        Hangar1.printCurrentNo();

        Hangar1.printCurrentTip();

        Hangar1.removeOne(smurd1.getNume());

        Hangar1.printCurrentTip();

        Hangar1.printCurrentNo();

        Hangar1.addOne(airbus1.getNume());

        Hangar1.printCurrentNo();
    }
}

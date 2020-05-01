package Company;

public class Main {

    public static void main(String[] args) throws NameException {
        Building h1 = new Building("House 1", 27, 9);
        Building h2 = new Building("House 2", 27, 9);
        Building h3 = new Building("House 3", 64, 16);

//        System.out.println(h1.getName());
//        System.out.println(h2.getPrice());
//        System.out.println(h3.getArea());
//        System.out.println(h1.profit());

        Vehicle c1 = new Vehicle("Car 1", 8, 4);
        Vehicle c2 = new Vehicle("Car 2", 8, 4);

//
//        System.out.println(c1.getPerformance());
//        System.out.println(c2.getName());
//        System.out.println(c2.getPrice());
//        System.out.println(c2.profit());

        Jewel r1 = new Jewel("Gold Diamond Ring", 2);


        AssetManager manager = new AssetManager();
        manager.add(h1, h2, h3);
        manager.add(c1, c2);
        manager.add(r1);
        System.out.println("Items sorted by the name: " + manager.getItems());

        System.out.println("Assets sorted by profit: " + manager.getAssets());

        int maxValue = 20;
        Portofolio solution = manager.createPortofolio( new GreedyAlgorithm() , maxValue );
        System.out.println("The best portofolio: " + solution );
        solution = manager.createPortofolio( new RandomAlgorithm() , maxValue );
        System.out.println("The best portofolio: " + solution );
    }
}


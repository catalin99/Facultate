
interface Animal{
    public void eat();
    public void sound();
};
interface Bird{
    int numberOfLegs=2;
    String outerCovering="FEATHER";
    public void fly();
}

class Eagle implements Animal,Bird{
    public void eat()
    {
        System.out.println("Eats  seeds");
    }
    public  void sound()
    {
        System.out.println("Has a high pitched whistling sound");
    }
    public void fly()
    {
        System.out.println("Flies up to 10,000 feet.");
    }
};


public class TestEagle {
    public static void main(String[]arg)
    {
        Eagle myEagle=new Eagle();
        myEagle.eat();
        myEagle.sound();
        myEagle.fly();
        System.out.println("Number of legs: "+myEagle.numberOfLegs);
        System.out.println("Outer covering:"+Bird.outerCovering);
    }

}

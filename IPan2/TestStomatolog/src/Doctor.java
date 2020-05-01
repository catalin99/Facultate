import java.util.function.DoubleConsumer;

abstract class Doctor extends Persoana {
    String Specializare="Doctor";
    int Diploma=0;

    abstract void PrintSpecializare();

    public void personality()
    {
        System.out.println("CNP-ul meu este: "+CNP);
        System.out.println("Numele meu este: "+Name);
        System.out.println("Locuiesc la: "+Addres);
        System.out.println("Am "+Age+" ani");
    }

}

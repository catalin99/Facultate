
class Stomatolog extends Doctor{

    Stomatolog(int age,String address,String name,String cnp)
    {
        Name=name;
        Addres=address;
        Age=age;
        CNP=cnp;
        Specializare="Stomatolog";
        Diploma=1;
    }
    void PrintSpecializare() {

        System.out.println(Specializare);
        if(Diploma==1)
            System.out.println("Licentiat");
        else System.out.println("Nelicentiat");
    }
}
public class TestStomatolog {
    public static void main(String[]args)
    {
        Persoana doc=new Stomatolog(32,"strada","irina","235");
        ((Stomatolog) doc).PrintSpecializare();
        doc.personality();

    }
}

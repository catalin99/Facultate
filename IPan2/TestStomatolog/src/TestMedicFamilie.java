
class MedicFamilie extends Doctor
{
    MedicFamilie(int age,String address,String name,String cnp)
    {
        Name=name;
        Addres=address;
        Age=age;
        CNP=cnp;
        Specializare="Medic de familie";
        Diploma=0;
    }
    MedicFamilie()
    {
        Specializare="Medic de familie";
        Diploma=0;
    }
    void PrintSpecializare() {
        System.out.println(Specializare);
        if(Diploma==1)
        System.out.println("Licentiat");
        else System.out.println("Nelicentiat");

    }
}

public class TestMedicFamilie {
    public static void main(String[]args)
    {
        Persoana fam=new MedicFamilie(21,"alee","mihnea","123");
        ((MedicFamilie) fam).PrintSpecializare();
        fam.personality();
        Persoana familie=new MedicFamilie();
        ((MedicFamilie) familie).PrintSpecializare();
        familie.personality();
    }
}

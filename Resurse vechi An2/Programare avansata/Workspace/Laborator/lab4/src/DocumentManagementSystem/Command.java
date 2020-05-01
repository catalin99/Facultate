package DocumentManagementSystem;

public abstract class Command {

    public static void generalHelp() {
        System.out.println();
        System.out.println("--------------------");
        System.out.println("Commands to use:");
        System.out.println("1. new catalog");
        System.out.println("2. cat *.java");
        System.out.println("3. exit");
        System.out.println("4. clear");
        System.out.println("---------------------");
        System.out.println();
    }

    abstract void implementCommand();

    abstract void help();
}

package DocumentManagementSystem;

enum Type {
    book,
    article
};

public class AddCommand extends Command {

    Type type;
    String title;
    String path;
    Integer year;
    String[] authors;

    AddCommand(Type type, String title, String path, Integer year, String ... authors) {
        this.type=type;
        this.title=title;
        this.path=path;
        this.year=year;
        int i=0;
        for(String x : authors) {
            this.authors[i++] = x;
        }
        Document()
    }

    @Override
    void implementCommand() {
        if(type=="book")
            addBook();

    }

    @Override
    void help() {

    }

    private void addBook() {

    }
}

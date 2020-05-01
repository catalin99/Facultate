public class Movie {
    private int movie_id;
    private String name;
    private int director_id;

    public Movie(int movie_id, String name, int director_id) {
        this.movie_id = movie_id;
        this.name = name;
        this.director_id = director_id;
    }

    public int getMovie_id() {
        return movie_id;
    }

    public void setMovie_id(int movie_id) {
        this.movie_id = movie_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDirector_id() {
        return director_id;
    }

    public void setDirector_id(int director_id) {
        this.director_id = director_id;
    }

    @Override
    public String toString()
    {
        return "id: " + this.movie_id + "\nname: " + this.name + "\ndirector_id: " + this.director_id + "\n";
    }
}

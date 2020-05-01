import java.sql.SQLException;
import java.util.List;

public class lab9 {
    public static void main(String[] args) {
        try {
            PersonController persons = new PersonController();
            MovieController movies = new MovieController();
            MovieActorsController movieActors = new MovieActorsController();

//            persons.create("Francis Ford Coppola", "director");
//            persons.create("Marlon Brando", "actor");
//            persons.create("Al Pacino", "actor");
//            Database.commit();
//
//            movies.create("The Godfather", persons.findByName("Brando"));
//            movies.create("Avengers", persons.findByName("Pacino"));
//           // ...//Add other movies to the database
//            Database.commit();

            //persons.create("Tom Johnson", "director");
            //Database.commit();
            movies.create("The failure", persons.findByName("Brando"));
            Database.commit();

//            movieActors.create("Wrong actor name", "Avengers"); //fail actor name
//            movieActors.create("Al Pacino", "Wrong movie name"); //fail movie name
//            movieActors.create("Francis Ford Coppola", "Avengers"); //fail not an actor
           // movieActors.create("Al Pacino", "Avengers"); //succes
//            movieActors.create("Marlon Brando", "Avengers");
            movieActors.delete("Marlon Brando", "Avengers");
            Database.commit();
//            List<Movie> allMovies=movies.findAll();
//            for(Movie movie:allMovies)
//                System.out.println(movie.toString());
//
//            List<Person> allPersons=persons.findAll();
//            for(Person person:allPersons)
//                System.out.println(person.toString());

            Database.closeConnection();
        } catch (SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
    }
}

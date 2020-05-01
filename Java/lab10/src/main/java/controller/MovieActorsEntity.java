package controller;

import javax.persistence.*;

@Entity
@Table(name = "movie_actors", schema = "java", catalog = "")
public class MovieActorsEntity {
    private int id;
    private int movieId;
    private int personId;

    @Id
    @Column(name = "id", nullable = false)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Basic
    @Column(name = "movie_id", nullable = false)
    public int getMovieId() {
        return movieId;
    }

    public void setMovieId(int movieId) {
        this.movieId = movieId;
    }

    @Basic
    @Column(name = "person_id", nullable = false)
    public int getPersonId() {
        return personId;
    }

    public void setPersonId(int personId) {
        this.personId = personId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        MovieActorsEntity that = (MovieActorsEntity) o;

        if (id != that.id) return false;
        if (movieId != that.movieId) return false;
        if (personId != that.personId) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = id;
        result = 31 * result + movieId;
        result = 31 * result + personId;
        return result;
    }
}

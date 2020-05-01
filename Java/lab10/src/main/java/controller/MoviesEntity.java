package controller;

import javax.persistence.*;

@Entity
@Table(name = "movies", schema = "java", catalog = "")
public class MoviesEntity {
    private int movieId;
    private String name;
    private int directorId;

    @Id
    @Column(name = "movie_id", nullable = false)
    public int getMovieId() {
        return movieId;
    }

    public void setMovieId(int movieId) {
        this.movieId = movieId;
    }

    @Basic
    @Column(name = "name", nullable = false, length = 100)
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Basic
    @Column(name = "director_id", nullable = false)
    public int getDirectorId() {
        return directorId;
    }

    public void setDirectorId(int directorId) {
        this.directorId = directorId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        MoviesEntity that = (MoviesEntity) o;

        if (movieId != that.movieId) return false;
        if (directorId != that.directorId) return false;
        if (name != null ? !name.equals(that.name) : that.name != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = movieId;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        result = 31 * result + directorId;
        return result;
    }
}

package entity;

import javax.persistence.*;

@Entity
@Table(name = "MOVIES", schema = "STUDENT")
public class Movie {
    @Id
    @GeneratedValue
    @Column(name = "ID")
    private long id;

    @Column(name = "NAME")
    private String name;

    @ManyToOne
    @JoinColumn(name = "DIRECTOR_ID")
    private Person director;


    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    public Person getDirector() {
        return director;
    }

    public void setDirector(Person director) {
        this.director = director;
    }
}

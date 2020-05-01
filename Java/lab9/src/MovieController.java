import javax.xml.transform.Result;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class MovieController {
    public void create(String name, Integer id) throws SQLException {
        Connection con = Database.getConnection();
        try(Statement state = con.createStatement())
        {
            ResultSet result = state.executeQuery("select type from persons where person_id like '" + id + "'");
            if(!result.next())
            {
                System.out.println("this id doesnt exists\n");
                return;
            }
            if(!result.getString(1).equalsIgnoreCase("director"))
            {
                System.out.println("this is not a director\n");
                return;
            }

        }
        try (PreparedStatement pstmt = con.prepareStatement("insert into movies (name, director_id) values (?, ?)")) {
            pstmt.setString(1, name);
            pstmt.setInt(2, id);
            pstmt.executeUpdate();
        }
    }
    public Integer findByName(String name) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select movie_id from movies where name like '%" + name + "%'")) {
            return rs.next() ? rs.getInt(1) : null;
        }
    }
    public String findById(int idd) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select name from movies where movie_id = idd")) {
            return rs.next() ? rs.getString(1) : null;
        }
    }

    public List<Movie> findAll()
    {
        List<Movie> movieList=new ArrayList<>();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select * from movies"))
        {

            while(rs.next())
            {
                Movie movie=new Movie(rs.getInt(1), rs.getString(2), rs.getInt(3));
                movieList.add(movie);
            }
            return movieList;
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return movieList;

    }

}

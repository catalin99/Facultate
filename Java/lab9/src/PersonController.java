import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class PersonController {
    public void create(String name, String tip) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("insert into persons (name,type) values (?,?)")) {
            pstmt.setString(1, name);
            pstmt.setString(2, tip);
            pstmt.executeUpdate();
        }
    }
    public Integer findByName(String name) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select person_id from persons where name like '%" + name + "%'")) {
            return rs.next() ? rs.getInt(1) : null;
        }
    }
    public String findById(int idd) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select name from persons where person_id = idd")) {
            return rs.next() ? rs.getString(1) : null;
        }
    }

    public List<Person> findAll()
    {
        List<Person> personList=new ArrayList<>();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select * from persons"))
            {

                while(rs.next())
                {
                    if(rs.getString(3).equalsIgnoreCase("director"))
                    {
                        Director director = new Director(rs.getInt(1),rs.getString(2),rs.getString(3));
                        personList.add(director);
                    }
                    else if(rs.getString(3).equalsIgnoreCase("actor"))
                    {
                        Actor actor = new Actor(rs.getInt(1),rs.getString(2),rs.getString(3));
                        personList.add(actor);
                    }
                }
                return personList;
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return personList;

    }
}
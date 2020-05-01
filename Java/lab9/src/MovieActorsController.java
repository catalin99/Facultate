import com.mysql.cj.xdevapi.DeleteStatement;

import java.sql.*;

public class MovieActorsController {
    public int actor_id=0;
    public int movie_id=0;
    private boolean check(String actorName, String movieName)
    {
        Connection con = Database.getConnection();
        try(Statement state=con.createStatement())
        {

            ResultSet rsactor = state.executeQuery("select person_id, type from persons where name like '" + actorName +"'");
            if(!rsactor.next())
            {
                System.out.println("Invalid actor name\n");
                return false;
            }
            if(!rsactor.getString(2).equalsIgnoreCase("actor"))
            {
                System.out.println("This is not an actor\n");
                return false;
            }
            actor_id=rsactor.getInt(1);
            //System.out.println(actor_id);
            ResultSet rsmovie = state.executeQuery("select movie_id from movies where name like '" + movieName +"'");
            if(!rsmovie.next())
            {
                System.out.println("Invalid movie name\n");
                return false;
            }
            movie_id=rsmovie.getInt(1);
            //System.out.println(movie_id);

        } catch (SQLException e) {
            e.printStackTrace();
        }
        return true;
    }
    public void create(String actorName, String movieName)
    {
        Connection con = Database.getConnection();
        //Integer actor_id=0, movie_id=0;
        if(!check(actorName,movieName))
            return;
        try(PreparedStatement pstmt = con.prepareStatement("insert into movie_actors (movie_id, person_id) values (?, ?)")) {
            pstmt.setInt(1, movie_id);
            pstmt.setInt(2, actor_id);

            if(movie_id!=0 && actor_id!=0)
                pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    public void delete(String actorName, String movieName)
    {
        Connection con = Database.getConnection();
//        int person_idd=0, movie_idd=0;
        if(!check(actorName,movieName))
            return;
        try(PreparedStatement ps = con.prepareStatement("delete from movie_actors where person_id like '" + actor_id + "' and movie_id like '" + movie_id + "'" )) {

            if(actor_id!=0 && movie_id!=0)
                ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

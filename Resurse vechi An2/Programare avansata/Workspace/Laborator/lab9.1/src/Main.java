import com.daoimpl.PersonDaoImpl;
import com.util.ConnectionConfiguration;

import java.sql.Connection;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {
        PersonDaoImpl pdi = new PersonDaoImpl();
        pdi.createPersonTable();

//        Connection connection = null;
//
//        try {
//            connection = ConnectionConfiguration.getConnection();
//            if(connection != null) {
//                System.out.println("Connection establised!");
//            }
//        } catch (Exception e) {
//            e.printStackTrace();
//        } finally {
//            if(connection != null) {
//                try {
//                    connection.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
//        }
    }
}

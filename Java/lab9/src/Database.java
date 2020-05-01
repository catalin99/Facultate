import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private static final String URL = "jdbc:mysql://localhost:3306/java";
    private static final String USER = "root";
    private static final String PASSWORD = "";
    private static Connection connection = null;
    private Database() { }
    public static Connection getConnection() {
        if (connection == null) {
            createConnection();
        }
        return connection;
    }
    //Implement the method createConnection()
    //Implement the method closeConnection()
    // Implement the method commit()
    //Implement the method rollback()
    static void createConnection()
    {
        //Connection con = null;
        try {
            connection = DriverManager.getConnection(
                    URL, USER, PASSWORD);
            connection.setAutoCommit(false);
        } catch(SQLException e) {
            System.err.println("SQLException: " + e);
        }
    }

    public static void commit() {
        try {
            connection.commit();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void closeConnection() {
        try {
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void rollback() {
        try {
            connection.rollback();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

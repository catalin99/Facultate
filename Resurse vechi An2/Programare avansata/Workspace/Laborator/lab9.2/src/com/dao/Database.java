package com.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private static final String URL = "jdbc:mysql://localhost:3306/musicalbums";
    private static final String USER = "dba";
    private static final String PASSWORD = "sql1";
    private static Connection connection = null;

    private static Database ourInstance = new Database();

    public static Database getInstance() {
        return ourInstance;
    }

    private Database() {
    }

    public static Connection getConnection() {
        if (connection == null) {
            createConnection();
        }
        return connection;
    }

    public static Connection createConnection() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
        } catch (Exception e) {
            e.printStackTrace();
        }

        return connection;
    }

    public static void closeConnection() {
        if(connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void commit() {
        try {
            connection.commit();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Rolling back data here....");
            rollback();
        }
    }

    public static void rollback() {
        try{
            if(connection!=null) {
                connection.rollback();
                connection.close();
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}

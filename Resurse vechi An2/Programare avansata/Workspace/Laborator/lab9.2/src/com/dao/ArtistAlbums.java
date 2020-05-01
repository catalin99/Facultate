package com.dao;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class ArtistAlbums {
    public void createArtistAlbumsTable() {
        Connection connection = null;
        Statement statement = null;

        try {
            connection = Database.getConnection();
            statement = connection.createStatement();
            statement.execute("CREATE TABLE IF NOT EXISTS artists (id int primary key unique auto_increment, name varchar(100) not null, country varchar(100))");
            statement.execute("CREATE TABLE IF NOT EXISTS albums (id int primary key unique auto_increment, name varchar(100) not null, artist_id int not null references artists on delete restrict, release_year int)");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(statement != null) {
                try {
                    statement.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }

            if(connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

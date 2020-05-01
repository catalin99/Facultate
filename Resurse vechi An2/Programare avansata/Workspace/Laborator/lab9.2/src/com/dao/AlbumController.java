package com.dao;

import java.sql.*;

public class AlbumController {
    public void create(Integer artistID, String name, Integer releaseYear) throws SQLException {
        Connection con = Database.getConnection();
        try (PreparedStatement pstmt = con.prepareStatement("insert into albums (artistID, name, releaseYear) values (?, ?, ?)")) {
            pstmt.setString(1, String.valueOf(artistID));
            pstmt.setString(2, name);
            pstmt.setString(3, String.valueOf(releaseYear));
            pstmt.executeUpdate();
        }
    }
    public void list(Integer artistID) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.getResultSet()) {
            stmt.executeQuery("select name from albums where id = artistID");
            System.out.println(rs.next() ? rs.getInt(1) : null);
        }
    }
}

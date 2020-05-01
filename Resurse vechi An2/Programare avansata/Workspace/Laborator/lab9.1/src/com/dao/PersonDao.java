package com.dao;

import java.util.List;

public interface PersonDao {
    void createPersonTable();
    void insert(com.entities.Person person);
    com.entities.Person selectById(int id);
    List<com.entities.Person> selectAll();
    void delete(int id);
    void update(com.entities.Person person, int id);
}

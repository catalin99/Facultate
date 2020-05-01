package server;

import java.util.ArrayList;
import java.util.List;

public class Person {
    private String name;
    private boolean logged;

    private List<Person> friendsList;
    private List<String> messageList;

    Person(String name) {
        friendsList = new ArrayList<>();
        messageList = new ArrayList<>();
        this.name = name;
        this.logged = false;
    }

    public void setLogged(boolean logged) {
        this.logged = logged;
    }

    public boolean isLogged() {
        return logged;
    }

    public String getName() {
        return name;
    }

    public List<Person> getFriendsList() {
        return friendsList;
    }

    public String getMessages() {
        StringBuilder output = new StringBuilder();
        for (String msg : messageList) {
            output.append(msg + "\n");
        }

        messageList = new ArrayList<>();
        return output.toString();
    }

    void addFriend(Person friend) {
        friendsList.add(friend);
    }

    void addMessage(String message) {
        messageList.add(message);
    }

}

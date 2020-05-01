import java.util.ArrayList;
import java.util.List;

public class Person {
    private String name;
    private Boolean logged;
    private List<Person> friendList;
    private List<String> messageList;

    public Person(String name) {
        this.name = name;
        this.logged = false;
        this.friendList = new ArrayList<>();
        this.messageList = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Boolean getLogged() {
        return logged;
    }

    public void setLogged(Boolean logged) {
        this.logged = logged;
    }

    public void addFriend(Person friend)
    {
        friendList.add(friend);
    }

    public void addMessage(String message)
    {
        messageList.add(message);
    }

    public String getMessages()
    {
        StringBuilder retStr=new StringBuilder();
        for(String str:messageList)
        {
            retStr.append(str);
            retStr.append("\n");
        }
        messageList.clear();
        return retStr.toString();
    }

    public List<Person> getFriendList()
    {
        return friendList;
    }

    public void setLogged(){
        this.logged=true;
    }
}

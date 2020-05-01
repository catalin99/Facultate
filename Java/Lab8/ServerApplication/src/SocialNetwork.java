import java.util.ArrayList;
import java.util.List;

public class SocialNetwork {
    private List<Person> personList;

    public SocialNetwork() {
        this.personList = new ArrayList<>();
    }

    public String Register(String name)
    {
        if(personList.isEmpty()==false)
            for(Person pp:personList)
            {
                if(pp.getName().equals(name))
                    return "[SocialNetwork] Error! A person with this name is already registered\n";
            }
        Person person=new Person(name);

        personList.add(person);
        return "[SocialNetwork] Registration complete!\n";
    }

    public String Login(String name)
    {
        for(Person pp:personList)
        {
            if(pp.getName().equals(name))
            {
                if(pp.getLogged()==true)
                    return "[SocialNetwork] Person already logged\n";
                pp.setLogged(true);
                return "[SocialNetwork] Login complete!\n";
            }
        }
        return "[SocialNetwork] Login failed!\n";
    }

    public Person getPerson (String name)
    {
        for(Person pp: personList)
        {
            if(pp.getName().equalsIgnoreCase(name))
                return pp;
        }
        return null;
    }
    public String addFriends(String name, List<String> friends)
    {
        Person person = getPerson(name);
        if(person==null)
            return "[SocialNetwork] You are not logged in!\n";
        Integer friendsAdded=0;
        for(String friend:friends)
        {
            if(person.getFriendList().contains(name)==false)
            {
                Person friendPerson=getPerson(friend);
                if(friendPerson!=null)
                {
                    person.addFriend(friendPerson);
                    friendsAdded++;
                }
            }

        }
        return "[SocialNetwork]" + friendsAdded.toString()+" friends was added for user " + name + "\n";
    }

    public String send(String name, String msg)
    {
        Person person=getPerson(name);
        if(person==null)
            return "[SocialNetwork] You are not logged in!\n";
        for(Person friend:person.getFriendList())
        {
            friend.addMessage(msg);
        }
        return "[SocialNetwork] Message added\n";

    }

    public String read(String name){
        Person person=getPerson(name);
        return "[SocialNetwork] Messages from friends:\n" + person.getMessages();
    }

}

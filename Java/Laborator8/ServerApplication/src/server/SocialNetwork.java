package server;

import java.util.ArrayList;
import java.util.List;

public class SocialNetwork {
    private List<Person> personList;

    SocialNetwork() {
        personList = new ArrayList<>();
    }

    String login(String name) {

        Person person = getPerson(name);

        if (person != null) {
            if (person.isLogged())
                return "Error! Already logged in!";
            else {
                person.setLogged(true);
                return "Logged in successfully";
            }
        }

        return "Error! Invalid name";
    }

    String register(String name) {
        boolean ok = true;

        Person person = getPerson(name);
        if (person != null)
            return "Error! Account already exists!";

        personList.add(new Person(name));
        return "Account created!";
    }

    Person getPerson(String name) {
        for (Person person : personList)
            if (person.getName().equalsIgnoreCase(name))
                return person;

        return null;
    }

    String addFriends(String name, List<String> friendList) {
        Person person = getPerson(name);
        int count = 0;

        if (person != null) {
            if (!person.isLogged())
                return "Error! You are not logged in!";

            for (String friendName : friendList) {
                Person friend = getPerson(friendName);

                if (friend != null) {
                    count++;
                    person.addFriend(friend);
                }
            }
        }

        return "Added " + count + " new friends!";
    }

    String send(String name, String message) {
        Person person = getPerson(name);

        if (person != null) {
            if (!person.isLogged())
                return "Error! You are not logged in!";

            for (Person friend : person.getFriendsList())
                friend.addMessage(message);

            return "Messages send!";
        }

        return "Error!";
    }

    String read(String name) {
        Person person = getPerson(name);

        if (person != null) {
            if (!person.isLogged())
                return "Error! You are not logged in!";

            return person.getMessages();
        }

        return "Error!";
    }
}

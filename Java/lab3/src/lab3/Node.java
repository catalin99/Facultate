package lab3;

import java.util.*;

public class Node implements Comparable{
    protected String name;

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Node{" +
                "name='" + name + '\'' +
                '}';
    }

    @Override
    public int compareTo(Object o) {
        if (this==o)
            return 1;
        else
            return 0;
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
}

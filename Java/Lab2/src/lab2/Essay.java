/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
import java.time.LocalDate;
/**
 *
 * @author catal
 */
public class Essay extends Project{
    Topic topic;
    String nameTopic;
    String date;
    
    public Essay(String topicname, LocalDate data, Topic topicc) {
        
        this.topic = topicc;
        this.nameTopic=topicname;
        this.date=data.toString();
    }

    public Topic getTopic() {
        return topic;
    }

    public void setTopic(Topic topic) {
        this.topic = topic;
    }

    @Override
    public String toString() {
        return "Essay{" + "topic=" + topic + '}';
    }
}

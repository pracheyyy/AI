package ex2;

public class Student {

    String name;
    int prn;
    int roll;
    String mail;

    Student() {
        name = "Prachi";
        prn = 1000;
        roll = 32;
        mail = "prachi@gmail.com";
    }

    static int count = 1001;
    
    Student(String name, int roll, String mail) {
        this.name = name;
        this.prn = count++;
        this.roll = roll;
        this.mail = mail;
    }

    void display() {
        System.out.println("Student Information");
        System.out.println("Name: " + name);
        System.out.println("PRN: " + prn);
        System.out.println("Roll: " + roll);
        System.out.println("Mail: " + mail);
    }
}
package ex1;

public class Student {

    String name;
    int roll;
    String mobile;
    String mail;

    void getdata(String name, int roll, String mobile, String mail) {

        this.name = name;
        this.roll = roll;
        this.mobile = mobile;
        this.mail = mail;
    }

    void display() {

        System.out.println("Name: " + name);
        System.out.println("Roll: " + roll);
        System.out.println("Mobile: " + mobile);
        System.out.println("Mail: " + mail);
    }
}
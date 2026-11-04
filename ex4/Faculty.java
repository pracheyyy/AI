package ex4;

public class Faculty extends Person {

    String subject;

    Faculty(String name, int age, String subject) {

        super(name, age);
        this.subject = subject;
    }

    @Override
    void display() {

        super.display();

        System.out.println("Subject: " + subject);
    }
}
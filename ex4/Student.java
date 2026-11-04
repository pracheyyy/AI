package ex4;

public class Student extends Person {

    int roll;
    String course;

    Student(String name, int age, int roll, String course) {

        super(name, age);

        this.roll = roll;
        this.course = course;
    }

    @Override
    void display() {

        super.display();

        System.out.println("Roll: " + roll);
        System.out.println("Course: " + course);
    }
}
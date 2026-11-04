package ex2;

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();
        s1.display();

        System.out.println("--------------------");

        Student s2 = new Student("Rahul", 45, "rahul@gmail.com");
        s2.display();

        System.out.println("--------------------");

        Student s3 = new Student("Mayur", 42, "mayurmun@gmail.com");
        s3.display();
    }
}
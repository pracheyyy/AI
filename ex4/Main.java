package ex4;

public class Main {

    public static void main(String[] args) {

        Student s = new Student("Prachi", 20, 32, "IT");

        Faculty f = new Faculty("Priya", 35, "Java");

        AdminStaff a = new AdminStaff("Rahul", 40, "Accounts");

        System.out.println("Student Details");
        s.display();

        System.out.println("----------------");

        System.out.println("Faculty Details");
        f.display();

        System.out.println("----------------");

        System.out.println("Admin Details");
        a.display();
    }
}
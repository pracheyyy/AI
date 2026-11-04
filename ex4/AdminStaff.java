package ex4;

public class AdminStaff extends Person {

    String department;

    AdminStaff(String name, int age, String department) {

        super(name, age);
        this.department = department;
    }

    @Override
    void display() {

        super.display();

        System.out.println("Department: " + department);
    }
}
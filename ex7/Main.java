package ex7;
import java.util.*;

public class Main {

    public static void main(String[] args) {


        List<String> orders = new ArrayList<>();

        orders.add("Laptop");
        orders.add("Mobile");
        orders.add("Keyboard");

        System.out.println("ORDER MANAGEMENT");
        System.out.println("Orders: " + orders);

        Queue<String> orderQueue = new LinkedList<>();

        orderQueue.add("Order 101");
        orderQueue.add("Order 102");
        orderQueue.add("Order 103");

        System.out.println("Processing: " + orderQueue.poll());
        System.out.println("Remaining Orders: " + orderQueue);

        System.out.println("-------------------------");


        // 2. MOVIE TICKET BOOKING SYSTEM

        Set<String> bookedSeats = new HashSet<>();

        bookedSeats.add("A1");
        bookedSeats.add("A2");
        bookedSeats.add("A3");

        bookedSeats.add("A1"); // Duplicate seat

        System.out.println("MOVIE TICKET BOOKING");
        System.out.println("Booked Seats: " + bookedSeats);

        if (bookedSeats.add("A2")) {
            System.out.println("Seat booked successfully");
        } else {
            System.out.println("Seat A2 is already booked");
        }

        System.out.println("-------------------------");


        // 3. TEAM MANAGEMENT SYSTEM

        Map<Integer, String> team = new HashMap<>();

        team.put(101, "Prachi");
        team.put(102, "Rahul");
        team.put(103, "Priya");

        System.out.println("TEAM MANAGEMENT");
        System.out.println("Team Members: " + team);

        System.out.println("Employee 101: " + team.get(101));

        team.remove(102);

        System.out.println("Updated Team: " + team);
    }
}

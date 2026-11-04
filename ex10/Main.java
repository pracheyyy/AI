package ex10;


import java.util.*;
import java.util.stream.*;

public class Main {

    public static void main(String[] args) {

        // A. Filter even numbers
        List<Integer> numbers = Arrays.asList(5, 12, 7, 8, 15, 24, 33, 16);

        System.out.println("Even Numbers:");

        numbers.stream()
               .filter(n -> n % 2 == 0)
               .forEach(System.out::println);


        // B. Convert names to uppercase
        List<String> names = Arrays.asList(
            "Prachi", "Rahul", "Meena", "Akash"
        );

        System.out.println("\nNames in Uppercase:");

        names.stream()
             .map(name -> name.toUpperCase())
             .forEach(System.out::println);


        // C. Count strings starting with A
        List<String> fruits = Arrays.asList(
            "Apple", "Banana", "Avocado",
            "Apricot", "Berry", "Cherry"
        );

        long count = fruits.stream()
                           .filter(s -> s.startsWith("A"))
                           .count();

        System.out.println("\nStrings starting with A: " + count);


        // D. Sort numbers
        System.out.println("\nSorted Numbers:");

        numbers.stream()
               .sorted()
               .forEach(System.out::println);
    }
}


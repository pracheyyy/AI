package ex3;

public class Main {

    public static void main(String[] args) {

        Calculator c = new Calculator();

        System.out.println("Integer Addition: " + c.calculate(10, 20));

        System.out.println("Double Addition: " + c.calculate(5.5, 2.5));

        System.out.println("Multiplication: " + c.calculate(2, 3, 4));

        System.out.println("Sin 30: " + c.calculate(30.0));

        System.out.println("Log 100 base 10: " + c.calculate(100.0, 10));

        int[][] a = {{1, 2}, {3, 4}};
        int[][] b = {{5, 6}, {7, 8}};

        int[][] result = c.calculate(a, b);

        System.out.println("Matrix Addition:");

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}
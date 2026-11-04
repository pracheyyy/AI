package ex3;

public class Calculator {

    int calculate(int a, int b) {
        return a + b;
    }

    double calculate(double a, double b) {
        return a + b;
    }

    int calculate(int a, int b, int c) {
        return a * b * c;
    }

    double calculate(double angle) {
        return Math.sin(Math.toRadians(angle));
    }

    double calculate(double number, int base) {
        return Math.log(number) / Math.log(base);
    }

    int[][] calculate(int[][] a, int[][] b) {

        int rows = a.length;
        int cols = a[0].length;

        int[][] result = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        return result;
    }
}
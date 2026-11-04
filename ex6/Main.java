package ex6;

public class Account {

    String holderName;
    double balance;

    Account(String holderName, double balance) {
        this.holderName = holderName;
        this.balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient Balance");
        }
    }

    void displayBalance() {
        System.out.println("Account Holder: " + holderName);
        System.out.println("Balance: " + balance);
    }
}

class TaxCalculator {

    double calculateTax(double income) {

        if (income <= 250000) {
            return 0;
        }
        else if (income <= 500000) {
            return income * 0.05;
        }
        else {
            return income * 0.10;
        }
    }
}

public class Main {

    public static void main(String[] args) {

        // Account operations
        Account a = new Account("Prachi", 10000);

        a.deposit(5000);
        a.withdraw(2000);
        a.displayBalance();

        System.out.println("--------------------");

        // Tax calculation
        TaxCalculator t = new TaxCalculator();

        double income = 400000;
        double tax = t.calculateTax(income);

        System.out.println("Income: " + income);
        System.out.println("Calculated Tax: " + tax);
    }
} 
    
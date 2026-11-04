package ex9;


class InvalidAmountException extends Exception {

    InvalidAmountException(String message) {
        super(message);
    }
}

class BankAccount {

    double balance = 10000;

    void withdraw(double amount) throws InvalidAmountException {

        if (amount <= 0) {
            throw new InvalidAmountException("Invalid withdrawal amount!");
        }

        if (amount > balance) {
            throw new InvalidAmountException("Insufficient balance!");
        }

        balance = balance - amount;

        System.out.println("Withdrawal Successful!");
        System.out.println("Withdrawn Amount: " + amount);
    }

    void displayBalance() {
        System.out.println("Available Balance: " + balance);
    }
}

public class Main {

    public static void main(String[] args) {

        BankAccount account = new BankAccount();

        try {

            System.out.println("Banking Application");

            account.withdraw(12000);

        }
        catch (InvalidAmountException e) {

            System.out.println("Exception: " + e.getMessage());

        }
        finally {

            System.out.println("Transaction Completed");
            account.displayBalance();

        }
    }
}


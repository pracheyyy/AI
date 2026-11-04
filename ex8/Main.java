package ex8;

class InsufficientBalanceException extends Exception {

    InsufficientBalanceException(String message) {
        super(message);
    }
}

class BankAccount {

    String name;
    double balance;

    BankAccount(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    void withdraw(double amount) throws InsufficientBalanceException {

        if (amount > balance) {
            throw new InsufficientBalanceException(
                "Insufficient balance! Cannot withdraw " + amount
            );
        }

        balance = balance - amount;

        System.out.println("Withdrawal successful: " + amount);
    }

    void displayBalance() {
        System.out.println("Account Holder: " + name);
        System.out.println("Available Balance: " + balance);
    }
}

public class Main {

    public static void main(String[] args) {

        BankAccount account = new BankAccount("Prachi", 10000);

        try {

            System.out.println("Attempting withdrawal...");

            account.withdraw(12000);

        }
        catch (InsufficientBalanceException e) {

            System.out.println("Exception caught: " + e.getMessage());

        }
        finally {

            System.out.println("Transaction completed.");

            account.displayBalance();

        }

    }
}

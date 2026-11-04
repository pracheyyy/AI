package ex5;

public class Main {

    public static void main(String[] args) {

        SmartTV tv = new SmartTV();

        tv.turnOn();
        tv.connectToInternet();
        tv.playMovie("Avengers");
        tv.turnOff();

        System.out.println("------------------");

        SmartFridge fridge = new SmartFridge();

        fridge.turnOn();
        fridge.connectToInternet();
        fridge.setTemperature(4);
        fridge.turnOff();

    }
}
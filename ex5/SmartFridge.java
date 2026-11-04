package ex5;

public class SmartFridge implements ControllableDevice, InternetEnabled {

    public void turnOn() {
        System.out.println("Smart Fridge is ON");
    }

    public void turnOff() {
        System.out.println("Smart Fridge is OFF");
    }

    public void connectToInternet() {
        System.out.println("Smart Fridge connected to WiFi");
    }

    void setTemperature(int temperature) {
        System.out.println("Fridge temperature: " + temperature);
    }
}
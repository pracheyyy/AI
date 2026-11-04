package ex5;

public class SmartTV implements ControllableDevice, InternetEnabled {

    public void turnOn() {
        System.out.println("Smart TV is ON");
    }

    public void turnOff() {
        System.out.println("Smart TV is OFF");
    }

    public void connectToInternet() {
        System.out.println("Smart TV connected to WiFi");
    }

    void playMovie(String movie) {
        System.out.println("Playing movie: " + movie);
    }
}
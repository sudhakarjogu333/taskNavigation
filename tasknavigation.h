
import java.util.Random;
class VehicleData {
    private int speed;             // Speed in km/h
    private double fuelLevel;      // Fuel level in percentage
    private int engineTemperature; // Temperature in Celsius

    // Constructor
    public VehicleData(int speed, double fuelLevel, int engineTemperature) {
        this.speed = speed;
        this.fuelLevel = fuelLevel;
        this.engineTemperature = engineTemperature;
    }

    // Getters and Setters
    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public double getFuelLevel() {
        return fuelLevel;
    }

    public void setFuelLevel(double fuelLevel) {
        this.fuelLevel = fuelLevel;
    }

    public int getEngineTemperature() {
        return engineTemperature;
    }

    public void setEngineTemperature(int engineTemperature) {
        this.engineTemperature = engineTemperature;
    }

    // Method to update the vehicle data randomly
    public void updateData() {
        Random random = new Random();
        this.speed = random.nextInt(121); // Random speed between 0 and 120 km/h
        this.fuelLevel = random.nextDouble() * 100; // Random fuel level between 0 and 100%
        this.engineTemperature = random.nextInt(51) - 10; // Random temperature between -10 and 40°C




    }
}

class Display {

    // Method to display the current vehicle data
    public static void displayData(VehicleData vehicleData) {
        int speed = vehicleData.getSpeed();
        double fuelLevel = vehicleData.getFuelLevel();
        int engineTemperature = vehicleData.getEngineTemperature();

        // Display the current data
        System.out.printf("Speed: %d km/h | Fuel: %.2f%% | Temperature: %d°C%n", speed, fuelLevel, engineTemperature);

        // Display warnings if certain thresholds are exceeded
        if (engineTemperature > 100) {
            System.out.println("WARNING: Engine temperature is too high!well it's too hot here I want to retire the race.");
        }

        if (fuelLevel < 10) {
            System.out.println("WARNING: Fuel level is low!please box now");
        }
    }
}





public class Main {

    public static void main(String[] args) {
        // Create an instance of VehicleData with initial values (for example purposes)
        VehicleData vehicleData = new VehicleData(0, 100.0, 20); // Initial values: speed 0 km/h, full fuel, normal temperature

        // Start an infinite loop to simulate continuous updates
        while (true) {

            vehicleData.updateData();


            Display.displayData(vehicleData);

            // Wait for 1 second before updating again
            try {
                Thread.sleep(1000); // 1000 milliseconds = 1 
                break;

            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}



















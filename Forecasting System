#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream> // For file operations

using namespace std;

// Location class definition
class Location {
public:
    string name;
    double latitude;
    double longitude;

    Location(const string& name, double latitude, double longitude)
        : name(name), latitude(latitude), longitude(longitude) {}
};

// LocationManager class definition
class LocationManager {
private:
    vector<Location> locations;

public:
    void addLocation(const string& name, double latitude, double longitude) {
        Location newLocation(name, latitude, longitude);
        locations.push_back(newLocation);
        cout << "Location " << name << " added.\n";
    }

    void removeLocation(const string& name) {
        auto it = remove_if(locations.begin(), locations.end(),
                            [&name](const Location& location) {
                                return location.name == name;
                            });
        if (it != locations.end()) {
            locations.erase(it, locations.end());
            cout << "Location " << name << " removed.\n";
        } else {
            cout << "Location " << name << " not found.\n";
        }
    }

    void listLocations() const {
        if (locations.empty()) {
            cout << "No locations available.\n";
            return;
        }

        cout << "Listing all locations:\n";
        for (const auto& location : locations) {
            cout << "Name: " << location.name
                 << ", Latitude: " << location.latitude
                 << ", Longitude: " << location.longitude << "\n";
        }
    }
};

// WeatherVariable class definition (unchanged)
class WeatherVariable {
private:
    string name;
    double value;

public:
    WeatherVariable(string name, double value)
        : name(name), value(value) {}

    void setName(const string& name) {
        this->name = name;
    }

    void setValue(double value) {
        this->value = value;
    }

    string getName() const {
        return name;
    }

    double getValue() const {
        return value;
    }
};

// WeatherForecastingSystem class definition (unchanged)
class WeatherForecastingSystem {
public:
    void fetchWeatherData(const string& location) {
        cout << "Fetching weather data for " << location << "...\n";
    }

    void displayWeatherData() const {
        cout << "Displaying weather forecast data...\n";
    }
};

// HistoricalWeatherSystem class definition (unchanged)
class HistoricalWeatherSystem {
public:
    void fetchHistoricalData(const string& location) {
        cout << "Fetching historical weather data for " << location << "...\n";
    }

    void displayHistoricalData() const {
        cout << "Displaying historical weather data...\n";
    }
};

// DataExporter class definition (unchanged)
class DataExporter {
public:
    void exportToCSV(const string& filename) {
        ofstream outfile(filename);

        if (!outfile) {
            cerr << "Error opening file " << filename << " for writing.\n";
            return;
        }

        outfile << "Date,Location,Temperature,Celsius,WindSpeed,m/s\n";
        outfile << "2024-07-08,New York,28,82,5,18\n";
        outfile.close();

        cout << "Exported data to CSV: " << filename << endl;
    }

    void exportToJSON(const string& filename) {
        ofstream outfile(filename);

        if (!outfile) {
            cerr << "Error opening file " << filename << " for writing.\n";
            return;
        }

        outfile << "{\n";
        outfile << "  \"date\": \"2024-07-08\",\n";
        outfile << "  \"location\": \"New York\",\n";
        outfile << "  \"temperature\": 28,\n";
        outfile << "  \"celsius\": 82,\n";
        outfile << "  \"wind_speed\": 5,\n";
        outfile << "  \"m/s\": 18\n";
        outfile << "}\n";
        outfile.close();

        cout << "Exported data to JSON: " << filename << endl;
    }
};

int main() {
    LocationManager locationManager;
    WeatherForecastingSystem weatherSystem;
    HistoricalWeatherSystem historicalSystem;
    DataExporter dataExporter;

    int choice;
    string name, location;
    double latitude, longitude;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Location\n";
        cout << "2. Remove Location\n";
        cout << "3. List Locations\n";
        cout << "4. Fetch Weather Data\n";
        cout << "5. Display Weather Forecast\n";
        cout << "6. Fetch Historical Weather Data\n";
        cout << "7. Display Historical Weather Data\n";
        cout << "8. Export Data to CSV\n";
        cout << "9. Export Data to JSON\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter latitude: ";
                cin >> latitude;
                cout << "Enter longitude: ";
                cin >> longitude;
                locationManager.addLocation(name, latitude, longitude);
                break;
            case 2:
                cout << "Enter name of location to remove: ";
                cin.ignore(); // Ignore newline left in buffer
                getline(cin, name);
                locationManager.removeLocation(name);
                break;
            case 3:
                locationManager.listLocations();
                break;
            case 4:
                cout << "Enter location to fetch weather data: ";
                cin.ignore(); // Ignore newline left in buffer
                getline(cin, location);
                weatherSystem.fetchWeatherData(location);
                break;
            case 5:
                weatherSystem.displayWeatherData();
                break;
            case 6:
                cout << "Enter location to fetch historical data: ";
                cin.ignore(); // Ignore newline left in buffer
                getline(cin, location);
                historicalSystem.fetchHistoricalData(location);
                break;
            case 7:
                historicalSystem.displayHistoricalData();
                break;
            case 8:
                dataExporter.exportToCSV("weather_data.csv");
                break;
            case 9:
                dataExporter.exportToJSON("weather_data.json");
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 10);

    return 0;
}

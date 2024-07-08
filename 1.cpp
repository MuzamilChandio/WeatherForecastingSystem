#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define the Location class
class Location {
public:
    string name;
    double latitude;
    double longitude;

    Location(string name, double latitude, double longitude)
        : name(name), latitude(latitude), longitude(longitude) {}
};

// Define the LocationManager class
class LocationManager {
private:
    vector<Location> locations;

public:
    // Method to add a location
    void addLocation(const string& name, double latitude, double longitude) {
        Location newLocation(name, latitude, longitude);
        locations.push_back(newLocation);
    }

    // Method to remove a location by name
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

    // Method to list all locations
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

int main() {
    LocationManager manager;
    int choice;
    string name;
    double latitude, longitude;

    do {
        cout << "\nLocation Manager Menu:\n";
        cout << "1. Add Location\n";
        cout << "2. Remove Location\n";
        cout << "3. List Locations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input in the stream
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter latitude: ";
                cin >> latitude;
                cout << "Enter longitude: ";
                cin >> longitude;
                manager.addLocation(name, latitude, longitude);
                break;
            case 2:
                cout << "Enter name of location to remove: ";
                cin >> name;
                manager.removeLocation(name);
                break;
            case 3:
                manager.listLocations();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

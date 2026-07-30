
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>
#include <iomanip>

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------
const double EARTH_RADIUS_METERS = 6371000.0; // Mean radius of Earth
const double PI_VAL = 3.14159265358979323846;

// ---------------------------------------------------------------------------
// Utility: convert degrees to radians
// ---------------------------------------------------------------------------
double toRadians(double degree)
{
    return degree * (PI_VAL / 180.0);
}

// ---------------------------------------------------------------------------
// Class: Location
// Represents a single geographic point (latitude, longitude) with a name.
// ---------------------------------------------------------------------------
class Location
{
public:
    std::string name;
    double latitude;
    double longitude;

    Location() : name("Unknown"), latitude(0.0), longitude(0.0) {}

    Location(std::string n, double lat, double lon)
        : name(n), latitude(lat), longitude(lon) {}

    void display() const
    {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << name << "  (Lat: " << latitude
                  << ", Lon: " << longitude << ")\n";
    }
};

// ---------------------------------------------------------------------------
// Function: haversineDistance
// Calculates the great-circle distance (in meters) between two Location
// points using the Haversine formula.
// ---------------------------------------------------------------------------
double haversineDistance(const Location &a, const Location &b)
{
    double lat1 = toRadians(a.latitude);
    double lat2 = toRadians(b.latitude);
    double dLat = toRadians(b.latitude - a.latitude);
    double dLon = toRadians(b.longitude - a.longitude);

    double h = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(lat1) * std::cos(lat2) *
                   std::sin(dLon / 2) * std::sin(dLon / 2);

    double c = 2 * std::atan2(std::sqrt(h), std::sqrt(1 - h));

    return EARTH_RADIUS_METERS * c; // distance in meters
}

// ---------------------------------------------------------------------------
// Class: GeoMarker
// Represents a location "pin" the user has marked, along with the radius
// (in meters) within which a notification should be triggered, and whether
// the marker has already fired its alert.
// ---------------------------------------------------------------------------
class GeoMarker
{
public:
    Location markedLocation;
    double radiusMeters;
    bool notified;

    GeoMarker(Location loc, double radius)
        : markedLocation(loc), radiusMeters(radius), notified(false) {}

    // Checks the current location against this marker.
    // Returns true if the user is within range (and prints a notification).
    bool checkProximity(const Location &current)
    {
        double distance = haversineDistance(markedLocation, current);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  -> Distance to \"" << markedLocation.name << "\": "
                  << distance << " m\n";

        if (distance <= radiusMeters && !notified)
        {
            triggerNotification(distance);
            notified = true;
            return true;
        }
        return false;
    }

    void triggerNotification(double distance) const
    {
        std::cout << "\n"
                  << "  *******************************************\n"
                  << "  *   NOTIFICATION: You are near \"" << markedLocation.name << "\"!\n"
                  << "  *   Distance    : " << distance << " m\n"
                  << "  *   Wake up / take action now.\n"
                  << "  *******************************************\n\n";
    }

    void reset() { notified = false; }
};

// ---------------------------------------------------------------------------
// Class: LocationTracker
// Manages the marked location(s) and simulates periodic GPS updates,
// checking proximity on every "tick" (representing a real-time GPS poll).
// ---------------------------------------------------------------------------
class LocationTracker
{
private:
    std::vector<GeoMarker> markers;

public:
    void addMarker(const GeoMarker &marker)
    {
        markers.push_back(marker);
        std::cout << "\nMarker added successfully:\n  ";
        marker.markedLocation.display();
        std::cout << "  Notification radius: " << marker.radiusMeters << " m\n";
    }

    bool hasMarkers() const { return !markers.empty(); }

    void listMarkers() const
    {
        if (markers.empty())
        {
            std::cout << "No markers set yet.\n";
            return;
        }
        std::cout << "\nCurrent markers:\n";
        for (size_t i = 0; i < markers.size(); ++i)
        {
            std::cout << "  [" << i + 1 << "] ";
            markers[i].markedLocation.display();
        }
    }

    // Simulates a monitoring session: repeatedly asks for the current
    // location (representing a live GPS feed) and checks it against every
    // active marker until the user stops or all markers have notified.
    void startMonitoring()
    {
        if (markers.empty())
        {
            std::cout << "\nNo markers set. Please mark a location first.\n";
            return;
        }

        int tick = 1;
        char choice;

        std::cout << "\n--- Monitoring started ---\n";
        std::cout << "(Each round simulates one GPS update / time interval)\n";

        do
        {
            std::cout << "\n[Update #" << tick << "] Enter current location:\n";
            double lat, lon;
            std::cout << "  Latitude : ";
            std::cin >> lat;
            std::cout << "  Longitude: ";
            std::cin >> lon;

            Location current("Current Position", lat, lon);

            for (auto &marker : markers)
            {
                if (!marker.notified)
                {
                    marker.checkProximity(current);
                }
            }

            if (allNotified())
            {
                std::cout << "\nAll markers have notified. Monitoring complete.\n";
                break;
            }

            std::cout << "\nContinue monitoring? (y/n): ";
            std::cin >> choice;
            tick++;

        } while (choice == 'y' || choice == 'Y');

        std::cout << "\n--- Monitoring stopped ---\n";
    }

    bool allNotified() const
    {
        for (const auto &m : markers)
        {
            if (!m.notified)
                return false;
        }
        return true;
    }

    void resetAll()
    {
        for (auto &m : markers)
            m.reset();
        std::cout << "All markers reset.\n";
    }
};

// ---------------------------------------------------------------------------
// Helper: clears bad input from std::cin
// ---------------------------------------------------------------------------
void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ---------------------------------------------------------------------------
// Main menu-driven program
// ---------------------------------------------------------------------------
void printMenu()
{
    std::cout << "\n============================================\n";
    std::cout << "   LOCATION MARKER & NOTIFICATION SYSTEM\n";
    std::cout << "============================================\n";
    std::cout << "  1. Mark a new location\n";
    std::cout << "  2. View marked locations\n";
    std::cout << "  3. Start monitoring (simulate GPS updates)\n";
    std::cout << "  4. Reset all markers\n";
    std::cout << "  5. Exit\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Enter choice: ";
}

int main()
{
    LocationTracker tracker;
    int choice;

    std::cout << "Welcome to the Location Marker & Notification System.\n";
    std::cout << "This tool marks a location and alerts you once your\n";
    std::cout << "current position is within a set radius of it.\n";

    do
    {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail())
        {
            clearInput();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            std::string name;
            double lat, lon, radius;

            std::cout << "\nEnter a name for this location (e.g. Home, Office Stop): ";
            std::cin >> name;

            std::cout << "Enter latitude  (e.g. 27.6710): ";
            std::cin >> lat;
            std::cout << "Enter longitude (e.g. 85.3245): ";
            std::cin >> lon;
            std::cout << "Enter notification radius in meters (e.g. 200): ";
            std::cin >> radius;

            Location loc(name, lat, lon);
            GeoMarker marker(loc, radius);
            tracker.addMarker(marker);
            break;
        }
        case 2:
            tracker.listMarkers();
            break;
        case 3:
            tracker.startMonitoring();
            break;
        case 4:
            tracker.resetAll();
            break;
        case 5:
            std::cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please select 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}
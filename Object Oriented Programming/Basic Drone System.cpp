#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Drone
{
protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    Drone(float lat, float lon, float alt, float spd) : latitude(lat), longitude(lon), altitude(alt), speed(spd) {}

    virtual void adjustAltitude(float meters)
    {
        if ((altitude + meters) < 0)
        {
            cout << "Altitude cannot be negative" << endl;
            return;
        }

        altitude += meters;
    }

    virtual void setSpeed(float s)
    {
        if (s < 0)
        {
            cout << "Speed cannot be negative" << endl;
            return;
        }

        speed = s;
    }

    virtual ~Drone() {}
};

class Flyable
{
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
    virtual ~Flyable() {}
};

class Scannable
{
public:
    virtual void scanArea(float radius) = 0;
    virtual ~Scannable() {}
};

class ReconDrone : public Drone, public Flyable, public Scannable
{
    float cameraResolution;
    float maxFlightTime;

public:
    ReconDrone(float lat, float lon, float alt, float spd, float cr, float mft) : Drone(lat, lon, alt, spd), cameraResolution(cr), maxFlightTime(mft) {}

    void takeoff() override
    {
        cout << "ReconDrone taking off from coordinates (" << latitude << ", " << longitude << ") at altitude: " << altitude << " meters" << endl;
    }

    void land() override
    {
        cout << "ReconDrone landing at coordinates (" << latitude << ", " << longitude << ") at altitude: " << altitude << " meters" << endl;
    }

    void navigateTo(float lat, float lon, float alt) override
    {
        if (lat < -90 || lat > 90 || lon < -180 || lon > 180)
        {
            cout << "Invalid GPS coordinates" << endl;
            return;
        }

        float distance = sqrt(pow(lat - latitude, 2) + pow(lon - longitude, 2));
        float estimatedTime = distance / speed;
        cout << "Navigating to coordinates (" << lat << ", " << lon << ") at altitude: " << alt << " meters." << endl;
        cout << "Estimated time to reach destination: " << estimatedTime << " hours." << endl;

        latitude = lat;
        longitude = lon;
        altitude = alt;
    }

    void scanArea(float radius) override
    {
        cout << "Scanning area within " << radius << "m radius." << endl;

        int objectsDetected = rand() % 10 + 1;

        cout << "Number of objects detected: " << objectsDetected << endl;
        for (int i = 0; i < objectsDetected; i++)
        {
            cout << "Object " << i + 1 << ": (" << latitude + (rand() % 10) / 10.0 << ", " << longitude + (rand() % 10) / 10.0 << ")" << endl;
        }
    }
};

int main()
{
    ReconDrone myDrone(0, 0, 0, 0, 1080, 2);
    myDrone.setSpeed(50);
    myDrone.adjustAltitude(500);

    myDrone.takeoff();

    myDrone.navigateTo(34.0522, -118.2437, 1000);
    myDrone.scanArea(100);

    cout << endl;
    myDrone.land();

    return 0;
}
#include <iostream>
#include <cstdlib> // For rand()

using namespace std;

class Passenger
{
private:
    int mobileNum;
    string pickup;
    string dropoff;
    int KMtoTravel;
    string category;

public:
    Passenger(int mn, string p, string d, int km, string c) : mobileNum(mn), pickup(p), dropoff(d), KMtoTravel(km), category(c) {}

    int getMobileNum()
    {
        return mobileNum;
    }
    void setMobileNum(int mn)
    {
        mobileNum = mn;
    }

    string getPickup()
    {
        return pickup;
    }
    void setPickup(string p)
    {
        pickup = p;
    }

    string getDropoff()
    {
        return dropoff;
    }
    void setDropoff(string d)
    {
        dropoff = d;
    }

    int getKMtoTravel()
    {
        return KMtoTravel;
    }
    void setKMtoTravel(int km)
    {
        KMtoTravel = km;
    }

    string getCategory()
    {
        return category;
    }
    void setCategory(string c)
    {
        category = c;
    }

    void display()
    {
        cout << "Mobile Num: " << mobileNum << endl;
        cout << "Pickup: " << pickup << endl;
        cout << "Drop-off: " << dropoff << endl;
        cout << "KMs to Travel: " << KMtoTravel << endl;
        cout << "Category: " << category << endl;
    }
};

class Driver
{
private:
    int dailyFuelQuota;
    int currentFuel;
    string name;
    int ID;
    int currentEarning;
    int alphaCount;
    int betaCount;
    int gammaCount;
    int alphaEarning;
    int betaEarning;
    int gammaEarning;

public:
    const int fuelPerKM = 2;

    Driver(string n, int id) : name(n), ID(id)
    {
        dailyFuelQuota = 0;
        currentFuel = dailyFuelQuota;
        currentEarning = 0;
        alphaCount = 0;
        betaCount = 0;
        gammaCount = 0;
        alphaEarning = 0;
        betaEarning = 0;
        gammaEarning = 0;
    }

    void allocateFuel(string n, int id)
    {
        name = n;
        ID = id;
        dailyFuelQuota = rand() % 400 + 50;
        currentFuel = dailyFuelQuota;
    }

    void assignPassenger(Passenger passengers[], int numPassengers)
    {
        for (int i = 0; i < numPassengers; i++)
        {

            int fuelRequired = passengers[i].getKMtoTravel() * fuelPerKM;
            if (fuelRequired <= currentFuel)
            {
                currentFuel -= fuelRequired;
                cout << endl
                     << "Passenger assigned!" << endl;
                passengers[i].display();

                int earning;
                if (passengers[i].getCategory() == "Alpha" || passengers[i].getCategory() == "alpha")
                {
                    alphaCount++;
                    earning = passengers[i].getKMtoTravel() * 150;
                    alphaEarning += earning;
                }
                else if (passengers[i].getCategory() == "Beta" || passengers[i].getCategory() == "beta")
                {
                    betaCount++;
                    earning = passengers[i].getKMtoTravel() * 100;
                    betaEarning += earning;
                }
                else if (passengers[i].getCategory() == "gamma" || passengers[i].getCategory() == "Gamma")
                {
                    gammaCount++;
                    earning = passengers[i].getKMtoTravel() * 70;
                    gammaEarning += earning;
                }

                cout << "Earning: " << earning << endl;
                currentEarning += earning;
            }
            else
            {
                cout << endl
                     << "Insufficient fuel for ride " << i + 1 << endl;
            }
        }
    }

    // Display remaining fuel with units
    void displayCurrentFuel()
    {
        cout << "Remaining Fuel: " << currentFuel << " liters" << endl;
    }

    // Display earnings for each passenger type and total earning
    void displayAllTypesEarnings()
    {
        cout << "Earning per Type:" << endl;
        cout << "Alpha: " << alphaEarning << endl;
        cout << "Beta: " << betaEarning << endl;
        cout << "Gamma: " << gammaEarning << endl;
        cout << "Total Earning: " << currentEarning << endl;
    }

    // Check for bonus eligibility and reward the driver if applicable
    void checkBonus()
    {
        if (alphaCount > betaCount && alphaCount > gammaCount)
        {
            currentEarning += 500;
            cout << "Bonus awarded: Rs. 500" << endl;
        }
    }
};

int main()
{
    Passenger passengers[5] = {Passenger(6643, "Steel Town", "Hyderabad", 20, "Gamma"),
                               Passenger(6234, "Korangi", "Sukkar", 15, "Alpha"),
                               Passenger(6532, "Hadeed", "Lyari", 14, "Gamma"),
                               Passenger(2346, "Gulshan", "Defence", 3, "Alpha"),
                               Passenger(8643, "Johar", "PECHS", 10, "Beta")};

    Driver d1("Haider", 666);
    d1.allocateFuel("Haider", 666);
    d1.displayCurrentFuel();

    // Assign passengers to the driver
    d1.assignPassenger(passengers, sizeof(passengers) / sizeof(passengers[0]));

    d1.displayCurrentFuel();
    cout << endl;
    d1.displayAllTypesEarnings();

    return 0;
}
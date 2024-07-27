#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;
    double odometer;
    string vin;

public:
    Vehicle(string make, string model, int year, double odometer, string vin) : make(make), model(model), year(year), odometer(odometer), vin(vin) {}

    virtual void getVehicleType() = 0;

    string getMake()
    {
        return make;
    }
    string getModel()
    {
        return model;
    }
    int getYear()
    {
        return year;
    }
    double getOdometer()
    {
        return odometer;
    }
    string getVIN()
    {
        return vin;
    }
};

class CompactCar : public Vehicle
{
public:
    CompactCar(string make, string model, int year, double odometer, string vin) : Vehicle(make, model, year, odometer, vin) {}

    void getVehicleType() override
    {
        cout << "Compact Car" << endl;
    }
};

class StandardCar : public Vehicle
{
public:
    StandardCar(string make, string model, int year, double odometer, string vin) : Vehicle(make, model, year, odometer, vin) {}

    void getVehicleType() override
    {
        cout << "Standard Car" << endl;
    }
};

class LuxuryCar : public Vehicle
{
public:
    LuxuryCar(string make, string model, int year, double odometer, string vin) : Vehicle(make, model, year, odometer, vin) {}

    void getVehicleType() override
    {
        cout << "Luxury Car" << endl;
    }
};

class Customer
{
private:
    string name;
    string address;
    string driverLicense;
    int age;
    vector<string> creditCards;

public:
    Customer(string name, string address, string license, int age) : name(name), address(address), driverLicense(license), age(age) {}

    void addCreditCard(string cardNumber)
    {
        creditCards.push_back(cardNumber);
    }

    bool isYoungAge()
    {
        return age <= 25;
    }

    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    string getDriverLicense()
    {
        return driverLicense;
    }
    int getAge()
    {
        return age;
    }
    vector<string> getCreditCards()
    {
        return creditCards;
    }
};

class Contract
{
private:
    Customer customer;
    Vehicle *rentedVehicle;
    string startDate;
    string endDate;
    double rentalRate;
    double youngAgeFee;

public:
    Contract(Customer cust, Vehicle *vehicle, string start, string end, double rate) : customer(cust), rentedVehicle(vehicle), startDate(start), endDate(end), rentalRate(rate)
    {
        if (customer.isYoungAge())
        {
            youngAgeFee = 18.0;
            rentalRate += youngAgeFee;
        }
        else
        {
            youngAgeFee = 0.0;
        }
    }

    Customer getCustomer()
    {
        return customer;
    }
    Vehicle *getRentedVehicle()
    {
        return rentedVehicle;
    }
    string getStartDate()
    {
        return startDate;
    }
    string getEndDate()
    {
        return endDate;
    }
    double getRentalRate()
    {
        return rentalRate;
    }
    double getYoungAgeFee()
    {
        return youngAgeFee;
    }
};

class Reservation
{
private:
    string startDate;
    string endDate;
    string requestedVehicleType;
    double quotedRate;
    bool vehicleAvailable;
    Vehicle *assignedVehicle;

public:
    Reservation(string start, string end, string type, double rate) : startDate(start), endDate(end), requestedVehicleType(type), quotedRate(rate), vehicleAvailable(false), assignedVehicle(nullptr) {}

    void checkVehicleAvailability(vector<Vehicle *> inventory)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i]->getMake() == requestedVehicleType)
            {
                vehicleAvailable = true;
                assignedVehicle = inventory[i];

                break;
            }
        }
    }

    void handleSubstitution(vector<Vehicle *> inventory)
    {
        if (!vehicleAvailable)
        {
            cout << "Requested vehicle type is unavailable. We're substituting with a different vehicle" << endl;
        }
    }

    string getStartDate()
    {
        return startDate;
    }
    string getEndDate()
    {
        return endDate;
    }
    string getRequestedVehicleType()
    {
        return requestedVehicleType;
    }
    double getQuotedRate()
    {
        return quotedRate;
    }
    bool isVehicleAvailable()
    {
        return vehicleAvailable;
    }
    Vehicle *getAssignedVehicle()
    {
        return assignedVehicle;
    }
};

int main()
{
    string now = "28-04-2024";
    string oneWeekLater = "05-05-2024";

    CompactCar compact("Peugeot", "208", 2022, 10000.0, "ABC123");
    StandardCar standard("Honda", "Civic", 2021, 8000.0, "DEF456");
    LuxuryCar luxury("Mercedes", "S-Class", 2023, 5000.0, "GHI789");

    Customer customer("Haider Murtaza", "A-10, Sector A-1, Steel Town", "ABC123", 30);
    customer.addCreditCard("1234-5678-9012-3456");

    cout << "Customer Name: " << customer.getName() << endl;
    cout << "Customer Address: " << customer.getAddress() << endl;
    cout << "Customer Driver's License: " << customer.getDriverLicense() << endl;
    cout << "Customer Age: " << customer.getAge() << endl;
    cout << "Customer Credit Cards: ";

    vector<string> creditCards = customer.getCreditCards();
    for (int i = 0; i < creditCards.size(); i++)
    {
        cout << creditCards[i] << " ";
    }

    cout << endl
         << endl;

    cout << "Vehicle Make: " << compact.getMake() << endl;
    cout << "Vehicle Model: " << compact.getModel() << endl;
    cout << "Vehicle Year: " << compact.getYear() << endl;
    cout << "Vehicle Odometer: " << compact.getOdometer() << endl;
    cout << "Vehicle VIN: " << compact.getVIN() << endl
         << endl;

    Contract rentalContract(customer, &compact, now, oneWeekLater, 75.0);

    cout << "Rental Start Date: " << rentalContract.getStartDate() << endl;
    cout << "Rental End Date: " << rentalContract.getEndDate() << endl;
    cout << "Rental Rate: " << rentalContract.getRentalRate() << endl;
    cout << "Young Age Fee: " << rentalContract.getYoungAgeFee() << endl
         << endl;

    Reservation rentalReservation(now, oneWeekLater, "Standard Car", 70.0);
    rentalReservation.checkVehicleAvailability({&compact, &standard, &luxury});
    cout << "Requested Vehicle Type: " << rentalReservation.getRequestedVehicleType() << endl;
    cout << "Quoted Rental Rate: " << rentalReservation.getQuotedRate() << endl;

    if (rentalReservation.isVehicleAvailable())
    {
        cout << "Vehicle Availability: Available" << endl;
    }
    else
    {
        cout << "Vehicle Availability: Not Available" << endl;
    }

    if (rentalReservation.isVehicleAvailable())
    {
        cout << "Assigned Vehicle Make: " << rentalReservation.getAssignedVehicle()->getMake() << endl;
    }
    else
    {
        rentalReservation.handleSubstitution({&compact, &standard, &luxury});
    }

    return 0;
}
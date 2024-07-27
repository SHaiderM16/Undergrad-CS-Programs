#include <iostream>

using namespace std;

class Flight
{
private:
    string **schedule; // 2D array
    int rows;          // Each Row = Flight Number
    int columns;       /* First column will represent the date of departure
                        Second column will represent departure point
                        Third column will represent the destination point
                        Fourth column will represent how many economy seats are available
                        Fifth column will show how many business seats are available */

public:
    Flight(int r, int c) : rows(r), columns(c)
    {
        schedule = new string *[rows];
        for (int i = 0; i < rows; i++)
        {
            schedule[i] = new string[columns];
        }
    }

    ~Flight()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] schedule[i];
        }
        delete[] schedule;
    }

    void setSchedule(string &flightNumber, string &date, string &departure, string &destination, string &economySeats, string &businessSeats, int index)
    {
        schedule[index][0] = flightNumber;
        schedule[index][1] = date;
        schedule[index][2] = departure;
        schedule[index][3] = destination;
        schedule[index][4] = economySeats;
        schedule[index][5] = businessSeats;
    }

    void displaySchedule()
    {
        cout << "Flight Schedule:" << endl;
        cout << "Flight No.\tDate\t\t\tDeparture\tDestination\tEconomy Seats\tBusiness Seats" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << schedule[i][j] << "\t\t";
            }
            cout << endl;
        }
    }

    bool checkAvailability(int flightNumber, string date, string departure, string destination, int requiredEconomySeats, int requiredBusinessSeats)
    {
        for (int i = 0; i < rows; i++)
        {
            if (schedule[i][0] == to_string(flightNumber) && schedule[i][1] == date && schedule[i][2] == departure && schedule[i][3] == destination)
            {
                int availableEconomySeats = stringToInt(schedule[i][4]);
                int availableBusinessSeats = stringToInt(schedule[i][5]);
                if (requiredEconomySeats <= availableEconomySeats && requiredBusinessSeats <= availableBusinessSeats)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }

    void updateSeats(int flightNumber, int requiredEconomySeats, int requiredBusinessSeats)
    {
        for (int i = 0; i < rows; i++)
        {
            if (schedule[i][0] == to_string(flightNumber))
            {
                int availableEconomySeats = stringToInt(schedule[i][4]);
                int availableBusinessSeats = stringToInt(schedule[i][5]);
                schedule[i][4] = intToString(availableEconomySeats - requiredEconomySeats);
                schedule[i][5] = intToString(availableBusinessSeats - requiredBusinessSeats);
                break;
            }
        }
    }

private:
    int stringToInt(const string &str)
    {
        int num = 0;
        for (char c : str)
        {
            num = num * 10 + (c - '0');
        }
        return num;
    }

    string intToString(int num)
    {
        string result;
        while (num > 0)
        {
            result = char('0' + num % 10) + result;
            num /= 10;
        }
        return result;
    }
};

class Reservation
{
private:
    string clientName;
    string passportNumber;
    string dateOfDeparture;
    string departurePoint;
    string destinationPoint;
    string seatType;

public:
    Reservation(string n, string pn, string d, string dep, string dest, string s) : clientName(n), passportNumber(pn), dateOfDeparture(d), departurePoint(dep), destinationPoint(dest), seatType(s) {}

    void makeReservation(Flight &flight)
    {
        int flightNumber;
        cout << endl
             << "Enter Flight Number: ";
        cin >> flightNumber;

        int requiredEconomySeats, requiredBusinessSeats;
        cout << "Enter number of economy seats required: ";
        cin >> requiredEconomySeats;
        cout << "Enter number of business seats required: ";
        cin >> requiredBusinessSeats;

        if (flight.checkAvailability(flightNumber, dateOfDeparture, departurePoint, destinationPoint, requiredEconomySeats, requiredBusinessSeats))
        {
            cout << "Reservation confirmed!" << endl;
            cout << "Flight Number: " << flightNumber << endl;
            cout << "Departure Time: " << flightNumber << endl;
            cout << "Departure: " << departurePoint << endl;
            cout << "Destination: " << destinationPoint << endl;

            flight.updateSeats(flightNumber, requiredEconomySeats, requiredBusinessSeats);
        }
        else
        {
            cout << "Seat(s) not available for flight " << flightNumber << ". Do you want to make a tentative reservation? Select 'Y' or 'N': ";

            char userChoice;
            cin >> userChoice;
            if (userChoice == 'Y' || userChoice == 'y')
            {
                tentativeReservation(flightNumber);
            }
        }
    }

    void tentativeReservation(int flightNumber)
    {
        cout << endl
             << "Tentative reservation made for Flight Number " << flightNumber << " on " << dateOfDeparture << endl;
    }

    void displayReservation()
    {
        cout << endl
             << "Passenger Name: " << clientName << endl;
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Your reservation is made in respective flight number." << endl;
    }
};

int main()
{
    int numFlights = 5;
    int numColumns = 6;

    string flightSchedule[numFlights][numColumns] = {{"123", "06-03-2024", "Karachi", "Lahore", "100", "50"},
                                                     {"456", "07-03-2024", "Quetta", "Malir", "80", "40"},
                                                     {"789", "08-03-2024", "Multan", "Thar", "120", "60"},
                                                     {"101", "09-03-2024", "Johar", "Gulshan", "150", "70"},
                                                     {"202", "10-03-2024", "Pindi", "Thatta", "90", "30"}};

    Flight flights(numFlights, numColumns);

    for (int i = 0; i < numFlights; i++)
    {
        flights.setSchedule(flightSchedule[i][0], flightSchedule[i][1], flightSchedule[i][2], flightSchedule[i][3], flightSchedule[i][4], flightSchedule[i][5], i);
    }

    flights.displaySchedule();

    Reservation reservation("Haider", "AB1234567", "07-03-2024", "Quetta", "Peshawar", "Economy");
    reservation.makeReservation(flights);
    reservation.displayReservation();

    return 0;
}
#include <iostream>

using namespace std;

class Employee
{
private:
    int salary;
    int hoursWorked;

public:
    Employee(int hw) : salary(40000), hoursWorked(hw) {}

    int getSalary()
    {
        return salary;
    }
    void setSalary(int s)
    {
        salary = s;
    }

    int getHoursWorked()
    {
        return hoursWorked;
    }
    void setHoursWorked(int hw)
    {
        hoursWorked = hw;
    }

    void calculateSalary()
    {
        salary += (hoursWorked * 12 * 1500); // For entire year; hoursWorked contant for each month assumption
    }
};

class LegalSecretary : public Employee
{
private:
public:
    LegalSecretary(int hw) : Employee(hw) {} // attributes of child class (Legal Secretary) are initialised within curly braces/place comma after initialising parent class

    void prepareLegalDocument()
    {
        cout << "Legal Secretary is preparing legal document" << endl;
    }

    void extraPayLegalSecretary()
    {
        setSalary(getSalary() + 5000);
    }
};

class Marketer : public Employee
{
private:
public:
    Marketer(int hw) : Employee(hw) {}

    void advertise()
    {
        cout << "Marketer is advertising" << endl;
    }

    void extraPayMarketer()
    {
        setSalary(getSalary() + 10000);
    }
};

class Secretary : public Employee
{
private:
public:
    Secretary(int hw) : Employee(hw) {}

    void takeDictation()
    {
        cout << "Secretary is taking dictation" << endl;
    }

    int leaves_encashment(int leaves)
    {
        setSalary(getSalary() + ((10 - leaves) * 500)); // Excluding Sat/Sun
        return (10 - leaves) * 500;
    }
};

class Lawyer : public Employee
{
private:
public:
    Lawyer(int hw) : Employee(hw) {}

    void sue()
    {
        cout << "Lawyer is sueing" << endl;
    }
};

int main()
{
    Lawyer l1(20);
    Marketer m1(30);
    Secretary s1(40);
    LegalSecretary ls1(50);

    cout << "Unique behaviours:" << endl;
    l1.sue();
    m1.advertise();
    s1.takeDictation();
    ls1.prepareLegalDocument();

    cout << endl
         << "Before extra pay, Legal Secretary's salary: $" << ls1.getSalary() << endl;
    ls1.extraPayLegalSecretary();
    cout << "After extra pay, Legal Secretary's salary: $" << ls1.getSalary() << endl;

    cout << endl
         << "Before extra pay, Marketer's salary: $" << m1.getSalary() << endl;
    m1.extraPayMarketer();
    cout << "After extra pay, Marketer's salary: $" << m1.getSalary() << endl;

    char userChoice;
    int totalLeaves;

    cout << endl
         << "Does the secretary wish to take leave encashment? (Y or N): ";
    cin >> userChoice;

    if (userChoice == 'Y' || userChoice == 'y')
    {
        cout << "Enter the total number of leaves availed: ";
        cin >> totalLeaves;
        cout << "Leave Encashment: $" << s1.leaves_encashment(totalLeaves) << endl;
    }

    l1.calculateSalary();
    m1.calculateSalary();
    s1.calculateSalary();
    ls1.calculateSalary();

    cout << endl
         << "Final Salaries:" << endl;
    cout << "Lawyer's: $" << l1.getSalary() << endl;
    cout << "Marketer's: $" << m1.getSalary() << endl;
    cout << "Secretary's: $" << s1.getSalary() << endl;
    cout << "Legal Secretary's: $" << ls1.getSalary() << endl;

    return 0;
}
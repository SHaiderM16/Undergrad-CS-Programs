#include <iostream>

using namespace std;

class Pet
{
private:
    string species;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string *specialSkills;
    int numSkills;

public:
    Pet(string spec = "Unknown", string health = "Healthy", int hunger = 5, int happiness = 5) : species(spec), healthStatus(health), hungerLevel(hunger), happinessLevel(happiness), specialSkills(nullptr), numSkills(0) {}

    Pet(const Pet &sourcePet)
    {
        species = sourcePet.species;
        healthStatus = sourcePet.healthStatus;
        hungerLevel = sourcePet.hungerLevel;
        happinessLevel = sourcePet.happinessLevel;
        numSkills = sourcePet.numSkills;
        if (numSkills > 0)
        {
            specialSkills = new string[numSkills];
            for (int i = 0; i < numSkills; i++)
            {
                specialSkills[i] = sourcePet.specialSkills[i];
            }
        }
        else
        {
            specialSkills = nullptr;
        }
    }

    void updateSpecies()
    {
        string inputSpecies;
        cout << "Enter specie of pet: ";
        getline(cin, inputSpecies);
        species = inputSpecies;
    }

    void updateHappiness()
    {
        int inputHappinessLevel;
        cout << "Enter happiness level of pet (1-10): ";
        cin >> inputHappinessLevel;
        happinessLevel = inputHappinessLevel;
    }

    void updateHealth()
    {
        string inputHealthStatus;
        cout << "Enter health status of pet: ";
        cin.ignore();
        getline(cin, inputHealthStatus);
        healthStatus = inputHealthStatus;
    }

    void updateHunger()
    {
        int inputHungerLevel;
        cout << "Enter hunger level of pet (1-10): ";
        cin >> inputHungerLevel;

        hungerLevel = inputHungerLevel;

        char feedingConfirmation;
        cout << "Has the pet been fed? (Y/N): ";
        cin >> feedingConfirmation;
        if ((feedingConfirmation == 'Y' || feedingConfirmation == 'y') && hungerLevel != 10)
        {
            happinessLevel++;
        }
    }

    void addSpecialSkill(const string &skill)
    {
        string *temp = new string[numSkills + 1];

        for (int i = 0; i < numSkills; i++)
        {
            temp[i] = specialSkills[i];
        }

        temp[numSkills] = skill;

        numSkills++;

        delete[] specialSkills;
        specialSkills = temp;
    }

    void displayPetDetails()
    {
        cout << "Specie: " << species << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Special Skills:" << endl;
        for (int i = 0; i < numSkills; i++)
        {
            cout << "Skill " << i + 1 << ": " << specialSkills[i] << endl;
        }
    }

    ~Pet()
    {
        delete[] specialSkills;
    }
};

class Adopter
{
private:
    string adopterName;
    string adopterMobileNum;
    Pet *adoptedPetRecords;
    int numAdoptedPets;

public:
    Adopter(string name, string mobileNum) : adopterName(name), adopterMobileNum(mobileNum), adoptedPetRecords(nullptr), numAdoptedPets(0) {}

    void adoptPet(const Pet &pet)
    {
        Pet *temp = new Pet[numAdoptedPets + 1];
        for (int i = 0; i < numAdoptedPets; i++)
        {
            temp[i] = adoptedPetRecords[i];
        }
        temp[numAdoptedPets] = pet;
        delete[] adoptedPetRecords;
        adoptedPetRecords = temp;
        numAdoptedPets++;
    }

    void returnPet(const Pet &pet)
    {
        int index = -1;
        for (int i = 0; i < numAdoptedPets; i++)
        {
            if (&adoptedPetRecords[i] == &pet)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            for (int i = index; i < numAdoptedPets - 1; i++)
            {
                adoptedPetRecords[i] = adoptedPetRecords[i + 1];
            }
            numAdoptedPets--;
        }
        else
        {
            cout << "The pet not found in adopted pets records!" << endl;
        }
    }

    void displayAdoptedPets()
    {
        cout << "Adopted Pets by " << adopterName << " (" << adopterMobileNum << "):" << endl;
        for (int i = 0; i < numAdoptedPets; i++)
        {
            cout << "Pet " << i + 1 << ":" << endl;
            adoptedPetRecords[i].displayPetDetails();
            cout << "--------------------------" << endl;
        }
    }

    ~Adopter()
    {
        delete[] adoptedPetRecords;
    }
};

int main()
{
    Pet pet1;
    cout << "Pet 1 Information:" << endl;
    pet1.updateSpecies();
    pet1.updateHappiness();
    pet1.updateHealth();
    pet1.updateHunger();
    pet1.addSpecialSkill("Running");
    pet1.addSpecialSkill("Guarding");

    Pet pet2;
    cout << endl
         << "Pet 2 Information:" << endl;
    cin.ignore();
    pet2.updateSpecies();
    pet2.updateHappiness();
    pet2.updateHealth();
    pet2.updateHunger();
    pet2.addSpecialSkill("Understanding sign language");
    pet2.addSpecialSkill("Athletic");

    cout << endl;
    Adopter adopter1("Ali", "1234567890");
    adopter1.adoptPet(pet1);
    adopter1.adoptPet(pet2);

    adopter1.displayAdoptedPets();

    return 0;
}
#include <iostream>

using namespace std;

class Product
{
private:
    long long int barcode;
    string name;

public:
    Product(long long int b = 0, string n = "") : barcode(b), name(n) {}

    void setCode(long long int b)
    {
        barcode = b;
    }
    long long int getCode()
    {
        return barcode;
    }

    void scanner()
    {
        cout << endl
             << "Enter barcode: ";
        cin >> barcode;
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);
    }

    void printer()
    {
        cout << "Barcode: " << barcode << endl;
        cout << "Name: " << name << endl;
    }
};

class PrepackedFood : public Product
{
private:
    float unitPrice;

public:
    PrepackedFood(long long int b = 0, string n = "", float up = 0.0) : Product(b, n)
    {
        unitPrice = up;
    }

    void setUnitPrice(float up)
    {
        unitPrice = up;
    }
    float getUnitPrice()
    {
        return unitPrice;
    }

    void scanner()
    {
        Product ::scanner();
        cout << "Enter unit price: ";
        cin >> unitPrice;
    }

    void printer()
    {
        Product ::printer();
        cout << "Unit price: PKR" << unitPrice << endl;
        cout << "Price: PKR" << unitPrice << endl;
    }
};

class FreshFood : public Product
{
private:
    float weight;
    float pricePerKilo;

public:
    FreshFood(long long int b = 0, string n = "", float w = 0.0, float ppk = 0.0) : Product(b, n)
    {
        weight = w;
        pricePerKilo = ppk;
    }

    void setWeight(float w)
    {
        weight = w;
    }
    float getWeight()
    {
        return weight;
    }

    void setPricePerKilo(float ppk)
    {
        pricePerKilo = ppk;
    }
    float getPricePerKilo()
    {
        return pricePerKilo;
    }

    void scanner()
    {
        Product ::scanner();

        cout << "Enter Weight: ";
        cin >> weight;

        cout << "Enter Price per Kilo: ";
        cin >> pricePerKilo;
    }

    void printer()
    {
        Product ::printer();
        cout << "Weight: " << weight << endl;
        cout << "Price per Kilo: PKR" << pricePerKilo << endl;
        cout << "Price: PKR" << weight * pricePerKilo << endl;
    }
};

int main()
{
    Product p1(12345678910, "TV");
    PrepackedFood pf1;
    FreshFood ff1;

    pf1.scanner();

    ff1.setCode(10987654321);
    ff1.setWeight(25.9);
    ff1.setPricePerKilo(2.5);

    cout << endl
         << "Fresh Food Barcode: " << ff1.getCode() << endl;
    cout << "Fresh Food Weight: " << ff1.getWeight() << endl;
    cout << "Fresh Food Price per Kilo: PKR" << ff1.getPricePerKilo() << endl;

    cout << endl
         << "Product Object:" << endl;
    p1.printer();

    cout << endl
         << "Prepacked Food Object:" << endl;
    pf1.printer();

    cout << endl
         << "Fresh Food Object:" << endl;
    ff1.printer();

    return 0;
}
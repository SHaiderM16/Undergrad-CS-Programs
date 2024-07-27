#include <iostream>
#include <math.h>

using namespace std;

class DessertItem
{
private:
    string name;
    float calories;

public:
    DessertItem(string n, float calo) : name(n), calories(calo) {}

    string getName()
    {
        return name;
    }

    void setCalories(float calo)
    {
        calories = calo;
    }
    float getCalories()
    {
        return calories;
    }

    virtual float getCost()
    {
        return 0.0;
    };
};

class Candy : public DessertItem
{
private:
    float weight;
    float pricePerPound;

public:
    Candy(string n, float calo, float w, float ppp) : DessertItem(n, calo), weight(w), pricePerPound(ppp) {}

    float getCost() override
    {
        return round(weight * pricePerPound * 100) / 100;
    }
};

class Cookie : public DessertItem
{
private:
    int quantity;
    float pricePerDozen;

public:
    Cookie(string n, float calo, int q, float ppd) : DessertItem(n, calo), quantity(q), pricePerDozen(ppd) {}

    float getCost() override
    {
        return round((quantity * (pricePerDozen / 12)) * 100) / 100;
    }
};

class IceCream : public DessertItem
{
private:
    float cost;

public:
    IceCream(string n, float calo, float cst) : DessertItem(n, calo)
    {
        cost = cst;
    }

    float getCost()
    {
        return cost;
    }
};

class Sundae : public IceCream
{
private:
    float toppingCost;

public:
    Sundae(string n, float calo, float cst, float tc) : IceCream(n, calo, cst)
    {
        toppingCost = tc;
    }

    float getCost()
    {
        return IceCream ::getCost() + toppingCost;
    }
};

class Checkout
{
private:
    float taxRate;
    DessertItem **desserts;
    int capacity;
    int itemCount;

public:
    Checkout(int cap = 100) : taxRate(0), capacity(cap), itemCount(0)
    {
        desserts = new DessertItem *[capacity];
    }

    ~Checkout()
    {
        for (int i = 0; i < itemCount; i++)
        {
            delete desserts[i];
        }
        delete[] desserts;
    }

    void setTaxRate(float tr)
    {
        taxRate = tr;
    }
    float getTaxRate()
    {
        return taxRate;
    }

    void enterDessertItems(DessertItem *item)
    {
        if (itemCount < capacity)
        {
            desserts[itemCount++] = item;
        }
        else
        {
            cout << "Maximum desserts count reached! Please place another order" << endl;
        }
    }

    void clearCashRegister()
    {
        for (int i = 0; i < itemCount; i++)
        {
            delete desserts[i];
            desserts[i] = nullptr;
        }
        itemCount = 0;
    }

    int getItemsQuantity()
    {
        return itemCount;
    }

    float getWithoutTaxCost()
    {
        float cost = 0;
        for (int i = 0; i < itemCount; i++)
        {
            cost += desserts[i]->getCost();
        }
        return cost;
    }

    float getTotalTax()
    {
        return round(getWithoutTaxCost() * (taxRate / 100) * 100) / 100;
    }

    string getReceipt()
    {
        string receipt = "\t     Receipt\n";
        receipt += "------------------------------------\n";

        for (int i = 0; i < itemCount; i++)
        {
            receipt += desserts[i]->getName() + ": $" + to_string(desserts[i]->getCost()) + "\n";
        }

        receipt += "\nTotal cost without tax: $" + to_string(getWithoutTaxCost()) + "\n";
        receipt += "Tax: $" + to_string(getTotalTax()) + "\n";

        receipt += "\nTotal cost with tax: $" + to_string(getWithoutTaxCost() + getTotalTax()) + "\n";

        return receipt;
    }
};

int main()
{
    Checkout c1;
    c1.setTaxRate(8.5);

    Candy candy("Fudge", 250, 2.3, 0.89);
    Cookie cookie("Chocolate Chip", 160, 4, 399);
    IceCream iceCream("Vanilla", 300, 1.05);
    Sundae sundae("Chocolate Sundae", 350, 1.05, 0.50);

    c1.enterDessertItems(&candy);
    c1.enterDessertItems(&cookie);
    c1.enterDessertItems(&iceCream);
    c1.enterDessertItems(&sundae);

    cout << c1.getReceipt();

    c1.clearCashRegister();
    cout << endl
         << endl
         << "Cash Register Cleared!" << endl;

    cout << endl
         << c1.getReceipt();

    return 0;
}
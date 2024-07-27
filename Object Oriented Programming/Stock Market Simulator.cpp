#include <iostream>

using namespace std;

class Stock
{
private:
    string symbol;
    string companyName;
    double price;
    int availableQuantity;
    int maxQuantityPerInvestor;
    int stockCategoryQuantity;

public:
    Stock(string s, string cn, double p, int aq, int mqpi, int scq) : symbol(s), companyName(cn), price(p), availableQuantity(aq), maxQuantityPerInvestor(mqpi), stockCategoryQuantity(scq) {}

    string getSymbol()
    {
        return symbol;
    }

    string getCompanyName()
    {
        return companyName;
    }

    double getPrice()
    {
        return price;
    }

    int getStockCategoryQuantity()
    {
        return stockCategoryQuantity;
    }

    bool isEligibleToBuy(int purchaseQuantity)
    {
        return purchaseQuantity <= maxQuantityPerInvestor;
    };

    void displayInfo()
    {
        cout << "Stock Information:" << endl;
        cout << "Symbol: " << symbol << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Price: " << price << endl;
        cout << "Available Quantity: " << availableQuantity << endl;
        cout << "Max Quantity per Investor: " << maxQuantityPerInvestor << endl;
        cout << "Stock Category Quantity: " << stockCategoryQuantity << endl;
    }
};

class PharmaStock : public Stock
{
public:
    PharmaStock(string s, string cn, double p, int aq, int mqpi, int scq) : Stock(s, cn, p, aq, mqpi, scq) {}

    bool isEligibleToBuy(int purchaseQuantity)
    {
        return Stock::isEligibleToBuy(purchaseQuantity) && (purchaseQuantity <= getStockCategoryQuantity());
    }
};

class TechStock : public Stock
{
public:
    TechStock(string s, string cn, double p, int aq, int mqpi, int scq) : Stock(s, cn, p, aq, mqpi, scq) {}

    bool isEligibleToBuy(int purchaseQuantity)
    {
        return Stock::isEligibleToBuy(purchaseQuantity) && (purchaseQuantity <= getStockCategoryQuantity());
    }
};

class Market
{
private:
    Stock **stocks;
    int numStocks;
    int stocksAdded;

public:
    Market(int ns) : numStocks(ns), stocksAdded(0)
    {
        stocks = new Stock *[ns];

        for (int i = 0; i < ns; i++)
        {
            stocks[i] = nullptr;
        }
    }

    void addStock(Stock *newStock)
    {
        if (stocksAdded < numStocks)
        {
            stocks[stocksAdded++] = newStock;
        }
        else
        {
            cout << "More stock cannot be added!" << endl;
        }
    }

    void tradeStocks()
    {
        int inputStockQuantity;
        string inputCompanyName;
        bool stockTraded = false;

        cout << "Enter company name whose stock are to be traded: ";
        cin >> inputCompanyName;

        cout << "Enter quantity of stock(s) to be traded: ";
        cin >> inputStockQuantity;

        for (int i = 0; i < stocksAdded; i++)
        {
            if (stocks[i]->getCompanyName() == inputCompanyName && stocks[i]->isEligibleToBuy(inputStockQuantity))
            {
                cout << endl
                     << "Stock is available" << endl;
                cout << inputStockQuantity << " shares of " << inputCompanyName << " are traded" << endl;

                stockTraded = true;
            }
        }

        if (!stockTraded)
        {
            cout << endl
                 << "Stock is unavailable or company name does not match" << endl;
        }
    }

    ~Market()
    {
        for (int i = 0; i < stocksAdded; i++)
        {
            delete stocks[i];
        }
        delete[] stocks;
    }
};

int main()
{
    Market market(2);
    PharmaStock *ps1 = new PharmaStock("b12", "Platinum", 5000.0, 10000, 500, 2000);
    TechStock *ts1 = new TechStock("a16", "Diamond", 4500.0, 8000, 400, 1800);

    ps1->displayInfo();

    cout << endl;
    ts1->displayInfo();

    market.addStock(ps1);
    market.addStock(ts1);

    cout << endl;
    market.tradeStocks();

    delete ps1;
    delete ts1;

    return 0;
}
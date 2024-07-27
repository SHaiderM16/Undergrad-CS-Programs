#include <iostream>
#include <string>

using namespace std;

class Restaurant
{
private:
    string restaurant_name;
    string location;
    string menu_list[3];
    int price_list[3];
    string valid_coupon_codes_list[3];
    static int coupons_redeemed_count;

public:
    Restaurant(string name, string loc, string menu[3], int price[3], string codes[3])
    {
        restaurant_name = name;
        location = loc;
        for (int i = 0; i < 3; i++)
        {
            menu_list[i] = menu[i];
            price_list[i] = price[i];
            valid_coupon_codes_list[i] = codes[i];
        }
    }

    void display_menu()
    {
        cout << endl
             << "\t\t   " << restaurant_name << endl;
        cout << "\tItem \t       |\tPrice" << endl;
        cout << "\t--------------------------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "\t" << menu_list[i];
            // Calculate spaces to be printed
            int spaces = 15 - menu_list[i].length();
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            cout << "|"
                 << "\t" << price_list[i] << endl;
        }
    }

    void generate_bill(int item_index)
    {
        int total = price_list[item_index];
        bool discount_applied = apply_discount(valid_coupon_codes_list[item_index], item_index);
        if (discount_applied)
        {
            total /= 2; // 50% discount set
            coupons_redeemed_count++;
        }
        cout << "Your bill for " << menu_list[item_index] << " is " << total << endl;
    }

    bool apply_discount(string coupon_code, int item_index)
    {
        for (int i = 0; i < 3; i++)
        {
            if (coupon_code == valid_coupon_codes_list[i])
            {
                cout << "You have a valid coupon for " << menu_list[item_index] << ". You get 50% discount!" << endl;
                return true;
            }
        }
        cout << "Sorry, you don't have a valid coupon for this item!" << endl;
        return false;
    }

    string get_restaurant_name()
    {
        return restaurant_name;
    }

    static int get_coupons_redeemed_count()
    {
        return coupons_redeemed_count;
    }
};

int Restaurant::coupons_redeemed_count = 0;

class BOGOCoupon
{
private:
    string coupon_code;
    string valid_from;
    string valid_until;
    string restaurant_code;

public:
    BOGOCoupon(string code, string from, string until, string rest_code)
    {
        coupon_code = code;
        valid_from = from;
        valid_until = until;
        restaurant_code = rest_code;
    }

    bool is_valid(string rest_name, string today)
    {
        if (rest_name[0] == restaurant_code[0] && rest_name[1] == restaurant_code[1])
        {
            if (today >= valid_from && today <= valid_until)
            {
                return true;
            }
        }
        return false;
    }

    string get_coupon_code()
    {
        return coupon_code;
    }
};

class User
{
private:
    string name;
    int age;
    string mobile_number;
    string coupons_list[3];
    string redeemed_coupons_list[3];
    int coupons_count;
    int redeemed_count;

public:
    User(string n, int a, string m)
    {
        name = n;
        age = a;
        mobile_number = m;
        coupons_count = 0;
        redeemed_count = 0;
    }

    void accumulate_coupon(string coupon_name)
    {
        coupons_list[coupons_count] = coupon_name;
        coupons_count++;
    }

    bool has_valid_coupon(string rest_name, string today)
    {
        for (int i = 0; i < coupons_count; i++)
        {
            BOGOCoupon coupon(coupons_list[i], "01-01-2024", "31-12-2024", rest_name.substr(0, 2)); // substr(startingLetter, extractionLength) used to obtain restaurant_code
            if (coupon.is_valid(rest_name, today))
            {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string rest_name, string today, int item_index)
    {
        for (int i = 0; i < coupons_count; i++)
        {
            BOGOCoupon coupon(coupons_list[i], "01-01-2024", "31-12-2024", rest_name.substr(0, 2));
            if (coupon.is_valid(rest_name, today))
            {
                redeemed_coupons_list[redeemed_count] = coupon.get_coupon_code();
                redeemed_count++;
                return true;
            }
        }
        return false;
    }

    void display_coupons()
    {
        cout << "You have " << coupons_count << " coupons:" << endl;
        for (int i = 0; i < coupons_count; i++)
        {
            cout << coupons_list[i] << endl;
        }
    }

    void display_redeemed_coupons()
    {
        cout << "You have redeemed " << redeemed_count << " coupons:" << endl;
        for (int i = 0; i < redeemed_count; i++)
        {
            cout << redeemed_coupons_list[i] << endl;
        }
    }
};

int main()
{
    string food_haven_menu[3] = {"Sushi", "Pad Thai", "Mango Tango"};
    int food_haven_price[3] = {500, 400, 300};
    string food_haven_codes[3] = {"FH-BOGO-12345", "FH-BOGO-23456", "FH-BOGO-34567"};
    Restaurant food_haven("Food Haven", "City Center", food_haven_menu, food_haven_price, food_haven_codes);

    string pixel_bites_menu[3] = {"Binary Burger", "Quantum Quinoa", "Data Donuts"};
    int pixel_bites_price[3] = {200, 150, 100};
    string pixel_bites_codes[3] = {"PB-BOGO-67890", "PB-BOGO-78901", "PB-BOGO-89012"};
    Restaurant pixel_bites("Pixel Bites", "Cyber Street", pixel_bites_menu, pixel_bites_price, pixel_bites_codes);

    User user("Ali", 25, "03001234567");

    food_haven.display_menu();
    pixel_bites.display_menu();

    user.accumulate_coupon("FH-BOGO-12345");
    user.accumulate_coupon("PB-BOGO-67890");
    user.accumulate_coupon("FH-BOGO-23456");

    cout << endl;
    user.display_coupons();

    string today = "25-02-2024";

    cout << endl;
    if (user.has_valid_coupon(food_haven.get_restaurant_name(), today))
    {
        if (user.redeem_coupon(food_haven.get_restaurant_name(), today, 0))
        {
            food_haven.generate_bill(0);
        }
    }
    if (user.has_valid_coupon(pixel_bites.get_restaurant_name(), today))
    {
        if (user.redeem_coupon(pixel_bites.get_restaurant_name(), today, 1))
        {
            pixel_bites.generate_bill(1);
        }
    }

    cout << endl;
    user.display_redeemed_coupons();

    return 0;
}
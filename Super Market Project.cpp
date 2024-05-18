#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <iostream>

using namespace std;

class supermarket
{

    fstream products;
    int productPrice{ 0 };
    int productQuantity;
    string productName;

public:

    supermarket():productPrice(0), productQuantity(0), productName("none") {};

    void setter() {

        system("cls");

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Product Price: ";
        cin >> productPrice;

        cout << "Enter Product Quantity: ";
        cin >> productQuantity;
        
    }

    void add_product() {
        
        string w;
        cin.ignore();
        int flage = 0;

        products.open("Products_Names.txt", ios:: in);
        
        while (products >> w) {
            if (w == productName)
            {
                flage++;
                break;
            }
        }

        products.close();

        if (flage != 0)
        {
            cout << "\nProduct already exists.\n";
            system("pause");
        }
        else
        {
            products.open("Products_Names.txt", ios::out | ios::app);

            products << productName << setw(18 - productName.size()) << productPrice << "\t\t" << productQuantity << "\n";

            products.close();
        }
    }

    void display_products() {

            system("cls");
            products.open("Products_Names.txt", ios::in | ios::binary);

            cout << "Product Name" << "\t" << "Product Price" << "\t" << "Product Quantity" << "\n";
            cout << products.rdbuf();

            products.close();
            cout << "\n";

            system("pause");

        
    }

    void check_product(string check_name) {

        products.open("Products_Names.txt", ios::in);

        string name;
        cin.ignore();
        int count = 0;
        int price;
        int quantity;


        while (products >> name >> price >> quantity)
        {
            if (name == check_name)
            {
                count++;
                cout << name << "\t\t" << price << "\t\t" << quantity << "\n";
                system("pause");
                break;
            }
        }

        if (count == 0)
        {
            cout << "Product does not exist.\n";
            system("pause");
        }

        products.close();
    }

    void update_product(string namie)
    {
        products.open("Products_Names.txt", ios::in);

        string name[100];
        cin.ignore();
        int count = 0, i = 0;;
        int price[100];
        int quantity[100];

        while (products >> name[i] >> price[i] >> quantity[i])
        {
            i++;
        }
        products.close();

        for (int j = 0; j < i; j++)
        {
            if (namie == name[j])
            {
                count++;
                int newprice, newquantity;
                cout << "Enter new price: ";
                cin >> newprice;
                cout << "Enter new quantity: ";
                cin >> newquantity;

                price[j] = newprice;
                quantity[j] = newquantity;
                break;
            }
        }

        products.open("Products_Names.txt", ios::out);

        for (int k = 0; k < i; k++)
        {
            products << name[k] << setw(18 - name[k].size()) << price[k] << "\t\t" << quantity[k] << "\n";
        }

        
        products.close();

        if (count == 0)
        {
            cout << "Product does not exist.\n";
            system("pause");

        }
        else
        {
            cout << "Product updated successfully.\n\n";
            system("pause");
        }

    }

};

void Mainmenu() {
    system("cls");
    cout << "Welcome to Super Market Project\n";
    cout << "*-----------------------------*\n";
    cout << " 1) Add Product.\n\n";
    cout << " 2) Display Products.\n\n";
    cout << " 3) Check Product.\n\n";
    cout << " 4) Update Product.\n\n";
    cout << " 5) Exit.\n";
    cout << "*-----------------------------*\n";
}


int main()
{

    supermarket product;
    string name;
    int option = 1;

    while (option != 5 && option > 0 && option < 6)
    {
        Mainmenu();
        
        cout << "choose your option: ";
        cin >> option;
        cout << "\n";

        switch (option)
        {
        case 1: {
                product.setter();
                product.add_product();
        }
              break;

        case 2:
        {
            product.display_products();
        }
            break;

        case 3: {
            cout << "Enter product name to check: ";
            cin >> name;
            product.check_product(name);
        };
              break;

        case 4: {
            cout << "Enter product name to update: ";
            cin >> name;
            product.update_product(name);

        }
              break;

        case 5: cout << "See You SoOn!...:)\n";
            break;

        default: break;
        }
    }

    return 0;
}
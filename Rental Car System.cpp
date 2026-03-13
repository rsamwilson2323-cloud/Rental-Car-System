#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Car {
public:
    int id;
    string name;
    string company;
    double rate;
    int sales;
    int rentals;

    Car() {
        sales = 0;
        rentals = 0;
        rate = 0;
    }

    void input() {
        cout << "Enter Car ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Car Name: ";
        getline(cin, name);

        cout << "Enter Company: ";
        getline(cin, company);

        cout << "Enter Rate: ";
        cin >> rate;

        sales = 0;
        rentals = 0;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nCar Name: " << name;
        cout << "\nCompany: " << company;
        cout << "\nRate: " << rate;
        cout << "\nSales: " << sales;
        cout << "\nRentals: " << rentals;
        cout << "\n---------------------------\n";
    }

    string saveFormat() {
        stringstream ss;
        ss << id << "|" << name << "|" << company << "|"
           << rate << "|" << sales << "|" << rentals;
        return ss.str();
    }

    static Car loadFormat(string line) {

        Car c;
        string temp;
        stringstream ss(line);

        getline(ss, temp, '|');
        c.id = atoi(temp.c_str());

        getline(ss, c.name, '|');
        getline(ss, c.company, '|');

        getline(ss, temp, '|');
        c.rate = atof(temp.c_str());

        getline(ss, temp, '|');
        c.sales = atoi(temp.c_str());

        getline(ss, temp, '|');
        c.rentals = atoi(temp.c_str());

        return c;
    }
};

class CarShop {

    vector<Car> cars;

public:

    void load() {

        cars.clear();
        ifstream file("cars.txt");
        string line;

        while (getline(file, line)) {
            if (!line.empty())
                cars.push_back(Car::loadFormat(line));
        }

        file.close();
    }

    void save() {

        ofstream file("cars.txt");

        for (int i = 0; i < cars.size(); i++) {
            file << cars[i].saveFormat() << endl;
        }

        file.close();
    }

    void addCar() {

        Car c;
        c.input();
        cars.push_back(c);
        save();

        cout << "\nCar Added Successfully!\n";
    }

    void showCars() {

        if (cars.empty()) {
            cout << "\nNo Cars Available!\n";
            return;
        }

        cout << "\n=========== CAR LIST ===========\n";

        for (int i = 0; i < cars.size(); i++) {
            cars[i].display();
        }
    }

    int searchMenu() {

        cout << "\nSearch By:\n";
        cout << "1. ID\n";
        cout << "2. Name\n";
        cout << "3. Company\n";
        cout << "Enter Choice: ";

        int ch;
        cin >> ch;
        cin.ignore();

        return ch;
    }

    int searchCar() {

        int option = searchMenu();

        if (option == 1) {

            int id;
            cout << "Enter ID: ";
            cin >> id;

            for (int i = 0; i < cars.size(); i++)
                if (cars[i].id == id)
                    return i;
        }

        else if (option == 2) {

            string name;
            cout << "Enter Name: ";
            getline(cin, name);

            for (int i = 0; i < cars.size(); i++)
                if (cars[i].name == name)
                    return i;
        }

        else if (option == 3) {

            string company;
            cout << "Enter Company: ";
            getline(cin, company);

            for (int i = 0; i < cars.size(); i++)
                if (cars[i].company == company)
                    return i;
        }

        return -1;
    }

    void recordRental(int index, string action) {

        ofstream file("rental_history.txt", ios::app);

        string date;
        cout << "Enter Date (DD.MM.YYYY): ";
        cin >> date;

        file << cars[index].id << "|"
             << cars[index].name << "|"
             << cars[index].company << "|"
             << date << "|" << action << endl;

        file.close();
    }

    void salesRent() {

        char choice;

        cout << "\n========== BILL ==========\n";

        do {

            int index = searchCar();

            if (index == -1) {
                cout << "Car Not Found!\n";
            }

            else {

                int type;

                cout << "\n1. Sale\n";
                cout << "2. Rent\n";
                cout << "Choose Option: ";
                cin >> type;

                if (type == 1) {

                    cars[index].sales++;

                    cout << "\nCar Sold Successfully!\n";
                    cout << "Car: " << cars[index].name << endl;
                    cout << "Amount: " << cars[index].rate << endl;
                }

                else if (type == 2) {

                    cars[index].rentals++;

                    cout << "\nCar Rented Successfully!\n";
                    cout << "Car: " << cars[index].name << endl;
                    cout << "Rent Price: " << cars[index].rate << endl;

                    recordRental(index, "rent");
                }

                else {
                    cout << "Invalid Option\n";
                }

                save();
            }

            cout << "\nAdd More Cars? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\n==========================\n";
    }

    void returnCar() {

        int index = searchCar();

        if (index == -1) {
            cout << "Car Not Found!\n";
            return;
        }

        cout << "\nReturning Car: " << cars[index].name << endl;

        recordRental(index, "return");

        cout << "Car Returned Successfully!\n";
    }

    void menu() {

        load();

        int choice;

        do {

            cout << "\n====================================\n";
            cout << "      CAR SHOP MANAGEMENT SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Add Car (New)\n";
            cout << "2. Show All Cars\n";
            cout << "3. Search Car\n";
            cout << "4. Sales / Rent\n";
            cout << "5. Return Car\n";
            cout << "6. Exit\n";
            cout << "Enter Choice: ";

            cin >> choice;

            switch (choice) {

                case 1:
                    addCar();
                    break;

                case 2:
                    showCars();
                    break;

                case 3: {

                    int index = searchCar();

                    if (index == -1)
                        cout << "Car Not Found!\n";
                    else
                        cars[index].display();

                    break;
                }

                case 4:
                    salesRent();
                    break;

                case 5:
                    returnCar();
                    break;

                case 6:
                    cout << "\nThank You!\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
            }

        } while (choice != 6);
    }
};

int main() {

    CarShop shop;
    shop.menu();

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // Stock for food items and rooms
    int stockRooms = 10, stockPasta = 50, stockBurger = 50, stockPizza = 40, stockDrinks = 100;
    // Sold items
    int soldRooms = 0, soldPasta = 0, soldBurger = 0, soldPizza = 0, soldDrinks = 0;
    // Total money
    int totalRooms = 0, totalPasta = 0, totalBurger = 0, totalPizza = 0, totalDrinks = 0;

    int choice, qty;

    cout << "\n\n\t Welcome to Hotel Management System (C++ Project)";
    do {
        cout << "\n\n================== MENU ==================";
        cout << "\n1. Rooms";
        cout << "\n2. Pasta";
        cout << "\n3. Burger";
        cout << "\n4. Pizza";
        cout << "\n5. Cold Drinks";
        cout << "\n6. Show Sales and Collection";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter number of Rooms you want: ";
            cin >> qty;
            if (stockRooms - soldRooms >= qty) {
                soldRooms += qty;
                totalRooms += qty * 1200; // price of one room
                cout << qty << " Room(s) have been allotted to you!";
            } else {
                cout << "\nOnly " << stockRooms - soldRooms << " Rooms remaining in hotel!";
            }
            break;

        case 2:
            cout << "\nEnter Pasta Quantity: ";
            cin >> qty;
            if (stockPasta - soldPasta >= qty) {
                soldPasta += qty;
                totalPasta += qty * 150; // price per pasta
                cout << qty << " Pasta ordered successfully!";
            } else {
                cout << "\nOnly " << stockPasta - soldPasta << " Pasta remaining!";
            }
            break;

        case 3:
            cout << "\nEnter Burger Quantity: ";
            cin >> qty;
            if (stockBurger - soldBurger >= qty) {
                soldBurger += qty;
                totalBurger += qty * 100;
                cout << qty << " Burger(s) ordered successfully!";
            } else {
                cout << "\nOnly " << stockBurger - soldBurger << " Burgers remaining!";
            }
            break;

        case 4:
            cout << "\nEnter Pizza Quantity: ";
            cin >> qty;
            if (stockPizza - soldPizza >= qty) {
                soldPizza += qty;
                totalPizza += qty * 250;
                cout << qty << " Pizza(s) ordered successfully!";
            } else {
                cout << "\nOnly " << stockPizza - soldPizza << " Pizza remaining!";
            }
            break;

        case 5:
            cout << "\nEnter Cold Drink Quantity: ";
            cin >> qty;
            if (stockDrinks - soldDrinks >= qty) {
                soldDrinks += qty;
                totalDrinks += qty * 50;
                cout << qty << " Cold Drink(s) ordered successfully!";
            } else {
                cout << "\nOnly " << stockDrinks - soldDrinks << " Cold Drinks remaining!";
            }
            break;

        case 6:
            cout << "\n\n===== Daily Sales and Collection =====";
            cout << "\n Rooms booked: " << soldRooms << " | Remaining: " << stockRooms - soldRooms << " | Collection: " << totalRooms;
            cout << "\n Pasta sold: " << soldPasta << " | Remaining: " << stockPasta - soldPasta << " | Collection: " << totalPasta;
            cout << "\n Burgers sold: " << soldBurger << " | Remaining: " << stockBurger - soldBurger << " | Collection: " << totalBurger;
            cout << "\n Pizza sold: " << soldPizza << " | Remaining: " << stockPizza - soldPizza << " | Collection: " << totalPizza;
            cout << "\n Cold Drinks sold: " << soldDrinks << " | Remaining: " << stockDrinks - soldDrinks << " | Collection: " << totalDrinks;

            cout << "\n\n TOTAL COLLECTION FOR THE DAY: "
                 << totalRooms + totalPasta + totalBurger + totalPizza + totalDrinks;
            break;

        case 7:
            cout << "\nExiting... Thank you for using Hotel Management System!";
            break;

        default:
            cout << "\nInvalid Choice! Please select from the menu.";
        }

    } while (choice != 7);

    return 0;
}

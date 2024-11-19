#include <iostream>
using namespace std;

class Passenger {
private:
    char name[50];     
    int age;           
    char gender[10];   
    int ticketNumber;  

public:

    Passenger() : age(0), ticketNumber(0) {
        name[0] = '0';
        gender[0] = '0';
    }


    void setDetails(const char pname[], int page, const char pgender[], int pticketNumber) {

        int i = 0;
        while (pname[i] != '0' && i < 50) {
            name[i] = pname[i];
            i++;
        }
        name[i] = '0'; 


        i = 0;
        while (pgender[i] != '0' && i < 10) {
            gender[i] = pgender[i];
            i++;
        }
        gender[i] = 'g'; 

        age = page;
        ticketNumber = pticketNumber;
    }


    int getTicketNumber() const {
        return ticketNumber;
    }

    void display() const {
        cout << "Ticket Number: " << ticketNumber
             << ", Name: " << name
             << ", Age: " << age
             << ", Gender: " << gender << endl;
    }
};

class TicketReservationSystem {
private:
    Passenger passengers[100]; 
    int passengerCount;         

public:

    TicketReservationSystem() : passengerCount(0) {}


    void addPassenger(const char pname[], int page, const char pgender[], int pticketNumber) {
        if (passengerCount < 100) {
            passengers[passengerCount].setDetails(pname, page, pgender, pticketNumber);
            passengerCount++;
        } else {
            cout << "Maximum passenger limit reached!" << endl;
        }
    }


    void displayPassengers() const {
        if (passengerCount == 0) {
            cout << "No passengers in the system." << endl;
        } else {
            for (int i = 0; i < passengerCount; i++) {
                passengers[i].display();
            }
        }
    }


    void searchPassengerByTicketNumber(int ticketNumber) const {
        bool found = false;
        for (int i = 0; i < passengerCount; i++) {
            if (passengers[i].getTicketNumber() == ticketNumber) {
                passengers[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Passenger with ticket number " << ticketNumber << " not found." << endl;
        }
    }
};

int main() {
    TicketReservationSystem system;


    system.addPassenger("XYZZZZZ", 30, "male", 101);
    system.addPassenger("XYZZZZ", 25, "Male", 102);
    system.addPassenger("XYZZ", 35, "FEMale", 103);


    cout << "Displaying all passengers:" << endl;
    system.displayPassengers();


    cout << "\nSearching for passenger with ticket number 102:" << endl;
    system.searchPassengerByTicketNumber(102);


  

    return 0;
}
#include<iostream>
using namespace std;

class Passenger{
private:
    string name;
    int age;
    int ticket_no;
public:
    Passenger() {

    } 
    Passenger(string name,int age,int ticket_no) {
        this->age=age;
        this->name=name;
        this->ticket_no=ticket_no;
    }
    string getName(){
     return name;
    }
    int getTicket(){
        return ticket_no; 
    } 
    
       public:
   
  virtual void displayDetails() const{ 
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"ticket_no"<<ticket_no<<endl;

    }

};
class FirstclassTicket : public Passenger{
    public:
    FirstclassTicket(string name,int age,int ticket_no):Passenger(name,age,ticket_no){

    }
     void displayDetails() const override {
        cout << "First Class Ticket:\n";
        Passenger::displayDetails();
        cout << " Perks such as Priority boarding, complimentary meals" << endl;
    }

};
class EconomyclassTicket : public Passenger{
    public:
    EconomyclassTicket(string name,int age,int ticket_no):Passenger(name,age,ticket_no){

    }
   void displayDetails() const override {
        cout << "Economy Class Ticket:\n";
        Passenger::displayDetails();
        cout << " Perks such as basic boarding,normal meals" << endl;
    }

};

    class TicketReservationSystem {
private:
    Passenger* passengers[100];
    int currentSize;

public:
    TicketReservationSystem() : currentSize(0) {
        for (int i = 0; i < 100; ++i) {
            passengers[i] = nullptr; 
        }
    }

    ~TicketReservationSystem() {
        
        for (int i = 0; i < currentSize; ++i) {
            delete passengers[i];
        }
    }

    void addPassenger(Passenger* passenger) {
        if (currentSize < 100) {
            passengers[currentSize] = passenger; // Store the pointer directly
            currentSize++;
            cout << "Passenger added successfully.\n";
        } else {
            cout << "Reservation system is full. Cannot add more passengers.\n";
        }
    }

    void searchPassengerByTicket(int ticketNumber) const {
        for (int i = 0; i < currentSize; ++i) {
            if (passengers[i]->getTicket() == ticketNumber) {
                cout << "Passenger found:\n";
                passengers[i]->displayDetails();
                return;
            }
        }
        cout << "No passenger found with Ticket Number: " << ticketNumber << "\n";
    }

    void displayAllPassengers() const {
        if (currentSize == 0) {
            cout << "No passengers in the system.\n";
            return;
        }
        cout << "Passenger List:\n";
        for (int i = 0; i < currentSize; ++i) {
            passengers[i]->displayDetails();
        }
    }
};

int main() {
    TicketReservationSystem system;
    system.addPassenger(new FirstclassTicket("GARVIT", 19, 11123));
    system.addPassenger(new EconomyclassTicket("manish", 22, 102234));

    system.displayAllPassengers();
    system.searchPassengerByTicket(1014334);
    system.searchPassengerByTicket(999343);

    return 0;
}

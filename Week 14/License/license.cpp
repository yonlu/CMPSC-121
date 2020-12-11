#include <iostream>
#include <vector>

struct Person {
    int age;
    bool license;
};

class Car {
    private:
        int seats;
        Person driver;
        std::vector<Person> passengers;
    public:
        bool setNumSeats(int);
        void setDriver(Person);
        bool addPassenger(Person);
        bool canDrive();
};

int main() {
    Car newCar;
    Person newDriver;

    int seats;
    int age;
    int hasLicense;

    do {
        std::cout << "Enter the number of seats in the car: ";
        std::cin >> seats;
    } while(!(newCar.setNumSeats(seats)));

    do {
        std::cout << "Enter the age of the driver: ";
        std::cin >> age;
        if (age < 1) {
            std::cout<< "Enter 1 or greater!" << std::endl;
        } else {
            newDriver.age = age;
        }
    } while(age < 1);

    do {
        std::cout << "Does the driver have a license? (0 for no, 1 for yes): ";
        std::cin >> hasLicense;
        if (!(hasLicense == 0 || hasLicense == 1)) {
            std::cout << "Please enter 0 for no, 1 for yes." << std::endl;
        } else {
            newDriver.license = static_cast<bool>(hasLicense);
        }
    } while(!(hasLicense == 0 || hasLicense == 1));

    newCar.setDriver(newDriver);

    if (newCar.canDrive()) {
       bool canTravel;
       int availableSeats = seats - 1;
       do {
           if (availableSeats > 0) {
               Person newPassenger;
               std::cout << "Enter a passenger's age (-1 if done): ";
               std::cin >> newPassenger.age;
               canTravel = newCar.addPassenger(newPassenger);
               availableSeats--;
           } else {
               canTravel = false;
               std::cout << "There is no more room!" << std::endl;
               std::cout << "Have a safe drive!";
           }
       } while(canTravel);
    } else {
        std::cout << "The driver is not allowed to drive!" << std::endl;
    }

    return 0;
}

bool Car::setNumSeats(int totalSeats) {
    if (totalSeats < 1) {
        std::cout << "Enter 1 or greater!" << std::endl;
        return false;
    } else {
        seats = totalSeats;
    }
    return true;
}

void Car::setDriver(Person newDriver) {
   driver = newDriver;
}

bool Car::addPassenger(Person newPassenger) {
    static int underagePassengers = 0;

    if (newPassenger.age == -1) {
        std::cout << "Have a safe drive!";
        return false;
    }

    if (driver.age >= 18) {
        passengers.push_back(newPassenger);
        return true;
    }

    if (newPassenger.age >= 18) {
        passengers.push_back(newPassenger);
        return true;
    }
    else if (newPassenger.age < 18 && underagePassengers < 1) {
        passengers.push_back(newPassenger);
        underagePassengers++;
        return true;
    } else {
        std::cout << "Too many minors!" << std::endl;
        return false;
    }
}

bool Car::canDrive() {
   if(driver.age >= 16 && driver.license == 1) {
       return true;
   } else {
       return false;
   }
}
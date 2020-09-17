#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Formatting to US currency standards.
    cout << fixed << setprecision(2);

    int hours = 0;
    char vehicleType;
    string licensePlate;
    double amountDue = 0.0;
    double overDue = 0.0;
    double total = 0.0;

    // Temporary variable to clear buffer
    string tmp;

    // Car rates
    const double CAR_FIRST_RATE = 1.25;
    const double CAR_SECOND_RATE = 1.50;

    // Truck rates
    const double TRUCK_FIRST_RATE = 2.75;
    const double TRUCK_SECOND_RATE = 3.75;

    // Bus rates
    const double BUS_FIRST_RATE = 9.50;
    const double BUS_SECOND_RATE = 6.75;

    cout << "Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): ";
    cin >> vehicleType;

    // If the Vehicle is NOT a car, or a truck, or a bus.
    if (!(vehicleType == 'C' || vehicleType == 'T' || vehicleType == 'B')) {
       cout << "This is an invalid vehicle type" << endl;
       return 1;
    }

    cout << "Enter the number of hours parked: ";
    cin >> hours;

    // Clear buffer
    getline(cin, tmp);

    cout << "What is the license plate? ";
    getline(cin, licensePlate);

    // Menu selection by vehicle type
    switch (vehicleType) {
        case 'C':
            cout << "Vehicle Type: Car" << endl;
            cout << "License Plate: " << licensePlate << endl;
            cout << "Time: " << hours << ((hours > 1) ? " hours" : " hour") << endl;

            // Second car rate applies after the first two hours, but it's not retrospective
            if (hours > 2) {
                amountDue = 2 * CAR_FIRST_RATE;
                overDue = (hours - 2) * CAR_SECOND_RATE;

                total = amountDue + overDue;
            } else {
                total = hours * CAR_FIRST_RATE;
            }

            cout << "Amount Due: $" << total << endl;

            break;

        case 'T':
            cout << "Vehicle Type: Truck" << endl;
            cout << "License Plate: " << licensePlate << endl;
            cout << "Time: " << hours << ((hours > 1) ? " hours" : " hour") << endl;

            // Second truck rate applies after the first two hours, but it's not retrospective
            if (hours > 2) {
                amountDue = 2 * TRUCK_FIRST_RATE;
                overDue = (hours - 2) * TRUCK_SECOND_RATE;

                total = amountDue + overDue;
            } else {
                total = hours * TRUCK_FIRST_RATE;
            }
            cout << "Amount Due: $" << total << endl;

            break;

        case 'B':
            cout << "Vehicle Type: Bus" << endl;
            cout << "License Plate: " << licensePlate << endl;
            cout << "Time: " << hours << ((hours > 1) ? " hours" : " hour") << endl;

            // Second bus rate applies after the first hour, but it's not retrospective
            if (hours > 1) {
                amountDue = BUS_FIRST_RATE;
                overDue = (hours - 1) * BUS_SECOND_RATE;

                total = amountDue + overDue;
            } else {
                total = hours * BUS_FIRST_RATE;
            }

            cout << "Amount Due: $" << total << endl;

            break;

        default:
            cout << "This is an invalid vehicle type" << endl;
            return 1;
    }

    return 0;
}

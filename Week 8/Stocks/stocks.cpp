#include <iostream>
#include <iomanip>

using namespace std;

double getSharesPurchased(double);
double getPurchasePricePerShare(double);
double getPurchaseCommission(double);
double getSoldPricePerShare(double);
double getSaleCommission(double);

double calculateProfit(double, double, double, double, double);

int main() {
    // Quantity of shares
    double numberOfShares = 0.0; // NS

    // Purchase related
    double purchasePricePerShare = 0.0; // PP
    double purchaseCommission = 0.0; // PC

    // Sold related
    double soldPricePerShare = 0.0; // SP
    double saleCommission = 0.0; // SC

    double profit;


    // Keep looping until until you get a positive non-zero value.
    do {
        numberOfShares = getSharesPurchased(numberOfShares);
    } while(!static_cast<bool>(numberOfShares));


    do {
        purchasePricePerShare = getPurchasePricePerShare(purchasePricePerShare);
    } while (!static_cast<bool>(purchasePricePerShare));

    do {
        purchaseCommission = getPurchaseCommission(purchaseCommission);
    } while(!static_cast<bool>(purchaseCommission));

    do {
        soldPricePerShare = getSoldPricePerShare(soldPricePerShare);
    } while(!static_cast<bool>(soldPricePerShare));

    do {
        saleCommission = getSaleCommission(saleCommission);
    } while(!static_cast<bool>(saleCommission));

    profit = calculateProfit(numberOfShares, soldPricePerShare, saleCommission, purchasePricePerShare, purchaseCommission);

    cout << fixed << setprecision(2);
    cout << "The profit on the stock was $" << profit << endl;

    return 0;
}

double getSharesPurchased(double shares) {
    cout << "Enter the number of shares purchased: ";
    cin >> shares;

    if (shares > 0.0) {
        return shares;
    } else {
        cout << "Please enter a non-zero positive value!" << endl;
        return 0;
    }
}

double getPurchasePricePerShare(double pricePerShare) {
    cout << "Enter the purchase price: ";
    cin >> pricePerShare;

    if (pricePerShare > 0.0) {
        return pricePerShare;
    } else {
        cout << "Please enter a non-zero positive value!" << endl;
        return 0;
    }
}

double getPurchaseCommission(double purchaseCommission) {
    cout << "Enter the purchase commission: ";
    cin >> purchaseCommission;

    if (purchaseCommission > 0.0) {
        return purchaseCommission;
    } else {
        cout << "Please enter a non-zero positive value!" << endl;
        return 0;
    }
}

double getSoldPricePerShare(double pricePerShare) {
    cout << "Enter the sale price: ";
    cin >> pricePerShare;

    if (pricePerShare > 0.0) {
        return pricePerShare;
    } else {
        cout << "Please enter a non-zero positive value!" << endl;
        return 0;
    }

}

double getSaleCommission(double saleCommission) {
    cout << "Enter the sale commission: ";
    cin >> saleCommission;

    if (saleCommission > 0.0) {
        return saleCommission;
    } else {
        cout << "Please enter a non-zero positive value!" << endl;
        return 0;
    }
}

/*
 * Profit = ((NS * SP) -SC) - ((NS*PP) + PC)
 */

double calculateProfit(double NS, double SP, double SC, double PP, double PC) {
    return (((NS * SP) - SC) - ((NS * PP) + PC));
}


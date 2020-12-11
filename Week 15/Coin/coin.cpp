#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <iomanip>

bool coinflip();

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Example counters
    int tails = 0;
    int heads = 0;
    bool result;

    // Game variables
    double balance = 0.0;
    double newBalance = 0.0;
    double winnings = 0.0;
    int numberOfWins = 0;
    const double GAME_COST = 5.50;

    // Loop controller
    char choice;
    char startGame;

    // RNG seeder
    unsigned seed = time(0);
    srand(seed);

    std::cout << "Welcome to the Coin Flip Game!" << std::endl;
    std::cout << "\nHere's a 100-Flip Example (T = Tails, H = Heads): ";
    for (int i = 0; i < 100; i++) {
        result = coinflip();
        if (i == 49) {
            std::cout << std::endl;
        }
        result ? tails++ : heads++;
    }
    std::cout << "\nThere were " << heads << " heads and " << tails << " tails." << std::endl;

    std::cout << "\nEach game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip." << std::endl;
    std::cout << "Your winnings will be $2^(n-2). Would you like to play a game? (Y/n) ";
    std::cin >> startGame;

    while (toupper(startGame) != 'Y' && toupper(startGame) != 'N') {
        std::cout << "\nPlease enter Y/y to start game or N/n to terminate the program: ";
        std::cin >> startGame;
    }

    if (toupper(startGame) == 'Y') {
        bool keepPlaying = false;
        do {
            std::cout << "\nGame Results: " << std::right << std::setw(11);
            do {
                keepPlaying = coinflip();
                numberOfWins++;
            } while (keepPlaying);

            winnings = pow(2, (numberOfWins - 2));
            newBalance = balance + winnings - GAME_COST;

            std::cout << "\nPrev. Balance: " << std::right << std::setw(12) << balance << std::endl;
            std::cout << "Game Cost: " << std::setw(16) <<  GAME_COST << std::endl;
            std::cout << "Winnings: " << std::setw(17) << winnings << std::endl;
            std::cout << "New Balance: " << std::setw(14) << newBalance << std::endl;

            balance = newBalance;
            numberOfWins = 0;

            std::cout << "\nWould you like to play another game for $5.50? (Y/N): ";
            std::cin >> choice;

            while (toupper(choice) != 'Y' && toupper(choice) != 'N') {
                std::cout << "\nPlease enter 'Y' or 'y' for yes;  'N' or 'n' for no: ";
                std::cin >> choice;
            }
        } while (toupper(choice) == 'Y');

        if (balance > 0) {
            std::cout << "Thanks for playing! Congratulations on your winnings of $" << balance << std::endl;
        }
        else if (balance < 0) {
           std::cout << "Thanks for playing! Sorry about your losses of $" << balance << std::endl;
        }
        else {
           std::cout << "Thanks for playing! However, you got $" << balance << std::endl;
        }
    }

    return 0;
}

bool coinflip() {
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 1;
    int coin = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    if (coin == 0) {
        std::cout << "H ";
        return false;
    } else {
        std::cout << "T ";
        return true;
    }
}





// This lab made me realize to never gamble........
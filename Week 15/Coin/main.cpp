#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

bool coinflip();

int main() {
    std::cout << std::fixed << std::setprecision(2);

    double balance = 0.0;
    int numberOfWins = 0;
    const double GAME_COST = 5.50;

    unsigned seed = time(0);
    srand(seed);

    std::cout << "Welcome to the Coin Flip Game!" << std::endl;
    std::cout << "Here's a 100-Flip Example (T = Tails, H = Heads): ";

    std::cout << "\nEach game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip." << std::endl;
    std::cout << "Your winnings will be $2^(n-2). Would you like to play a game? " << std::endl;

    bool keepPlaying = false;

    do {
       keepPlaying = coinflip();
       numberOfWins++;
    } while(keepPlaying);

    balance = pow(2, (numberOfWins - 2)) - GAME_COST;
    std::cout << "\n$" << balance << std::endl;

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

#include <iostream>

using namespace std;

bool isPrime(int);

int main() {
    for (int i = 1; i <= 100; i++) {
       if(isPrime(i)) {
           if(i == 97) { // unfortunately this line made it not optimized.
               cout << i ;
           } else {
               cout << i << ", ";
           }
       }
    }
}

/*
 * Sieve of Eratosthenes!
 *
 * When the counter hits 2, we can eliminate all multiples of 2.
 * When it hits 3, eliminate all its multiples.
 * Notice how 6 is already a multiple of 2 and therefore, already eliminated.
 * So starting eliminating multiples of 3 at the square of 3. Which is 9.
 *
 * 4 is a multiple of 2, so it's already eliminated.
 *
 * Counter hits 5, but 10 (multiple of 2) is already eliminated,
 * and so is 15 (multiple of 3) and 20 (multiple of 2).
 * Start counting at its square root (25).
 *
 * Repeat this pattern for all non-eliminated numbers.
 *
 * When you hit 11, 11 squared is already bigger than 100 (our limit).
 * Now all remaining numbers are prime.
 */
bool isPrime(int num) {
    bool isNumPrime = true;

    if (num == 1) {
        return false;
    }

    // We need to do this check outside of the loop to optimize the loop counter's update
    if (num % 2 == 0) {
        return (num == 2);
    }

    // Checking for primality up to num is not necessary
    // Instead, make the limit to be sqrt(n).
    int limit = floor(sqrt(num));

    // Update counter by two every iteration in order to not check even numbers
    // Because every even number besides 2 is not prime.
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) { // If this is true, it means we found a multiple. So num is NOT prime.
            isNumPrime = false;
            return isNumPrime;
        }
    }

    return isNumPrime;
}

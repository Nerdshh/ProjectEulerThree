/// @author Frederick Bouchard

#include <iostream>

using namespace std;

// function prototype
void sieveOfEratosthenes(bool primes[], int size);

int main() {
	
	long long value = 600851475143;	// number to find the greatest prime factor of
	int size = 775147;				// square of above number rounded up
	bool primes[size];				// array storing primes represented by indices
	bool foundLargestPrime = false;	// trigger to leave loop when greatest prime factor is found
	
	sieveOfEratosthenes(primes, size);
	
	// finds greatest prime factor of original value by iterating through the primes array in
	// reverse and testing each prime with modulo
	for(int i = size; !foundLargestPrime; i--) {
		
		if(primes[i] == true) {
			
			if(value % i == 0) {
				
				cout << i << endl;
				foundLargestPrime = true;
			}
		}
	}
	
	return 0;
}

/// ------------------------------------------------------------------------------------------
/// @brief Sets every index that is not a prime number to false in the given bool array using
///        the Sieve of Eratosthenes algorithm as shown on Wikipedia.
///        https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
/// @param primes[] boolean array where indices represent numbers
/// @param size     the length of the primes bool array.
/// ------------------------------------------------------------------------------------------

void sieveOfEratosthenes(bool primes[], int size) {
	
	int sqrtSize = 881;
	
	for(int i = 2; i <= size; i++) {
		primes[i] = true;
	}
	
	for(int i = 2; i <= sqrtSize; i++) {
		
		int counter = 0;
		
		if(primes[i] == true) {
			
			for(int j = i * i; j < size; j = i * i + counter * i) {
				primes[j] = false;
				counter++;
			}
		}
	}
}


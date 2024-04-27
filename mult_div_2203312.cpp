#include <iostream>
using namespace std;

// Recursive function to multiply two integers x and y
int multiplyIntegers(int a, int b) {
    // Base case: If b is 0, return 0
    if (b == 0) {
        return 0;
    }

    // Recursively calculate half the multiplication
    int halfProduct = multiplyIntegers(a, b / 2);

    // If b is even, double the half product
    if (b % 2 == 0) {
        return 2 * halfProduct;
    } else { // If b is odd, add a to double the half product
        return a + 2 * halfProduct;
    }
}

// Function to divide two integers x and y and store quotient in q and remainder in r
void divideIntegers(int x, int y, int &quotient, int &remainder) {
    // Base case: If x is less than y, quotient is 0 and remainder is x
    if (x < y) {
        quotient = 0;
        remainder = x;
        return;
    }

    // calculate quotient and remainder
    int qrQuotient, qrRemainder;
    divideIntegers(x / 2, y, qrQuotient, qrRemainder);

    // Double the quotient and remainder
    quotient = 2 * qrQuotient;
    remainder = 2 * qrRemainder;

    // Adjust for odd x values
    if (x % 2 != 0) {
        remainder = remainder + 1;
    }

    // If remainder being greater than or equal to y
    if (remainder >= y) {
        remainder = remainder - y;
        quotient = quotient + 1;
    }
}

int main() {
    int n1, n2;
    cout << "Enter the two integers: ";
    cin>>n1>>n2;


    // Calculate and display the product of num1 and num2
    int productResult = multiplyIntegers(n1, n2);
    cout << "Product: " << productResult << endl;

    // Calculate and display the quotient and remainder of num1 divided by num2
    int quotient, remainder;
    divideIntegers(n1, n2, quotient, remainder);
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double powerValue(double a, double b) { return pow(a, b); }

int main() {
    int choice;
    do {
        cout << "\n--- Scientific Calculator ---\n"
             << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Remainder\n"
             << "6. Power\n7. Square root\n8. Exit\nChoice: ";
        cin >> choice;

        double a, b;
        switch (choice) {
            case 1:
                cout << "Enter two numbers: "; cin >> a >> b;
                cout << "Result = " << add(a, b) << '\n'; break;
            case 2:
                cout << "Enter two numbers: "; cin >> a >> b;
                cout << "Result = " << subtract(a, b) << '\n'; break;
            case 3:
                cout << "Enter two numbers: "; cin >> a >> b;
                cout << "Result = " << multiply(a, b) << '\n'; break;
            case 4:
                cout << "Enter two numbers: "; cin >> a >> b;
                if (b == 0) cout << "Cannot divide by zero.\n";
                else cout << "Result = " << a / b << '\n';
                break;
            case 5: {
                int x, y;
                cout << "Enter two integers: "; cin >> x >> y;
                if (y == 0) cout << "Cannot divide by zero.\n";
                else cout << "Remainder = " << x % y << '\n';
                break;
            }
            case 6:
                cout << "Enter base and exponent: "; cin >> a >> b;
                cout << "Result = " << powerValue(a, b) << '\n'; break;
            case 7:
                cout << "Enter a number: "; cin >> a;
                if (a < 0) cout << "Square root requires a non-negative number.\n";
                else cout << "Result = " << sqrt(a) << '\n';
                break;
            case 8: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}

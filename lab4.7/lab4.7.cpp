#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x_s, x_e, dx, eps;
    int n = 0;

    cout << " x: ";
    cin >> x_s;
    cout << " x: ";
    cin >> x_e;
    cout << " dx: ";
    cin >> dx;
    cout << "eps: ";
    cin >> eps;

    
    cout << fixed; 
    cout << setw(12) << "x"
        << setw(20) << "e^(x^2)"
        << setw(20) << "sum"
        << setw(10) << "dodan" << endl;
    cout << string(62, '-') << endl;  

    
    for (double x = x_s; x <= x_e; x += dx) {
        double sum = 1.0;  
        double term = 1.0; // поч дод
        int n = 1;         // кількіст доданків

        // наст дод = минулий* (x^2 / n)
        while (fabs(term) > eps) {
            term *= (x * x) / n; 
            sum += term;          
            n++;                  
        }

        //exact_value- точне значення
        double exact_value = exp(x * x);

        
        cout << setw(12) << x
            << setw(20) << exact_value
            << setw(20) << sum
            << setw(10) << n << endl;
    }

    return 0;
}
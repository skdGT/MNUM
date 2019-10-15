#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*  Métodos iterativos:
 *      - Picard Peano
 *      - Newton
 *  Sistemas de equações
 */

double func(double x) {
    return 2*x*x - 5*x - 3;
}

void solver(double* sol)
{
    sol[0] = (5.0 - sqrt(5.0*5.0 + 4.0*3.0*2.0)) / (2.0*2.0);
    sol[1] = (5.0 + sqrt(5.0*5.0 + 4.0*3.0*2.0)) / (2.0*2.0);
}

/*      Método de Picard Peano
 *      x(n+1) = g(xn)
 *      x <- (2x^2 - 3) / 5 ---> 0.4x^2 - 0.6
 *      x <- (5x+3) / 2x    ---> 2.5 + 1.5/x
 *
 */

double g1(double x) {
    return 0.4f*x*x - 0.6f;
}

double g2(double x) {
    return 2.5 + 1.5/x;
}

double picard(string funcao) {
    double xn;
    cout << "guess: ";
    cin >> xn;

    double sol[2];
    solver(sol);

    int i = 10000;

    if (funcao == "g1") {
        while (abs(xn - g1(xn)) && i != 0) {
            cout << "xn: " << xn << endl;
            cout << "erro abs: " << abs(xn - sol[0]) << endl;
            xn = g1(xn);
            i--;
        }
    }
    else {
        while (abs(xn - g2(xn)) && i != 0) {
            cout << "xn: " << xn << endl;
            cout << "erro abs: " << abs(xn - sol[1]) << endl;
            xn = g2(xn);
            i--;
        }
    }

    if (i == 0) {
        cerr << "diverges\ntry a new gess" << endl;
        exit(1);
    }
    return xn;
}


int main() {
    double sol[2];
    solver(sol);

    cout << setprecision(20) << "sol correta: " << sol[0] << " ; " << sol[1] << endl;
    cout << setprecision(20) << picard("g2") << endl << picard("g1");
}
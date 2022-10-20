#include <iostream>
#include <iomanip>

using namespace std;

const int w = 3;
const int k = 8;
const double X = 7.5;
const double D = 1.9;
const double G = 8.3;

/* Fills table with random doubles in range between top and bottom */
void fillTable(double T[w][k], double top, double bottom)
{
    for (int i=0; i<w; i++) {
        for (int j=0; j<k; j++) {
            T[i][j] = (top - bottom) * ((double) rand() / RAND_MAX) + bottom;
        }
    }
};
/* Prints table with given precision */
void printTable(double T[w][k], int precision)
{
    for (int i=0; i<w; i++) {
        for (int j=0; j<k; j++) {
            cout << setprecision(precision) << fixed << setw(8) << T[i][j];
        }
        cout << endl;
    }
    cout << endl;
};

/* Switches element order for rows with average less than given number */
int switchOrder(double T[w][k], double number)
{
    int rows = 0;
    for (int i=0; i<w; i++) {
        double sum = 0;
        for (int j=0; j<k; j++) {
            sum += T[i][j];
        }
        if (sum/k < number) {
            rows++;
            for (int j=0; j<k/2; j++) {
                double temp = T[i][j];
                T[i][j] = T[i][k-1-j];
                T[i][k-1-j] = temp;
            }
        }
    }
    return rows;
}

int main()
{
    // 1

    double A[w][k];
    double B[w][k];

    fillTable(A, X, -X);
    fillTable(B, D, G);

    // 2
    printTable(A, 1);
    printTable(B, 2);

    // 3
    int a = switchOrder(A, 0);
    int b = switchOrder(B, (D+G)/2);

    // 4
    printTable(A, 1);
    printTable(B, 2);

    // 5
    cout << "W tablicy A odwrocono " << a << " wierszy, a w tablicy B odwrocono " << b << " wierszy." << endl;
    if (a > b) {
        cout << "W tablicy A odwrocono wiecej wierszy" << endl;
    } else if (a < b) {
        cout << "W tablicy B odwrocono wiecej wierszy" << endl;
    } else {
        cout << "W obu tablicach odwrocono tyle samo wierszy" << endl;
    }

    return 0;
}



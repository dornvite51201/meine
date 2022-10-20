#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int n=3;
    struct Towar
    {
        char nazwa_towaru;
        int cena;
    };

    Towar A[n][n];

// 1
    srand(time(NULL));

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i==j || j== n-1-i || i==0 || i==n-1 || j==0 || i==n-1)
            {
                A[i][j].nazwa_towaru = 65+rand()%(90+1-65);
            }
            else
            {
                A[i][j].nazwa_towaru = 97+rand()%(122+1-97);
            }
            A[i][j].cena = rand()%(99+1-1);
        }
    }

// 2
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<fixed<<setw(8)<<setprecision(0)<<A[i][j].nazwa_towaru<<A[i][j].cena;
        }
        cout << endl;
    }

// 3

    int mini =A[0][n-1].cena;
    int indeks_min;
    for (int i=0; i<n; i++)
    {
        if (A[i][n-1-i].cena<mini)
        {
            mini = A[i][n-1-i].cena;
            indeks_min = i;
        }
    }

    cout << "Najtanszy towar na drugiej przekatnej: " << mini;
    cout<<endl;

    int highest =0;
    int indeks_max,kolumna_max;
    for (int i = n-3; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (A[i][j].cena>highest)
            {
                highest = A[i][j].cena;
                indeks_max = i;
                kolumna_max = j;
            }
        }
    }

    cout << "Najdrozszy towar lezacy w trzech ostatnich wierszach tablicy: "<< highest;
    cout<<endl;

    Towar zamiana;
    zamiana = A[indeks_max][kolumna_max];
    A[indeks_max][kolumna_max] = A[indeks_min][n-1-indeks_min];
    A[indeks_min][n-1-indeks_min] = zamiana;

// 4
    cout << "Cena maksymalna w 3 ostatnich wierszach: " << highest;
    cout<<endl;

    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << fixed << setw(8) << setprecision (0)<< A[i][j].nazwa_towaru << A[i][j].cena;
        }
        cout << endl;
    }
    return 0;
}


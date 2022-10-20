#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    const int n = 3;
    int A[n][n];
    const int D = -10;
    const int G = 20;
    const int W=10;

    srand(time(NULL));


    for (int i=0; i<n; i++)
    {
        for (int k=0; k<n; k++)
        {
            A[i][k] = (rand()%(G+1-D))+D;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int k=0; k<n; k++)
        {
            cout<<setw(W)<<A[i][k];
        }
        cout<<endl;
    }

    //

    int kolumna=0;
    int kol_poprzednia=0;

    cout<<"-----"<<endl;

    for (int k=0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            if (A[i][k]%2==0)
            {
                kolumna++;
            }
    }

    cout << setw(W) << (kolumna-kol_poprzednia);
    kol_poprzednia=kolumna;
    kolumna=0;
    }
    cout<<endl;

    //

    int najwiekszy_element = A[0][0];
    int indeks_wiersza=0;

    for (int i=1; i<n; i++)
    {
        if(A[i][i]>najwiekszy_element)
        {
            najwiekszy_element=A[i][i];
            indeks_wiersza=i;
        }
    }
    cout<<endl;
    cout<<"-----"<<endl;

    cout<<"Indeks wiersza: "<<indeks_wiersza<<endl;

    //

    int min_element_wiersza=A[indeks_wiersza][0];
    int numer_kolumny=0;

    for (int k=1;k<n;k++)
    {
        if (A[indeks_wiersza][k] <min_element_wiersza)
        {
            min_element_wiersza=A[indeks_wiersza][k];
            numer_kolumny=k;
        }
    }

    int zamiana = A[indeks_wiersza][numer_kolumny];

    A[indeks_wiersza][numer_kolumny] = A[indeks_wiersza][indeks_wiersza];
    A[indeks_wiersza][indeks_wiersza] = zamiana;

    cout<<"-----"<<endl;
    cout<<"Zamieniony wiersz: "<<endl;

    for (int k=0;k<n;k++)
    {
        cout << setw(W) << A[indeks_wiersza][k];
    }

    return 0;

return 0;
}

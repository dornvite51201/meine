#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int w = 6;
const int k = 9;

int main()
{
    float A[w][k];
    const int Z=0;
    const int P=1;
    const int D=15;

    string plik, plik_koncowy;
    cout << fixed << setprecision(P);

    // 1

    for (int i=0; i<w; i++)
    {
        for (int j=0; j<k; j++)
        {
            A[i][j]=Z;
        }
    }

    cout << "Podaj nazwe pliku do wczytania: ";
    getline(cin, plik);

    ifstream file(plik.c_str());

    if (!file.is_open())
    {
        cout << "Nie ma takiego pliku.";
        return 1;
    }

    // 2

    cout << "Tablica z elementow wczytanych z pliku: \n";

    for (int i=0; i<w; i++)
    {
        for(int j=0; j<k; j++)
        {
            file >> A[i][j];
            cout << fixed << setw(D) << A[i][j];
        }
        cout << endl;
    }

    // 3

    float suma=0;
    float srednia_wszystkie[w], srednia_skrajna[w];

    for (int i =0; i<w;i++)
    {
        srednia_wszystkie[i]=0;
        srednia_skrajna[i]=0;
    }

    for (int i=0; i<w; i++)
    {
        for (int j=0; j<k; j++)
        {
            suma += A[i][j];
        }
        srednia_wszystkie[i] = suma/k;
        srednia_skrajna[i] = (A[i][0]+A[i][k-1])/2.0;
        cout<< "Srednia wszystkich elementow w wierszu "<<i+1<<": "<<srednia_wszystkie[i]<< ", srednia skrajnych elementow to: "<<srednia_skrajna[i]<<endl;
        suma =0;
    }

    float przesuniecie;
    for (int i =0; i<w; i++)
    {
        if (srednia_wszystkie[i] > srednia_skrajna[i])
        {
            przesuniecie = A[i][0];
            for (int j = 0; j<k-1; j++)
            A[i][j] = A[i][j+1];
            A[i][k-1] = przesuniecie;
        }

    }

    // 4

    cout << "Tablica po przeksztalceniu: \n";

    for (int i=0; i<w; i++)
        {
        for(int j=0; j<k; j++)
        {
            file >> A[i][j];
            cout << fixed << setw(D) << A[i][j];
        }
        cout << endl;
        }

    // 5
    ofstream file_o("nowa.txt");
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<k; j++)
        {
            file_o <<fixed<<setprecision(P)<<setw(D)<<A[i][j];
        }
        file_o<<endl;
    }

    file.close();
    file_o.close();

    return 0;

}







































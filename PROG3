#include <iostream>
#include <cstdlib>

using namespace std;

int main()

{

    const int N=5;
    int liczba;

    if(N<=1)
    {
        cout<<"Wprowadzona liczba jest MNIEJSZA niz 1. ";
        return 0;
    }
    else
    {
        cout<<"Wartosc stalej N: "<<N<<endl;
    }

    //

    int first_highest=INT_MIN, second_highest=INT_MIN, n;

    for (int i=0; i<N; i++)
    {
        cout<<"Wprowadz liczbe: "<<endl;
        cin>>n;

        if(n>first_highest)
        {
            second_highest=first_highest;
            first_highest=n;
        }
        else if(n>second_highest)
        {
            second_highest=n;
        }
    }

    cout<<"Dwie najwieksze liczby to: "<<first_highest<<" oraz "<<second_highest<<endl;

    //

    string a, b;

    for(int i=0; i<N; i++)
    {
        cout<<"Wprowadz napis: "<<endl;
        cin>>a;

        if(N-i==2)
        {
            b=a;
        }
    }

    cout<<"Dwa ostatnie napisy: "<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    //

    char znak;
    char tablica[N];

    for (int i=0; i<N; i++)
    {
        cout<<"Wprowadz znak: "<<endl;
        cin>>tablica[i];
    }

    cout<<"Co drugi wczytany znak (w kolejnosci od ostatniego do pierwszego): "<<endl;

    for (int i=N-1; i>=0; i-=2)
    {
    cout<<tablica[i]<<endl;
    }
    return 0;


return 0;
}

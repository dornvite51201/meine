#include <iostream>

using namespace std;

int main()
{
   string imie;
   int a, b;
   int wieksza, mniejsza;
   short c=0;
   float d;

   cout<<"Podaj imie: ";
   cin>>imie;
   cout<<"Witaj "<<imie<<endl;

   cout<<"Podaj pierwsza liczbe CALKOWITA: ";
   cin>>a;
   cout<<"Podaj druga liczbe CALKOWITA: ";
   cin>>b;

   if (a<10&&a>-10)
   {
       c+=1;
   }

   if (b<10&&b>-10)
   {
       c+=1;
   }

   cout<<"Ilosc liczb JEDNOCYFROWYCH: "<<c<<endl;

   if (a==b){
    cout <<"Wczytane liczby sa sobie ROWNE."<<endl;
    return 0;}
   else if (a<b){
    wieksza=b;
    mniejsza=a;
   } else {
    wieksza=a;
   mniejsza=b;}

if (mniejsza==0){cout <<"Mniejsza z wczytanych liczb jest rowna 0. Uwaga! Nie mozna dzielic przez zero."<<endl;
return 0;}

else if(mniejsza<0){cout<<"Mniejsza z wczytanych liczb jest UJEMNA."<<endl;}
else {cout<<"Mniejsza z wczytanych liczb jest DODATNIA."<<endl;}


d = wieksza/ (mniejsza*3.0);
cout<<"Wynik dzielenia wiekszej liczby przez potrojona wartosc mniejszej: "<<d<<endl;
return 0;

}



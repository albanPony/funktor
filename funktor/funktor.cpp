
#include <iostream>
#include <vector>

using namespace std;

//obiekt funkcyjny struct
struct F_czyNieparzyste {
    bool operator()(int liczba) {
        return liczba % 2;
    }
};

//obiekt funkcyjny class
class F_wiekszyNiz {
public:
    int liczba{};
    //konstruktor
    F_wiekszyNiz(int l) : liczba{ l } {};

    bool operator()(int wartosc) {
        return wartosc > liczba; 
    }
};


//funkcja zliczająca dla obiektu F_czyNieparzyste
int policzElementy(vector<int> kontener, F_czyNieparzyste decydent) {
    int licznik{ 0 };
    for (auto e : kontener) {
        if (decydent(e))
            licznik++;
    }
    return licznik;
}

//funkcja zliczająca dla obiekt F_wiekszyNiz
int policzElementy2(vector<int> kontener, F_wiekszyNiz decydent) {
    int licznik{ 0 };
    for (auto e : kontener) {
        if (decydent(e))
            licznik++;
    }
    return licznik;
}

int main()
{
    vector<int> v{ 1,5,3,7,11,12,15,19,20,22,26};

    F_czyNieparzyste obiekt1;

    F_wiekszyNiz obiekt_9{ 9 };

    F_wiekszyNiz obiekt_2{ 2 };
     
    cout << "F_czy nieparzyste - policzono że jest elemntów nieparzystych:" << policzElementy(v, obiekt1)<< endl;

    cout << "F_wiekszyNiz - elementów wiekszych niz 9 jest:" << policzElementy2(v, obiekt_9) << endl;

    cout << "F_wiekszyNiz - elementów wiekszych niz 3 jest:" << policzElementy2(v, obiekt_2) << endl;


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

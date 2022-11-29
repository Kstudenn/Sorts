
#include <iostream>
#include "../Headers/Table.hpp"
#include <ctime>
#include "../Headers/QuickSort.hpp"
#include "../Headers/IntroSort.hpp"
#include "../Headers/MergeSort.hpp"

const int ILOSCTABLIC=5;

int StworzTablice(int **wskaznik, int wielkosc) {

    for(int i=0;i<ILOSCTABLIC;i++)
        wskaznik[i]=new int[wielkosc];
}

int WypelnienieTablicy(int **tablicaDanych, float poczatkowePosrtowanie, int wielkoscTablicy) {

    for (int i = 0; i < ILOSCTABLIC; i++) {
        for(int j=0;j<wielkoscTablicy;j++) {
            if (j > (int)((poczatkowePosrtowanie / 100) * wielkoscTablicy))
                tablicaDanych[i][j] = (rand() % wielkoscTablicy) + (poczatkowePosrtowanie / 100) * wielkoscTablicy;
            else
                tablicaDanych[i][j] = j;
        }
    }
}

int OdwrotneWypelnienieTablicy(int **tablicaDanych, int wielkoscTablicy){

    for(int j=0;j<ILOSCTABLIC;j++)
        for(int i=wielkoscTablicy-1;i>=0;i--)
            tablicaDanych[j][i]=i;

}




void MenuSortu(int **tablicaDanych, int wielkoscTablicy) {

    time_t czasStartu, czasKonca;
    int menuOp = 0;

    std::cout << "Wybierz metode sortowania" << std::endl;
    std::cout << "1. QuickSort\n2. Merge\n3. Intro\n4. Cofnij\n> ";
    std::cin >> menuOp;
    switch (menuOp) {

        case 1:
            time(&czasStartu);
            for(int i=0;i<ILOSCTABLIC;i++)
                QuickSort(tablicaDanych[i], 0, wielkoscTablicy-1);
            time(&czasKonca);
            std::cout<<"Czas wykonywania operacji wyniosl: "<<difftime(czasKonca, czasStartu)<<" sekund"<<"\nPoczatek: "<<ctime(&czasStartu)
                     <<"\nKoniec: "<<ctime(&czasKonca)<<" "<<std::endl;

            break;
        case 2:
            time(&czasStartu);
            for(int i=0;i<ILOSCTABLIC;i++)
                MergeSort(tablicaDanych[i],0,wielkoscTablicy-1);
            time(&czasKonca);
            std::cout<<"Czas wykonywania operacji wyniosl: "<<difftime(czasKonca, czasStartu)<<" sekund"<<"\nPoczatek: "<<ctime(&czasStartu)
                     <<"\nKoniec: "<<ctime(&czasKonca)<<" "<<std::endl;

            break;
        case 3:
            time(&czasStartu);
            for(int i=0;i<ILOSCTABLIC;i++)
                IntroSort(tablicaDanych[i], wielkoscTablicy);
            time(&czasKonca);
            std::cout<<"Czas wykonywania operacji wyniosl: "<<difftime(czasKonca, czasStartu)<<" sekund"<<"\nPoczatek: "<<ctime(&czasStartu)
                     <<"\nKoniec: "<<ctime(&czasKonca)<<" "<<std::endl;

            break;
        case 4:
            break;
        default:
            std::cout<<"Bledny wybor, cofnie Cie do menu glownego\n";

    }
}


void MenuObslugi() {


    int **tablicaDanych = nullptr;
    int wielkoscTablicy = 0;          //zły format, za mala zmienna na liczbe 1 000 000
    float wstepnePosortowanie = 0;
    unsigned int menuSwitch = 0;


    while (true) {
        //std::cout<<"1. Tworz tablice\n2. Wypisz tablice\n3. Usuwanie\n4. Koniec\n> ";
        std::cout<<"===================\n";
        std::cout << "1. Tworz tablice\n2. Wypisz tablice\n3. Sortuj\n4. Usun\n5. Koniec\n";
        std::cout<<"===================\n> ";
        std::cin >> menuSwitch;

        switch (menuSwitch) {

            case 1:                                                                                                      //Tworzenie tablicy
                tablicaDanych = new int *[ILOSCTABLIC];
                std::cout << "Ile elementow ma liczyc tablica? > ";
                std::cin >> wielkoscTablicy;
                std::cout << "Procentowa wartosc wstepnego posortowania > ";
                std::cin >> wstepnePosortowanie;
                StworzTablice(tablicaDanych, wielkoscTablicy);
                if (wstepnePosortowanie >= 0) WypelnienieTablicy(tablicaDanych, wstepnePosortowanie, wielkoscTablicy);
                if (wstepnePosortowanie < 0) OdwrotneWypelnienieTablicy(tablicaDanych, wielkoscTablicy);

                break;

            case 2:
                if (tablicaDanych != nullptr)
                    for (int i = 0; i < ILOSCTABLIC; i++) {
                        if (tablicaDanych[i] != nullptr)
                            for (int j = 0; j < wielkoscTablicy; j++) {
                                std::cout << tablicaDanych[i][j] << " ";
                            }
                        std::cout << std::endl;
                    }
                else
                    std::cout << "Tablica jest pusta" << std::endl;
                break;

            case 3:
                MenuSortu(tablicaDanych, wielkoscTablicy);
                break;

            case 4: //Usuwanie tablicy
                if (tablicaDanych != nullptr) {
                    for (int i = 0; i < ILOSCTABLIC; i++) {
                        delete[] tablicaDanych[i];
                        tablicaDanych[i] = nullptr;
                    }
                    delete[] tablicaDanych;
                    tablicaDanych = nullptr;
                }
                std::cout << "Usunieto tablice" << std::endl;
                break;

            case 5:
                if (tablicaDanych != nullptr) {
                    for (int i = 0; i < ILOSCTABLIC; i++) {

                        delete[] tablicaDanych[i];
                        tablicaDanych[i] = nullptr;
                    }
                }
                delete[] tablicaDanych;
                std::cout << "Pomyslnie zakonczono program";
                return;

            default:
            std::cout<<"Opcja nieobslugiwana, wybierz ponownie > ";
        }
    }
}



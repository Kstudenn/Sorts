
#include <cmath>

 int Partition(int* tablicaDanych, int poczatekZakresu, int koniecZakresu) {
    int pivot = tablicaDanych[koniecZakresu];
    int temp;
    int i = poczatekZakresu;

    for (int j = poczatekZakresu; j < koniecZakresu; ++j)
    {
        if (tablicaDanych[j] <= pivot)
        {
            temp = tablicaDanych[j];
            tablicaDanych[j] = tablicaDanych[i];
            tablicaDanych[i] = temp;
            i++;
        }
    }

    tablicaDanych[koniecZakresu] = tablicaDanych[i];
    tablicaDanych[i] = pivot;

    return i;
}

 void QuickSortRecursive(int* tablicaDanych, int poczatekZakresu, int koniecZakresu) {
    if (poczatekZakresu < koniecZakresu)
    {
        int q = Partition(tablicaDanych, poczatekZakresu, koniecZakresu);
        QuickSortRecursive(tablicaDanych, poczatekZakresu, q - 1);
        QuickSortRecursive(tablicaDanych, q + 1, koniecZakresu);
    }
}

 void MaxHeapify(int* tablicaDanych, int heapSize, int index) {
    int lewaTablica = (index + 1) * 2 - 1;
    int prawaTablica = (index + 1) * 2;
    int najwiekszaWartoscLiczbowa = 0;

    if (lewaTablica < heapSize && tablicaDanych[lewaTablica] > tablicaDanych[index])
        najwiekszaWartoscLiczbowa = lewaTablica;
    else
        najwiekszaWartoscLiczbowa = index;

    if (prawaTablica < heapSize && tablicaDanych[prawaTablica] > tablicaDanych[najwiekszaWartoscLiczbowa])
        najwiekszaWartoscLiczbowa = prawaTablica;

    if (najwiekszaWartoscLiczbowa != index)
    {
        int temp = tablicaDanych[index];
        tablicaDanych[index] = tablicaDanych[najwiekszaWartoscLiczbowa];
        tablicaDanych[najwiekszaWartoscLiczbowa] = temp;

        MaxHeapify(tablicaDanych, heapSize, najwiekszaWartoscLiczbowa);
    }
}

 void HeapSort(int* tablicaDanych, int licznik) {
    int heapSize = licznik;

    for (int p = (heapSize - 1) / 2; p >= 0; --p)
        MaxHeapify(tablicaDanych, heapSize, p);

    for (int i = licznik - 1; i > 0; --i)
    {
        int temp = tablicaDanych[i];
        tablicaDanych[i] = tablicaDanych[0];
        tablicaDanych[0] = temp;

        --heapSize;
        MaxHeapify(tablicaDanych, heapSize, 0);
    }
}

 void InsertionSort(int* tablicaDanych, int licznik) {
    for (int i = 1; i < licznik; ++i)
    {
        int j = i;

        while ((j > 0))
        {
            if (tablicaDanych[j - 1] > tablicaDanych[j])
            {
                tablicaDanych[j - 1] ^= tablicaDanych[j];
                tablicaDanych[j] ^= tablicaDanych[j - 1];
                tablicaDanych[j - 1] ^= tablicaDanych[j];

                --j;
            }
            else
            {
                break;
            }
        }
    }
}

 void IntroSort(int* tablicaDanych, int licznik) {
    int rozmiarTablicyPodzielonej = Partition(tablicaDanych, 0, licznik - 1);

    if (rozmiarTablicyPodzielonej < 16)
    {
        InsertionSort(tablicaDanych, licznik);
    }
    else if (rozmiarTablicyPodzielonej >(2 * log(licznik)))
    {
        HeapSort(tablicaDanych, licznik);
    }
    else
    {
        QuickSortRecursive(tablicaDanych, 0, licznik - 1);
    }
}
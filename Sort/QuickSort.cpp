


void Swap(int &pierwszyZnak, int &drugiZnak)
{
    int tempA =pierwszyZnak, tempB=drugiZnak;
    pierwszyZnak=tempB;
    drugiZnak=tempA;
}

void QuickSort(int *tablicaDanych, int poczatekZakresu, int koniecZakresu)
{
    if(koniecZakresu <= poczatekZakresu) return;

    int i = poczatekZakresu - 1, j = koniecZakresu + 1,
            pivot = tablicaDanych[(poczatekZakresu+koniecZakresu)/2]; //wybieramy punkt odniesienia

    while(true)
    {
        //szukam elementu wiekszego lub rownego piwot stojacego
        //po prawej stronie wartosci pivot
        while(pivot>tablicaDanych[++i]);

        //szukam elementu mniejszego lub rownego pivot stojacego
        //po lewej stronie wartosci pivot
        while(pivot<tablicaDanych[--j]);

        //jesli liczniki sie nie minely to zamień elementy ze soba
        //stojace po niewlasciwej stronie elementu pivot
        if( i <= j)
            //funkcja swap zamienia wartosciami tablicaDanych[i] z tablicaDanych[j]
            Swap(tablicaDanych[i],tablicaDanych[j]);
        else
            break;
    }

    if(j > poczatekZakresu)
        QuickSort(tablicaDanych, poczatekZakresu, j);
    if(i < koniecZakresu)
        QuickSort(tablicaDanych, i, koniecZakresu);
}
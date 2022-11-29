


void Merge(int* tablicaDanych,int pivot,int poczatekZakresu,int koniecZakresu) {
    int wielkoscLewejTablicy=poczatekZakresu-pivot+1;
    int wielkoscPrawejTablicy=koniecZakresu-poczatekZakresu;
    int lewaCzescTablicy[wielkoscLewejTablicy+1];
    int prawaCzescTablicy[wielkoscPrawejTablicy+1];
    for(int i=0; i<wielkoscLewejTablicy; i++) lewaCzescTablicy[i]=tablicaDanych[pivot+i];
    for(int j=0; j<wielkoscPrawejTablicy; j++) prawaCzescTablicy[j]=tablicaDanych[poczatekZakresu+1+j];
    int i=0;
    int j=0;
    int n=0;
    while(i!=wielkoscLewejTablicy && j!=wielkoscPrawejTablicy) {
        if(lewaCzescTablicy[i]>prawaCzescTablicy[j]) {
            tablicaDanych[pivot+n]=prawaCzescTablicy[j];
            j++;
        } else {
            tablicaDanych[pivot+n]=lewaCzescTablicy[i];
            i++;
        }
        n++;
    }
    while(j!=wielkoscPrawejTablicy) {
        tablicaDanych[pivot+n]=prawaCzescTablicy[j];
        j++;
        n++;
    }
    while(i!=wielkoscLewejTablicy) {
        tablicaDanych[pivot+n]=lewaCzescTablicy[i];
        i++;
        n++;
    }
}
void MergeSort(int* tablicaDanych,int p,int r) {
    if(r>p) {
        int poczatek;
        poczatek=(p+r)/2;
        MergeSort(tablicaDanych,p,poczatek);
        MergeSort(tablicaDanych,poczatek+1,r);
        Merge(tablicaDanych,p,poczatek,r);
    }
}
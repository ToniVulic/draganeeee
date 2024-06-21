#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define REG 20      //s ovim smo izbjegli VLA
#define MODEL 20
#define REGA 20

typedef enum {
    ADMINISTRATOR = 1,
    KORISNIK = 2,
    EXIT = 3
} IzbornikOpcijaMain;

typedef enum {
    DODAJ_KAMION = 1,
    DODAJ_VOZACA,
    PLANIRAJ_RUTU,
    GENERIRAJ_IZVJESTAJ,
    IZBRISI_KAMION,
    IZBRISI_VOZACA,
    IZBRISI_RUTU,
    SORTIRAJ_VOZACE,
    PRETRAZI_KAMIONE,
    BRISANJE_DATOTEKE_KAMIONA,
    ADMINISTRATORSKI_IZLAZ
} AdministratorskaOpcija;

typedef enum {
    DODAJ_KAMION_KORISNIK = 1,
    DODAJ_VOZACA_KORISNIK,
    PLANIRAJ_RUTU_KORISNIK,
    GENERIRAJ_IZVJESTAJ_KORISNIK,
    SORTIRAJ_VOZACE_KORISNIK,
    PRETRAZI_KAMIONE_KORISNIK,
    AZURIRAJ_KILOMETRAZU_KAMIONA,
    KORISNICKI_IZLAZ
} KorisnickaOpcija;

// definicija struktura koristeci typedef
typedef struct {
    int id;
    char registracija[REG];
    char trazenaRegistracija[REGA];
    char model[MODEL];
    int godinaProizvodnje;
    int kilometraza;
    int stanjeGoriva;
} Kamion;


#define IME 20
#define PREZIME 20
#define VOZACKA 20

typedef struct {
    int id;
    char ime[IME];
    char prezime[PREZIME];
    char vozackaDozvola[VOZACKA];
    int godineIskustva;
} Vozac;

#define P_LOKACIJA 50
#define K_LOKACIJA 50

typedef struct {
    int id;
    int idKamiona;
    int idVozaca;
    char pocetnaLokacija[P_LOKACIJA];
    char krajnjaLokacija[K_LOKACIJA];
    float udaljenost;
    float trajanje;
} Ruta;

//prijava
extern void prijavaAdministratora();
extern void prijavaKorisnika();

//Kamioni
extern void dodajKamione();
extern void obrisiKamion();
extern void pretraziKamionePoID();
inline extern void brisanjeDatotekeKamiona();
extern void azurirajKilometaraKamiona();

//vozaci
extern void dodajVozaca();
extern void brisiVozaca();
extern void sortiraj_po_iskustvu();
extern void pisi_u_datoteku(Vozac*, const int);

//rute
extern void dodajRutu();
extern void brisiRutu();

//generiranje izvjestaja
extern void generirajIzvjestaj();





#endif // HEADER_H


/*
Obavezni koncepti
1. Odabir konkretnih primitivnih tipova podataka za rad s cjelobrojnim i realnim konstantama.   DA
2. Odabir konkretnih slo�enih tipova podataka za rad sa specifi?nim objektima.                  DA
3. Primjena typedef sa strukturama i unijama, po potrebi s enum tipovima podataka tamo gdje     DA
treba.
4. Imenovanje identifikatora (varijabli, konstanti, polja, funkcija, pokaziva?a�) � upotreba
camelCase, PascalCase i snake_case konzistento kroz cijeli projekt.                                         DA
5. Primjena klju?ne rije?i static za globalne i lokalne varijable.                                      FALI
6. Organizacija izvornog k�da.                                                                  DA
7. Primjena extern klju?ne rije?i za globalne varijable.                                                    DA
8. Ako su funkcije jednostavne koristiti makro funkcije ili inline funkcije.                                DA
9. Izbornik/podizbornici.                                                                       DA
10. Generalno upotreba pokaziva?a tamo gdje su potrebni.                                                DA
11. Generalno upotreba struktura i funkcija.                                                    DA
12. Za�tita parametara kod svih funkcija.                                                                   DA
13. Koristiti stati?ki zauzeta polja gdje su potrebna, nikako ne koristiti VLA polja.                   DA
14. Koristiti dinami?ko zauzimanje memorije za bilo koji tip podatka, osobito za slo�ene tipove             DA
podataka.
15. Koristiti funkcije malloc(), calloc(), realloc(), free() � neku od njih, ako ne i sve.                  DA
16. Sigurno brisanje memorije koja je dinami?ki zauzeta, anuliranje memorijskog prostora, provjera          DA
pokaziva?a kako se ne bi dogodila pogre�ka double free() i anuliranje svih pokaziva?a koji su bili
usmjereni na memorijski prostor koji se dinami?ki zauzeo.
17. Datoteke, koristiti tekstualnu ili binarnu, provjera pokaziva?a i zatvaranje datoteke.              DA
18. Koristiti funkcije fseek(), ftell(), rewind(), ovisno o potrebi � neku od njih ako ne sve.              DA
19. Koristiti funkcije remove(), rename(), po potrebi implementirati funkciju za kopiranje datoteka.        DA
20. Upravljati s pogre�kama, errno, perror(), strerror(), feof(), ferror() � neku od njih ako ne sve.   DA
21. Sortiranje � preporuka koristiti ugra?enu qsort() funkciju.                                             DA
22. Pretra�ivanje � preporuka koristiti ugra?enu bsearch() funkciju.                                        DA
23. Rekurzije je najlak�e koristiti primjenom rekurzivnih algoritama sortiranja kao �to su quick sort,      NE-----------------
merge sort, insert sort ili pretra�ivanja kao �to je binary search.
24. Pokaziva?e na funkcije je najlak�e koristiti upotrebom funkcije qsort() ili bsearch() iz standardne     DA
biblioteke.
*/

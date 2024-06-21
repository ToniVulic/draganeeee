#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

void prijavaAdministratora() {
    char korisnickoIme[20];
    char lozinka[20];

    printf("Unesite korisnicko ime (admin): ");
    fgets(korisnickoIme, sizeof(korisnickoIme), stdin);
    strtok(korisnickoIme, "\n");

    printf("Unesite lozinku(admin123): ");
    fgets(lozinka, sizeof(lozinka), stdin);
    strtok(lozinka, "\n");

    // provjera korisnickog imena i lozinke
    if (strcmp(korisnickoIme, "admin") == 0 && strcmp(lozinka, "admin123") == 0) {
        printf("\nDobrodosli, administrator!\n");
        AdministratorskaOpcija izbor;
        do {
            printf("\nAdministratorske opcije:\n");
            printf("1. Dodaj kamion\n");
            printf("2. Dodaj vozaca\n");
            printf("3. Planiraj rutu\n");
            printf("4. Generiraj izvjestaj\n");
            printf("5. Izbrisi kamion\n");
            printf("6. Izbrisi vozaca\n");
            printf("7. Izbrisi rutu\n");
            printf("8. Sortiraj vozace\n");
            printf("9. Pretrazi kamione\n");
            printf("10. Brisanje cijele datoteke kamiona\n");
            printf("11. Izlaz\n");
            printf("Odaberite opciju: ");
            scanf("%d", (int*)&izbor);
            getchar(); // �isti newline iz buffer-a

            switch (izbor) {
            case DODAJ_KAMION:
                dodajKamione();
                break;
            case DODAJ_VOZACA:
                dodajVozaca();
                break;
            case PLANIRAJ_RUTU:
                dodajRutu();
                break;
            case GENERIRAJ_IZVJESTAJ:
                generirajIzvjestaj();
                break;
            case IZBRISI_KAMION:
                obrisiKamion();
                break;
            case IZBRISI_VOZACA:
                brisiVozaca();
                break;
            case IZBRISI_RUTU:
                brisiRutu();
                break;
            case SORTIRAJ_VOZACE:
                sortiraj_po_iskustvu();
                break;
            case PRETRAZI_KAMIONE:
                pretraziKamionePoID();
                break;
            case BRISANJE_DATOTEKE_KAMIONA:
                brisanjeDatotekeKamiona();
                break;
            case ADMINISTRATORSKI_IZLAZ:
                printf("Izlaz iz administratorskog izbornika.\n");
                break;
            default:
                printf("Nepostoje�a opcija. Poku�ajte ponovno.\n");
            }
        } while (izbor != ADMINISTRATORSKI_IZLAZ);
        return 0;

    }

    else {
        printf("Pogresno korisnicko ime ili lozinka. Pokusajte ponovno.\n");
    }

}

void prijavaKorisnika() {

    printf("\nDobrodosli, korisnik!\n");
    KorisnickaOpcija izbor;
    do {
        printf("\nKorisnicke opcije:\n");
        printf("1. Dodaj kamion\n");
        printf("2. Dodaj vozaca\n");
        printf("3. Planiraj rutu\n");
        printf("4. Generiraj izvjestaj\n");
        printf("5. Sortiraj vozace\n");
        printf("6. Pretrazi kamione\n");
        printf("7. azuriraj kilometrazu kamiona\n");
        printf("8. Izlaz\n");
        printf("Odaberite opciju: ");
        scanf("%d", (int*)&izbor);
        getchar(); // �isti newline iz buffer-a

        switch (izbor) {
        case DODAJ_KAMION_KORISNIK:
            dodajKamione();
            break;
        case DODAJ_VOZACA_KORISNIK:
            dodajVozaca();
            break;
        case PLANIRAJ_RUTU_KORISNIK:
            dodajRutu();
            break;
        case GENERIRAJ_IZVJESTAJ_KORISNIK:
            generirajIzvjestaj();
            break;
        case SORTIRAJ_VOZACE_KORISNIK:
            sortiraj_po_iskustvu();
            break;
        case PRETRAZI_KAMIONE_KORISNIK:
            pretraziKamionePoID();
            break;
        case AZURIRAJ_KILOMETRAZU_KAMIONA:
            azurirajKilometaraKamiona();
            break;
        case KORISNICKI_IZLAZ:
            printf("Izlaz iz korisni�kog izbornika.\n");
            break;
        default:
            printf("Nepostoje�a opcija. Poku�ajte ponovno.\n");
        }
    } while (izbor != KORISNICKI_IZLAZ);
    return 0;
}




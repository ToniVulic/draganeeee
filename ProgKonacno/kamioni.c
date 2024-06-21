#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//funkcija za dodavanje kamiona
void dodajKamione() {
    FILE* file = fopen("kamioni.txt", "a+");
    if (file == NULL) {
        perror("Ne moze se otvoriti datoteka za kamione");
        exit(1);
    }

    Kamion* noviKamion = (Kamion*)malloc(sizeof(Kamion));
    if (noviKamion == NULL) {
        perror("Ne moze se alocirati memorija za novog kamiona");
        fclose(file);
        exit(1);
    }

    printf("Unesite ID: ");
    if (scanf("%d", &noviKamion->id) != 1) {
        printf("Neispravan unos ID-a.\n");
        fclose(file);
        free(noviKamion);
        return 1;
    }

    // Provjera da li ID već postoji
    fseek(file, 0, SEEK_SET); // Premjesti pokazivač na početak datoteke
    Kamion tempKamion;
    int idPostojeci = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "ID: %d", &tempKamion.id) == 1) {
            if (tempKamion.id == noviKamion->id) {
                idPostojeci = 1;
                break;
            }
        }
    }

    if (idPostojeci) {
        printf("Kamion sa ID %d vec postoji.\n", noviKamion->id);
        fclose(file);
        free(noviKamion);
        return 1;
    }

    printf("Unesite registraciju: ");
    if (scanf("%49s", noviKamion->registracija) != 1) {
        fclose(file);
        free(noviKamion);
        return 1;
    }
 
    printf("Unesite model kamiona: ");
    if (scanf("%49s", noviKamion->model) != 1) {
        fclose(file);
        free(noviKamion);
        return 1;
    }
 

    printf("Unesite godinu proizvodnje: ");
    if (scanf("%d", &noviKamion->godinaProizvodnje) != 1) {
        fclose(file);
        free(noviKamion);
        return 1;
    }
  

    printf("Unesite kilometrazu: ");
    if (scanf("%d", &noviKamion->kilometraza) != 1) {
        fclose(file);
        free(noviKamion);
        return 1;
    }
 

    printf("Unesite stanje goriva u l: ");
    if (scanf("%d", &noviKamion->stanjeGoriva) != 1) {
        fclose(file);
        free(noviKamion);
        return 1;
    }

   fprintf(file, "ID: %d\nRegistracija: %s\nModel: %s\nGodina Proizvodnje: %d godina\nKilometraža: %d km\nStanje Goriva: %d l\n\n", noviKamion->id, noviKamion->registracija, noviKamion->model, noviKamion->godinaProizvodnje, noviKamion->kilometraza, noviKamion->stanjeGoriva);
   
    fclose(file);
    free(noviKamion);

    printf("Kamion uspjesno dodan.\n\n");

    return 0;
}

// Funkcija za pretrazivanje kamiona po registraciji
void pretraziKamionePoID() {
    int trazeniID;
    printf("Unesite ID kamiona za pretragu: ");
    if (scanf("%d", &trazeniID) != 1) {
        printf("Neispravan unos ID-a.\n");
        return;
    }

    FILE* file = fopen("kamioni.txt", "r");
    if (file == NULL) {
        perror("Ne moze se otvoriti datoteka za kamione");
        return;
    }
    char line[256];
    Kamion tempKamion;
    int pronadjen = 0;
    while (fgets(line, sizeof(line), file)) {
        // Ako je linija prazna (samo novi red), ignoriramo je
        if (strcmp(line, "\n") == 0) {
            continue;
        }

        // Učitavanje ID-a
        if (sscanf(line, "ID: %d", &tempKamion.id) == 1) {
            continue; // Preskačemo dalje procesiranje jer smo već učitali ID
        }

        // Učitavanje Registracije
        if (sscanf(line, "Registracija: %49s", tempKamion.registracija) == 1) {
            continue;
        }

        // Učitavanje Modela
        if (sscanf(line, "Model: %49s", tempKamion.model) == 1) {
            continue;
        }

        // Učitavanje Godine Proizvodnje
        if (sscanf(line, "Godina Proizvodnje: %d", &tempKamion.godinaProizvodnje) == 1) {
            continue;
        }

        // Učitavanje Kilometraže
        if (sscanf(line, "Kilometraža: %d", &tempKamion.kilometraza) == 1) {
            continue;
        }

        // Učitavanje Stanja Goriva
        if (sscanf(line, "Stanje Goriva: %d", &tempKamion.stanjeGoriva) == 1) {
            // Nakon učitavanja stanja goriva, provjeravamo ID
            if (tempKamion.id == trazeniID) {
                printf("Kamion pronadjen:\n\n");
                printf("ID: %d\n", tempKamion.id);
                printf("Registacija: %s\n", tempKamion.registracija);
                printf("Model: %s\n", tempKamion.model);
                printf("Godina proizvodnje: %d\n", tempKamion.godinaProizvodnje);
                printf("Kilometraza: %d\n", tempKamion.kilometraza);
                printf("Stanje goriva: %d\n", tempKamion.stanjeGoriva);
                pronadjen = 1;
                break; // Izlazimo iz petlje jer smo pronašli traženi kamion
            }
        }
    }


    if (!pronadjen) {
        printf("Kamion sa ID-em %d nije pronadjen.\n", trazeniID);
    }

    fclose(file);
}

inline void brisanjeDatotekeKamiona() {
    const char* kamioni = "kamioni.txt";

    if (remove(kamioni) == 0) {
        printf("Datoteka %s je uspjesno izbrisana.\n",kamioni);
    }
    else {
        perror("Greska pri brisanju datoteke");
    }
}

void azurirajKilometaraKamiona() {
    FILE* file = fopen("kamioni.txt", "r");
    if (file == NULL) {
        perror("Ne moze se otvoriti datoteka za citanje kamiona");
        return;
    }

    Kamion* kamioni = (Kamion*)malloc(10 * sizeof(Kamion));

    char line[256];
    int n = 0;
    for(int i=0;i<10;i++){
        if (fgets(line, sizeof(line), file) == NULL) break; 
        sscanf(line, "ID: %d", &kamioni[i].id);

        if (fgets(line, sizeof(line), file) == NULL) break; 
        sscanf(line, "Registracija: %s", kamioni[i].registracija);

        if (fgets(line, sizeof(line), file) == NULL) break;
        sscanf(line, "Model: %s", kamioni[i].model);

        if (fgets(line, sizeof(line), file) == NULL) break;
        sscanf(line, "Godina Proizvodnje: %d", &kamioni[i].godinaProizvodnje);

        if (fgets(line, sizeof(line), file) == NULL) break;
        sscanf(line, "Kilometraža: %d", &kamioni[i].kilometraza);

        if (fgets(line, sizeof(line), file) == NULL) break; 
        sscanf(line, "Stanje Goriva: %d", &kamioni[i].stanjeGoriva);

        // Preskočite praznu liniju između zapisa 
        fgets(line, sizeof(line), file);
        n++;
    }

    fclose(file);


    int idKamiona;
    printf("Unesite ID kamioni koje zelite azurirati: ");
    if (scanf("%d", &idKamiona) != 1) {
        printf("Neispravan unos ID-a kamioni.\n");
        free(kamioni);
        return;
    }

    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (kamioni[i].id == idKamiona) {
            found = 1;
            printf("Unesite novu kilometrazu: ");
            if (scanf("%d", &kamioni[i].kilometraza) != 1) {
                printf("Neispravan unos kilometraze.\n");
                free(kamioni);
                return;
            }
            break;
        }
    }

    if (!found) {
        printf("Kamion s ID %d nije pronadeno.\n", idKamiona);
        free(kamioni);
        return;
    }

    file = fopen("kamioni.txt", "w");
    if (file == NULL) {
        perror("Ne moze se otvoriti datoteka za pisanje kamioni");
        free(kamioni);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "ID: %d\nRegistracija: %s\nModel: %s\nGodina Proizvodnje: %d godina\nKilometraža: %d km\nStanje Goriva: %d l\n\n", 
            kamioni[i].id, kamioni[i].registracija, kamioni[i].model, kamioni[i].godinaProizvodnje, kamioni[i].kilometraza, kamioni[i].stanjeGoriva);
    }

    fclose(file);
    free(kamioni);

    printf("Kilometraza kamiona s ID %d uspjesno azurirana.\n", idKamiona);
}

void obrisiKamion() {
    FILE* file = fopen("kamioni.txt", "r");
    if (file == NULL) {
        perror("Ne može se otvoriti datoteka za kamione");
        exit(1);
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Ne može se otvoriti privremena datoteka");
        fclose(file);
        exit(1);
    }

    int targetID;
    printf("Unesite ID kamiona za brisanje: ");
    if (scanf("%d", &targetID) != 1) {
        printf("Neispravan unos ID-a.\n");
        fclose(file);
        fclose(tempFile);
        return;
    }

    Kamion tempKamion;
    char line[256];
    int found = 0;
    int readID = -1;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "ID: %d", &readID) == 1) {
            if (readID == targetID) {
                found = 1;
                
                for (int i = 0; i < 6; ++i) { // APrilagodite ovaj broj na osnovu stvarnog broja linija po kamionu
                    fgets(line, sizeof(line), file); // preskoci ostatak informacija o kamionu
                }
                continue;
            }
        }
        fputs(line, tempFile); // kopiraj line u temp file
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        if (remove("kamioni.txt") != 0) {
            perror("Greska pri brisanju originalne datoteke");
        }
        else if (rename("temp.txt", "kamioni.txt") != 0) {
            perror("Greška pri preimenovanju privremene datoteke");
        }
        else {
            printf("Kamion sa ID %d je uspjesno obrisan.\n", targetID);
        }
    }
    else {
        remove("temp.txt");
        printf("Kamion sa ID %d nije pronaden.\n", targetID);
    }
}
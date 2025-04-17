#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {  // Controlla che sia passato almeno un argomento
        printf("Errore: nessun file specificato.\n");
        return 1;  // Esce con codice di errore
    }

    char *filename = argv[1];  // Assegna il nome del file
    printf("Il nome del file è: %s\n", filename);

    return 0;
}

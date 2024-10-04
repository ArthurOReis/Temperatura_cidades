#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *arquivo = fopen("texto.txt", "r");
    char buffer[255];
    float temperaturas[20];
    int i = 0;
    char numeroChar[4];
    float numero;

    if (arquivo == NULL) {
        printf("Arquivo não pode ser aberto");
    } else {

        while (fgets(buffer, 255, arquivo) != NULL){
            char *tempLugar = strchr(buffer, ';');
            strcpy(numeroChar, tempLugar + 1);
            numero = atof(numeroChar);
            temperaturas[i++] = numero;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%.1f\n", temperaturas[i]);
    }
    
    fclose(arquivo);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    float temp_minima, temp_media, temp_maxima;
} Estatisticas;

Estatisticas calcula_estatisticas(float temperaturas[], int tamanho){

    float soma = 0.0;
    float menor;
    float maior;

    for (int i = tamanho; i != 0; i--)
    {
        
        soma += temperaturas[i];
    }
    

}

int main(){
    FILE *arquivo = fopen("texto.txt", "r");
    char buffer[255];
    float temperaturas[20];
    char numeroChar[4];
    float numero;

    if (arquivo == NULL) {
        printf("Arquivo não pode ser aberto");
    } else {

        int i = 0;
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

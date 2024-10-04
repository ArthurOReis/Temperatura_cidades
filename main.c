#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    float temp_minima, temp_media, temp_maxima;
} Estatisticas;

void calcula_estatisticas(float temperaturas[], int tamanho){ // Terminar o código depois

    float soma = 0.0;
    float menor;
    float maior;

    for (int i = tamanho; i != 0; i--)
    {
        if(temperaturas[i] < temperaturas[i + 1]){
            menor = temperaturas[i];
        }
        soma += temperaturas[i];
    }
    
    printf("%.1f\n", menor);

}

int main(){
    FILE *arquivo = fopen("texto.txt", "r");
    char buffer[255];
    float temperaturas[5];
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

    calcula_estatisticas(temperaturas ,sizeof(temperaturas)/sizeof(temperaturas[0]));
    
    fclose(arquivo);
}

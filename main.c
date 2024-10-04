#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    float temp_minima, temp_media, temp_maior;
} Estatisticas;

Estatisticas calcula_estatisticas(float temperaturas[], int tamanho){ // Terminar o código depois

    float soma = 0.0;
    Estatisticas estatisticas;

    for (int i = tamanho; i != 0; i--){
        if (temperaturas[i] < temperaturas[i + 1]){
            estatisticas.temp_minima = temperaturas[i];
        }
        else if (temperaturas[i] > temperaturas[i + 1]){
            estatisticas.temp_maior = temperaturas[i];
        }
        soma += temperaturas[i];
    }

    estatisticas.temp_media = soma / (float)tamanho;

    return estatisticas;
}

int main(){
    FILE *arquivo = fopen("texto.txt", "r");
    char buffer[255];
    float temperaturas[5];
    char numeroChar[4];
    float numero;

    if (arquivo == NULL){
        printf("Arquivo não pode ser aberto");
    }
    else{
        int i = 0;
        while (fgets(buffer, 255, arquivo) != NULL){ // Terminar o código depois
            char *tempLugar = strchr(buffer, ';');
            printf("%s", buffer);
            strcpy(numeroChar, tempLugar + 1);
            numero = atof(numeroChar);
            temperaturas[i++] = numero;
        }
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%.1f\n", temperaturas[i]);
    // }

    Estatisticas estatisticas = calcula_estatisticas(temperaturas, sizeof(temperaturas) / sizeof(temperaturas[0]));

    fclose(arquivo);
}

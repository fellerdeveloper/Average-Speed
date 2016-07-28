#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int hora, minuto,segundo,tempo,tempo_total,tempo_anterior=0,i;
    double velocidade,velocidade_ms,distancia,distancia_total,velocidade_anterior=0,distancia_anterior=0;
    char *token;
    char line[250];
    char *search = " :";

    while(fgets(line,240,stdin) != NULL && line[0] != '\n'){

        i = strlen(line)-1;
        if( line[ i ] == '\n')
            line[i] = '\0';

        token = strtok(line, search);
        hora = atoi(token);

        token = strtok(NULL, search);
        minuto = atoi(token);

        token = strtok(NULL, search);
        segundo = atoi(token);

        tempo = hora*3600 + minuto*60 + segundo;
        tempo_total = tempo - tempo_anterior;
        tempo_anterior = tempo;


        token = strtok(NULL, search);
        velocidade = atof(token);

        if(velocidade <= 0){
            velocidade_ms = velocidade_anterior / 3.6;
        }else{
            velocidade_ms = velocidade / 3.6;
        }

        distancia = tempo_total * velocidade_ms / 1000;
        distancia_total = distancia + distancia_anterior;
        distancia_anterior = distancia;


        velocidade_anterior = velocidade;

        if(velocidade <= 0){
            if(hora<=10)
                printf("%02d:%02d:%02d %.2f km",hora,minuto,segundo,distancia_total);
            else
                printf("%d:%02d:%02d %.2f km",hora,minuto,segundo,distancia_total);
        }

    }
    return 0;
}
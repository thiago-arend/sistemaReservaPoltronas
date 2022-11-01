#include <stdio.h>

#define FILA 8
#define CADEIRA 8

/*
(a) Dados uma fileira e uma cadeira, reserva uma poltrona ou exibe mensagem de ocupada.
(b) Também mostra ocupação do cinema de forma matricial.
(c) Dado um preço do ingresso, mostra o total arrecadado em cada fileira

Entradas: fileira, poltrona, preço
Saídas: matriz de ocupação e total arrecadado por fileira
*/

int main() {
    int p[FILA][CADEIRA] = {0}; // matriz de poltronas 8 x 8
    int f, c, cnt_venda;
    int i, j;
    float preco, tot_fileira;

    cnt_venda = 0; // contador de vendas começa em zero
    do {
        printf("\nInforme a fileira e a cadeira: ");
        scanf("%d%d", &f, &c);

        if(f == -1) {
            // apenas mostra ocupação, sem apresentar msg
        } else if(f < -1 || f >= FILA) { // se fileira fora do intervalo valido
            printf("\nFileira invalida! ");
        } else if(c < 0 || c >= CADEIRA) { // se cadeira fora do intervalo valido
            printf("\nCadeira invalida! ");
        } else { // cadeira valida

            if(p[f][c] == 0) { // se cadeira vazia
                p[f][c] = 1; // vende ingresso
                cnt_venda++; // conta mais uma venda
            } else if(p[f][c] == 1) { // se cadeira ocupada
                printf("\nCadeira ocupada! ");
            }
        }
    } while(f != -1 && cnt_venda < FILA * CADEIRA); // duas condições p/ saida do laço: fila == -1 ou cnt_venda >= FILA * CADEIRA (que resulta na lotação maxima)
    // a partir desse ponto já podemos mostrar lotação

    // formatação da representação de lugares
    printf("\n");
    printf("MAPA DE OCUPACAO DO CINEMA: \n\n");
    printf("     ");
    for(i = 0; i < CADEIRA; i++) {
        printf("P  ");
    }
    printf("\n");
    // fim da formatação de lugares

    for(i = 0; i < FILA; i++) {
        printf(" F ");
        for(j = 0; j < CADEIRA; j++) {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }

    printf("\nInforme o valor do ingresso: ");
    scanf("%f", &preco);
    for(i = 0; i < FILA; i++) { // percorre fileiras
        tot_fileira = 0;
        for(j = 0; j < CADEIRA; j++) { // percorre poltronas
            if(p[i][j]) { // se ocupada (1, true)
                tot_fileira += preco; // adiciona o valor do ingresso daquela poltrona
            }
        }
        printf("\nTotal arrecadado na fileira %d: %.2f", i, tot_fileira);
    }

    return 0;
}

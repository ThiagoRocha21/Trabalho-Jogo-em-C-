#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

void menu();
void jogar();
void ranking();
void cadastrarPalavra();
void creditos();

int main() {
    setlocale(LC_ALL, "");

    menu();

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu() {
    char option;
    do {
        system("cls"); 
        printf("          JOGO DA FORCA          ");
        printf("\n          1 - JOGAR               ");
        printf("\n          2 - RANKING             ");
        printf("\n          3 - CADASTRO DE PALAVRAS");
        printf("\n          4 - CR�DITOS            ");
        printf("\n          5 - SAIR                ");
        printf("\n			Digite o n�mero de uma op��o: ");
        fflush(stdin);
        scanf(" %c", &option);

        switch (option) {
            case '1':
                jogar ();
                break;

            case '2':
                ranking();
                break;

            case '3':
                cadastrarPalavra();
                break;

            case '4':
                creditos();
                break;

            case '5':
                break;

            default:
                printf("Op��o inv�lida.\n");
                break;
        }

        limparBuffer();
    } while (option != '5');
}

void jogar() {
	// fun��o jogo
}

void ranking() {
    // fun��o mostrar ranking 
}

void cadastrarPalavra() {
    // fun��o de cadastrar palavra 
}

void creditos() {
    printf("Feito por: Biel, Thiago, Jo�o Victor, Italo e Ant�nio.\n");
    printf("Pressione Enter para voltar ao menu.");
    limparBuffer(); // Limpar o buffer 
    getchar(); // Aguardar o Enter
}


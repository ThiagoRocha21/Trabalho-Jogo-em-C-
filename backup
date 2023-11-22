#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//#include <locale.h>

#define MAX_PALAVRA 20
#define MAX_ERROS 27
#define MAX_PALAVRAS_BANCO 5

char bancoPalavras[MAX_PALAVRAS_BANCO][MAX_PALAVRA] = {"JVGOSTOSO", "KUNK", "PATRICIA", "BIELGAY", "WALLACE"};

char palavra[MAX_PALAVRA];
char forca[MAX_PALAVRA];
char erros[MAX_ERROS];

void limparBuffer(char *buf, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        buf[i] = 0;
    }
}

int ehLetra(char c) {
    return isalpha(c);
}

char maiuscula(char c) {
    return islower(c) ? toupper(c) : c;
}

void escolherPalavraAleatoria() {
    srand(time(NULL));
    int indice = rand() % MAX_PALAVRAS_BANCO;
    strcpy(palavra, bancoPalavras[indice]);
}

void escolherPalavraManualmente() {
    printf("\nDigite uma palavra: ");
    scanf("%19s", palavra);
}

void escolherOpcaoPalavra() {
    int opcao;
    printf("\nEscolha a opção:\n");
    printf("1. PLAYER VS CPU\n");
    printf("2. PLAYER VS PLAYER\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            escolherPalavraAleatoria();
            break;
        case 2:
            escolherPalavraManualmente();
            break;
        default:
            printf("Opção inválida. Escolhendo palavra do banco.\n");
            escolherPalavraAleatoria();
    }
}

void exibirForca() {
    printf("\n%s\n", forca);
}

void exibirErros() {
    if (strlen(erros) > 0) {
        printf("Erros: %s\n", erros);
    }
}

void inicializarForca() {
    for (int i = 0; palavra[i] != 0; i++) {
        char c = palavra[i];
        forca[i] = ehLetra(c) ? '_' : c;
    }
}

void mostrarResultado(int resultado) {
    printf("\n");
    if (resultado == 0) {
        printf("Você perdeu. A palavra era %s\n", palavra);
    } else {
        printf("Parabéns, você acertou a palavra %s\n", palavra);
    }
}

void start() {
    limparBuffer(forca, MAX_PALAVRA);
    limparBuffer(erros, MAX_ERROS);
    
    escolherOpcaoPalavra();
    
    inicializarForca();

    printf("\nBem-vindo ao Jogo da Forca!\n");
}

int jogo() {
    char tentativa;
    int chances = 5;

    int letras = 0;
    for (int i = 0; palavra[i] != 0; i++) {
        if (ehLetra(palavra[i])) letras++;
    }

    while (chances > 0) {
        system("clear"); // Substitua por uma abordagem mais portátil, se necessário
        exibirForca();
        exibirErros();

        printf("\nChances: %d - a palavra tem %d letras\n", chances, letras);
        printf("\nDigite uma letra: ");
        scanf(" %c", &tentativa);

        if (!ehLetra(tentativa)) continue;

        int jaTentou = 0;
        for (int i = 0; erros[i] != 0; i++) {
            if (erros[i] == maiuscula(tentativa)) {
                jaTentou = 1;
                break;
            }
        }

        if (jaTentou) continue;

        int ganhou = 1;
        int achou = 0;
        for (int i = 0; palavra[i] != 0; i++) {
            if (!ehLetra(palavra[i])) continue;
            if (forca[i] == '_') {
                if (maiuscula(palavra[i]) == maiuscula(tentativa)) {
                    forca[i] = palavra[i];
                    achou = 1;
                } else {
                    ganhou = 0;
                }
            }
        }

        if (ganhou) {
            return 1;
        }
        if (!achou) {
            chances--;
            erros[strlen(erros)] = maiuscula(tentativa);
        }
    }

    return 0;
}

int main() {
//	setlocale(0, "portuguese");
    start();
    int resultado = jogo();
    mostrarResultado(resultado);
    return 0;
}

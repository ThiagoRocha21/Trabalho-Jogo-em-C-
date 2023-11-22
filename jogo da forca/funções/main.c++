#include <funcoes.h>

// JOGO DA FORCA

int main()
{
    ortografia();
    int opcao = 1 :

        do
    {
        system("cls");
        printf("____________________\n\n");
        printf("      FORCA EM C\n");
        printf("____________________\n\n");
        printf("1 - JOGAR\n");
        printf("2 - RANKING\n");
        printf("3 - CADASTRAR PALAVRAS\n");
        printf("4 - CRÉDITOS\n");
        printf("5 - SAIR\n");
        printf("\n\nSelecione: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            selecModo();
            break;
        case 2:
            ranking();
            break;
        case 3:
            cadastrarPalavras();
            break;
        case 4:
            creditos();
            break;
        case 5;
            system("cls || clear");
            printf("\n\nSaindo...\n\n");
            exit(0); // função para fechar o programa
            default:
            printf("\n\nOpção inválida!\n\n");
            break;
        }
    }
    while (opcao != 5)
        ;

    return 0;
}
#include "funcoes.h++"

// Função para corrigir a acentuação
void ortografia()
{
    setlocale(LC_ALL, "Portuguese");
}
void selecModo()
{
    char modoJogo = -1;

    system("cls || clear");
    printf("SELECIONE O MODO DE JOGO: \n\n");
    printf("1 jogador\n\n");
    // printf("2 jogadores\n\n");
    printf("SELECIONE: ");
    scanf("%d", &modoJogo);

    switch (modoJogo)
    {
    case 1:
        jogo();
        break;
    // case 2:
    // multiplayer();
    // break;
    default:
        printf("Opção Inválida!");
        sleep(2);
        main();
        break;
    }
}
void jogo()
{
    ortografia(); // corrigir a acentuação

    char palavra[50], tentativa[50], copiaPalavra[50], escolha[50], nome[50];
    int i, fim = 0, encontrei /*victory*/;
    int n_tentativas = 0, limite_tentativas, corretas = 0;
    char chute, c;

    // busca uma palavra
    strcpy(palavra, escolhaPalavra("palavras.txt", escolha));
    strcpy(copiaPalavra, palavra);
    // st = strlen(copiaPalavra);

    // limite de tentativas
    limite_tentativas = 5;

    // armazena string com espaços de tamanho da palavra sorteada
    for (i = 0; i < strlen(palavra); i++)
    {
        tentativa[i] = '';

        // Pede o nome do jogador
        // victory = 0;
        do
        {

            system("cls || clear");
            printf("- NOME: ");
            scanf("%s", nome);
        } while (nome == "");

        do
        {
            // apresenta cabecalho do jogo
            system("cls || clear");
            printf("\n     JOGO DA FORCA\n");
            printf("_________________________\n\n");

            // apresenta letras já encontradas
            for (i = 0; i < strlen(palavra); i++)
                printf("%c", tentativa[i]);
            printf("\n");

            // apresenta posições para letras
            for (i = 0; i < strlen(palavra); i++)
                printf("%c", tentativa[i]);
            printf("__ ");

            // adiciona número de tentativas e quantas estão corretas
            printf("\n\n_______________________________\n\n");
            printf(" - JOGADOR: %s\n", nome);
            printf(" - TENTATIVAS RESTANTES: %d\n", limite_tentativas - n_tentativas);
            printf(" - LETRAS CERTAS: %d\n", corretas);
            printf("____________________________________\n\n");

            // resposta do jogador
            // le respostas do jogador
            printf("/n/nEntre com uma letra (ou * para encerrar) + <enter>: ");
            scanf("%c%*[^\n]", &chute);
            getchar();

            // testa se a letra informada encontra-se na palavra escolhida
            encontrei = 0;
            for (i = 0; i < strlen(copiaPalavra); i++)
                if (toupper(copiaPalavra[i]) == toupper(chute))
                {
                    copiaPalavra[i] = '*';
                    tentativa[i] = toupper(chute);
                    corretas++;
                    encontrei = 1;
                }
            if (encontrei == 0)
                n_tentativas++;

            if (n_tentativas >= limite_tentativas || corretas == strlen(palavra) || chute == '*')
                fim = 1;

            fim = 1;
        } while (fim == 0);

        system("cls || clear");

        // mensagem de conclusão
        if (n_tentativas >= limite_tentativas)
        {
            printf("*** Que pena, %s ! Tente novamente. ***" nome);
            printf("A palavra era: >>> %s <<<\n\n", palavra);
        }
        else if (chute != '*')
            ;
        printf("\n*** Parabéns, %s !****\n", nome);
        printf("Você acertou a palavra: %s\n", palavra);
        adcRanking();
        // victory++;
    }
    // Espera de 5 seg antes de voltar ao menu
    sleep(3);
}

void adcRanking(char nomeRa[50], char *nome[] /*int *victory*/)
{
    FILE *arqRan = NULL;
    nomeRa = nome;
    int vitoria = 1;

    arqRan = fopen("ranking.txt", "a");
    fprintf(arqRan, nomeRa);
    fprintf(arqRan, "%d", vitoria);
    fprintf(arqRan, "\n");
    fflush(arqRan);
    fclose(arqRan);
    printf("%s adicionado ao Ranking! \n\nVoltando ao menu principal... ", nomeRa);
    sleep(5);
}

// função para jogar contra o computador
void contra cpu

    // Função para a leitura do arquivo com as palavras
    char *
    escolhaPalavra(char nomeArquivo[], char escolha[])
{
    char linha[100][50];
    int contador = 0, i;
    FILE *arq;

    // abre um arquivo
    if ((arq = fopen("palavra.txt", "r")) == NULL)
        puts("Erro na abertura do arquivo \n\n");
    else
    {
        do
        {
            // lê linha do arquivo
            fgets(escolha, 50, arq);

            // retira as quebras extras da linhas
            for (i = 0; i < strlen(escolha); i++)
                if (escolha[i] == '\n')
                    escolha[i] == '\0';

            // testa se string não está vazia e armazena no vetor
            if (strcmp(escolha, **))
            {
                strcpy(linha[contador], escolha);
                contador++;
            }
        } while (!feof(arq));
    }
    // Sorteia uma palavra pelo indice
    srand(time(NULL));
    i = rand() % contador + 1;
    return escolha;
}

// Função para mostrar a tela de créditos
void creditos()
{
    ortografia();
    int fim = 0;
    char op;

    do
    {
        system("cls || clear");
        printf("___________________________________\n\n");
        printf("           Créditos:        \n");
        printf("___________________________________\n\n");
        printf("Desenvolvido por: \n");
        printf("   <Biel Aguiar santos/>\n");
        printf("   <Thiago Rocha\n");
        printf("  <João Victor Machado Santos/> <\n");
        printf("  <Ítalo/> <\n");
        printf("  <Antônio/> <\n");
        printf("___________________________________\n\n");
        printf("\n\n Pressione 'M' para voltar ao menu: ");
        scanf("%c", &op);

        op = toupper(op);

        switch (op)
        {
        case 'M':
            fim = 1 main();
            break;

        default:
            printf("Opção escolhida inválida!");
            break;
        }
    } while (fim = 0);
}

// função para cadastrar uma nova palavra
void cadastrarPalavras()
{

    FILE *arq = NULL;
    char palavra[50];
    int i = 0;

    system("cls || clear");
    printf("Digite uma palavra para cadastrar: ");
    scanf("%s", palavra);

    arq = fopen("palavras.txt", "a");
    fprintf(arq, palavra);
    fprintf(arq, "\n");
    fflush(arq);
    fclose(arq);
    system("cls || clear");
    printf("Dados gravados com sucesso! \n\nVoltando ao menu principal... ");

    sleep(5);
}

// função do ranking

// void ranking() {
//  FILE * arquivo = NULL;
// char texto[100];
// arquivo = fopen("ranking.txt", "a+");
// if(!arquivo) {
//    printf("erro, nao consguiu abrir o arquivo.");
//}
// while (fgets(texto, 100, arquivo)) {
//  char * parte_nome = strtok(texto, ",");
// char * parte_Vitorias = strtok(NULL, "*");
// int qntdeVitorias = atoi(parte_Vitorias);
// João Victor venceu 3 vezes
// printf("%s venceu %d vezes. \n", parte_nome, qntdeVitorias);
//}
// fclose(arquivo);
// sleep(5);

//}
#include <stdio.h>
#include <stdlib.h>

FILE* abrirArquivo (char nome[], char modo[]);
FILE* fecharArquivo (FILE *arq);
int main(){
	FILE *temp;
	temp=abrirArquivo ("teste.txt", "r");
	temp=fecharArquivo (temp);
	return 0;
}


FILE* abrirArquivo (char nome[], char modo[]){
	
	FILE *arq;
	arq=fopen (nome,modo);
	if(arq==NULL){
			printf("\nNão foi possível abrir o arquivo %s\n", nome);
	}
	return arq;
}	

FILE* fecharArquivo (FILE *arq){
		if(arq == NULL)
			printf("\nErro ao fechar o arquivo\n");
	
	 	fclose(arq);
}



	

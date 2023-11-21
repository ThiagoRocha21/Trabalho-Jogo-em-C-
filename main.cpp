#include <iostream>
#include <stdlib.h>


using namespace std;
// está array unidimensional: A variável "palavra" é a palavra secreta, "letra" armazena a letra que a pessoa digitar e "secreta" contém a palavra conforme for desvendada
int main() {
	
	char palavra[30], letra[1],secreta[30]; 
	int tam,i,chances,acertos;
	bool acerto=false;
	
	chances=6;
	tam=0;
	i=0;
	acerto=false;
	acertos=0;
	
	cout << "Fale para seu amigo tampar os olhos e digite a palavra secreta: ";
	cin >> palavra;
	system("cls");
//essa função do barra zero serve para indicar que após o enter é onde a string terminou ali
	while(palavra[i] != '\0'){
		i++;
		tam++;
	}
//o vetor secreta serve para aparecer os tracinhos para os caracteres e substitui pela letra que vc acertou. Serve para a estética do jogo
	for(i=0;i<30;i++){
		secreta[i]='_';
	}
//esse while é o loop principal do jogo	
	while((chances > 0)&&(acertos < tam)){
		cout << "Chances restantes: " << chances << "\n\n";
		cout << "Palavra secreta: ";
		for(i=0; i<tam; i++){
			cout << secreta[i];
		}
		cout << "\n\nDigite uma letra: ";
		cin >> letra[0];
		for(i=0; i<tam; i++){
			if(palavra[i]==letra[0]){
				acerto=true;
				secreta[i]=palavra[i];
				acertos++;
			}
		}
		if(!acerto){
			chances--;
		}
		acertos=false;
		system("cls");
	}
	
	if(acertos==tam){
		cout << "Você venceu";
	}else{
		cout << "Que pena, você perdeu!";
	}
	
	system("pause");
	return 0; 
	
}


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main()
{
	char palavra[4],jogo[4]={'?','?','?','?'},letra,res[4];
    int cont=1,descobriu=0,i,f;

	
	printf("\nBem vindo ao jogo da velha!\n");
	printf("Regras: \n");
	printf("O jogador 1 Escrevera uma palavra de ate 4 digitos\n");
	printf("O jogador 2 tera 7 tentativas para advinha a palavra,\n");
	printf("Escrevendo uma letra por tentativa.\n");
	printf("\n\n\n\n\n\n\n\n\n\nVamos Comecar!\n\n\n\n\n\n\n\n\n\n\n\n");
	system("pause");
	printf("\e[1;1H\e[2J"); /*função para passar a tela*/

	printf("\n\n\n\nJogador 1, digite a palavra a ser descoberta: ");
	scanf("%s",palavra);
	
	if (strlen(palavra) != 4) {
		do
		{
			printf("\nA palavra que voce digitou não tem 4 letras. \n");
			printf("\nPor favor, digite a palavra novamente!: ");
			scanf("%s",palavra);
		} while (strlen(palavra) != 4);
		
	}
	printf("\nOtimo!, agora passe para o jogador 2\n\n\n\n\n");
	system("pause");
	
	printf("\e[1;1H\e[2J"); /*função para passar a tela*/
	printf("\nJogador 2, Sua vez!\n");
	printf("\n\n\n\nATENÇÃO JOGADOR 2\n\n\n\n");
	printf(" | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |");
	printf("\nSe voce digitar mais de uma letra, cada letra a mais sera contada como uma tentativa!!\n");
	printf("Entao, use somente uma letra por tentativa!!\n");
	printf(" | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | \n\n\n");
	system("pause");
	printf("\e[1;1H\e[2J"); /*função para passar a tela*/

	while(cont <= 7){
		printf("\ndigite uma letra: ");		
		scanf(" %c",&letra);
		
		while (letra==jogo[0] || letra==jogo[1] || letra==jogo[2] || letra==jogo[3]){
			printf("\n\nA letra digitada ja foi descoberta! digite outra letra!\n ");
			printf("\ndigite uma letra: ");		
			scanf(" %c",&letra);
		}
		

		for(i = 0; i < strlen(palavra); i++){

			if (letra==palavra[i]) {
				jogo[i]=letra;
				descobriu=1;
				printf("\nVoce Descobriu a Letra %c na %d posicao da palavra! \n", letra, i+1);
				printf("\nVoce ainda tem %d tentativas!", 7-cont);	
			}			
		}
		
		if (descobriu == 0) {
			printf("\nVoce não descobriu nenhuma letra!\n");
			printf("\nVoce ainda tem %d tentativas!", 7-cont);
		}
		
		if (jogo[0] != '?' && jogo[1] != '?' && jogo[2] != '?' && jogo[3] != '?') {
			printf("\n Parabens! Voce descobriu a palavra!\n");
			printf("\nA palavra era : ");
			printf("%s", jogo);
			return 0;
		}

		if (cont==7) {
			printf("\e[1;1H\e[2J"); /*função para passar a tela*/
			printf("\n\n\n\n\nVoce usou todas as tentativas!\n");
			printf("\nO jogo ficou assim: \n");
			printf("%c - %c - %c - %c\n", jogo[0], jogo[1], jogo[2], jogo[3]);
			printf("\n\nAgora, Tente advinhar a palavra!\n\n");
			printf("\nDigite a palavra: ");
			scanf("%s",res);
			
			if (res[0]==palavra[0] && res[1]==palavra[1] && res[2]==palavra[2] && res[3]==palavra[3]){
				printf("\nParabens! Jogador 2 advinhou a palavra e ganhou!\n");
				printf("\nA palavra era :  ");
				printf("%s", palavra);
				printf("\n Jogador 2 digitou :  ");
				printf("%s", res);
				return 0;

			}
			else {
				printf("\nParabens Jogador 1, voce ganhou! O jogador 2 não adivinhou a palavra!\n");
				printf("\nA palavra era :  ");
				printf("%s", palavra);
				printf("\n Jogador 2 digitou :  ");
				printf("%s", res);
				return 0;
			}
		}
		

		printf("\nPor enquanto o jogo esta assim: \n");
		printf("%c - %c - %c - %c\n", jogo[0], jogo[1], jogo[2], jogo[3]);
		
		
		descobriu=0;
		cont++;
	}
	
			
		
	return 0;
}



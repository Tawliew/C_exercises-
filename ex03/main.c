#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num1=0, num2=0, venc=0;
	char palavra;
	
	printf("Bem vindo ao jogo do par e impar digital \n");
	printf("Escolha seu lado pela primeira letra \n");
	printf("Por favor, jogador 1, Escolha: (P)ar ou (I)mpar?  \n");
	scanf("%c",&palavra);
	palavra=toupper(palavra);
	
	
	switch ( palavra ) {
		
		case 'P':
			printf("Jogador 1 escolheu par \n");
			printf("Jogador 2 escolheu impar \n");
			printf("\n");
			printf("Jogador 1, digite seu numero(INTEIRO):  \n");
			scanf("%d", &num1);
			printf("Agora, digite seu numero jogador 2:   \n");
			scanf("%d", &num2);
			venc=num1+num2;
			if(venc % 2 == 0){
				printf("Jogador 1 escolheu o numero %d \n", num1);
				printf("Jogador 2 escolheu o numero %d \n", num2);
				printf("A soma dos dois numeros e da %d, que e um numero par. Jogador 1 Venceu! \n", venc);
				return 0;
			}
			else {
				printf("Jogador 1 escolheu o numero %d \n", num1);
				printf("Jogador 2 escolheu o numero %d \n", num2);
				printf("A soma dos dois numeros e da %d, que e um numero impar. Jogador 2 Venceu! \n", venc);
				return 0;
			}
		
		case 'I':
			printf("Jogador 1 escolheu impar \n");
			printf("Jogador 2 escolheu par \n");
			printf("\n");
			printf("Jogador 1, digite seu numero(INTEIRO):  \n");
			scanf("%d", &num1);
			printf("Agora, digite seu numero jogador 2(INTEIRO):   \n");
			scanf("%d", &num2);
			venc=num1+num2;
			if(venc % 2 == 0){
				printf("Jogador 1 escolheu o numero %d \n", num1);
				printf("Jogador 2 escolheu o numero %d \n", num2);
				printf("A soma dos dois numeros e da %d, que e um numero par. Jogador 2 Venceu! \n", venc);
				return 0;
			}
			else {
				printf("Jogador 1 escolheu o numero %d \n", num1);
				printf("Jogador 2 escolheu o numero %d \n", num2);
				printf("A soma dos dois numeros e da %d, que e um numero impar. Jogador 1 Venceu! \n", venc);
				return 0;
			}
		
		default:
			printf("Valor invalido. Saindo...");
			return 0;
		
	}
		
	
	
	return 0;
}

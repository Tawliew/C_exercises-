#include <stdio.h>
#include <stdlib.h>

/* ruasdasn this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int dist_z=0, circuito=0;
	float vel=0, tempo=0;
	
	printf("Ola! Vamos calcular o tempo, em segundos, que um carro de corrida vai demorar para concluir um circuito.");
	printf("\n");
	printf("Vamos comecar!");
	printf("\n");
	printf("Digite a distancia do trecho Z(em metros): ");
	scanf("%d", &dist_z);
	
	if (dist_z > 750) {
		do
		{
			printf("\n\nDistancia digitada menor que 750m! \n\n");
			printf("\n\nPor favor, digite um numero menor que 750: ");
			scanf("%d", &dist_z);
		
		} while (dist_z > 750);
	}
	printf("\n");
	printf("Ok!");
	printf("\n");
	printf("Agora, digite a velocidade que o carro est� (em m/s): ");
	scanf("%f", &vel);
	printf("\n");
	if(vel < 27.7) {
		do
		{
			printf("\n\nVelocidade menor que 27.7 m/s! \n\n");
			printf("\n\nPor favor, digite um numero maior que 27.7: ");
			scanf("%f", &vel);
		
		} while (vel < 27.7);
	}
	printf("\nOtimo!\n");
	circuito=dist_z+750+200+300+1500;
	tempo=circuito/vel;
	printf("\nO carro, andando num circuito de %d metros a uma velocidade %.2f o terminara em %.1f segundos",circuito,vel,tempo);
	
	
	
	return 0;
}

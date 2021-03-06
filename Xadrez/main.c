#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tabuleiro[10][10]=
	{
	'-', '1', '2', '3', '4', '5', '6', '7', '8', '-',
	'1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't', '|',
	'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '|',
	'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
	'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
	'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
	'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
	'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '|',
	'8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T', '|',
	'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'
};

int mover=0, ganhar=0;
	
void jogador1();
void jogador2();
void win();
	
void main(){
	while(ganhar==0){

		do
		{
			mover=0;
			printf("\nJogador 1, sua vez!\n");
			jogador1();
		} while (mover==0);
		
		
		printf("\njogador 2, sua vez!\n");
		jogador2();

	}
}
	
/*Codigo começa aqui */

void jogador1(){
	int pesa,x,y,z,h,t,i;
	int num1, num2;
	unsigned int l,c; //Para as variaveis não se tornarem negativas 
	
		/*exibe o tabuleiro*/
	for(t=0; t<10; ++t){
		for(i=0; i<10; ++i){
			printf("%3c",tabuleiro[t][i]);
		}
		printf("\n");
	}
	
	printf("Digite a peca que deseja movimentar no tabuleiro inferior (ex: coluna:1, linha: 7): ");
	scanf("%d%d",&z,&h);
	
	/* Movimento das Peças */
	
	/*TORRE*/

	if(tabuleiro[z][h]=='T'){
		
		int cont=1;
		/*cima*/
		l=z-1;
		c=h; 
		if(tabuleiro[l][c] ==' ' ){
			while(tabuleiro[l][c] == ' '){
				tabuleiro[l][c]='x';
				l=l-1;
				cont++;
			}
		} 
		
		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				cont++;
			}
		} 
	
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c-1;
				cont++;
			}
		} 
	
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c+1;
				cont++;
			}
		}
		
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
		
		
		if(tabuleiro[x][y]=='x'){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
						mover=1;
					}
				}
			}
		}
		
		else if((tabuleiro[x][y]=='p') || (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') || (tabuleiro[x][y]=='k')){
			
			/* CIMA */
			num2=h;
			num2=cont-num2;
			if(tabuleiro[z][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}

			/* BAIXO */
			num2=h;
			num2+=cont;
			if(tabuleiro[z][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}

			/* ESQUERDA */
			num1=z;
			num1-=cont;
			if(tabuleiro[num1][h]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}
			
			/* DIREITA */
			num1=z;
			num1+=cont;
			if(tabuleiro[num1][h]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}
			/* Looping para tirar os "X" */
			else{
				for(t=0; t<10; ++t){
					for(i=0; i<10; ++i){
						if(tabuleiro[t][i]=='x'){
							tabuleiro[t][i]=' ';
						}
					}
				}
			}

		}

		/* Looping para tirar os "X" */
		else{
			for(t=0; t<10; ++t){
					for(i=0; i<10; ++i){
						if(tabuleiro[t][i]=='x'){
							tabuleiro[t][i]=' ';
						}
					}
			}
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	/*CAVALO*/
	if (tabuleiro[z][h]=='C') {
		
		/*cima esquerda*/
		l=z-2;
		c=h-1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*baixo esquerda*/
		l=z+2;
		c=h-1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*cima direita*/
		l=z-2;
		c=h+1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*baixo direito*/
		l=z+2;
		c=h+1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*esquerda baixo*/
		l=z+1;
		c=h-2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*esquerda cima*/
		l=z-1;
		c=h-2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*direita baixo*/
		l=z+1;
		c=h+2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*direita cima*/
		l=z-1;
		c=h+2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
			
		printf("Digite o local que deseja movimentar a peca: ");
		scanf("%d%d",&x,&y);
			
		if  ((tabuleiro[x][y]=='x')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
						mover=1;
					}
				}
			}
		}

		else if((tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p') || (tabuleiro[x][y]=='k')){
			
			/*Verificação para comer peça*/
			
			/*L - CIMA ESQUERDA */
			num1=z;
			num2=h;
			num1-=2;
			num2-=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}


			/* L CIMA DIREITA */
			num1=z;
			num2=h;
			num1-=2;
			num2+=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}

			/* L BAIXO ESQUERDA */
			num1=z;
			num2=h;
			num1+=2;
			num2-=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}

			/* L BAIXO DIREITA */
			num1=z;
			num2=h;
			num1+=2;
			num2+=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}
			
			/* Looping para tirar os "X" */
			else{
				for(t=0; t<10; ++t){
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x'){
								tabuleiro[t][i]=' ';
							}
						}
				}
			}
		}
		
		/* Looping para tirar os "X" */
		else{
			for(t=0; t<10; ++t){
					for(i=0; i<10; ++i){
						if(tabuleiro[t][i]=='x'){
							tabuleiro[t][i]=' ';							}
						}
					}
			}
	}
	
	
	///////////////////////////////////////////////////////////////////////////////
	
	
	/*BISPO*/
	if (tabuleiro[z][h]=='B'){
		
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c+1;
			}
		}
		
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c-1;
			}
		}
		
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c+1;
			}
		}
		
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c-1;
			}
		}
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
		
		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
	 
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}
		
		else{

			printf("%3c",tabuleiro[t][i]);
			printf("\n");

		}
		
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	
	/*RAINHA*/
	if (tabuleiro[z][h]=='Q'){
		
		/*cima*/
		l=z-1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
			}
		} 
		
		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
			}
		} 
		
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c-1;
			}
		} 
		
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c+1;
			}
		} 
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c+1;
			}
		}
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c-1;
			}
		}
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c+1;
			}
		}
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c-1;
			}
		}
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca: ");
		scanf("%d%d",&x,&y);
		
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t) {
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
					tabuleiro[t][i]=' ';
					}
				}
			}
		}

		else{
			printf("%3c",tabuleiro[t][i]);
			printf("\n");
		}
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	
	/*REI*/
	if (tabuleiro[z][h]=='K'){
		
		/*cima*/
		l=z-1;
		c=h; 
		if (tabuleiro[l][c] ==' '){
			tabuleiro[l][c]='x';
		}

		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		} 
		
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
		
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}
		else{
			printf("%3c",tabuleiro[t][i]);
			printf("\n");

		}
		
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	/*PEAO*/

	if (tabuleiro[z][h]=='P'){
		if (z==7){
			
			/*cima*/
			l=z-2;
			c=h; 
			
			if (tabuleiro[l][c] ==' ') {
				tabuleiro[l][c]='x';
			}
			
			l=z-1;
			c=h;
			
			if (tabuleiro[l][c] ==' ') {
				tabuleiro[l][c]='x';
			}	
		}
		else{
			
			/*CIMA*/
			if(tabuleiro[z][h]=='P'){
				l=z-1;
				c=h; 
				if(tabuleiro[l][c] ==' ' ){
					tabuleiro[l][c]='x';
				}
			}
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */	
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
			
		printf("Digite o local que deseja movimentar a peca: ");
		scanf("%d%d",&x,&y);
	
		if(tabuleiro[x][y]=='x'){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
						mover=1;
					}
				}
			}
		}

		else if((tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p') || (tabuleiro[x][y]=='k')){
			
			/*Verificação se pode comer a peça*/
			/*DIAGONAL CIMA/DIREITA*/
			num1=z;
			num2=h;
			num1-=1;
			num2+=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}
					
			
			/*DIAGONAL CIMA/ESQUERDA*/
			num1=z;
			num2=h;
			num1-=1;
			num2-=1;
			
			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
								mover=1;
							}
						}
					}
			}

			
			/* Looping para tirar os "X" */
			else{
				for(t=0; t<10; ++t){
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x'){
								tabuleiro[t][i]=' ';
							}
						}
				}
			}
		}
		/* Looping para tirar os "X" */
		else{
				for(t=0; t<10; ++t){
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x'){
								tabuleiro[t][i]=' ';
							}
						}
				}
		}
	}
}

	

void jogador2(){
	int pesa,x,y,z,h,t,i;
	unsigned int l,c; //Para as variaveis não se tornarem negativas 
	
		/*exibe o tabuleiro*/
	for(t=0; t<10; ++t){
		for(i=0; i<10; ++i){
			printf("%3c",tabuleiro[t][i]);
		}
		printf("\n");
		/*hue */
	}
	
	printf("Digite a peca que deseja movimentar no tabuleiro inferior (ex: coluna:1, linha: 7)");
	scanf("%d%d",&z,&h);
	
	/* Movimento das Peças */
	
	/*TORRE*/

	if(tabuleiro[z][h]=='t'){
		
		
		/*cima*/
		l=z-1;
		c=h; 
		if(tabuleiro[l][c] ==' ' ){
			while(tabuleiro[l][c] == ' '){
				tabuleiro[l][c]='x';
				l=l-1;
			}
		} 
		
		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
			}
		} 
	
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c-1;
			}
		} 
	
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c+1;
			}
		}
		
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
		/* AJUSTAR "COMIDA" */
		
		if ((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p') ||  (tabuleiro[x][y]=='k')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			
			/*PROGRAMAR A "COMIDA" DO REI*/
			for(t=0; t<10; ++t) {
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
							tabuleiro[t][i]=' ';
					}
				}
			}
		}
		
		else {
			/* ajustar isso */
			printf("%3c",tabuleiro[t][i]);
			printf("\n");
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////
	
	/*CAVALO*/
	if (tabuleiro[z][h]=='c') {
		
		/*cima esquerda*/
		l=z-2;
		c=h-1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*baixo esquerda*/
		l=z+2;
		c=h-1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*cima direita*/
		l=z-2;
		c=h+1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*baixo direito*/
		l=z+2;
		c=h+1;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*esquerda baixo*/
		l=z+1;
		c=h-2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*esquerda cima*/
		l=z-1;
		c=h-2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
	
		/*direita baixo*/
		l=z+1;
		c=h+2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}
		
		/*direita cima*/
		l=z-1;
		c=h+2;
		if(tabuleiro[l][c]==' '){
			tabuleiro[l][c]='x';
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
			
		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
			
		if  ((tabuleiro[x][y]=='x') |  (tabuleiro[x][y]=='t')  |  (tabuleiro[x][y]=='c')  |  (tabuleiro[x][y]=='b')  |  (tabuleiro[x][y]=='q') |  (tabuleiro[x][y]=='p')) {
			/*Adicionar Rei e fazer o cheque*/
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t) {
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}

		else{
			printf("%3c",tabuleiro[t][i]);
			printf("\n");
		}
	}
	
	
	///////////////////////////////////////////////////////////////////////////////
	
	
	/*BISPO*/
	if (tabuleiro[z][h]=='b'){
		
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c+1;
			}
		}
		
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c-1;
			}
		}
		
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c+1;
			}
		}
		
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c-1;
			}
		}
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
		
		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
	 
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}
		
		else{

			printf("%3c",tabuleiro[t][i]);
			printf("\n");

		}
		
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	
	/*RAINHA*/
	if (tabuleiro[z][h]=='q'){
		
		/*cima*/
		l=z-1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
			}
		} 
		
		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
			}
		} 
		
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c-1;
			}
		} 
		
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				c=c+1;
			}
		} 
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c+1;
			}
		}
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l-1;
				c=c-1;
			}
		}
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c+1;
			}
		}
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			while(tabuleiro[l][c] == ' ') {
				tabuleiro[l][c]='x';
				l=l+1;
				c=c-1;
			}
		}
		
		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca: ");
		scanf("%d%d",&x,&y);
		
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t) {
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
					tabuleiro[t][i]=' ';
					}
				}
			}
		}

		else{
			printf("%3c",tabuleiro[t][i]);
			printf("\n");
		}
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	
	/*REI*/
	if (tabuleiro[z][h]=='k'){
		
		/*cima*/
		l=z-1;
		c=h; 
		if (tabuleiro[l][c] ==' '){
			tabuleiro[l][c]='x';
		}

		/*baixo*/
		l=z+1;
		c=h; 
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*esquerda*/
		l=z;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		} 
		
		/*direita*/
		l=z;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*cima direita*/
		l=z-1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*cima esquerda*/
		l=z-1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*baixo direita*/
		l=z+1;
		c=h+1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}
		
		/*baixo esquerda*/
		l=z+1;
		c=h-1;
		if (tabuleiro[l][c] ==' ' ) {
			tabuleiro[l][c]='x';
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */
		for(t=0; t<10; ++t){
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}

		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
		
		if((tabuleiro[x][y]=='x') ||  (tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p')){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}
		else{
			printf("%3c",tabuleiro[t][i]);
			printf("\n");

		}
		
	}
	
	
	////////////////////////////////////////////////////////////////////////////////
	
	/*PEAO*/
	if (tabuleiro[z][h]=='p'){
		if (z==7 || z==2){
			
			/*cima*/
			l=z-2;
			c=h; 
			
			if (tabuleiro[l][c] ==' ') {
				tabuleiro[l][c]='x';
			}
			
			l=z-1;
			c=h;
			
			if (tabuleiro[l][c] ==' ') {
				tabuleiro[l][c]='x';
			}
			
			/*baixo*/
			l=z+2;
			c=h;
			if(tabuleiro[l][c]==' '){
				tabuleiro[l][c]='x';
			}
			l=z+1;
			c=h;
			if(tabuleiro[l][c]==' '){
				tabuleiro[l][c]='x';
			}
		}
		else{
			/*CIMA*/
			if(tabuleiro[z][h]=='P'){
				l=z-1;
				c=h; 
				if (tabuleiro[l][c] ==' ' ){
					tabuleiro[l][c]='x';
				}
			}
			
			/*BAIXO*/
			if(tabuleiro[z][h]=='p'){
				l=z+1;
				c=h; 
				if (tabuleiro[l][c] ==' ' ){
					tabuleiro[l][c]='x';
				}
			}
		}

		/* MOSTRAR TABULEIRO APÓS OS "X" */	
		for(t=0; t<10; ++t) {
			for(i=0; i<10; ++i){
				printf("%3c",tabuleiro[t][i]);
			}
			printf("\n");
		}
			
		printf("Digite o local que deseja movimentar a peca ");
		scanf("%d%d",&x,&y);
	
		if(tabuleiro[x][y]=='x'){
			tabuleiro[x][y]=tabuleiro[z][h];
			tabuleiro[z][h]=' ';
			for(t=0; t<10; ++t){
				for(i=0; i<10; ++i){
					if(tabuleiro[t][i]=='x') {
						tabuleiro[t][i]=' ';
					}
				}
			}
		}

		else if((tabuleiro[x][y]=='t')  ||  (tabuleiro[x][y]=='c')  ||  (tabuleiro[x][y]=='b')  ||  (tabuleiro[x][y]=='q') ||  (tabuleiro[x][y]=='p') || (tabuleiro[x][y]=='k') 
		|| (tabuleiro[x][y]=='T')  ||  (tabuleiro[x][y]=='C')  ||  (tabuleiro[x][y]=='B')  ||  (tabuleiro[x][y]=='Q') ||  (tabuleiro[x][y]=='P') || (tabuleiro[x][y]=='K')){
			
			int num1, num2;
			/*Pulo do gato*/
			/*DIAGONAL CIMA/DIREITA*/
			num1=z;
			num2=h;
			num1-=1;
			num2+=1;

			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
							}
						}
					}
			}
					
			
			/*DIAGONAL CIMA/ESQUERDA*/
			num1=z;
			num2=h;
			num1-=1;
			num2-=1;
			
			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
							}
						}
					}
			}

			/*DIAGONAL BAIXO/DIREITA*/
			num1=z;
			num2=h;
			num1+=1;
			num2-=1;
			
			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x') {
								tabuleiro[t][i]=' ';
							}
						}
					}
			}
			
			/*DIAGONAL BAIXO/ESQUERDA*/
			num1=z;
			num2=h;
			num1+=1;
			num2+=1;
			
			if(tabuleiro[num1][num2]==tabuleiro[x][y]){
					tabuleiro[x][y]=tabuleiro[z][h];
					tabuleiro[z][h]=' ';
					for(t=0; t<10; ++t) {
						for(i=0; i<10; ++i){
							if(tabuleiro[t][i]=='x'){
								tabuleiro[t][i]=' ';
							}
						}
					}
			}
		}
	}
}

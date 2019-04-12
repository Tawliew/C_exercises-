#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(){
   
   
   char velha[4][4] = {{'1','2','3','4'},{'5','-','-','-'},{'9','-','-','-'},{'d','-','-','-'}};
   int lin=1,col=1,i=0,j=0,jogador=1,vencedor=0;

    printf("Bem vindo ao jogo da velha!\n");
    printf("O primeiro jogador começa com 'X', e o segundo com 'O'\n");
    printf("Vamos Comecar!\n");


    while (vencedor != 1) {
        

        for(i = 1; i<4; i++){
            for(j = 1; j<4; j++){
            printf("%c\t", velha[i][j]);
            }
            printf("\n");
        }

        printf("\n\n\nO jogo da velha está assim: \n");
        printf("\n\nAgora é a vez do jogador %d\n", jogador);
        printf("\n\ndigite uma posicao na linha: ");
        scanf("%d", &lin);
        printf("\n");
        printf("\n\ndigite uma posicao na coluna: ");
        scanf("%d", &col);
        printf("\n\n\n\n\n\n\n\n\n");

        while(velha[lin][col] == 'X' || velha[lin][col] == 'O'){
            printf("\nEspaco ja foi usado!\n");
            printf("\nPor favor, digite novamente em um outro local!\n");
            printf("digite uma posicao na linha: ");
            scanf("%d", &lin);
            printf("\n");
            printf("digite uma posicao na coluna: ");
            scanf("%d", &col);
            printf("\n\n\n\n\n\n\n\n\n");
        }
        
        

        if (velha[lin][col] != '-'){
            printf("Espaço ocupado, por favor, insira em outro local. \n");
            break;
        }
        
        if(jogador % 2 == 0 ){
            velha[lin][col]='X';
        } else if (jogador % 2 !=0) {
            velha[lin][col]='O';
        }
        if(velha[1][1]=='X' && velha[2][2]=='X' && velha[3][3]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][1]=='O' && velha[2][2]=='O' && velha[3][3]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][3]=='X' && velha[2][2]=='X' && velha[3][1]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][3]=='O' && velha[2][2]=='O' && velha[3][1]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
               
               
                /*para quando o vencedor ganhar cruzando */


        else if(velha[1][1]=='O' && velha[1][2]=='O' && velha[1][3]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][1]=='X' && velha[1][2]=='X' && velha[1][3]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
         /*se ganhar na 1º linha */
        
        else if(velha[2][1]=='O' && velha[2][2]=='O' && velha[2][3]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[2][1]=='X' && velha[2][2]=='X' && velha[2][3]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
        /*se ganhar na 2º linha */
        
        else if(velha[3][1]=='O' && velha[3][2]=='O' && velha[3][3]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[3][1]=='X' && velha[3][2]=='X' && velha[3][3]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
        /*se ganhar na 3º linha */

        else if(velha[1][1]=='O' && velha[2][1]=='O' && velha[3][1]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][1]=='X' && velha[2][1]=='X' && velha[3][1]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
        /*se ganhar na 1º coluna */
        
        else if(velha[1][2]=='O' && velha[2][2]=='O' && velha[3][2]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        else if(velha[1][2]=='X' && velha[2][2]=='X' && velha[3][2]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
        /*se ganhar na 2º coluna */

        else if(velha[1][3]=='O' && velha[2][3]=='O' && velha[3][3]=='O'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;   
        }
        else if(velha[1][3]=='X' && velha[2][3]=='X' && velha[3][3]=='X'){
            for(i = 1; i<4; i++){
                for(j = 1; j<4; j++){
                    printf("%c\t", velha[i][j]);
                }
                printf("\n");
            }   
            printf("\n\n\n\n\njogador %d ganhou!", jogador);
            vencedor=1;
            return 0;
        }
        
        /*se ganhar na 3º coluna */

        else if (
            velha[1][1] != '-' && 
            velha[1][2] != '-' &&
            velha[1][3] != '-' &&
            velha[2][1] != '-' &&
            velha[2][2] != '-' && 
            velha[2][3] != '-' && 
            velha[3][1] != '-' &&
            velha[3][2] != '-' && 
            velha[3][3] != '-' )
        {
            printf("Nenhum vencedor! \n");
            printf("Saindo... \n");
            return 0;
        }

        /* caso ninguem ganhe */

        jogador=jogador%2;
        jogador++;

    
    
    }

return 0;
}
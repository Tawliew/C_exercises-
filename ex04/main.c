#include <stdio.h>

int main() {
    
    char numero[2];


    printf("Ola! Digite um numero de 0 a 100: ");
    scanf("%s", &numero);


    if (numero[0] == '1' && numero[1]=='0' && numero[2]=='0') {
        printf("%s -> Cem", numero);
        return 0;
    }
    else if(numero[2] != '\0'){
        if(numero[2] > '0'){
            printf("Não conseguimos identificar seu numero. Por favor, digite um numero de 0 a 100");
            return 0;
        }
        
        printf("Não conseguimos identificar seu numero. Por favor, digite um numero de 0 a 100");
        return 0;
    }



    switch( numero[0] ) {
        
        case '0':
            if(numero[1] != '\0'){
                printf("%c -> ", numero[1]);
                break;
            }
            printf("&s -> Zero", numero);
            break;
        case '1':
            if(numero[1] == '\0'){
                printf("%c -> Um", numero[0]);
                return 0;
            }
            else if(numero[1]=='0'){
                printf("%s -> Dez", numero);
                return 0;
            }
            else if(numero[1] == '1'){
                printf("%s -> Onze", numero);
                return 0;
            }
            else if(numero[1] == '2'){
                printf("%s -> Doze", numero);
                return 0;
            }
            else if(numero[1] == '3'){
                printf("%s -> Treze", numero);
                return 0;
            }
            else if(numero[1] == '4'){
                printf("%s -> Quatorze", numero);
                return 0;
            }
            else if(numero[1] == '5'){
                printf("%s -> Quinze", numero);
                return 0;
            }
            else if(numero[1] == '6'){
                printf("%s -> Dezesseis", numero);
                return 0;
            }
            else if(numero[1] == '7'){
                printf("%s -> Dezessete", numero);
                return 0;
            }
            else if(numero[1] == '8'){
                printf("%s -> Dezoito", numero);
                return 0;
            }
            else if(numero[1] == '9'){
                printf("%s -> Dezenove", numero);
                return 0;
            }


        case '2':
            if(numero[1] == '\0'){
                printf("%c -> Dois", numero[0]);
                return 0;
            } else {
                printf("%s -> Vinte e ", numero);
                break;
            }
        case '3':
            if(numero[1] == '\0'){
                printf("%c -> Tres", numero[0]);
                return 0;
            } else {
                printf("%s -> Trinta e ", numero);
                break;
            }
        case '4':
            if(numero[1] == '\0'){
                printf("%c -> Quatro", numero[0]);
                return 0;
            } else {
                printf("%s -> Quarenta e ", numero);
                break;
            }
        case '5':
            if(numero[1] == '\0'){
                printf("%c -> Cinco", numero[0]);
                return 0;
            } else {
                printf("%s -> Cinquenta e ", numero);
                break;
            }
        case '6':
            if(numero[1] == '\0'){
                printf("%c -> Seis", numero[0]);
                return 0;
            } else {
                printf("%s -> Sessenta e ", numero);
                break;
            }
        case '7':
            if(numero[1] == '\0'){
                printf("%c -> Sete", numero[0]);
                return 0;
            } else {
                printf("%s -> Setenta e ", numero);
                break;
            }
        case '8':
            if(numero[1] == '\0'){
                printf("%c -> Oito", numero[0]);
                return 0;
            } else {
                printf("%s -> Oitenta e ", numero);
                break;
            }
        case '9':
            if(numero[1] == '\0'){
                printf("%c -> Um", numero[0]);
                return 0;
            } else {
                printf("%s -> Noventa e ", numero);
                break;
            }
        default:
            printf("Numero digitado incorreto");
            return 0;    
    
    
    
    }

    switch (numero[1])
    {
        case '1':
            printf("Um");
            break;
        
        case '2':
            printf("Dois");
            break;

        case '3':
            printf("Tres");
            break;

        case '4':
            printf("Quatro");
            break;

        case '5':
            printf("Cinco");
            break;

        case '6':
            printf("Seis");
            break;

        case '7':
            printf("Sete");
            break;

        case '8':
            printf("Oito");
            break;

        case '9':
            printf("Nove");
            break;
    
        default:
            break;
    }




/*
    if (numero[0] == '2'){
        printf("hue hue esta funcionando");
    }
*/
    return 0;
}
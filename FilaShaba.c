#include <stdio.h>
#include <locale.h>

//instrucao para definir um padrao
#define tamfila 10

int fila[tamfila] = {0,0,0,0,0,0,0,0,0,0};
int head = 0;
int tail = 0;

void lista_elementos (){

    printf("\n=====================Fila Atual====================\n");

    //primeiro bloco inicializa, segundo bloco é a condição(logica) ver se vai dar certo, o ultimo imcrementa
    for(int i=0 ; i<tamfila ; i++){

        printf("-");
        printf("|%d|", fila[i]);
        printf("-");

    }

}



int main (){
    setlocale(LC_ALL, "Portuguese");

    lista_elementos();

    return 0;
}

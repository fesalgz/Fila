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

//adiciona valores na fila, e incrementa o tail
void enqueue() {
    int val; //receber o numero do valor

    /*se o num de elementos for menor que o num da fila, adiciona
    senao falamos que a fila está cheia*/
    if (tail < tamfila) {
        printf("Informe um valor para adicionar na fila:");
        scanf("%d", &val);
        //posicao da fila [aonde vai colocar na fila, usando o tail]
        fila[tail] = val;
        tail = tail++;
        lista_elementos();
    } else {
        printf("Mano, não cabe, fila cheia.");
    }
}

//chama o proximo valor da lista, e incrementa o head
void dequeue(){
    /*temos que ver se a head for menor que tail
      pq se for igual, a fila está vazia*/
    if(head < tail){
        //pos. da fila [posicao da head] = começo da fila - sao correlacionados
        fila[head] = 0;
        head = head++;
        lista_elementos();
    }
}

//limpa a fila
void clear(){
    //repetição para zerar todas as posições da fila
    for (int i=0, i < tamfila, i++) {
        fila[i] = 0;
    }
    head = 0; //zerou head
    tail = 0; //zerou tail
}



int main (){
    setlocale(LC_ALL, "Portuguese");

    lista_elementos();

    return 0;
}

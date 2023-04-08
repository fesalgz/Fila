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
        printf("Informe um valor para adicionar na fila:\n");
        scanf("%d", &val);
        //posicao da fila [aonde vai colocar na fila, usando o tail]
        fila[tail] = val;
        tail = tail + 1;
        lista_elementos();
    } else {
        printf("Mano, não cabe, fila cheia.");
    }
}

//chama o proximo valor da lista, e incrementa o head
void dequeue(){
    printf("\nNúmero removido: %d", fila[head]);
    /*temos que ver se a head for menor que tail
      pq se for igual, a fila está vazia*/

    if(head < tail){

      //move os outros elementos da fila para frente
      for (int i = head ; i < tail - 1; i++) {

        fila[i] = fila[i + 1]; // o valor i + 1 da fila é movido para a posição i

      }

      // define como 0 o ultimo valor da fila, que está vazio
      fila[tail - 1] = 0;

      // atualiza a posicao da tail para apontar para a posicao anterior da fila
      tail--;

      lista_elementos();

    }
}

//limpa a fila
void clear(){

    //repetição para zerar todas as posições da fila

    for (int i = 0 ; i < tamfila ; i++) {
        fila[i] = 0;
    }

    head = 0; //zerou head
    tail = 0; //zerou tail
}



int main (){
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
//inicio do laço de repetição
do {
    printf("\nSELECIONE A OPÇÃO ABAIXO:\n\n");
    printf("[1] - Inserir (Enqueue)\n");
    printf("[2] - Remover (Dequeue)\n");
    printf("[3] - Listar\n");
    printf("[4] - Limpar a fila (Clear)\n");
    printf("[-1] - Sair\n");
    printf("\nDigite a opção desejada: \n");
    scanf("%d", &opcao);

    //
    switch(opcao) {

case 1:
    enqueue();
    break;

case 2:
    dequeue();
    break;

case 3:
    lista_elementos();
    break;

case 4:
    clear();
    break;


case -1:
    break;

default:
    printf("Mardito, digite dentro da faixa\n");
    break;
        }
    } while (opcao != -1); //fazendo a verificação de da opçao diferente de -1

    return 0;
}

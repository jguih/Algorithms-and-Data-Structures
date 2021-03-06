typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

Queue* Queue_create(); // funcao para criar a fila
void Enqueue(Queue *q, int key); // funcao para enfileirar
int Dequeue(Queue *q); // funcao para desenfileirar
void Queue_print(Queue *q); // funcao para imprimir a fila
int Queue_isempty(Queue *q); // verifica se a fila estah vazia
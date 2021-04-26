#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"
#include "LinkedList.h"
#include "Queue.h"

// Grafo por lista de adjacencia
struct GraphAL
{
   int V; // numero de vertices
   int E; // numero de arestas
   Llist **adj; // lista de adjacencia
};

// funcao para criar a lista de adjacencia
Llist** Adjlist_create(int n)
{
    Llist **l = (Llist**) malloc(n * sizeof(Llist*));
    int i;

    for(i = 0; i < n; i++)
        l[i] = Llist_create();
    
    return l;
}

// funcao para criar o grafo
GraphAL* GraphAL_create(int v)
{
    GraphAL *G = malloc(sizeof(GraphAL));

    G->V = v;
    G->E = 0;
    G->adj = Adjlist_create(G->V);

    return G;
}

// funcao para verificar se a aresta existe
int Edgeexists(GraphAL *G, int v1, int v2)
{
    if(G != NULL && !Llist_isempty(G->adj[v1]))
        return Llist_search(G->adj[v1], v2);
    return 0;
}

// funcao para verificar se vertice eh valido
int Vortex_isvalid(GraphAL *G, int v1)
{
    return (G != NULL && v1 >= 0 && v1 < G->V) ? 1:0;
}

// funcao para inserir aresta
void Edge_insert(GraphAL *G, int v1, int v2)
{
    if(!Edgeexists(G, v1, v2) && Vortex_isvalid(G, v1) && Vortex_isvalid(G, v2))
    {
        Llist_insert(G->adj[v1], v2);
        G->E++;
    }
}

// funcao para remover aresta
void Edge_remove(GraphAL *G, int v1, int v2)
{
    if(Edgeexists(G, v1, v2) && Vortex_isvalid(G, v1) && Vortex_isvalid(G, v2))
    {
        Llist_delete(G->adj[v1], v2);
        G->E--;
    }
}

// funcao para imprimir grafo
void GraphAL_print(GraphAL *G)
{
    int i;

    for(i = 0; i < G->V; i++)
    {
        printf("%d -> ",i);
        Llist_print(G->adj[i]);
        printf("\n");
    }
}

// Breadth Fist Search
void BFS(GraphAL *G, int v1)
{
    Queue *q = Queue_create(); // fila
    int visited[G->V]; // vetor para marcar os visitados
    int i, u; // auxiliares
    int printed;

    for(i = 0; i < G->V; i++)
        visited[i] = 0;

    printf("%d\n",v1);
    visited[v1] = 1;
    Enqueue(q, v1);
    while(!Queue_isempty(q))
    {
        u = Dequeue(q); // vertice
        printed = 0;
        for(i = 0; i < G->V; i++) // arestas do vertice em 'u'
        {
            if(visited[i] == 0 && Edgeexists(G, u, i))
            {
                printf("%d ",i);
                visited[i] = 1;
                Enqueue(q, i);
                printed++;
            }
        }
        if(printed > 0)
            printf("\n");
    }
}
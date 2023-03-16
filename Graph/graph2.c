// Adjacency List representation of graph
// This is a unweighted directed graph 
#include<stdio.h>
#include<stdlib.h>

typedef struct adjListNode{
    int dest;
    int weight;
    struct adjListNode *next;
}adjListNode;

typedef struct adjList{
    struct adjListNode *head;
}adjList;

typedef struct graph{
    int vertices;
    struct adjList *array;
}graph;

graph* create_graph(int v){
    graph *new_graph = (graph *)malloc(sizeof(graph));
    new_graph->vertices = v;
    new_graph->array = (adjList *)malloc(v * sizeof(adjList));

    for (int i = 0; i < v; i++)
    {
        new_graph->array[i].head = NULL;
    }

    return new_graph;
}

void add_edge(graph *g, int initial, int final){
    adjListNode *new_node = (adjListNode *)malloc(sizeof(adjListNode));
    new_node->dest = final;
    new_node->weight = 1;
    new_node->next = g->array[initial].head;
    g->array[initial].head = new_node;
}

void print_graph(graph *g){
    for (int i = 0; i < g->vertices; i++)
    {
        printf("\n Adjacency list of vertex %d\n head ", i);
        adjListNode *temp = g->array[i].head;
        while (temp != NULL)
        {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

int main(){
    int V = 5;
    struct graph* graph = create_graph(V);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
 
    print_graph(graph);
}
// BFS implementation for a graph
// Adjacency List representation of graph
// Comment or Uncomment the add_edge() function second part to make undirected or directed
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

// add an additional argument 'price' that means weight of edge and make 'new_node1->weight = price' 
// to make the graph weighted
void add_edge(graph *g, int initial, int final){
    adjListNode *new_node1 = (adjListNode *)malloc(sizeof(adjListNode));
    new_node1->dest = final;
    new_node1->weight = 1;
    new_node1->next = g->array[initial].head;
    g->array[initial].head = new_node1;

    // since undirected graph, so we need to add the corresponding edge for final to initial also (uncomment it!)

    // adjListNode *new_node2 = (adjListNode *)malloc(sizeof(adjListNode));
    // new_node2->dest = initial;
    // new_node2->weight = 1;
    // new_node2->next = g->array[final].head;
    // g->array[final].head = new_node2;
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

// BREADTH FIRST SEARCH
void bfs(graph *g, int start){
    int queue[g->vertices];
    int front = 0, rear = 0;
    queue[rear] = start;
    rear++;

    int visited_nodes[g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        visited_nodes[i] = 0;
    }
    visited_nodes[start] = 1;

    while (front != rear)
    {
        printf("%d ", queue[front]);
        adjListNode *temp = g->array[queue[front]].head;
        front++;
        while (temp != NULL)
        {
            if (visited_nodes[temp->dest] != 1)
            {
                queue[rear++] = temp->dest;
                visited_nodes[temp->dest] = 1;
            }
            temp = temp->next;
        }   
    }
    printf("\n");
}


// DEPTH FIRST SEARCH 
void actual_dfs_recursive(graph *g, int start, int *visited){
    if (visited[start] == 1)
    {
        return;
    }
    visited[start] = 1;
    printf("%d\t", start);
    adjListNode *temp = g->array[start].head;
    while (temp != NULL)
    {
        actual_dfs_recursive(g, temp->dest, visited);
        temp = temp->next;
    }
}
void dfs_recursive(graph *g, int start){
    int visited_nodes[g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        visited_nodes[i] = 0;
    }
    actual_dfs_recursive(g, start, visited_nodes);
    printf("\n");
}

// DEPTH FIRST SEARCH ITERATIVE USING STACK
void dfs_iterative(graph *g, int start){
    int stack[g->vertices];
    int top = -1;
    top++;
    stack[top] = start;

    int visited_nodes[g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        visited_nodes[i] = 0;
    }

    while (top >= 0)
    {
        int currentNodeIndex = stack[top--];

        if (visited_nodes[currentNodeIndex] == 0)
        {
            visited_nodes[currentNodeIndex] = 1;
            printf("%d ", currentNodeIndex);
            adjListNode *currentNode = g->array[currentNodeIndex].head;
            while (currentNode != NULL)
            {
                if (visited_nodes[currentNode->dest] == 0)
                {
                    stack[++top] = currentNode->dest;
                }
                currentNode = currentNode->next;
            }
        }
    }
}

int main(){
    // graph *g = create_graph(5);
    // // make sure this is a connected graph
    // add_edge(g, 0, 1);
    // add_edge(g, 0, 4);
    // add_edge(g, 1, 2);
    // add_edge(g, 1, 3);
    // add_edge(g, 1, 4);
    // add_edge(g, 2, 3);
    // add_edge(g, 3, 4);

    graph *g = create_graph(6);
    // make sure this is a connected graph
    add_edge(g, 5, 2);
    add_edge(g, 5, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 1);
    add_edge(g, 4, 0);
    add_edge(g, 4, 1);
 
    // printf("Following is Breadth First Traversal "
    //        "(starting from vertex 0) \n");
    // bfs(g, 0);

    dfs_recursive(g, 4);
    //dfs_iterative(g, 0);
}
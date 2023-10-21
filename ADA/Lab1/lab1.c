#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
 

Graph* createGraph(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
 
    return g;
}

void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = true;
    g->adj[w][v] = true;
}

void Graph_BFS(Graph* g, int s)
{
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
 
        
        s = queue[front++];
        char x = s+'A';
        printf("%c ", x);
 
        
        for (int i = 0; i < g->V; i++) {
            if ((g->adj[s][i]||g->adj[i][s]) && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}



void traverseDFS(Graph* g, int visited[], int s) {
    // printf("%d",);
    int i;
    visited[s]=1;
    char x = s+'A';
    printf("%c ", x);
    for(i=0;i< g->V;i++) {
        if((g->adj[s][i]) && (visited[i]==0)) {
            traverseDFS(g,visited,i);
        }
    }
    
}

void printMatrix(Graph* g) {
    for(int i=0;i< g->V;i++) {
        for(int j=0;j< g->V;j++) {
            printf("%d ",g->adj[i][j]);
        }
        printf("\n");
    }
}


int main() {

    int visited[MAX_VERTICES];
    for (int i = 0; i < 4; i++) {
        visited[i] = 0;
    }
    Graph* g = createGraph(4);
    char node1, node2;
    int n=3;
    while(1) {
        printf("enter the source and destination node: (enter same characters to end):  ");
        scanf(" %c %c",&node1, &node2);
        int a=node1-'A';
        int b=node2-'A';
        if(a==b) {
            break;
        }
        Graph_addEdge(g,a,b);
        
        // printf("%d %d",a, b);
        
    }

    printf("BFS TRAVERSAL: \n");
    Graph_BFS(g, 0);
    
    printf("\nDFS TRAVERSAL: \n");
    traverseDFS(g, visited, 0);
    printf("\n");
    printMatrix(g);
    return 0;
}
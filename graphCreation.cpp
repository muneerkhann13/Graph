#include<bits/stdc++.h>
using namespace std;
struct adjNode {
  int des;
  struct adjNode *next;
};

struct adjList{
  struct adjNode *head;
}

struct graph{
  int v;
  struct adjList *arr;
}

struct adjNode* newNode(int des){
  struct adjNode *t=(struct adjNode*)malloc(sizeof(struct adjNode));
  t->des=des;
  t->next=NULL;
  return t;
}

struct graph *newGraph(int v){
  struct graph=(struct graph*)malloc(sizeof(struct graph));
  graph->v=v;
  graph->arr=(struct adjList *)malloc(sizeof(struct adjList)*graph->v);
  for(int i=0;i<graph->v;i++){
    graph->arr[i].head=NULL:
  }
  return graph;
}

void addEdge(graph *g,int src,int des){
  struct adjNode* t=newNode(des);
  t->next = g->arr[src].head;
  g->arr[src].head=t;

  struct adjNode* t=newNode(src);
  t->next = g->arr[des].head;
  g->arr[des].head=t;
}

void printGraph(struct graph* graph)
{
    int v;
    for (v = 0; v < graph->v; ++v)
    {
        struct adjNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->des);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct graph* graph = newGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}

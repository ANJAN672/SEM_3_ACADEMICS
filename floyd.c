#include <stdio.h>
#define V 4

void printsolutions(int dist[][V]);
void floydwarshall(int graph[][V]){
    int dist[V][V], i, j, k;

    // Initialize the distance matrix with the values of the graph
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Compute shortest distances using Floyd-Warshall algorithm
    for(k = 0; k < V; k++){
        for(i = 0; i < V; i++){
            for(j = 0; j < V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printsolutions(dist);
}

void printsolutions(int dist[][V]){
    printf("Following matrix shows the shortest distances between every pair of vertices\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] == 9999)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[V][V] = {
        {0, 5, 9999, 10},
        {9999, 0, 3, 9999},
        {9999, 9999, 0, 1},
        {9999, 9999, 9999, 0}
    };

    floydwarshall(graph);
    return 0;
}

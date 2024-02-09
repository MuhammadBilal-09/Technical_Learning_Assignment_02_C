#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int i, j;
void initializeGraph(int n) {
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    graph[start][end] = 1;
}

void printGraph(int n) {
    printf("Graph Representation:\n");
    printf("   ");
    for (i = 0; i < n; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < n; ++i) {
        printf("%d |", i);
        for (j = 0; j < n; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void inDegree(int n) {
    printf("In-Degree of Each Vertex:\n");
    for (i = 0; i < n; ++i) {
        int inDegreeCount = 0;
        for (j = 0; j < n; ++j) {
            inDegreeCount += graph[j][i];
        }
        printf("Vertex %d: %d\n", i, inDegreeCount);
    }
}

void outDegree(int n) {
    printf("Out-Degree of Each Vertex:\n");
    for (i = 0; i < n; ++i) {
        int outDegreeCount = 0;
        for (j = 0; j < n; ++j) {
            outDegreeCount += graph[i][j];
        }
        printf("Vertex %d: %d\n", i, outDegreeCount);
    }
}

void highestDegree(int n) {
    int maxDegree = 0;
    int vertexWithMaxDegree = -1;

    for (i = 0; i < n; ++i) {
        int degree = 0;
        for (j = 0; j < n; ++j) {
            degree += graph[i][j];
            degree += graph[j][i];
        }
        if (degree > maxDegree) {
            maxDegree = degree;
            vertexWithMaxDegree = i;
        }
    }

    printf("Vertex with Highest Degree (in + out): %d\n", vertexWithMaxDegree);
}

int hasIndirectPath(int start, int end, int n) {
    if (graph[start][end] == 1) {
        return 1;
    }

    for (i = 0; i < n; ++i) {
        if (graph[start][i] == 1 && hasIndirectPath(i, end, n)) {
            return 1;
        }
    }

    return 0;
}

int isolatedVertex(int vertex, int n) {
    for (i = 0; i < n; ++i) {
        if (graph[vertex][i] == 1 || graph[i][vertex] == 1) {
            return 0;
        }
    }
    return 1;
}

int connectedToAll(int vertex, int n) {
    for (i = 0; i < n; ++i) {
        if (i != vertex && (graph[vertex][i] == 0 || graph[i][vertex] == 0)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, choice;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n > MAX_VERTICES) {
        printf("Number of vertices exceeds the maximum limit.\n");
        return 1;
    }

    initializeGraph(n);

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Find In-Degree\n");
        printf("4. Find Out-Degree\n");
        printf("5. Find Highest Degree\n");
        printf("6. Find Indirect Path Length\n");
        printf("7. Find Isolated Vertex\n");
        printf("8. Find Vertex Connected to All\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter start vertex and end vertex: ");
                int start, end;
                scanf("%d %d", &start, &end);
                addEdge(start, end);
                break;
            case 2:
                printGraph(n);
                break;
            case 3:
                inDegree(n);
                break;
            case 4:
                outDegree(n);
                break;
            case 5:
                highestDegree(n);
                break;
            case 6:
                printf("Enter start vertex and end vertex: ");
                scanf("%d %d", &start, &end);
                if (hasIndirectPath(start, end, n)) {
                    printf("Indirect path exists.\n");
                } else {
                    printf("No indirect path exists.\n");
                }
                break;
            case 7:
                printf("Isolated Vertex: %d\n", isolatedVertex(0, n));
                break;
            case 8:
                printf("Vertex Connected to All: %d\n", connectedToAll(0, n));
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

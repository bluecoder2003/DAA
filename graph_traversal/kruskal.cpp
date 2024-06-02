#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

class Edge {
public:
  int u, v, weight;
  Edge() {}
  Edge(int u, int v, int weight) {
    this->u = u;
    this->v = v;
    this->weight = weight;
  }
};

void makeSet(int *parent, int *rank, int size) {
  for (int i = 0; i < size; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(int *parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, int *parent, int *rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);
  if (u == v) {
    return;
  }
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[v] < rank[u]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}

bool compareEdge(Edge a, Edge b) { return a.weight < b.weight; }

void bubbleSort(Edge *edges, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (compareEdge(edges[j + 1], edges[j])) {
        Edge temp = edges[j];
        edges[j] = edges[j + 1];
        edges[j + 1] = temp;
      }
    }
  }
}

int Kruskals(Edge *edges, Edge *ansArray, int edgeCount,
                        int vertexCount, int *rank, int *parent) {
  makeSet(parent, rank, vertexCount);
  bubbleSort(edges, edgeCount);

  int minWeight = 0;
  int ansIdx = 0;
  for (int i = 0; i < edgeCount; i++) {
    int u = findParent(parent, edges[i].u);
    int v = findParent(parent, edges[i].v);

    if (u != v) {
      minWeight += edges[i].weight;
      ansArray[ansIdx++] = edges[i];
      unionSet(u, v, parent, rank);
    }
  }
  return minWeight;
}

int main(int argc, char *argv[]) {
  const char *file = "file1.txt";
  fstream f;
  f.open(file);
  if (!f.is_open()) {
    cerr << "Error opening file: " << file << endl;
    return 1;
  }

  int vertexCount;
  f >> vertexCount;

  cout << "Vertex count: " << vertexCount << endl;

  int maxEdges = vertexCount * vertexCount;
  Edge *edges = new Edge[maxEdges];
  int edgeCount = 0;

  for (int i = 0; i < vertexCount; i++) {
    for (int j = 0; j < vertexCount; j++) {
      int weight;
      f >> weight;
      if (weight != 0) {
        edges[edgeCount++] = Edge(i, j, weight); 
      }
    }
  }

  cout << "Number of edges: " << edgeCount << endl;

  Edge *ansArray = new Edge[vertexCount - 1];
  int *parent = new int[vertexCount];
  int *rank = new int[vertexCount];

  int minWeight = Kruskals(edges, ansArray, edgeCount, vertexCount,
                                      rank, parent);
  cout << "The minimum weight of the spanning tree is: " << minWeight << endl;
  cout << "The edges of the minimum spanning tree are: " << endl;
  for (int i = 0; i < vertexCount - 1; i++) {
    cout << ansArray[i].u << " - " << ansArray[i].v << " with weight "
         << ansArray[i].weight << endl;
  }

  delete[] parent;
  delete[] rank;
  delete[] edges;
  delete[] ansArray;

  return 0;
}

/*
  2 3 69
  3 4 74
  4 5 86
  5 6 87
  2 5 88
 * */



// our considerd array : 0 1 5 , 0 2 6 , 1 2 7 , 1 3 8 , 2 3 9
// minweight = 5
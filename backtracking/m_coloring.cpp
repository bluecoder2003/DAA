#include <iostream>
#include <fstream>

using namespace std;

// bool isSafe(int c, int *colors, int **graph, int v, int V) {
bool isSafe(int **graph, int V,int c, int v,int *colors) {
  for (int i = 0; i < V; i++) {//iterates through each vertex in the graph
    if (graph[v][i]!=0 && c == colors[i]) { //graph[v][i]!=0
      return false;
    }
  }
  return true;
}

void printColors(int *colors, int V) {
  for (int i = 0; i < V; i++) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

void colorGraphUntill(int **graph, int V, int m, int v, int *colors) {
  if (v == V) {//v=current vertex index, V=total number of vertices
    printColors(colors, V);
    return;
  }
  for (int c = 1; c <= m; c++) {//This loop iterates through each color from 1 to m, representing the colors available for coloring the current vertex v.
    // if (isSafe(c, colors, graph, v, V)) {
    if (isSafe(graph, V, c, v, colors)) {
      colors[v] = c;
      colorGraphUntill(graph, V, m, v + 1, colors);//checking for the next vertex
      colors[v] = 0;
    }
  }
}

int main() {
  int V, m; //V=vertex,m=max n. of colors assigned
  ifstream fp("color.txt");
  if(!fp){
    cout << "Error opening file";
    return 1;
  }
  fp >> V >> m;
  int **graph = new int *[V];//2d array creation that allocates memory for V rows
  for (int i = 0; i < V; i++) {
    graph[i] = new int[V];//allocates memory for V columns
    for (int j = 0; j < V; j++) {
      fp >> graph[i][j];//reads an integer from the file and assigns it to graph[i][j]
    }
  }
  fp.close();
  int *colors = new int[V]{0};//keeps track of the color assignments to the vertex
  colorGraphUntill(graph, V, m, 0, colors);//0 is assigned to v,which checks current vertex color
  return 0;
}
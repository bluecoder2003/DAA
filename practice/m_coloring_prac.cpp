#include<iostream>
#include<fstream>
using namespace std;

bool isSafe(int c,int* colors,int** graph,int v,int V)
{
    for(int i=0;i<V;i++)
    {
        if(graph[v][i] && c==colors[i])
        return false;
    }
    return true;
}

void print(int *colors,int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<colors[i];
    }
    cout<<endl;
}

void colorgraph(int** graph,int V,int m,int v,int* colors)
{
    if(v==V)
    {
        print(colors,V);
        return;
    }
    for(int c=1;c<=m;c++)
    {
        if (isSafe(c,colors,graph,v,V))
        {
            colors[v]=c;
            colorgraph(graph,V,m,v+1,colors);
            colors[v]=0;
        }
    }
}

int main()
{
   int V,m;
   ifstream fp("color2.txt");
   if(!fp)
   {
    cout<<"error in opening file";
    return 1;
   }
   fp>>V>>m;
   int** graph=new int*[V];
   for(int i=0;i<V;i++)
   {
    graph[i]=new int[V];
    for(int j=0;j<V;j++)
    {
        fp>>graph[i][j];
    }
   }
   fp.close();
   int *colors=new int[V]{0};
   colorgraph(graph,V,m,0,colors);
   return 0;
}
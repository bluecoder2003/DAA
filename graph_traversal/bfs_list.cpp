#include<stdio.h>
#include<stdlib.h>
int n;
int front=-1;int rear=-1;
int visit[100]={0};
int que[100]={0};

void insert(int n)
{
    if(front==-1)
    {
        front++;
    }
    que[++rear]=n;
}

int isempty()
{
    return (front==-1 && rear==-1);
}

int peak()
{
    int top;
    if(front==rear)
    {
         top=que[rear];
        rear=-1;front=-1;
        return top;
    }

    return que[front++];
}


struct node{
    int vertex;
    struct node* next;
};

struct node* adj[10]={NULL};


void insertlist(int i, int v)
{
    struct node* curr=(struct node*)malloc(sizeof (struct node));
    curr->vertex=v;
    curr->next=NULL;
    if(adj[i]==NULL)
    {
        adj[i]=curr;
        return;
    }

    struct node* temp=adj[i];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=curr;
    return;
}

void show_list()
{
    printf("The Total No. Of Vertex in the graph is: %d\n",n);
    printf("The Adjency list is:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nAdjency of %c: ",'A'+i);
        struct node* temp=adj[i];
       // if(temp!=NULL)
        //{
            while(temp!=NULL)
            {
                printf("%c",('A'+temp->vertex));
                printf("<<<--->>>");
                temp=temp->next;
            }
       // }
        printf("\n");
    }
}

void make_adjlist()
{
    FILE* f;
    int data;
    f=fopen("bfs.txt","r");
    if(f==NULL)
    {
        printf("ERROR:");
        exit(0);
    }
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(f,"%d",&data);
            if(data==1)
            insertlist(i,j);
        }
    }
    fclose(f);
}

void BFS(int src)
{
    printf("The BFS Traversal is:\n");
    insert(src);
    visit[src]=1;
    printf("%c",'A'+src);
    printf("<<<--->>>");
    while(!isempty())
    {
        //printf("\n soura\n");
        int currnode=peak();
        node* temp=adj[currnode];
        while(temp!=NULL)
        {
            if(visit[temp->vertex]==0)
            {
                printf("%c",'A'+(temp->vertex));
                 printf("<<<--->>>");
                insert(temp->vertex);
                visit[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}




int main()
{
    make_adjlist();
    show_list();
    BFS(4);
}
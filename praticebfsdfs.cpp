#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node
{
    string a;
    node *next;
};

class graph
{
    public:
    int x;
    graph()
    {
        cout<<"\nEnter no of node:";
        cin>>x;
    }

    node *head[10];
    int visited[10];
    void initial();
    void create();
    void display();
    void bfs();
    void dfs(); 
    void dfs1(int v);      
};

void graph::create()
{
   int n;
   node *temp;
   for(int i=0;i<x;i++)
   {
    cout<<"Enter node:";
    cin>>head[i]->a;
    cout<<"Enter no of node are connected to "<<head[i]->a<<" : ";
    cin>>n;

    for(int j=0;j<n;j++)
    {
        node *nnode=new node;
        nnode->next=NULL;
        cout<<"Enter connected node:";
        cin>>nnode->a;
        temp=head[i];

        while(temp->next!=NULL)
          temp=temp->next;

        temp->next=nnode;
    }
   }
}


void graph::initial()
{
    for(int i=0;i<x;i++)
    {
        head[i]=new node;
        head[i]->a='x';
        head[i]->next=NULL;
    }
}

void graph::bfs()
{
   queue<string>q1;
   int visited[x],i;
   for(int i=0;i<x;i++)
   {
    visited[i]=0;
   }

   string c;
   node *temp;
   temp=head[0];
   q1.push(head[0]->a);
   visited[0]=1;

   while(!q1.empty())
   {
      c=q1.front();
      q1.pop();
      cout<<c<<" ";

      i=0;
      while(c!= head[i]->a)
      {
        i++;
      }

      temp=head[i];
      while(temp!=NULL)
      {
        i=0;
        while(temp->a!=head[i]->a)
        {
            i++;
        }

        if(visited[i]!=1)
        {
            q1.push(temp->a);
            visited[i]=1;
        }

        temp=temp->next;
      }
   }
}

void graph::dfs()
{
    for(int i=0;i<x;i++)
    {
        visited[i]=0;
    }
    for(int j=0;j<x;j++)
    {
        if(visited[j]==0)
        {
            dfs1(j);
        }
    }
}

void graph::dfs1(int v)
{
   int i;
   node *temp;
   cout<<head[v]->a<<" ";
   visited[v]=1;
   temp=head[v]->next;
   while(temp!=NULL)
   {
    i=0;
    while(temp->a!=head[i]->a)
        i++;
    if(visited[i]==0)
        dfs1(i);
    temp=temp->next;
   }
}

void graph::display()
{
    node *temp=new node;
    cout<<"Graph:-\n";
    for(int i=0;i<x;i++)
    {
        temp=head[i];
        cout<<temp->a<<" : ";
        temp=temp->next;
        while(temp!=NULL)
        {
            cout<<temp->a<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    graph g1;
    g1.initial();
    g1.create();
    g1.display();
    cout<<"\nBFS: ";
    g1.bfs();
    cout<<"\nDFS: ";
    g1.dfs();
    return(0);

}
#include <bits/stdc++.h>
using namespace std;

int number_of_nodes,number_of_edges,**graph,src=0,sink;

int bfs(int path[]){
    int visited[number_of_nodes]={0};

    queue <int>q;
    q.push(src);
    visited[src]=1;
    path[src]=-1;

    while(!q.empty()){
        int u;
        u=q.front();
        q.pop();
        for(int i=0;i<number_of_nodes;i++){
            if(!visited[i] && graph[u][i]>0){
                q.push(i);
                path[i]=u;
                visited[i]=1;
            }
        }
    }
    return (visited[sink]==1);
}

int find_flow(){
    int path[number_of_nodes],flow=0;
    while(bfs(path)){
        int residual_flow=INT_MAX;
        for(int i=sink;i!=src;i=path[i])
            residual_flow=min(residual_flow,graph[path[i]][i]);
        for(int i=sink;i!=src;i=path[i]){
            graph[path[i]][i]-=residual_flow;
            graph[i][path[i]]+=residual_flow;
        }
        flow+=residual_flow;
    }
    return flow;
}


int main(){
    int i,j;
    cout<<"Number of vertices : ";
    cin>>number_of_nodes;
    cout<<"Number of edges : ";
    cin>>number_of_edges;
    sink=number_of_nodes-1;
    graph=(int **)malloc(number_of_nodes*sizeof(int *));
    for(int i=0;i<number_of_nodes;i++)
        graph[i]=(int *)malloc(number_of_nodes*sizeof(int));
    
    for(i=0;i<number_of_nodes;i++)
        for(j=0;j<number_of_nodes;j++)
            graph[i][j]=0;

    for(i=0;i<number_of_edges;i++){
        int src,dest,weight;
        cout<<"Enter Edge(Src,Dest,Weight) : ";
        cin>>src>>dest>>weight;
        graph[src][dest]=weight;
    }
    cout<<"Max Flow in network : "<<find_flow()<<"\n";
    return 0;
}
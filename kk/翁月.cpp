#include <iostream>
#include "tp.h"
using namespace std;
Graphmtx::Graphmtx(){
    numVertices = 0;
    numEdges = 0;
    int i,j;
    VerticesList = new string[maxVertices];
    p=new int[maxVertices];
    Edge = (int **) new int*[maxVertices];
    for(i = 0;i<maxVertices;i++)
        Edge[i] = new int[maxVertices];
    for(i=0;i<maxVertices;i++)
        for(j = 0;j<maxVertices;j++)
            Edge[i][j] = (i==j) ?0:maxWeight;
}
bool Graphmtx::insertVertex(int n,const string vertex)
{
    cout<<"aa"<<endl;
    cout<<"ÎÌÔÂ"<<endl;
    if(numVertices == maxVertices)
        return false;
    VerticesList[numVertices] = vertex;
    p[numVertices]=n;
    numVertices++;
    return true;
}
bool Graphmtx::insertEdge(int v1, int v2,int cost)
{
    int w1=-1,w2=-1;
    for(int i=0;i<numVertices;i++){
        if(p[i]==v1){
            w1=i;
        }
        if(p[i]==v2){
            w2=i;
        }
        if(w1!=-1&&w2!=-1){
            break;
        }
    }
    if(w1 > -1 && w2< numVertices && w1>-1 && w2<numVertices && Edge[w1][w2] == maxWeight)
    {
        Edge[w1][w2] = Edge[w2][w1] = cost;
        numEdges ++;
        return true;
    }
    else return false;
}
int Graphmtx::re(int q){
    int v=-1;
    for(int h=0;h<numVertices;h++){
        if(p[h]==q){
            v=h;
            break;
        }
    }
    return v;
}
void Graphmtx::shuchu(){
    cout<<"     ";
    for(int i=0;i<numVertices;i++){
        cout<<p[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<numVertices;i++){
        cout<<p[i]<<" | ";
        for(int j=0;j<numVertices;j++){
            if(Edge[i][j]==INT_MAX){
                cout<<"Max ";
            }
            else
                cout<<Edge[i][j]<<" ";
        }
        cout<<endl;
    }
}

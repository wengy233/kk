#include"tp.h"
#include<iostream>
using namespace std;
bool Graphmtx::removeVertex(int v)
{
	cout<<"Ф��"<<endl;
    if(v < 0 && v>= numVertices)
    	{
		 cout<< "�����ڸ�·����������"<<endl;
         return false;
        } 
    if(numVertices == 1)//ֻ��һ���㣬�������κα� 
    	{
		cout<<"ֻ����һ��·����,�޷�����·�ɱ�����"<<endl; 
        return false;
    	}
    int i,j;
    VerticesList[v] = VerticesList[numVertices-1];
	p[v]=p[numVertices-1];//ɾ�� 
    for(i = 0;i<numVertices;i++)
    {
        if( Edge[i][v] >0 && Edge[i][v] <maxWeight )
            numEdges --;
    }
    for(i = 0;i<numVertices;i++)
    {
        Edge[i][v] = Edge[i][numVertices-1];
    }
    numVertices --;
    for(j= 0;j<numVertices;j++)
        Edge[v][j] =Edge[numVertices][j];
    return true;
}
bool Graphmtx::removeEdge(int v1,int v2)
{
    if (v1 > -1 && v1< numVertices && v2>-1 && v2<numVertices && Edge[v1][v2] > 0 && v1 != v2 && Edge[v1][v2]< maxWeight)
    {
        Edge[v1][v2] = Edge[v2][v1]=maxWeight;
        numEdges --;
        return true;
    }
    else
    {
        return false;
    }
}


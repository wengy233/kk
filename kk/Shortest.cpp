#include"tp.h"
#include<iostream>
using namespace std;

void Graphmtx::Shortest(int v) { 
	cout << "��ޱ" << endl;
	if(v==-1){
             cout<<"���޴�·�ɱ�"<<endl;
             return;
        }
	int dist[numVertices];
	int path[numVertices];
	if(v==-1)
	{
		cout<<"�����ڸ�·����"<<endl;
		return;
	}
	int n = numVertices;
	bool *S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = Edge[v][i];
		S[i] = false;
		if (i != v && dist[i] <maxWeight)   //�����v����path�����У������д˱ߣ��򽫵�v����path���飬���򲻼���
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;      //��ʾ�˱ߴ������
	dist[v] = 0;      //�Ƚ��˱ߵľ������㣬�൱�ڳ�ʼ��
	for (i = 0; i<n - 1; i++)
	{
		min = maxWeight;   //��Ĭ����̾���ΪmaxWeight
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)   //����㻹δ�����Ҵ��ڸ��̾���
			{
				u = j;
				min = dist[j];     //�����̾���
			}
		}
		S[u] = true;    //�ô˵㴦�����
		for (k = 0; k<n; k++)
		{
			w = Edge[u][k];
			if (S[k] == false && w <maxWeight && dist[u] + w<dist[k])   //����㻹δ�����Ҵ�������·����ͨ������㣩С��ԭ��·��
			{
				dist[k] = dist[u] + w;   //���ø�С�ı�ֵ����ԭ����ֵ
				path[k] = u;
			}
		}
	}
	printPath(v, dist, path);   //�����������
}
void Graphmtx::printPath(int v, int dist[], int path[])
{
    cout << "| 路由�? "<< p[v] <<"路由表：" <<"           |"<< endl;
    int i, j, k, n =numVertices;
    int * d = new int[n];
    for (i = 0; i<n; i++)
    {
        if (i != v)
        {
            j = i;
            k = 0;
            while (j != v)
            {
                d[k++] = j;
                j = path[j];
            }
            cout <<"| 目的路由"<<p[i]<<" ";
            cout <<"下一跳："<<p[d[--k]]<<" ";
            cout << "权值：" << dist[i] <<" |"<< endl;
        }
    }
    delete[] d;
}

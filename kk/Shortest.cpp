#include"tp.h"
#include<iostream>
using namespace std;

void Graphmtx::Shortest(int v) { 
	cout << "孙薇" << endl;
	if(v==-1){
             cout<<"查无此路由表"<<endl;
             return;
        }
	int dist[numVertices];
	int path[numVertices];
	if(v==-1)
	{
		cout<<"不存在该路由器"<<endl;
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
		if (i != v && dist[i] <maxWeight)   //如果点v不在path数组中，而且有此边，则将点v加入path数组，否则不加入
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;      //表示此边处理完毕
	dist[v] = 0;      //先将此边的距离置零，相当于初始化
	for (i = 0; i<n - 1; i++)
	{
		min = maxWeight;   //先默认最短距离为maxWeight
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)   //如果点还未处理，且存在更短距离
			{
				u = j;
				min = dist[j];     //存此最短距离
			}
		}
		S[u] = true;    //让此点处理完毕
		for (k = 0; k<n; k++)
		{
			w = Edge[u][k];
			if (S[k] == false && w <maxWeight && dist[u] + w<dist[k])   //如果点还未处理，且存在新增路径（通过多个点）小于原来路径
			{
				dist[k] = dist[u] + w;   //则用更小的边值代替原来的值
				path[k] = u;
			}
		}
	}
	printPath(v, dist, path);   //调用输出函数
}
void Graphmtx::printPath(int v, int dist[], int path[])
{
    cout << "| 璺敱鍣? "<< p[v] <<"璺敱琛細" <<"           |"<< endl;
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
            cout <<"| 鐩殑璺敱"<<p[i]<<" ";
            cout <<"涓嬩竴璺筹細"<<p[d[--k]]<<" ";
            cout << "鏉冨�硷細" << dist[i] <<" |"<< endl;
        }
    }
    delete[] d;
}

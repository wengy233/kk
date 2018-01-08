#ifndef tp_h
#define tp_h
#include <string>
extern int maxVertices;
extern int maxWeight;
using namespace std;
struct Router{
    int number;
    string address;
};
class Graphmtx{
protected:
    int numVertices;
    int numEdges;
    string *VerticesList;
    int *p;
    int **Edge;
public:
    Graphmtx();
    int re(int q);
    bool insertVertex(int n,const string vertex);
    bool insertEdge(int v1,int v2,int cost);
    bool removeVertex(int v);
    bool removeEdge(int v1,int v2);
    void Shortest(int n);
    void printPath(int v,int dist[],int path[]);
    void shuchu();
};

#endif /* tp_h */

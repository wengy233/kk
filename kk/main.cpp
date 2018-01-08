#include <iostream>
#include <fstream>
#include "assert.h"
#include "tp.h"
//#include"翁月.cpp"
//#include"d.cpp"
//#include"Shortest.cpp" 
int maxVertices=10;
int maxWeight=INT_MAX;
int main(int argc, const char * argv[]) {
    // insert code here...
    Graphmtx t;
    int x,x2,y2,cost,n,m,p,q,kk,kkk;
    string y;
    ifstream in("Router.txt",ios::in);
    assert(in);
    in>>x>>y;
    while(in){
        t.insertVertex(x,y);
        in>>x>>y;
    }
    ifstream f2("Router2.txt",ios::in);
    assert(f2);
    f2>>x2>>y2>>cost;
    while(f2){
        t.insertEdge(x2,y2,cost);
        f2>>x2>>y2>>cost;
    }
    cout<<"邻阶矩阵："<<endl;
    t.shuchu();
    while(1)
    {
        cout<<"*******************************"<<endl;
        cout<<"1.查询路由表 2.删除路由器 3.删除边 4.退出"<<endl;
        cin>>m;
        if(m==1){
            cout<<"请输入路由器编号："<<endl;;
            cin>>n;
            cout<<"---------------------------"<<endl;
            kk=t.re(n);
            t.Shortest(kk);
            cout<<"---------------------------"<<endl;
        }
        else if(m==2){
            cout<<"请输入删除的路由器编号："<<endl;
            cin>>p;
            kk=t.re(p);
            t.removeVertex(kk);
            t.shuchu();
        }
        else if(m==3){
            cout<<"请输入删除边的两个路由器编号："<<endl;
            cout<<"第一个："<<endl;
            cin>>p;
            cout<<"第二个："<<endl;
            cin>>q;
            kk=t.re(p);
            kkk=t.re(q);
            t.removeEdge(kk,kkk);
            t.shuchu();
        }
        else if(m==4){
            break;
        }
        else{
            cout<<"输入错误"<<endl;
        }
        cout<<"*******************************"<<endl;
        
    }
    return 0;
}


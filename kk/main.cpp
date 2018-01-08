#include <iostream>
#include <fstream>
#include "assert.h"
#include "tp.h"
//#include"����.cpp"
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
    cout<<"�ڽ׾���"<<endl;
    t.shuchu();
    while(1)
    {
        cout<<"*******************************"<<endl;
        cout<<"1.��ѯ·�ɱ� 2.ɾ��·���� 3.ɾ���� 4.�˳�"<<endl;
        cin>>m;
        if(m==1){
            cout<<"������·������ţ�"<<endl;;
            cin>>n;
            cout<<"---------------------------"<<endl;
            kk=t.re(n);
            t.Shortest(kk);
            cout<<"---------------------------"<<endl;
        }
        else if(m==2){
            cout<<"������ɾ����·������ţ�"<<endl;
            cin>>p;
            kk=t.re(p);
            t.removeVertex(kk);
            t.shuchu();
        }
        else if(m==3){
            cout<<"������ɾ���ߵ�����·������ţ�"<<endl;
            cout<<"��һ����"<<endl;
            cin>>p;
            cout<<"�ڶ�����"<<endl;
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
            cout<<"�������"<<endl;
        }
        cout<<"*******************************"<<endl;
        
    }
    return 0;
}


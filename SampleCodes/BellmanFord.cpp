//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;
class Graph{
    vector<vector<pair<int,int>>> e;
    int size;

public:
    Graph(int v){
        size=v;
        e.resize(v);
    }
    void add_edge(int u,int v,int w){
        e[u].emplace_back(make_pair(v,w));
    }

    vector <int> bellmanFord(int s)
    {
        vector<int> d(size);
        for(int &x:d){
            x=INT_MAX;
        }
        d[s] =0;

        for(int i=0;i<size-1;i++){
            // Go through all edges and update once
            for(int j=0;j<size;j++){
                for(auto row: e[j]){
                    int v=row.first;
                    int w=row.second;
                    if(d[v] > w + d[j] && d[j]!= INT_MAX){
                        d[v]=w+d[j];
                    }
                }
            }
        }
        // Go thru all edges and if an update happens then there is a negative cycle
        for(int j=0;j<size;j++){
            for(auto row: e[j]){
                int v=row.first;
                int w=row.second;
                if(d[v] > w + d[j] && d[j]!= INT_MAX){
                    cout<<"Negative cycle"<<endl;
                    return d;
                }
            }
        }

        return d;
    }

};
int main(){
    int n=5;
    Graph g(n);
    g.add_edge(0,1,-1);
    g.add_edge(0,2,4);
    g.add_edge(1,2,3);
    g.add_edge(1,3,2);
    g.add_edge(1,4,2);
    g.add_edge(3,2,5);
    g.add_edge(3,1,1);
    g.add_edge(4,3,-3);
    vector<int>ans = g.bellmanFord(0);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}

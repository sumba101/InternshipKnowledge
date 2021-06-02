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

    vector <int> dijkstra(int s)
    {
        vector<int> d(size);
        for(int &x:d){
            x=INT_MAX;
        }
        d[s] =0;

        unordered_set<int>vis;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(make_pair(d[s],s));
        while(!q.empty()){
            pair<int,int> temp=q.top();
            q.pop();
            if(vis.count(temp.second)){
                continue;
            }
            vis.emplace(temp.second);
            int d_curr=temp.first;

            int u=temp.second;

            for(auto row: e[u]){
                int v=row.first;
                int w=row.second;
                if(d[v] > w + d_curr){
                    d[v]=w+d_curr;
                    q.emplace(make_pair(d[v],v));
                }
            }
        }
        return d;
    }

};
int main(){
    int n=5;
    Graph g(n);

    g.add_edge(1,0,0);
    g.add_edge(0,2,0);
    g.add_edge(2,1,0);
    g.add_edge(0,3,0);
    g.add_edge(3,4,0);
    vector<vector<int>>ans;
    for(auto row:ans){
        cout<<endl;
        for(auto x:row){
            cout<<x<<" ";
        }
    }
    return 0;
}

//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;
int find(vector<pair<int,int>>&a, int i){
    return (a[i].first==i)?i:a[i].first=find(a,a[i].first);
}
int Union(int x,int y,vector<pair<int,int>>&a){ // Returns -1 if it is already connected and in same subset, else connects it and returns 1
    int px=find(a,x);
    int py=find(a,y);
    if(px==py){
        return -1;
    }
    if(a[px].second>a[py].second){
        a[py].first=px;
        a[px].second+=a[py].second;
    }else{
        a[px].first=py;
        a[py].second+=a[px].second;
    }
    return 1;
}

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
    void kruskals(){
        vector<pair<int,int>>a;
        for(int i=0;i<size;i++){
            a.emplace_back(make_pair(i,1));
        }
//        vector<int> ans;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> q;
        for(int i=0;i<size;i++){
            for(auto ele:e[i]){
                q.emplace(make_tuple(ele.second,i,ele.first));
            }
        }
        int count = 0;
        int u,v,w;
        int cost=0;
        while (!q.empty() && count!= size-1){
            tie(w,u,v) = q.top();
            q.pop();

            if(Union(u,v,a)!=-1){
                count++;
                cost+=w;
            }
        }
        cout<<"cost "<<cost<<endl;
    }

    void prims(){
        unordered_set<int>s;
        vector<int>d(size);
        for(int &x:d){
            x=INT_MAX;
        }
        d[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push(make_pair(d[0],0));
        int count = 0;
        pair<int,int>temp;
        int cost=0;
        while (!q.empty() && count!= size){
            temp= q.top();
            q.pop();
            int u=temp.second;
            if(s.count(u)){
                continue;
            }
            count++;
            cost+=temp.first;

            s.emplace(u);
            for(auto pairing: e[temp.second]){
                int v=pairing.first;
                int w=pairing.second;
                if(d[v]>d[u] + w){
                    d[v]=d[u]+w;
                    q.emplace(make_pair(d[v],v));
                }
            }
        }
        cout<<"cost "<<cost<<endl;
    }

};
int main(){
    int n=4;
    Graph g(n);

    g.add_edge(0,2,6);
    g.add_edge(0,1,10);
    g.add_edge(0,3,5);
    g.add_edge(1,3,15);
    g.add_edge(2,3,4);
    g.prims();
    return 0;
}

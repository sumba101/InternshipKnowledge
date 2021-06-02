#include <bits/stdc++.h>
using namespace std;
class Graph{
    vector<vector<int>> e;
    int size;

public:
    Graph(int v){
        size=v;
        e.resize(v);
    }
    void add_edge(int u,int v){
        e[u].emplace_back(v);
    }
    void reverse(){
        vector<vector<int>>temp(size);
        for(int i=0;i<size;i++){
            for(int x:e[i]){
                temp[x].emplace_back(i);
            }
        }
        e=temp;
    }
    void dfs(unordered_set<int>&vis,int i,stack<int> &s){
        if(vis.count(i)){
            return;
        }
        vis.emplace(i);
        for(int x:e[i]){
            dfs(vis,x,s);
        }
        s.push(i);
    }

    void dfs2(unordered_set<int>&vis,int i,vector<int> &s){
        if(vis.count(i)){
            return;
        }
        vis.emplace(i);
        for(int x:e[i]){
            dfs2(vis,x,s);
        }
        s.emplace_back(i);
    }
    void SCC(vector<vector<int>>&ans){
        stack<int> s;
        unordered_set<int>vis;
        for(int i=0;i<size;i++){
            if(!vis.count(i))
                dfs(vis,i,s);
        }
        reverse();
        vis.clear();
        while(!s.empty()){
            vector<int>temp;
            int i=s.top();
            s.pop();
            if(vis.count(i)){
                continue;
            }
            dfs2(vis,i,temp);
            ans.emplace_back(temp);
        }
    }
};
int main(){
    int n=5;
    Graph g(n);

        g.add_edge(1,0);
        g.add_edge(0,2);
        g.add_edge(2,1);
        g.add_edge(0,3);
        g.add_edge(3,4);
        vector<vector<int>>ans;
        g.SCC(ans);
        for(auto row:ans){
            cout<<endl;
            for(auto x:row){
                cout<<x<<" ";
            }
        }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll maxN = 2501;
vector<ll> dist(maxN,LLONG_MIN), adj[maxN];;
ll nodes[maxN], vis[maxN]; 
 
void dfs(int n, int node) {
    vis[node]=1;
    for (auto it : adj[node]) {
        nodes[node]=max(nodes[node], nodes[it]);
        if (!vis[it]) dfs(n,it);
        nodes[node]=max(nodes[node], nodes[it]);
    }
}
 
ll bellmanCycle(ll n, vector<vector<ll>> edges) {
    nodes[n]=1;
    dfs(n,1);
    for (int i=1; i<=n-1; i++) {
        for (auto edge : edges) {
            ll u=edge[0],v=edge[1],wt=edge[2]; 
            if (dist[u]!=LLONG_MIN) {
                dist[v] = max(dist[v], dist[u]+wt);
            }
        }
    }
 
    for (auto edge : edges) {
        ll u=edge[0],v=edge[1],wt=edge[2]; 
        if (dist[u]+wt > dist[v]) {
            if (nodes[v]) return -1;
            dist[v]=dist[u]+wt;
        }
    }
    return dist[n];
}    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> edges;
 
    for (int i=0; i<m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(v);
        edges.push_back({u,v,wt});
    }
    dist[1]=0;
//  for (int i=1; i<=n; i++) cout << nodes[i] << " ";
    cout << bellmanCycle(n,edges);
    // for (auto x : adj[n]) {
    //     cout << x << " " << nodes[x] << "\n";
    // }
//  for (int i=1; i<=n; i++) cout << nodes[i] << " ";
    
    return 0;
}

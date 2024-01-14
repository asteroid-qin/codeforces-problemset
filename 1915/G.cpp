#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#define ll long long
using namespace std;

const int MAXN = 1e3 + 1, MAXM = 1e3 + 1;
struct Edge{
    int next, to, w;
} edge[MAXM];
struct node{
    ll w, u;

    bool operator<(const node& x) const{
        return w > x.w;
    }
};
int cnt, head[MAXN];
int t, n, m, s, u, v, w;
ll dis[MAXN];
bool vis[MAXN];

void addE(int u, int v, int w){
    edge[++cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt;
}

void slv() {
	cin >> n >> m;    
    while(m--){
        cin >> u >> v >> w;
        addE(u, v, w);
    }
    int min_s = 1e3;
    for(int i = 1; i <= n; i++) {
    	int x; std::cin >> x;
    	min_s = std::min(min_s, x);
    	dis[i] = 0x3f7f7f7f3f;
	}
    priority_queue<node> q;
    q.push((node){0,1});
    dis[1] = 0;
    std::cout << min_s << "##\n";
    while(!q.empty()){
        node x = q.top(); q.pop();
        u = x.u;
        if(vis[u]) continue;
        vis[u] = true;

        for(int i = head[u]; i; i = edge[i].next){
            v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w * min_s ){
                dis[v] = dis[u] + edge[i].w * min_s;
                q.push({dis[v], v});
            }
        }
    }
    cout << dis[n] << "\n";
} 

int main(){
    std::cin >> t;
	while(t--) slv();
    return 0;
}

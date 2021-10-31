
const int MAX = 3e5 + 5;
int id[MAX], nodes, edges;

vector<pair <int, pair<int, int>> > p;

int n,m;

int timer,l;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    } 
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}

// pseudo code

    for (int node = 1; node <= k; ++node) {  // path from i to j considering node in b/w
        for (int i = 1; i < k+1; ++i) {
            for (int j = 1; j < k+1; ++j) {
                if (dist[i][node] < INF && dist[node][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][node] + dist[node][j]); 
            }
        }
    }

void dfs_cen(int u, int prev) {
                szz[u] = 1;
                bool is_centroid = true;
                for (auto v : G[u]) if (v != prev) {
                        dfs_cen(v, u);
                        szz[u] += szz[v];
                        if (szz[v] > n / 2) is_centroid = false;
                }
                if (n - szz[u] > n / 2) is_centroid = false;
                if (is_centroid) pp.push_back(u);  
}




int kruskal()
{
    int x, y;
    int cost, minimumCost = 0;
    for(int i = 0;i < sz(p);++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}  

// kruskal

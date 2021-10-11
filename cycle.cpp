
const int MAX = 3e5 + 5;
int id[MAX], nodes, edges;

vector<pair <int, pair<int, int>> > p;

int n,m;

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
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
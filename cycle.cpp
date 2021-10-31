
const int MAX = 3e5 + 5;
int id[MAX], nodes, edges;

vector<pair <int, pair<int, int>> > p;

int n,m;


void dijkstra(int sx){
  rep(i,0,n+1)
  {
         vis[i]=0;
       dist[i]=INF;
       parent[i]=-1;
  }

                                                // set the vertices distances as infinity
   // memset(vis, false , sizeof vis);            // set all vertex as unvisited

    dist[sx] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue
 
    s.insert({0 ,sx});                          // insert the source node with distance = 0
    
    parent[sx]=sx;
 
    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());
 
        int x = p.S; int wei = p.F;
 
      //  dbg2(x,wei);
 
        if( vis[x]) continue;                  // check if the s.insert({dist[x][y+1] , {x,y+1} } );  s.insert({dist[x][y+1] , {x,y+1} } );  s.insert({dist[x][y+1] , {x,y+1} } );  popped vertex is visited before
         vis[x] = 1;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i]; 
            if(dist[x] + 1 < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + 1;
                parent[e]=x;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
}
}


void path(int x)   //path generator----------------------
{
  pat.clear();

  while(true)
  {
    pat.pb(x);   
    if(parent[x]==x)  
     break;
     x=parent[x];
  }

    REVERSE(pat); 
}       /

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

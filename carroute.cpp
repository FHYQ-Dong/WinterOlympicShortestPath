#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define pdi pair<double, int>
#define mp make_pair
using namespace std;

struct route{
    int point[50];
    int cnt;
}R[50];
struct Edge{
    int v;
    double w;
    Edge(int vv = 0, double ww = 0): v(vv), w(ww) {}
};
const int N = 50;
const double INF = 1e9;
int n, m, t, u, v;
int target[N];
double w, dis[N];
bool vis[N];
vector<Edge> adj[N];
priority_queue<pdi, vector<pdi >, greater<pdi > > pq;

void dijkstra(){
    pq.push(mp(0, 1));
    dis[1] = 0;
    while(!pq.empty()){
        u = pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        rep(i, 0, int(adj[u].size())-1){
            v = adj[u][i].v; w = adj[u][i].w;
            if(dis[v] >= dis[u]+w){
                dis[v] = dis[u] + w;
                R[v] = R[u];
                R[v].point[++R[v].cnt] = u;
                pq.push(mp(dis[v], v));
            }
        }   
    }
    return;
}

void solvego(string place){
    string inputFileName = place + ".carroute", \
           outputFileName = place + ".shortestpath";
    ifstream fin (inputFileName, ios_base::in);
    ofstream fout (outputFileName, ios_base::out);

    fin >> n >> m >> t;
    rep(i, 1, t) fin >> target[i];
    // 初始化
    rep(i, 1, n) dis[i] = INF;
    rep(i, 1, n) adj[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(R, 0, sizeof(R));
    while(!pq.empty()) pq.pop();
    // 输入
    rep(i, 1, m){
        fin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
    }
    // 求最短路
    dijkstra();
    // 输出
    fout << "GO:\n";
    rep(i, 1, t){
        fout << target[i] << ' ' << dis[target[i]] << ' ';
        rep(j, 1, R[target[i]].cnt) fout << R[target[i]].point[j] << "->";
        fout << target[i] << '\n';
    }
    fout << "\n\n";
    fin.close(); fout.close();
    return;
}

void solveback(string place){
    string inputFileName = place + ".carroute", \
           outputFileName = place + ".shortestpath";
    ifstream fin (inputFileName, ios_base::in);
    ofstream fout (outputFileName, ios_base::app);

    fin >> n >> m >> t;
    rep(i, 1, t) fin >> target[i];
    // 初始化
    rep(i, 1, n) dis[i] = INF;
    rep(i, 1, n) adj[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(R, 0, sizeof(R));
    while(!pq.empty()) pq.pop();
    // 输入
    rep(i, 1, m){
        fin >> u >> v >> w;
        adj[v].push_back(Edge(u, w));
    }
    // 求最短路
    dijkstra();
    // 输出
    fout << "BACK:\n";
    rep(i, 1, t){
        fout << target[i] << ' ' << dis[target[i]] << ' ';
        fout << target[i] << "->";
        per(j, R[target[i]].cnt, 2) fout << R[target[i]].point[j] << "->";
        fout << "1\n";
    }
    fin.close(); fout.close();
    return;
}

int main(){
    solvego("BeiJing");
    solvego("YanQing");
    solvego("ZhangJiaKou");
    solveback("BeiJing");
    solveback("YanQing");
    solveback("ZhangJiaKou");
    return 0;
}
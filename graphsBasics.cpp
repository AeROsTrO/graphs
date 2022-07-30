#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define fl(i, l, r, k) for (int i = l; i < r; i += k)
#define vi vector<int>
#define vc vector<char>
#define fe(i, v) for (int i : v)
#define pb push_back
#define pp pop_back
#define in(n) cin >> n
#define out(n) cout << n
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mci map<char, int>
#define pqi priority_queue<int>
#define rpqi priority_queue<int, vector<int>, greater<int>>
#define pii pair<int, int>
#define pci pair<char, int>
#define vpii vector<pair<int, int>>
#define sti stack<int>
#define stc stack<char>
#define qi queue<int>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define sor(v) sort(all(v))
#define readd(a, n) fl(i, 0, n, 1) cin >> a[i];
#define writee(a) fl(i, 0, n, 1) cout << a[i];
#define ln cout << nl;
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return in;
}
#define sp ' '
template <typename T>
void printArr(vector<T> &v)
{
    for (auto &i : v)
        cout << i << ' ';
}
// per aspera ad astra
vi dfs(vector<int> v[], int n)
{
    vi dfst;
    stack<int> s;
    s.push(0);
    bool vis[n] = {false};
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        vis[x] = true;
        dfst.push_back(x);
        for (int nei : v[x])
            s.push(nei), vis[nei] = true;
    }
    return dfst;
}
void dfsRec(vector<int> v[], int source)
{
    cout << source << " ";
    for (int nei : v[source])
        dfsRec(v, nei);
}
vi bfs(vector<int> v[], int source, int n)
{
    vi bfst;
    queue<int> q;
    q.push(source);
    bool vis[n] = {false};
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        bfst.push_back(x);
        vis[x] = true;
        for (int nei : v[x])
            q.push(nei), vis[nei] = true;
    }
    return bfst;
}
void solve()
{
    // directed graph
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    vector<int> v[n]; // adjacency list
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    // vi bfst = bfs(v, 1, n);
    // printArr(bfst);
    dfsRec(v, 1);
}
int main()
{
    FIO;

    solve();

    return 0;
}
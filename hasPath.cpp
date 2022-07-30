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

// directed acyclic graph
bool dfs(vi v[], int source, int destination)
{
    stack<int> s;
    s.push(source);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        for (int nei : v[x])
        {
            if (nei == destination)
                return true;
            else
            {
                s.push(nei);
            }
        }
    }
    return false;
}
bool dfsRec(vi v[], int s, int d)
{
    if (s == d)
        return true;
    for (int nei : v[s])
    {
        if (dfsRec(v, nei, d))
            return true;
    }
    return false;
}
bool bfs(vi v[], int s, int d)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == d)
            return true;
        for (int nei : v[x])
            q.push(nei);
    }
    return false;
}

// undirected graph
// use visited array
bool dfsU(vi v[], int so, int d, int n)
{
    vector<bool> vis(n, false);
    stack<int> s;
    s.push(so);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        vis[x] = true;
        for (int nei : v[x])
        {
            if (!vis[nei])
            {
                if (nei == d)
                    return true;
                else
                    s.push(nei);
            }
        }
    }
    return false;
}
void solve()
{
    // given a directed acyclic graph, find it there exists a valid path between a source and a destination
    int n;
    cin >> n;
    int edg;
    cin >> edg;
    vi v[n];
    for (int i = 0; i < edg; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        // for undirected graph do v[b].push_back(a);
    }
    cout << dfsU(v, 0, 2, n);
}
int main()
{
    FIO;

    solve();

    return 0;
}
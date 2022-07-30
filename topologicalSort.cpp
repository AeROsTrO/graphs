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

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
// graph given should be dag(directed acyclic graph)
// cannot take undirected graph coz we cannot specify which is first
// acyclic because there is no definite order in which they appear
// vector<int> findIndegree(vi v[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         // for (int j = 0; j < n; j++)
//         // {
//         //     if ()
//         // }
//     }
// }
void topoSortBFS(vi v[], int n, vector<int> &indegree, vector<int> &ans)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        ans.push_back(x);
        for (auto nei : v[x])
        {
            if (--indegree[nei] == 0)
                q.push(nei);
        }
    }
    for (int x : ans)
        cout << x << " ";
}
void solve2()
{
    int n, m;
    cin >> n >> m;
    vi v[n];
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        indegree[y]++;
    }
    // for (int i : indegree)
    //     cout << i << " ";
    vector<int> ans;
    vector<bool> vis(n, false);
    topoSortBFS(v, n, indegree, ans);
}
void topoSort(vi v[], int i, vector<bool> &vis, stack<int> &ans)
{
    // this is dfs technique
    vis[i] = true;
    for (auto nei : v[i])
    {
        if (!vis[nei])
            topoSort(v, nei, vis, ans);
    }
    ans.push(i);
    // tc=O(n+e)
    // sc=O(n)+O(n): stack plus recursive space+visited array
}
void solve()
{
    int n;
    cin >> n;
    int ed;
    cin >> ed;
    vector<int> v[n];
    for (int i = 0; i < ed; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    stack<int> ans;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {

            topoSort(v, i, vis, ans);
            // ans.push(i);
        }
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}
int main()
{
    FIO;
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve2();
    }
    return 0;
}
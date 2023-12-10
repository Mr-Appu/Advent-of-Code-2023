#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int n;
int ans;

void bfs(int i, int j, vector <string> &arr, vector<vector<int>> &vis, int length)
{
    if(arr[i][j] == 'S' && vis[i][j]) 
    {
        ans = max(ans, length/2);
        return;
    }

    if(vis[i][j] || arr[i][j] == '.') 
    {
        return;
    }

    vis[i][j] = 1;

    if(arr[i][j] == 'S')
    {
        if(i>0) bfs(i-1, j, arr, vis, length+1);
        if(i<n-1) bfs(i+1, j, arr, vis, length+1);
        if(j>0) bfs(i, j-1, arr, vis, length+1);
        if(j<n-1) bfs(i, j+1, arr, vis, length+1);
    }

    if(arr[i][j] == '|') 
    {
        if(i>0) bfs(i-1, j, arr, vis, length+1);
        if(i<n-1) bfs(i+1, j, arr, vis, length+1);
    }

    if(arr[i][j] == '-')
    {
        if(j>0) bfs(i, j-1, arr, vis, length+1);
        if(j<n-1) bfs(i, j+1, arr, vis, length+1);
    }

    if(arr[i][j] == 'L') 
    {
        if(i>0) bfs(i-1, j, arr, vis, length+1);
        if(j<n-1) bfs(i, j+1, arr, vis, length+1);
    }

    if(arr[i][j] == 'J')
    {
        if(i>0) bfs(i-1, j, arr, vis, length+1);
        if(j>0) bfs(i, j-1, arr, vis, length+1);
    }

    if(arr[i][j] == 'F')
    {
        if(i<n-1) bfs(i+1, j, arr, vis, length+1);
        if(j<n-1) bfs(i, j+1, arr, vis, length+1);
    }

    if(arr[i][j] == '7')
    {
        if(i<n-1) bfs(i+1, j, arr, vis, length+1);
        if(j>0) bfs(i, j-1, arr, vis, length+1);
    }
    
    vis[i][j] = 0;
}

void solve()
{
    n = 140;

    pair <int, int> start;

    vector <string> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
        if (arr[i].find("S") != string::npos)
        {
            start = {i, arr[i].find("S")};
        }
    }  

    vector <vector<int>> vis(n, vector<int> (n, 0));

    bfs(start.first, start.second, arr, vis, 0); 

    cout << ans << '\n';
}
 
signed main(void) 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

	return 0;
}

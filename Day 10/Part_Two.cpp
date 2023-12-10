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
vector <vector<int>> matrix;

// Part - 1

void bfs(int i, int j, vector <string> &arr, vector<vector<int>> &vis, int length)
{
    if(arr[i][j] == 'S' && vis[i][j]) 
    {
        ans = max(ans, length/2);
        if(length/2 == 7173 && matrix.size() == 0) matrix.assign(vis.begin(), vis.end());
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

// Part - 2

void killer(int i, int j, vector<vector<char>> &arr, vector<vector<int>> &vis)
{
    if(arr[i][j] == '#' || vis[i][j] == 1) return;

    queue <pair<int, int>> q;
    
    q.push({i, j});
    vis[i][j] = 1;

    while(!q.empty())
    {
        auto node = q.front(); q.pop();

        int x = node.first;
        int y = node.second;
        
        vector <pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(auto d : dir) 
        {
            int xx = x + d.first;
            int yy = y + d.second;

            if(xx < 0 || yy < 0 || xx == 3*n || yy == 3*n || vis[xx][yy] == 1 || arr[xx][yy] == '#') continue;
            vis[xx][yy] = 1;
            q.push({xx, yy}); 
        }
    }
}


void solve()
{
    n = 140;

    // Part - 1

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

    // cout << ans << '\n';

    // Part - 2

    // Generate a new Pipeline
    vector <vector<char>> island(3*n, vector<char> (3*n, '.'));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j])
            {
                if(arr[i][j] == '|') 
                {
                    island[3*i+0][3*j+1] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+2][3*j+1] = '#';
                }
                if(arr[i][j] == '-')
                {
                    island[3*i+1][3*j+0] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+1][3*j+2] = '#';
                }
                if(arr[i][j] == 'L')
                {
                    island[3*i+0][3*j+1] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+1][3*j+2] = '#';
                }
                if(arr[i][j] == 'J')
                {
                    island[3*i+0][3*j+1] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+1][3*j+0] = '#';
                }
                if(arr[i][j] == 'F')
                {
                    island[3*i+2][3*j+1] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+1][3*j+2] = '#';
                }
                if(arr[i][j] == '7')
                {
                    island[3*i+1][3*j+0] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+2][3*j+1] = '#';
                }
                if(arr[i][j] == 'S')
                {
                    island[3*i+0][3*j+1] = '#';
                    island[3*i+1][3*j+1] = '#';
                    island[3*i+2][3*j+1] = '#';
                    island[3*i+1][3*j+0] = '#';
                    island[3*i+1][3*j+2] = '#';
                }
            }
        }
    }


    vector <vector<int>> island_vis(3*n, vector<int> (3*n, 0));

    for(int i=0; i<3*n; i++)
    {
        for(int j=0; j<3*n; j++)
        {
            if(island[i][j] == '#') island_vis[i][j] = 2;
        }
    }

    for(int i=1; i<3*n; i++)
    {
        killer(0, i, island, island_vis);
        killer(i, 0, island, island_vis);
        killer(3*n-1, i, island, island_vis);
        killer(i, 3*n-1, island, island_vis);
    }

    // for(auto i : island_vis)
    // {
    //     for(auto j : i) cout << j << ' ';
    //     cout << '\n';
    // }

    int ans_part_2 = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(island_vis[3*i + 1][3*j + 1] == 0) ans_part_2++;
        }
    }

    cout << ans_part_2 << '\n';
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

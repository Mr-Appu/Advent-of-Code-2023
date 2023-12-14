#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;
  
void compute()
{

}

int calc_load(vector <string> &arr)
{
    int n = arr.size();
    int ans = 0;

    for(int i=0; i<arr[0].size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j][i] == 'O')
            {
                ans += (n - j);
            }
        }
    }

    return ans;
}

void cycle(vector <string> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    // North
    for(int temp=0; temp<=100; temp++)
    {    
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                if(arr[j][i] == '.' && arr[j+1][i] == 'O') 
                {
                    arr[j][i] = 'O';
                    arr[j+1][i] = '.';
                }
            }
        }
    }

    // West
    for(int temp=0; temp<=100; temp++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                if(arr[i][j] == '.' && arr[i][j+1] == 'O') 
                {
                    arr[i][j] = 'O';
                    arr[i][j+1] = '.';
                }
            }
        }
    }

    // South
    for(int temp=0; temp<=100; temp++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=n-1; j>0; j--)
            {
                if(arr[j][i] == '.' && arr[j-1][i] == 'O') 
                {
                    arr[j][i] = 'O';
                    arr[j-1][i] = '.';
                }
            }
        }
    }

    // East
    for(int temp=0; temp<=100; temp++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=m-1; j>0; j--)
            {
                if(arr[i][j] == '.' && arr[i][j-1] == 'O') 
                {
                    arr[i][j] = 'O';
                    arr[i][j-1] = '.';
                }
            }
        }
    }
}

void solve()
{
    int n = 100;
    
    vector <string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0;
    
    unordered_map <string, int> mp, freq;

    // This part was inspired from https://www.youtube.com/watch?v=4Ms3SN0lpxE [Jonathan Paulson]
    // Tried memorization

    for(int i=1; i<=1000000000; i++)
    {
        cycle(arr);
        ans = calc_load(arr);

        string temp;
        for(auto i : arr) temp += i;

        if(mp.find(temp) != mp.end() && freq[temp] >= 5)
        {
            int diff = i - mp[temp];
            
            int next = ((1000000000 - i) / diff)  * diff;
            i += next; 
        }

        freq[temp]++;
        mp[temp] = i;
    }

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

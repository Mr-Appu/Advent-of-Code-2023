#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}


void solve()
{
    int n = 100;
    
    vector <string> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0;

    for(int i=0; i<arr[0].size(); i++)
    {
        int temp = n;
        for(int j=0; j<n; j++)
        {
            if(arr[j][i] == '#')
            {
                temp = n-j-1;
            }
            else if(arr[j][i] == 'O')
            {
                ans += temp;
                temp--;
            }
        }
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

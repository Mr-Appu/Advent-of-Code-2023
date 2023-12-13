#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int MOD =  1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e10;

void compute()
{

}

int ANS = 0;

int func(vector <string> &str)
{
    int n = str.size();

    unordered_map<string, int> mp;
    vector <int> vec;
    
    int index = 1;
    for(int i=0; i<n; i++)
    {
        if(mp.find(str[i]) != mp.end()) vec.push_back(mp[str[i]]);
        else {
            mp[str[i]] = index;
            vec.push_back(mp[str[i]]);
            index++;
        }
    }

    int ans = -1;
    unordered_map <int, int> temp;

    for(int i=1; i<n; i++)
    {
        if(vec[i] == vec[i-1])
        {
            int left = i-1;
            int right = i;

            int flag = 1;
            while(left >= 0 && right < n)
            {
                if(vec[left] == vec[right])
                {
                    left--;
                    right++;
                }
                else 
                {
                    flag = 0;
                    break;
                }
            }

            if(flag) ans = i;
        }
    }

    if(ans == -1) return -1;

    return ans;
}

void solve()
{
    int n; cin >> n;
    
    vector <string> str(n);
    for(int i=0; i<n; i++) cin >> str[i];
    
    // Horizontal
    int row = func(str);

    // Vertical
    vector <string> tstr(str[0].length());
    for(int i=0; i<str[0].length(); i++)
    {
        string temp = "";
        for(int j=0; j<n; j++)
        {
            temp += str[j][i];
        }
        tstr[i] = temp;
    }

    int col = func(tstr);

    if(row != -1) ANS += row*100;
    else ANS += col;
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
    cin >> t;

    compute();
    
    for(int i=0;i<t;i++)
    {
        // cout << "Case #" << i+1 << ": "; // Kick Start
        solve();
    }

    cout << ANS << '\n';

	return 0;
}

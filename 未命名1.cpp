#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
const int dx[8] = {-1,0,1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1};
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {  
        if (ch == '-') w = -1;        
        ch = getchar();               
    }
    while (ch >= '0' && ch <= '9')
    {  
        x = x * 10 + (ch - '0');
        ch = getchar();  
    }
    return x * w; 
}
int n,k;
vector<int> a[11];
__int128_t cnt=1;
set<int> end1[10]={};
void dfs(int w,int c)
{
    if(c>=15)
        return;
    for(auto i:a[w])
    {
        end1[w].insert(i);
        dfs(i,c+1);
    }
    return;   
}
void solve()
{
    cin>>n>>k;
    for (int i = 0; i < k; i++)
    {
        int b,e;
        cin>>b>>e;
        a[b].push_back(e);
    }
    for (int i = 0; i < 10; i++)
    {
        end1[i].insert(i);
        dfs(i,0);
    }
    int shul[10]={};
    for(int i=0;i<10;i++)
    {
        shul[i]=end1[i].size()-1;
    }
    while (n)
    {
        int k=n%10;
        n/=10;
        cnt*=shul[k];
    }
    stack<int> e;
    while (cnt)
    {
        e.push(cnt%10);
        cnt/=10;
    }
    while (!e.empty())
    {
        cout<<e.top();
        e.pop();
    }
    
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}
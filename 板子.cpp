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

void solve()
{
    
}
struct node{
    int len1;
    int pre1;
    int sur1;
    int arr;
};
node tree[4*N];
void push_up(int rt,int l,int r)
{
    tree[rt].len1=max(tree[rt<<1].len1,tree[rt<<1|1].len);
    tree[rt].pre1=tree[rt<<1].pre1;
    tree[rt].sur1=tree[rt<<1|1].sur1;
    int mid=l+r>>1;
    int ln=mid-l+1;
    int rn=r-mid;
    if(a[mid]!=a[mid+1])
    {
        len=max(len,tree[rt<<1].sur1+tree[rt<<1|1].pre1);
        if(tree[rt<<1].len1==ln)
        {
            tree[rt].pre1=ln+tree[rt<<1|1].pre1;
        }
        if(tree[rt<<1|1].len1==rn)
        {
            tree[rt].sur1=rn+tree[rt<<1].sur1;
        }
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt].len1=1;
        tree[rt].pre1=1;
        tree[rt].sur1=1;
        return ;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,rt<<1|1);
    push_up(rt,l,r);
}

void remove(int i,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]^=1;
        return ;
    }
    int mid=l+r>>1;
    if(i<=mid) remove(i,l,mid,rt<<1);
    if(i>mid) remove(i,mid+1,r,rt<<1|1);
    push_up(rt,l,r);
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
#include<bits/stdc++.h>
using namespace std;
struct point
{
    int color[26],change[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
}tree[100001 * 4];
short v[100001]; int n, m;;
int ls(int x)
{
    return x * 2;
}
int rs(int x)
{
    return x * 2 + 1;
}
void merge(int end[],int a[],int b[])
{
    for (int i = 0; i <= m; i++)
    {
        end[i]=a[i]+b[i];
    }
    return;
}
void apply(int end[],int a[],int b[]) //a[]是本层的change b[] 是上层的  end[]也就是r[]
{
    for (int i = 0; i <= m; i++)
    {
        end[i]=a[b[i]];
    }
    return;
}
void merge1(int end[],int a[],int b[]) //a[]是本层的原颜色 b[]就是change  end[]也就是颜色
{
    int color[26];
    for (int i = 0; i <= m; i++)
    {
        color[i]=a[i];
    }
    
    for (int i = 0; i <= m; i++)
    {
        end[i]=color[b[i]];
    }
    return;
}
void _clear(int x)
{
    for (int i = 0; i <= m; i++)
    {
        tree[x].change[i]=i;
    }
    return;
}
void push_up(int root)
{
    apply(tree[root].color,tree[root*2].color,tree[root*2+1].color);
}

void push_down(int root, int  l, int r)
{
    apply(tree[ls(root)].change,tree[ls(root)].change,tree[root].change);//往左子树传递
    apply(tree[rs(root)].change,tree[rs(root)].change,tree[root].change);//往右子树传递
    merge1(tree[root].color,tree[root].color,tree[root].change);//更改自己的color的顺序
    _clear(root);
    
}
void change(int root, int l, int r, int l1, int r1, short color1, short color2)//前改后范围
{
    if (l == l1 && r == r1)
    {
        swap(tree[root].change[color1],tree[root].change[color2]);
    }
    push_down(root, l1, r1);
    int mid = (l1 + r1) / 2;
    if (r <= mid)
        change(ls(root), l, r, l1, mid, color1, color2);
    else if (l > mid)
        change(rs(root), l, r, mid + 1, r1, color1, color2);
    else
    {
        change(ls(root), l, mid, l1, mid, color1, color2);
        change(rs(root), mid + 1, r, mid + 1, r1, color1, color2);
    }
    push_up(root);
    return;
}

int find(int root, int l, int r, int l1, int r1, short color)//前查询后范围
{
    push_down(root, l1, r1);
    if (l == l1 && r == r1)
    {
        return tree[root].color[tree[root].change[color]];
    }
    
    int mid = (l1 + r1) / 2;
    if (r <= mid)
        return find(ls(root), l, r, l1, mid, color);
    else if (l > mid)
        return find(rs(root), l, r, mid + 1, r1, color);
    else
    {
        return find(ls(root), l, mid, l1, mid, color) + find(rs(root), mid + 1, r, mid + 1, r1, color);
    }
}

void build(int root, int l, int r)
{
    if (l == r)
    {
        tree[root].color[v[l]]++;
        return;
    }
    int mid = (l + r) / 2;
    build(ls(root), l, mid);
    build(rs(root), mid + 1, r);
    push_up(root);
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;short color1, color2;
            cin >> l >> r >> color1 >> color2;
            change(1, l, r, 1, n, color1, color2);
        }
        else
        {
            int l, r;short color;
            cin >> l >> r >> color;
            cout << find(1, l, r, 1, n, color) << endl;
        }

    } 
}
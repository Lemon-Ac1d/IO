#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5 + 10;
int t, n, f[1000007], book[1000007 * 3]; // t表示t组数据，n表示有n个操作，f[]是我们并查集的数字，book[]是离散化的数组
struct node
{
    int x, y, e;
} a[1000001];
bool cmp(node a, node b)
{
    return a.e > b.e;
}

inline void first(int kkk)
{
    for (int i = 1; i <= kkk; i++)
        f[i] = i;
} // 初 始 化
int find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}
int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        int tot = -1;
        int flag = 1;
        memset(book, 0, sizeof(book));
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));

        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> a[i].e;
            book[++tot] = a[i].x;
            book[++tot] = a[i].y;
        }
        sort(book, book + tot); // 排序
        int reu = unique(book, book + tot) - book; // 去重
        for (int i = 1; i <= n; ++i)
        {
            a[i].x = lower_bound(book, book + reu, a[i].x) - book;
            a[i].y = lower_bound(book, book + reu, a[i].y) - book;
        }

        first(reu);
        sort(a + 1, a + n + 1, cmp); // 按e排序
        for (int i = 1; i <= n; i++)
        {
            int r1 = find(a[i].x);
            int r2 = find(a[i].y);
            if (a[i].e)
            {
                f[r1] = r2; // 就是我们的merge操作
            }
            else if (r1 == r2)
            {
                printf("NO\n");
                flag = 0; // 如果不满足条件，标记为否
                break;
            }
        }
        if (flag)
            printf("YES\n"); // 都满足条件了
    }

    return 0;
}
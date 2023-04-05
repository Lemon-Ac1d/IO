#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx, dist[N];
int n, m, x, y, z;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    if(spfa() > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else    cout << dist[n] << endl;


    return 0;
}
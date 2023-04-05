#include<bits/stdc++.h>

using namespace std;
std::map<int,int> m;
typedef std::map<int,int>::iterator it;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    for( int i = 0; i < n; i++){
        int t;
        cin >> t;
        ++m[t];
    }

    while(!m.empty())
    {
        it i = m.begin(),j = m.begin();
        int t = 1;
        for(j++; j!=m.end() && (*j).first == (*i).first + 1 && (*j).second > (*i).second; i++,j++){
            ++t;
            --(*j).second;
        }
        i = m.begin();
        while(i != m.end() && (*i).second == 0){
            m.erase((*i++).first);
        }
    }

    

    return 0;
}
#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, op, score;
    string name;
    map<string,int> m;

    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1){
            cin >> name >> score;
            m[name] = score;
            cout << "OK" << endl;
        }
        else if(op == 2){
            cin >> name;
            if(m.count(name))
            cout << m[name] << endl;
            else cout << "Not found\n";
        }
        else if(op == 3){
            cin >> name;
            if (m.count(name))
            {                                     // 如果找得到
                m.erase(name);                    // 那就删了它
                cout << "Deleted successfully\n"; // 成功删除
            }
            else
                cout << "Not found\n";
        }
        else
            cout << m.size() <<endl;
    }

    return 0;
}
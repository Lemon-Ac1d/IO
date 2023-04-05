#include<iostream>

using namespace std;
const int N = 2e5 + 10;
int n;
double p;
double a[N], b[N];
double lbound = 0, rbound = 1e10;
double sum = 0;
int check(double ans)
{                       // 验证答案
    double q = p * ans; // 充电器最多提供的能量
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * ans <= b[i])
        {             // 若设备已有的能量大于使用时间需要的能量
            continue; // 忽略该设备
        }
        sum += (a[i] * ans - b[i]); // 否则用充电器充电，使设备已有的能量等于使用时间需要的能量，并记录需要的能量。
    }
    return sum <= q; // 最后比较需要的能量总和和充电器最多提供的能量。
}

int main(){
    cin >> n >> p;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if(sum <= p){
        cout << -1.000000 << endl;
        return 0;
    }


        while (rbound - lbound > 1e-6)
        {
            double mid = (lbound + rbound) / 2;
            if (check(mid))
            {
                lbound = mid;
            }
            else
            {
                rbound = mid;
            }
        }
    
    cout << lbound << endl;
    return 0;
}
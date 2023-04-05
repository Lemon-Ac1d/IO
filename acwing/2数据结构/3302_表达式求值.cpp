#include<iostream>
#include <unordered_map>
#include<stack>
using namespace std;
stack<int> num;
stack<char> op;

void eval(){
    int b = num.top(); num.pop();
    char c = op.top(); op.pop();
    int a = num.top(); num.pop();
    int res = 0;
    if(c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*')  res = a * b;
    else res = a / b;
    num.push(res);   
}

int main(){
    string s;

    cin >> s;

    unordered_map<char, int> pr = {{'-', 1}, {'+', 1}, {'*', 2}, {'/', 2}};

    for(int i = 0; i < s.size(); i++){
        auto c = s[i];
        if(isdigit(c)){
            int x = 0, j = i;
            while(j < s.size() && isdigit(s[j])){
                x = x * 10 + s[j++] - '0';
            }
            i = j - 1;
            num.push(x);
        }
        else if(c == '(')   op.push(c);
        else if(c == ')'){
            while(op.top() != '('){
                eval();
            }
            op.pop();
        }
        else{
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while(op.size())
        eval();
    cout << num.top() << endl;

    return 0;
}
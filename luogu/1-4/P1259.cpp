#include<bits/stdc++.h>

using namespace std;

void initial(int n){
    for(int i=0 ; i< n ; i++ )  putchar('o');
    for(int i=0 ; i< n ; i++ )  putchar('*');
    putchar('-');
    putchar('-');

}
void add(int n){
    for(int i = 1 ; i <= n ; i++ ){
        putchar('o');
        putchar('*');
    }
}
void move(int n){
    for(int i=0 ; i< n-1 ; i++ )  putchar('o');
    putchar('-');
    putchar('-');
    for(int i=0 ; i< n-1 ; i++ )  putchar('*');
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = n; i>=4; i--){
        initial(i);
        add(n-i);
        putchar('\n');
        move(i);
        add(n-i+1);
        putchar('\n');
    }    

    printf("ooo*o**--*");
    add(n-4);putchar('\n');

    printf("o--*o**o");add(n-3);putchar('\n'); 
    
    add(3);putchar('-');putchar('-');add(n-3);putchar('\n'); 

    putchar('-');putchar('-');add(n);putchar('\n'); 

    return 0;
}
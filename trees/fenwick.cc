#include <bits/stdc++.h> 

using namespace std;

struct bit {
    int n; 
    vector<int> v; 
    bit(int n) : n(n), v(n) {};

    int f(int x, int y) { 
        return x + y; 
    } 

    void update(int x, int y) {
        x++;
        for (; x <= n; x += x & -x) 
            v[x - 1] = f(v[x - 1], y);  
    }

    int query(int x) {
        x++;
        int y = 0;
        for (; x; x -= x & -x) 
            y = f(v[x - 1], y); 
        return y;
    }
};

int main() {
    bit b(10); // Our fenwick tree holds up to 10 elements. 
    b.update(1, 1);
    cout << b.query(2) << '\n'; 
}
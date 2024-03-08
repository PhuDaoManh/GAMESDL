
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int n,q;
        cin >> n >> q;
        vector<vector<int>> mangbiendoi;
        vector<int> a;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            for(int j=0;j<k;j++){
                int c;
                cin >> c;
                a.push_back(c);
            }mangbiendoi.push_back(a);
        }int somang,thutu;

        for(int i=0;i<q;i++){
            cin >> somang>> thutu;
            cout << mangbiendoi[somang][thutu];}
}




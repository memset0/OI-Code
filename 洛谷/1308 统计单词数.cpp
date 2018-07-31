#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++)
        a[i] = tolower(a[i]);
    for (int i = 0; i < b.length(); i++)
        b[i] = tolower(b[i]);
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    if (b.find(a)==string::npos) {
        cout<<-1<<endl;
        return 0;
    }
    
    int t = b.find(a), cnt=0;
    while (t != string::npos){
        t = b.find(a,t+1);
        cnt ++;
    }
    cout << cnt << " " << b.find(a) << endl;
    return 0;
}

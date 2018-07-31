#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;
    int i,j;
    int flag = 0;
    cin >> a >> b;
    for(i = 0, j = 0; b[j]!= '\0';){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            flag++;
            j=0;
            i=flag;
        }
    }
    cout << flag + 1;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n;
    vector <int> a;
    vector <int> b;
    int last[n];
    int p[n];
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
        b.push_back(10000);
    }
    b[0]=-1;
    b[n]=10000;
    last[0]=0;
    for(int i=0;i<n;i++){
        int j = upper_bound ( b.begin(),b.end(),a[i] ) - b.begin();
        if(b[j-1]<a[i]){
            b[j]=a[i];
            if (k<j) k=j;
            last[j]=i;
            p[i]=last[j-1];
        }
        else{
            p[i]=p[last[j-1]];
        }
    }
    cout << k << endl;
    x=last[k];
    for(int i=0;i<k;i++){
        cout << a[x];
        x=p[x];
    }
    return 0;
}

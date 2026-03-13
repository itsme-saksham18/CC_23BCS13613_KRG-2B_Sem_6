#include<bits/stdc++.h>
using namespace std;
int SingleNumII(vector<int>& arr)
{
    int ans = 0;
    for(int i = 0; i < 32; i++)
    {
        int count = 0;
        for(int num : arr)
        {
            if(num & (1 << i))
                count++;
        }
        if(count % 3 != 0)
            ans |= (1 << i);
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int singleNum = SingleNumII(arr);
    cout<<singleNum<<endl;
}

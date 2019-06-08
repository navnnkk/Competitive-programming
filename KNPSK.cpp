#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n,w,c,sum = 0,w_sum = 0,c_sum = 0;
    cin>>n;

    vector<pair<int,int>>v1;
    vector<pair<int,int>>v2;
    vector<long long>vect;

    for(int i=0;i<n;i++)
    {
        cin>>w>>c;
        sum += w;
        if(w == 1)
            v1.pb(make_pair(w,c));
        if(w == 2)
            v2.pb(make_pair(w,c));
    }

    int m = v2.size() - 1;

    sort(v1.begin(),v1.end(),compare);
    sort(v2.begin(),v2.end(),compare);

    for(int i = 1;i <= sum ;i++)
    {
        if((i - w_sum) % 2 != 0)
            c_sum += v1[v1.size()-1].second;
        else
        {
            while(i - w_sum != 0)
            {
                c_sum -= v1[v1.size()-1].second;
                w_sum += 2;
                c_sum = c_sum + v2[m--].second;
            }
        }
        vect.pb(c_sum);
    }

    for(int i=0;i<vect.size();i++)
        cout<<vect[i]<<" ";
    cout<<endl;

    return 0;
}

ll lps[N];
void ini(string &s)
{
    ll j=0;
    ll i=1;
    lps[0]=0;
    while(i<s.size())
    {
        if(s[i]==s[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(!j)
            {
                lps[i++]=0;
            }
            else
                j=lps[j-1];
        }
    }
}

void solve()
{
    ll i,j;
    string s,t;
    cin>>s>>t;
    ini(t);
    i=0;j=0;
    vector<ll> ans;
    while(i<s.size())
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        if(j==t.size())
        {
            ans.pb(i-j);
            cout<<i-j<<" ";
            j=lps[j-1];
        }
        else if(i<s.size() && s[i]!=t[j])
        {
            if(!j)
                i++;
            else
                j=lps[j-1];
        }
    }
}

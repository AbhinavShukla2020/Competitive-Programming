vi getDivs(int n)
{
    vi ans;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
               ans.pb(i);
            else{
            	ans.pb(i);
            	ans.pb(n/i);
            }
        }
    }
    return ans;
}

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow (string S, string P){
     string res = "";
    int i=0;
    int j=0;
    int x=0;
    int l=0;
    int r = 0;
    int arr[256]={0};
    for(int i=0;i<P.size();i++)
    {
        arr[P[i]]++;
    }
    int count = P.size();
    while(r<S.size())
    {
        if(arr[S[r]]>0)
        {
            count--;
        }
        arr[S[r]]--;
        while(count==0)
        {
            if(j==0 || r-l<j-i)
            {
                i=l;
                x = i;
                j=r;
            }
            arr[S[l]]++;
            if(arr[S[l]]>0)
            {
                count++;
            }
            l++;
        }
        r++;
    }
    if(i==0 && j==0)
    {
        return "-1";
    }
    else{
    for(i=x;i<=j;i++)
    {
        res=res+S[i];
    }
    return res;
    }
}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;

        cout<<smallestWindow(s, pat)<<endl;

    }
	return 0;
}  // } Driver Code Ends

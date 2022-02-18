class Solution{
  public:
  unordered_set<string> out;
    void isPalindrome(string &s,int l,int r,int n)
    {
        string temp="";
            while((l>=0&&r<n)&&(s[l]==s[r]))
            {
                if(l==r)
                {
                    temp=temp+s[l];
                } 
                else
                {
                    temp=s[l]+temp+s[r];
                }
                out.insert(temp);
                l--;r++;
            }
    }
    unordered_set<string> palindromeSubStrs(string s) {
        // code here
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            isPalindrome(s,i,i+1,n);
            isPalindrome(s,i,i,n);
        }
        return out;
    }
};
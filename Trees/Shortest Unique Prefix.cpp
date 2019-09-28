/* 
Shortest Unique Prefix
Find shortest unique prefix to represent each word in the list. Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node
{
    unordered_map<char,node*> mp;
    bool end;
    
    node(bool e)
    { end=e; }
};

class trie
{
    public:
    node *root=NULL;
    
    node* ins(string &str,int i,node* rt)
    {
        if(i==str.size())
        {
            if(rt==NULL)
            {
                node *tmp=new node(1);
                return tmp;
            }
            rt->end=1;
            return rt;
        }
        
        if(rt==NULL){ rt=new node(0); }
        
        rt->mp[str[i]]=ins(str,i+1,rt->mp[str[i]]);
        return rt;
    }
    
    void  insert(string &str)
    {
        root=ins(str,0,root);
    }
    
    void getprf(string &A, int i, int &fl, string &s, node* rt)
    {
        if(i>=A.size()){ return; }
        
        getprf(A,i+1,fl,s,rt->mp[A[i]]);
        if((rt->mp).size()>1){ fl=1; }
        
        if(fl){ s+=A[i]; }
    }
        
    string getprefix(string &A)
    {
        int fl=0;  string s="";
        getprf(A,0,fl,s,root);
        
        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            char ch=s[i]; s[i]=s[j]; s[j]=ch;
            i++; j--;
        }
        
        if(s.empty()){ s+=A[0]; }
        return s;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    
    
    vector<string> vt;
    trie t;
    
    for(int i=0; i<A.size(); i++){ t.insert(A[i]); }
    
    for(int i=0; i<A.size(); i++){ vt.push_back( t.getprefix(A[i]) ); }
    
    return vt;
}

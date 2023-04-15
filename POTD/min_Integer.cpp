//! Question : You are given an array A of size N. Let us denote S as the sum of all integers present in the array. Among all integers present in the array, find the minimum integer X such that S ≤ N*X.
/* Example 1:

 Input:
 N = 3,
 A = { 1, 3, 2}
 Output:
 2
 Explanation:
 Sum of integers in the array is 6.
 since 6 ≤ 3*2, therefore 2 is the answer  
 */
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
   int minimumInteger(int N, vector<int> &a)
{
    long long  int sum = 0,i,min,ans,c=0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }
  
    for(i=0;i<N;i++)
    {
        long long int x = a[i];
        if(sum <= x*N)
        {
            
            min = x;
            if(c==0)  //only enter at once
            {
                ans = min;
            }
            
            if(min < ans)
            {
                ans = min;
            }
            c++;
        }
    }
    return ans;
}

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
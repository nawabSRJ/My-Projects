//! Question : Given an unsorted array Arr[] of N integers and a Key which is present in this array. You need to write a program to find the start index( index where the element is first found from left in the array ) and end index( index where the element is first found from right in the array ).If the key does not exist in the array then return -1 for both start and end index in this case.

#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 


class Solution
{
  public:
    vector <int> findIndex(int a[], int n, int key)
    {
        int i, first_ind = -1, last_ind = -1, found = 0;
        
        for(i=0;i<n;i++)
        {
            if(a[i] == key)
            {
                first_ind = i;
                found = 1;
                break;
            }
           
        }
        
        for(i=n-1;i>=0;i--)
        {
            if(a[i] == key)
            {
                last_ind = i;
                found = 1;
                break;
            }
            
        }
       
        vector<int> indices;
        if (found) {
            indices.push_back(first_ind);
            indices.push_back(last_ind);
        } else {
            indices.push_back(-1);
            indices.push_back(-1);
        }
        return indices;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends
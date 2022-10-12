
// All Tracks>Algorithms> Dynamic Programming> Introduction to Dynamic Programming 1> Problem
// Selection of Numbers
// 1383
// 77%
// 30
// ★★★★★3.1
// 14 votes
// Algorithms, Dynamic Programming, Medium, Prefix sum, prefix sum
// Share
// Details
// Submissions
// Discussion
// Similar Problems
// Editorial
// Updated problem name:
// Selection of numbers

// Updated problem statement:

// You are given N numbers placed in a line. You have to select K numbers from those numbers. The priority level of the numbers is different.
// You can select numbers from end only. You want to maximize the total priority level of the numbers. Your task is to find the maximum priority level.

// Author's Solution
// #include <iostream>
// using namespace std;


// long long arr[100005];
// int main()
// {
//     int k,n;
//      freopen("input1.txt","r",stdin);
//       freopen("output1.txt","w",stdout);
//     cin>>k>>n;
//     long long sum =0;
//     arr[0] = 0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>arr[i];
//         sum+=arr[i];
        
//         arr[i]+=arr[i-1];
        
//     }
//     int p = n-k;
//     long long maxi = 0;
//     for(int i=1;i<=n-p+1;i++){
        
//         long long here = arr[i+p-1] - arr[i-1];
//         maxi =max(maxi,sum-here);
        
        
        
        
        
//     }
//     cout<<maxi;
// }
// ?


// All Tracks>Algorithms> Dynamic Programming> Introduction to Dynamic Programming 1> Problem
// Selection of Numbers
// 1383
// 77%
// 30
// ★★★★★3.1
// 14 votes
// Algorithms, Dynamic Programming, Medium, Prefix sum, prefix sum
// Share
// Details
// Submissions
// Discussion
// Similar Problems
// Editorial
// Updated problem name:
// Selection of numbers

// Updated problem statement:

// You are given N numbers placed in a line. You have to select K numbers from those numbers. The priority level of the numbers is different.
// You can select numbers from end only. You want to maximize the total priority level of the numbers. Your task is to find the maximum priority level.

// Author's Solution
#include <iostream>
using namespace std;


long long arr[100005];
int main()
{
    int k,n;
     // freopen("input1.txt","r",stdin);
     //  freopen("output1.txt","w",stdout);
    cin>>k>>n;
    long long sum =0;
    arr[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        
        arr[i]+=arr[i-1];
        
    }
    int p = n-k;
    long long maxi = 0;
    for(int i=1;i<=n-p+1;i++){
        
        long long here = arr[i+p-1] - arr[i-1];
        maxi =max(maxi,sum-here);
        
        
        
        
        
    }
    cout<<maxi;
}
// ?


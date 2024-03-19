#include <bits/stdc++.h>
using namespace std;
long long int maxSubarrayProduct(int arr[], int n)
{
   long long ans=INT_MIN;
   long long product=1;
    
   for(int i=0;i<n;i++){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
    
   product=1;
    
   for(int i=n-1;i>=0;i--){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
   return ans;
}
 
int main()
{
    int n ;
    cout<<"Input the length of array n";
    cin >> n;

    int arr[n];

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}
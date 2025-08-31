#include<iostream>
#include<vector>
#include<climits>

using namespace std;

 bool iscorrect(vector<int>arr,int n , int m, int maxivalue){
    int painter = 1, time = 0;
    for(int i = 0;i<n;i++){
        if(time + arr[i] <= maxivalue){
            time += arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
    }
    return painter<=m;
 }
int Possible(vector<int>arr, int n , int m){
  
    int sum =0, maxvalue =INT_MIN;
    if(m>n){
        return -1;
    }
    for(int i =0; i<n;i++){
        sum += arr[i];
        maxvalue = max(maxvalue, arr[i]);
    }
    int st = maxvalue, end = sum , ans = -1;
    while(st<=end){
        int mid = st + (end - st)/2;
        if(iscorrect(arr, n, m, mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            st = mid +1;
        }
    }
    return ans;

}
int main(){

    vector<int>arr={10,20,30,40};
int n =4,  m =2;
cout<<Possible(arr,n,m);
    return 0;
}
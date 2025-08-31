#include<iostream>
#include<vector>

using namespace std;
 
class BinarySearch{
 public:
 int data;
 BinarySearch*left;
 BinarySearch*right;
 BinarySearch(int val){
    data = val;
    left = right = NULL;
 }
};
 
BinarySearch*insert(BinarySearch*root,int val){
    if(root == NULL){
        return new BinarySearch(val);
    }
    if(val < root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

BinarySearch*uploading(vector<int>&arr){
    BinarySearch*root = NULL;
    for(int i : arr){
        root = insert(root,i);
    }
    return root;
}

void inorder(BinarySearch*root, vector<int>&arr){
    if(root == NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
BinarySearch*BST_setup(vector<int>&arr,int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end -st)/2;
    BinarySearch *root = new BinarySearch(arr[mid]);
     root->left = BST_setup(arr,st,mid-1);
     root->right = BST_setup(arr,mid+1,end);
    return root;

}

BinarySearch*Merging(BinarySearch*root1,BinarySearch*root2){
 
    vector<int>arr1,arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);
    vector<int>temp;
    int i = 0 , j= 0;
    while(i < arr1.size() && j < arr2.size()){
      
        if(arr1[i] < arr2[j]){
         temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i < arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        temp.push_back(arr2[j++]);
    }
    return BST_setup(temp,0,temp.size()-1);
    
}

int main(){
  vector<int> arr1 = {8,2,1,10};
  vector<int> arr2 = {5,3,0};

  BinarySearch*ans1 = uploading(arr1);
  BinarySearch*ans2 = uploading(arr2);

  BinarySearch*oneans = Merging(ans1,ans2);
  vector<int>sq;
  inorder(oneans,sq);
  for(int i : sq){
    cout<<i<<" ";
  }
 cout<<endl;
return 0;
}
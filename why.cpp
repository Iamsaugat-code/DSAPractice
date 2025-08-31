#include<iostream>
#include<vector>
using namespace std;
class Binary{
 public:
 int data;
 Binary*left;
 Binary*right;
 Binary(int val){
  data = val;
  left = right = NULL;
 }

};

Binary*insert(Binary*root, int val){
  if(root == NULL){
    return new Binary(val);

  }
  if(val < root->data){
    root->left= insert(root->left,val);
  }
  else {
    root->right = insert(root->right,val);
  }
 
}
Binary * Firstcase(vector<int>&arr){
 Binary*root = NULL;
 for(int val : arr){
  root = insert(root,val);
 }
 return root;
}
 
bool search(Binary *root, int key){
if( root == NULL){
  return false;
}
if(key==root->data){
  return true;
}
else if( key < root->data){
  return search(root->left,key);
}
else{
  return search(root->right,key);
}
}
 
void inorder(Binary*root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
Binary*Successor(Binary*root){
  while(root != NULL && root->left != NULL){
    root = root->left;
  }
  return root;
}
Binary* deletedata(Binary*root,int key){
  if(root == NULL){
    return NULL;
  }
  if(key < root->data){
     root->left = deletedata(root->left,key);

  }
  else if(key > root->data){
    root->right=deletedata(root->right,key);
  }
  else{
    if(root->left == NULL){
      Binary*temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL){
      Binary*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Binary * Is = Successor(root->right);
      root->data = Is->data;
      root->right = deletedata(root->right,Is->data);
    }
  }
}
int main(){
 vector<int>v = {3,2,1,5,6,4};
  Binary*ans = Firstcase(v);
  cout<<" Inorder set : ";
  inorder(ans);
  cout<<"\n Result : "<<search(ans,10);
  deletedata(ans,5);
  cout<<endl;
  cout<<" New set : ";
  inorder(ans);
  return 0;
}
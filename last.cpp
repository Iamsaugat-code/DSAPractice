#include<iostream>
#include<vector>

using namespace std;

class Number{
 public:
 int val;
 Number*left;
 Number*right;
 Number(int val){
    this->val = val;
    left = right = NULL;
 }    

};

Number*leftmost(Number*root){
    Number*ans;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}
Number*rightmost(Number*root){
    Number*ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}
vector<int>finding(Number*root, int key){
    Number*cur = root;
    Number*pred = NULL;
    Number*suc = NULL;
    while(cur != NULL){
        if(cur->val > key){
            suc = cur;
            cur= cur->left;
        }
        if(cur->val < key){
            pred = cur;
            cur = cur->right;
        }
        else{
            if(cur->left != NULL){
                pred = leftmost(root->left);
            }
            if(cur->right != NULL){
                suc = rightmost(root->right);
            }
            break;
        }
    }
    return {pred->val, suc->val};
}
int main(){

  Number*root = new Number(6);
  root->left = new Number(4);
  root->left->left = new Number(1);
  root->left->right = new Number(5);
  root->right = new Number(8);
  root->right->left = new Number(7);
  root->right->right = new Number(9);

  int val = 6;
  vector<int>ans = finding(root, val);
  cout<<" Preorder val :  "<<ans[0]<<endl;
  cout<<" Successor val : "<<ans[1]<<endl;
    return 0;
}
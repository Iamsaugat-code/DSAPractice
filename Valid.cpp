#include<iostream>
#include<climits>
using namespace std;

class Height{
  
    public:
    int data;
    Height*left;
    Height*right;
    Height(int val){
        data = val;
        left = right = NULL;
    }
};

class boy{
     public:
     int mini,maxi,size;
     boy(int mi, int ma,int  si){
      mini = mi;
      maxi = ma;
      size = si;
     }
};
boy helper(Height*root){
 if(root == NULL){
    return boy(INT_MAX,INT_MIN,0);

 }
 boy leftside = helper(root->left);
 boy rightside = helper(root->right);
 if(root->data > leftside.maxi && root->data < rightside.mini){
    int curmin = min(root->data,leftside.mini);
    int curmax = max(root->data,rightside.maxi);
    int cursize = leftside.size + rightside.size+1;
    return boy(curmin,curmax, cursize);
 }
 else{
    return boy(INT_MIN,INT_MAX,max(leftside.size,rightside.size));
 }
}
int show(Height*root){
    boy ans = helper(root);
    return ans.size;
};
int main(){
    Height*root = new Height(10);
    root->left = new Height(5);
    root->right =new Height(15);
    root->left->left = new Height(1);
    root->left->right = new Height(8);
    root->right->right = new Height(20);
    cout<<" ans : "<<show(root);
    return 0;
}
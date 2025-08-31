#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Boy{

    public: 
    int data;
    Boy*left;
    Boy*right;
    Boy(int val){
        data = val;
        left = right = NULL;

    }

};

static int ind = -1;
Boy* firstcase(vector<int>preorder){
     ind++;
     if(preorder[ind] == -1){
        return NULL;
     }
    Boy* root = new Boy(preorder[ind]);
    root->left= firstcase(preorder);
    root->right= firstcase(preorder);

    return root;
}
void levelcase(Boy*root){
    queue<Boy*>q;
    q.push(root);
    q.push(NULL);
    if(root == NULL){
        return;
    }
    while(q.size() >0){
        Boy*cur= q.front();
        q.pop();
        if(cur == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<cur->data<<" ";
        if(cur->left !=NULL){
            q.push(cur->left);
        }
        if(cur->right != NULL){
            q.push(cur->right);
        }
    }
}

void Topview(Boy *root){
    queue<pair<Boy*, int >>q;
     if(root == NULL){
        return;
     }
      q.push({root, 0});
      map<int,int>m;
      while(!q.empty()){
        Boy*cur = q.front().first;
        int currHd =q.front().second;
        q.pop();
        if(m.find(currHd) == m.end()){
            m[currHd] =cur->data;
        }
        if(cur->left != NULL){
            q.push({cur->left,currHd-1});
        }
        if(cur->right != NULL){
            q.push({cur->right,currHd+1});
        }
      }
      for(auto i : m){
        cout<<i.second<<" ";
      }
}
 void DownLevel( Boy *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
       cout<<root->data<<" ";
       return;
    }
    DownLevel(root->left,k-1);
    DownLevel(root->right,k-1);
 }

 
 int transform(Boy*root){
     if(root == NULL){
         return 0;
        }
        int leftside = transform(root->left);
        int rightside = transform(root->right);
        int val = root->data;
        root->data = leftside+rightside;
        return root->data + val;
    }
    int orderlevel(Boy*root){
       if(root== NULL){
           return 0;
       }
       cout<<root->data<<" ";
       orderlevel(root->left);
       orderlevel(root->right);
   
   
    }
    int main(){
        
    vector<int>preload = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Boy*ans = firstcase(preload);
   cout<<"Order Level : ";
    orderlevel(ans);
    transform(ans);
    cout<<endl;
    cout<<"Transfrom Order :";
    orderlevel(ans);
  
    return 0;
}
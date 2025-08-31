#include<iostream>
using namespace std;
class boy{
    public:
     boy*next;
     int data;
     boy(int a){
        data = a;
        next= NULL;
     }
};
class B{

    public:
    boy*head;
    boy*tail;
    B(){
    head= tail = NULL;
    }
    void adding(int val){
        boy*newadding = new boy(val);
        if( head == NULL){
        head = tail = newadding;
        return ; 
        }
        else{
            newadding->next = head;
            head = newadding;
        }
    } 
    void backadding(int val){
        boy*newnode = new boy(val);
        if( head == NULL){
            head= tail = newnode;
            return;
        }
        else{
            tail->next = newnode;
            tail= newnode;
        }
    }
    void pop_front(){
        if( head == NULL){
            cout<<" SORRY \n";
            return;
        }
        else{
          boy*temp = head;
          head = head->next;
          temp->next = NULL;
          delete temp;
        }
    }

    void pop_back(){
        if(head == NULL ){
            cout<<" No Data \n";
            return;
        }
        else{
            boy* temp = head;
            while( temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void insert(int val, int pos){

        if(pos<0){
            cout<<" Invalid \n";
            return;
        }
        if( pos == 0){
            adding(val);
            return;
        }
        boy *temp = head;
        for(int i =0; i<pos-1;i++){
            if(temp == NULL){
                cout<<" Sorrt \n";
                return;
            }
            temp = temp->next;
        }
        
        boy *newnode = new boy (val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    
  void printa(){
    boy*temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-";
        temp = temp->next;
    }
    cout<<" null"<<endl;
  }

  int search(int key){
    boy *temp = head;
    int ind=0;
    while( temp !=NULL){
        if( temp->data == key){
        return ind; 
    }
    temp = temp->next;
    ind++;
}
return -1;
  }
};
int main(){
  B b;
  b.adding(3);
  b.adding(4);
  b.adding(5);
  b.backadding(1);
  b.backadding(0);
  b.backadding(-1);
  b.insert(7,1);
//   b.pop_front();
//   b.pop_back();
  b.printa();

  cout<<" position : "<<b.search(3);

return 0;    
}
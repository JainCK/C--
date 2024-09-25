#include <iostream>
using namespace std;

#define MAX_SIZE 100//Maximum size of the stack

class Stack{
    private:
    int arr[MAX_SIZE];
    int top;

    public:
    Stack(){
        top=-1;
    }

    void push(int element){
        if(top==MAX_SIZE-1){
            cout<<"Stack is full. Cannot push element"<<element<<endl;
            return;
        }
        arr[++top]=element;
        cout<<"Pushed element"<<element<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty. Cannot pop element"<<endl;
            return;
    }
    cout<<"Popped element"<<arr[top--]<<endl;
}
void display(){
    for(int i = 0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};

int main(){
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(8);
    stack.push(12);
    stack.push(25);
    stack.push(23);
    stack.pop();
    stack.push(27);
    stack.display();

    return 0;
}

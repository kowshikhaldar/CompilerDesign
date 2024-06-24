#include<iostream>
using namespace std;



int main(){
    int count=0;
    string input;
    cout<<"Enter Input:"<<endl;
    cin>>input;
    for (int i = 0; i < input.length(); i++)
    {
        

        switch (input[i])
        {
        case '+':
            cout<<"Operator"<<count+1<<":"<<input[i]<<endl;
            count++;
            break;
        case '=':
            cout<<"Operator"<<count+1<<":"<<input[i]<<endl;
            
            count++;
            break;

        case '-':
            cout<<"Operator"<<count+1<<":"<<input[i]<<endl;
            count++;
            break;

        case '*':
            cout<<"Operator"<<count+1<<":"<<input[i]<<endl;
            count++;
            break;
        case '/':
            cout<<"Operator"<<count+1<<":"<<input[i]<<endl;
            count++;
            break;
        
        default:
           
            break;
        }
    }

    cout<<"Total Count:"<<count<<endl;
    


}
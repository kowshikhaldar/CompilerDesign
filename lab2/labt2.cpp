#include<iostream>
using namespace std;



int main(){
    string input;
    cout<<"Enter Input:"<<endl;
    cin>>input;



    if (input.substr(0,2) =="//")
    {

        cout<<"This is a Single line comment"<<endl;

    }else if (input.substr(0,2) =="/*" && input.substr(input.length()-2,2) =="*/" )
    {
        cout<<"This is Multi line comment"<<endl;
    }else{
        cout<<"This is not a comment";
    }
    
        


}
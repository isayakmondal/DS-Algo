#include<iostream>
#include<string>
using namespace std;

// int print(int arr[],int size){
//     if(size<1)
//     return arr[size];

//     std::cout<<print(arr,size-1)<<" ";
//     return arr[size];

// }

int expo(int a, int b){
    if(b<1)
    return 1;

    return a*expo(a,b-1);
}
string reverseString(string str){
    if(str.size()<2)
    return str;

    return reverseString(str.substr(1,str.size()-1)) + str[0];

}

bool pallindrome ( string str){
    string newstr = reverseString(str);
    if(newstr==str)
    return true;
    else 
    return false;
}

int main(){
    int arr[]={2,4,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
        // cout<<size;
        std::cout<<expo(2,5);
        // cout<<pallindrome("malayalam");
    // print(arr,size);
}
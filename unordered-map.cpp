#include <iostream>
#include <unordered_map>
#include<map>
#include <vector>
using namespace std;

vector<int> remove_duplicates(int a[], int arr_size)
{

    unordered_map<int, bool> mymap;
    vector<int> v;

    // cout<<arr_size<<endl;
    for (int i = 0; i < arr_size; i++)
    {
        if (!mymap.count(a[i]))
        {
            mymap.insert(make_pair(a[i], 1));
            v.push_back(a[i]);
        }
    }

    return v;
}

int main(int argc, char const *argv[])
{
    // unordered_map<string,int> umap;

    // umap.insert(make_pair("abc",100));
    // umap["def"] = 20;

    // cout<<umap.at("abc")<<endl;
    // cout<<umap["def"]<<endl;
    // cout<<umap.count("abc")<<endl;
    int arr[] = {1, 1, 2, 3, 5, 3, 4, 2, 4, 5, 1, 6, 1, 2, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = remove_duplicates(arr, arr_size);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << " ";
    // }
    for(auto val:v){  //Range Based for loops
        cout<<val<<" ";
    }

    return 0;
}

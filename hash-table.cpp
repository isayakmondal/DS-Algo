#include <iostream>
#include <string>

using namespace std;

template <typename T>
class node
{
    private:

    string key;
    T value;
    node *next;
public:

    node(string key, T value)
    {

        this->key = key;
        this->value = value;
        next = nullptr;
    }
    ~node()
    {
        delete next;
    }

    template <typename V>
    friend class hashMap;
};

template <typename T>
class hashMap
{

private:
    node<T> **bucketArray;
    int count;
    int numBuckets;

    int getBucketIndex(string key) //Hash Function
    {

        int hashCode = 0;
        int base = 1;
        int p = 37;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashCode += key[i] * base;
            base = base * p;
            hashCode = hashCode % numBuckets;
            base = base % numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash(){
        
        int oldBucketSize = numBuckets; 
         numBuckets = 2*numBuckets; 
        node<T>** temp = bucketArray;
        bucketArray = new node<T>*[numBuckets]{};

        for (int i = 0; i < oldBucketSize; i++)
        {
        
            node<T> * head = temp[i];
            while (head)
            {
                string newKey = head->key;
                T newValue = head->value;
                insert(newKey,newValue);
                head = head->next;
            }
            
        }

        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }
        delete []temp;
        


    }

public:
    hashMap(int size)
    {
        count = 0;
        numBuckets = size;
        bucketArray = new node<T> *[numBuckets] {};
        // for (int i = 0; i < numBuckets; i++)
        // {
        //     bucketArray[i] = nullptr;
        // }
    }
    ~hashMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete bucketArray[i];
        }
        delete[] bucketArray;
    }

    /*  Member Functions  */
    int getSize()
    {
        return count;
    }

    T getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        node<T> *head = bucketArray[bucketIndex];
        while (head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, T value)
    {

        int bucketIndex = getBucketIndex(key);
        node<T> *head = bucketArray[bucketIndex];

        while (head)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        node<T> *newnode = new node<T>(key, value);
        newnode->next = bucketArray[bucketIndex];
        bucketArray[bucketIndex] = newnode;
        count++;
        double loadFactor = (float)count/(float)numBuckets;
        if(loadFactor>0.7){
            rehash();
        }
    }

    T remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        node<T> *head = bucketArray[bucketIndex];
        node<T> *temp = nullptr;
        while (head)
        {
            if (head->key == key)
            {

                if (!temp)
                {
                    bucketArray[bucketIndex] = head->next;
                }
                else
                {
                    temp->next = head->next;
                }
                T tempVal = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return tempVal;
            }
            temp = head;
            head = head->next;
        }   

        return 0;
    }
};

int main()
{
    hashMap<int> h(8);
    h.insert("abc", 2);
    h.insert("def", 3);
    h.insert("ghi", 1);
    h.insert("ijk", 4);
    h.insert("mno", 6);

    cout<<h.getSize()<<endl;
    // cout<<h.remove("mno")<<endl;
    cout << h.getValue("mno") << endl;
}
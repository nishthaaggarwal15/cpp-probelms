#include<bits/stdc++.h>
using namespace std;

class LFUCache{
    int capacity;
    int minFreq;
    unordered_map<int,int>keyval,keyfreq;
     unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> keyItr;
    
    public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
   int get(int key){
        if(keyval.find(key)==keyval.end()){
            return -1;
        }
        //erase the current frequency
        int freq= keyfreq[key];
        freqList[freq].erase(keyItr[key]);
        if(freqList[freq].empty()){
            freqList.erase(freq);
            if(minFreq==freq){
                minFreq++;
            }
        }
        // add to new freq because as we touch it it's freq increase
        freq++;
        keyfreq[key]=freq;
        freqList[freq].push_front(key);
        keyItr[key]= freqList[freq].begin();
return keyval[key];
    }
    void put(int key,int value){
        if(capacity==0)return;
        //if key already exists update the value and increase freq
        if(keyval.find(key)!=keyval.end()){
           keyval[key]=value;
           get(key);
           return;
        }
        //if capacity is full remove least frequency element from all maps
        if(keyval.size()==capacity){
        int lfu= freqList[minFreq].back();
        freqList[minFreq].pop_back();
          if(freqList[minFreq].empty()){
        freqList.erase(minFreq);
    }

          keyval.erase(lfu);
            keyfreq.erase(lfu);
            keyItr.erase(lfu);
        }

        // and give this key a new freq as 1 and insert it everwheere
        keyval[key]=value;
        keyfreq[key]= 1;
        freqList[1].push_front(key);
        keyItr[key]=freqList[1].begin();
        minFreq=1;
    }


};

int main(){
    return 0;
}
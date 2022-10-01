/*
Frequency Stack (hard) #

Design a class that simulates a Stack data structure, implementing the following two operations:

    push(int num): Pushes the number ‘num’ on the stack.
    pop(): Returns the most frequent number in the stack. If there is a tie, return the number which was pushed later.

Example:

After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)
 
1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2

Time complexity #

The time complexity of push() and pop() is O(logN) where ‘N’ is the current number of elements in the heap.

Space complexity #

We will need O(N) space for the heap and the map, so the overall space complexity of the algorithm is O(N).
*/
#include<bits/stdc++.h>
using namespace std;

class Element{
    public:
    int number=0;
    int frequency=0;
    int sequencenum=0;

    Element(int number,int frequency,int sequencenum){
        this->number=number;
        this->frequency=frequency;
        this->sequencenum=sequencenum;
    }
};

class FrequencyStack{
    public:

    struct comp{
        bool operator()(const Element &e1,const Element &e2){
            if(e1.frequency!=e2.frequency)
                return e2.frequency>e1.frequency;
            else
                return e2.sequencenum>e1.sequencenum;
        }
    };

    int sequencenum=0;
    unordered_map<int,int> umap;
    priority_queue<Element,vector<Element>,comp> maxheap;

    void push(int num){
        umap[num]+=1;
        maxheap.push({num,umap[num],sequencenum++});
    }

    int pop(){
        int num=maxheap.top().number;
        maxheap.pop();

        if(umap[num]>1)
            umap[num]-=1;
        else
            umap.erase(num);
        return num;
    }
};

int main(){
    FrequencyStack fs;
    fs.push(1);
    fs.push(2);
    fs.push(3);
    fs.push(2);
    fs.push(1);
    fs.push(2);
    fs.push(5);
    cout<<fs.pop()<<endl;
    cout<<fs.pop()<<endl;
    cout<<fs.pop()<<endl;
}
/* Day 11
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3810/
*/

// Solution 1

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> ms;
    multiset<int>::iterator it1, it2;
    MedianFinder() {

    }

    void addNum(int num) {
        int n = ms.size();
        ms.insert(num);
        if(n == 0) {
            it1 = it2 = ms.begin();
        }
        else if(n % 2 == 1) {
            if(num < *it1)
                it1--;
            else
                it2++;
        }
        else{
            if(*it1 < num and *it2 > num) {
                it1++;
                it2--;
            }
            else if(num >= *it2) {
                it1++;
            }
            else{
                it2--;
                it1 = it2;
            }
        }
    }

    double findMedian() {
        return (*it1 + (*it2)) * 1.0 / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// Solution 2

class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int> >minHeap;
    double med=100005.5;
public:
    /** initialize your data structure here. */
    MedianFinder()
    {

    }
    void addNum(int num)
    {
        if(maxHeap.size()>minHeap.size())
        {
            if(num<med)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }
            med=(minHeap.top()+maxHeap.top())*1.0/2.0;
        }
        else if(minHeap.size()==maxHeap.size())
        {
            if(num<med)
            {
                maxHeap.push(num);
                med=maxHeap.top();
            }
            else
            {
                minHeap.push(num);
                med=minHeap.top();
            }
        }
        else
        {
            if(num>med)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
            med=(minHeap.top()+maxHeap.top())*1.0/2.0;
        }
    }

    double findMedian()
    {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

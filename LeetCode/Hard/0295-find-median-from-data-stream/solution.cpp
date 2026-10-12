#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
private:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    double median;
    bool isMid = false, isInitialized = false;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!isInitialized)
        {
            isInitialized = true;
            median = num;
            return;
        }
        if (num >= median)
        {
            minq.push(num);
            if (!isMid)
                maxq.push(median);
        }
        else
        {
            maxq.push(num);
            if (!isMid)
                minq.push(median);
        }
        // update median
        if (minq.size() > maxq.size())
        {
            median = minq.top();
            minq.pop();
            isMid = false;
        }
        else if (minq.size() < maxq.size())
        {
            median = maxq.top();
            maxq.pop();
            isMid = false;
        }
        else if (minq.size() != 0 && maxq.size() != 0)
        {
            median = (maxq.top() - minq.top()) / 2.0 + minq.top();
            isMid = true;
        }
    }

    double findMedian()
    {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

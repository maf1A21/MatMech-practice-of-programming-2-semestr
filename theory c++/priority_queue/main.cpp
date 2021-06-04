#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Problem
{
  string name;
  double t_in;
  double t_work;
  int priority;
  Problem(string str = "", double in = 0, double work = 0, int prior = 0)
    : name(str), t_in(in), t_work(work), priority(prior){}
};



struct Heap
{
  vector<Problem> priority_q;
  Heap(vector<Problem> priority_q_= {})
  {
    for (size_t i = 0; i < priority_q_.size(); ++i)
    {
      priority_q.push_back(priority_q_[i]);
    }
  }
  ~Heap();
  Heap siftDown(int i);
  Heap siftUp(int i);
  Problem extractMin();
  Heap insert(Problem t);
};

  Heap Heap::siftDown(int i)
  {
    while (2 * i + 1 < priority_q.size())
    {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int j = left;
      if ((right < priority_q.size()) &&
           (priority_q[right].priority < priority_q[left].priority))
      {
        j = right;
        if (priority_q[i].priority <= priority_q[j].priority)
        {
          break;
        }
        swap(priority_q[i], priority_q[j]);
        i = j;
      }
    return *this;
    }
  }

  Heap Heap::siftUp(int i)
  {
    while (priority_q[i].priority < priority_q[(i - 1) / 2].priority)
    {
      swap(priority_q[i], priority_q[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
    return *this;
  }

  Problem Heap::extractMin()
  {
    Problem min = priority_q[0];
    priority_q[0] = priority_q[priority_q.size() - 1];
    priority_q.erase(priority_q.begin());
    siftDown(0);
    return min;
  }

  Heap Heap::insert(Problem t)
  {
    priority_q.push_back(t);
    siftUp(priority_q.size() - 1);
    return *this;
  }

  bool cmp(Problem a, Problem b)
  {
    return a.t_in < b.t_in;
  }

  int main()
  {
    int n;
    cin >> n;
    string name;
    int prior;
    int t_in;
    int t_work;
    Problem temp;
    vector<Problem> problems;
    for (size_t i = 0; i < n; ++i)
    {
      cin >> name >> prior >> t_in >> t_work;
      temp.name = name;
      temp.priority = prior;
      temp.t_in = t_in;
      temp.t_work = t_work;
      problems.push_back(temp);
    }

    sort(problems.begin(), problems.end(), cmp);
    int t = 0;
    Heap heap;

    while ((problems.size()) || (heap.priority_q.size()))
    {
      t++;
      if (t == problems[0].t_in)
      {
        heap.insert(problems[0]);
        problems.erase(problems.begin());
      }
      if (heap.priority_q.size())
      {
        heap.priority_q[0].t_work--;
        if (heap.priority_q[0].t_work == 0)
        {
          cout << heap.priority_q[0].name << " " << t << endl;
          heap.extractMin();
        }
      }

      if (t % 3 == 0)
      {
        for (int i = 0; i < heap.priority_q.size(); i++)
        {
          heap.priority_q[i].priority--;
        }
      }
    }
    return 0;
}

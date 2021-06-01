#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void insertion_sort(vector <int> &vec)
{
    for(int i = 1;i < vec.size(); i++)
        for(int j = i; j > 0 && vec[j-1] > vec[j]; j--)
            swap(vec[j-1], vec[j]);
}

int minimal(vector<int> vec)
{
    int res = 0;
    for (int i = 1; i < vec.size(); i++) if (vec[i] < vec[res]) res = i;
    return res;
}

void min_sort(vector<int> &vec)
{
    int min_index;
    vector <int> res;
    while (vec.size() > 0)
    {
        min_index = minimal(vec);
        res.push_back(vec[min_index]);
        vec.erase(vec.begin()+min_index);
    }
    vec = res;
}

void random_sort(vector<int> &vec)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    bool check = true;
    while (check)
    {
        for (int i = 0; i < vec.size()-1; i++)
        {
            if (vec[i] > vec[i+1])
            {
                std::shuffle(std::begin(vec), std::end(vec), e);
                break;
            }
            else if (i == vec.size()-2) check = false;
        }
    }
}

void qsort(int beg, int end, std::vector<int> &vec)
{
    int l = beg, r = end;
    int mid = vec[(l + r) / 2];
    while (l <= r) {
        while (vec[l] < mid)
            l++;
        while (vec[r] > mid)
            r--;
        if (l <= r)
            std::swap(vec[l++], vec[r--]);
    }
    if (beg < r)
        qsort(beg, r, vec);
    if (end > l)
        qsort(l, end, vec);
}

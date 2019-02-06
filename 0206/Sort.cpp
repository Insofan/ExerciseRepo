//
// Created by Insomnia on 2019/2/6.
// MIT License
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;


void out(vector<int> &vec) {

    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }
    return tempVec;
}

class Solution1 {
public:
    void quickSort(vector<int> &vec, int left, int right) {

        int l = left;
        int r = right;
        int pivot = vec[left];

        while (l < r) {
            while ( l < r && vec[r] >= pivot) {
                r--;
            }

            if (l < r) {
                swap(vec[l], vec[r]);
            }

            while ( l < r && vec[l] < pivot) {
                l++;
            }

            if (l < r) {
                swap(vec[l], vec[r]);
            }

            if (l != left) {
                quickSort(vec, left, l - 1);
            }

            if (r != right) {
                quickSort(vec, r + 1, right);
            }
        }

    }
};

class Solution2 {
public:
    void mergeSort(vector<int> &vec, int left, int right) {
       if (left < right) {
           int mid = (left + right) / 2;

           mergeSort(vec, left, mid );
           mergeSort(vec, mid + 1, right);
           merge(vec, left, mid, right);
       }
    }

private:

    void merge(vector<int> &vec, int left, int mid, int right) {
        int len1 = mid - left + 1;
        int len2 = right - mid;

        vector<int> vec1;
        vector<int> vec2;

        for (int i = 0; i < len1; i++) {
           vec1.push_back(vec[left + i]);
        }
        vec1.push_back(INT32_MAX);

        for (int i = 0; i < len2; i++) {
            vec2.push_back(vec[mid + i + 1]);
        }
        vec2.push_back(INT32_MAX);

        int m = 0;
        int n = 0;

        for ( int i = left; i <= right; i++) {
            if (vec1[m] < vec2[n]) {
                vec[i] = vec1[m];
                m++;
            } else {
                vec[i] = vec2[n];
                n++;
            }
        }
    }
};


class Solution3 {
public:
    void bubble(vector<int> &vec) {

        for ( int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] < vec[i]) {
                    swap(vec[i], vec[j]);
                }
            }
        }
    }
};

class Solution4 {
public:
    void hashSort(vector<int> &vec, int maxNum) {

        map<int, int> hashMap;

        for (int i = 0; i < vec.size(); i++) {
            hashMap[vec[i]]++;
        }

        vector<int> res;

        for (int i = 0; i <vec.size(); i++) {
           for (int j = 0; j < hashMap[i]; j++) {
               res.push_back(i);
           }
        }

        vec = res;
    }
};

int main() {
    vector<int> vec1 = randomVec(10, 50);
    out(vec1);
    Solution1 solution1;
    solution1.quickSort(vec1, 0, vec1.size() - 1);
    out(vec1);

    vector<int> vec2 = randomVec(10, 50);
    out(vec2);
    Solution2 solution2;
    solution2.mergeSort(vec2, 0, vec2.size() - 1);
    out(vec2);

    vector<int> vec3 = randomVec(10, 100);
    out(vec3);
    Solution3 solution3;
    solution3.bubble(vec3);
    out(vec3);

    vector<int> vec4 = randomVec(10, 100);
    out(vec4);
    Solution4 solution4;
    solution4.hashSort(vec4, 1000);
    out(vec4);


    return 0;
}
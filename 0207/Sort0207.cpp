//
// Created by Insomnia on 2019/2/7.
// MIT License
//
#include <iostream>
#include <vector>

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

class Solution {
public:
    void mergeSort(vector<int> &vec, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(vec, left,mid);
            mergeSort(vec, mid + 1, right);
            merge(vec, left, mid, right);
        }
    }


    void quickSort(vector<int> &vec, int left, int right) {
        int l = left;
        int r = right;

        int pivot = vec[left];


        while ( l < r ) {
            while (l < r && vec[r] >= pivot) {
                r--;
            }

            if (l < r) {
                swap(vec[l], vec[r]);
            }

            while (l < r && vec[l] < pivot) {
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

private:
    void merge(vector<int> &vec, int left, int mid, int right) {

        int len1 = mid - left + 1;
        int len2 = right - mid;

        vector<int> vector1;
        vector<int> vector2;

        for (int i = 0; i < len1;i++) {
            vector1.push_back(vec[left + i]);
        }

        for (int i = 0; i < len2; i++) {
            vector2.push_back(vec[mid + i + 1]);
        }

        vector1.push_back(INT32_MAX);
        vector2.push_back(INT32_MAX);

        int m = 0;
        int n = 0;

        for (int i = left; i<= right; i++) {
            if (vector1[m] < vector2[n]) {
                vec[i] = vector1[m++];
            } else {
                vec[i] = vector2[n++];
            }
        }

    }

};

int main() {
    vector<int> vec = randomVec(10, 50);
    out(vec);
    Solution sol;
//    sol.mergeSort(vec, 0, vec.size() - 1);
    sol.quickSort(vec, 0, vec.size() - 1);
    out(vec);

    return 0;
}
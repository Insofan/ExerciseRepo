//
// @ClassName Sort0219
// @Description TODO
// @Date 2019/2/19 8:57 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> randomVec(int len, int maxNum) {
    vector<int> res;

    srand((unsigned)time(NULL));

    for (int i = 0; i < len; i++) {
        res.push_back(rand() % maxNum);
    }

    return res;
}


void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    void quickSort(vector<int> &vec, int left, int right) {
        int l = left;
        int r = right;
        int pivot = vec[l];
        while (l < r) {
            while ( l < r && vec[r] >= pivot) {
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
                quickSort(vec, left, l -1 );
            }

            if (r != right) {
                quickSort(vec, r + 1, right);
            }
        }
    }

    void mergeSort(vector<int> &vec, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(vec, left, mid);
            mergeSort(vec, mid + 1, right);
            mergeHelper(vec, left, mid, right);
        }
    }

    void bubbleSort(vector<int> &vec) {
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] < vec[i]) {
                    swap(vec[i], vec[j]);
                }
            }
        }
    }

private:
    void mergeHelper(vector<int> &vec, int left,int mid, int right) {
        int len1 = mid - left + 1;
        int len2 = right - mid;

        vector<int> vector1;
        vector<int> vector2;

        for (int i = 0; i < len1; i++) {
          vector1.push_back(vec[left + i]);
        }

        for (int i = 0; i < len2; i++) {
          vector2.push_back(vec[mid + i + 1]);
        }

        vector1.push_back(INT32_MAX);
        vector2.push_back(INT32_MAX);

        int m = 0;
        int n = 0;

        for (int i = left; i <= right; i++) {
          if (vector1[m] <= vector2[n]) {
            vec[i] = vector1[m++];
          } else {
            vec[i] = vector2[n++];
          }
        }
    }

};

int main() {
    vector<int> vec = randomVec(10, 50);
    printVec(vec);
    Solution sol;
//    sol.quickSort(vec, 0, vec.size() - 1);
//    sol.mergeSort(vec, 0, vec.size() - 1);
    sol.bubbleSort(vec);
    printVec(vec);

    return 0;
}

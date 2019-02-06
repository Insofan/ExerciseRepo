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


class Solution {
public:

    vector<int> twoSum(vector<int> &vec, int tar) {
        map<int, int> hashMap;
        for ( int i = 0; i < vec.size(); i++) {
            hashMap[vec[i]]++;
        }

        vector<int> res;
        for ( int i = 0; i < vec.size();i++) {
            int other = tar - vec[i];
            if (hashMap.find(other) != hashMap.end()) {
                res.push_back(vec[i]);
                res.push_back(other);
                return res;
            }
        }

        return vector<int>();
    }
};

int main() {
    int arr[10] = {10, 1, 2, 3, 4, 5, 6, 7, 0, 21};
    vector<int> vec(&arr[0], &arr[10]);
    out(vec);
    Solution solution;
    vector<int> res = solution.twoSum(vec, 31);
    out(res);

    return 0;
}
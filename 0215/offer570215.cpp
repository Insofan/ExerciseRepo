//
// @ClassName offer570215
// @Description TODO
// @Date 2019/2/15 2:48 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using  namespace std;
//        pair<int, int> myPair = make_pair(1, 3);
//        pairVec.push_back(myPair);
//        cout << myPair.second<< endl;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> vec = array;
        vector<int> res;

        vector<pair<int,int> > pairVec;

        map<int, int> hashMap;
        for ( int i = 0 ; i < vec.size(); i++) {
            hashMap[vec[i]] = i;
        }

        for (int i = 0; i < vec.size(); i++) {
            int other = sum - vec[i];
            if (hashMap.find(other) != hashMap.end() && i != hashMap[other]) {
                pairVec.push_back(make_pair(vec[i], other));
            }
        }

        int mulRes = INT32_MAX;
        int idx = -1;
        for (int i = 0; i < pairVec.size(); i++) {
            int tmp = pairVec[i].first * pairVec[i].second;
            if (tmp < mulRes) {
                mulRes = tmp;
                idx = i;
            }
        }
        res.push_back(pairVec[idx].first);
        res.push_back(pairVec[idx].second);

        return  res;
    }
};


int main() {
    int arr[] = {2, 3, 4, 5, 6};
    vector<int> vec(&arr[0], &arr[5]);

    Solution sol;

    vector<int> res =sol.FindNumbersWithSum(vec, 8);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

//    cout << sol.towNum(vec, 8).size() << endl;
    return 0;
}

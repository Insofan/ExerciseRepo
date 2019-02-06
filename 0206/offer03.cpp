//
// @ClassName offer03
// @Description TODO
// @Date 2019/2/6 9:20 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int duplicate(vector<int> &vec) {

        for (int i = 0; i < vec.size(); i++) {
            while (vec[i] != i) {
                swap(vec[i], vec[vec[i]]);
            }
        }

        return NULL;
    }
    
    int duplicate2(vector<int> &vec) {
        map<int, int> hashMap;
        
        for (int i = 0; i < vec.size(); i++) {
            hashMap[vec[i]]++;
        }
        
        for (int i = 0; i < vec.size();i++) {
            if (hashMap[vec[i]] > 1) {
                return vec[i];
            }
        }
        return NULL;
    }

};


int main() {

    int arr[] = {8, 1, 2, 3, 4, 5, 6, 7, 0, 8};
    vector<int> vec(&arr[0], &arr[10]);
    Solution solution;
    int res   = solution.duplicate2(vec);
    cout << res << endl;

    return 0;
}

//
// @ClassName offer210209
// @Description TODO
// @Date 2019/2/9 9:44 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class  Solution {
public:
    vector<int> adjustArr(vector<int> &vec) {

        vector<int> vector1;
        vector<int> vector2;

        for (int i = 0 ; i < vec.size(); i++) {
            if (vec[i] % 2 != 0) {
                vector1.push_back(vec[i]);
            } else {
               vector2.push_back(vec[i]);
            }
        }
       vector<int> res;
        for (int i = 0; i < vector1.size(); i++) {
            res.push_back(vector1[i]);
        }

        for (int i = 0; i < vector2.size(); i++) {
            res.push_back(vector2[i]);
        }

        return res;

    }
};


void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << endl;
}

int main() {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   vector<int> vec(&arr[0], &arr[9]);
   printVec(vec);

   Solution sol;

   vector<int> res = sol.adjustArr(vec);

   printVec(res);




    return 0;
}

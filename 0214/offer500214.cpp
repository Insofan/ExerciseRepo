// 
// @ClassName offer500214
// @Description TODO
// @Date 19-2-14 下午9:21
// @Created by Insomnia
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int firstSingleChar(string str) {
        map<char, int> hashMap;

        for (int i = 0; i < str.length(); i++) {
            hashMap[str[i]]++;
        }

        for (int i = 0; i < str.length(); i++) {
            if (hashMap[str[i]] == 1) {
                return  i;
            }
        }


        return -1;
    }
};

int main() {
    return 0;
}

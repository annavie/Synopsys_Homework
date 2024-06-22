#include<iostream>
#include<vector>
// std::vector<std::pair<int, int>> solution(std::vector<int>& numbers) {

//     std::vector<std::pair<int,int>> res;
//     int n = numbers.size();
//     for(int i = 0; i < n; ++i) {
//         res.push_back({numbers[i], numbers[n-i-1]});
//     }
//     return res;
// }
std::string solution(std::string inputString) {
    std::string result = "";
    int length = inputString.length();
    for (int i = 0; i < length / 2 + length % 2; i++) {
        result += inputString[i];
        if (length - 1 - i != i) {
            result += inputString[length - 1 - i];
        }
    }
    return result;
}
int main() {
    std::string s = "women";
    std::cout << solution(s);
}
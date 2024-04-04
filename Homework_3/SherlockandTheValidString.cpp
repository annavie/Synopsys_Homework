#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    
    int arr[26] = {0};
    int count = 0;
    for(char ch : s) {
        ++arr[ch - 'a'];
    }
     for(int i = 1; i < 26; ++i) {
          std::cout  << arr[i];}
    for(int i = 1; i < 26; ++i) {
      
        if(arr[i] != arr[i-1]) {
            ++count;
            if (count > 2) {
                 return "NO";  
            }
            if(arr[i] - arr[i-1 ]  != 1  ||  arr[i] - arr[i-1 ]  != -1) {
                 return "NO";  
            }
        }
}
    
     return "YES";   
      
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

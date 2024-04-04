#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    int arr[26]  ={0};
    for ( char ch : a) {
        ++arr[ch - 'a'];
    }
    for( char ch : b) {
        --arr[ch - 'a'];
    }
    int count = 0;
    
    for( int i = 0; i < 26; ++i) {
        while( arr[i] > 0) {
            ++count;
            --arr[i];
        }
        while (arr[i] < 0) {
            ++count;
            ++arr[i];
        }
        
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

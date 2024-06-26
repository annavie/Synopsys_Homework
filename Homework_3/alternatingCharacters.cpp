#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternatingCharacters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternatingCharacters(string s) {
    stack<char> s_stack;
    int deletions = 0;
    
    for (char c : s) {
        if (s_stack.empty() || s_stack.top() != c) {
            s_stack.push(c);
        } else {
            deletions++;
        }
    }
    return deletions;
}

/* or without stack */
/*
int alternatingCharacters(string s) {
    int deletions = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            deletions++;
        }
    }
    return deletions;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

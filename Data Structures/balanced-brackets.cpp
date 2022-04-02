#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
// Start of my solution----- 
 
struct Node {
    char open = '-';
    Node *prev, *next;
    
    Node(char _open) : open(_open){
        prev = nullptr;
        next = nullptr;
    }
};

static void LogList(Node *root){
    if(root){
        cout << "Logging List-----" << endl;  
        while(root){
            cout << "Next Node: " << root->open << endl;
            root = root->next;
        }  
    }
}

static bool isMatchingPair(char open, char close){
    switch(open){
        case '{':
            return close == '}';
        case '(':
            return close == ')';
        case '[':
            return close == ']';
        default:
            return false;
    }
}

static bool isClosing(char c){
    return (c == ']' || c == ')' || c == '}');
}

string isBalanced(string s) {
    //cout << "-----Checking string: " << s << endl;
    Node *tmp = nullptr;
    Node *cur = nullptr;
    
    for(char c : s){
        //LogList(cur);
        if(!cur){
            cur = new Node(c);    
        }else if(isClosing(c)){
            if(isMatchingPair(cur->open, c)){
                tmp = cur;
                cur = cur->prev;
                if(cur){
                    cur->next = nullptr;
                } 
                delete tmp;
            }else{
                return "NO";
            }
        }else{
            tmp = new Node(c);
            cur->next = tmp;
            tmp->prev = cur;
            cur = tmp;
        } 
    }
    return cur ? "NO" : "YES";
}

// ----- End of my solution

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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

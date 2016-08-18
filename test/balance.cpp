// BALANCING PROGRAM
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main()
{
    stack<char> s;
    char c;
    ifstream in;

    cout << "What file to open?" << endl;
    string file;
    cin >> file;

    in.open(file.c_str());
    if(in.fail()){
        cout << "failed to open file!" << endl;
        return 0;
    }
    in.get(c);
    while(!in.eof()){
        if (c == '(' || c == '[' || c == '{')
            s.push(c);
        else if ( c == ')'){
            if (!s.empty() && s.top() == '(')
                s.pop();
            else{
                cout << "No match for ), missing (" << endl;
                return 0;
            }
        }
        else if ( c == ']'){
            if (!s.empty() && s.top() == '[')
                s.pop();
            else{
                cout << "No match ], missing [" << endl;
                return 0;
            }
        }
        else if ( c == '}'){
            if (!s.empty() && s.top() == '{')
                s.pop();
            else{
                cout << "No match for }, missing {" << endl;
                return 0;
            }
        }
        in.get(c);
    }
    if(s.empty())
        cout << "This program is balanced" << endl;
    else
        cout << "The program was is not balanced" << endl;
        return 0;
}

#include <string>
#include <stack>

using namespace std;
 
bool Check(string s)
{
    stack <char> temp;
 
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] == '(' || s[j] == '{' || s[j] == '[')
            temp.push(s[j]);
        else
        {
            if (temp.empty()) return false;
            if (temp.top() == '(' && s[j] == ')') temp.pop();
            else if (temp.top() == '{' && s[j] == '}') temp.pop();
            else if (temp.top() == '[' && s[j] == ']') temp.pop();
        }
    }
    if(temp.empty()) return true;
    else return false;
}
 
 
int solution(string s)
{
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        s += s.front();
        s.erase(s.begin());
        
        if (Check(s)) answer++;
    }
 
    return answer;
}
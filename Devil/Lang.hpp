#include <iostream>
#include "../Cal/queue.hpp"
#include "../Cal/stack.hpp"

class Lang
{

public:
    Lang(){
        res = "";
    }

    void setString(string s){
        this->s = s;
    }

    bool ifLegal();
    string toNormal();
private:
    string s;
    string res;
    stack <char> s1;
    stack <char> s2;
    queue <char> q;
};

string Lang::toNormal()
{
    int flag = 0;
    int size = s.size();
    for(int i = 0;i<size;i++){
        if(!flag && s[i] >= 'a' && s[i] <= 'z'){
            res.append(1,s[i]);
        }else if(flag && s[i] >= 'a' && s[i] <= 'z'){
            s1.push(s[i]);
        }else if(s[i] == 'B' ){
            if(flag){
                s1.push('t');
                s1.push('s');
                s1.push('a');
                s1.push('e');
                s1.push('d');
                s1.push('s');
                s1.push('a');
                s1.push('e');
            }
            else res += "tsaedsae";
        }else if(s[i] == 'A'){
            if(flag){
                s1.push('s');
                s1.push('a');
                s1.push('e');
            }
            else res += "sae";
        }else if(s[i] == '('){
            flag++;
            s1.push('(');
        }else if(s[i] == ')'){
            
            flag--;
            while(!s1.empty() && s1.top() != '('){

                if(!flag){
                    res.append(1,'e');
                    if(s1.top() != 'e'){
                        res.append(1,s1.top());
                    }
                }else{
                    q.push('e');
                    if(s1.top() != 'e'){
                        q.push(s1.top());
                    }
                }
                s1.pop();
            }
            s1.pop();//弹出栈顶(
            while(!q.empty()){
                s1.push(q.front());
                q.pop();
            }

        }
    }

    return res;
}

bool Lang::ifLegal()
{
    int cnt = 0;
    int size = s.size();
    for(int i = 0;i<size;i++){
        if(s[i] == '('){
            cnt++;
        }else if(s[i] == ')'){
            cnt--;
        }else{
            if(s[i] == 'B' || s[i] == 'A' || (s[i] >= 'a' && s[i] <= 'z')){
                ;
            }else return false;
        }
    }

    if(cnt) return false;
    else return true;
}



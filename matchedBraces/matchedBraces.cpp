/*
[EASY]

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.

*/

// to solve, make a stack. Start to traverse the string. If the current character in the string is an opening bracket, push it to the stack and move on. If the character in the string is an ending parenthese, check if the last item in the stack is the opening one to match it. If if is pop it. 

#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <stack>
#include <string>

int main(void)
{
    //std::stack<char> stack;
    std::string str1 = "([])[]({})";
    std::string str2 = "((()";
    std::string str3 = "([)]";

    return 0;
}

bool isWellFormed(std::string str)
{
    std::stack<char> stack;
    char letter = 0;
    for(int i=0; i< str.length(); i++)
    {
        if(str[i] == '{' || str[i]== '[' || str[i] == '('){         //opening
            stack.push(str[i]); 
        }
        else if(str[i] == '}' || str[i]== ']' || str[i] == ')'){        //closing
            // pop the element and see if it matches the beacket. The opening is one ascii vlue away from the closing
            if(stack.top() == str[i]-1) {
                stack.pop();
            }


        }
    }

    return true;
}
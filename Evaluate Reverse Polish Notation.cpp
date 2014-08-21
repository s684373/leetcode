//
//  main.cpp
//  leetcode
//
//  Created by 周嘉俊 on 14-8-20.
//  Copyright (c) 2014年 周嘉俊. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    vector<string> tokens;
    stack<int> ss;
    int point = 0;
    tokens.push_back("-1");
    tokens.push_back("1");
    tokens.push_back("*");
    tokens.push_back("-1");
    tokens.push_back("+");
    
    ss.push(atoi(tokens[point++].c_str()));
    while(point < tokens.size())
    {
        if(!isdigit(tokens[point][0]) && tokens[point].size()<=1)
        {
            int b = ss.top();
            ss.pop();
            int a = ss.top();
            ss.pop();
            int ans = 0;
            switch (tokens[point][0]) {
                case '+':
                    ans = a + b;
                    break;
                case '-':
                    ans = a - b;
                    break;
                case '/':
                    ans = a / b;
                    break;
                case '*':
                    ans = a * b;
                    break;
            }
            ss.push(ans);
        }
        else
        {
            ss.push(atoi(tokens[point].c_str()));
        }
        point++;
    }
    cout << ss.top();
    return 0;
}

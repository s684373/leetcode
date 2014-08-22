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
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    };
int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(2);
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(5);
    ListNode *p3 = new ListNode(4);
    head -> next = p1;
    head -> next -> next = p2;
    p3 -> next = NULL;
    head -> next -> next -> next = p3;
    ListNode *p = head;
    ListNode *pp = NULL;
    while(p && p->next)
    {
        if(p->next->val < head->val)
        {
            ListNode *tmp = p -> next;
            p->next = p->next->next;
            tmp -> next = head;
            head = tmp;
            continue;
        }
        pp = head;
        while(pp->next->val <= p->next->val && pp->next != p->next)
            pp = pp->next;
        if(pp->next != p->next)
        {
            ListNode *tmp = p -> next;
            p -> next = p ->next->next;
            tmp -> next = pp -> next;
            pp -> next = tmp;
            continue;
        }
        p = p->next;
    }
    return 0;
}

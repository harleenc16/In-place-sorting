
//  LSorter.cpp
//  LSorter
//
//  Created by Tali Moreshet
//  Copyright Â©  Tali Moreshet. All rights reserved.
//

#include <algorithm>
#include "LSorter.h"
using namespace std;

LNode* LSorter::sortList(LNode* head){
if(head==NULL || head->next == NULL)
return head;

int n= getCount(head);
     
LNode * start=head;
LNode dummyHead(0);
for(int size=1; size<n; size = size*2){
tail=&dummyHead;
while(start){
if (!start->next) {
tail->next = start;
break;
}
LNode* mid = split(start,size);
merge(start,mid);
start=nextSubList;
}
      start=dummyHead.next;

}

  return dummyHead.next;

}

LNode* LSorter::split(LNode* start, int size) {
      LNode* midPrev = start;
      LNode* end = start->next;
      //use fast and slow approach to find middle and end of second linked list
      for (int index = 1; index < size && (midPrev->next || end->next); index++) {
          if (end->next) {
              end = (end->next->next) ? end->next->next : end->next;
          }
          if (midPrev->next) {
              midPrev = midPrev->next;
          }
      }
      LNode* mid = midPrev->next;
      nextSubList = end->next;
      midPrev->next = nullptr;
      end->next = nullptr;
      // return the start of second linked list
      return mid;
  }

  void LSorter::merge(LNode* list1, LNode* list2) {
      LNode dummyHead(0);
      LNode* newTail = &dummyHead;
      while (list1 && list2) {
          if (list1->val < list2->val) {
              newTail->next = list1;
              list1 = list1->next;
              newTail = newTail->next;
          } else {
              newTail->next = list2;
              list2 = list2->next;
              newTail = newTail->next;
          }
      }
      newTail->next = (list1) ? list1 : list2;
      // traverse till the end of merged list to get the newTail
      while (newTail->next) {
          newTail = newTail->next;
      }
      // link the old tail with the head of merged list
      tail->next = dummyHead.next;
      // update the old tail with the new tail of merged list
      tail = newTail;
  }


int LSorter::getCount(LNode* head){
      LNode* ptr = head;
int cnt=0;
      while (ptr) {
          ptr = ptr->next;
          cnt++;
      }
      return cnt;
}
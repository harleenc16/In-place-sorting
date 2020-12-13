#ifndef LSorter_h
#define LSorter_h

#include <stdio.h>
#include "LNode.h"

class LSorter {
public:
LNode* tail;
   void merge(LNode* list1, LNode* list2);
   int getCount(LNode* head);
   LNode* nextSubList;
    LNode* split(LNode* start, int size);
    LNode* sortList(LNode* head);
};

#endif /* LSorter_h */

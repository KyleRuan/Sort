//
//  main.cpp
//  Sort
//
//  Created by Jason on 15/9/14.
//  Copyright © 2015年 KYLERUAN. All rights reserved.
//

#include <iostream>
#include "Sort.hpp"

int main(int argc, const char * argv[]) {
    
    using namespace std;
    Sort ss = *new Sort();
    int arr1[] = {1,5,6,4,8};
    ss.bubble_sort(arr1,5);
      int arr2[] = {1,5,6,4,8};
    ss.select_sort(arr2, 5);
     int arr3[] = {1,5,6,4,8};
    ss.insert_sort(arr3, 5) ;
     int arr4[] = {3,7,6,4,8,2,5,12};
    ss.quick_sort(arr4, 0, 7);
     int arr5[] = {3,7,6,4,8,2,5,99};
      int arr[] = {3,7,6,4,8,2,5,99};
      ss.merge_sort(arr5, arr, 0, 7);
    int arr6[] = {49,38,65,97,76,13,27,49};
    ss.heap_sort(arr6, 8);
      int arr7[] = {1,5,6,4,8,2};
    ss.shell_sort(arr7, 6) ;
    return 0;
    

}






//
//  Sort.hpp
//  Sort
//
//  Created by Jason on 15/9/14.
//  Copyright © 2015年 KYLERUAN. All rights reserved.
//

#ifndef Sort_cpp
#define Sort_cpp

#include <stdio.h>
#include <iostream>
class Sort{
private:
     void merge(int arr[], int temp_arr[], int start_index, int mid_index, int end_index);
        void heap_adjust(int arr[], int i, int len);
    
public:
     void  bubble_sort(int[], int);
     void select_sort(int [], int len);
    void insert_sort(int arr[], int len);
    void quick_sort(int arr[], int left, int right);
    void merge_sort(int arr[], int temp_arr[], int start_index, int end_index);
    void heap_sort(int arr[], int len);
     void shell_sort(int arr[] ,int len) ;
   
};

#endif /* Sort_cpp */

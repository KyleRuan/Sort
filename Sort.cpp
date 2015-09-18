//
//  Sort.cpp
//  Sort
//
//  Created by Jason on 15/9/14.
//  Copyright © 2015年 KYLERUAN. All rights reserved.
//

#include "Sort.hpp"



//MARK: 冒泡排序

/**
 *
 相邻的数据进行两两比较，小数放在前面，大数放在后面，这样一趟下来，最小的数就被排在了第一位，第二趟也是如此，如此类推，直到所有的数据排序完成
 *
 *  @param arr 数组
 *  @param len 数组长度
 */
void  Sort::bubble_sort(int arr[], int len){
    //从小到大
    for (int i = 0; i<len; i++) {
        for (int j = len-1; j>i; j--) {
            if (arr[j]<arr[j-1]) {
                int temp = arr[j] ;
                arr[j] = arr[j-1] ;
                arr[j-1] = temp ;
            }
        }
    }
    
//    从大到小
//    for (int i = 0; i<len; i++) {
//        for (int j = len-1; j>i; j--) {
//            if (arr[j]>arr[j-1]) {
//                int temp = arr[j] ;
//                arr[j] = arr[j-1] ;
//                arr[j-1] = temp ;
//            }
//        }
//    }

    
}

//MARK: - 选择排序
/**
 *  将数据分为两部分，有序部分与无序部分，一开始有序部分包含第1个元素，依次将无序的元素插入到有序部分，直到所有元素有序。插入排序又分为直接插入排序、二分插入排序、链表插入等，这里只讨论直接插入排序。它是稳定的排序算法，时间复杂度为O(n^2)
 *
 *  @param arr 数组
 *  @param len 数组长度
 */

void Sort::select_sort(int arr[], int len){
    for (int i= 0; i<len-1; i++) {
            int temp = i ;
        for (int j=i+1; j<len; j++) {
            if(arr[j]<arr[temp]){
                temp = j ;
            }
        }
        if (temp != i) {
            int arrTemp = arr[i] ;
            arr[i] = arr[temp] ;
            arr[temp] =arrTemp ;
        }
    }
}


//MARK: - 简单插入排序

/**
 *  算法原理
 将数据分为两部分，有序部分与无序部分，一开始有序部分包含第1个元素，依次将无序的元素插入到有序部分，直到所有元素有序。插入排序又分为直接插入排序、二分插入排序、链表插入等，这里只讨论直接插入排序。它是稳定的排序算法，时间复杂度为O(n^2)
 *
 *  @param arr 数组
 *  @param len 数组长度
 */
void Sort::insert_sort(int arr[], int len){
    for (int i=1; i<len; i++) {
        int temp = arr[i] ;
        for (int j = i-1; j>=0; j--) {
          //j+1位置一直是空的，
            if (arr[j]>temp) {
                arr[j+1] = arr[j] ;
            }else {
                arr[j+1] = temp ;
                break ;
            }
        }
        
    }
    
}


// MARK: -希尔排序
/**
 *  希尔排序
 *
 *  @param arr 数组
 *  @param len 数组长度s
 */
void Sort::shell_sort(int arr[] ,int len) {
	//增长区间
	for (int d = len /2; d>=1; d = d/2)
	{   //一次希尔排序
		for (int i = d; i < len; i++)
		{ 	 //和有序的数组的最后一个元素比较
            if (arr[i]<arr[i-d])
            {
                int temp = arr[i] ;
            	int j = i-d ;
            	while(j>=0&&arr[j]>temp){
                    arr[j+d] = arr[j];
                    j = j-d;
            	}
            	arr[j+d] = temp ;
            }
		}
	}

}

//MARK: -快速排序
/**
 *  通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 *
 *  @param arr   数组
 *  @param left  左边边界
 *  @param right 右边边界
 */
void Sort::quick_sort(int arr[], int left, int right){
    //递归结束条件
    if (left<right) {
        //一次遍历
        int i = left , j = right , key = arr[left] ;
         while (i<j) {
           	while (i<j&&arr[j]>key) 
            j-- ;
        	if (i<j)
            arr[i++] =arr[j];
        	while (i<j&& arr[i]<key)
            i++ ;
        	if (i<j) 
            arr[j--] = arr[i] ; 
         }
        //递归
        arr[i] =key ;
        quick_sort(arr, left, i-1);
        quick_sort(arr, i+1, right); 
    }

}


//MARK: -归并排序

/**
 *
 
合并有序数列
 *
 *  @param arr         待排序的数组
 *  @param temp_arr    合并好的数组
 *  @param start_index  待排序数组起始位置下标
 *  @param mid_index   待排序数组中间位置下标
 *  @param end_index   待排序数组的最后一个位置下标
 */

void Sort:: merge(int arr[], int temp_arr[], int start_index, int mid_index, int end_index){
    
    int i=start_index;
    int k=0;
    int j=mid_index+1 ;
    
    //直到一个组数被遍历完
    while (i<mid_index+1 && j<1+end_index) {
        if (arr[i]>arr[j]) {
            temp_arr[k++] =arr[j++];
        }else{
            temp_arr[k++] =arr[i++];
        }
    }
    //将没被遍历完的数组添加到数组中去
    while (i<1+mid_index) {
        temp_arr[k++]= arr[i++];
    }
    
    while (j<1+end_index) {
        temp_arr[k++] =arr[j++];
    }
    
    for (i = 0, j = start_index; j <1+end_index; i ++, j ++)
         arr[j] = temp_arr[i];

    
}
/**
 *  归并排序
 *
 *  @param arr         数组
 *  @param arr_temp    临时数组，存放排序好的数组
 *  @param start_index 开始下标
 *  @param end_index   结束下标
 */
void Sort::merge_sort(int arr[], int arr_temp[],int start_index, int end_index){
    if (start_index<end_index) {
        int mid = (start_index+end_index)/2 ;
        merge_sort(arr, arr_temp, start_index, mid);
        merge_sort(arr, arr_temp, mid+1, end_index);
        merge(arr, arr_temp, start_index, mid, end_index);
    }
}


//MARK: -堆排序

/**
 *  将数组生成堆 ,从小到大(大根堆)
 *
 *  @param arr 数组
 *  @param i   当前要生成堆的节点下标（从0开始）
 *  @param len 数组长度
 */
void Sort::heap_adjust(int arr[], int i, int len){

    int child = 2 * i + 1;
    int temp;
    while (child<len) {
        // 得到子结点中键值较大的结点 这里求的是大根堆, 如果是小根堆，下面变为arr[child + 1] < arr[child]
        if (child < len - 1 && arr[child + 1]>arr[child])
            child ++;
        //这里求的是大根堆，如果求小根堆arr[i] > arr[child]
        if (arr[i] <arr[child])
        {
            temp = arr[i];
            arr[i] = arr[child];
            arr[child] = temp;
            i =child ;
            child = 2 * i + 1;
        }
        else
            break;

    }
    
}


/**
 *  堆排序
 *
 *  @param arr 数组
 *  @param len 数组长度
 */
void Sort::heap_sort(int arr[], int len){

    int i;
    // 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heap_adjust(arr, i, len);
    }
    
    for (i = len - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        heap_adjust(arr, 0, i);
    }
}


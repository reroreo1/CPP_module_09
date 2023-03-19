/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:42:04 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/19 16:44:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <deque>
#include <ctime>
#define K 10
// procedure insertionSort(A: list of sortable items)
//    n = length(A)
//    for i = 1 to n - 1 do
//        j = i
//        while j > 0 and A[j-1] > A[j] do
//            swap(A[j], A[j-1])
//            j = j - 1
//        end while
//    end for
// end procedure

void insertionSort(std::vector<int> &arr, int start, int stop){
	int j;
	for (int i = start; i < stop;i++){
		j = i;
		 while (j > 0 and arr[j-1] > arr[j]){
           std::swap(arr[j], arr[j-1]);
           j -= 1;
		 }
	}
}
void merge(std::vector<int> &arr, int start, int stop,int mid){
	std::vector<int> right;
	std::vector<int> left;
	for (int i = start; i < mid;i++)
		left.push_back(arr[i]);
	for (int i = mid; i < stop;i++)
		right.push_back(arr[i]);
	size_t i = 0;
	size_t j = 0;
	int k = start;
	while (i < left.size() && j < right.size()){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size()){
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < right.size()){
		arr[k] = right[j];
		j++;
		k++;
	}
}
void mergeSort(std::vector<int> &arr, int start, int stop){
    if(stop - start > K){ 
        int mid = start + (stop-start)/2; 
        mergeSort(arr,start,mid); 
        mergeSort(arr,mid+1,stop); 
        merge(arr,start,stop,mid);
    } 
	else{
		std::cout << "insertionSort" << std::endl;
		insertionSort(arr,start,stop);
	}
}
 
int main(int ac, char **av){
	std::vector<int> numbers;
	std::deque<int> numbers1;
	int a;
	clock_t start,end,start1,end1;
	for (int i = 1;i < ac;i++){
		try{
			a = std::stoi(av[i]);
		}
		catch(...){
			std::cout << "please enter valid arguments" << std::endl;
			return -1;
		}
		if (a < 0){
			std::cout << "Error" << std::endl;
			return 0;
		}
		numbers.push_back(a);
		numbers1.push_back(a);
	}
	std::cout << "Before:     ";
	for(size_t i = 0; i < numbers.size() - 1;i++)
		std::cout << numbers[i] <<  " ";
	std::cout << numbers[numbers.size() - 1] << std::endl;
	start = clock();
	mergeSort(numbers,0,numbers.size());
	end = clock() - start;
	start1 = clock(); 
	// mergeSortD(numbers1,0,numbers1.size());
	end1 = clock() - start1; 
	std::cout << "after:     ";
	for(size_t i = 0; i < numbers.size() - 1;i++)
		std::cout << numbers[i] <<  " ";
	std::cout << numbers[numbers.size() - 1] << std::endl;
	std::cout << "Time to process a range of "<<  ac << " elements with std::vector : ";
	std::cout << (end / (float) CLOCKS_PER_SEC) / 1000000  <<" us"<< std::endl;
	// std::cout << "Time to process a range of "<<  ac << " elements with std::deque : ";
	// std::cout << (end1 / (float) CLOCKS_PER_SEC) / 1000000  <<" us"<< std::endl;
}


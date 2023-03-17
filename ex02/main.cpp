/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:42:04 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/17 22:42:05 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <deque>
#include <ctime>

void mergeInsertion(std::vector<int> &arr){
	int j;
	for (size_t i = 0; i < arr.size();i++){
		j = i;
		 while (j > 0 and arr[j-1] > arr[j])
           std::swap(arr[j], arr[j-1]);
           j -= 1;
	}
}

void mergeSort(std::vector<int> &arr, int start, int stop){
    if(stop>start){ 
        int mid = start + (stop-start)/2; 
        mergeSort(arr,start,mid); 
        mergeSort(arr,mid+1,stop); 
        mergeInsertion(arr);
    } 
}

void mergeInsertionD(std::deque<int> &arr){
	int j;
	for (size_t i = 0; i < arr.size();i++){
		j = i;
		 while (j > 0 and arr[j-1] > arr[j])
           std::swap(arr[j], arr[j-1]);
           j -= 1;
	}
}

void mergeSortD(std::deque<int> &arr, int start, int stop){
    if(stop>start){ 
        int mid = start + (stop-start)/2; 
        mergeSortD(arr,start,mid); 
        mergeSortD(arr,mid+1,stop); 
        mergeInsertionD(arr);
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
	mergeSortD(numbers1,0,numbers1.size());
	end1 = clock() - start1; 
	std::cout << "after:     ";
	for(size_t i = 0; i < numbers.size() - 1;i++)
		std::cout << numbers[i] <<  " ";
	std::cout << numbers[numbers.size() - 1] << std::endl;
	std::cout << "Time to process a range of "<<  ac << " elements with std::vector : ";
	std::cout << (end / (float) CLOCKS_PER_SEC) / 1000000  <<" us"<< std::endl;
	std::cout << "Time to process a range of "<<  ac << " elements with std::deque : ";
	std::cout << (end1 / (float) CLOCKS_PER_SEC) / 1000000  <<" us"<< std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:41:46 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/17 22:41:47 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

bool isLeap(int year)
{
	return (((year % 4 == 0) && 
         (year % 100 != 0)) ||
         (year % 400 == 0));
}
  
bool isValidDate(int d, int m, int y)
{
	if (y > 3000 || y < 2000)
	return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
    return true;
}

void parseBTC(const std::string &file, std::map<std::string,std::string> &a){
	std::ifstream file1(file);
	if (file1.is_open()) {
	    std::string line;
		std::getline(file1,line);
	    while (std::getline(file1, line)) {
			std::string key;
			std::string value;
	        std::stringstream ss(line);
			std::getline(ss,key,',');
			std::getline(ss,value);
			a.insert(std::make_pair(key,value));
	    }
	    file1.close();
	}
	else
		std::cout << "database Error\n"<<std::endl;
}
int isNum(std::string num){
	for(size_t i = 0;i < num.length();i++)
		if (!isdigit(num[i]) && num[i] != '.')
			return 1;
	return 0;
}

bool dateValidator(std::string date){
	std::string d,m,y;
	int d1,m1,y1;
	std::stringstream ss(date);
	std::getline(ss,y,'-');
	if (!isNum(y))
		y1 = atoi(y.c_str());
	else
		return false;
	std::getline(ss,m,'-');
	if (!isNum(m))
		m1 = atoi(m.c_str());
	else
		return false;
	std::getline(ss,d);	
	if (!isNum(d))
		d1 = atoi(d.c_str());
	else
		return false;
	return (isValidDate(d1,m1,y1));
}


std::string getBTCprice(std::map<std::string,std::string> &a,std::string metadata){
	std::string key;
	std::string value;
	std::stringstream ss(metadata);
	double d;
	double d1;
	std::getline(ss,key,' ');
	if (!dateValidator(key)){
		std::cout << key + " => " << "Invalid Date" << std::endl;
		return "";
	}
	std::getline(ss,value);
	try {
			value = value.substr(2,value.npos);
	}
	catch(...){
		std::cout << "Error: bad input => " << metadata <<std::endl;
	}
	std::stringstream dd(value);
	dd >> d;
	if (d < 0){
		std::cout << "Error: not a positive number.\n";
		return "";
	}
	if(d > 1000){
		std::cout << "Error: too large a number.\n";
		return "";
	}
	std::map<std::string,std::string>::iterator it = a.lower_bound(key);
	std::stringstream dd1(it->second);
	dd1 >> d1;
	std::cout << key + " => " + value + " = " << d1 * d << std::endl;
	return "";
}

int main(int ac,char **av){
	std::map<std::string,std::string> a;
	if (ac ==2){
		std::string line;
		std::ifstream file1(av[1]);
		parseBTC("data.csv",a);
		if(file1.is_open()){
			std::getline(file1,line);
			while (std::getline(file1, line)) {
				getBTCprice(a,line);
			}
		}
		else
			std::cout << "can t Open the file\n"; 
	}
}
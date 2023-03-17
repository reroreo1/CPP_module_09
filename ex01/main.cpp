/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:41:52 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/17 22:41:53 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <iostream>

int main(int ac,char **av){
    if(ac == 2){
        std::string expression = av[1];
        RPN rpn(expression);
    }
    else{
        std::cout << "enter a Valid RPN expression" << std::endl;
    }
}
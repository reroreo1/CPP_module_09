/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:41:57 by rezzahra          #+#    #+#             */
/*   Updated: 2023/03/17 22:41:58 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


void RPN::checkOp(std::string expression){
    for (size_t i = 0; i < expression.length();i++){
        if (expression[i] >= '0' && expression[i] <= '9' && operands.size() < 2){
            operands.push(expression[i] - '0');
        }
        else if(expression[i] == ' ')
            continue;
        else if (expression[i] == '+'){
            executeOp('+');

        }
        else if (expression[i] == '-'){
            executeOp('-');
        }
        else if (expression[i] == '*'){
            executeOp('*');
        }
        else if (expression[i] == '/'){
            executeOp('/');
        }
        else{
            std::cout << "Operand error" << std::endl;
            exit(1) ;
        }
    }
    result = operands.top();
}

void RPN::executeOp(char operation){
    if (operands.size() != 2)
        throw std::runtime_error("Not enough operands");
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();
    if (operation == '+')
        operands.push(a + b);
    else if (operation == '-')
        operands.push(b - a);
    else if (operation == '*')
        operands.push(a * b);
    else if (operation == '/'){
        if (a == 0)
            throw std::runtime_error("Division by zero");
        operands.push(b / a);
    }
}
RPN::RPN(std::string& expression){
    checkOp(expression);
    std::cout << result << std::endl;
}

RPN::~RPN(){
}
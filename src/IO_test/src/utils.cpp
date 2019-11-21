/*
 * utils.cpp
 *
 *  Created on: 2019��10��31��
 *      Author: ʯ����Sesen��
 */

#include <iostream>
#include <string>

#include "Sales_data.h"
using namespace std;

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price;
	is >> item.bookno >> item.units_sold >> price;
	item.total_money = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << "������ " << item.isbn() << " �۳������� " << item.units_sold <<
    		"  �����ܶ " << item.total_money << " �۳�����:" << item.avg_price();
    return os;
}
Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}
/*
 * date_test.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: pthim
 */
#include "date.h"
#include <iostream>
#include <ctime>

using namespace std;
using namespace main_savitch_3;

int main() {
	cout << "Creating a date using today's date: " << endl;
	time_t t = time(0);
	struct tm* now = localtime( &t);
	date test_date(now->tm_mday,now->tm_mon + 1,now->tm_year + 1900);
	cout << "Date created (numerically): " << endl;
	test_date.print_date();
	cout << "Incrementing the date." << endl;
	test_date.increment_day();
	cout << "Updated date: " << endl;
	test_date.print_date();
	cout << endl;

	cout << "Creating a date at the end of a month and incrementing." << endl;
	test_date.set_month(10);
	test_date.set_day(31);
	cout << "Date created (as text): " << endl;
	test_date.print_string();
	cout << "Incrementing the date." << endl;
	test_date.increment_day();
	test_date.print_string();
	cout << endl;

	cout << "Adjusting date to evaluate leap years: " << endl;
	test_date.set_year(2016);
	test_date.set_month(2);
	test_date.set_day(28);
	cout << "Date should be 2/28/2016." << endl;
	test_date.print_date();
	cout << "Incrementing the date." << endl;
	test_date.increment_day();
	test_date.print_date();
	cout << "Changing the year to a non-leap year." << endl;
	test_date.set_year(2015);
	test_date.print_date();
}



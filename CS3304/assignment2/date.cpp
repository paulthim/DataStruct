/*
 * date.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: pthim
 */
#include "date.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const string days_of_week[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
};

const string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
};

namespace main_savitch_3
{
	date::date() {
		time_t t = time(0);
		struct tm* now = localtime( &t);
		set_year(now->tm_year + 1900);
		set_month(now->tm_mon + 1);
		set_day(now->tm_mday);
	}

	date::date(int day, int month, int year) {
		set_year(year);
		set_month(month);
		set_day(day);
	}

	void date::set_day(int new_day) {
		if(new_day > 0 && new_day <= max_mday())
			day = new_day;
	}

	void date::set_month(int new_month) {
		if (new_month > 0 && new_month < 13)
			month = new_month;
		if (day > max_mday()) {
			set_day(1);
		}
	}

	void date::set_year(int new_year) {
		if (new_year >= 1900)
			year = new_year;
		if (day > max_mday()) {
			set_day(day - 1);
		}
	}

	void date::increment_day() {
		if (day == max_mday()) {
			day = 1;
			if (month+1 == 13) {
				year += 1;
				set_month(1);
			} else set_month(month+1);
		}
		else set_day(day+1);
	}

	int date::max_mday() const {
		if (month == 4 || month == 6 ||
				month == 9 || month == 11)
			return 30;
		else if (month == 2) {
			if (is_leap_year()) return 29;
			else return 28;
		}
		else return 31;
	}

	bool date::is_leap_year() const {
		if ((year % 4 == 0 && year % 100 != 0)
				or year % 400 == 0) {
			return true;
		}
		else return false;
	}

	void date::print_date() {
		cout << month << "/" << day << "/" << year << endl;
	}

	void date::print_string() {
		int weekday = day_of_week();
		cout << days_of_week[weekday] << " " << months[month - 1] << " " << day << ", " << year << endl;
	}

	int date::day_of_week() const {
		static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
		int y = year - month < 3;
		return (y + y/4 - y/100 + y/400
				+ t[month-1] + day) % 7;
	}
}



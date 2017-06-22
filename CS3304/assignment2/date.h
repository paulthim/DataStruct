/*
 * date.h
 *
 *  Created on: Jun 8, 2017
 *  Author: pthim
 *
 *  Class DATE:
 *
 *  CONSTRUCTOR:
 *  	date()
 *  		Postcondition: Assigns the current date to this date
 *  	date(int day, int month, int year)
 *  		Postcondition: Creates a date with the given day, month, and year. Default is 1/1/1900/
 *
 *  MODIFICATION MEMBER FUNCTIONS:
 *  	void set_day(int day)
 *  		Precondition: Day is non-negative.
 *  		Postcondition: The date's current day is set to this day. If the day is outside of
 *  		the range for the given month, no change is made.
 *
 *  	void set_month(int month)
 *  		Precondition: Month is between 1 and 12.
 *  		Postcondition: The date's current month is set to this month. If this puts the day
 *  		outside of range, day is set to 1.
 *
 *  	void set_year(int year)
 *  		Precondition: Year is >= 1900.
 *  		Postcondition: The date's current year is set to this year. If this puts the day
 *  		outside of range (in the case of non-leap years), day is set to 1.
 *
 *  	void increment_day()
 *  		Postcondition: The date is moved forward by one day. This update month and year as
 *  		appropriate.
 *
 *  CONSTANT MEMBER FUNCTIONS:
 *		int get_day() const
 *			Postcondition: The int returned is the date's current day.
 *
 *		int get_month() const
 *			Postcondition: The int returned is the date's current month.
 *
 *		int get_year() const
 *			Postcondition: The int returned is the date's current year.
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
#include <string>

namespace main_savitch_3
{
	class date {
	public:
		// CONSTRUCTORS
		date();
		date(int day = 1, int month = 1, int year = 1900);
		// MODIFICATION MEMBER FUNCTIONS
		void set_day(int new_day);
		void set_month(int new_month);
		void set_year(int new_month);
		void increment_day();
		void print_date();
		void print_string();
		// CONSTANT MEMBER FUNCTIONS
		int get_day() const { return day; }
		int get_month() const { return month; }
		int get_year() const { return year; }
		int max_mday() const;
		bool is_leap_year() const;
		int day_of_week() const;
	private:
		int day, month, year;
	};


}


#endif /* DATE_H_ */

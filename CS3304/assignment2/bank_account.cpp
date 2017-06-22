/*
 * bank_account.cpp
 *
 *  Created on: June 8, 2017
 *      Author: pthim
 */
#include "bank_account.h"
#include <cassert>


namespace main_savitch_3
{
	bank_account::bank_account(value_type starting_balance, rate_type rate) {
		balance = starting_balance;
		interest_rate = rate;
	}

	void bank_account::set_rate(rate_type new_rate) {
		if(new_rate >= 0) //rate of 0% is possible in the real world, but kinda sucks.
			interest_rate = new_rate;
	}

	void bank_account::deposit(value_type deposit_amount) {
		if(deposit_amount >= 0)
				balance += deposit_amount;
	}

	void bank_account::withdraw(value_type withdrawal_amount) {
		if(withdrawal_amount >= 0 && withdrawal_amount <= balance)
			balance -= withdrawal_amount;
	}

	void bank_account::add_interest(time_type number_of_years) {
		if(number_of_years >= 0)
			balance *= (interest_rate * number_of_years);
	}

	bank_account::time_type bank_account::time_to_balance(value_type final_balance) const {
		if(final_balance > 0 && interest_rate > 0) { // prevent division by 0
			bank_account::time_type number_of_years;
			number_of_years = final_balance/(current_balance() * interest_rate);
			return number_of_years;
		}
		else
			return 0;
	}

	bank_account::value_type bank_account::balance_needed(value_type final_balance, time_type number_of_years) const {
		if(interest_rate > 0) // prevent division by 0
			return final_balance/(number_of_years * interest_rate);
		else
			return 0;
	}

	bank_account::value_type bank_account::current_balance() const {
		return balance;
	}

	bank_account::rate_type bank_account::get_rate() const {
		return interest_rate;
	}
}



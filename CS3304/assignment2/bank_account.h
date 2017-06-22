/*
 * bank_account.h
 *
 *  Created on: Jun 8, 2017
 *  Author: pthim
 *
 *      class fields:
 *      	balance : the current balance of the account
 *      	interest_rate : annual interest rate
 *
*      	constructor:
*      		initial_balance >0
*      		interest_rate > 0
*
*      	public functions:
*      		deposit(amount) returns void : amount > 0
*      		withdraw(amount) returns void : 0 < amount <= balance
*      		current_balance() returns balance
*      		add_interest(number_of_years) returns void : number_of_years can be fractional, > 0
*			time_to_balance(final_balance) returns number_of_years : given a goal balance, how long at the current interest rate.
*			balance_needed(final_balance, number_of_years) returns initial balance needed; both > 0, balance <= final_balance
*				if balance_needed > balance, calculate payments needed to reach it. (balance_needed-balance)/number_of_years
*
 */

#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

namespace main_savitch_3
{
	class bank_account {
	public:
		typedef double value_type; //balance is by default a double (even pennies matter)
		typedef double rate_type; //unlikely for interest to not be double, but just in case
		typedef double time_type; //allows for fraction years
		//CONSTRUCTOR
		bank_account(value_type starting_balance = 0.0, rate_type rate = 0.0);
		//MODIFICATION MEMBER FUNCTIONS
		void set_rate(rate_type new_rate);
		void deposit(value_type deposit_amount);
		void withdraw(value_type withdrawal_amount);
		void add_interest(time_type number_of_years);
		//CONSTANT MEMBER FUNCTIONS
		value_type current_balance() const;
		rate_type get_rate( ) const;
		time_type time_to_balance(value_type final_balance) const;
		value_type balance_needed(value_type final_balance, time_type number_of_years) const;
	private:
		value_type balance;
		rate_type interest_rate;
	};
}



#endif /* BANK_ACCOUNT_H_ */

/*
 * bank_account_test.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: pthim
 */

#include "bank_account.h"
#include <cassert>
#include <iostream>
using namespace std;
using namespace main_savitch_3;

bank_account::value_type account1balance = 500.0;
bank_account::rate_type account1rate = 1.5;
bank_account::value_type account2 = 20000.0;
double data[] = {500.0, 1.5, 20, 275, 17, 2000.0, 0, 35, 500, 23};
double false_data[] = {-10.0, -2};

bool test1(bank_account& test, int account_number) {
	int index = account_number * 5;
	bank_account::value_type current_balance = data[index+0];
	bank_account::rate_type rate = data[index+1];
	bank_account::value_type deposit = data[index+2];
	bank_account::value_type withdrawal = data[index+3];
	bank_account::time_type years = data[index+4];

	cout << "Beginning detailed tests on this account." << endl;
	cout << "This test will deposit, then withdraw, then add interest over a period of time." << endl;

	cout << "Depositing " << deposit << " into account." << endl;
	test.deposit(deposit);
	current_balance += deposit; //should match the arithmetic performed by deposit()
	assert(test.current_balance() == current_balance);

	cout << "Withdrawing " << withdrawal << " from account." << endl;
	test.withdraw(withdrawal);
	current_balance -= withdrawal; //as above, should match arithmetic performed by withdraw()
	assert(test.current_balance() == current_balance);

	cout << "Adding interest over a period of " << years << " years." << endl;
	test.add_interest(years);
	current_balance *= (years * rate); // should match arithmetic performed by add_interest
	assert(test.current_balance() == current_balance);

	if (account_number == 1) {
		cout << "Additional rate testing." << endl;
		cout << "Setting interest rate to .7 and verifying rate." << endl;
		test.set_rate(.7);
		rate = .7;
		assert(test.get_rate() == rate);
		cout << "Adding interest over a period of " << years << " years." << endl;
		test.add_interest(years);
		current_balance *= (years * rate);
		assert(test.current_balance() == current_balance);
	}

	return true;
}

bool test2(bank_account& test) {
	cout << "This test will evaluate assertions and checks of the modification functions." << endl;
	cout << "Attempting to deposit a negative amount." << endl;
	bank_account::value_type beginning_balance = test.current_balance();
	test.deposit(false_data[0]);
	assert(test.current_balance() == beginning_balance); // balance should be unchanged.
	cout << "Attempting to withdraw more than is contained in the account." << endl;
	test.withdraw(test.current_balance() + 50);
	assert(test.current_balance() == beginning_balance); // balance should be unchanged.
	cout << "Attempting to change interest rate to a negative." << endl;
	test.set_rate(false_data[1]);
	assert(test.current_balance() == beginning_balance); // balance should be unchanged.
	return true;
}

int main() {
	bool result;
	cout << "Creating an account with a starting balance of " << account1balance << " and interest rate of " << account1rate << endl;
	bank_account bank_account0(account1balance, account1rate);
	cout << "Checking that values assigned correctly:" << endl;
	result = (bank_account0.current_balance() == account1balance);
	cout << "Balance correct: " << (result ? "PASSED" : "FAILED") << endl;
	result = (bank_account0.get_rate() == account1rate);
	cout << "Interest correct: " << (result ? "PASSED" : "FAILED") << endl;

	result = test1(bank_account0, 0);
	cout << "First test on account 0 " << (result ? "PASSED." : "FAILED.") << endl;
	cout << endl;
	result = (test2(bank_account0));
	cout << "Second test on account 0 " << (result ? "PASSED." : "FAILED.") << endl;
	cout << endl;

	bank_account::value_type account2balance = data[5];
	cout << "Creating an account with a balance of " << account2balance << " and no supplied interest rate." << endl;
	bank_account bank_account1(data[5]);
	cout << "Interest rate should default to 0." << endl;
	result = (bank_account1.get_rate() == 0);
	cout << "Interest correct: " << (result ? "PASSED" : "FAILED") << endl;
	result = test1(bank_account1, 1);
		cout << "First test on account 1 " << (result ? "PASSED." : "FAILED.") << endl;
	cout << endl;
	result = (test2(bank_account1));
	cout << "Second test on account 1 " << (result ? "PASSED." : "FAILED.") << endl;
	cout << endl;

}


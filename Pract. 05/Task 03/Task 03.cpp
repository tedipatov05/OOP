// Task 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace CONSTANTS {
	constexpr int NAME_MAX_LEN = 15;
	constexpr int ACCOUNT_MAX_LEN = 30;
	constexpr int BANK_ACCOUNT_MAXLEN = 1024;
	const char DELIM = '\n';
	constexpr int BANK_INITIAL_CAPACITY = 8;
}

class Bank {
public:

	Bank() {
		len = 0;
		capacity = CONSTANTS::BANK_INITIAL_CAPACITY;
		accounts = new BankAccount[capacity];

	}
	Bank(std::ifstream& ifs) {
		getBankAccounts(ifs);
	}

	void addBankAccount(const BankAccount& bankAccount) {
		if (len == capacity) {
			resize(capacity * 2);
		}

		accounts[len++] = bankAccount;

	}

	void removeBankAccount(char* accountNumber) {

		int indexToRemove = -1;
		for (int i = 0; i < len; i++) {
			if (strcmp(this->accounts[i].getAccount(), accountNumber) == 0) {
				indexToRemove = i;
				break;
			}
		}

		if (indexToRemove == -1) {
			std::cout << "This account doesn't exist" << std::endl;
		}

		shiftLeft(indexToRemove);

		len--;
	}

	double getAccountBalance(char* accountNumber) const {

		for (size_t i = 0; i < len; i++) {
			if (strcmp(this->accounts[i].getAccount(), accountNumber) == 0) {
				return this->accounts[i].getBalance();
			}
		}

		return 0.0;
	}

	double getClientBalance(char* name) const {
		double sum = 0;

		for (size_t i = 0; i < len; i++) {
			if (strcmp(this->accounts[i].getName(), name) == 0) {
				sum += this->accounts[i].getBalance();
			}
		}

		return sum;
	}

	void saveInfo(std::ofstream& ofs) {
		for (size_t i = 0; i < len; i++) {
			this->accounts[i].getInfo(ofs);
		}
	}

	~Bank() {
		delete[] accounts;
	}


private:

	BankAccount* accounts;
	int capacity = 0;
	int len = 0;

	void getBankAccounts(std::ifstream& ifs) {

		len = 0;
		capacity = CONSTANTS::BANK_INITIAL_CAPACITY;
		this->accounts = new BankAccount[capacity];

		size_t index = 0;

		while (true) {
			BankAccount bankAccount;
			bankAccount.readBankAccountFromFile(ifs);

			addBankAccount(bankAccount);

			if (ifs.eof()) {
				break;
			}
		}



	}

	void resize(int newCapacity) {
		capacity = newCapacity;

		BankAccount* temp = new BankAccount[capacity];
		for (size_t i = 0; i < len; i++) {
			temp[i] = accounts[i];
		}

		delete[] accounts;

		accounts = temp;
	}

	void shiftLeft(int index) {
		for (int i = 0; i < len - 1; i++) {
			accounts[i] = accounts[i + 1];
		}
	}




};

class BankAccount {

	char name[CONSTANTS::NAME_MAX_LEN];
	char account[CONSTANTS::ACCOUNT_MAX_LEN];
	double balance = 0;

	void setName(const char* name) {
		size_t len = strlen(name);
		if (len >= CONSTANTS::NAME_MAX_LEN) {
			return;
		}

		strcpy(this->name, name);
	}

	void setAccount(const char* account) {
		size_t len = strlen(account);
		if (len >= CONSTANTS::ACCOUNT_MAX_LEN) {
			return;
		}

		strcpy(this->account, account);
	}

	void setBalance(double balance) {
		this->balance = balance;
	}

public:
	BankAccount() {
		setName("");
		setAccount("");
		setBalance(0);

	}
	BankAccount(const char* name, const char* account, double balance) {
		setName(name);
		setAccount(account);
		setBalance(balance);
	}
	BankAccount(char* name, char* account) {
		setAccount(account);
		setName(name);
	}

	void deposit(double amount) {
		this->balance += amount;
	}

	char* getAccount() {
		return this->account;
	}

	char* getName() {
		return this->name;
	}

	double getBalance() {
		return this->balance;
	}

	void readBankAccountFromFile(std::ifstream& ifs) {
		ifs.getline(this->name, CONSTANTS::NAME_MAX_LEN, CONSTANTS::DELIM);
		ifs.getline(this->account, CONSTANTS::ACCOUNT_MAX_LEN, CONSTANTS::DELIM);
		ifs >> balance;
		ifs.ignore();

	}

	void draw(double amount) {
		if (this->balance < amount) {
			std::cout << "Cannot withdraw. Don't have enough money." << std::endl;
			return;
		}

		this->balance -= amount;
	}

	void getInfo(std::ostream& stream) {
		stream << this->name << " " << this->account << " " << this->balance << std::endl;
	}
};

int main()
{
	BankAccount account("Test", "473648713", 2000);
	account.deposit(100);
	account.draw(50);
	account.getInfo(std::cout);
}

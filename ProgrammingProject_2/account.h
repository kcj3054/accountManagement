#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class accountManageMent
{
public:
	accountManageMent() {}
	accountManageMent(string accountHolder, int accountNumber, int accountSecretNumber, int balance);
	~accountManageMent () {}

public:

	//�Ա�
	void Deposit(int accountNumber, int value, vector<accountManageMent*>&v);
	//���
	void Withdraw(int accountNumber, int secretNum, int value, vector<accountManageMent*>&v); // ��� 
	//��ȸ
	void Search(std::string name, int accountNumber, 
		vector< accountManageMent*>&v);
	
	void Info();

	//getter, setter ����..
public:

	string	getName() { return _accountHolder; }
	void	setName(string name) { _accountHolder = name; }

	int		getAccountNumber() { return _accountNumber; }
	void	setAccountNumber(int num) { _accountNumber = num; }

	int		getAccountSecretNumber() { return _accountSecretNumber; }
	void	setAccountSecretNumber(int num) { _accountSecretNumber = num;}

	int		getMoney() { return _balance; }
	void	setMoney(int money) { _balance += money; }

private:
	std::string		_accountHolder = "";
	int				_accountNumber = 0;
	int				_accountSecretNumber = 0;
	int				_balance = 0;

};


#include "account.h"

accountManageMent::accountManageMent(string accountHolder, int accountNumber, int accountSecretNumber, int balance)
{
	_accountHolder = accountHolder;
	_accountNumber = accountNumber;
	_accountSecretNumber = accountSecretNumber;
	_balance = balance;
}

//계좌정보를 입력받아서, +value만큼 입금.. 
void accountManageMent::Deposit(int accountNumber, int value, vector<accountManageMent*>&v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getAccountNumber())
		{
			v[i]->setMoney(value);
			return;
		}
	}
}

//출금할 경우 통장 잔고보다 더 많은 금액을 출금할 경우 에러..
void accountManageMent::Withdraw(int accountNumber, int secretNum, int value, vector<accountManageMent*>&v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getAccountNumber() && v[i]->getAccountSecretNumber())
		{
			int nowMoney = v[i]->getMoney();
			int nextMoney = nowMoney - value;
			if (nextMoney < 0)
			{
				cout << "출금 금액이 부족합니다 현재  잔고는 " << nowMoney << "입니다." << endl;
				break;
			}
			else
			{
				cout << value << "가 출금되었습니다" << endl;
				v[i]->setMoney(-value);
				return;
			}
		}
	}
}
 
void accountManageMent::Search(std::string name, int accountNumber, vector<accountManageMent*>&v)
{
	//예끔주나, 예좌번호를 입력받아서
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getName() == name && v[i]->getAccountNumber() == accountNumber)
		{
			// 화면에서 출력
			Info();
			return ;
		}
	}

	cout << "조회를 할 수 없습니다" << endl;
}

void accountManageMent::Info()
{
	cout << "계좌번호 : " << _accountSecretNumber << endl;
	cout << "예금주 : " << _accountHolder << endl;
	cout << "잔액 : " << _balance << endl;
}

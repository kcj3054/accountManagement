#include "account.h"

accountManageMent::accountManageMent(string accountHolder, int accountNumber, int accountSecretNumber, int balance)
{
	_accountHolder = accountHolder;
	_accountNumber = accountNumber;
	_accountSecretNumber = accountSecretNumber;
	_balance = balance;
}

//���������� �Է¹޾Ƽ�, +value��ŭ �Ա�.. 
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

//����� ��� ���� �ܰ��� �� ���� �ݾ��� ����� ��� ����..
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
				cout << "��� �ݾ��� �����մϴ� ����  �ܰ�� " << nowMoney << "�Դϴ�." << endl;
				break;
			}
			else
			{
				cout << value << "�� ��ݵǾ����ϴ�" << endl;
				v[i]->setMoney(-value);
				return;
			}
		}
	}
}
 
void accountManageMent::Search(std::string name, int accountNumber, vector<accountManageMent*>&v)
{
	//�����ֳ�, ���¹�ȣ�� �Է¹޾Ƽ�
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getName() == name && v[i]->getAccountNumber() == accountNumber)
		{
			// ȭ�鿡�� ���
			Info();
			return ;
		}
	}

	cout << "��ȸ�� �� �� �����ϴ�" << endl;
}

void accountManageMent::Info()
{
	cout << "���¹�ȣ : " << _accountSecretNumber << endl;
	cout << "������ : " << _accountHolder << endl;
	cout << "�ܾ� : " << _balance << endl;
}

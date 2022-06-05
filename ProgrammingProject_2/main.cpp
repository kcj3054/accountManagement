#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <fstream>

#include <conio.h> // Windows.. -> _getch(), _getche() -> _getche()�� e�� echo �޸����̴� buffer�� ���� ���·� �����Ѵ�..
#include "account.h"

using namespace std;

int main()
{
	int cmd = 0;
	FILE* readFile;   // file pointer to write
	FILE* writeFile;
	vector<accountManageMent*> Info;
	vector<accountManageMent*>::iterator it;

	string name;
	int accountNumber = 0, secretNumber = 0, value = 0;

	ifstream infile("account.txt");
	string s;
	int a = 0, b = 0, c = 0;
	cout << Info.size() << endl;
	while (infile.eof() == false)
	{
		/*infile >> s >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		Info.push_back(new accountManageMent(s, a, b, c));*/
		

		infile >> s;
		if (infile.eof())
			break;
		infile >> a;
		if (infile.eof())
			break;
		infile >> b;
		if (infile.eof())
			break;
		infile >> c;
		if (infile.eof())
			break;
		if (a == 0 && b == 0 && c == 0) break;
		Info.push_back(new accountManageMent(s, a, b, c));

		/*if (!(infile >> s))
			break;
		if (!(infile >> a))
			break;*/
	}
	cout << Info.size() << endl;
	for(auto a : Info)
	{
		 a->Info();
		 cout << endl;
	}
	while (true)
	{
		cout << "=================�޴�===================" << endl;
		cout << "1. �������� ��������" << endl;
		cout << "2. �Ա� " << endl;
		cout << "3. ���" << endl;
		cout << "4. ��ȸ" << endl;
		cout << "5. �����߰� " << endl; //�����߰� ������ ����Ŭ�������� �ϴ� ���̾ƴϴ�..
		cout << "6. ���»��� " << endl;
		cout << "7. ���� " << endl;

		cin >> cmd;
		rewind(stdin);
		if (cmd == 1)
		{
			//1.	���������� �������⡯�� ������Ʈ ���� �� 
			//account.txt ������ ������ �о ȭ�鿡 ���kcj
			cout << "������ ���¹�ȣ ���º�й�ȣ �ܰ�" << endl;

			ifstream infile2("account.txt");
			while (infile2.eof() == false)
			{
				

				infile2 >> s >> a >> b >> c;
				if (a == 0 && b == 0 && c == 0) break;
				cout << s << " " << a << " " << b << " " << c << endl;

				if (!(infile >> s))
					break;
				if (!(infile >> a))
					break;
			}
		}
		else if (cmd == 2)
		{
			cout << "���¹�ȣ ���º�й�ȣ �Ա� �ݾ��Է����ּ���" << endl;
			//�Ա�
			cin >> accountNumber >> secretNumber >> value;

			
			for (int i = 0; i < (int)Info.size(); i++)
			{
				if (Info[i]->getAccountNumber() == accountNumber && Info[i]->getAccountSecretNumber() == secretNumber)
				{
					Info[i]->setMoney(value);
					break;
				}
				else if (Info[i]->getAccountNumber() == accountNumber && Info[i]->getAccountSecretNumber() != secretNumber)
				{
					cout << "��й�ȣ��  Ʋ�Ƚ��ϴ� �ٽ� Ȯ�����ּ���" << endl;
					break;
				}
				else if (Info[i]->getAccountNumber() != accountNumber)
				{
					cout << "��ϵ��� ���� ���¹�ȣ�Դϴ�" << endl;
					break;
				}
			}
		}
		else if (cmd == 3)
		{
			//���
			cout << "���¹�ȣ ��й�ȣ ���ϴ� �ݾ� ������ �Է����ּ���" << endl;

			cin >> accountNumber >> secretNumber >> value;

			for (int i = 0; i < Info.size(); i++)
			{
				if (Info[i]->getAccountNumber() && Info[i]->getAccountSecretNumber() == secretNumber)
				{
					Info[i]->Withdraw(accountNumber, secretNumber, value, Info);
					break;
				}
				else if (Info[i]->getAccountNumber() && Info[i]->getAccountSecretNumber() != secretNumber)
				{
					cout << "��й�ȣ�� ��ġ�����ʽ��ϴ�" << endl;
				}
			}
		}
		else if (cmd == 4)
		{
			//��ȸ
			bool IsOk = false;
			cout << "�̸� ���¹�ȣ ������ �Է��ϼ���" << endl;
			cin >> name >> accountNumber;
			for (int i = 0; i < Info.size(); i++)
			{
				if (Info[i]->getName() == name)
				{
					Info[i]->Info();
					IsOk = true;
					break;
				}
			}
			if (!IsOk)
			{
				cout << "��ȸ�� �� �����ϴ� " << endl;
				system("cls");
			}
		}
		else if (cmd == 5)
		{
			bool IsOk = true;
			//���� �߰�
			//������, ���¹�ȣ, ��й�ȣ, �Աݾ��� �Է� �޾� �ش� ���¿� ���� ���� �߰�
			cout << "�̸�, ���¹�ȣ, ��й�ȣ, �Ա��� �ݾ׼����� �Է����ּ���" << endl;
			cin >> name >> accountNumber >> secretNumber >> value;

			for (int i = 0; i < Info.size(); i++)
			{
				if (Info[i]->getAccountNumber() == accountNumber)
				{
					cout << "�̹� �����ϴ� ���¹�ȣ�Դϴ�" << endl;
					IsOk = false;
					break;
				}
			}
			if (IsOk == true)
			{
				accountManageMent* ac = new accountManageMent(name, accountNumber, secretNumber, value);
				Info.push_back(ac);

				ofstream writeOut("account.txt", ios::trunc);
				for (int i = 0; i < Info.size(); i++)
				{
					writeOut << Info[i]->getName() << endl;
					writeOut << Info[i]->getAccountNumber() << endl;
					writeOut << Info[i]->getAccountSecretNumber() << endl;
					writeOut << Info[i]->getMoney() << endl;
					//...
				}
			}

		}
		else if (cmd == 6)
		{
			bool IsOk = false;
			//���»���
			cout << "���¹�ȣ, ��й�ȣ�� �Է����ּ���" << endl;

			cin >> accountNumber >> secretNumber;

			int cnt = 0;
			for (auto& now : Info)
			{
				if (now->getAccountNumber() == accountNumber && now->getAccountSecretNumber() == secretNumber)
				{
					Info.erase(Info.begin() + cnt);
					IsOk = true;
					break;
				}
				cnt++;
			}
			
			if (IsOk == false)
			{
				cout << "��û�Ͻ� ���¹�ȣ�� �������� �ʽ��ϴ�" << endl;
				continue;
			}
			//���� �� ���ŵ� ������ ������ �ٽ� out_filename���� �����. 
			ofstream writeOut("account.txt", ios::trunc);

			for (int i = 0; i < Info.size(); i++)
			{
				writeOut << Info[i]->getName() << endl;
				writeOut << Info[i]->getAccountNumber() << endl;
				writeOut << Info[i]->getAccountSecretNumber() << endl;
				writeOut << Info[i]->getMoney() << endl;
			}
		}
		else if (cmd == 7)
			break;
	}

	return 0;
}

/*
* ����Ŭ����(ifstream, ofstream..) ��Ʈ����ü��(���ϸ�, ������(in, out))
* 
* ����Ŭ����  ��Ʈ����ü��;
* ��Ʈ����ü��.open(���ϸ�, ������)
* ��Ʈ����ü��.close()
* 
*/

/*
* ifstream infile("in.dat", ��������);
* or 
* ifstream infile("in.dat", ios::in);
* 
* 
* ====================
* 
* ofstream outfile("out.dat", ios::out);
* 
*/

/*
* std::ios::app  -> append , �̾��.
* std::ios::trunc  -> overwrite , �����, ���������� ������
* 
* 
*/
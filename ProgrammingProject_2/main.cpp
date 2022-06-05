#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <fstream>

#include <conio.h> // Windows.. -> _getch(), _getche() -> _getche()는 e는 echo 메마리이다 buffer가 없는 상태로 동작한다..
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
		cout << "=================메뉴===================" << endl;
		cout << "1. 계좌정보 가져오기" << endl;
		cout << "2. 입금 " << endl;
		cout << "3. 출금" << endl;
		cout << "4. 조회" << endl;
		cout << "5. 계좌추가 " << endl; //계좌추가 삭제는 계좌클래스에서 하는 것이아니다..
		cout << "6. 계좌삭제 " << endl;
		cout << "7. 종료 " << endl;

		cin >> cmd;
		rewind(stdin);
		if (cmd == 1)
		{
			//1.	‘계좌정보 가져오기’시 프로젝트 폴더 내 
			//account.txt 파일의 정보를 읽어서 화면에 출력kcj
			cout << "계좌주 계좌번호 계좌비밀번호 잔고" << endl;

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
			cout << "계좌번호 계좌비밀번호 입금 금액입력해주세요" << endl;
			//입금
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
					cout << "비밀번호가  틀렸습니다 다시 확인해주세요" << endl;
					break;
				}
				else if (Info[i]->getAccountNumber() != accountNumber)
				{
					cout << "등록되지 않은 계좌번호입니다" << endl;
					break;
				}
			}
		}
		else if (cmd == 3)
		{
			//출금
			cout << "계좌번호 비밀번호 원하는 금액 순으로 입력해주세요" << endl;

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
					cout << "비밀번호가 일치하지않습니다" << endl;
				}
			}
		}
		else if (cmd == 4)
		{
			//조회
			bool IsOk = false;
			cout << "이름 계좌번호 순으로 입력하세요" << endl;
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
				cout << "조회할 수 없습니다 " << endl;
				system("cls");
			}
		}
		else if (cmd == 5)
		{
			bool IsOk = true;
			//계좌 추가
			//예금주, 계좌번호, 비밀번호, 입금액을 입력 받아 해당 계좌에 대한 정보 추가
			cout << "이름, 계좌번호, 비밀번호, 입금할 금액순으로 입력해주세요" << endl;
			cin >> name >> accountNumber >> secretNumber >> value;

			for (int i = 0; i < Info.size(); i++)
			{
				if (Info[i]->getAccountNumber() == accountNumber)
				{
					cout << "이미 존재하는 계좌번호입니다" << endl;
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
			//계좌삭제
			cout << "계좌번호, 비밀번호를 입력해주세요" << endl;

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
				cout << "요청하신 계좌번호가 존재하지 않습니다" << endl;
				continue;
			}
			//삭제 후 갱신된 벡터의 내용을 다시 out_filename으로 덮어쓰기. 
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
* 파일클래스(ifstream, ofstream..) 스트림객체명(파일명, 개방모드(in, out))
* 
* 파일클래스  스트림객체명;
* 스트림객체명.open(파일명, 개방모드)
* 스트림객체명.close()
* 
*/

/*
* ifstream infile("in.dat", 생략가능);
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
* std::ios::app  -> append , 이어쓰기.
* std::ios::trunc  -> overwrite , 덮어쓰기, 기존파일이 있으면
* 
* 
*/
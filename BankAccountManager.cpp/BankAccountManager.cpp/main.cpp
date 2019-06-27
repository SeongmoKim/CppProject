#include <iostream>
#include <cstring>
using namespace std;

#define CUS_NUM 100
#define NAME_LEN 30
typedef struct _customerInfo
{
	char name[NAME_LEN];
	int accountId;
	int balance;
}customerInfo;

enum { OPEN = 1, DEPOSIT, WITHDRAW, PRINT, EXIT };

customerInfo cusList[CUS_NUM];
int cusOfNum = 0;

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

}
void OpenAccount(void)
{
	if (cusOfNum == CUS_NUM)
	{
		cout << "더 이상 새로운 계좌를 개설할 수 없습니다." << endl;
		return;
	}
	int accountId;
	char name[NAME_LEN];
	int money;
	

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountId;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;

	cusList[cusOfNum].accountId = accountId;
	cusList[cusOfNum].balance = money;
	strcpy(cusList[cusOfNum].name, name);

	cusOfNum++;

}
void Deposit(void)
{
	int accountId;
	int money;
	int i;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> accountId;
	cout << "입금액: ";
	cin >> money;

	for (i = 0; i < cusOfNum; i++)
	{
		if (cusList[i].accountId == accountId)
		{
			cusList[i].balance += money;
			cout << "입금완료" << endl;
			return;
		}

	}
	cout << "계좌가 존재하지 않습니다." << endl << endl;
	
}
void Withdraw(void)
{
	int accountId;
	int money;
	int i;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> accountId;
	cout << "출금액: ";
	cin >> money;

	for (i = 0; i < cusOfNum; i++)
	{
		if (cusList[i].accountId == accountId)
		{
			if (cusList[i].balance >= money)
			{
				cusList[i].balance -= money;
				cout << "출금완료" << endl << endl;
				return;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl << endl;
				return;
			}

		}

	}
	cout << "계좌가 존재하지 않습니다." << endl << endl;

}
void ShowAllCusInfo(void)
{
	int i;
	for (i = 0; i < cusOfNum; i++)
	{
		cout << "No. " << i + 1 << endl;
		cout << "┏━━━━━━━━━━━━━━━━━━━" << endl;
		cout << "┃계좌ID: " << cusList[i].accountId << endl;
		cout << "┃이 름: " << cusList[i].name << endl;
		cout << "┃잔 액: " << cusList[i].balance << endl;
		cout << "┗━━━━━━━━━━━━━━━━━━━" << endl << endl;
	}
	
}
int main(void)
{
	int nInput;
	
	while (1)
	{
		ShowMenu();

		cout << "선택: ";
		cin >> nInput;
		cout << endl;

		if (nInput == EXIT)
			break;
		
		switch (nInput)
		{
		case OPEN:
			OpenAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case PRINT:
			ShowAllCusInfo();
			break;
			
		}
		cout << endl;
	}
	
	cout << "프로그램을 종료합니다." << endl << endl;
	return 0;
}

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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

}
void OpenAccount(void)
{
	if (cusOfNum == CUS_NUM)
	{
		cout << "�� �̻� ���ο� ���¸� ������ �� �����ϴ�." << endl;
		return;
	}
	int accountId;
	char name[NAME_LEN];
	int money;
	

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accountId;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
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

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> accountId;
	cout << "�Աݾ�: ";
	cin >> money;

	for (i = 0; i < cusOfNum; i++)
	{
		if (cusList[i].accountId == accountId)
		{
			cusList[i].balance += money;
			cout << "�ԱݿϷ�" << endl;
			return;
		}

	}
	cout << "���°� �������� �ʽ��ϴ�." << endl << endl;
	
}
void Withdraw(void)
{
	int accountId;
	int money;
	int i;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> accountId;
	cout << "��ݾ�: ";
	cin >> money;

	for (i = 0; i < cusOfNum; i++)
	{
		if (cusList[i].accountId == accountId)
		{
			if (cusList[i].balance >= money)
			{
				cusList[i].balance -= money;
				cout << "��ݿϷ�" << endl << endl;
				return;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl << endl;
				return;
			}

		}

	}
	cout << "���°� �������� �ʽ��ϴ�." << endl << endl;

}
void ShowAllCusInfo(void)
{
	int i;
	for (i = 0; i < cusOfNum; i++)
	{
		cout << "No. " << i + 1 << endl;
		cout << "����������������������������������������" << endl;
		cout << "������ID: " << cusList[i].accountId << endl;
		cout << "���� ��: " << cusList[i].name << endl;
		cout << "���� ��: " << cusList[i].balance << endl;
		cout << "����������������������������������������" << endl << endl;
	}
	
}
int main(void)
{
	int nInput;
	
	while (1)
	{
		ShowMenu();

		cout << "����: ";
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
	
	cout << "���α׷��� �����մϴ�." << endl << endl;
	return 0;
}

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <fstream>
#include <string>
using namespace std;

#define DLL_NAME "csgocheat.dll"


void steamverify(string login, string senha, int i);
void iniciar(int a);
int somar(int a);

DWORD Process(char* ProcessName)
{

	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);
	do
	{

		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			DWORD dwPID = ProcEntry.th32ProcessID;

			CloseHandle(hPID);

			return dwPID;
		}

	} while (Process32Next(hPID, &ProcEntry));

}

void verificar(string login, string senha, int a)
{
	
	DWORD dwProcess;
	dwProcess = Process("csgo.exe");
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	if (hProcess)
	{
		cout << "Rodando, fechando em 50 minutos" << endl;
		CloseHandle(hProcess);
		Sleep(3000000);
		system("taskkill /F /T /IM csgo.exe");
		Sleep(5000);
		system("cls");
		verificar(login, senha, a);
	}
	else
	{
		cout << "Conta finalizada. Reiniciando processo..." << endl;
		system("taskkill /F /T /IM Steam.exe");
		CloseHandle(hProcess);
		Sleep(5000);
		system("cls");
		somar(a);
	}
}

void csgohandle(string login, string senha, int a)
{

	DWORD dwProcess;
	dwProcess = Process("csgo.exe");
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	if (hProcess)
	{
		char myDLL[MAX_PATH];
		GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
		LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
		CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
		CloseHandle(hProcess);
		//ShellExecute(NULL, "open", "LotusInjector.exe", NULL, NULL, SW_SHOWDEFAULT);
		cout << "Detectado! Injetando DLL" << endl;
		Sleep(5000);

		int x = 41;
		int y = 122;
		SetCursorPos(x, y);
		Sleep(50);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
		Sleep(250);
		x = 358;
		y = 162;
		SetCursorPos(x, y);
		Sleep(250);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
		Sleep(150);
		x = 684;
		y = 441;
		SetCursorPos(x, y);
		Sleep(250);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
		Sleep(250);
		x = 1335;
		y = 863;
		SetCursorPos(x, y);
		Sleep(50);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
		Sleep(50);
		verificar(login, senha, a);
	}
	else
	{
		char* linkChar = "steam://rungameid/730";
		ShellExecute(NULL, "open", linkChar, NULL, NULL, SW_SHOWNORMAL);
		cout << "Iniciando CSGO" << endl;
		Sleep(50000);
		CloseHandle(hProcess);
		csgohandle(login, senha, a);
	}
	system("pause");
}

void steamverify(string login, string senha, int a)
{
	
	DWORD dwProcess;
	dwProcess = Process("Steam.exe");
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	if (hProcess)
	{
		cout << "Steam Aberta, iniciando processo..." << endl;
		csgohandle(login, senha, a);
	}
	else
	{
		const char *loginchar = login.c_str();
		const char *senhachar = senha.c_str();
		char mews[519];
		sprintf_s(mews, "-Login %s %s", loginchar, senhachar);
		cout << "Abrindo Steam e logando na conta..." << endl;
		ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Steam\\Steam.exe", mews, NULL, SW_SHOWDEFAULT);
		Sleep(20000);
		steamverify(login, senha, a);
	}
	CloseHandle(hProcess);
}

int somar(int a)
{
	iniciar(a + 1);
	return a;
}

void iniciar(int a)
{
	int z;
	z = a;
	string login;
	string senha;
	
	ifstream inFile("accounts.txt");

	if (inFile.is_open())
	{
		for (z; z > 0; --z)
		{
			inFile.ignore(256, '\n');
		}
		for (int i = 0; i < 1; ++i)
		{
			inFile >> login >> senha;
			cout << login << " " << senha << endl;
			cout << a << endl;
		}
	}

	steamverify(login, senha, a);
}


int main(int z, int a)
{
	a = 0;
	z = 0;
	iniciar(a);
	return z, a;
}
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string ids[4];
string passes[4];

string userInputID;
string userInputPass;

int idTarama(string dizi[], int buyukluk, string aranacakId){
	
	for(int i = 0; i < buyukluk; i++) {
		
		if (aranacakId == dizi[i]) 
		{
			return i;
			
		}
		
	}
	
	return -1;
}

int passTarama(string dizi[], int buyukluk, string aranacakPass){
	
	for(int i = 0; i < buyukluk; i++) {
		
		if (aranacakPass == dizi[i]) 
		{
			return i;
			
		}
		
	}
	
	return -1;
}

int main() {
	
// Username
ifstream idler;
idler.open("usernames.txt");

for(int i = 0; i < 4; ++i) {
	
	idler >> ids[i];
}

// Pass
ifstream passlar;
passlar.open("passwords.txt");

for(int i = 0; i < 4; ++i) {
	
	passlar >> passes[i];
}
	bas:
	system("cls");
	cout << "Please enter your username : ";
	cin >> userInputID; 
	
	int sonuc = idTarama(ids, 4, userInputID);
	
	if(sonuc >= 0) {
		
		cout << "The username " << ids[sonuc] << " has been found !" << endl;
		_sleep(1000);
		
		system("cls");
		
		cout << "Please enter your password : ";
		cin >> userInputPass;
		
		int sonucPass = passTarama(passes, 4, userInputPass);
		
			if(sonucPass >= 0) {
			cout << "Password is correct !";
			_sleep(1000);
			system("cls");
			}
		
			else{
			cout << "Password is incorrect !";
			_sleep(1000);
			
			goto bas;
			}
	}
	else{
		cout << "The username " << userInputID << " cannot be found !" << endl;
		_sleep(1000);
		
		goto bas;
	}
		
		

}

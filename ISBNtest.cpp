#include <iostream>
#include <string>

void error_message(){
	std::cout << "ISBN not entered correctly\n";
}



int main(){

	std::string ISBN;
	getline(cin, ISBN);

	return 0;
}
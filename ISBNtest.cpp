#include <iostream>
#include <string>

void error_message(){
	std::cout << "ISBN not entered correctly\n";
}
bool check_ISBN_has_only_int(std::string ISBN){
	int i = 0;
	while (i < 13){
		if (ISBN[i] < 48 || ISBN[i] > 57){
			return false;
		}
		i++;
	}
	return true;
}



int main(){

	std::string ISBN;
	getline(std::cin, ISBN);

	if (ISBN.length() != 13){
		error_message();
	}
	else {
		//std::cout << "here 1\n";
		if (check_ISBN_has_only_int(ISBN)){

		}
		else {
			error_message();
		}

	}

	return 0;
}
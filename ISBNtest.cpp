#include <iostream>
#include <string>

void error_message(){
	std::cout << "ISBN not entered correctly\n";
}
bool check_ISBN_has_only_int(std::string ISBN){
	int i = 0;
	while (i < 13){
		if (ISBN[i] < '0' || ISBN[i] > '9'){
			return false;
		}
		i++;
	}
	return true;
}
bool check_ISBN_is_valid(std::string ISBN){
	int sum = 0, i = 0;
	while (i < 12){
		sum += (((int)ISBN[i++] - '0') * 1);
		sum += (((int)ISBN[i++] - '0') * 3);
	}
	if (((sum%10) == 0) && (((int)ISBN[i] - '0') == 0)){
	 	return true;
	}
	else if ((10 -(sum%10)) ==  ((int)ISBN[i] - '0')) {
		return true;
	}
	else {
		return false;
	}

}

int main(){
    
    std::cout << "enter ISBN: ";
	std::string ISBN;
	getline(std::cin, ISBN);

	if (ISBN.length() != 13){
		error_message();
	}
	else {
		if (!check_ISBN_has_only_int(ISBN)){
			error_message();
		}
		else {
			if (!check_ISBN_is_valid(ISBN)) {
				error_message();
			}
			else std::cout << ISBN << " is a valid ISBN\n";
		}

	}

	return 0;
}
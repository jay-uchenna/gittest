#include <iostream>
#include <string>

void Error_Message(){
	std::cout << "ISBN not entered correctly\n";
}
bool Check_ISBN_has_only_int(std::string ISBN){
    for(int i = 0; i < 13; i++){
		if (ISBN[i] < '0' || ISBN[i] > '9'){
			return false;
		}
	}
	return true;
}
bool Check_ISBN_is_valid(std::string ISBN){
	int sum = 0, i = 0;
	for ( ; i < 12; ){
		sum += (((int)ISBN[i++] - '0') * 1);
		sum += (((int)ISBN[i++] - '0') * 3);
	}
	if ((((sum%10) == 0) && (((int)ISBN[i] - '0') == 0))||
			((10 -(sum%10)) ==  ((int)ISBN[i] - '0'))){
	 	return true;
	}
	return false;
}

int main(){
    
    std::cout << "enter ISBN: ";
	std::string ISBN;
	getline(std::cin, ISBN);

	if ((ISBN.length() != 13)||
		(!Check_ISBN_has_only_int(ISBN))||
			(!Check_ISBN_is_valid(ISBN))){
		Error_Message();
	}
	else {
		std::cout << ISBN << " is a valid ISBN\n";
	}
	return 0;
}
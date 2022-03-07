#pragma once
using namespace std;
class FileUnableToOpen {
	char message[25];
public:
	FileUnableToOpen(const char msg[]) {
		strcpy_s(message, msg);
	}
	char* what() {
		return message;
	}
};

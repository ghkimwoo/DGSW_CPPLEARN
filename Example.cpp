#include <iostream>
using namespace std;

class CDeviceInterface {
public:
	CDeviceInterface() {
		cout << "CDeviceInterface()" << endl;
	}
	virtual int GetDeviceID() = 0;
protected:
	int deviceID;
};
class CDisplay : public CDeviceInterface {
public:
	CDisplay() {
		cout << "CDisplay()" << endl;
		deviceID = 2;
	}
	int GetId() const {
		cout << "CDisplay GetID()" << endl;
		return deviceID;
	}
};

class CAudio : public CDeviceInterface {
public:
	CAudio() {
		cout << "CAudio()" << endl;
		deviceID = 1;
	}
	int GetId() const {
		cout << "CAudio GetID()" << endl;
		return deviceID;
	}
};

void disabled_main(){
}
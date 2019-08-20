
using namespace std;

class Device {

private:
    string name;
    unsigned int id = 0;
    bool state = false;
    unsigned int pin = 0;
    unsigned int virtualPin = 0;

public:
    static unsigned int id_counter;

    Device(string name, int pin, int virtualPin);

    ~Device();

    int getId();

    string getName();

    bool isTurnedOn();

    unsigned int getPin();

    unsigned int getVirtualPin();
};

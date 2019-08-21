
using namespace std;

class Device {

private:
    string name;
    unsigned int id = 0;
    bool turnedOn;
    unsigned int pin = 0;
    unsigned int virtualPin = 0;

public:
    static unsigned int id_counter;

    Device(string name, int pin, int virtualPin);

    ~Device();

    virtual void init();

    virtual void execute();

    int getId();

    string getName();

    virtual bool isTurnedOn();

    unsigned int getPin();

    unsigned int getVirtualPin();


};

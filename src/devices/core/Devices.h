#ifndef DEVICES_H
#define DEVICES_H

#include <array>
#include <tuple>
#include <vector>
#include <string>
#include <bits/unique_ptr.h>

using namespace std;

class Device;

class IrDevice;

class ExtBtnDevice;

class LightsDevice;

class Devices {
private:
    static vector<unique_ptr<Device>> devicesVect;
    static vector<unique_ptr<LightsDevice>> lightsVect;
    static vector<unique_ptr<IrDevice>> IrVect;
    static vector<unique_ptr<ExtBtnDevice>> extBtnVect;

public:

    static Device &findById(int id);

    static Device &findByName(const string &name);

    template<class T>
    static void addDevice(const unique_ptr<T> &device);

    static void removeDevice(unique_ptr<Device> &device);

    static int getSize();

    static void initAll();

    static void execAll();

    static vector<unique_ptr<Device>> getAllDevices();

    static vector<unique_ptr<LightsDevice>> getLights();

    static vector<unique_ptr<IrDevice>> getIR();

    static vector<unique_ptr<ExtBtnDevice>> getExtBtns();
};

#endif //DEVICES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

int num1;
int num2;

void get_id_value_map(std::unordered_map<std::string, std::string> &configData) {
    // Open config file and check, if it coul be opened
    ifstream configFileStream("1.txt");
    if (configFileStream)
    {
        std::string line{};
        while (std::getline(configFileStream, line)) {
            cout << line << endl;
            if (line.find(':') != std::string::npos) {
                std::istringstream iss{ line };
                std::string id, value;
                if (std::getline(std::getline(iss, id, ':') >> std::ws, value))
                    configData[id] = value;
            }
        }
        cout << "mymap contains:";
        for (auto it = configData.begin(); it != configData.end(); ++it)
            cout << " " << it->first << " " << it->second << endl;
    }
    else cout << "error!!!!!!!!" << endl;
    return;
}

void config_value(std::unordered_map<std::string, std::string>& configData) {
    for (auto it = configData.begin(); it != configData.end(); ++it) {
        if (it->first == "num1") num1 = stoi(it->second);
        else if (it->first == "num2") num2 = stoi(it->second);
    }
}

//test
int main() {
    std::unordered_map<std::string, std::string> configData;
    get_id_value_map(configData);
    config_value(configData);
    cout << "num1 num2:  " << num1 << "  " << num2 << endl;
    return 0;
}

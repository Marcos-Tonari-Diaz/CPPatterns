#include <unistd.h>

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

// Singleton Pattern
class SingletonLog {
  static SingletonLog* singleton_log;
  ofstream log_file;

  string getDateTime() {
    std::time_t current_time =
        chrono::system_clock::to_time_t(chrono::system_clock::now());
    string result(ctime(&current_time));
    result.pop_back();
    return result;
  }

  string logFormat(string log_string) {
    string result = "[" + getDateTime() + "] " + log_string;
    return result;
  }

  SingletonLog(string filename) {
    log_file.open(filename);
    log_file << logFormat("LOG START") << endl;
  }

  ~SingletonLog(){
    log_file.close();
  }

 public:
  static SingletonLog* getLog() {
    if (singleton_log == nullptr) singleton_log = new SingletonLog("ex.log");
    return singleton_log;
  }
  void logString(string log_string) {
    log_file << logFormat(log_string) << endl;
  }
};

SingletonLog* SingletonLog::singleton_log = nullptr;

int main() {
  SingletonLog::getLog()->logString("work1");
  usleep(1000000);
  SingletonLog::getLog()->logString("work2");
  return 0;
}
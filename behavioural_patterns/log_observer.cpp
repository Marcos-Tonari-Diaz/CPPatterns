// Observer Pattern
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class LoggerSubscriber {
    public:
    virtual void update(string message) = 0;
};


class LoggerPublisher {
    vector<LoggerSubscriber*> subscribers;

    public:
        void subscribe(LoggerSubscriber* subscriber){
            subscribers.push_back(subscriber);
        };
        void unsubscribe(LoggerSubscriber* subscriber){
            subscribers.erase(find(subscribers.begin(), subscribers.end(), subscriber));
        };
        void notifyAllSubscribers(string message){
            for (auto subscriber: this->subscribers)
                subscriber->update(message);
        };
};


class FileLogger: public LoggerSubscriber {
    ofstream log_file;
    public:
    FileLogger(string filename) {
        log_file.open(filename);
        log_file << "START FILE LOGGING" << endl;
    }
    void update(string message){
        log_file << message << endl;
    }
    ~FileLogger(){
        log_file.close();
    }

};

class PrintLogger: public LoggerSubscriber{
    public:
    PrintLogger() {
        cout << "START LOGGING" << endl;
    }
    void update(string message){
        cout << message << endl;
    }
    ~PrintLogger(){
        cout << "END LOGGING" << endl;
    }
};

int main(){
    LoggerPublisher publisher;
    FileLogger file_logger("observer.log");
    PrintLogger print_logger;
    publisher.subscribe(&file_logger);
    publisher.subscribe(&print_logger);
    publisher.notifyAllSubscribers("first!");
    publisher.unsubscribe(&print_logger);
    publisher.notifyAllSubscribers("second!");
    return 0;
}
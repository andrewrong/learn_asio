#include <iostream>
//#include "max.h"
#include <asio.hpp>

using namespace std;

asio::io_service service;
asio::io_service::strand strand_one(service), strand_two(service);
asio::io_service::work work(service);

int ct = 0;

void func(int i) {
        std::shared_ptr<asio::steady_timer> timer = std::make_shared<asio::steady_timer>(service);
        timer->expires_after(std::chrono::seconds(20 - i ));
        timer->async_wait([timer, i](const std::error_code& code) {
            cout << "code:" << code.message() << ";timer out:" << i << endl;

        });

    stringstream  ss;
    ss << "func called, i = " << i << "-" << this_thread::get_id() << endl;
    cerr << ss.str() << endl;

//    if (i % 2 == 0) {
//        strand_one.dispatch([i](){
//            stringstream  ss;
//            ss << "again = " << i << "-" << this_thread::get_id() << endl;
//            cerr << ss.str() << endl;
//        });
//    }
//    buffer[i] = ss.str();
}

void worker_thread() {
    service.run();
    cout << "i am quit" << endl;
}

int main() {
    for (int i = 0; i < 10; i++) {
        strand_one.dispatch([i](){
            func(i);
        });
    }
    for (int i = 10; i < 20; i++) {
        strand_one.dispatch([i]{
            func(i);
        });
//        service.dispatch(strand_two.wrap([i](){func(i);}));
    }

    vector<thread> threadGroup;
    for (int i = 0; i < 3; i++) {
        threadGroup.push_back(thread([](){
            worker_thread();
        }));
    }

//    for (const auto &item : buffer) {
//        cout << item << endl;
//    }
//    this_thread::sleep_for(std::chrono::seconds(10));
//    for (int i = 20; i < 25; i++) {
//        strand_one.dispatch([i](){
//            func(i);
//        });
////        service.dispatch(strand_one.wrap());
//    }

//    this_thread::sleep_for(std::chrono::seconds(30));
    for (auto &item : threadGroup) {
        if(item.joinable()) {
            item.join();
        }
    }
}
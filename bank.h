//
// Created by National Cyber City on 11/4/2022.
//
#include "iostream"
using namespace std;
#ifndef NCCBANKPROJECT3_BANK_H
#define NCCBANKPROJECT3_BANK_H

namespace N {
    class bank {
    public:
        // loading declaration
        int usernameIndex=0;
        int pwIndex=0;
        int amountIndex=0;
        string admin[5]={"admin1@gmail.com" , "admin2@gmail.com" , "admin3@gmail.com"};
        string adminpw[5]={"admin" , "admin" , "admin"};

        string _arrUsername[100];
        string _arrPassword[100];
        string _amount[100];
        //attributes declaration
        string l_username;
        string l_password;
        string r_username;
        string r_password;
        // method declaration
        void welcome();
        void mainMenu();
        int Register();
        int login();
        int _nameloading();
        int userNameExit(string username);
        int exchange();
        void showAllData();
        int _mainLoading();
        int _recording();
        int adminchecking(string adname , string adpw);
        int adminOptionfun();
        int sepcificInformation();

    private:


    };
}

#endif //NCCBANKPROJECT3_BANK_H

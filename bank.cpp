//
// Created by National Cyber City on 11/4/2022.
//
#include "iostream"
#include "bank.h"
#include "fstream"
using namespace N;
using namespace std;

void bank::welcome(){
    cout<<"Welcome to NCC Bank"<<endl;
    _nameloading();
    showAllData();
    mainMenu();



}

void bank::mainMenu(){
    string mainOption;
    cout<<"Press 1 to Register:"<<endl;
    cout<<"Press 2 to Login:"<<endl;
    cout<<"Press 3 to Quit:"<<endl;
    cin>>mainOption;
    if(mainOption == "1"){
       Register();
    }else if(mainOption=="2"){
        login();
    } else if(mainOption =="3"){
        cout<<"Good Luck!"<<endl;
        cout<<"Recording............"<<endl;
        _recording();
        exit(1);
    } else{
        cout<<"Invalid Option"<<endl;
        mainMenu();
    }
}

int bank::Register() {
    string conPass;
    string amount;
    cout<<"This is Register:"<<endl;
    cout<<"Enter your username to Register:";
    cin>>r_username;
    int result = userNameExit(r_username);

        while(result == -1) {
            cout << "Valid Username: Enter password:";
            cin >> r_password;
            cout << "Confirm your password:";
            cin >> conPass;
            while (true) {
                if (r_password == conPass) {
                    // registration
                    cout << "Registration Success" << endl;
                    cout<<"Enter your amount:"<<endl;
                    cin>>amount;
                    _arrUsername[usernameIndex] = r_username;
                    _arrPassword[pwIndex]=r_password;
                    _amount[amountIndex] = amount;
                    usernameIndex++;
                    pwIndex++;
                    amountIndex++;
                    mainMenu();
                } else {
                    cout << "Your password is not match:" << endl;
                    break;
                }
            }
        }
            cout << "Username Already Exist" << endl;
            Register();

}

int bank::login() {
    int adResult=0;
    cout<<"This is Login:"<<endl;
    cout<<"Enter username:"<<endl;
    cin>>l_username;

    if(l_username == "admin1@gmail.com"){
        string adpass;
        cout<<"Enter Password for admin:";
        cin>>adpass;
        adResult = adminchecking(l_username , adpass);
        if(adResult == -1){
            login();
        }
    } else{

        int result = userNameExit(l_username);

        if(result!=-1){
            cout<< l_username <<"is valid Enter password:";
            cin>>l_password;
            if(l_password == _arrPassword[result]){
                cout<<"Login Success:"<<endl;
                cout<<"Welcome :"<<l_username<<endl;
                exchange();

            } else{
                cout<<"Wrong Password"<<endl;
                login();
            }

        } else{
            cout<<"Invalid Username:"<<endl;
            login();
        }

    }



}

int bank::userNameExit(string username){
    for(int i=0 ; i<usernameIndex ;i++){
        if(_arrUsername[i] == username){
            return i;
        }
    }
    return -1;

}

int bank::_nameloading() {
    // username.txt   password.txt
    cout<<"Loading Processing is Running..\n.\n.\n."<<endl;
    string username="username.txt";
    string password="password.txt";
//    ofstream usernamefile;
//    ofstream passwordfile;
//    usernamefile.open(username,ios::app);
//    passwordfile.open(password,ios::app);

    string data;
    string dataPassword;
    ifstream userfile(username);
    if(userfile.is_open()){
        while (getline(userfile,data)){
            _arrUsername[usernameIndex] = data;
            usernameIndex++;
        }
        userfile.close();
    } else{
        cout<<"Unable to open file:"<<endl;
    }
    ifstream psfile(password);
    if(psfile.is_open()){
        while (getline(psfile,dataPassword)){
            _arrPassword[pwIndex] = dataPassword;
            pwIndex++;
        }
        psfile.close();
    } else{
        cout<<"Unable to open file:"<<endl;
    }

}

int bank::_mainLoading(){
    int count=0;
    string data;
    cout<<"Main Loading Processing is Running..\n.\n.\n."<<endl;
    string dataFile="bankdatafile.txt";
    string dataLine; // to store all data from file and get one line;
    ifstream data_file(dataFile);
    if(data_file.is_open()){
        while (getline(data_file,dataLine)){
            dataLine=dataLine+" ";

            for(auto &ch :dataLine){
                if(ch==' '){
                    if(count==0){
                        _arrUsername[usernameIndex]=data;
                        usernameIndex++;
                        cout<<"We found one space"<<endl;
                        data="";
                        count++;
                    } else if(count==1){
                        _arrPassword[pwIndex]=data;
                        pwIndex++;
                        cout<<"We found two times space:"<<endl;
                        data="";
                        count++;
                    } else if(count==2){
                        _amount[amountIndex] = data;
                        amountIndex++;
                        cout<<"We found three time space:"<<endl;
                        data="";
                        count=0;
                    }

                } else{
                    string st(1,ch);
                    data = data+st;
                }

            }//for ending

        }//while ending
    } else{
        cout<<"Unable to open file"<<endl;
    }



showAllData();
}


int bank::exchange() {
    string status;
    cout<<"This is Exchange page"<<endl;
    cout<<"Press 1 to Exit:\nPress 2 To Transfer Money:\nPress 3 to Withdraw:"<<endl;
    cin>>status;
    if(status=="1"){
        cout<<"Recording..........";
        _recording();
        exit(1);
    } else if(status == "2"){

        cout<<"This is Transfer money page"<<endl;
    } else if(status == "3"){

        cout<<"This is Withdraw page"<<endl;
    }


}

void bank::showAllData(){
    for(int i=0 ; i<usernameIndex ; i++){
        cout<<"Username:"<<_arrUsername[i]<<": Password:"<<_arrPassword[i]<<"amount"<<_amount[i]<<endl;
    }

}

int bank::_recording() {
    string filename ="bankdatafile.txt";
    ofstream recordFile;

    recordFile.open(filename);

    if(!recordFile.is_open()){
        cout<<"Unable to record!"<<endl;
    } else{
        for(int i=0 ; i<usernameIndex ; i++){
            string data=_arrUsername[i]+" "+_arrPassword[i]+" "+_amount[i]+"\n";
            //cout<<"Username:"<<_arrUsername[i]<<": Password:"<<_arrPassword[i]<<"amount"<<_amount[i]<<endl;
            recordFile<<data;
        }
    }

    recordFile.close();

}
int bank::adminchecking(string adname , string adpw){

    for(int i=0 ; i < 3 ; i++){
        if(admin[i] == adname && adminpw[i]==adpw){
                adminOptionfun();

        }

    }

    return -1;


}

int bank::adminOptionfun(){
    string adminOption;
    cout<<"Hello Admin.....\n"<<endl;
    cout<<"Press 1 to know all info:\nPress 2 to know Specific:\nPress 3 to Manage Users:\nPress 4 to Exit:";
    cin>>adminOption;

    if(adminOption == "1"){
        //all info
        cout<<"This is all User Information:"<<endl;
        showAllData();
        adminOptionfun();
    } else if(adminOption =="2"){
        // specific
        cout<<"This is Specific Information:"<<endl;
        sepcificInformation();
        adminOptionfun();

    } else if(adminOption=="3"){
        //manage;
        cout<<"This is manager"<<endl;
    } else if(adminOption=="4"){
        //manage;
        cout<<"bye Bye Admin"<<endl;
        exit(1);
    }else{
        cout<<"Invalid Option"<<endl;
        mainMenu();
    }


}

int bank::sepcificInformation(){
    int count=0;
    string data;
    string specUsername;
    cout<<"Enter username to know specific:";
    cin>>specUsername;

    string dataFile="recordingfile.txt";
    string dataLine; // to store all data from file and get one line;
    ifstream data_file(dataFile);
    if(data_file.is_open()){
        while (getline(data_file,dataLine)){
            dataLine=dataLine+" ";

            for(auto &ch :dataLine){

                if(ch==' '){
                    if(data ==specUsername){
                        cout<<"Data: "<<dataLine<<endl;
                        data="";
                    } else{
                        data="";
                    }

                } else{
                    string st(1,ch);
                    data = data+st;
                    //cout<<"This is data:"<<data<<endl;
                }

            }//for ending

        }//while ending
    } else{
        cout<<"Unable to open file"<<endl;
    }





}
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Record{
    private:
        string date;
        string title;
        string content;
    public:
        Record(string d, string t, string c){
            date = d;
            title = t;
            content = c;
        }
        void display(){
            cout << "Date: " << date << endl;
            cout << "Title: " << title << endl;
            cout << "Content: " << content << endl;
        }
        string get_title(){
            return title;
        }
};

class User{
    private:
        string username;
        string password;
        vector<Record> records;
    public:
        User(string u, string p){
            username = u;
            password = p;
        }
        string get_username(){
            return username;
        }
        bool check_password(string p){
            return password == p;
        }
        void add_record(string d, string t, string c){
            Record r(d, t, c);
            records.push_back(r);
        }
        void view_record(string t){
            for(int i=0;i<records.size();i++){
                if(records[i].get_title() == t){
                    records[i].display();
                    return;
                }
            }
            cout << "Record not found!" << endl;
        }
        void delete_record(string t){
            for(int i=0;i<records.size();i++){
                if(records[i].get_title() == t){
                    records.erase(records.begin() + i);
                    cout << "Record deleted!" << endl;
                    return;
                }
            }
            cout << "Record not found!" << endl;
        }
        void edit_record(string t){
            for(int i=0;i<records.size();i++){
                if(records[i].get_title() == t){
                    string d, c;
                    cout << "Enter new date: ";
                    cin >> d;
                    cout << "Enter new content: ";
                    cin >> c;
                    records[i] = Record(d, t, c);
                    cout << "Record edited!" << endl;
                    return;
                }
            }
            cout << "Record not found!" << endl;
        }
};

class Diary{
    private:
        vector<User> users;
    public:
        void add_user(string u, string p){
            User user(u, p);
            users.push_back(user);
            cout << "User added!" << endl;
        }
        User* login(string u, string p){
            for(int i=0;i<users.size();i++){
                if(users[i].get_username() == u && users[i].check_password(p)){
                    cout << "Login successful!" << endl;
                    return &users[i];
                }
            }
            cout << "Invalid username or password!" << endl;
            return NULL;
        }
};

int main(){
    Diary diary;
    int choice;
    User* user = NULL;
    string username, password, title, date, content;

    while(true){
        cout << "1. Add user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            diary.add_user(username, password);
    }
    else if(choice == 2){
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        user = diary.login(username, password);
        if(user != NULL){
            while(true){
                cout << "1. Add record" << endl;
                cout << "2. View record" << endl;
                cout << "3. Delete record" << endl;
                cout << "4. Edit record" << endl;
                cout << "5. Change password" << endl;
                cout << "6. Logout" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                if(choice == 1){
                    cout << "Enter date: ";
                    cin >> date;
                    cout << "Enter title: ";
                    cin >> title;
                    cout << "Enter content: ";
                    cin >> content;
                    user->add_record(date, title, content);
                    cout << "Record added!" << endl;
                }
                else if(choice == 2){
                    cout << "Enter title: ";
                    cin >> title;
                    user->view_record(title);
                }
                else if(choice == 3){
                    cout << "Enter title: ";
                    cin >> title;
                    user->delete_record(title);
                }
                else if(choice == 4){
                    cout << "Enter title: ";
                    cin >> title;
                    user->edit_record(title);
                }
                else if(choice == 5){
                    string new_password;
                    cout << "Enter new password: ";
                    cin >> new_password;
                    user->check_password(new_password);
                    cout << "Password changed!" << endl;
                }
                else if(choice == 6){
                    user = NULL;
                    break;
                }
                else{
                    cout << "Invalid choice!" << endl;
                }
            }
        }
    }
    else if(choice == 3){
        break;
    }
    else{
        cout << "Invalid choice!" << endl;
    }
}
return 0;

}
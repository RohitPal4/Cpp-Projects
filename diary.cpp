#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Diary {
    private:
    string password;
    string username;
    vector<string> stories;
    public:
    Diary(){}
    void set_password(string p){
        password = p;
    }

    void set_username(string u){
        username = u;
    }

    bool login_pass(string p) {    
       return password ==p;
    }
    bool login_user(string u) {
        return username == u;
    }

    void Edit_password(string new_password){
        password = new_password;
    }

    void Login_with_new_password() {
        login();
    }

    void add_story(string s) {
        stories.push_back(s);
    } 

    void view_stories() {
        if (stories.size() == 0) {
            cout << "No stories found."<<endl;
            return;
        }
        for(int i = 0; i < stories.size(); i++){
            cout << i+1 << ". "<< stories[i] << endl;
        }
    }

    void edit_story(int index, string new_story) {
        stories[index-1] = new_story;
    }

    void remove_story(int index) {
        stories.erase(stories.begin()+index-1);
    }

    void login() {
         while (true)
    {   string Input_username;
        string input_password;
        cout<< " Enter name: ";
        cin>>Input_username;
        cout<<"Enter password: ";
        cin>>input_password;
        if (login_pass(input_password) && login_user(Input_username))
        {
            cout << "Login successful." << endl;
            break;
        }
        else{
            cout << "Invalid password. Please try again. "<<endl;
        }
    }
    
     }


     void save_to_file(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < stories.size(); i++) {
            file << stories[i] << endl;
        }
        file.close();
        cout << "Stories saved to file." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void load_from_file(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stories.push_back(line);
        }
        file.close();
        cout << "Stories loaded from file." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}


    void management() {
    while(true) {
        int choice;
        cout << "\nwhat would you like to do ?. " << endl;
        cout << "Press 1. to Edit password" << endl;
        cout << "Press 2. to Add a new story" << endl;
        cout << "Press 3. to View stories" << endl;
        cout << "Press 4. to Edit story" << endl;
        cout << "Press 5. to Remove a story" << endl;
        cout << "Press 6. to login with new password" << endl;
        cout << "Press 7. to Save stories to file" << endl;
        cout << "Press 8. to Load stories from file" << endl;
        cout << "Press 9. to Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string new_password;
            cout << "Enter your new password: ";
            cin >> new_password;
            Edit_password(new_password);
        }
        else if (choice == 2) {
            string new_story;
            cout << "Enter your new story: ";
            cin.ignore();
            getline(cin, new_story);
            add_story(new_story);
        }
        else if (choice == 3) {
            view_stories();
        }
        else if (choice == 4) {
            int index;
            string new_story;
            cout << "Enter the index of the story you want to edit: ";
            cin >> index;
            cout << "Enter the new story: ";
            cin.ignore();
            getline(cin, new_story);
            edit_story(index, new_story);
        } 
        else if (choice == 5) {
            int index;
            cout << "Enter the index of the story you want to remove: ";
            cin >> index;
            remove_story(index);
        }
        else if (choice == 6) {
            Login_with_new_password();
        } 
        else if (choice == 7) {
            string filename;
            cout << "Enter the filename to save stories: ";
            cin >> filename;
            save_to_file(filename);
        }
        else if (choice == 8) {
            string filename;
            cout << "Enter the filename to load stories: ";
            cin >> filename;
            load_from_file(filename);
        }
        else if (choice == 9) {
            cout << "Goodbye! " << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
};

int main() {
    Diary diary;
    string username;
    string password;
    cout << "\n************************************\n"
              << "*   Welcome to my personal diary   *\n"
              << "************************************\n";
    cout << "\nCreate a username for your diary: ";
    cin>>username;
    cout << "Create a password for your diary: ";
    cin>>password;
    diary.set_username(username);
    diary.set_password(password);
    cout << "\n**********************************\n"
              << "*   Please login to your diary   *\n"
              << "**********************************\n";
    diary.login();
    diary.management();
   
return 0;
}
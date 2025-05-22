#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Template{
protected:
    vector<T> vid;
    vector<string> vname;
public:
    Template(){
        cout<<"----- Initializing Student ID and Name!! -----"<<endl;
        int n;
        cout<<"Enter the number of students: ";
        cin>>n;
        vid.resize(n);
        vname.resize(n);
        for(int i=0; i<vid.size(); i++){
            cout<<"Enter the ID of student "<<i+1<<": ";
            cin>>vid[i];
            cout<<"Enter the name of student "<<i+1<<": ";
            cin>>vname[i];
        }
        cout<<"----- Initializing Student ID and Name Are Finished!! -----"<<endl;
    }
};
class Task: public Template<int>{
public:
    void AddStudent(){
        int id;
        string name;
        cout<<"Enter the ID of the new student: ";
        cin>>id;
        cout<<"Enter the name of the new student: ";
        cin>>name;
        vid.push_back(id);
        vname.push_back(name);
        cout<<"Student Added Successfully!"<<endl;
        cout<<"----- Add Student Finished -----"<<endl;
    }
    void display(){
        cout<<"\n----- Student ID and Name -----"<<endl;
        for(int i=0; i<vid.size(); i++){
            cout<<"ID: "<<vid[i]<<" Name: "<<vname[i]<<endl;
        }
        cout<<"----- Display Finished -----"<<endl;
        cout<<endl;
    }
    void searchStudent(int id){
        bool found = false;
        for(int i=0; i<vid.size(); i++){
            if(vid[i] == id){
                cout<<"Student found with ID: "<<vid[i]<<" Name: "<<vname[i]<<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Student with ID "<<id<<" not found."<<endl;
        }
        cout<<"--- Search Finished ---"<<endl;
    }
    void deleteStudent(int id){
        for(int i=0; i<vid.size(); i++){
            if(vid[i] == id){
                vid.erase(vid.begin() + i);
                vname.erase(vname.begin() + i);
                cout<<"Student with ID "<<id<<" deleted."<<endl;
                cout<<"--- Delete Finished ---"<<endl;
                return;
            }
        }
        cout<<"Student with ID "<<id<<" not found."<<endl;
        cout<<"--- Delete Finished ---"<<endl;
    }
};
int main(){
    cout<<"============================================================="<<endl;
    cout<<"\t\tStudent Management System"<<endl;
    cout<<"============================================================="<<endl;

    int ch;
    Task t;
    do{
        cout<<"----- Menu -----"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display Students"<<endl;
        cout<<"3. Search Student by ID"<<endl;
        cout<<"4. Delete Student by ID"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                t.AddStudent();
                break;
            case 2:
                t.display();
                break;
            case 3:
                int id;
                cout<<"Enter the ID to search: ";
                cin>>id;
                t.searchStudent(id);
                break;
            case 4:
                cout<<"Enter the ID to delete: ";
                cin>>id;
                t.deleteStudent(id);
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }while(ch != 5);
    cout<<"============================================================="<<endl;
    cout<<"\t\tProgram Ended"<<endl; 
    cout<<"============================================================="<<endl;   
    return 0;
}
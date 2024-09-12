#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;

void gotoy(){
	cout<<"\n\n\n\n\n";
}
void loadingbar(){
	char a=219;
			system("cls");
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\t\t\t";
			cout<<"\tLoading......\n";
			cout<<"\t\t\t\t\t\t";
		for(int i=0 ; i<20 ; i++){
			Sleep(100);
			cout<<a;
			}
			system("cls");
}

class Register{
	private:
		char username[30],email[30];
		char pass[20];
	public:
		void input(){
			again:
			cout<<"\t\t\t\t-----------------Register form-------------------"<<endl;
			cout<<"\t\t\t\t\t Enter Username:";gets(username);
			cout<<"\t\t\t\t\t Enter Email   :";gets(email);
			cout<<"\t\t\t\t\t Enter Password:";gets(pass);
		if(strlen(pass) < 8 ){
			cout<<"\n\t\t\t\t Password must be 8 charecter :)";
			getch();
			system("cls");
			goto again;
				
		}
	}
	
		char *getUsername(){
			return username;
		}
		char *getEmail(){
			return email;
		}
		char *getPass(){
			return pass;
		}
	

};



void regis(){
	fstream file;
	Register re;
	file.open("Username.bin" , ios::app | ios::binary);
	re.input();
	file.write((char*)&re , sizeof(re));
	file.close();
}
void login(){
	fstream file;
	Register arr[100],re;
	char usernameoremail[30] , password[20];
	int count = 0;
	file.open("Username.bin" , ios::in | ios::binary);
	while(file.read((char*)&re , sizeof(re))){
		arr[count] = re;
		count++;	
	}
			again:
			gotoy();
			cout<<"\t\t\t\t-----------------Login form-------------------"<<endl;
			cout<<"\t\t\t\t\t Enter Username & Email:";gets(usernameoremail);
			cout<<"\t\t\t\t\t Enter Password        :";gets(password);
			
		for(int i=0 ; i<count ; i++){
			if( ( strcmp(usernameoremail,arr[i].getUsername()) == 0 )	 
			||  ( strcmp(usernameoremail,arr[i].getEmail()) == 0 ) 
			&& ( strcmp(password,arr[i].getPass()) == 0 )){
				system("cls");
				loadingbar();                                           
				break;
			}else{
				cout<<"\t\t\t\t\tCheck your information again :)";
				getch();
				system("cls");
				
				goto again;
			}
		}	
	file.close();	
}

void form(){
	int op;
	
	again:
		gotoy();
		cout<<"\t\t\t\t-------------------------------------------------"<<endl;
		cout<<"\t\t\t\t|                                               |"<<endl;
		cout<<"\t\t\t\t|                 DELIVERY SYSTEM 	        |"<<endl;
		cout<<"\t\t\t\t|                                               |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------"<<endl;
		cout<<"\t\t\t\t|[1. Sign in]          \2\1\2\1         [2. Sign up]|"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------"<<endl;
		cout<<"\t\t\t\tChoose one option :";cin>>op;
		
		if(op ==1){
			system("cls");
			cin.ignore();
			login();
		}else if(op ==2){
			system("cls");
			cin.ignore();
			regis();
			getch();
			cout<<"\n\t\t\t\tPress Enter back to Sing in...";
			system("cls");
			goto again;
		}else{
			cout<<"\n\t\t\t\tWe only have two option :)";
			getch();
			system("cls");
			goto again;
		}
}
class customer{
	private:
		int id;
		char name[20],tel[20],location[20],time[20];
		
	public:
		customer(){
			id = 0;
			strcpy(name,"undifine");
			strcpy(tel,"undifine");
			strcpy(time,"undifine");
			strcpy(location,"undifine");
		}
		void input(){
			cout<<"\t\t\t\t-----------------Input form-------------------"<<endl;
			cout<<"\t\t\t\t\t Enter Id\t:";cin>>id;
			cout<<"\t\t\t\t\t Enter Name\t:";cin.ignore();gets(name);
			cout<<"\t\t\t\t\t Enter Tel\t:";gets(tel);
			cout<<"\t\t\t\t\t Enter Time\t:";gets(time);
			cout<<"\t\t\t\t\t Enter Location\t:";gets(location);
		}
		void input(int id){
			cout<<"\t\t\t\t-----------------Input form-------------------"<<endl;
			this->id = id;
			cout<<"\t\t\t\t\t Enter Name\t:";cin.ignore();gets(name);
			cout<<"\t\t\t\t\t Enter Tel\t:";gets(tel);
			cout<<"\t\t\t\t\t Enter Time\t:";gets(time);
			cout<<"\t\t\t\t\t Enter Location\t:";gets(location);
		}
		void output(){
			cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<tel<<"\t\t"<<time<<"\t\t"<<location<<endl;
		}
		int getid(){
			return id;
		}
};
void menu(){
	gotoy();
			cout<<"\t\t\t\t-----------------Input form--------------------"<<endl;
			cout<<"\t\t\t\t|              1. Write Data                  |"<<endl;
			cout<<"\t\t\t\t-----------------------------------------------"<<endl;
			cout<<"\t\t\t\t|              2. Read Data                   |"<<endl;
			cout<<"\t\t\t\t-----------------------------------------------"<<endl;
			cout<<"\t\t\t\t|              3. Update Data                 |"<<endl;
			cout<<"\t\t\t\t-----------------------------------------------"<<endl;
			cout<<"\t\t\t\t|              4. Delete Data                 |"<<endl;
			cout<<"\t\t\t\t-----------------------------------------------"<<endl;
			
}

int main(){
		customer cus;
		fstream file;
		int op;
		form();
		system("cls");
	do{
		menu();
		cout<<"\t\t\t\t Enter option U want\t:";cin>>op;
		switch(op){
			case 1:{
				system("cls");
				gotoy();
				file.open("Username.bin" , ios::app | ios::binary);
				cus.input();
				file.write((char*)&cus , sizeof(cus));
				file.close();
				getch();
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				gotoy();
				file.open("Username.bin" , ios::in | ios::binary);
				cout<<"\t\t\t\t                  [-Record Data-]                         "<<endl;
				cout<<"\t\t-----------------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t ID\t\tName\t\t\tTel\t\t\tTime\t\tLocation"<<endl;
				while(file.read((char*)&cus , sizeof(cus))){
						cus.output();
				cout<<"\t\t----------------------------------------------------------------------------------------"<<endl;
				}
			
				file.close();
				break;
			}
			case 3:{
				int sId , check=0;
				fstream tmp;
				system("cls");
				file.open("Username.bin" , ios::in | ios::binary);
			    tmp.open("temp.bin" , ios::out | ios::binary);
				gotoy();		
				cout<<"\t\t\t\t-----------------Update form-------------------"<<endl;
				cout<<"\t\t\t\t\t Enter ID\t:";cin>>sId;
				cout<<"\t\t\t\t-----------------------------------------------"<<endl;
				
				while(file.read( (char*)&cus , sizeof(cus))){
			    	if(sId == cus.getid()){
			    		system("cls");
			    		gotoy();
			    		cout<<"\t\t\t\t-----------------Let Update-------------------"<<endl;
			    		cus.input(sId);
			    		tmp.write((char*)&cus , sizeof(cus));
			    		check = 1;
			    		cout<<"\t\t\t\t\t\tUpdate success....";
					}else{
						tmp.write((char*)&cus , sizeof(cus));
						}
				if(check == 0){
					cout<<"\t\t\t\t\t\tID Not found :)"<<endl;
					}
				}
				file.close();
				tmp.close();
				remove("Username.bin");
				rename("temp.bin" , "Username.bin");
				break;
			}
			case 4:{
				int sId , check=0;
				fstream de;
				system("cls");
				file.open("Username.bin" , ios::in | ios::binary);
			    de.open("delete.bin" , ios::out | ios::binary);
				gotoy();		
				cout<<"\t\t\t\t-----------------Update form-------------------"<<endl;
				cout<<"\t\t\t\t\t Enter ID\t:";cin>>sId;
				cout<<"\t\t\t\t-----------------------------------------------"<<endl;
				
				while(file.read( (char*)&cus , sizeof(cus))){
			    	if(sId != cus.getid()){
			    		system("cls");
			    		gotoy();
			    		loadingbar();
			    		de.write((char*)&cus , sizeof(cus));
			    		check = 1;
			    		gotoy();
			    		cout<<"\t\t\t\t\t\tDelete success....";
			    		
					}
				/*	else{
							loadingbar();
							gotoy();
							
							cout<<"\t\t\t\t\t\tDelete success....";
						}*/

				}
				file.close();
				de.close();
				remove("Username.bin");
				rename("delete.bin" , "Username.bin");
				break;
			}
		}
		getch();
		system("cls");
	}while(op < 5);
	
}



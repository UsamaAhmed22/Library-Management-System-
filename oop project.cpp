#include<iostream> 
#include<conio.h>
#include<string>
#include<Windows.h>
#include<fstream>
//#include "sign-in.h"

using namespace std;
class View{
	public:
	virtual void viewAllBooks()=0;
	
};
//counter for Book array
int counter = 0;

//function for incrementing counter

void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}
class sig_in{
	public:
	string name="maju",password="ooplab";
};
class Book {
	private:
		string isbn,title,author,edition,publication; //private variables
	public:
		//setters - assigning user value to private variables
		void setIsbn(string a){isbn = a;}
		void setTitle(string b){title = b;}
		void setAuthor(string c){author = c;}
		void setEdition(string d){edition = d;}
		void setPublication(string e){publication = e;}
		//getters - getting the values from private variables
		string getIsbn(){return isbn;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
};
class LMS{
	public:
//Book class array initialization
Book books[10];

//addBook function
void addBook(){
	string isbn,title,author,edition,publication;
	cout<<"\t\tADD BOOK\n\n";
	if(counter < 10){
		cout<<"\t\tEnter ISBN of Book: ";
		cin>>isbn; 
		cout<<"\t\tEnter Title of Book: ";
		cin.ignore();
		getline(cin,title);//getline - just like cin but includes white spaces
		cout<<"\t\tEnter Author of Book: ";
		getline(cin,author);
		cout<<"\t\tEnter Edition of Book: ";
		getline(cin,edition);
		cout<<"\t\tEnter Publication of Book: ";
		getline(cin,publication);
		books[counter].setIsbn(isbn); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);	
		increment(counter);	//calling function to increment counter
		cout<<"\n\t\tBOOK ADDED SUCCESSFULLY!\n\n\t\tPress any key to continue . . .";
		_getch();
	}
	else{
		cout<<"\t\tYOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\n\t\tPress any key to continue . . .";
		_getch();
	}
}

//deleteBook function
void deleteBook(){
	string isbn;
	int choice;
	cout<<"\t\tDELETE BOOK\n\n";
	if(counter==0){
		cout<<"\t\tTHERE IS NO BOOK TO DELETE!\n\n\t\tPress any key to continue . . .";
		_getch();
	}
	else
	{
		cout<<"\t\tEnter ISBN of Book: ";
		cin.ignore();
		getline(cin,isbn);
	
		for(int i=0;i<counter;i++)
		{
			//finding a match using for loop
			if(books[i].getIsbn()==isbn){
				cout<<"\n\t\tBOOK FOUND\n\n";
				cout<<"\t\tDo you want to delete?\n\t\t[1]Yes\n\t\t[2]No\n\n\t\tEnter Choice: ";
				cin>>choice;
				if(choice==1){
					books[i].setIsbn(""); //setting the value to none
					books[i].setTitle("");
					books[i].setAuthor("");
					books[i].setEdition("");
					books[i].setPublication("");
					for(int a=i;a<counter;a++){
						//adjusting the values after deletion of data eg. data from book[4] copied to book[3]
						books[a] = books[a+1];
					}
					books[9].setIsbn(""); //adjustment if the library is full(10 books)
					books[9].setTitle("");
					books[9].setAuthor("");
					books[9].setEdition("");
					books[9].setPublication("");
					decrement(counter); //calling function to decrement counter
					cout<<"\n\t\tBOOK SUCCESSFULLY DELETED!\n\n\t\tPress any key to continue . . .";
					_getch();
	//				main();
				}
				else{
	//				main();
				}
			}
		}
		cout<<"\n\t\tBOOK NOT FOUND!\n\n\t\tPress any key to continue . . .";
		_getch();
//	main();
	}
}
void editBook(){
	string editIsbn,choice;
	string isbn,title,author,edition,publication;
	cout<<"\n\t\tEDIT BOOK\n\n";
	if(counter==0){
		cout<<"\t\tTHERE IS NO BOOK TO EDIT!\n\n\t\tPress any key to continue . . .";
		_getch();
//		main();
	}
	else
	{
		cout<<"\t\tEnter ISBN of Book: ";
		cin.ignore();
		getline(cin,editIsbn);
		for(int i=0;i<counter;i++){
			//finding a match using for loop
			if(books[i].getIsbn()==editIsbn)
			{
				cout<<"\n\t\tBOOK FOUND!\n\n";
				cout<<"\t\tISBN of Book: "<<books[i].getIsbn()<<endl;
				cout<<"\t\tTITLE of Book: "<<books[i].getTitle()<<endl;
				cout<<"\t\tAUTHOR of Book: "<<books[i].getAuthor()<<endl;
				cout<<"\t\tEDITION of Book: "<<books[i].getEdition()<<endl;
				cout<<"\t\tPUBLICATION of Book: "<<books[i].getPublication()<<endl;
				cout<<"\n\t\tDo you want to edit?\n\t\t[1]Yes\n\t\t[2]No\n\n\t\tEnter choice: ";
				getline(cin,choice);
				if(choice=="1"){
					//re-entering values
					cout<<"\t\tEnter ISBN of Book: ";
					getline(cin,isbn);
					cout<<"\t\tEnter Title of Book: ";
					getline(cin,title);
					cout<<"\t\tEnter Author of Book: ";
					getline(cin,author);
					cout<<"\t\tEnter Edition of Book: ";
					getline(cin,edition);
					cout<<"\t\tEnter Publication of Book: ";
					getline(cin,publication);
					books[i].setIsbn(isbn);
					books[i].setTitle(title);
					books[i].setAuthor(author);
					books[i].setEdition(edition);
					books[i].setPublication(publication);	
					cout<<"\n\t\tBOOK EDITED SUCCESSFULLY!\n\n\t\tPress any key to continue . . .";
					_getch();
					cout<<"\n\n\t\tDo you want to continue editing?\n\t\t[1]Yes\n\t\t[2]No\n\n\t\tEnter choice: ";
					getline(cin,choice);
					if(choice=="1"){
						editBook();//function call to self
					}
				}			
			}
		}
		cout<<"\n\t\tBOOK NOT FOUND!\n\n\t\tPress any key to continue . . .";
		_getch();
	}
}
void searchBook(){
	string isbn;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"\t\tSEARCH BOOK\n\n";
	if(counter > 0)
	{
		cout<<"\t\tEnter ISBN of Book: ";
		cin.ignore();
		getline(cin,isbn);
		for(int i=0;i<counter;i++){
			//finding a match using for loop
			if(books[i].getIsbn() == isbn){ 
				cout<<"\n\t\tBOOK FOUND!\n\n";
				cout<<"\t\tISBN of Book: "<<books[i].getIsbn()<<endl;
				cout<<"\t\tTITLE of Book: "<<books[i].getTitle()<<endl;
				cout<<"\t\tAUTHOR of Book: "<<books[i].getAuthor()<<endl;
				cout<<"\t\tEDITION of Book: "<<books[i].getEdition()<<endl;
				cout<<"\t\tPUBLICATION of Book: "<<books[i].getPublication()<<endl;
				print = true;
			}
		}
	}
	else
	{
		cout<<"\t\tTHERE IS NO BOOK TO SEARCH!\n\n\t\tPress any key to continue . . .";
		getch();
//		main();
	}
	if(print){
		cout<<"\n\n\t\tPress any key to continue . . .";
		_getch();
//		main();
	}
	//if there's no book found
	else{
		cout<<"\n\t\tBOOK NOT FOUND!\n\n\t\tPress any key to continue . . .";
		_getch();
//		main();		
	}
}
void viewAllBooks(){
	//iterating all the values on the library using book array
	cout<<"\t\tVIEW ALL BOOKS\n\n";
	 fstream fout;
   	    fout.open("ViewBook.txt",ios::app);
   	    {
   	    		for(int i=0;i<counter;i++){
		cout<<"\t\tBOOK DETAILS\n\n";
		cout<<"\t\tISBN of Book: "<<books[i].getIsbn()<<endl;
		cout<<"\t\tTITLE of Book: "<<books[i].getTitle()<<endl;
		cout<<"\t\tAUTHOR of Book: "<<books[i].getAuthor()<<endl;
		cout<<"\t\tEDITION of Book: "<<books[i].getEdition()<<endl;
		cout<<"\t\tPUBLICATION of Book: "<<books[i].getPublication()<<endl<<endl;
		fout<<"\t\tBOOK DETAILS\n\n";
		fout<<"\t\tISBN of Book: "<<books[i].getIsbn()<<endl;
		fout<<"\t\tTITLE of Book: "<<books[i].getTitle()<<endl;
		fout<<"\t\tAUTHOR of Book: "<<books[i].getAuthor()<<endl;
		fout<<"\t\tEDITION of Book: "<<books[i].getEdition()<<endl;
		fout<<"\t\tPUBLICATION of Book: "<<books[i].getPublication()<<endl<<endl;
		fout.close();
	}
	}
		   

	cout<<"\t\tPress any key to continue . . .";
	_getch();
//	main();
}
void quit(){
	//quit function
	_exit(1);
}

};

//initializing functions with counter as parameter
//void addBook();
//void deleteBook();
//void editBook();
//void searchBook();
//void viewAllBooks();
//void quit();

//student class inhert from book
	
//};
//librarain  class inhert from book
class lib  : public LMS{
public:
//void addBook();
//void deleteBook();
//void editBook();
//void searchBook();
//void viewAllBooks();
//void quit();
bool login()
{
	string uname,pass;
	sig_in s1;
	cout<<"\t\tEnter the Name: ";
	cin>>uname;
	cout<<"\t\tEnter the Password: ";
	cin>>pass;
	if(uname ==s1.name && pass ==s1.password){
		cout<<"\t\tLogged in...."<<endl;
		Sleep(1000);
		system("CLS");
		return true;
	}
	else
	{
		cout<<"\t\tIncorrect username or password"<<endl;
		Sleep(1000);
		system("CLS");
		return false;
	}
}
};
class student : public LMS{
//	public:
//	viewAllBooks();
//	searchBook(); 

//main function
};
int main(){
student s1;
lib l1;
int input, option ;
system("cls");
mainmenu: cout<<"\t\t\tWELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n";
cout<<"--------------------------------------------------------------------------------\n";
cout<<"\t\tPress 1 For Student\n\t\tPress 2 For Librarian\n";
cin >> input;
fflush(stdin);
system("cls");
//cout << "Going to switch case\n";
switch (input) {
  case 1:
  	studentmenu:cout<<"\t\t\t*******WELCOME STUDENT*******\n\n";
  	cout<<"--------------------------------------------------------------------------------\n";
  	cout<<"\t\t\t[1]: Search Book\n\t\t\t[2]: View Book List\n\t\t\t[3]: Go To Main Menu"<<endl;
  	fflush(stdin);
	cin >> option;
    switch(option)
	{
	case 1:
		//s1=l1;
    	l1.searchBook();
    	break;
    case 2:
    	
		l1.viewAllBooks();
		break;
	case 3:
		system("cls");
		goto mainmenu;
		break;
	default:
		break;
	}
	system("cls");
	goto studentmenu;
    break;
  case 2:
  	if(l1.login()){
	libmenu:cout<<"\t\t\t*******WELCOME LIBRARIAN*******\n\n";
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<"\t\t[1]ADD BOOK\n";	
	cout<<"\t\t[2]DELETE BOOK\n";	
	cout<<"\t\t[3]EDIT BOOK\n";	
	cout<<"\t\t[4]SEARCH BOOK\n";	
	cout<<"\t\t[5]VIEW ALL BOOKS\n";
	cout<<"\t\t[6]GO TO MAIN MENU\n";	
	cout<<"\t\t[7]QUIT\n\n";
	
	cout<<"\t\tENTER CHOICE: ";
	  	cin>>input;
	    switch(input)
		{
	  	case 1: 
	     	l1.addBook();
	    	break;
	    case 2:
			l1.deleteBook();
	    	break;
		case 3:    	
			l1.editBook();
	    	break;
	    case 4:
			l1.searchBook();
	    	break;
		case 5:    	
			l1.viewAllBooks();
	    	break;
	    case 6:
	    	system("cls");
	    	goto mainmenu;
	    default: 
			l1.quit();
	    	break;
		}
		system("CLS");
	    goto libmenu;
	}
	else
		goto mainmenu;
	}
}

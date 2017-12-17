#include <fstream.h>
#include <conio.h>


struct node{
	char data;
	node *next;
};

class list{
	node *head;
	node *tail;
	public:
			//To Get Rid of Garbage Values
		list(){
			head = NULL;
			tail = NULL;
		}
		void createnode(char val);
		void display(char path[]); //displays decrypted message
		void store(char arr[]); //stores encrypted message in a file
};

void list::createnode (char val){
	node *temp = new node;
	temp -> data = val;
	temp -> next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

class XOR{
	char key;
	public:
		char encryptdecrypt(char p);
		XOR();
};

void list::display(char path[]){
	ifstream file;
	char c=NULL;
	file.open(path, ios::app);
	file.seekg(0);
	while(file.get(c))
	{
		createnode(c);
	}
	node *temp = new node;
	temp = head;
	XOR xor;
	while(temp!=NULL)
	{
		cout<<xor.encryptdecrypt(temp->data);
		temp = temp->next;
	}
file.close();

}
void list::store(char arr[]){
       ofstream file;
       file.open (arr, ios::out);
       node *temp = new node;
       temp = head;
       while(temp!= NULL)
       {
		file.put(temp->data);
		temp = temp->next;
       }
       file.close();
}
XOR::XOR(){
	key = '3';
}
char XOR::encryptdecrypt(char p)
{
		p^=key;
		return p;

}
 
void main(){
	clrscr();
	char c;
	int num=0;
	do{
		cout<<"\n\n\tWelcome to Your Very Own Encryption/Decryption Program\n\t";
		cout<<"Choose one of the following options:\n\n\t";
		cout<<"1.Encrypt\n\t2.Decrypt\n\t3.Close the Program\n\t  	(e, d, c)\n\n";
		cin>>c;
		clrscr();
		switch(c){
			case 'e':
			case 'E':    cout<<"ENCRYPTION\n\nEnter Choice Number\n";
				    cout<<"1. Enter File\t2.Type in Text\n";
				    cin>>num;
				    XOR xor;
				    switch(num){
					case 1: clrscr();
						list l;
						cout<<"Enter Name of File to be Encrypted\n";
						char name[100], temp;
						cin>>name;
						fstream file;
						file.open(name, ios::app | ios::in | ios::out);
						file.seekg(0);
						while(file.get(temp))
							l.createnode(xor.encryptdecrypt(temp));
						file.close();
						file.open(name, ios::trunc);
						l.store(name);
						file.close();
						break;
					  case 2: char input=NULL;
						 list linked;
					  	 clrscr();
					 	 char arr[11];
					  	 cout<<"ALL TYPED TEXT WILL BE 			   						ENCRYPTED\n\n(Enter # to terminate input)\n\n";
 
				//INPUT

						cin.get(input);
						while(input!='#'){
				//XOR encryption
											 			 						linked.createnode(xor.encryptdecrypt(input));
							cin.get(input);
							}
						  cout<<"\n Enter File Name (No spaces, max 									length 10 chars)\n ";
					 	  cin>>arr;
					 	  linked.store(arr);
				//store in file
						break;
				default: break;
				}

			 	 break;
			case 'd':
			case 'D': cout<<"Enter Path of Encrypted File\n\n";
				  char path[11];
				  list linked;
		 	 	  cin>>path;
				  cout<<"-------\n-------\n-------\n\n";
				  linked.display(path);
				  cout<<endl<<endl;

				break;

			case 'c': break;
			case 'C': break;
			default: cout<<"You've entered an incorrect option. Please try again\n\n";
				continue;
		}
       }while(c!='c');
 getch();
}

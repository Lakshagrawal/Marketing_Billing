#include<iostream>
#include<fstream>

using namespace std;
class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void recepit();
};


void shopping :: menu()
{
    m:

    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t    Supermarket Main Menu     \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t______________________________\n";

    cout<<"\t\t\t\t|       1)Administrator      |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|       2)Buyer              |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|       3)Exit               |\n";

    cout<<"Please select the above option: ";
    cin>>choice;

    if(choice == 1){
        cout<<"Please login\n";
        cout<<"Enter you email: ";
        cin>>email;
        cout<<"Password: ";
        cin>>password;

        if(email == "lakshya@gmail.com" && password == "Lakshya12"){
            administrator();
        }
        else{
            cout<<"Correct E-mail or Passoword";
            goto m;
        }
    }
    else if(choice == 2){
        buyer();
    }
    else if(choice == 3){
        exit(0);
    }
    else{
        cout<<"Please select valid option";
        goto m;
    }

    goto m;

}



void shopping :: administrator(){
    m:

    int choice;
    cout<<"\n\n\n\t\t\t\t Administrator menu";
    cout<<"\n\t\t\t|____1)Add the product________|";
    cout<<"\n\t\t\t|____2)Modify the product_____|";
    cout<<"\n\t\t\t|____3)Delete the product_____|";
    cout<<"\n\t\t\t|____4)Back to main menu______|";


    cout<<"\n\n\t Please enter you choice";
    cin>>choice;

    if(choice == 1){
        add();
    }
    else if(choice == 2){
        edit();
    }
    else if (choice == 3){
        rem();
    }
    else if(choice == 4){
        menu();
    }
    else cout<<"Invalid choice";

    goto m;

}

void shopping:: buyer(){
    m:

    int choice;
    cout<<"\n\n\n\t\t\t Buyer  ";
    cout<<"\n\t\t\t ____1)Buy product_______|";
    cout<<"\n\t\t\t ____2)Go back___________|";
    cout<<"\nEnter your choice: ";
    cin>>choice;


    if(choice == 1)
        recepit();
    else if (choice == 2)
        menu();
    else 
        cout<<"Enter valid choice";

    goto m;

}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p,d;
    string n;

    cout<<"\n\n\n\t\t\t Add new product  ";
    cout<<"\n\t\t\t Procuct code of the product: ";
    cin>>pcode;
    cout<<"\n\t\t\t Name of the product: ";
    cin>>pname;
    cout<<"\n\t\t\t price of the product: ";
    cin>>price;
    cout<<"\n\t\t\t Discount on the product: ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        // app mean it is open in append mode 
        // out mean it is open in write mode it make the file then write in it 
        data.open("database.txt",ios::app|ios::out);
        // inserting the value inthe file
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        // reading the file
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode)
                token++;
            data>>c>>n>>p>>d;
        }

        data.close();
    

        if(token == 1)
            goto m;
        else{
            data.open("database.txt",ios::app|ios::out);
            // inserting the value inthe file
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted !";

}

void shopping :: edit(){
    fstream data,data1;
    int pkey,token = 0,c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code: ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n file doesn't exit! ";
    }
    else{
        data1.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\n\t\t Name of the product: ";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }

            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<"\n\n Record not fount sorry! ";
        }
    }
}

void shopping :: rem(){

    fstream data,data1;

    int pkey,token = 0;

    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product Code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\n\t Product delete succesfully";
                token++;
            }
            else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<"\n\n Record not found";
        }

    }

}

void shopping :: list(){
    fstream data;

    data.open("database.txt",ios::in);
    cout<<"\n\n|___________________________________\n";
    cout<<"ProNo\t\t Name\t\t Price\n";
    cout<<"\n\n____________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();

}

void shopping :: recepit(){
    m:
    fstream data;
    int arrc[100],arrq[100];
    char choice;
    int c = 0;
    float amount = 0,dis=0;
    float total = 0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    data.open("database.txt",ios::in);

    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n_______________________\n";
        cout<<"\n|                      \n";
        cout<<"\n    Please place the order    \n";
        cout<<"\n|                      \n";
        cout<<"\n_______________________\n";

        do{
            cout<<"\n\n Enter Product Code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter the Product Quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try again ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you wnat to buy another product? if yes the press yes else no ";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n\n\t\t\t__________________________RECEIPT_________________\n";
        cout<<"\n PRoduct no.\t product Name \t Product quantity \t price \t Amount \t Amount with discount\n";

        for(int i=0;i<c;i++){
            data.open("databases.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis)/100;
                    total += dis;
                    cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }

                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }


    cout<<"\n\n___________________________________________________";
    cout<<"\n Total Amount: "<<total;
}

int main(){
    shopping s;
    s.menu();
}
#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;
MYSQL* conn;
int qstate;


void registration()
{

    MYSQL_RES *res;
    MYSQL_ROW row;
    system("cls");
    string name,password,email,address;
    string phonenumber;
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"                 *******************WELCOME TO REGISTRATION*******************           ";
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"                 ------------------Enter the details carefully----------------           ";
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    cout<<"     ENTER NAME:: ";
    cin.ignore();
    getline(cin,name);
    cout<<endl;
    cout<<"     ENTER PASSWORD:: ";
    cin>>password;
    cout<<endl;
    int v=1;
    while(v)
    {


        cout<<"   ------------------------phone number should be of 10 digits-----------------------"<<endl<<endl;;
        cout<<"     ENTER PHONENUMBER:: ";
        cin>>phonenumber;
        cout<<endl<<endl;
        int kl=phonenumber.length();
        if(kl != 10)
        {
            system("cls");
            v=1;
            cout<<"                 ..........  INVALID PHONENUMBER  .........    "<<endl<<endl;
        }
        else
        {
            v=0;
            char ch[15];
            strcpy(ch,phonenumber.c_str());
            int c=0;
            for(int i=0 ; i<10 ; i++ )
            {
                if(ch[i]=='0' || ch[i]=='1' ||ch[i]=='2' ||ch[i]=='3' ||ch[i]=='4' ||ch[i]=='5' ||ch[i]=='6' ||ch[i]=='7' ||ch[i]=='8' ||ch[i]=='9'  )
                {
                    c++;

                }
            }
            if(c!=10)
            {
                 v=1;
                 system("cls");
                cout<<"                 ----------------            USE ONLY NUMBERS IN PHONE NUMBER        --------------"<<endl<<endl;
            }
            else
                v=0;
        }
    }
    int vv=1;
    while(vv)
    {

    //system("cls");
    cout<<"             ...................  Enter a valid email id...............       "<<endl<<endl;
    cout<<"     ENTER EMAIL:: ";
    cin>>email;


            vv=0;
            char ch[30];
            strcpy(ch,email.c_str());
            int c=0;
            for(int i=0 ; i<30 ; i++ )
            {
                if(ch[i]=='@' )
                {
                    c++;

                }
            }
            if(c!=1)
            {
                system("cls");
                 vv=1;
                cout<<"                 -------------------            USE VALID EMAIL        -----------------"<<endl<<endl;
            }
            else
                vv=0;




     cout<<endl<<endl;


    }
    cout<<endl;
    cout<<"     ENTER ADDRESS:: ";
    cin>>address;
    cout<<endl<<endl;

    string namee,passwordd;
    cout<<"                 -----------------------ENTER MANAGER DETAILS FOR VALIDATION-----------------------"<<endl<<endl<<endl;
                cout<<"                 ENTER MANAGER USER-ID :: ";
                cin>>namee;
                cout<<endl<<endl;
                cout<<"                 ENTER MANAGER PASSWORD :: ";
                cin>>passwordd;
                cout<<endl<<endl;
                string query="SELECT password,name FROM registration where name = '"+namee+"' AND password = '"+passwordd+"' ";
                const char* qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                int validate=0;
                if(row != 0)
                {
                    validate=1;
                    cout<<"                          ---------------------------------------------------------------------------------   "<<endl;
                    cout<<"                          ------------------------------VALIDATION DONE BY MANAGER-------------------------   "<<endl;
                    cout<<"                          ---------------------------------------------------------------------------------   "<<endl;
                }
                else
                {
                    cout<<"                     ------------------------------------------------------------------------------------"<<endl;
                    cout<<"                     -------------------------------------VALIDATION FAILED------------------------------"<<endl;
                    cout<<"                     -------------------------------------------TRY AGAIN--------------------------------"<<endl;
                    cout<<"                      -----------------------------------------------------------------------------------"<<endl;

                }



    cout<<endl;
    if(validate==1)
    {


    mysql_query (conn,"ALTER TABLE registration AUTO_INCREMENT = 1");
    string query = "INSERT INTO registration (id,name,password,phonenumber,email,address)  values ('','"+name+"','"+password+"','"+phonenumber+"','"+email+"','"+address+"')";
    const char* q=query.c_str();
    qstate=mysql_query(conn,q);
    if(qstate ==0)
    cout<<"                 ********************************* MANAGER REGISTRATION SUCCESSFULLY DONE************************************" << endl;
    else
    cout <<"                    ************************************REGISTRATION FAILED****************************************"<<endl;

    }

}

booking()
{

    system("cls");
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"******************************************************** WELCOME TO BOOKING **************************************************";
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"------------------------------------------------Enter the details carefully--------------------------------------------------";
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;


   // cout<<"ENTER ROOM TYPE:: "<<endl;cout<<endl;
    cout<<"                 PRESS 11 FOR SINGLE-BED AC ROOM "<<endl;cout<<endl;
    cout<<"                 PRESS 12 FOR DOUBLE-BED AC ROOM "<<endl;cout<<endl;
    cout<<"                 PRESS 13 FOR TRIPLE-BED AC ROOM "<<endl;cout<<endl;
    cout<<"                 PRESS 21 FOR SINGLE-BED NON-AC ROOM "<<endl;cout<<endl;
    cout<<"                 PRESS 22 FOR DOUBLE-BED NON-AC ROOM "<<endl;cout<<endl;
    cout<<"                 PRESS 23 FOR TRIPLE-BED NON-AC ROOM "<<endl;cout<<endl;
    int roomtype1;
    string stayduration;
    cout<<endl;
    cout<<"             ENTER ROOM TYPE ::      ";
    cin>>roomtype1;
    cout<<endl;
    cout<<"             BOOKING FOR NO OF DAYS ::       ";
    cin>>stayduration;
    cout<<endl<<endl;
    int confirm;
    if(roomtype1==11)
    {
       cout<<"      YOU WANT TO BOOK A SINGLE-BED AC ROOM FOR "<< stayduration<<" DAYS"<<endl<<endl;
                            cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
       cin>>confirm;cout<<endl<<endl;
    }
        else
        {
            if(roomtype1==12)
            {
                cout<<"     YOU WANT TO BOOK A DOUBLE-BED AC ROOM FOR   "<< stayduration<<" DAYS"<<endl<<endl;
                 cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
                cin>>confirm;cout<<endl<<endl;
            }
            else
            {
                if(roomtype1==13)
                {
                cout<<"     YOU WANT TO BOOK A TRIPLE-BED AC ROOM FOR   "<< stayduration<<" DAYS"<<endl<<endl;
                 cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
                cin>>confirm;cout<<endl<<endl;


                }
                else
                {
                    if(roomtype1==21)
                    {
                        cout<<"     YOU WANT TO BOOK A SINGLE-BED NON-AC ROOM FOR   "<< stayduration<<"  DAYS"<<endl<<endl;
                         cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
                        cin>>confirm;cout<<endl<<endl;


                    }
                    else
                    {
                        if(roomtype1==22)
                        {
                        cout<<"     YOU WANT TO BOOK A DOUBLE-BED NON-AC ROOM FOR "<< stayduration<<" DAYS"<<endl<<endl;
                         cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
                        cin>>confirm;cout<<endl<<endl;



                        }
                        else
                        {
                            if(roomtype1==23)
                            {

                            cout<<"     YOU WANT TO BOOK A TRIPLE-BED NON-AC ROOM FOR "<< stayduration<<" DAYS"<<endl<<endl;
                            cout<<"      ____________________________________________________________"<<endl;
                            cout<<"     |                                                            |"<<endl;
                            cout<<"     |        PRESS 1 TO CONFIRM AND ANY OTHER KEY TO CANCEL      |"<<endl;
                            cout<<"     |____________________________________________________________|"<<endl;
                            cin>>confirm;cout<<endl<<endl;


                            }
                            else
                            {
                                cout<<"     INVALID ROOM SELECTION      " <<endl<<endl;
                            }
                        }
                    }
                }
            }
        }

        if(confirm==1)
        {
            system("cls");
            string roomid;
            int iroomid;
            roomid=to_string(roomtype1);
                            cout<<"                        ____________________________________________________________"<<endl;
                            cout<<"                       |                                                            |"<<endl;
                            cout<<"                       |               CHECKING FOR ROOM AVAILABILITY               |"<<endl;
                            cout<<"                       |____________________________________________________________|"<<endl<<endl<<endl;
             MYSQL_RES *res;
             MYSQL_ROW row;
             string query= "SELECT emptyrooms FROM roomdetails where roomid = '"+roomid+"' ";
             const char* q=query.c_str();
             mysql_query(conn,q);
              res = mysql_store_result(conn);
             row=mysql_fetch_row(res);
             string p=*row;
             int iemptyrooms=stoi(p);
             iroomid=stoi(roomid);
             if(iemptyrooms>0)
             {
                            cout<<"                        ____________________________________________________________"<<endl;
                            cout<<"                       |                                                            |"<<endl;
                            cout<<"                       |                      CONGRATS ROOM AVAILABLE               |"<<endl;
                            cout<<"                       |____________________________________________________________|"<<endl<<endl<<endl;
                 cout<<endl;
                 cout<<"                ---------------PRESS ANY KEY TO CONTINUE---------------"<<endl<<endl;
                 cin.ignore();
                 getchar();
                 system("cls");
                 cout<<endl;
                 cout<<"            --------------------------ENTER DETAILS TO PROCEED-------------------------"<<endl<<endl<<endl<<endl;

                     string name,idnumber,email,address;
                     string phonenumber;
                     string namee,passwordd;

                    cout<<"        ENTER NAME:: ";
                   //cin.ignore();
                    getline(cin,name);

                    cout<<endl;
int v=1;
while(v)
    {


        cout<<"                                phone number should be of 10 digits     -----------------------"<<endl;;
        cout<<"        ENTER PHONENUMBER:: ";
        cin>>phonenumber;
        cout<<endl;
        int kl=phonenumber.length();
        if(kl != 10)
        {
            system("cls");
            v=1;
            cout<<"    ......INVALID PHONENUMBER......    "<<endl<<endl;
        }
        else
        {
                v=0;
            char ch[15];
            strcpy(ch,phonenumber.c_str());
            int c=0;
            for(int i=0 ; i<10 ; i++ )
            {
                if(ch[i]=='0' || ch[i]=='1' ||ch[i]=='2' ||ch[i]=='3' ||ch[i]=='4' ||ch[i]=='5' ||ch[i]=='6' ||ch[i]=='7' ||ch[i]=='8' ||ch[i]=='9'  )
                {
                    c++;

                }
            }
            if(c!=10)
            {
                 v=1;
                 system("cls");
                cout<<"                 ----------------            USE ONLY NUMBERS IN PHONE NUMBER        --------------"<<endl<<endl;
            }
            else
                v=0;
        }
    }
                    cout<<endl;
                    cout<<"        ENTER ID-NUMBER:: ";
                    cin>>idnumber;
                    cout<<endl;
                        int vv=1;
    while(vv)
    {

    //system("cls");
    cout<<"                                Enter a valid email id...............       "<<endl<<endl;
    cout<<"        ENTER EMAIL:: ";
    cin>>email;


            vv=0;
            char ch[30];
            strcpy(ch,email.c_str());
            int c=0;
            for(int i=0 ; i<30 ; i++ )
            {
                if(ch[i]=='@' )
                {
                    c++;

                }
            }
            if(c!=1)
            {
                system("cls");
                 vv=1;
                cout<<"                 -------------------            USE VALID EMAIL        -----------------"<<endl<<endl;
            }
            else
                vv=0;




     cout<<endl<<endl;


    }

                    cout<<endl;
                    cout<<"        ENTER ADDRESS:: ";
                    cin>>address;
                    cout<<endl;


                cout<<"                 -----------------------ENTER MANAGER DETAILS FOR VALIDATION-----------------------"<<endl<<endl<<endl;
                cout<<"                 ENTER MANAGER USER-ID :: ";
                cin>>namee;
                cout<<endl<<endl;
                cout<<"                 ENTER MANAGER PASSWORD :: ";
                cin>>passwordd;
                cout<<endl<<endl;
                string query="SELECT password,name FROM registration where name = '"+namee+"' AND password = '"+passwordd+"' ";
                const char* qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                int validate=0;
                if(row != 0)
                {
                    validate=1;
                    cout<<"                          ---------------------------------------------------------------------------------   "<<endl;
                    cout<<"                          ------------------------------VALIDATION DONE BY MANAGER-------------------------   "<<endl;
                    cout<<"                          ---------------------------------------------------------------------------------   "<<endl;

                    string roomtype=to_string(roomtype1);
                    mysql_query (conn,"ALTER TABLE registration AUTO_INCREMENT = 1");
                    string query = "INSERT INTO bookingdetails (id,name,phonenumber,idnumber,email,address,stayduration,roomtype)  values ('','"+name+"','"+phonenumber+"','"+idnumber+"','"+email+"','"+address+"','"+stayduration+"','"+roomtype+"')";
                    const char* q=query.c_str();
                    qstate=mysql_query(conn,q);
                    if(qstate ==0)
                    {
                        system("cls");
                        cout<<endl<<endl<<endl<<endl<<endl;
                        cout<<"                               ---------------------------------------------------------------------------------"<<endl;
                        cout<<"                               --------******************BOOKING SUCCESSFULLY DONE************************------" << endl;
                        cout<<"                               ----------------------------------------------------------------------------------"<<endl<<endl<<endl;
                        //------------------------updating total emptyrooms in here-----------------------------------
                        query= "SELECT emptyrooms FROM roomdetails where roomid = '"+roomid+"' ";
                        const char* uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);
                        row=mysql_fetch_row(res);
                        string up=*row;
                        int uemptyrooms=stoi(p);
                        uemptyrooms=uemptyrooms-1;
                        string uuemptyrooms=to_string(uemptyrooms);
                        query= "update roomdetails set emptyrooms ='"+uuemptyrooms+"' where roomid = '"+roomid+"' ";
                        uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);
                        //id generation
                        query= "SELECT id FROM bookingdetails where name = '"+name+"' AND phonenumber = '"+phonenumber+"' ";
                        uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);
                        row=mysql_fetch_row(res);
                        string did=*row;
                        cout<<endl<<endl;
                        cout<<endl<<endl<<endl<<endl<<endl;
                        cout<<"                                -----------------------------------------------------------------------------------"<<endl;
                        cout<<"                                -------------------DEAR "<<name<<" YOUR BOOKING ID IS : "<<did<<"------------------"<<endl;
                        cout<<"                                -----------------------------------------------------------------------------------"<<endl<<endl<<endl<<endl;
                    }

                    else
                    {


                        cout<<"                _________________________________________________________________________"<<endl;
                        cout<<"                ******************************BOOKING FAILED*****************************"<<endl;
                        cout<<"                |________________________________________________________________________|"<<endl;

                    }
                }
                else
                {
                    cout<<"                     ------------------------------------------------------------------------------------"<<endl;
                    cout<<"                     -------------------------------------VALIDATION FAILED------------------------------"<<endl;
                    cout<<"                     -------------------------------------------TRY AGAIN--------------------------------"<<endl;
                    cout<<"                      -----------------------------------------------------------------------------------"<<endl;
                }


             }

             else

             {
                            cout<<"                        ____________________________________________________________"<<endl;
                            cout<<"                       |                                                            |"<<endl;
                            cout<<"                       |               SORRY NO ROOMS AVAILABLE                     |"<<endl;
                            cout<<"                       |____________________________________________________________|"<<endl<<endl<<endl;



             }




        }




}

food()
{

    system("cls");
    string bookingid,foodname,footitemname,phone;

   // cout<<"   ENTER BOOKING ID----:: ";
    //cin>>id;
    cout<<endl;
    cout<<"----------------------------WELCOME TO FOOD SECTION---------------------------"<<endl;
    cout<<"                            ```````````````````````                          "<<endl;
    cout<<endl<<endl<<endl;
    cout<<"   ENTER BOOKING ID----:: ";
    cin>>bookingid;
    cout<<endl<<endl;
    cout<<"   ENTER PHONENUMBER----:: ";
    cin>>phone;
    cout<<endl<<endl;
    MYSQL_RES *res;
             MYSQL_ROW row;
    string query= "SELECT id FROM bookingdetails where phonenumber = '"+phone+"' ";
     const char* q=query.c_str();
// const char* uq=query.c_str();
                        mysql_query(conn,q);
                        res = mysql_store_result(conn);
                        row=mysql_fetch_row(res);
                        string diid;
                        if(row!=0)
                         diid=*row;
                        //cout<<diid<<endl;
                        int tttt=1;
                        if(diid.compare(bookingid)!=0)
                        {
                            cout<<"*********************************************************************************************************"<<endl;
                            cout<<"------------------------------                INVALID BOOKING ID AND PHONENUMBER                ---------"<<endl;
                            cout<<"*********************************************************************************************************"<<endl;
                            tttt=0;
                        }


    if(tttt==1)
    {


        cout<<"__________________SELECT FOOD ITEMS FROM THIS LIST____________________"<<endl;
        cout<<"|                                                                     |"<<endl;
        cout<<"| 1. paneermasala                                                  150|"<<endl;
        cout<<"| 2. paneerbuttermasala                                            150|"<<endl;
        cout<<"| 3. plainnann                                                      30|"<<endl;
        cout<<"| 4. butternann                                                     50|"<<endl;
        cout<<"| 5. dalfry                                                         60|"<<endl;
        cout<<"| 6. maggie                                                         20|"<<endl;
        cout<<"| 7. chickenmasala                                                 180|"<<endl;
        cout<<"| 8. chickenbuttermasala                                           200|"<<endl;
        cout<<"| 9. vegbiryani                                                    250|"<<endl;
        cout<<"| 10. muttonbiryani                                                260|"<<endl;
        cout<<"| 11. fishbiryani                                                  280|"<<endl;
        cout<<"| 12. fishcurry                                                    360|"<<endl;
        cout<<"| 13. icecream                                                     100|"<<endl;
        cout<<"| 14. coffee                                                        30|"<<endl;
        cout<<"| 15. colddrinks                                                    30|"<<endl;
        cout<<"| 16. tea                                                           10|"<<endl;
        cout<<"| 17. energydrink                                                  100|"<<endl;
        cout<<"_______________________________________________________________________"<<endl;

       int x=0;
        cout<<endl<<endl<<endl;
        cout<<"                             ENTER THE ITEMS YOU WANT TO ORDER                   "<<endl<<endl;
       // cout<<"----ITEMS-ID---|-----QUANTITY---"<<endl;
        char more;
        more='y';
        int item[1000];
        int quantity[1000];
        int i=0;
         while(more=='y')
        {

            more='n';
            cout<<"     -------------------------------------ENTER ITEM NAME : ";
            cin>>item[i];
            cout<<endl;
            cout<<"     -------------------------------------ENTER QUANTITY  : ";
            cin>>quantity[i];

            cout<<endl<<endl<<"           Press 'y' if you want to add more food items and n if you :";
            cin>>more;
            cout<<endl;
            i++;
        }
            string fitem;
            string fname;
            int totalprice=0;
            string strr="";
            i--;

        for(;i>=0;i--)
        {
            int xx=item[i];

            string qq= to_string(quantity[i]);
            switch(xx)
            {
                case 1: totalprice=totalprice+quantity[i]*150;
                        strr.append("paneermasala ");
                        break;
                case 2: totalprice=totalprice+quantity[i]*150;
                        strr.append("paneerbuttermasala ");
                        break;
                case 3: totalprice=totalprice+quantity[i]*30;
                        strr.append("plainnann ");
                        break;
                case 4: totalprice=totalprice+quantity[i]*50;
                        strr.append("butternann ");
                        break;
                case 5: totalprice=totalprice+quantity[i]*60;
                        strr.append("dalfry ");
                        break;
                case 6: totalprice=totalprice+quantity[i]*20;
                        strr.append("maggie ");
                        break;
                case 7: totalprice=totalprice+quantity[i]*180;
                        strr.append("chickenmasala ");
                        break;
                case 8: totalprice=totalprice+quantity[i]*200;
                        strr.append("chickenbuttermasala ");
                        break;
                case 9: totalprice=totalprice+quantity[i]*250;
                        strr.append("vegbiryani ");
                        break;
                case 10: totalprice=totalprice+quantity[i]*260;
                        strr.append("muttonbiryani ");
                        break;
                case 11: totalprice=totalprice+quantity[i]*280;
                        strr.append("fishbiryani ");
                        break;
                case 12: totalprice=totalprice+quantity[i]*360;
                        strr.append("fishcurry ");
                        break;
                case 13: totalprice=totalprice+quantity[i]*100;
                        strr.append("icecream ");
                        break;
                case 14: totalprice=totalprice+quantity[i]*30;
                        strr.append("coffee ");
                        break;
                case 15: totalprice=totalprice+quantity[i]*30;
                        strr.append("colddrinks ");
                        break;
                case 16: totalprice=totalprice+quantity[i]*10;
                        strr.append("tea ");
                        break;
                case 17: totalprice=totalprice+quantity[i]*100;
                        strr.append("energydrink ");
                        break;
                 default:cout<<"        invalid selection       "<<endl;
            }

        }
        system("cls");
            cout<<endl<<endl;
            cout<<"     Total price-- "<<totalprice<<endl;

            cout<<"     Items ordered-- "<<strr<<endl;
                    string totalfoodprice=to_string(totalprice);
                    mysql_query (conn,"ALTER TABLE foodorderdetails AUTO_INCREMENT = 1");
                    string query = "INSERT INTO foodorderdetails (foodorderid,bookingid,totalfoodprice,fooditemsordered)  values ('','"+bookingid+"','"+totalfoodprice+"','"+strr+"')";
                    const char* q=query.c_str();
//                    cout<<q;
                    qstate=mysql_query(conn,q);
                    if(qstate ==0)
                    {
                        cout<<endl<<"       -------------------------------------------FOOD SUCCESSFULLY ORDERED--------------------------------------------------   "<<endl;
                    }
                    else
                      cout<<endl<<"         ----------------------------------------------FOOD ORDER FAILED-----------------------------------------------------------   "<<endl;

    }


}

checkout()
{

        system("cls");
        string bookingid,namee,passwordd,phone;
        MYSQL_RES *res;
        MYSQL_ROW row;
        cout<<endl;
        cout<<"--------------------------------------------------------------       CHECKOUT       -----------------------------------------------------"<<endl;
        cout<<"                                                              ```````````````````````                          "<<endl;
        cout<<endl<<endl<<endl;
        cout<<"         ENTER BOOKING ID----:: ";
        cin>>bookingid;
        cout<<endl;
        cout<<"         ENTER PHONENUMBER----:: ";
        cin>>phone;
        cout<<endl<<endl;

        string qquery= "SELECT id FROM bookingdetails where phonenumber = '"+phone+"' ";
        const char* qq=qquery.c_str();
// const char* uq=query.c_str();
        mysql_query(conn,qq);
        res = mysql_store_result(conn);
        row=mysql_fetch_row(res);
        string diid;
        if(row!=0)
        diid=*row;
                        //cout<<diid<<endl;
                        int tttt=1;
                        if(diid.compare(bookingid)!=0)
                        {
                            cout<<"*********************************************************************************************************"<<endl;
                            cout<<"------------------------------                INVALID BOOKING ID AND PHONENUMBER                ---------"<<endl;
                            cout<<"*********************************************************************************************************"<<endl;
                            tttt=0;
                        }

                        if(tttt==1)
                        {



                cout<<"                                    -----------ENTER MANAGER DETAILS FOR VALIDATION--------------------"<<endl;
                cout<<"                                    ___________________________________________________________________"<<endl<<endl;
                cout<<"                  ENTER MANAGER USER-ID :: ";
                cin>>namee;
                cout<<endl<<endl;
                cout<<"                  ENTER MANAGER PASSWORD :: ";
                cin>>passwordd;
                cout<<endl<<endl;
                string query="SELECT password,name FROM registration where name = '"+namee+"' AND password = '"+passwordd+"' ";
                const char* qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                int validate=0;
                system("cls");
                if(row != 0)
                {
                    validate=1;
                    cout<<"                         --------------------------------------------------------------------------------------"<<endl;
                    cout<<"                         ---------------------------------VALIDATION DONE BY MANAGER---------------------------"<<endl;
                    cout<<"                         --------------------------------------------------------------------------------------"<<endl;

                    cout<<endl<<endl<<endl;
                    int i=0,totalfoodprice=0;
                     string query="SELECT totalfoodprice FROM foodorderdetails where bookingid = '"+bookingid+"' ";
                const char* qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                while((row=mysql_fetch_row(res))!=NULL)
                {

                    totalfoodprice=totalfoodprice+stoi(row[i]);
                   // i++;
                }
                query="SELECT phonenumber FROM bookingdetails where id = '"+bookingid+"' ";
                const char* qqqq=query.c_str();
                mysql_query(conn,qqqq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                string phnumber=row[0];

                query="SELECT stayduration FROM bookingdetails where id = '"+bookingid+"' ";
                const char* qqq=query.c_str();
                mysql_query(conn,qqq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                string result=row[0];
                int stay =stoi(result);
          //      cout<<"stay "<<stay<<endl;
                query="SELECT roomtype FROM bookingdetails where id = '"+bookingid+"' ";
                qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                string rtype=row[0];
            //    cout<<"rtype "<<rtype<<endl;
                query="SELECT roomrate FROM roomdetails where roomid = '"+rtype+"' ";
                qq=query.c_str();
                mysql_query(conn,qq);
                res = mysql_store_result(conn);
                row=mysql_fetch_row(res);
                string rate=row[0];

                int rrate=stoi(rate);



                        query= "SELECT emptyrooms FROM roomdetails where roomid = '"+rtype+"' ";
                        const char* uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);
                        row=mysql_fetch_row(res);
                        string up=*row;
                        int uemptyrooms=stoi(up);
                        uemptyrooms=uemptyrooms+1;
                        string uuemptyrooms=to_string(uemptyrooms);
                        query= "update roomdetails set emptyrooms ='"+uuemptyrooms+"' where roomid = '"+rtype+"' ";
                        uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);

//cout<<"discount2 "<<endl;
                        query="DELETE  FROM bookingdetails where id = '"+bookingid+"' ";
                        qq=query.c_str();
                        mysql_query(conn,qq);
                        res = mysql_store_result(conn);

                        query="DELETE  FROM foodorderdetails where bookingid = '"+bookingid+"' ";
                        qq=query.c_str();
                        mysql_query(conn,qq);
                        res = mysql_store_result(conn);

                        query= "SELECT count FROM discount where phonenumber = '"+phnumber+"' ";

                         uq=query.c_str();

                        mysql_query(conn,uq);

                        res = mysql_store_result(conn);

                        row=mysql_fetch_row(res);
                        int dis=0;
                        string cou="0";
                        if(row != 0)
                        {
                         cou=*row;
                        }

                        //cout<<"discount1 "<<endl;
                        int countt=stoi(cou);
                        //cout<<"discount1 "<<endl;
                        countt=countt+1;

                        if(countt>5)
                        {
                            dis=100;
                        }
                        if(countt>10)
                        {
                            dis=300;
                        }
                        if(countt>20)
                        {
                            dis=500;
                        }

                        string ccc=to_string(countt);
                        if(countt==1)
                        {
                            string cnt = to_string(countt);
                            string query = "INSERT INTO discount (discountid,phonenumber,count)  values ('','"+phnumber+"','"+cnt+"')";
                            const char* q=query.c_str();
                            qstate=mysql_query(conn,q);


                        }
                        //cout<<"discount "<<ccc<<endl;
                        query= "update discount set count ='"+ccc+"' where phonenumber = '"+phnumber+"' ";
                        uq=query.c_str();
                        mysql_query(conn,uq);
                        res = mysql_store_result(conn);


                        int totalroomprice=rrate*stay;
                        int x=totalroomprice+totalfoodprice-dis;
                        cout<<"------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
                        cout<<"                                                   Total room price= "<<totalroomprice<<"  total food price= "<<totalfoodprice<<endl;
                        cout<<"                                                   DISCOUNT:  "<<dis<<endl;
                        cout<<"                                                   Total payable amount = "<<x<<endl<<endl;
                        cout<<"------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
                }

                else
                {

                    cout<<"                      ------------------------------------------------------------------------------------"<<endl;
                    cout<<"                      -------------------------------------VALIDATION FAILED------------------------------"<<endl;
                    cout<<"                      ------------------------------------------------------------------------------------"<<endl;

                }
            }



}

int main()
{
    conn = mysql_init(0);
    conn = mysql_real_connect( conn , "192.168.43.184" , "bijit" , "1234" , "hms" , 0 , NULL , 0);
    int x=1;
    while(x==1)

{
        qstate = 0;
// stringstream ss;
cout<<endl<<endl;
cout<<"                                  *************************************************************************                "<<endl;
cout<<"                                  ******-------------- HOTEL MANAGEMENT SYSTEM ---------------*************                "<<endl;
cout<<"                                  *************************************************************************                "<<endl;
cout<<endl;
cout<<endl<<endl<<endl;
    int homepage=1;

cout<<"             PRESS '1' IF YOU WANT TO REGISTER A MANAGER         ";
cout<<endl;

cout<<endl;
cout<<"             PRESS '2' IF YOU WANT TO MAKE A BOOKING             ";
cout<<endl;

cout<<endl;
cout<<"             PRESS '3' IF YOU WANT TO ORDER FOOD                 ";
cout<<endl;

cout<<endl;
cout<<"             PRESS '4' IF YOU WANT TO CHECK-OUT           ";
cout<<endl;

cout<<endl;
cout<<"             PRESS TO CONTINUE----------------------------::";
cin>>homepage;
cout<<endl;
cout<<endl;

if(homepage!=1 && homepage!=2 && homepage!=3 && homepage!=4 )
{
    homepage=100;
}

//cout<<"dsncdskc"<<homepage<<endl;

if(homepage==1)

{
    //here manager registration function is called...........l
    registration();
}


if(homepage==2)
{
    //room availability checking and booking is done here...
    booking();
}


if(homepage==3)
{
    //food can be ordered ...
    food();
}


if(homepage==4)
{
    //final checkout.....
    checkout();
}


if(homepage==100)

{

    system("cls");

   cout<<endl<<endl<<endl<<endl;

   cout<<"---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR"<<endl<<endl<<endl;

   cout<<".........................................................PLEASE SELECT A VALID NUMBER.................................................................."<<endl<<endl<<endl;

   cout<<"---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR"<<endl;

    x=1;

    cout<<endl<<endl<<endl<<endl;
}
else
{
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;

    cout<<"                                 ---------------------------------------------------------------------------------"<<endl;
    cout<<"                                                       ___PRESS '1' IF YOU WANT TO GO TO HOME PAGE____             "<<endl;
    cout<<"                                 ---------------------------------------------------------------------------------"<<endl;

    cin>>x;
    system("cls");
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
}

}
    return 0;

}

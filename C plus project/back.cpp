
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
char ch;
class prestate
{

public:
    void autodelete(int a)
    {
        ifstream fp1;
        ofstream fp2;
        fp1.open("Record_File.txt", ios::in);
        fp2.open("temp.txt", ios::app);
        if (!fp1.is_open())
        {
            cout << "\n        ---- Cannot Opened ! ----   \n";
            exit(0);
        }
        if (!fp2.is_open())
        {
            cout << "\n        ---- Cannot Opened ! ----  \n";
            exit(0);
        }
        double file_num;
        string F_name, d_birth, b_place, fa_name, m_name, P_add, i_d;
        bool result = false;
        while (fp1 >> file_num)
        {
            fp1.ignore();
            getline(fp1, F_name);
            getline(fp1, d_birth);
            getline(fp1, b_place);
            getline(fp1, fa_name);
            getline(fp1, m_name);
            getline(fp1, P_add);
            getline(fp1, i_d);

            if (file_num == a)
            {
                cout << "\n\n        ---- Successfully Old Data Deleted ! ----\n\n  ";
                result = true;
                continue;
            }
            fp2 << file_num << endl;
            fp2 << F_name << endl;
            fp2 << d_birth << endl;
            fp2 << b_place << endl;
            fp2 << fa_name << endl;
            fp2 << m_name << endl;
            fp2 << P_add << endl;
            fp2 << i_d << endl
                << endl;
        }
        fp1.close();
        fp2.close();

        if (!result)
        {
            cout << "\n\n            ---- Number is Not Match for Delete ! ---- \n\n";
        }
    }

    void PasswordRecovery()
    {
        string name, passW, name1;
        string passW1 = "";
        int u = 0;
        ifstream fp;
        fp.open("account.txt", ios::in);
        if (!fp.is_open())
        {
            cout << "    ---- Unable to opened ! : ---- \n";
            exit(0);
        }
        fp >> name;
        fp >> passW;
        fp.close();
        while (1)
        {
            cout << "      Enter Username : ";
            cin >> name1;
            if (name1 == name)
            {
                ofstream fp2;
                fp2.open("account.txt", ios::out);
                if (!fp2.is_open())
                {
                    cout << "    ---- Unable to opened ! : ---- \n";
                    exit(0);
                }
                cout << "      Enter New Password : ";

                while ((ch = getch()) != '\r')
                {
                    if (ch == '\b')
                    {
                        if (!passW1.empty())
                        {
                            cout << "\b \b";
                            passW1.pop_back();
                        }
                    }
                    else
                    {
                        passW1.push_back(ch);
                        cout << "*";
                    }
                }

                fp2 << name << endl;
                fp2 << passW1 << endl;
                fp2.close();
                cout << "\n\n        ---- Successfully New Password is Create ! ----\n\n  ";
                break;
            }
            else
            {
                cout << "\n      ---- Username is not corrected ! ---- \n\n";
                u++;

                if (u == 3)
                {
                    cout << "\n          ---- You have Try more than 3 Times ! ---- \n\n";
                    exit(0);
                }
            }
        }
    }

    void newaccount()
    {

        string name;
        string password = "";
        ofstream fp;
        fp.open("account.txt", ios::out);
        if (!fp.is_open())
        {
            cout << "     ---- Sorry There is no Any file available ! ---- \n";
            exit(0);
        }
        cout << "         Enter the Username : ";
        cin >> name;
        fp << name << endl;
        cout << "         Enter the password : ";

        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!password.empty())
                {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else
            {
                password.push_back(ch);
                cout << "*";
            }
        }
        fp << password;
        fp.close();
        cout << "\n\n        --- Successfully New Account Is Created ! ---\n\n  ";
    }
    void passwordchange()
    {
        string name, passW, passN, passR = "";
        ifstream fp;
        fp.open("account.txt", ios::in);
        if (!fp.is_open())
        {
            cout << "    ---- Unable to opened ! : ---- \n";
            exit(0);
        }
        fp >> name;
        fp >> passW;
        fp.close();
        while (1)
        {
            cout << "      Enter New password : ";
            cin >> passN;
            cout << "      Enter Re-write New Password : ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (!passR.empty())
                    {
                        passR.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    passR.push_back(ch);
                    cout << "*";
                }
            }

            if (passN == passR)
            {
                ofstream fp2;
                fp2.open("account.txt", ios::out);
                if (!fp2.is_open())
                {
                    cout << "    ---- Unable to opened ! : ---- \n";
                    break;
                }

                fp2 << name << endl;
                fp2 << passN << endl;
                fp2.close();
                cout << "\n\n        ---- Successfully New Password is Created ! ----\n\n  ";
                break;
            }
            else
            {
                cout << "\n      ---- New and Re-write Password is not Match ! ---- \n\n";
            }
        }
    }

    void reset()
    {
        ofstream file;
        file.open("Record_File.txt", ios::out);
        if (!file.is_open())
        {
            cout << "\n             ---- Unable to opened a File ! ----\n";
            exit(0);
        }
        cout << "\n\n        ---- Successfully Reset Data ! ----\n\n  ";
        file.close();
    }

    void databackup()
    {
        ifstream fp1;
        ofstream fp2;
        fp1.open("Record_File.txt", ios::in);
        fp2.open("BackUp.txt", ios::app);

        if (!fp1.is_open())
        {
            cout << "\n             ---- Unable to opened a File ! ---- \n";
            exit(0);
        }
        if (!fp2.is_open())
        {
            cout << "\n             ---- Unable to opened a File ! ---- \n";
            exit(0);
        }
        string line;
        while (getline(fp1, line))
        {
            fp2 << line << endl;
        }
        fp1.close();
        fp2.close();
        cout << "\n\n        ---- Successfully Data are send to BackUp ! ----\n  ";
        cout << "        ---- Present Data in File delete automatically  ----\n  ";
        cout << "        ---- Because it Make data duplicated while using data backup again ----";
        reset();
    }

    void helpline()
    {
        ifstream fp;
        fp.open("helpline.txt", ios::in);
        if (!fp.is_open())
        {
            cout << "\n\n        ---- unable to opened ---- \n\n";
            exit(0);
        }
        string line;
        while (getline(fp, line))
        {
            cout << line << endl;
        }
    }

    void about()
    {
        ifstream fp;
        fp.open("About.txt", ios::in);
        if (!fp.is_open())
        {
            cout << "\n\n        ---- unable to opened ---- \n\n";
            exit(0);
        }
        string line;
        while (getline(fp, line))
        {
            cout << line << endl;
        }
    }
};

class Firstpart : public prestate
{

public:
    void displayhome()
    {
        int n, a;
        while (1)
        {
            cout << "\n\n\tDataSetUp (1) \t Helpline (2) \t  About Us (3) \t Setting (4) \t Exit (5) \n\n\n";
            cout << " Enter : ";
            cin >> n;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            if (n == 1)
            {
                while (1)
                {
                    cout << "\n\n\tData Upload (1) \t  Display Data (2) \t Update Data(3) \t Delete Data(4) \tExit (5) \n\n\n";
                    cout << "Enter : ";
                    cin >> a;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    if (a == 1)
                    {
                        string fullname, dataofbirth, p_address, Place_birth, I_date, Father, Mother;
                        double C_num;
                        ofstream file;
                        file.open("Record_File.txt", ios::app);
                        if (!file.is_open())
                        {
                            cout << "\n             ---- Unable to opened a File ! ---- \n";
                            exit(0);
                        }
                        cout << "           Citizenship Certificate NO. : ";
                        cin >> C_num;
                        cin.ignore(); // due to the newline \n present in cin
                        cout << "           Full Name : ";
                        getline(cin, fullname);
                        cout << "           Date Of Birth (BS)(YY-MM-DD) : ";
                        getline(cin, dataofbirth);
                        cout << "           Place of Birth : ";
                        getline(cin, Place_birth);
                        cout << "           Father Name : ";
                        getline(cin, Father);
                        cout << "           Mother Name : ";
                        getline(cin, Mother);
                        cout << "           Permanent Address : ";
                        getline(cin, p_address);
                        cout << "           Issue Date (BS) (YY-MM-DD) : ";
                        getline(cin, I_date);
                        file << C_num << endl;
                        file << fullname << endl;
                        file << dataofbirth << endl;
                        file << Place_birth << endl;
                        file << Father << endl;
                        file << Mother << endl;
                        file << p_address << endl;
                        file << I_date << endl
                             << endl;

                        file.close();

                        cout << "\n\n             ---- Data Uploaded Successfully ----  \n\n";
                    }
                    else if (a == 2)
                    {

                        ifstream file("Record_File.txt", ios::in);
                        if (!file)
                        {
                            cout << "     ---- Cannot open file ! ----";
                            exit(0);
                        }

                        double searchNum;
                        cout << "      citizenship Certificate NO. : ";
                        cin >> searchNum;

                        double file_num;
                        string F_name, d_birth, b_place, fa_name, m_name, P_add, i_d;
                        bool result = false;

                        while (file >> file_num)
                        {
                            file.ignore();

                            getline(file, F_name);
                            getline(file, d_birth);
                            getline(file, b_place);
                            getline(file, fa_name);
                            getline(file, m_name);
                            getline(file, P_add);
                            getline(file, i_d);

                            if (file_num == searchNum)
                            {
                                cout << "\n\n        ---- Citizenship Number Found ----\n\n  ";
                                cout << "         Citizenship Certificate NO. : " << file_num << endl;
                                cout << "           Full Name :  " << F_name << endl;
                                cout << "           Date Of Birth :  " << d_birth << endl;
                                cout << "           Birth Place :  " << b_place << endl;
                                cout << "           Father Name :  " << fa_name << endl;
                                cout << "           Mother Name :  " << m_name << endl;
                                cout << "           Permanent Address :  " << P_add << endl;
                                cout << "           Issue Date :  " << i_d << endl;
                                result = true;
                                break;
                            }
                        }
                        if (!result)
                        {

                            cout << "\n              ---- Sorry! No match found ---- \n\n";
                        }

                        file.close();
                    }
                    else if (a == 3)
                    {
                        double oldnum, newnum;
                        ifstream fp1;
                        fp1.open("Record_File.txt", ios::in);
                        if (!fp1.is_open())
                        {
                            cout << "        ---- Cannot Opened A file ! ---- " << endl;
                            exit(0);
                        }
                        cout << "     Enter Old CitizenShip NO : ";
                        cin >> oldnum;

                        double file_num;
                        string F_name, d_birth, b_place, fa_name, m_name, P_add, i_d;
                        bool res = false;
                        while (fp1 >> file_num)
                        {
                            fp1.ignore();
                            getline(fp1, F_name);
                            getline(fp1, d_birth);
                            getline(fp1, b_place);
                            getline(fp1, fa_name);
                            getline(fp1, m_name);
                            getline(fp1, P_add);
                            getline(fp1, i_d);

                            if (file_num == oldnum)
                            {
                                cout << "\n\n        ---- Citizenship Number Found ----\n\n  ";
                                ofstream fp2;
                                fp2.open("Record_File.txt", ios::app);
                                if (!fp2.is_open())
                                {
                                    cout << "\n      ---- cannot Opened ! ----  \n\n";
                                    exit(0);
                                }
                                cout << "     Enter new CitizenShip NO : ";
                                cin >> newnum;
                                fp2 << newnum << endl;
                                fp2 << F_name << endl;
                                fp2 << d_birth << endl;
                                fp2 << b_place << endl;
                                fp2 << fa_name << endl;
                                fp2 << m_name << endl;
                                fp2 << P_add << endl;
                                fp2 << i_d << endl
                                    << endl;
                                fp2.close();
                                autodelete(oldnum);
                                res = true;
                                break;
                            }
                        }
                        fp1.close();
                        if (!res)
                        {
                            cout << "\n              ---- Sorry! No match found ---- \n\n";
                        }
                        remove("Record_File.txt");
                        rename("temp.txt", "Record_File.txt");
                    }
                    else if (a == 4)
                    {
                        double num;
                        cout << "    Enter Citizenship No. for to delete Data : ";
                        cin >> num;
                        autodelete(num);
                        remove("Record_File.txt");
                        rename("temp.txt", "Record_File.txt");
                    }
                    else if (a == 5)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n    ---- wrong input ! ---- \n";
                    }
                }
            }
            else if (n == 2)
            {
                helpline();
            }
            else if (n == 3)
            {
                about();
            }
            else if (n == 4)
            {
                while (1)
                {
                    cout << "\n                                Password Change (1) \n";
                    cout << "                                Reset Data (2) \n";
                    cout << "                                Data Backup (3) \n";
                    cout << "                                Exit (4) \n\n\n";
                    int a;
                    cout << "  Enter : ";
                    cin >> a;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    if (a == 1)
                    {
                        ifstream f_1;
                        f_1.open("account.txt", ios::in);
                        if (!f_1.is_open())
                        {
                            cout << "\n\n             ---- unable to opened ! ---- \n\n";
                            exit(0);
                        }
                        string un1, userp1, userp2;
                        int C = 0;
                        while (1)
                        {

                            cout << "        Enter the Old Password : ";
                            cin >> userp1;
                            f_1 >> un1;
                            f_1 >> userp2;
                            if (userp1 == userp2)
                            {
                                passwordchange();
                                break;
                            }
                            else
                            {
                                cout << "\n\n           ---- wrong password ! ---- \n\n";
                                C++;
                                if (C == 3)
                                {
                                    while (1)
                                    {
                                        string ans;
                                        cout << "\n          -- Do You want to Recover a Password ? (yes/no) -- \n";
                                        cout << "     Enter : ";
                                        cin >> ans;
                                        if (ans == "Yes" || ans == "yes")
                                        {
                                            PasswordRecovery();
                                            break;
                                        }
                                        else if (ans == "No" || ans == "no")
                                        {
                                            cout << "\n\n         ---- Thank You ---- \n\n";
                                            exit(0);
                                        }
                                        else
                                        {
                                            cout << "\n\n       ---- wrong input ----    \n\n";
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (a == 2)
                    {
                        reset();
                    }
                    else if (a == 3)
                    {
                        databackup();
                    }
                    else if (a == 4)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n   ---- Wrong input ! ----  \n";
                    }
                }
            }
            else if (n == 5)
            {
                cout << "\n  ---- Software is closed ! ---- \n\n";
                break;
            }
            else
            {
                cout << "       \n   ---- worng input ! ----   \n";
            }
        }
    }
};

class secondpart : public Firstpart
{

    string name;
    string password = "";
    int c, n;

public:
    int login()
    {
        while (1)
        {
            cout << "\n                     Username (1)      \n";
            cout << "                     password (2)      \n";
            cout << "                     Login (3)      \n";
            cout << "                     Create New Account (4)     \n";
            cout << "                     Password Forget (5)      \n";
            cout << "                     Exit (6)     \n\n";

            cout << " Enter : ";
            cin >> n;

            if (cin.fail())
            {
                cin.clear();            // reset the fail state
                cin.ignore(1000, '\n'); // remove bad  input from the buffer
            }
            cout << endl;
            if (n == 1)
            {
                cout << "           Username : ";
                cin >> name;
                cin.ignore();
            }
            else if (n == 2)
            {
                char ch;
                cout << "           Password : ";
                while ((ch = getch()) != '\r')
                { // getch take input but is doesnot show in scrren  r mean it stop when user input enter btn
                    if (ch == '\b')
                    {
                        if (!password.empty())
                        {
                            cout << "\b \b";
                            password.pop_back();
                        }
                    }
                    else
                    {
                        password.push_back(ch);
                        cout << "*";
                    }
                }
                cout << "\n";
            }
            else if (n == 3)
            {
                ifstream fp;
                fp.open("account.txt", ios::in);
                if (!fp.is_open())
                {
                    cout << " ---- There No any file of record of Account ---- \n";
                    exit(0);
                }
                string username, usernum;
                fp >> username;
                fp >> usernum;
                fp.close();
                if (name == username && password == usernum)
                {
                    displayhome();
                    break;
                }
                else if (name == "iamuser" && password != usernum)
                {
                    cout << "\n       ---- Password is Wrong ----\n";
                    cout << "        ---- please Try Again ---- \n";
                }
                else
                {
                    cout << "\n    ---- Unauthorized Access ! (please Try Again) ---- \n";
                    c++;
                    if (c == 3)
                    {
                        cout << "\n    ---- You Have Try More 3 Times ---- \n\n";
                        exit(0);

                    }
                }
            }

            else if (n == 4)
            {
                newaccount();
            }
            else if (n == 5)
            {
                PasswordRecovery();
            }
            else if (n == 6)
            {
                return 0;
            }
            else
            {
                cout << " ---- Wrong input : ---\n";
            }
        }
    }
};

int main()
{

    secondpart s;
    s.login();
    // s.displayhome();

    return 0;
}
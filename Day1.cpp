
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>  // For prepared statements

using namespace std;
using namespace sql;

int main() {
    try {
        // Step 1: Create driver and connection objects
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "your_password"); // change username & password
        con->setSchema("testdb"); // database name

        // Step 2: Ensure table exists
        sql::Statement* stmt = con->createStatement();
        stmt->execute("CREATE TABLE IF NOT EXISTS student (id INT PRIMARY KEY, name VARCHAR(50))");
        delete stmt;

        // Step 3: Ask user for input
        int id;
        string name;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore(); // clear newline from buffer
        cout << "Enter Student Name: ";
        getline(cin, name);

        // Step 4: Insert data using Prepared Statement (safer)
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO student(id, name) VALUES(?, ?)");
        pstmt->setInt(1, id);
        pstmt->setString(2, name);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Data inserted successfully!" << endl;

        // Step 5: Fetch and display all data
        stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM student");

        cout << "\n📋 Student Table Data:\n";
        while (res->next()) {
            cout << "ID = " << res->getInt("id")
                 << ", Name = " << res->getString("name") << endl;
        }

        // Cleanup
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException& e) {
        cerr << "❌ SQL Error: " << e.what() << endl;
    }

    return 0;
}

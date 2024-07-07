#include"MYSQL.h"

manage::manage() {};
manage::~manage() {};

void manage::init() {

    mysql_init(&mysql);
    
};
bool manage::connect() {

    if (!mysql_real_connect(&mysql, host, user, pass, db, 3306, 0, 0)) {

        cout << "数据库连接失败" << mysql_error(&mysql) << endl;
        return false;

    }
    else {

        cout << "数据库连接成功" << endl;
        return true;

    }

};

void manage::close() {

    mysql_close(&mysql);
    mysql_library_end();
    cout << "数据库已关闭" << endl;

}



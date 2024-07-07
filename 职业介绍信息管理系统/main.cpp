#include"MYSQL.h"
#include"lib.h"
#include"menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);//设置utf-8字符集
    SetConsoleCP(CP_UTF8);

    cout << "欢迎使用职业介绍信息管理系统" << endl;
    main_menu();
    
    return 0;
}
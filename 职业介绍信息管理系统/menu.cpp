#include"menu.h"

void show_main_menu() {

    cout << "---------------------------------------" << endl;
    cout << "*             1、增加数据             *" << endl;
    cout << "*             2、删除数据             *" << endl;
    cout << "*             3、修改数据             *" << endl;
    cout << "*             4、查找数据             *" << endl;
    cout << "*             5、存储过程             *" << endl;
    cout << "*             6、算法实现             *" << endl;
    cout << "*             0、退出系统             *" << endl;
    cout << "---------------------------------------" << endl;
    
}

void main_menu() {

    int chose = 0;
    show_main_menu();
    while (true) {
        cin >> chose;
        if (chose >= 0 && chose <= 6) {
            switch (chose) {

            case 1:insert_menu(); break;
            case 2:delete_menu(); break;
            case 3:update_menu(); break;
            case 4:select_menu(); break;
            case 5:num_demand_get(); break;
            case 6:method(); break;
            case 0:exit(); break;

            }
        }
        else {

            cout << "输入有误，请重新输入" << endl;
            continue;

        }
    }
}

void exit() {

    cout << "感谢使用职业介绍信息管理系统" << endl;
    exit(0);

}

void stop() {

    system("pause");

}

void num_demand_get() {

    system("cls");
    cout << "存储过程格式 :" << "get_num_demand(in id, out num, out demand)" << endl;
    int id = 0;
    cout << "请输入id :";
    cin >> id;
    eims_manage::getInstance()->get_num_demand(id);
    stop();
    system("cls");
    show_main_menu();
}

void show_lib_menu() {

    system("cls");
    cout << "请选择要操作的表" << endl;
    vector<string>table;
    table.push_back("hum"); table.push_back("jw"); table.push_back("oc"); table.push_back("oim"); table.push_back("pay"); table.push_back("unit");
    cout << "eims" <<"\t0、返回上一级菜单" << endl;
    for (int i = 0; i < 6; i++) {

        cout << "\t" <<i+1<<"、" << table[i];
        if ((i+1) % 3 == 0) { cout << endl; }

    }

    cout << endl;
}

void insert_menu() {

    int chose = 0;
    show_lib_menu();
    while (true) {
        cin >> chose;
        if (chose >= 0 && chose <= 6) {
            switch (chose) {

            case 1:insert_hum(); break;
            case 2:insert_jw(); break;
            case 3:insert_oc(); break;
            case 4:insert_oim(); break;
            case 5:insert_pay(); break;
            case 6:insert_unit(); break;
            case 0:main_menu(); break;

            }
        }
        else {

            cout << "输入有误，请重新输入" << endl;
            continue;

        }
    }
}

void delete_menu() {

    int chose = 0;
    show_lib_menu();
    while (true) {
        cin >> chose;
        if (chose >= 0 && chose <= 6) {
            switch (chose) {

            case 1:delete_hum(); break;
            case 2:delete_jw(); break;
            case 3:delete_oc(); break;
            case 4:delete_oim(); break;
            case 5:delete_pay(); break;
            case 6:delete_unit(); break;
            case 0:main_menu(); break;

            }
        }
        else {

            cout << "输入有误，请重新输入" << endl;
            continue;

        }
    }
}

void update_menu() {

    int chose = 0;
    show_lib_menu();
    while (true) {
        cin >> chose;
        if (chose >= 0 && chose <= 6) {
            switch (chose) {

            case 1:update_hum(); break;
            case 2:update_jw(); break;
            case 3:update_oc(); break;
            case 4:update_oim(); break;
            case 5:update_pay(); break;
            case 6:update_unit(); break;
            case 0:main_menu(); break;

            }
        }
        else {

            cout << "输入有误，请重新输入" << endl;
            continue;

        }
    }

}

void select_menu() {
    
    int chose = 0;
    show_lib_menu();
    while (true) {
        cin >> chose;
        if (chose >= 0 && chose <= 6) {
            switch (chose) {

            case 1:select_hum(); break;
            case 2:select_jw(); break;
            case 3:select_oc(); break;
            case 4:select_oim(); break;
            case 5:select_pay(); break;
            case 6:select_unit(); break;
            case 0:main_menu(); break;

            }
        }
        else {

            cout << "输入有误，请重新输入" << endl;
            continue;

        }
    }
}


//hum
void insert_hum() {

    system("cls");
    int id; int OC_id; int unit_id; string name; string sex; string state;
    cout << "hum输入格式 :" << endl;
    cout << "hum_id (int 主键)"; cin >> id; cout << endl;
    cout << "hum_OC_id (int 外键OC)"; cin >> OC_id; cout << endl;
    cout << "hum_unit_id (int 外键unit)"; cin >> unit_id; cout << endl;
    cout << "hum_name (string)"; cin >> name; cout << endl;
    cout << "hum_sex (string 男/女)"; cin >> sex; cout << endl;
    cout << "hum_state (string 未聘用/成功聘用 填入NULL即为默认值未聘用)"; cin >> state; cout << endl;
    if (state == "NULL") {
        hum temp(id, OC_id, unit_id, name, sex);
        hum_manage::getInstance()->hum_insert(temp);
    }
    else {
        hum temp(id, OC_id, unit_id, name, sex, state);
        hum_manage::getInstance()->hum_insert(temp);
    }
    stop();
    show_lib_menu();
}
void delete_hum() {

    system("cls");
    int id; vector<hum>res;
    res = hum_manage::getInstance()->hum_select("");
    hum_manage::getInstance()->hum_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    hum_manage::getInstance()->hum_delete(id);
    stop();
    show_lib_menu();
}
void update_hum() {

    system("cls");
    int id; int OC_id; int unit_id; string name; string sex; string state;
    cout << "hum输入格式 :" << endl;
    cout << "hum_id (int 主键)"; cin >> id; cout << endl;
    cout << "hum_OC_id (int 外键OC)"; cin >> OC_id; cout << endl;
    cout << "hum_unit_id (int 外键unit)"; cin >> unit_id; cout << endl;
    cout << "hum_name (string)"; cin >> name; cout << endl;
    cout << "hum_sex (string 男/女)"; cin >> sex; cout << endl;
    cout << "hum_state (string 未聘用/成功聘用 填入NULL即为默认值未聘用)"; cin >> state; cout << endl;
    if (state == "NULL") {
        hum temp(id, OC_id, unit_id, name, sex);
        hum_manage::getInstance()->hum_update(temp);
    }
    else {
        hum temp(id, OC_id, unit_id, name, sex, state);
        hum_manage::getInstance()->hum_update(temp);
    }
    stop();
    show_lib_menu();
}
void select_hum() {

    system("cls");
    string condition; vector<hum>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = hum_manage::getInstance()->hum_select("");
        hum_manage::getInstance()->hum_print(res);
    }
    else {
        res = hum_manage::getInstance()->hum_select(condition);
        hum_manage::getInstance()->hum_print(res);
    }
    stop();
    show_lib_menu();
}

//jw
void insert_jw() {

    system("cls");
    int id; int OIM_id; int hum_id; string state;
    cout << "jw输入格式 :" << endl;
    cout << "JW_id (int 主键)"; cin >> id; cout << endl;
    cout << "JW_OIM_id (int 外键OIM)"; cin >> OIM_id; cout << endl;
    cout << "JW_hum_id (int 外键hum)"; cin >> hum_id; cout << endl;
    cout << "JW_state (string 未聘用/成功聘用 填入NULL即为默认值未聘用)"; cin >> state; cout << endl;
    if (state == "NULL") {
        jw temp(id, OIM_id, hum_id);
        jw_manage::getInstance()->jw_insert(temp);
    }
    else {
        jw temp(id, OIM_id, hum_id, state);
        jw_manage::getInstance()->jw_insert(temp);
    }
    stop();
    show_lib_menu();
}
void delete_jw() {

    system("cls");
    int id; vector<jw>res;
    res = jw_manage::getInstance()->jw_select("");
    jw_manage::getInstance()->jw_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    jw_manage::getInstance()->jw_delete(id);
    stop();
    show_lib_menu();
}
void update_jw() {

    system("cls");
    int id; int OIM_id; int hum_id; string state;
    cout << "jw输入格式 :" << endl;
    cout << "JW_id (int 主键)"; cin >> id; cout << endl;
    cout << "JW_OIM_id (int 外键OIM)"; cin >> OIM_id; cout << endl;
    cout << "JW_hum_id (int 外键hum)"; cin >> hum_id; cout << endl;
    cout << "JW_state (string 未聘用/成功聘用 填入NULL即为默认值未聘用)"; cin >> state; cout << endl;
    if (state == "NULL") {
        jw temp(id, OIM_id, hum_id);
        jw_manage::getInstance()->jw_update(temp);
    }
    else {
        jw temp(id, OIM_id, hum_id, state);
        jw_manage::getInstance()->jw_update(temp);
    }
    stop();
    show_lib_menu();
}
void select_jw() {

    system("cls");
    string condition; vector<jw>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = jw_manage::getInstance()->jw_select("");
        jw_manage::getInstance()->jw_print(res);
    }
    else {
        res = jw_manage::getInstance()->jw_select(condition);
        jw_manage::getInstance()->jw_print(res);
    }
    stop();
    show_lib_menu();
}

//oc
void insert_oc() {
    
    system("cls");
    int id; string name;
    cout << "oc输入格式 :" << endl;
    cout << "OC_id (int 主键)"; cin >> id; cout << endl;
    cout << "OC_name (string)"; cin >> name; cout << endl;
    oc temp(id, name);
    oc_manage::getInstance()->oc_insert(temp);
    stop();
    show_lib_menu();
}
void delete_oc() {

    system("cls");
    int id; vector<oc>res;
    res = oc_manage::getInstance()->oc_select("");
    oc_manage::getInstance()->oc_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    oc_manage::getInstance()->oc_delete(id);
    stop();
    show_lib_menu();
}
void update_oc() {

    system("cls");
    int id; string name;
    cout << "oc输入格式 :" << endl;
    cout << "OC_id (int 主键)"; cin >> id; cout << endl;
    cout << "OC_name (string)"; cin >> name; cout << endl;
    oc temp(id, name);
    oc_manage::getInstance()->oc_update(temp);
    stop();
    show_lib_menu();
}
void select_oc() {

    system("cls");
    string condition; vector<oc>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = oc_manage::getInstance()->oc_select("");
        oc_manage::getInstance()->oc_print(res);
    }
    else {
        res = oc_manage::getInstance()->oc_select(condition);
        oc_manage::getInstance()->oc_print(res);
    }
    stop();
    show_lib_menu();
}

//oim
void insert_oim() {

    system("cls");
    int id; int OC_id; int unit_id; int num; int demand; string comment;
    cout << "oim输入格式 :" << endl;
    cout << "OIM_id (int 主键)"; cin >> id; cout << endl;
    cout << "OIM_OC_id (int 外键OC)"; cin >> OC_id; cout << endl;
    cout << "OIM_unit_id (int 外键unit)"; cin >> unit_id; cout << endl;
    cout << "OIM_num (int)"; cin >> num; cout << endl;
    cout << "OIM_demand (int)"; cin >> demand; cout << endl;
    cout << "OIM_comment (string 填入NULL即为默认值空)"; cin >> comment; cout << endl;
    if (comment == "NULL") {
        oim temp(id, OC_id, unit_id, num, demand);
        oim_manage::getInstance()->oim_insert(temp);
    }
    else {
        oim temp(id, OC_id, unit_id, num, demand, comment);
        oim_manage::getInstance()->oim_insert(temp);
    }
    stop();
    show_lib_menu();
}
void delete_oim() {

    system("cls");
    int id; vector<oim>res;
    res = oim_manage::getInstance()->oim_select("");
    oim_manage::getInstance()->oim_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    oim_manage::getInstance()->oim_delete(id);
    stop();
    show_lib_menu();
}
void update_oim() {

    system("cls");
    int id; int OC_id; int unit_id; int num; int demand; string comment;
    cout << "oim输入格式 :" << endl;
    cout << "OIM_id (int 主键)"; cin >> id; cout << endl;
    cout << "OIM_OC_id (int 外键OC)"; cin >> OC_id; cout << endl;
    cout << "OIM_unit_id (int 外键unit)"; cin >> unit_id; cout << endl;
    cout << "OIM_num (int)"; cin >> num; cout << endl;
    cout << "OIM_demand (int)"; cin >> demand; cout << endl;
    cout << "OIM_comment (string 填入NULL即为默认值空)"; cin >> comment; cout << endl;
    if (comment == "NULL") {
        oim temp(id, OC_id, unit_id, num, demand);
        oim_manage::getInstance()->oim_update(temp);
    }
    else {
        oim temp(id, OC_id, unit_id, num, demand, comment);
        oim_manage::getInstance()->oim_update(temp);
    }
    stop();
    show_lib_menu();
}
void select_oim() {

    system("cls");
    string condition; vector<oim>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = oim_manage::getInstance()->oim_select("");
        oim_manage::getInstance()->oim_print(res);
    }
    else {
        res = oim_manage::getInstance()->oim_select(condition);
        oim_manage::getInstance()->oim_print(res);
    }
    stop();
    show_lib_menu();
}

//pay
void insert_pay() {

    system("cls");
    int id; int unit_id; int hum_id; int num; string date;
    cout << "pay输入格式 :" << endl;
    cout << "pay_id (int 主键)"; cin >> id; cout << endl;
    cout << "pay_unit_id (int 外键)"; cin >> unit_id; cout << endl;
    cout << "pay_hum_id (int 外键)"; cin >> hum_id; cout << endl;
    cout << "pay_num (int)"; cin >> num; cout << endl;
    cout << "pay_date (string xxxx-xx-xx)"; cin >> date; cout << endl;
    pay temp(id, unit_id, hum_id, num, date);
    pay_manage::getInstance()->pay_insert(temp);
    stop();
    show_lib_menu();
}
void delete_pay() {

    system("cls");
    int id; vector<pay>res;
    res = pay_manage::getInstance()->pay_select("");
    pay_manage::getInstance()->pay_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    pay_manage::getInstance()->pay_delete(id);
    stop();
    show_lib_menu();
}
void update_pay() {

    system("cls");
    int id; int unit_id; int hum_id; int num; string date;
    cout << "pay输入格式 :" << endl;
    cout << "pay_id (int 主键)"; cin >> id; cout << endl;
    cout << "pay_unit_id (int 外键)"; cin >> unit_id; cout << endl;
    cout << "pay_hum_id (int 外键)"; cin >> hum_id; cout << endl;
    cout << "pay_num (int)"; cin >> num; cout << endl;
    cout << "pay_date (string xxxx-xx-xx)"; cin >> date; cout << endl;
    pay temp(id, unit_id, hum_id, num, date);
    pay_manage::getInstance()->pay_update(temp);
    stop();
    show_lib_menu();
}
void select_pay() {

    system("cls");
    string condition; vector<pay>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = pay_manage::getInstance()->pay_select("");
        pay_manage::getInstance()->pay_print(res);
    }
    else {
        res = pay_manage::getInstance()->pay_select(condition);
        pay_manage::getInstance()->pay_print(res);
    }
    stop();
    show_lib_menu();
}

//unit
void insert_unit() {

    system("cls");
    int id; string name; string tel;
    cout << "unit输入格式 :" << endl;
    cout << "unit_id (int 主键)"; cin >> id; cout << endl;
    cout << "unit_name (string)"; cin >> name; cout << endl;
    cout << "unit_tel (string 11位)"; cin >> tel; cout << endl;
    unit temp(id, name, tel);
    unit_manage::getInstance()->unit_insert(temp);
    stop();
    show_lib_menu();
}
void delete_unit() {

    system("cls");
    int id; vector<unit>res;
    res = unit_manage::getInstance()->unit_select("");
    unit_manage::getInstance()->unit_print(res);
    cout << "根据id删除 :"; cin >> id; cout << endl;
    unit_manage::getInstance()->unit_delete(id);
    stop();
    show_lib_menu();
}
void update_unit() {

    system("cls");
    int id; string name; string tel;
    cout << "unit输入格式 :" << endl;
    cout << "unit_id (int 主键)"; cin >> id; cout << endl;
    cout << "unit_name (string)"; cin >> name; cout << endl;
    cout << "unit_tel (string 11位)"; cin >> tel; cout << endl;
    unit temp(id, name, tel);
    unit_manage::getInstance()->unit_update(temp);
    stop();
    show_lib_menu();
}
void select_unit() {

    system("cls");
    string condition; vector<unit>res;
    cout << "查询条件 (以WHERE开头后接条件输入NULL即查询全部) :"; cin >> condition; cout << endl;
    if (condition == "NULL") {
        res = unit_manage::getInstance()->unit_select("");
        unit_manage::getInstance()->unit_print(res);
    }
    else {
        res = unit_manage::getInstance()->unit_select(condition);
        unit_manage::getInstance()->unit_print(res);
    }
    stop();
    show_lib_menu();
}

//method
void method() {

    system("cls");
    vector<pay>res;
    res = pay_manage::getInstance()->pay_select("");
    cout << "基于双路快速排序排列实现缴费表按金额升序排列 :" << endl;
    cout << "排序前 :" << endl;
    pay_manage::getInstance()->pay_print(res);
    quickSort(res, 0, res.size() - 1);
    cout << "排序后 :" << endl;
    pay_manage::getInstance()->pay_print(res);
    stop();
    system("cls");
    show_main_menu();
}
//双路快速排序
void quickSort(vector<pay>& list, int left, int right) {
    if (left >= right) {
        return;
    }

    int l = left, r = right;
    int p = list[(left + right) / 2].pay_num;

    while (l <= r) {
        while (list[l].pay_num < p) {
            l++;
        }

        while (list[r].pay_num > p) {
            r--;
        }

        if (l <= r) {
            swap(list[l], list[r]);
            l++;
            r--;
        }
    }
    quickSort(list, left, r);
    quickSort(list, l, right);
}
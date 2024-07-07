#include"lib.h"

//eims
eims_manage::eims_manage() {};
eims_manage::~eims_manage() {};
void eims_manage::get_num_demand(int id) {

    int res;
    char sql[256];

    init();
    if (connect()) {

        //设置变量 
        sprintf_s(sql, 256, "SET @id = %d", id);
        res = mysql_query(&mysql, sql);
        if( res !=0){
            
            cout << "变量设置失败" << endl;
            cout << mysql_error(&mysql) << endl;
        
        }
        else { cout << "变量设置成功" << endl;}
        //调用存储过程
        strcpy_s(sql, strlen("CALL get_num_demand(@id,@num,@demand)")+1, "CALL get_num_demand(@id,@num,@demand)");
        res = mysql_query(&mysql, sql);
        if (res != 0) {

            cout << "存储过程调用失败" << endl;
            cout << mysql_error(&mysql) << endl;

        }
        else { cout << "存储过程调用成功" << endl;}
        //获取存储过程结果集
        strcpy_s(sql, strlen("SELECT @num,@demand") + 1, "SELECT @num,@demand");
        res = mysql_query(&mysql, sql);
        if (res != 0) {

            cout << "获取存储过程结果失败" << endl;
            cout << mysql_error(&mysql) << endl;

        }
        else {
            cout << "获取存储过程结果成功" << endl;
            MYSQL_RES* result = mysql_store_result(&mysql);
            cout << "结果为 : ";
            MYSQL_ROW row = mysql_fetch_row(result);
            cout << "\t num = " << row[0];
            cout << "\t demand = " << row[1];
            cout << endl;

            mysql_free_result(result);
        
        }

    }
    else {

        close();
        return;

    }

    close();

}

//OC
oc::oc(int id, string name) {

    OC_id = id;
    OC_name = name;

};
oc::oc() {};
oc::~oc() {};
oc_manage::oc_manage() {};
oc_manage::~oc_manage() {};

void oc_manage::oc_insert(oc &OC) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO oc (OC_id , OC_name) VALUES(%d, '%s')", OC.OC_id, OC.OC_name.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void oc_manage::oc_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM oc WHERE OC_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void oc_manage::oc_update(oc& OC) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE oc SET OC_name ='%s' WHERE OC_id = %d", OC.OC_name.c_str(), OC.OC_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<oc>oc_manage::oc_select(string condition) {

    vector<oc>ocList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM oc %s", condition.c_str());

    }
    else {

        close();
        return vector<oc>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        oc OC;
        OC.OC_id = atoi(row[0]);
        OC.OC_name = row[1];

        ocList.push_back(OC);
    }
    mysql_free_result(res);
    close();
    return ocList;

}

void oc_manage::oc_print(vector<oc>OC) {

    if (OC.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "oc" << "\t" << "OC_id" << "\t\t" << "oc_name" << "\t" << endl;
        for (vector<oc>::iterator it = OC.begin(); it != OC.end(); ++it) {

            cout << "\t" << it->OC_id << "\t\t" << it->OC_name << "\t";
            cout << endl;

        }
        cout << endl;

    }
    
}

//unit
unit::unit(int id, string name, string tel) {

    unit_id = id;
    unit_name = name;
    unit_tel = tel;

};
unit::unit() {};
unit::~unit() {};
unit_manage::unit_manage() {};
unit_manage::~unit_manage() {};

void unit_manage::unit_insert(unit& unit) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO unit (unit_id , unit_name, unit_tel) VALUES(%d, '%s', '%s')", unit.unit_id, unit.unit_name.c_str(),unit.unit_tel.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void unit_manage::unit_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM unit WHERE unit_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void unit_manage::unit_update(unit& unit) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE unit SET unit_name ='%s', unit_tel ='%s' WHERE unit_id = %d", unit.unit_name.c_str(), unit.unit_tel.c_str(), unit.unit_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<unit>unit_manage::unit_select(string condition) {

    vector<unit>unitList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM unit %s", condition.c_str());

    }
    else {

        close();
        return vector<unit>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        unit unit;
        unit.unit_id = atoi(row[0]);
        unit.unit_name = row[1];
        unit.unit_tel = row[2];

        unitList.push_back(unit);
    }
    mysql_free_result(res);
    close();
    return unitList;

}

void unit_manage::unit_print(vector<unit>_unit) {

    if (_unit.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "unit" << "\t" << "unt_id" << "\t\t" << "unit_name" << "\t\t" << "unit_tel" << "\t" << endl;
        for (vector<unit>::iterator it = _unit.begin(); it != _unit.end(); ++it) {

            cout << "\t" << it->unit_id << "\t\t" << it->unit_name << "\t\t\t" << it->unit_tel << "\t";
            cout << endl;

        }
        cout << endl;

    }

}

//hum
hum::hum(int id, int OC_id, int unit_id, string name, string sex, string state) {

    hum_id = id;
    hum_OC_id = OC_id;
    hum_unit_id = unit_id;
    hum_name = name;
    hum_sex = sex;
    hum_state = state;

};
hum::hum(int id, int OC_id, int unit_id, string name, string sex) {

    hum_id = id;
    hum_OC_id = OC_id;
    hum_unit_id = unit_id;
    hum_name = name;
    hum_sex = sex;

};
hum::hum() {};
hum::~hum() {};
hum_manage::hum_manage() {};
hum_manage::~hum_manage() {};

void hum_manage::hum_insert(hum& hum) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO hum (hum_id , hum_OC_id, hum_unit_id, hum_name, hum_sex, hum_state) VALUES(%d, %d, %d, '%s', '%s', '%s')",
            hum.hum_id, hum.hum_OC_id, hum.hum_unit_id, hum.hum_name.c_str(), hum.hum_sex.c_str(), hum.hum_state.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void hum_manage::hum_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM hum WHERE hum_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void hum_manage::hum_update(hum& hum) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE hum SET hum_OC_id =%d, hum_unit_id =%d, hum_name ='%s', hum_sex ='%s', hum_state ='%s' WHERE hum_id = %d",
            hum.hum_OC_id, hum.hum_unit_id, hum.hum_name.c_str(), hum.hum_sex.c_str(), hum.hum_state.c_str(), hum.hum_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<hum>hum_manage::hum_select(string condition) {

    vector<hum>humList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM hum %s", condition.c_str());

    }
    else {

        close();
        return vector<hum>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        hum hum;
        hum.hum_id = atoi(row[0]);
        hum.hum_OC_id = atoi(row[1]);
        hum.hum_unit_id = atoi(row[2]);
        hum.hum_name = row[3];
        hum.hum_sex = row[4];
        hum.hum_state = row[5];

        humList.push_back(hum);
    }
    mysql_free_result(res);
    close();
    return humList;

}

void hum_manage::hum_print(vector<hum>_hum) {

    if (_hum.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "hum" << "\t" << "hum_id" << "\t\t" << "hum_OC_id" << "\t\t" << "hum_unit_id" << "\t\t" << "hum_name" << "\t\t" << "hum_sex" << "\t\t" << "hum_state" << "\t" << endl;
        for (vector<hum>::iterator it = _hum.begin(); it != _hum.end(); ++it) {

            cout << "\t" << it->hum_id << "\t\t" << it->hum_OC_id << "\t\t\t" << it->hum_unit_id << "\t\t\t" << it->hum_name << "\t\t\t" << it->hum_sex << "\t\t" << it->hum_state << "\t";
            cout << endl;

        }
        cout << endl;

    }

}

//pay
pay::pay(int id, int unit_id, int hum_id, int num, string date) {

    pay_id = id;
    pay_unit_id = unit_id;
    pay_hum_id = hum_id;
    pay_num = num;
    pay_date = date;

}
pay::pay() {};
pay::~pay() {};
pay_manage::pay_manage() {};
pay_manage::~pay_manage() {};

void pay_manage::pay_insert(pay& pay) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO pay (pay_id , pay_unit_id, pay_hum_id, pay_num, pay_date) VALUES(%d, %d, %d, %d, '%s')",
            pay.pay_id, pay.pay_unit_id, pay.pay_hum_id, pay.pay_num, pay.pay_date.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void pay_manage::pay_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM pay WHERE pay_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void pay_manage::pay_update(pay& pay) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE pay SET pay_unit_id =%d, pay_hum_id =%d, pay_num =%d, pay_date ='%s' WHERE pay_id = %d",
            pay.pay_unit_id, pay.pay_hum_id, pay.pay_num, pay.pay_date.c_str(), pay.pay_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<pay>pay_manage::pay_select(string condition) {

    vector<pay>payList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM pay %s", condition.c_str());

    }
    else {

        close();
        return vector<pay>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        pay pay;
        pay.pay_id = atoi(row[0]);
        pay.pay_unit_id = atoi(row[1]);
        pay.pay_hum_id = atoi(row[2]);
        pay.pay_num = atoi(row[3]);
        pay.pay_date = row[4];
        
        payList.push_back(pay);
    }
    mysql_free_result(res);
    close();
    return payList;

}

void pay_manage::pay_print(vector<pay>_pay) {

    if (_pay.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "pay" << "\t" << "pay_id" << "\t\t" << "pay_unit_id" << "\t\t" << "pay_hum_id" << "\t\t" << "pay_num" << "\t\t" << "pay_date" << "\t" << endl;
        for (vector<pay>::iterator it = _pay.begin(); it != _pay.end(); ++it) {

            cout << "\t" << it->pay_id << "\t\t" << it->pay_unit_id << "\t\t\t" << it->pay_hum_id << "\t\t\t" << it->pay_num << "\t\t" << it->pay_date << "\t";
            cout << endl;

        }
        cout << endl;

    }

}

//oim
oim::oim(int id, int OC_id, int unit_id, int num, int demand, string comment) {

    OIM_id = id;
    OIM_OC_id = OC_id;
    OIM_unit_id = unit_id;
    OIM_num = num;
    OIM_demand = demand;
    OIM_comment = comment;

}
oim::oim(int id, int OC_id, int unit_id, int num, int demand) {

    OIM_id = id;
    OIM_OC_id = OC_id;
    OIM_unit_id = unit_id;
    OIM_num = num;
    OIM_demand = demand;

}
oim::oim() {};
oim::~oim() {};
oim_manage::oim_manage() {};
oim_manage::~oim_manage() {};

void oim_manage::oim_insert(oim& OIM) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO oim (OIM_id , OIM_OC_id, OIM_unit_id, OIM_num, OIM_demand, OIM_comment) VALUES(%d, %d, %d, %d, %d, '%s')",
            OIM.OIM_id, OIM.OIM_OC_id, OIM.OIM_unit_id, OIM.OIM_num, OIM.OIM_demand, OIM.OIM_comment.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void oim_manage::oim_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM oim WHERE OIM_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void oim_manage::oim_update(oim& OIM) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE oim SET OIM_OC_id =%d, OIM_unit_id =%d, OIM_num =%d, OIM_demand =%d, OIM_comment ='%s' WHERE OIM_id = %d",
            OIM.OIM_OC_id, OIM.OIM_unit_id, OIM.OIM_num, OIM.OIM_demand, OIM.OIM_comment.c_str(), OIM.OIM_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<oim>oim_manage::oim_select(string condition) {

    vector<oim>oimList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM oim %s", condition.c_str());

    }
    else {

        close();
        return vector<oim>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        oim OIM;
        OIM.OIM_id = atoi(row[0]);
        OIM.OIM_OC_id = atoi(row[1]);
        OIM.OIM_unit_id = atoi(row[2]);
        OIM.OIM_num = atoi(row[3]);
        OIM.OIM_demand = atoi(row[4]);
        OIM.OIM_comment = row[5];

        oimList.push_back(OIM);
    }
    mysql_free_result(res);
    close();
    return oimList;

}

void oim_manage::oim_print(vector<oim>OIM) {

    if (OIM.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "oim" << "\t" << "OIM_id" << "\t\t" << "OIM_OC_id" << "\t\t" << "OIM_unit_id" << "\t\t" << "OIM_num" << "\t\t" << "OIM_demand" << "\t\t" << "OIM_comment" << "\t" << endl;
        for (vector<oim>::iterator it = OIM.begin(); it != OIM.end(); ++it) {

            cout << "\t" << it->OIM_id << "\t\t" << it->OIM_OC_id << "\t\t\t" << it->OIM_unit_id << "\t\t\t" << it->OIM_num << "\t\t" << it->OIM_demand << "\t\t" << it->OIM_comment << "\t";
            cout << endl;

        }
        cout << endl;

    }

}

//jw
jw::jw(int id,int OIM_id, int hum_id, string state) {

    JW_id = id;
    JW_OIM_id = OIM_id;
    JW_hum_id = hum_id;
    JW_state = state;

}
jw::jw(int id,int OIM_id, int hum_id) {

    JW_id = id;
    JW_OIM_id = OIM_id;
    JW_hum_id = hum_id;

}
jw::jw() {};
jw::~jw() {};
jw_manage::jw_manage() {};
jw_manage::~jw_manage() {};

void jw_manage::jw_insert(jw& JW) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "INSERT INTO jw (JW_id, JW_OIM_id , JW_hum_id, JW_state) VALUES(%d, %d, %d, '%s')", JW.JW_id, JW.JW_OIM_id, JW.JW_hum_id, JW.JW_state.c_str());

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据插入失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据插入成功" << endl; }
    close();

}

void jw_manage::jw_delete(int id) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "DELETE FROM jw WHERE JW_id = %d", id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据删除失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据删除成功" << endl; }
    close();

}

void jw_manage::jw_update(jw& JW) {

    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "UPDATE jw SET JW_OIM_id = %d, JW_hum_id = %d, JW_state = '%s' WHERE JW_id = %d", JW.JW_OIM_id, JW.JW_hum_id, JW.JW_state.c_str(), JW.JW_id);

    }
    else {

        close();
        return;

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据更新失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据更新成功" << endl; }
    close();

}

vector<jw>jw_manage::jw_select(string condition) {

    vector<jw>jwList;
    char sql[256];
    init();
    if (connect()) {

        sprintf_s(sql, 256, "SELECT * FROM jw %s", condition.c_str());

    }
    else {

        close();
        return vector<jw>();

    }
    if (mysql_query(&mysql, sql)) {

        cout << "数据查询失败 " << mysql_error(&mysql) << endl;

    }
    else { cout << "数据查询成功" << endl; }

    MYSQL_RES* res = mysql_store_result(&mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {

        jw JW;
        JW.JW_id = atoi(row[0]);
        JW.JW_OIM_id = atoi(row[1]);
        JW.JW_hum_id = atoi(row[2]);
        JW.JW_state = row[3];

        jwList.push_back(JW);
    }
    mysql_free_result(res);
    close();
    return jwList;

}

void jw_manage::jw_print(vector<jw>JW) {

    if (JW.empty()) {

        cout << "数据为空" << endl;

    }
    else {

        cout << "jw" << "\t" << "JW_id" << "\t\t" << "JW_OIM_id" << "\t\t" << "JW_hum_id" << "\t\t" << "JW_state" << "\t" << endl;
        for (vector<jw>::iterator it = JW.begin(); it != JW.end(); ++it) {

            cout << "\t" << it->JW_id << "\t\t" << it->JW_OIM_id << "\t\t\t" << it->JW_hum_id << "\t\t\t" << it->JW_state << "\t";
            cout << endl;

        }
        cout << endl;

    }

}
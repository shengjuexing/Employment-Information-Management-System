#pragma once
#include<iostream>
#include<string>
#include"MYSQL.h"
#include<vector>
using namespace std;

class eims_manage : public manage {
public:

    eims_manage();
    ~eims_manage();

    static eims_manage* getInstance() {

        static eims_manage eims_manage;
        return &eims_manage;

    }

    void get_num_demand(int id);

};


class oc {
public:

    oc(int id, string name);
    oc();
    ~oc();
    int OC_id;
    string OC_name;
};
class oc_manage:public manage {
public:

    oc_manage();
    ~oc_manage();
    static oc_manage* getInstance() {

        static oc_manage oc_manage;
        return &oc_manage;

    } //单例模式

    void oc_insert(oc& OC);
    void oc_delete(int id);
    void oc_update(oc& OC);
    vector<oc> oc_select(string condition);
    void oc_print(vector<oc>OC);
};

class unit {
public:

    unit(int id,string name,string tel);
    unit();
    ~unit();
    int unit_id;
    string unit_name;
    string unit_tel;
};
class unit_manage :public manage {
public:

    unit_manage();
    ~unit_manage();
    static unit_manage* getInstance() {
        
        static unit_manage unit_manage;
        return &unit_manage;

    }

    void unit_insert(unit& unit);
    void unit_delete(int id);
    void unit_update(unit& unit);
    vector<unit> unit_select(string condition);
    void unit_print(vector<unit>_unit);
};

class hum {
public:

    hum(int id,int OC_id,int unit_id,string name,string sex,string state);
    hum(int id, int OC_id, int unit_id, string name, string sex);
    hum();
    ~hum();

    int hum_id;
    int hum_OC_id;
    int hum_unit_id;
    string hum_name;
    string hum_sex;
    string hum_state = "未聘用";
};
class hum_manage:public manage {
public:

    hum_manage();
    ~hum_manage();
    static hum_manage* getInstance() {

        static hum_manage hum_manage;
        return &hum_manage;

    }

    void hum_insert(hum& hum);
    void hum_delete(int id);
    void hum_update(hum& hum);
    vector<hum>hum_select(string condition);
    void hum_print(vector<hum>_hum);
};

class pay {
public:

    pay();
    pay(int id, int unit_id, int hum_id, int num, string date);
    ~pay();

    int pay_id;
    int pay_unit_id;
    int pay_hum_id;
    int pay_num;
    string pay_date;
};

class pay_manage :public manage {
public:

    pay_manage();
    ~pay_manage();

    static pay_manage* getInstance() {

        static pay_manage pay_manage;
        return &pay_manage;

    }

    void pay_insert(pay& pay);
    void pay_delete(int id);
    void pay_update(pay& pay);
    vector<pay>pay_select(string condition);
    void pay_print(vector<pay>_pay);
};

class oim {
public:

    oim(int id,int OC_id,int unit_id,int num,int demand,string comment);
    oim(int id, int OC_id, int unit_id, int num, int demand);
    oim();
    ~oim();

    int OIM_id;
    int OIM_OC_id;
    int OIM_unit_id;
    int OIM_num;
    int OIM_demand;
    string OIM_comment = "";
};

class oim_manage :public manage {
public:

    oim_manage();
    ~oim_manage();

    static oim_manage* getInstance() {

        static oim_manage oim_manage;
        return &oim_manage;

    }

    void oim_insert(oim& OIM);
    void oim_delete(int id);
    void oim_update(oim& OIM);
    vector<oim> oim_select(string condition);
    void oim_print(vector<oim>OIM);
};

class jw {
public:

    jw(int JW_id, int OIM_id, int hum_id, string state);
    jw(int JW_id, int OIM_id, int hum_id);
    jw();
    ~jw();

    int JW_id;
    int JW_OIM_id;
    int JW_hum_id;
    string JW_state = "未聘用";
};

class jw_manage :public manage {
public:

    jw_manage();
    ~jw_manage();

    static jw_manage* getInstance() {

        static jw_manage jw_manage;
        return &jw_manage;

    }

    void jw_insert(jw& JW);
    void jw_delete(int id1);
    void jw_update(jw& JW);
    vector<jw> jw_select(string condition);
    void jw_print(vector<jw>JW);
};
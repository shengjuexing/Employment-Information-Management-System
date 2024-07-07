#pragma once
#include<iostream>
#include<string>
#include"lib.h"
using namespace std;

void show_main_menu();
void main_menu();
void exit();
void stop();
void show_lib_menu();
void insert_menu();
void delete_menu();
void update_menu();
void select_menu();
void method();
void quickSort(vector<pay>& list, int left, int right);
void num_demand_get();

//insert
void insert_hum();
void insert_jw();
void insert_oc();
void insert_oim();
void insert_pay();
void insert_unit();
//delete
void delete_hum();
void delete_jw();
void delete_oc();
void delete_oim();
void delete_pay();
void delete_unit();
//update
void update_hum();
void update_jw();
void update_oc();
void update_oim();
void update_pay();
void update_unit();
//select
void select_hum();
void select_jw();
void select_oc();
void select_oim();
void select_pay();
void select_unit();

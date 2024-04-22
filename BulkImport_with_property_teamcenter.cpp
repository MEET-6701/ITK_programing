#include<tc/tc_startup.h>
#include<tccore/item.h>
#include<tccore/aom.h>
#include<tccore/aom_prop.h>
#include<tccore/tctype.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int ITK_user_main(int argc, char** argv) {
	int s = 0;
	ifstream file("C://Users//DELL//Desktop//first.csv");
	string line;
	char* col1;
	char* col2;
	char* col3;

	while (getline(file, line)) {
		istringstream ss(line);
		string token;


		getline(ss, token, ',');

		col1 = new char[token.length() + 1];
		strcpy(col1, token.c_str());

		getline(ss, token, ',');
		col2 = new char[token.length() + 1];
		strcpy(col2, token.c_str());

		getline(ss, token, ',');
		col3 = new char[token.length() + 2];
		strcpy(col3, token.c_str());

		cout << "Column 1: " << col1 << ", Column 2: " << col2 << endl;



		s = TC_init_module("infodba", "infodba", "dba");

		if (s != ITK_ok) {
			cout << "Login Faild\n";
		}

		tag_t bo_type, bo, create_input, rev, datasettype, new_dataset, relation_type, relation, home, user;

		s = TCTYPE_find_type("Item", "Item", &bo_type);
		s = TCTYPE_construct_create_input(bo_type, &create_input);
		s = AOM_set_value_string(create_input, "item_id", col1);
		s = AOM_set_value_string(create_input, "object_name", col2);
		s = AOM_set_value_string(create_input, "object_desc", col3);
		s = TCTYPE_create_object(create_input, &bo);
		s = AOM_save_with_extensions(bo);
	}
	return s;

}
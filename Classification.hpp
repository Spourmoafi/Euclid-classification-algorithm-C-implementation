#ifndef Classification_hpp
#define Classification_hpp

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include "Table.hpp"
using namespace std;
class Classification{
    int accuracy;vector<vector<double>> data;
    
protected:
    
public:
    
    
    Classification(){};
    bool is_K_larger_Learning_Data(int k);
    void checkMatches_R_C();
    bool Is_Lerngdata_Cols_Match_Data_Cols();
    bool Is_Lerng_data_Rows_Match_Lear_Data_Label_Rows();
    float Euclidean(int k);
    float Manhattan(int k);
    void Classification_Read_CSV(string st_file,string nd_file,string rd_file,string th_file);
    void printFiles();
    
    Table obj;
    
    
    
    
    
};
#endif0

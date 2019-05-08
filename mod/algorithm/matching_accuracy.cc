 #include "mod/algorithm/passby_matching.h"
 #include "mod/algorithm/matching_accuracy.h"
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <sstream>
 #include <string>
namespace mod{
 bool equCompare(struct MatchingResult matching ,struct MatchingResult output){
        if(matching.edge_id == output.edge_id)
          return true;
        else
          return false;
   }   
   
 double MatchingAccuracy::getMatchingAccuracy(std::vector<struct MatchingResult>& matching_results_,const std::string& file){
        std::ifstream infile;
        std::string temp;
        infile.open(file.c_str());
        if (!infile.is_open()){
            std::cout << "未成功打开文件" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::vector<struct MatchingResult> output_results_;
        while(getline(infile,temp)) {
	    struct MatchingResult o_result_;
            sscanf(temp.c_str(),"%d%*c%d%*c",&o_result_.p_index,&o_result_.edge_id);
	    output_results_.push_back(o_result_);
            if(infile.eof())
                    break;
        }
	int equ = 0,a_num = 0;	
	std::vector<int>  accuracy_result_;
		for(int i = 0;i<matching_results_.size();i++){
		    equ = (int)equCompare(matching_results_[i],output_results_[i]);
		    if(equ)
			a_num++;
		    accuracy_result_.push_back(equ);		
		}
	printf("a_num的个数：%d",a_num);
	double r_matching = (a_num*1.0)/ matching_results_.size();
        return r_matching;

  }
}

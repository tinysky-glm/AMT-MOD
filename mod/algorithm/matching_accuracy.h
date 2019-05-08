
 #pragma once
 #include "mod/algorithm/passby_matching.h"
 #include <vector>
 #include  <string>
 namespace mod{
    class MatchingAccuracy{
        public:
		MatchingAccuracy(){};
		double getMatchingAccuracy(std::vector<struct MatchingResult>& matching_results_,const std::string& file);            
    };
}

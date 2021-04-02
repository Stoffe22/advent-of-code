#include <string>
#include <vector>
#include <map>
#include <boost/tuple/tuple.hpp>

using namespace std;

void loadInstructions(const string& file, vector<map<int, boost::tuple<enum instruction, int>>>* instructions);
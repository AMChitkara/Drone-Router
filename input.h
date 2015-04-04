//Project 4, EECS 281
//Programmer: Audrey Chitkara
//Started: November 17, 2014
//Submitted: 

#ifndef INPUT_H
#define INPUT_H

using namespace std; 

struct facility 
{
    int X_coord; 
    int Y_coord; 
    int facilityNumber; 
    bool visited; 
};

struct path 
{
    facility lower_fcty; 
    facility higher_fcty;
    double distance;      
};


class pathComparator 
{
    public: 
        pathComparator(); 
        bool operator() (path x, path y) 
        {
            //true if x has LOWER priority than y
            if (x.distance > y.distance) 
            {
                return true; 
            }
            else return false; 
        }
};

/*class finalPathComparator 
{
public: 
	finalPathComparator(); 
	bool operator() (path x, path y) 
    {
		if (x.lower_fcty.facilityNumber > y.lower_fcty.facilityNumber) 
        {
			return true; 
		}
		else return false; 
	}

}; */

int inputA(std::unordered_map<int, facility> &facilityMap, 
			std::priority_queue<path, std::deque<path>, pathComparator> &paths, 
            int &num_facilities, int &num_paths);

void MST(std::priority_queue<path, std::deque<path>, pathComparator> &paths, 
    std::priority_queue<path, std::deque<path>, pathComparator> &finalPath, int &num_facilities); 

/*deque<facility> facilities; 

struct pathmap {
    priority_queue<double, deque<path>, pathComparator> paths;     
        //arranged by distance. min distance = highest priority. 
};*/


#endif

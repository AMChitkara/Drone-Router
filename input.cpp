//Project 4, EECS 281
//Programmer: Audrey Chitkara
//Started: November 17, 2014
//Submitted: 

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string> 
#include <deque>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sstream> 
#include <functional>
#include <algorithm>
#include <list>
#include <vector>
#include <math.h>

#include "input.h"

using namespace std; 

pathComparator::pathComparator() {}
//finalPathComparator::finalPathComparator() {}; 


//REQUIRES: paths is full, finalPath is empty, num_faciltiies > 0.
//MODIFIES: finalPath.
//EFFECTS:  fills finalPath with the first num_facilities - 1 paths in paths.
//          finalPath is arranged in order of lowest facility number. 
void MST(priority_queue<path, deque<path>, pathComparator> &paths,
        priority_queue<path, deque<path>, pathComparator> &finalPath, 
        int &num_facilities) 
{
	//create path out of the minimum distance queues. 
	//push into new path, sorted by lowest facility number to highest facility number.
	double totaldist = 0; 
    vector<int> v; 
    for (int i = 0; i < num_facilities; ++i)
    {
        v.push_back(i);  
    }
	int count = 0; 
    for (int j = 0; j < num_facilities - 1; ++j) 
    {
        //check if paths.top() creates a cycle with what has already been added to the finalPath
        if (v[paths.top().lower_fcty.facilityNumber] != v[paths.top().higher_fcty.facilityNumber])
        {
            count++; 
            finalPath.push(paths.top());
            for (int i = 0; i < num_facilities; ++i)
            {
                if (v[i] == v[paths.top().higher_fcty.facilityNumber])
                {
                    v[i] = v[paths.top().lower_fcty.facilityNumber]; 
                }  
            }
            totaldist += paths.top().distance;
            paths.pop();
        }
        else 
        {
            paths.pop(); 
            num_facilities++; 
        }
	}
	cout << totaldist << '\n'; 
	
    for (int k = 0; k < num_facilities - 1; ++k) 
    {
		cout << finalPath.top().lower_fcty.facilityNumber << " " << finalPath.top().higher_fcty.facilityNumber; 
        cout << " " << finalPath.top().distance; 
		finalPath.pop(); 
		if (k != num_facilities) 
        {
			cout << '\n'; 
		}
	}
}

//REQUIRES: 
//MODIFIES: 
//EFFECTS: 
int inputA(unordered_map<int, facility> &facilityMap, priority_queue <path, deque<path>, pathComparator> &paths, 
            int &num_facilities, int &num_paths) 
{
    string junk; 
    int x, y = 0;
    int facilityNumber = 0; 
    double distance; 

    string inputstream; 
    getline(cin, inputstream); 
    stringstream parser; 
    parser << inputstream; 
    parser >> junk >> num_facilities; 
    parser.clear(); 
    
    //input facility coordinates
    for (int i = 0; i < num_facilities; ++i) 
    {
        getline(cin, inputstream); 
        parser << inputstream; 
        parser >> x >> y;  
        facility f1;
        facilityNumber = i; 
        f1.facilityNumber = i; 
        f1.X_coord = x; 
        f1.Y_coord = y; 
        f1.visited = false; 
        facilityMap[facilityNumber] = f1;  
        parser.clear(); 
    }

    getline(cin, inputstream); 
    parser << inputstream; 
    string newJunk; 
    parser >> newJunk >> num_paths; 
    parser.clear(); 

    //input path numbers
    for (int j = 0; j < num_paths; ++j)
    {
        path p1; 
        int startFacility; 
        int endFacility; 
        getline(cin, inputstream); 
        parser << inputstream; 
        parser >> startFacility >> endFacility; 
        //cout << "start facility: " << startFacility << '\n'; 
        //cout << "end facility: " << endFacility << '\n'; 
        
        int x1 = facilityMap[startFacility].X_coord; 
        int y1 = facilityMap[startFacility].Y_coord; 
        int x2 = facilityMap[endFacility].X_coord; 
        int y2 = facilityMap[endFacility].Y_coord; 

        double x = (x1 - x2) * (x1 - x2); 
        double y = (y1 - y2) * (y1 - y2); 
	
        distance = sqrt(x + y); 
        //cout << distance << '\n'; 
        p1.lower_fcty = facilityMap[startFacility]; 
        p1.higher_fcty = facilityMap[endFacility]; 
        p1.distance = distance; 
        paths.push(p1); 
        parser.clear(); 
    }

    return num_facilities; 

}


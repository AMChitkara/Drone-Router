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


#include "getopt.h"
#include "input.h"

using namespace std; 

int main(int argc, char **argv) 
{
    const struct option longOpts[] = 
    {
        {"clientType",	required_argument,	0,	'c'},
        {"help",		no_argument,		0,	'h'}
    }; 

    int index; 
    int opt = 0; 
    opterr = 1; 
    char CLIENT_TYPE = 'Z'; 

    while ((opt = getopt_long(argc, argv, "c:h", longOpts, &index)) != EOF) 
    {
        switch(opt)
        {
            case 'c': 
                if (*optarg == 'A' || *optarg == 'B' || *optarg == 'C')
                {
                    CLIENT_TYPE = *optarg; 
                }
                else 
                {
                    cerr << "Error: Client Type must equal A, B or C." << endl; 
                    exit(1);
                }
            break; 

            case 'h': 
                cout << "Need help? This program accepts the following:\n";
                cout << "  -c, --clientType      Specify what type of client should run\n";
                cout << "  -h, --help            Prints help information\n";            
                exit(0); 
            break; 

            case '?': 
                cerr << "Error" << endl; 
                exit(1); 
            break; 
        }
    }

    //need a map of facilities because they need to be accessible by their numbers. 
    //need a priority queue of paths because they need to be arranged by their distances.

    unordered_map<int, facility> facilityMap; 
    priority_queue<path, deque<path>, pathComparator> paths;     
    priority_queue<path, deque<path>, pathComparator> finalPath; 
    int num_facilities = 0; 
    int num_paths = 0; 

    if (CLIENT_TYPE == 'A') 
    {
        inputA(facilityMap, paths, num_facilities, num_paths); 
        MST(paths, finalPath, num_facilities);
    }

    else if (CLIENT_TYPE == 'B') 
    {
        cout << "B!" << endl; 
    }

    else if (CLIENT_TYPE == 'C') 
    {
        cout << "C!" << endl; 
    }

    return 0;

}

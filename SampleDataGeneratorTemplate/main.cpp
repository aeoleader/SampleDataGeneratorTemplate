//
//  main.cpp
//  SampleDataGeneratorTemplate
//
//  Created by Xiangyu on 02/11/2016.
//  Copyright © 2016 jxkj. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile;
    ofstream outfile("/Users/jxkj/Desktop/PlayGround/CGALTest/test_data.in");
    //infile.open("", ios::in);
    //outfile.open("test_data.in", ios::out);
    
    if (outfile.is_open())
    {
        //Write Data here
        
        
        outfile.close();
    }
    
    return 0;
}

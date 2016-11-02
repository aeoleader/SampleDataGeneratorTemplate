//
//  main.cpp
//  SampleDataGeneratorTemplate
//
//  Created by Xiangyu on 02/11/2016.
//  Copyright © 2016 jxkj. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <random>
#include <map>
#include <iomanip>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
using namespace std;
//MODE 0 to use std random number generator
//     1 to use boost random number generator

#define MODE 1
boost::mt19937 rng;
float gen_random_float(float min, float max)
{
    
    boost::uniform_real<float> u(min, max);
    boost::variate_generator<boost::mt19937&, boost::uniform_real<float> > gen(rng, u);
    return gen();
}

void generatePoints(ofstream& outfile)
{
#if MODE == 0
    random_device rd;
    
    //
    // Engines
    //
    //mt19937 e2(rd());
    //std::knuth_b e2(rd());
    std::default_random_engine e2(rd()) ;
    
    //
    // Distribtuions
    //
    uniform_real_distribution<> dist(0, 100);
    //std::normal_distribution<> dist(2, 2);
    //std::student_t_distribution<> dist(5);
    //std::poisson_distribution<> dist(2);
    //std::extreme_value_distribution<> dist(0,2);
    
    map<int, double> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::floor(dist(e2))];
    }
    //outfile << "hello";
    for (auto p : hist) {
        outfile << fixed << setprecision(4) << setw(3)
        << p.first << ' '<< std::string(p.second/100, '*') << ' ' << p.second/100 << '\n';
    }
#endif
#if MODE == 1
    for (int i = 0; i < 100; i++)
    {
        outfile << fixed << setprecision(4) << setw(3)
        << gen_random_float(0.0f, 1.0f) << endl
        << gen_random_float(0.0f, 1.0f) << endl
        << gen_random_float(0.0f, 1.0f) << endl;
    }
#endif
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile;
    ofstream outfile("/Users/jxkj/Desktop/PlayGround/CGALTest/test_data.in");
    //infile.open("", ios::in);
    //outfile.open("test_data.in", ios::out);
    
    if (outfile.is_open())
    {
        //Write Data here
        
        generatePoints(outfile);
        outfile.close();
    }
    
    return 0;
}

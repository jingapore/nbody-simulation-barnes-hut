#include "inputparser.h"

#include <iostream>


bool InputParser::parse(int argc, char** argv){

    static const char * opt_string = "s:t:d:G:f:vo:i:T:R:r:q:";
    int in;

    opterr = 0;
    try{
        while((in = getopt(argc, argv, opt_string)) != -1){
            switch(in){
                case 's':
                    steps = std::stoi(optarg);
                    break;
                case 'd':
                    dt = std::stod(optarg);
                    break;
                case 't':
                    theta = std::stod(optarg);
                    break;
                case 'G':
                    g = std::stod(optarg);
                    break;
                case 'i':
                    readfile = true;
                    in_fn = optarg;
                    break;
                case 'o':
                    save_positions = true;
                    out_fn = optarg;
                    break;
                case 'v':
                    verb = true;
                    break;
                case 'T':
                    out_time_fn = optarg;
                    clock = true;
                    break;
                case 'r':
                    save_tree = true;
                    out_tree_fn = optarg;
                    break;
                case 'R':
                    save_tree_size = true;
                    out_tree_size_fn = optarg;
                    break;
                case 'q':
                    summarize = true;
                    summary_fn = optarg;
                    break;
                default:
                    return false;
            }
        }
    }
    catch(std::exception const & e){
        return false;
    }
    return true;
}

void print_usage(int argc, char ** argv){
    std::cout << "usage: mpirun -np P ";
    std::cout << argv[0];
    std::cout << " [-s S] [-t ∆t] [-i ∆i]";
    std::cout << " [-a θ] [-G g] [-T] [-o outfile]";
    std::cout << " [-r outfile] [-f infile] [-v] [-q outfile]" << std::endl;
    std::cout << "\t -s S \t \t simulate for S number of steps (default is 100)" << std::endl;
    std::cout << "\t -d ∆t \t \t take time steps of ∆t (default is 1)" << std::endl;
    std::cout << "\t -a θ \t \t Barnes-Hut approximation parameter (default is 0.5)" << std::endl;
    std::cout << "\t -G g \t \t gravitational constant (default is 0.001)" << std::endl;
    std::cout << "\t -T outfile \t measure the running time and write to outfile" << std::endl;
    std::cout << "\t -o outfile \t output file for bodies" << std::endl;
    std::cout << "\t -r outfile \t output file for tree" << std::endl;
    std::cout << "\t -R outfile \t output file for tree size" << std::endl;
    std::cout << "\t -f infile \t input file with initial conditions." << std::endl;
    std::cout << "\t -v \t \t verbose program" << std::endl;
    std::cout << "\t -q outfile \t output summary to outfile" << std::endl;
}


double InputParser::grav_constant(){
    return g;
}

double InputParser::bh_approx_constant(){
    return theta;
}

bool InputParser::read_bodies(){
    return readfile;
}

std::string InputParser::in_file(){
    return in_fn;
}


int InputParser::n_steps(){
    return steps;
}


double InputParser::time_step(){
    return dt;
}

bool InputParser::verbose(){
    return verb;
}

bool InputParser::write_positions(){
    return save_positions; 
}

std::string InputParser::out_file(){
    return out_fn;
}

bool InputParser::clock_run(){
    return clock;
}

std::string InputParser::out_time_file(){
    return out_time_fn;
}

bool InputParser::write_tree(){
    return save_tree; 
}

std::string InputParser::out_tree_file(){
    return out_tree_fn;
}

bool InputParser::write_tree_size(){
    return save_tree_size;
}

std::string InputParser::out_tree_size_file(){
    return out_tree_size_fn;
}

bool InputParser::write_summary(){
    return summarize;
}

std::string InputParser::out_sum_file(){
    return summary_fn;
}

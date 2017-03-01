#include <ecl/ecl.h>
#include <sstream>
#include <iostream>

#include "ui.h"
#include "engine.h"
using namespace std;

cl_object ecl_eval(const string &call) {
    return cl_safe_eval(c_string_to_object(call.c_str()), Cnil, Cnil);
}

void start_ecl(int argc, char **argv) {

    cl_boot(argc, argv);
    atexit(cl_shutdown);

    stringstream ss;
    ss << "(load \"" << argv[1] << "\")";
    string command = ss.str();

    cout << "Loading lisp file: " << command << endl;

    ecl_eval(command);
    ecl_eval("(lisp_hello)");
}

int main(int argc, char *argv[]) {
    start_ecl(argc, argv);

    auto lisp_val = ecl_to_float(ecl_eval("(lisp_sum 7 11)"));
    stringstream result_str;
    result_str << "Result: " << lisp_val << endl;

//    ogl_w(&result_str);

    // Declare an instance of Engine
    Engine engine;

    // Start the engine
    engine.start();

    // for (int counter = 0; counter < 20; counter++)
    // {
    //   sleep(1);
    // }

    return 0;
}
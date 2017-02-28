#include <ecl/ecl.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <iostream>

#include "ui.h"

cl_object ecl_eval(const std::string &call) {
    return cl_safe_eval(c_string_to_object(call.c_str()), Cnil, Cnil);
}

void start_ecl(int argc, char **argv) {

    cl_boot(argc, argv);
    atexit(cl_shutdown);

    std::stringstream ss;
    ss << "(load \"" << argv[1] << "\")";
    std::string command = ss.str();

    std::cout << "Loading lisp file: " << command << std::endl;

    ecl_eval(command);
    ecl_eval("(lisp_hello)");
}

int main(int argc, char *argv[]) {
    start_ecl(argc, argv);

    auto lisp_val = ecl_to_float(ecl_eval("(lisp_sum 7 11)"));
    std::stringstream result_str;
    result_str << "Result: " << lisp_val << std::endl;

    ogl_w(&result_str);

    // for (int counter = 0; counter < 20; counter++)
    // {
    //   sleep(1);
    // }

    return 0;
}
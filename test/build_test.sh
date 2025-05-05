#!/usr/bin/bash

# Makefile compile settings

CXX="g++"
CXX_FLAGS="-std=c++11 -c"
CXX_FILES="test.cpp"
CXX_LDFLAGS="-o"
CXX_INCLUDE="-I../src/ -I."
CXX_EXEC="test_run.elf"







# local Makefile strings

main_makefile_string="
CXX=$CXX
CXXFLAGS=$CXX_FLAGS
LDFLAGS=$CXX_LDFLAGS
INCLUDE=$CXX_INCLUDE

TEST_MODULE=$CXX_EXEC

SRC=$CXX_FILES
OBJ=\$(SRC:.cpp=.o)

.PHONY: build clean

\$(TEST_MODULE): \$(OBJ)
\t\$(CXX) \$^ \$(LDFLAGS) \$@

build: \$(TEST_MODULE)
\techo \"Build \$^ [OK]\"

clean:
\trm \$(TEST_MODULE) \$(OBJ)

"

add_makefile_cpp_module_build_string="\t\$(CXX)  \$(INCLUDE) \$(CXXFLAGS) \$^
"




function FillMakefile {
    fill_pattern=$main_makefile_string

    for i in $CXX_FILES
    do
        new_cpp_module_proc=$(echo -e "$(echo $i | sed s/.cpp/.o/):$i\n$add_makefile_cpp_module_build_string")

        fill_pattern=$(echo -e "$fill_pattern\n\n$new_cpp_module_proc")
    done

    echo "$fill_pattern" > Makefile
}

function BuildTestModule {
    current_dir=$(pwd)

    if echo "$current_dir" | grep "sorting-benchmark/test"
    then
        touch Makefile
        FillMakefile
        make build
    else
        echo "Your dir $current_dir not \`sorting-benchmark/test\`"
    fi
}

function ClearTestModule {
    current_dir=$(pwd)

    if echo "$current_dir" | grep "sorting-benchmark/test"
    then
        if [ -e Makefile ]
        then
            make clean
            rm Makefile
        fi
    else
        echo "Your dir $current_dir not \`sorting-benchmark/test\`"
    fi
}


function MainModule {
    if [ -n "$2" ]
    then
        echo "Error: invalid count of arguments, expected 1 (one) argument, use \`-B\` or \`-D\`"
    elif [ "$1" = "-B" ]
    then
        echo "Start build test module"
        BuildTestModule
    elif [ "$1" = "-D" ]
    then
        echo "Clear test module"
        ClearTestModule
    elif [ -n "$1" ]
    then
        echo "Error: unexpected argument, use \`-B\` or \`-D\`"
    else
        echo "Error: expected 1 (one) argument, use \`-B\` or \`-D\`"
    fi
}

MainModule $1 $2


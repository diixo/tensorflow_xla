
cmake_minimum_required (VERSION 2.8)

project (tensorflow-prj-vs2015)

# Set compiler flags and options. 
if(MSVC) # MSVC compiler (Win32 only)
    # Display more warnings
    set(CMAKE_CXX_FLAGS "/W3")
elseif(UNIX OR CMAKE_COMPILER_IS_GNUCXX) # Clang OR Gcc (Linux, Mac OS or Win32 with MingW)
    # Enable C++11 and displays all warnings
    set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
    if(APPLE) # Clang / Mac OS only
        # Required on OSX to compile c++11
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -mmacosx-version-min=10.7")
    endif(APPLE)
endif()

# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

# Sub-directories where more CMakeLists.txt exist
add_subdirectory (google)

# Set include-directory
# include_directories(${INCLUDE_DIRS})

set (SOURCE_TENSOR_NN 

   arithmetic.cc 
   array2d.cc 
   bitmap.cc 
   client_library_test_base.cc 
   computation.cc 
   computation_builder.cc 
   core_status.cc 
   #cpu_info.cc 
   default_logging.cc 
   env_time.cc 
   global_data.cc 
   hash.cc 
   image.cc 
   image_loader.cc 
   literal_test_util.cc 
   numbers.cc 
   padding.cc 
   primitive_util.cc 
   reference_util.cc 
   statusor.cc 
   status_macros.cc 
   strcat.cc 
   stringpiece.cc 
   stringprintf.cc 
   str_util.cc 
   test_helpers.cc 

   util.cc 
   window_util.cc 
   xla_data.pb.cc 
   
   index_util.cc 
   layout_util.cc 
   layout_util_flags.cc 
   literal_util.cc 
   shape_util.cc 
   )

   
add_library (lib_tensor_nn STATIC ${SOURCE_TENSOR_NN})

set (SOURCE_TESTS 

   array2d_test.cc 
   array3d_test.cc 
   array4d_test.cc 
   convolution_test.cc 
   convolution_variants_test.cc 
   index_util_test.cc 
   literal_util_test.cc 
   math_util_test.cc 
   util_test.cc 
   
   padding_test.cc 
   pad_test.cc 
   reduce_window_test.cc 
   pooling_test.cpp 
   reference_util_test.cc 
   reshape_test.cc 
   select_and_scatter_test.cc 
   shape_util_test.cc 
   )


set (SOURCE_EXE 
   Main.cpp
   ${SOURCE_TESTS}
   )

add_executable (tensor_nn ${SOURCE_EXE})

target_link_libraries (tensor_nn 
   lib_tensor_nn
   lib_google_protobuf
   )

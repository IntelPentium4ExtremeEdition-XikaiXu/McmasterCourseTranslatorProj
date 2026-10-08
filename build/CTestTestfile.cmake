# CMake generated Testfile for 
# Source directory: /home/xikaixu/Development/McmasterCourseTranslatorProj
# Build directory: /home/xikaixu/Development/McmasterCourseTranslatorProj/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[core]=] "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/test_core")
set_tests_properties([=[core]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/xikaixu/Development/McmasterCourseTranslatorProj/CMakeLists.txt;32;add_test;/home/xikaixu/Development/McmasterCourseTranslatorProj/CMakeLists.txt;0;")
subdirs("third_party/whisper.cpp")

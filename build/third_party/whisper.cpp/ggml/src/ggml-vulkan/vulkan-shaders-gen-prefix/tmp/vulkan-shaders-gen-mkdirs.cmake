# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src/vulkan-shaders-gen-build"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/tmp"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src/vulkan-shaders-gen-stamp"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src"
  "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src/vulkan-shaders-gen-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src/vulkan-shaders-gen-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/xikaixu/Development/McmasterCourseTranslatorProj/build/third_party/whisper.cpp/ggml/src/ggml-vulkan/vulkan-shaders-gen-prefix/src/vulkan-shaders-gen-stamp${cfgdir}") # cfgdir has leading slash
endif()

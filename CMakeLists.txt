cmake_minimum_required(VERSION 3.15)

set(CMAKE_STANDARD_CXX 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE main.cpp nfiqlib.c)

add_executable(Nfiq ${SOURCE})

target_include_directories(Nfiq PRIVATE include/)

target_link_libraries(Nfiq
        ${CMAKE_SOURCE_DIR}/lib/libnfseg.a
        ${CMAKE_SOURCE_DIR}/lib/libimage.a
        ${CMAKE_SOURCE_DIR}/lib/libwsq.a
        ${CMAKE_SOURCE_DIR}/lib/libfet.a
        ${CMAKE_SOURCE_DIR}/lib/liban2k.a
        ${CMAKE_SOURCE_DIR}/lib/libjpegl.a
        ${CMAKE_SOURCE_DIR}/lib/libjpegb.a
        ${CMAKE_SOURCE_DIR}/lib/libihead.a
        #${CMAKE_SOURCE_DIR}/libm.so.6
        ${CMAKE_SOURCE_DIR}/lib/libmlp.a
        ${CMAKE_SOURCE_DIR}/lib/libpca.a
        ${CMAKE_SOURCE_DIR}/lib/libutil.a
        ${CMAKE_SOURCE_DIR}/lib/libioutil.a
        ${CMAKE_SOURCE_DIR}/lib/libnfiq.a
        ${CMAKE_SOURCE_DIR}/lib/libpng.a
        ${CMAKE_SOURCE_DIR}/lib/libf2c.a
        ${CMAKE_SOURCE_DIR}/lib/libmindtct.a
        ${CMAKE_SOURCE_DIR}/lib/libmlp.a
        ${CMAKE_SOURCE_DIR}/lib/libcblas.a
        ${CMAKE_SOURCE_DIR}/lib/libmindtct.a
        ${CMAKE_SOURCE_DIR}/lib/libopenjp2.a
        ${CMAKE_SOURCE_DIR}/lib/libz.a
        ${CMAKE_SOURCE_DIR}/lib/libclapck.a
        ${CMAKE_SOURCE_DIR}/lib/libfft.a
        )



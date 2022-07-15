#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>

#include <GLFW/glfw3.h>

// export api
#ifdef FUSE_EXPORT
    #ifdef _MSC_VER
        #define FUSE_API __declspec(dllexport)
    #else
        #define FUSE_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define FUSE_API __declspec(dllimport)
    #else
        #define FUSE_API
    #endif
#endif

// free allocated memory and sets it to null pointer
#define FUSE_DELETE(p) if (p != NULL) { delete (p); p = NULL; }

// logging
#ifdef FUSE_DEBUG
	#define FUSE_LOG(level, message, ...) \
    fprintf(stderr, "[%s] ", level);\
    fprintf(stderr, message, ##__VA_ARGS__); \
    fprintf(stderr, "\n");

	#define FUSE_FATAL(message, ...) FUSE_LOG("fatal", message, ##__VA_ARGS__) \
    exit(EXIT_FAILURE);

	#define FUSE_WARNING(message, ...) FUSE_LOG("warning", message, ##__VA_ARGS__)
	#define FUSE_ERROR(message, ...) FUSE_LOG("error", message, ##__VA_ARGS__)
	#define FUSE_INFO(message, ...) FUSE_LOG("info", message, ##__VA_ARGS__)
#else
    #define FUSE_WARNING
	#define FUSE_ERROR	
	#define FUSE_FATAL	
	#define FUSE_INFO
#endif

// Assertions
#ifdef FUSE_DEBUG
    // runtime assertion
    #define FUSE_ASSERT assert

    // static assertion
    #if defined(__clang__) || defined(__gcc__)
        #define FUSE_STATIC_ASSERT _Static_assert
    #else
        #define FUSE_STATIC_ASSERT static_assert
    #endif
#else
    #define FUSE_STATIC_ASSERT
    #define FUSE_ASSERT
#endif

// function inlining
#if defined(__clang__) || defined(__gcc__)
    #define FUSE_INLINE __attribute__((always_inline)) inline
    #define FUSE_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define FUSE_INLINE __forceinline
    #define FUSE_NOINLINE __declspec(noinline)
#else
    #define FUSE_INLINE inline
    #define FUSE_NOINLINE
#endif




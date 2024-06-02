#pragma once

#include <string>
#include <vector>
#include <map>
#include "toolkit.hpp"

struct KernelGroup
{
    /**
     * @brief A kernel group will be compiled together
     */

    void add(const std::string& src) { sources.push_back(src); }

    std::vector<std::string> sources;

    void compile();

};

class KernelManager
{
public:

    KernelManager();

    ~KernelManager();

    void compile(const std::string& src);

    void addGroup(const char* name) { kernels[name] = new KernelGroup; }

    void addSource(const char* name, const std::string src) { kernels[name]->add(src); }

private:

    std::map<std::string, KernelGroup*> kernels;

};

#include "KernelManager.inl"

// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/make_shared.hpp>

//[plugcpp_my_plugin_sum
#include <boost/dll/alias.hpp> // for BOOST_DLL_ALIAS
#include "../tutorial_common/plugin_api.hpp"

namespace my_namespace {

class my_plugin_sum : public my_plugin_api {
public:
    my_plugin_sum() {
        std::cout << "Constructing my_plugin_sum" << std::endl;
    }

    float version() const {
        return 1.0;
    }

    std::string name() const {
        return "sum";
    }

    float calculate(float x, float y) {
        return x + y;
    }
   
    ~my_plugin_sum() {
        std::cout << "Destructing my_plugin_sum ;o)" << std::endl;
    }
};

my_plugin_sum plugin;

} // namespace my_namespace

// Exporting `my_namespace::plugin` variable with alias name `plugin`
BOOST_DLL_ALIAS(my_namespace::plugin, plugin)
//]

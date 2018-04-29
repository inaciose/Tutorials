#include "yaml-cpp/yaml.h"
#include <yaml-cpp/node/node.h>


//https://github.com/jbeder/yaml-cpp/wiki/Tutorial

int main (int argc, char** argv)
{

    YAML::Node node;  // starts out as null
    node["key"] = "value";  // it now is a map node
    node["seq"].push_back("first element");  // node["seq"] automatically becomes a sequence
    node["seq"].push_back("second element");

    node["mirror"] = node["seq"][0];  // this creates an alias
    node["seq"][0] = "1st element";  // this also changes node["mirror"]
    node["mirror"] = "element #1";  // and this changes node["seq"][0] - they're really the "same" node

    node["self"] = node;  // you can even create self-aliases
    node[node["mirror"]] = node["seq"];  // and strange loops :)

}


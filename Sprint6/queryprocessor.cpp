#include "queryprocessor.h"

QueryProcessor::QueryProcessor()
{

}

bool QueryProcessor::isBoolQuery(std::string str)
{
    return (str == "AND" || str == "OR" || str == "NOT") ? true : false;
}

#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{

}

bool QueryProcessor::isBoolQuery(std::string str)
{
    return (str == "AND" || str == "OR" || str == "NOT") ? true : false;
}

void QueryProcessor::runQuery()
{


    bool run = true;
    while (run) {

        run = indexhandler.selectDS();

    }

    while (true) {

        std::cout << std::endl << "Please enter a search query (0 to exit): ";

        std::string query;
        std::getline(std::cin, query);

        if (query == "0") {

            std::cout << "\nThanks for searching!\n";
            break;
        }

        std::string temp;
        std::vector<std::string> queryWords;
        for (std::stringstream s(query); s >> temp; )
            queryWords.push_back(temp);

        if(queryWords.size() >= 2) {

            //Stem the all of the query input first
            for (size_t i = 0; i < queryWords.size(); i++) {
                Porter2Stemmer::trim(queryWords[i]);
                Porter2Stemmer::stem(queryWords[i]);
            }

            for (size_t i = 0; i < queryWords.size(); i++) {

                if (queryWords[i] == "not") {

                    std::string notWord = queryWords[i+1];
                    std::cout << "NOT detected. NOT word is:  " << notWord << std::endl;
                    if (queryWords[0] == "and" || queryWords[0] == "or") {

                        std::string boolOperator = queryWords[0];
                        runNOTadvanced(queryWords, notWord, boolOperator);

                    } else {
                        std::string goodWord = queryWords[0];
                        runNOT(goodWord, notWord);
                    }
                }
            }


            if (queryWords[0] == "and") {
                runAND(queryWords);
            }

            if (queryWords[0] == "or") {
                runOR(queryWords);
            }

        } else {

            Porter2Stemmer::trim(query);
            Porter2Stemmer::stem(query);

            Word queryword(query);

            Word& found = indexhandler.index->getWord(queryword);

            if (found != queryword) {


                std::cout << "\nQuery not found. Try again." << std::endl;
                continue;
            }

            std::cout << found << std::endl;


            int i = 0;
            for (auto& q: found.getMostFrequent()) {

                i++;

                std::cout << std::endl << q.second << " - " << q.first;

            }
        }

    }

}

Word QueryProcessor::runAND(std::vector<std::string> queryWords)
{
    std::cout << "Bool query 'AND' found" << std::endl;
    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return str1;

    }

    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {

        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return str1;

    }
    Word intersection(found1.queryAND(found1,found2));
    for (auto& q: intersection.getMostFrequent()) {

        std::cout << std::endl << q.second << " - " << q.first;

    }
    return intersection;
}

Word QueryProcessor::runOR(std::vector<std::string> queryWords)
{
    std::cout << "Bool query 'OR' found" << std::endl;
    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return str1;
    }
    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {


        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return str1;
    }
    Word intersection(found1.queryOR(found1,found2));
    for (auto& q: intersection.getMostFrequent()) {

        std::cout << std::endl << q.second << " - " << q.first;

    }
    return intersection;
}

void QueryProcessor::runNOT(std::string goodWord, std::string notWord)
{
    Word keep(goodWord);
    Word trashWord(notWord);
    Word& found1 = indexhandler.index->getWord(keep);
    if (found1 != goodWord) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return;
    }
    Word& found2 = indexhandler.index->getWord(trashWord);
    if (found2 != notWord) {

        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return;
    }
    Word outputWord(found1.queryNOT(found1,found2));
    for (auto& q: outputWord.getMostFrequent()) {

        std::cout << std::endl << q.second << " - " << q.first;

    }
}

void QueryProcessor::runNOTadvanced(std::vector<std::string> queryWords, std::string notWord, std::string boolOperation)
{

    if (boolOperation == "or") {

        Word outputWord(runHelperOR(queryWords));

    }
    if(boolOperation == "and") {

        Word outputWord(runHelperAND(queryWords));

    }
}

Word QueryProcessor::runHelperAND(std::vector<std::string> queryWords)
{
    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return str1;

    }

    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {

        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return str1;

    }
    Word intersection(found1.queryAND(found1,found2));
    return intersection;
}

Word QueryProcessor::runHelperOR(std::vector<std::string> queryWords)
{

    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return str1;
    }
    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {


        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return str1;
    }
    Word intersection(found1.queryOR(found1,found2));
    return intersection;
}














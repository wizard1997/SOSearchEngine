/** Owner: Jake Watkins **/

#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{

}

bool QueryProcessor::isBoolQuery(std::string str)
{
    return (str == "AND" || str == "OR" || str == "NOT") ? true : false;
}

/**
 *
 * @brief QueryProcessor::runQuery The heart of the query processing. This function
 * takes in the user's search and processes it.  If the query is only one word then
 * the query will be processed in runQuery. If however the query is multiple words,
 * then the input is searched and processed based on the different queries inputed.
 *
 **/
void QueryProcessor::runQuery()
{

    bool run = true;
    while (run) {

        run = indexhandler.selectDS();

    }

    while (true) {

        std::cout << std::endl << "Load index from output.dat? (Y or N): ";
        char selection = 'N';
        std::cin >> selection;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if (selection == 'Y') {

            indexhandler.loadIndex();
            break;
        } else if (selection == 'N') {

            break;

        } else {

            std::cout << "\nTry again, wrong selection.\n";
        }

    }


    while (true) {



        std::cout << "\nPlease enter a search query (0 to exit): ";

        std::string query;
        std::getline(std::cin, query);

        if (query == "0") {

            std::cout << "\nThanks for searching!\n";
            break;
        }

        std::string temp;
        std::vector<std::string> queryWords;
        for (std::stringstream s(query); s >> temp; ) {
            queryWords.push_back(temp);

        }
        Word found(query);
        //If the size is greater than 1 then it must be a bool query search
        if(queryWords.size() >= 2) {

            //Stem the all of the query input first
            for (size_t i = 0; i < queryWords.size(); i++) {
                Porter2Stemmer::trim(queryWords[i]);
                Porter2Stemmer::stem(queryWords[i]);
            }

            //Finding out if any of the words is a NOT
            for (size_t i = 0; i < queryWords.size(); i++) {

                if (queryWords[i] == "not") {

                    std::string notWord = queryWords[i+1];
                    std::cout << "NOT detected. NOT word is:  " << notWord << std::endl;
                    if (queryWords[0] == "and" || queryWords[0] == "or") {

                        std::string boolOperator = queryWords[0];
                        runNOTadvanced(queryWords, notWord, boolOperator);

                    } else {
                        std::string goodWord = queryWords[0];
                        runNOT(goodWord, notWord,found);
                    }
                }
            }

            //Process an AND boolean query
            if (queryWords[0] == "and") {
                runAND(queryWords,found);
            }

            //Process an OR boolean query
            if (queryWords[0] == "or") {
                runOR(queryWords,found);
            }

        } else {

            //Just your typical one word query
            Porter2Stemmer::trim(query);
            Porter2Stemmer::stem(query);
            if (FileProcessor::isStopWord(query)) {
                std::cout << "\nQuery is a stop word. Try again" << std::endl;
                continue;

            }

            Word queryword(query);
            try {

                found =  (indexhandler.index->getWord(queryword));

            } catch (std::bad_alloc) {


            }




        }

        if (found.questionData.size() < 1) {


            std::cout << "\nQuery not found. Try again." << std::endl;
            continue;
        }


        int i = 0;
        std::cout << std::endl;
        for (auto& q: found.getMostFrequent()) {

            i++;

            std::cout << i << ".\t"<< q.second << " frequency: " << q.first << std::endl;

        }
        while (true) {

                std::cout << "\nChoose question to view more (1-10, 0 to exit): ";
                int selection;
                std::cin >> selection;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                if (selection == 0) {

                    break;
                }
                unsigned long id = found.getMostFrequent()[selection-1].second;
                FileProcessor fp2("../Sprint6/data/");
                fp2.displayQuestion(id);


        }

    }

}

/**
 *
 * @brief QueryProcessor::runAND Processes an AND query. It does this by
 * making sure that the words to be ANDed are in fact words that are used
 * in the files,  then it uses the AND function in the word class to create
 * a word with the data that is the AND of two words
 *
 * @param queryWords the vector that contains the query input
 *
 **/
void QueryProcessor::runAND(std::vector<std::string> queryWords, Word& found)
{

    std::cout << "Bool query 'AND' found" << std::endl;
    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return;

    }

    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {

        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return;

    }
    Word intersection(found1.queryAND(found1,found2));
    found = intersection;

}

/**

 * @brief QueryProcessor::runOR Processes an OR query. It does this by
 * making sure that the words to be ORed are in fact words that are used
 * in the files,  then it uses the OR function in the word class to create
 * a word with the data that is the OR of two words
 *
 * @param queryWords the vector that contains the query input
 *
 **/
void QueryProcessor::runOR(std::vector<std::string> queryWords, Word& found)
{
    std::cout << "Bool query 'OR' found" << std::endl;
    Word str1(queryWords[1]);
    Word str2(queryWords[2]);
    Word& found1 = indexhandler.index->getWord(str1);
    if (found1 != queryWords[1]) {

        std::cout << "\nFirst query argument not found. Try again." << std::endl;
        return;
    }
    Word& found2 = indexhandler.index->getWord(str2);
    if (found2 != queryWords[2]) {


        std::cout << "\nSecond query argument not found. Try again." << std::endl;
        return;
    }
    Word intersection(found1.queryOR(found1,found2));
    found.questionData = intersection.questionData;
}

/**

 * @brief QueryProcessor::runNOT This function outputs a NOT of two words.
 * This means that the output data will be the instances of files in which
 * the 'good word' is frequently used and there are no uses of the 'not word'.
 *
 * @param goodWord The word who's data we want to find
 *
 * @param notWord The word that we dont want to see used in any of the output data
 * files
 *
 **/
void QueryProcessor::runNOT(std::string goodWord, std::string notWord, Word& found)
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
    found.questionData = outputWord.questionData;
}

/**
 *
 * @brief QueryProcessor::runNOTadvanced The not function that also takes
 * into account other bool queries in the user search. It handles the OR and
 * AND operations before NOT
 *
 * @param queryWords The vector of the words inputed by the user
 *
 * @param notWord The word to be NOTed
 *
 * @param boolOperation The other bool operation in the query, OR or AND
 *
 */
void QueryProcessor::runNOTadvanced(std::vector<std::string> queryWords, std::string notWord, std::string boolOperation)
{

    if (boolOperation == "or") {

        Word keep(runHelperOR(queryWords));

    } else {

        Word keep(runHelperAND(queryWords));


        Word trashWord(notWord);
        Word& found1 = indexhandler.index->getWord(keep);
        std::string keepStr = keep.getWordStr();
        if (found1 != keepStr) {

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

}

/**
 *
 * @brief QueryProcessor::runHelperAND The helper AND function for the
 * advanced NOT function.  It ANDs words but instead of outputting results
 * it returns a Word containing the data of the ANDed words.
 *
 * @param queryWords The query inputed by the user
 *
 * @return A Word containing the data of the ANDed words.
 *
 */
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

/**
 *
 * @brief QueryProcessor::runHelperOR Helper OR function for the
 * advanced NOT function.  ORs words together.
 *
 * @param queryWords vector of words inputed by the user
 *
 * @return A word containing the data of the ORed words to return
 * back to the advanced AND funcion
 *
 */
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



/** Owner: Addison Kimball **/

#include "FileProcessor.h"

/**
 * @brief FileProcessor::FileProcessor(std::string) Constructor for supplying a directory to
 * scan for files.
 *
 * @param dirIn String of path to directory.
 **/
FileProcessor::FileProcessor(std::string dirIn) {

     DIR* dirp;
     dirent* dp;

     if ((dirp = opendir(dirIn.c_str())) != NULL) {
       /* print all the files and directories within directory */
       while ((dp = readdir(dirp)) != NULL) {

         if (strlen(dp->d_name) > 3) {

             fileVec.push_back(dirIn + dp->d_name);
         }
       }

       closedir(dirp);


     } else {
       /* could not open directory */
       std::cout << "could not open directory";

     }



}

/**
 * @brief FileProcessor::selectDetectedFile Private definition for selecting and
 *  parsing individual files.
 *
 * @param index Numerical pos of file in displayed list that user wants to parse.
 **/
void FileProcessor::selectDetectedFile(size_t index) {

    std::string path = fileVec[index];
    if (path.substr(path.size()-3,3) == "psv") {

        parseQuestionFile(path);
    }

}


/**
 * @brief FileParser::selectDetectedFile Public declaration for selecting file, or parsing all
 * at once. Presents UI to user.
 * @return bool Bool for continued menu display.
 */
bool FileProcessor::selectDetectedFile() {

    std::cout << "----------------------------------------\n"
                 "List of files detected in specific path:\n"
                 "----------------------------------------\n";

    for (size_t i = 0; i < fileVec.size(); i++) {

        std::cout << i+1 << ".\t" << fileVec[i] << std::endl;
    }
    std::cout << "X.\tParse all valid detected files" << std::endl;
    std::cout << "Please enter number of file to parse: ";
    char selection;
    std::cin >> selection;
    if (selection == 'X') {

        parseAllValidFiles();
        std::cout << std::endl;
        return true;

    } else if (selection == '0') {

        std::cout << "\nFinished parsing. Exiting.\n";
        return false;

    } else if (selection == 'S') {




    } else if (selection < '9' && selection > '0') {

        size_t selectionNum = selection - '0';
        std::cout << "\nParsing file: " << fileVec[selectionNum-1] << std::endl;
        parseQuestionFile(fileVec[selectionNum-1]);
        return true;

    } else {


        return true;

    }


    return true;



}
/**
 * @brief FileParser::parseQuestionFile Takes in string file path and parses
 * the file chunk by chunk, and then question by question. Credits to
 * Stephen Brumme for the memory mapped library.
 * @param file  String file path
 */
void FileProcessor::parseQuestionFile(std::string file)
{

    //Open the question file
    MemoryMapped data(file,0);


    if (!data.isValid()) {
        std::cout << "********** Error the question file was NOT opened **********\n\n";
        return;
    }


    std::cout << "\t\tQuestion File mapped to memory!\n\n";


    size_t qcount = 0;
    size_t it = 50;
    size_t bufferSize = 1000000;

    while (it < data.size()) {



        std::string buffer ="";

        size_t counter = 0;
        while (it < data.size() && counter < bufferSize) {

            if (data[it] < 128) {

                buffer += data[it];

            }
            it++;
            counter++;

        }

        int questionBeginIndex = buffer.find("<>?<>?<>", questionBeginIndex);
        questionBeginIndex = buffer.find("<>!<>!<>", questionBeginIndex);
        questionBeginIndex = buffer.find("<>!<>!<>", questionBeginIndex +1);
        questionBeginIndex = (buffer.find('\n', questionBeginIndex+1)+1);

        //deal with id number and skip over to where question starts

//        std::cout << buffer;
        int lastQuestionBeginIndex = buffer.rfind("<>?<>?<>");
        lastQuestionBeginIndex = buffer.rfind("<>?<>?<>",lastQuestionBeginIndex-1);
        for (int i = 0; i < 4; i++) {

            lastQuestionBeginIndex = buffer.rfind('|',lastQuestionBeginIndex-1);

        }
        lastQuestionBeginIndex = buffer.rfind('\n',lastQuestionBeginIndex-1);
        lastQuestionBeginIndex++;
        int lastQuestionIdEnd = buffer.find('|',lastQuestionBeginIndex);
        int lastQuestionId = atoi(buffer.substr(lastQuestionBeginIndex,lastQuestionIdEnd).c_str());


        while (true) {

            int idEndIndex = buffer.find('|',questionBeginIndex);
            int questionID = atoi(buffer.substr(questionBeginIndex,idEndIndex).c_str());
            if (questionID == lastQuestionId) {

                break;
            }
            int titleBeginIndex = buffer.find('|',idEndIndex+1);
            for (int i = 0; i < 2; i++) {

                titleBeginIndex = buffer.find('|',titleBeginIndex+1);

            }
            int titleEndIndex = buffer.find('|',titleBeginIndex+1);
            std::string titleString = buffer.substr(titleBeginIndex+1,titleEndIndex-titleBeginIndex-1);
            qcount++;
            parseString(titleString,questionID);

            int bodyBeginIndex = buffer.find("<>?<>?<>", titleEndIndex+1)+7;
            int bodyEndIndex = buffer.find("<>?<>?<>", bodyBeginIndex+1);
            std::string bodyString = buffer.substr(bodyBeginIndex+1,bodyEndIndex-bodyBeginIndex-1);
            parseString(bodyString,questionID);
            //std::cout << questionID << std::endl;
            int codeBeginIndex = buffer.find("<>!<>!<>", titleEndIndex+1);
            int codeEndIndex = buffer.find("<>!<>!<>", codeBeginIndex+1);

            questionBeginIndex = (buffer.find('\n',codeEndIndex)+1);

        }


    }

    std::cout << std::endl << qcount << " questions parsed!\n";


}


/**
 * @brief FileParser::parseString Parses actual string of words, separates into
 * words, stems, trims, and inserts into index.
 * @param stringIn String of words to parse, extracted from overall
 * question.
 * @param idNum ID number extracted from question.
 */
void FileProcessor::parseString(std::string& stringIn,unsigned long idNum) {

    auto done = stringIn.end();
    auto end = stringIn.begin();
    decltype(end) index;

    while((index = std::find_if(end, done, std::not1(std::ptr_fun(isspace)))) != done) {
        end = std::find_if(index, done, std::ptr_fun(isspace));
        while ( !(((*end >= 'A') && (*end <= 'Z')) || ((*end >= 'a') && (*end <= 'z'))) ) {


            end++;
        }
        std::string word(index, end);
        if (word.size() > 2 && !isStopWord(word)) {


            Porter2Stemmer::trim(word);
            Porter2Stemmer::stem(word); 

            if (((word[0] >= 'A') && (word[0] <= 'Z')) || ((word[0] >= 'a') && (word[0] <= 'z'))) {

                if (idNum > 0) {

                    indexhandler.index->addWord(word,idNum);

                }

            }

        }

    }

}

/**
 * @brief FileProcessor::parseAllValidFiles Parses all files
 * detected in supplied directory.
 */
void FileProcessor::parseAllValidFiles() {


    for (size_t i = 0; i < fileVec.size(); i++) {


        selectDetectedFile(i);

    }


}

bool FileProcessor::scanFile(std::string file, unsigned long idNum) {

    //Open the question file
    MemoryMapped data(file,0);
    std::string idString(std::to_string(idNum));


    if (!data.isValid()) {
        std::cout << "********** Error the question file was NOT opened **********\n\n";
        return false;
    }



    size_t it = 0;
    std::string foundString;


    while (it < data.size()) {


        foundString = "0";
        while (data[it] != idString[0]) {

            it++;
        }
        foundString[0] = data[it];
        for (size_t i = 1; i  < idString.length()+1; i++) {

            if (data[it+i] == idString[i]) {


                foundString += data[it+i];
            } else {

                break;
            }

        }
        if (foundString == idString) {

            std::string buffString;
            for (int i = 0; i < 4000; i++) {

                buffString += data[it+i];
            }
            int codeBeginIndex = buffString.find("<>!<>!<>", 0);
            int codeEndIndex = buffString.find("<>!<>!<>", codeBeginIndex+1);
            std::string qString = buffString.substr(0,codeEndIndex);
            std::cout << buffString;
            return true;
        }
        it++;




    }

    return false;


}

void FileProcessor::displayQuestion(unsigned long idNum) {

    for (auto& q: fileVec) {

        if (q.substr(q.size()-3,3) == "psv") {

             if (scanFile(q,idNum)) {

                break;
            }
        }
    }


}


/**
 * @brief FileProcessor::runMenu Continually display menu to user for operating program
 * in parsing mode.
 */
void FileProcessor::runMenu() {


    bool run = true;
    while (run) {

        run = indexhandler.selectDS();

    }

    while (true) {
        std::cin.sync();
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

    run = true;
    while (run) {

        run = selectDetectedFile();
    }

    indexhandler.saveIndex("output.dat");

}



/**
 * @brief FileParser::isStopWord Function that identifies if the given
 * word is in fact a stop word that should be removed
 * @param word The word that will be tested to see if it's a stop word
 * @return True if word is a stop word, false if not
 */
bool FileProcessor::isStopWord(std::string &word)
{
    return stopWords.count(word);
}


//Stop words from the website given by the project handout, minus a few that
//I thought to be unnecessary and a few that I didn't believe to be stopWords, like "zero"
std::unordered_set<std::string> FileProcessor::stopWords {
    "able", "about", "above", "abroad", "accordingly", "across", "actually",
    "adj", "after", "afterwards", "again", "against", "ago", "ahead", "ain't",
    "all", "allow", "almost", "alone", "along", "alongside", "already", "also",
    "although", "always", "am", "amid", "among", "amongst", "an", "and", "another",
    "any", "anybody", "anyhow", "anyone", "anything", "anyway", "anyways", "anywhere",
    "apart", "appear", "appreciate", "appropriate", "are", "aren't", "around", "as", "a's",
    "aside", "ask", "asking", "associated", "at", "available", "away", "awfully", "back",
    "backward", "backwards", "be", "became", "because", "become", "becomes", "becoming",
    "been", "before", "beforehand", "begin", "behind", "being", "believe", "below",
    "beside", "besides", "best", "better", "between", "beyond", "both", "brief", "but",
    "by", "came", "can", "cannot", "cant", "can't", "caption", "cause", "causes",
    "certain", "certainly", "changes", "clearly", "c'mon", "co", "co.", "com",
    "come", "comes", "concerning", "consequently", "consider", "considering",
    "contain", "containing", "contains", "corresponding", "could", "couldn't", "course",
    "c's", "currently", "dare", "daren't", "definitley", "described", "despite", "did",
    "didn't", "different", "directly", "do", "does", "doesn't", "doing", "done", "don't",
    "down", "downwards", "during", "each", "edu", "eg", "eight", "eighty", "either",
    "else", "elsewhere", "end", "ending", "enough", "entirely", "especially", "et",
    "etc", "even", "ever", "evermore", "every", "everybody", "everyone", "everything",
    "everywhere", "ex", "exactly", "example", "except", "fairly", "far", "farther",
    "few", "fewer", "fifth", "first", "five", "followed", "following", "follows",
    "for", "forever", "former", "formerly", "forth", "forward", "found", "four",
    "from", "further", "furthermore", "get", "gets", "getting", "given", "gives",
    "go", "goes", "going", "gone", "got", "gotten", "greetings", "had",
    "hadn't", "half", "happens", "hardly", "has", "hasn't", "have", "haven't",
    "having", "he", "he'd", "he'll", "hello", "help", "hence", "her", "here",
    "hereafter", "hereby", "herin", "here's", "hereupon", "hers", "herself",
    "he's", "hi", "him", "himself", "his", "hither", "hopefully", "how", "howbeit",
    "however", "hundred", "i'd", "ie", "if", "ignored", "i'll", "i'm", "immediate",
    "in", "inasmuch", "inc", "inc.", "indeed", "indicate", "indicated", "indicates",
    "inner", "inside", "insofar", "instead", "into", "inward", "is", "isn't", "it",
    "it'd", "it'll", "it's", "its", "itslef", "i've", "just", "k", "keep", "keeps",
    "kept", "know", "known", "knows", "last", "lately", "later", "latter",
    "latterly", "least", "less", "lest", "let", "let's", "like", "liked", "likely",
    "likewise", "little", "look", "looking", "look", "looking", "looks", "low",
    "lower", "ltd", "made", "mainly", "make", "makes", "many", "may", "maybe",
    "mayn't", "me", "mean", "meantime", "meanwhile", "merely", "might", "mightn't",
    "mine", "minus", "miss", "more", "moreover", "most", "mostly", "mr", "mrs",
    "much", "must", "mustn't", "my", "myself", "name", "namely", "nd", "near",
    "nearly", "necessary", "need", "needn't", "needs", "neither", "never",
    "neverless", "nevertheless", "new", "next", "nine", "ninety", "no",
    "nobody", "non", "none", "nonetheless", "noone", "no-one", "nor",
    "normally", "not", "nothing", "notwithstanding", "novel", "now", "nowhere",
    "obviously", "of", "off", "often", "oh", "ok", "okay", "old", "on",
    "once", "one", "ones", "one's", "only", "onto", "opposite", "or", "other",
    "others", "otherwise", "ought", "oughtn't", "our", "ours", "ourselves",
    "out", "outside", "over", "overall", "own", "particular", "particularly",
    "past", "per", "perhaps", "placed", "please", "plus", "possible",
    "presumably", "probably", "provided", "provides", "que", "quite", "qv",
    "rather", "rd", "re", "really", "reasonably", "recent", "recently", "regarding",
    "regardless", "regards", "relatively", "respectively", "right", "round", "said",
    "same", "saw", "say", "saying", "says", "second", "secondly", "see", "seeing", "seem",
    "seemed", "seeming", "seems", "seen", "self", "selves", "sensible", "sent", "serious",
    "seriously", "seven", "several", "shall", "shan't", "she", "she'd", "she'll",
    "she's", "should", "shouldn't", "since", "six", "so", "some", "somebody", "someday",
    "somehow", "someone", "something", "sometime", "sometimes", "somewhat", "somewhere",
    "soon", "sorry", "specified", "specify", "specifying", "still", "sub", "sure",
    "take", "taken", "taking", "tell", "tends", "th", "than", "thank", "thanks",
    "that", "that'll", "thats", "that's", "that've", "the", "their", "theirs", "them",
    "themselves", "then", "thence", "there", "therafter", "thereby", "there'd", "therefore",
    "therein", "there'll", "there're", "theres", "there's", "thereupon", "there've", "these",
    "they", "they'd", "they'll", "they're", "they've", "thing", "things", "think", "third",
    "thirty", "this", "thorough", "thoroughly", "those", "though", "three", "through",
    "throughout", "thru", "till", "to", "together", "too", "took", "toward", "towards",
    "tried", "tries", "truly", "try", "trying", "t's", "twice", "two", "un", "under",
    "underneath", "undoing", "unfortunatley", "unless", "unlike", "unlikely", "until", "unto",
    "up", "upon", "upwards", "us", "use", "used", "useful", "uses", "using", "usually", "v",
    "value", "various6", "versus", "very", "via", "viz", "vs", "want", "wants", "was", "wasn't",
    "way", "we", "we'd", "welcome", "well", "we'll", "went", "were", "we're", "weren't", "we've",
    "what", "whatever", "what'll", "what's", "what've", "when", "whence", "whenever", "where",
    "whereafter", "whereas", "whereby", "wherein", "where's", "whereupon", "wherever", "whether",
    "which", "whichever", "while", "whilst", "whither", "who", "who'd", "whoever", "whole",
    "who'll", "whom", "whomever", "who's", "whose", "why", "will", "willing", "wish", "with",
    "within", "without", "wonder", "won't", "would", "wouldn't", "yes", "yet", "you", "you'd",
    "you'll", "your", "you're", "yours", "yourself", "yourself", "yourselves", "you've", "how", "why",
    "via"
};


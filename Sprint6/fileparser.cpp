#include "fileparser.h"

FileParser::FileParser()
{

}

/**
 * @brief FileParser::parseQuestionFile
 * @param file
 */
void FileParser::parseQuestionFile(std::string file)
{

    //Open the question file
    std::ifstream questionFile;
    questionFile.open(file);
    if (!questionFile.is_open()) {
        std::cout << "********** Error the question file was NOT opened **********\n\n";
    }

    std::cout << "**Question File opened\n\n**";
    //temp here is used to bypass the very first line of file
    char* temp = new char[50];
    questionFile.getline(temp, 50);
    std::cout << temp << std::endl;
    delete [] temp;

    //Reading the rest of the file into a buffer
    std::stringstream strStream;
    strStream << questionFile.rdbuf();
    std::string buffer = strStream.str();
    //std::cout << buffer;
    questionFile.close();

    int counter = 0;
    //deal with id number and skip over to where question starts


    //parse word for word, stem, trim, and stopword each word and then add
    //the word into the vector for that particular id number and  go to next word
}

/**
 * @brief FileParser::isStopWord Function that identifies if the given
 * word is in fact a stop word that should be removed
 * @param word The word that will be tested to see if it's a stop word
 * @return True if word is a stop word, false if not
 */
bool FileParser::isStopWord(std::string &word)
{
    return stopWords.count(word);
}

void FileParser::test()
{
    std::string val = "about";
    if(isStopWord(val))
        std::cout << "found stop word\n\n";
}

//Stop words from the website given by the project handout, minus a few that
//I thought to be unnecessary and a few that I didn't believe to be stopWords, like "zero"
std::unordered_set<std::string> FileParser::stopWords {
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
    "you'll", "your", "you're", "yours", "yourself", "yourself", "yourselves", "you've"
};



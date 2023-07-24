#include "parse.h"

std::string parseLine(std::string s, std::string startTag, std::string endTag) {
   int startPos = s.find(startTag) + startTag.length();
   int endPos = s.find(endTag);
   return s.substr(startPos, endPos - startPos);
}

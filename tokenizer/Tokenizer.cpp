//
// Created by wolek on 17.09.24.
//

#include "Tokenizer.hpp"
#include <set>

std::vector<std::string> Tokenizer::parse(std::string& text, const std::string delimiters)
{
  std::set<char> inputDelimiters(delimiters.begin(),delimiters.end());
  std::string parsed;
  for(auto letter : text)
  {
    if(inputDelimiters.find(letter) != inputDelimiters.end())
    {
      if(not parsed.empty())
      {
        tokens.push_back(parsed);
        parsed.clear();
      }
    }
    else{
      parsed += letter;
    }
  }

  if(!parsed.empty()){
    tokens.push_back(parsed);
  }

  return tokens;
}
std::vector<std::string> Tokenizer::regParse(std::string &text, std::regex reg) {
  std::vector<std::string> regRes;
  std::sregex_iterator it(text.begin(), text.end(), reg);
  std::sregex_iterator end;

  while (it != end){
    regRes.push_back(it->str());
    ++it;
  }
  return regRes;

}

//
// Created by wolek on 17.09.24.
//

#include "Tokenizer.hpp"
#include <set>
#include <cassert>

std::vector<std::string> Tokenizer::parse(std::string &text, const std::string delimiters) {
  std::set<char> inputDelimiters(delimiters.begin(), delimiters.end());
  std::string parsed;
  for (auto letter : text) {
    if (inputDelimiters.find(letter) != inputDelimiters.end()) {
      if (not parsed.empty()) {
        tokens.push_back(parsed);
        parsed.clear();
      }
    } else {
      parsed += letter;
    }
  }

  if (!parsed.empty()) {
    tokens.push_back(parsed);
  }

  return tokens;
}
std::vector<std::string> Tokenizer::regParse(std::string &text, std::regex reg) {
  std::vector<std::string> regRes;
  std::sregex_iterator it(text.begin(), text.end(), reg);
  std::sregex_iterator end;

  while (it != end) {
    regRes.push_back(it->str());
    ++it;
  }
  return regRes;
}

void insertRuleFromLine(std::string &line, RulesMap &rules) {
  std::regex reg(R"(\d+)");
  std::sregex_iterator it(line.begin(), line.end(), reg);
  //fmt::print("{}\n", std::distance(it->begin(), it->end()));
  assert(std::distance(it->begin(), it->end()) == 1 && "to many regex hits for rule");
  auto key = std::stoi(it->str());
  auto value = std::stoi((++it)->str());
  rules[key].push_back(value);
}

void insertPages(std::string &line, PageVec &pages)
{
  std::regex reg(R"(\d+)");
  std::sregex_iterator it(line.begin(), line.end(), reg);
  std::sregex_iterator end;
  std::vector<int> update;
  while (it != end)
  {
    update.push_back(std::stoi(it->str()));
    it++;
  }
  pages.push_back(update);
}

void Tokenizer::day05parse(std::vector<std::string> &lines, RulesMap &rules, PageVec &pages) {

  for (auto &line : lines) {
    if (line.find('|') != std::string::npos) {
      insertRuleFromLine(line, rules);
    } else {
      insertPages(line, pages);
    }
  }
}

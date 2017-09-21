/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<string> stringTokenizer(string input, char delimiter){
        vector<string> result;

        if(!input.length())
            return result;

        const char *it = input.c_str();
        do {
            const char *cstart = it;
            while(*it && *it != delimiter)
                it++;
            result.push_back(string(cstart, it));
        } while(*it++);

        return result;
    }

    string simplifyPath(string path) {
      vector<string> tokenizedPath = stringTokenizer(path, '/');
      vector<string> resultPath;

      for(auto& it: tokenizedPath){
        if(it.length() == 0){
          continue;
        }
        else if(it == "."){
          continue;
        }else if(it == ".."){
          if(resultPath.empty()){
            continue;
          }
          resultPath.pop_back();
        }
        else{
          resultPath.push_back(it);
        }
      }

      if(resultPath.size() == 0){
        return "/";
      }
      
      string result;
      for(auto& it : resultPath){
        result += "/" + it;
      }
      return result;
    }
};

int main(){
  Solution s;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
}

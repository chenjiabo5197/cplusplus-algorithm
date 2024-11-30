class Solution {
public:
    string simplifyPath(string path) {
        std::istringstream pathStream(path);
        vector<string> pathVector;
        string token;
        while (std::getline(pathStream, token, '/'))
        {
            pathVector.push_back(token);
        }
        stack<string> myStack;
        for (int i = 0; i < pathVector.size(); ++i) {
            string temp = pathVector[i];
            if (temp == "..")
            {
                if(!myStack.empty())
                {
                    myStack.pop();
                }
            }
            else if(temp != "" && temp != ".")
            {
                myStack.push(temp);
            }
        }
        string result = "";
        while (!myStack.empty())
        {
            result = myStack.top() + "/" + result;
            myStack.pop();
        }
        return "/" + result.substr(0, result.length()-1);
    }
};
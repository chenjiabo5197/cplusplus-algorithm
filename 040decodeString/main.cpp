class Solution {
public:
    string decodeString(string s) {
//        stack<string> myStack;
//        string strDigit = "";
//        for (int i = 0; i < s.length(); ++i) {
//            char ch = s[i];
//            if(isdigit(ch))
//            {
//                strDigit += ch;
//            }
//            else if(ch == '[')
//            {
//                if(strDigit != "")
//                {
//                    std::cout << "数字:" <<  strDigit << std::endl;
//                    myStack.push(strDigit);
//                    strDigit = "";
//                }
//                myStack.push("[");
//            }
//            else if(ch == ']')
//            {
//                string needRepeat = "";
//                std::cout<< "top:" << myStack.top() << std::endl;
//                while(!myStack.empty() && isalpha(myStack.top()[0]))
//                {
//                    needRepeat = myStack.top() + needRepeat;
//                    myStack.pop();
//                }
//                std::cout << "need1:" << needRepeat << std::endl;
//                // 将[弹出
//                myStack.pop();
//                // 此时是数字
//                int repeatTimes = std::stoi(myStack.top());
//                string repeatResult = needRepeat;
//                std::cout << "repeat nums" << repeatTimes << std::endl;
//                for (int j = 1; j < repeatTimes; ++j) {
//                    repeatResult += needRepeat;
//                }
//                // 将数字弹出
//                myStack.pop();
//                std::cout <<  "need2:" << repeatResult << std::endl;
//                myStack.push(repeatResult);
//            }
//            else
//            {
//                std::cout << "char: " <<  string(1,ch) << std::endl;
//                myStack.push(string(1, ch));
//            }
//        }
//        string result = "";
//        while (!myStack.empty())
//        {
//            result = myStack.top() + result;
//            myStack.pop();
//        }
//        return result;
        // 储存数字
        stack<int> numStack;
        // 储存中间的字符串
        stack<string> strStack;
        int num = 0;
        string str;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0');
            }
            else if(ch >= 'a' && ch <= 'z')
            {
                str += ch;
            }
            else if(ch == '[')
            {
                numStack.push(num);
                strStack.push(str);
                num = 0;
                str = "";
            }
            else if(ch == ']')
            {
                int repeatTimes = numStack.top();
                numStack.pop();
                string outStr = strStack.top();
                strStack.pop();
                for (int j = 0; j < repeatTimes; ++j) {
                    outStr += str;
                }
                str = outStr;
            }
        }
        return str;
    }
};
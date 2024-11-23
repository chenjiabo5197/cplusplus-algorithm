#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 储存课程列表的入度，入度为0时，此课程可以上，索引代表课程号
        vector<int> courseDegree(numCourses);
        // 课程的依赖映射关系，key为课程名，value为依赖该课程的课程列表
        map<int, vector<int>> courseDepend;
        for (int i = 0; i < prerequisites.size(); ++i) {
            courseDegree[prerequisites[i][0]]++;
            courseDepend[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // 储存可以学习的课程，该队列中课程的入度均为0
        queue<int> canStudyCourse;
        for (int i = 0; i < courseDegree.size(); ++i) {
            if (courseDegree[i] == 0)  // 该课程的入度为0，不依赖其他课程
            {
                canStudyCourse.push(i);
            }
        }
        int studyCourse = 0;
        while (!canStudyCourse.empty())
        {
            int courseNum = canStudyCourse.front();
            canStudyCourse.pop();
            studyCourse++;
            // 遍历依赖该课程的课程列表，在该列表中的课程入度均-1，然后度为0，则加入到canStudyCourse中
            for (int i = 0; i < courseDepend[courseNum].size(); ++i) {
                courseDegree[courseDepend[courseNum][i]]--;
                if (courseDegree[courseDepend[courseNum][i]] == 0)
                {
                    canStudyCourse.push(courseDepend[courseNum][i]);
                }
            }
        }
        return studyCourse == numCourses;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> v = {{1, 0}};
    int numCourses = 2;

    auto result = sl.canFinish(numCourses, v);
    std::cout << result << std::endl;
    return 0;
}


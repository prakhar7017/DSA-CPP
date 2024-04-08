/*
1700. Number of Students Unable to Eat Lunch

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
*/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        stack<int>st;
        queue<int>q;
        for(int i=0;i<n;i++){
            st.push(sandwiches[n-i-1]);
            q.push(students[i]);
        }

        int lastServed=0;
        while(!q.empty() && lastServed<q.size()){
            if(q.front()==st.top()){
                q.pop();
                st.pop();
                lastServed=0;
            }else {
                ++lastServed;
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};

// time complexity: O(n)
// space complexity: O(n)

// link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08


//---------------------------------------------------------------------------------
 class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int arr[2]={0};
        for(int i=0;i<n;i++){
            arr[students[i]]++;
        }
        for(int i=0;i<n;i++){
            int sandW=sandwiches[i];
            if(arr[sandW]<=0){
                return n-i;
            }else {
                arr[sandW]--;
            }
        }
        return 0;
    }
};

// time comeplexity: O(n)
// space complexity: O(1)
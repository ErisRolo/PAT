/*  1036. Boys vs Girls (25)

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Sample Output 1:
Mary EE990830
Joe Math990112
6

Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
    char name[11];
    char gender;
    char id[11];
    int score;
};

vector<Stu> male;
vector<Stu> female;

int N;

bool cmp_male(Stu &lhs, Stu &rhs){
    if(lhs.score < rhs.score) return true;
    else return false;
}
bool cmp_female(Stu &lhs, Stu &rhs){
    if(lhs.score > rhs.score) return true;
    else return false;
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        Stu stu;
        scanf("%s %c %s %d", stu.name, &stu.gender, stu.id, &stu.score);
        if(stu.gender == 'M') male.push_back(stu);
        else female.push_back(stu);
    }
    if(female.size() == 0) printf("Absent\n");
    else{
        sort(female.begin(), female.end(), cmp_female);
        printf("%s %s\n", female[0].name, female[0].id);
    }
    if(male.size() == 0) printf("Absent\n");
    else{
        sort(male.begin(), male.end(), cmp_male);
        printf("%s %s\n", male[0].name, male[0].id);
    }
    if(male.size()== 0 || female.size() ==0){
        printf("NA");
    }
    else{
        int high = female[0].score;
        int low = male[0].score;
        printf("%d", high-low);
    }
    return 0;
}

/* 1022. Digital Library (30)

A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print"Not Found" instead.

Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;

int N, M;

// struct Book{
//     string id;
//     string title;
//     string author;
//     string key;
//     string pub;
//     string year;
//     Book(string id, string title, string author, string key, string pub, string year):id(id),title(title),author(author),key(key),pub(pub),year(year){}
// };

// vector<Book> vec;
map<string, set<string>> title_id;
map<string, set<string>> author_id;
map<string, set<string>> key_id;
map<string, set<string>> pub_id;
map<string, set<string>> year_id;

void s_title(string s){
    cout << "1: " << s << endl;
    if(title_id.find(s) != title_id.end()){
        for(auto it = title_id[s].begin(); it != title_id[s].end(); it++){
            cout << *it << endl;
        }
    }
    else{
        cout << "Not Found" << endl;
    }
}

void s_author(string s){
    cout << "2: " << s<< endl;
    if(author_id.find(s) != author_id.end()){
        for(auto it = author_id[s].begin(); it != author_id[s].end(); it++){
            cout << *it << endl;
        }
    }
    else{
        cout << "Not Found" << endl;
    }
}

void s_key(string s){
    cout << "3: " << s<< endl;
    if(key_id.find(s) != key_id.end()){
        for(auto it = key_id[s].begin(); it != key_id[s].end(); it++){
            cout << *it << endl;
        }
    }
    else{
        cout << "Not Found" << endl;
    }
}

void s_pub(string s){
    cout << "4: " << s<< endl;
    if(pub_id.find(s) != pub_id.end()){
        for(auto it = pub_id[s].begin(); it != pub_id[s].end(); it++){
            cout << *it << endl;
        }
    }
    else{
        cout << "Not Found" << endl;
    }
}

void s_year(string s){
    cout << "5: " << s<< endl;
    if(year_id.find(s) != year_id.end()){
        for(auto it = year_id[s].begin(); it != year_id[s].end(); it++){
            cout << *it << endl;
        }
    }
    else{
        cout << "Not Found" << endl;
    }
}

int main()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        string id, title, author, key, pub, year;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        while(cin >> key){
            key_id[key].insert(id);
            char c = getchar();
            if(c=='\n') break;
        }
        getline(cin, pub);
        getline(cin, year);
        // vec.push_back(Book(id, title, author,key,pub,year));
        title_id[title].insert(id);
        author_id[author].insert(id);
      
        pub_id[pub].insert(id);
        year_id[year].insert(id);
    }

    cin >> M;
    cin.ignore();
    for(int i = 0; i < M; i++){
        int type;
        string s;
        scanf("%d: ", &type);
        getline(cin, s);
        switch(type){
            case 1:
                s_title(s);
                break;
            case 2:
                s_author(s);
                break;
            case 3:
                s_key(s);
                break;
            case 4:
                s_pub(s);
                break;
            case 5:
                s_year(s);
                break;
        }

    }
    return 0;
}
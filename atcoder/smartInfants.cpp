// //for each student:
//     read rating and initial school
//     call reg() to register them

// for each query:
//     read student c and destination school d
//     call dereg(c, current_school[c])
//     update current_school[c] = d
//     call reg(c, d)
//     print get_evenness()//


#include<bits/stdc++.h>
using namespace std;
#define int long long
int rating[200200];             // rating[i] = rating of student i
int current_school[200200];     // current_school[i] = school of student i

multiset<int> school_ratings[200200]; // school_ratings[i] = ratings of students in school i

multiset<int> highest_rating;        // stores highest rating from each school

void reg(int kid , int school){
    //remove potential leader 
    if(school_ratings[school].size()>0){
        int highest = *(school_ratings[school].rbegin());
        highest_rating.erase(highest_rating.find(highest));

    }
    //insert this student
    school_ratings[school].insert(rating[kid]);
    //
    // add new highest rating , add new potential leader
    int highest = *(school_ratings[school].rbegin());
    highest_rating.insert(highest);;
}
void dereg(int kid, int school){
    //remove potential leaeder 
    if(school_ratings[school].size()>0){
        int highest = *(school_ratings[school].rbegin());
        highest_rating.erase(highest_rating.find(highest));
    }
    //remove this student
    school_ratings[school].erase(school_ratings[school].find(rating[kid]));
    // update potential leader
    if(school_ratings[school].size()>0){
        int highest = *(school_ratings[school].rbegin());
        highest_rating.insert(highest);

    }
}
int get_evennes(){
    return *(highest_rating.begin());
}
signed main(){
int n,q;
cin>> n>> q;
for(int i =1; i<=n; i++){
 cin>> rating[i]>>current_school[i];
 reg(i, current_school[i]);
}
while(q--){
    int c, d;
    cin>> c>> d;
    dereg(c, current_school[c]);
    current_school[c]= d;
    reg(c,current_school[c]);
    cout<< get_evennes()<<endl;
}
    return 0;
}
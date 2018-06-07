#include <iostream>
#include <string>

using namespace std;

bool is_edit_dist_long(string a, string b){
    int length_diff = a.length() - b.length();
    
    // char removed case
    if(length_diff == 1){ 
       
        // put a in bit vec
        int a_ind = 0;
        for(int b_ind = 0; b_ind < b.length(); b_ind++){
            if(a[a_ind] != b[b_ind] && a_ind != b_ind){
                return false;
            }
            else if(a[a_ind] != b[b_ind] ){
                b_ind--;
            }
            a_ind++;
        }
        return true;
    }
    else if(length_diff == -1){
        int b_ind = 0;
        for(int a_ind = 0; a_ind < a.length(); a_ind++){
            if(b[b_ind] != a[a_ind] && a_ind != b_ind){
                return false;
            }
            else if(a[a_ind] != b[b_ind]){
                a_ind--;
            }
            b_ind++;
        }
        return true;
    }
    
    else if(length_diff == 0){
        bool skipped_one = false;
        
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i] && skipped_one){
                return false;
            }
            else if(a[i] != b[i]){
                skipped_one = true;
            }
        }
        return true;
    }
    
    else{
        return false;
    }
}

bool is_edit_dist_short(string a, string b){
    int length_diff = a.length() - b.length();
    
    // char removed case
    if(length_diff <=1 && length_diff >= -1){ 
       bool skipped = false;
        int b_ind = -1;
        for(int a_ind = 0; a_ind < a.length()-length_diff; a_ind++){
            b_ind++;
            if(a[a_ind] == b[b_ind]){
                continue;
            }
            else if(skipped){
                return false;
            }
            else if(length_diff == 1){
                a_ind++; // a had a char added to it. Increase a's ind
                skipped = true;
            }
            else if(length_diff == -1){
                b_ind++;
                skipped = true;
            }
            else{
                skipped = true;
            }
        }
        return true;
    }
    else{
        return false;
    }
}


int main(){

    while(true){
        cout << "Enter two strings: ";
        
        string a,b;
        
        cin >> a >> b;
        
        bool result = is_edit_dist_short(a,b);
        
        cout << "Result of is permutation is: " << result << endl;
    }
}




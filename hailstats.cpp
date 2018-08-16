// Hailstats
#include <iostream>
#include <map>

using namespace std;

//Declaration or Prototype
int counter( int );

int main( int argc, char *argv[] ) {
   
    int user_input_1;
    int user_input_2;
    int user_length;
    int user_range;
    int min_length_key;
    int min_length_value;
    int max_length_key;
    int max_length_value;
    int tmp, tmp2;
    map<int, int> m;
   
    cout << "Enter a range you want to search between 10 and 100: ";
    cin >> user_input_1;
    cin >> user_input_2;
   
    if ( user_input_1 > user_input_2 )
    {   
        cout << "Invalid range." << endl;
    }
    else
    {   
        user_range = (user_input_2 - user_input_1);
      
        for ( int i = 0; i < user_range + 1; ++i )
        {
            user_length = counter( user_input_1 + i );
            m.insert( pair<int, int>(user_input_1 + i, user_length) );
        }
    }
   
    map<int, int>::iterator it = m.begin();
    tmp = m[ user_input_1 ];                //return value at index 0
    cout << it->first << " : " << it->second << endl;
    it++;                                   // Start at index 1 (value)

    // Minimum length stars here
    while ( it != m.end() )
    {
        cout << it->first << " : " << it->second << endl;
       
        if ( tmp > it->second )
        {
            min_length_value = it->second;
            min_length_key = it->first;
            tmp = min_length_value;
        }    
        it++;
    }
   
    map<int, int>::iterator it2 = m.begin();
    tmp2 = m[ user_input_1 ];                //return value at index 0
    it2++;
   
    // Maximum length stars here
    while ( it2 != m.end() )
    {       
        if ( tmp2 < it2->second )
        {
            max_length_value = it2->second;
            max_length_key = it2->first;
            tmp2 = max_length_value;
        }    
        it2++;
    }
    cout << endl;
    cout << "Minimum length: " << min_length_value << endl;
    cout << "Achieved by: " << min_length_key << endl;
    cout << "Maximum length: " << max_length_value << endl;
    cout << "Achieved by: " << max_length_key << endl;

    return 0;
}

//Definition
int counter( int user_input )
{
    int ctr = 0;            //Keep track of length that it takes to reach number 1 (counter)
   
    while ( true )
    {
        // Even
        if ( user_input % 2 == 0 )
        {
            user_input = user_input / 2;
        }
        // Odd
        else if ( user_input % 2 != 0 )
        {
            user_input = (( user_input * 3 ) + 1 );
        }
        if ( user_input == 1 )
        {
            ctr++;
            break;
        }
        ctr++;
    }
   
    return ctr;
}
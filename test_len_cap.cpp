// Author: Gabe Colbrunn
//
// String Length and Capacity Test Program
//
// Tests: int length() const;
//        int capacity() const;
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Length and capacity of an empty string
        String str;
        
        // Verify
        assert(str.length() == 0);
        assert(str.capacity() == 0);
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Length and capacity of a string with a single character
        String str("A");
        
        // Verify
        assert(str.length() == 1);
        assert(str.capacity() == 1);
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Length and capacity of a short string
        String str("Hello");
        
        // Verify
        assert(str.length() == 5);
        assert(str.capacity() == 5);
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Length and capacity of a string with large capacity
        char longStr[255];
        for (int i = 0; i < 255; i++) {
            longStr[i] = 'A' + (i % 26); // Filling the string with letters from A to Z
        }
        longStr[256 - 2] = '\0'; // Null-terminate the string
        String str(longStr);
        
        // Verify
        assert(str.length() == 254);
        assert(str.capacity() == 254);
    }
    
    {
        //------------------------------------------------------
        // Test case 5: Length and capacity of a string after modifying it
        String str("Hello");
        str[1] = 'i'; // Modify the string
        
        // Verify
        assert(str.length() == 5);
        assert(str.capacity() == 5);
    }
    
    {
        //------------------------------------------------------
        // Test case 6: Length and capacity of a very long string
        char veryLongStr[1000];
        for (int i = 0; i < 1000; i++) {
            veryLongStr[i] = 'A' + (i % 26); // Filling the string with letters from A to Z
        }
        veryLongStr[999] = '\0'; // Null-terminate the string
        String str(veryLongStr);
        
        // Verify
        assert(str.length() == 999);
        assert(str.capacity() == 999);
    }
   
    {
        //------------------------------------------------------
        // Test case 7: Length and capacity of a string after modifying it with addition
        String str("Hello ");
        String str2("World"); // Modify the string
        String result = str + str2;

        // Verify
        assert(result.length() == 11);
        assert(result.capacity() == 11);
    }

    std::cout << "Done testing length and capacity operators" << std::endl;
    return 0;
}

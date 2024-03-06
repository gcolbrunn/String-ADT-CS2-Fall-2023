// Author: Gabe Colbrunn
//
// String Constructor with char array Test Program
//
// Tests: String(const char[])
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Construct with an empty char array
        const char empty[] = "";
        String str(empty);
        
        // Verify
        assert(str.length() == 0);    // String length should be 0
        assert(str[0] == '\0');       // The string should be empty
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Construct with a single character char array
        const char singleChar[] = "A";
        String str(singleChar);
        
        // Verify
        assert(str.length() == 1);    // String length should be 1
        assert(str[0] == 'A');        // The character at position 0 should be 'A'
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Construct with a string char array
        const char text[] = "Hello, World!";
        String str(text);
        
        // Verify
        assert(str.length() == 13);   // String length should be 13
        assert(str[0] == 'H');        // The character at position 0 should be 'H'
        assert(str[5] == ',');        // The character at position 5 should be ','
        assert(str[12] == '!');       // The character at position 12 should be '!'
        assert(str[13] == '\0');
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Construct with a null-terminated char array
        const char nullTerminated[] = {'F', 'o', 'o', '\0'};
        String str(nullTerminated);
        
        // Verify
        assert(str[0] == 'F');        // The character at position 0 should be 'F'
        assert(str[2] == 'o');        // The character at position 2 should be 'o'
    }

    {
        //------------------------------------------------------
        // Test case 5: Construct with a long character array
        const char longText[] = "This is a very long text string but my dynamic memory doesn't have a size limit so I can't exceed the capacity even if I tried.";
        String str(longText);
        
        // Verify
        assert(str[20] == 't');       // The character at position 20 should be 't'
        assert(str[127] == '\0');     // The last character should be the null terminator
    }

    std::cout << "Done testing String(const char[]) constructor" << std::endl;
    return 0;
}

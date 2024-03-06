// Author: Gabe Colbrunn
//
// String Copy Constructor Test Program
//
// Tests: String::String(const String&)
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Copy constructor with an empty string
        String emptyStr;
        String copy(emptyStr);
        
        // Verify
        assert(copy.length() == 0);      // Copy length should be 0
        assert(copy[0] == '\0');         // Copy should be empty
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Copy constructor with a single character string
        String str("A");
        String copy(str);
        
        // Verify
        assert(copy.length() == 1);      // Copy length should be 1
        assert(copy[0] == 'A');          // Copy should have the same character
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Copy constructor with a string
        String str("Hello, World!");
        String copy(str);
        
        // Verify
        assert(copy.length() == 13);     // Copy length should be 13
        assert(copy[0] == 'H');          // Copy should have the same content
        assert(copy[5] == ',');
        assert(copy[12] == '!');
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Copy constructor with a long string
        String longStr("This is a very long text string that used to exceed the capacity of the String class, but with dynamic memory it no longer does. This is a very long text string that exceeds the capacity of the String class.This is a very long text string that exceeds the capacity of the String class.This is a very long text string that exceeds the capacity of the String class.");
        String copy(longStr);
        
        // Verify
        assert(copy.length() == 363);    // Copy length should be 363
        assert(copy[20] == 't');         // Copy should have the same content
        assert(copy[364] == 0);
    }

    {
        //------------------------------------------------------
        // Test case 5: Copy constructor with a string containing numbers
        String str("12345");
        String copy(str);
        
        // Verify
        assert(copy.length() == 5);      // Copy length should be 5
        assert(copy[0] == '1');          // Copy should have the same content
        assert(copy[2] == '3');
        assert(copy[4] == '5');
    }
    
    {
        //------------------------------------------------------
        // Test case 6: Copy constructor with a string containing spaces
        String str("   Space   ");
        String copy(str);
        
        // Verify
        assert(copy.length() == 11);     // Copy length should be 11
        assert(copy[0] == ' ');          // Copy should have the same content
        assert(copy[3] == 'S');
        assert(copy[7] == 'e');
        assert(copy[11] == '\0');
    }
    
    {
        //------------------------------------------------------
        // Test case 7: Copy constructor with a string containing special characters
        String str("!@#$%^&*()_+");
        String copy(str);
        
        // Verify
        assert(copy.length() == 12);     // Copy length should be 12
        assert(copy[0] == '!');          // Copy should have the same content
        assert(copy[2] == '#');
        assert(copy[10] == '_');
    }
    
    {
        //------------------------------------------------------
        // Test case 8: Copy constructor with a string containing mixed characters
        String str("Ab1#cD*");
        String copy(str);
        
        // Verify
        assert(copy.length() == 7);      // Copy length should be 7
        assert(copy[0] == 'A');          // Copy should have the same content
        assert(copy[2] == '1');
        assert(copy[6] == '*');
    }

    std::cout << "Done testing copy constructor" << std::endl;
    return 0;
}

// Author: Gabe Colbrunn
//
// String substr Test Program
//
// Tests: String substr(int, int)
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Extract substring "world" from "Hello, world!"
        String str("Hello, world!");
        String subStr = str.substr(7, 11);
        
        // Verify
        assert(subStr == "world");
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Extract substring "Hello" from "Hello, world!"
        String str("Hello, world!");
        String subStr = str.substr(0, 4);
        
        // Verify
        assert(subStr == "Hello");
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Extract substring "is a" from "This is a test."
        String str("This is a test.");
        String subStr = str.substr(5, 8);
        
        // Verify
        assert(subStr == "is a");
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Extract substring "a test." from "This is a test."
        String str("This is a test.");
        String subStr = str.substr(8, 15);
        
        // Verify
        assert(subStr == "a test.");
    }
    
    {
        //------------------------------------------------------
        // Test case 5: Extract nonexistent substring from "Hello, world!"
        String str("Hello, world!");
        String subStr = str.substr(100, 101);
        
        // Verify
        assert(subStr == "");
    }

    {
        //------------------------------------------------------
        // Test case 6: Extract substring from an empty string
        String str("");
        String subStr = str.substr(0, 0);
        
        // Verify
        assert(subStr == "");
    }
    
    {
        //------------------------------------------------------
        // Test case 7: Extract substring from an empty string with negative start
        String str("");
        String subStr = str.substr(-2, 5);
        
        // Verify
        assert(subStr == "");
    }
    
    {
        //------------------------------------------------------
        // Test case 8: Extract substring with negative (impossible) length, should be empty
        String str("This is a test.");
        String subStr = str.substr(6, 5);
        
        // Verify
        assert(subStr == "");
    }
    
    {
        //------------------------------------------------------
        // Test case 9: Extract substring from the middle of a long string
        String str("This is a very long string with multiple words.");
        String subStr = str.substr(8,26);
        
        // Verify
        assert(subStr == "a very long string ");
    }

    {
        //------------------------------------------------------
        // Test case 10: Negative starting position, should treat start as position 0
        String str("Negative start");
        String subStr = str.substr(-5, 7);
        
        // Verify
        assert(subStr == "Negative");
    }

    {
        //------------------------------------------------------
        // Test case 11: Ending position greater than the length, substring should end at the end of the string
        String str("Substring test");
        String subStr = str.substr(10, 200);
        
        // Verify
        assert(subStr == "test");
    }

    {
        //------------------------------------------------------
        // Test case 12: Starting position of 0, ending position is the length of the string
        String str("Equal Substring");
        String subStr = str.substr(0, str.length());
        
        // Verify
        assert(subStr == "Equal Substring");
    }

    {
        //------------------------------------------------------
        // Test case 13: Negative start position and ending position greater than the length,
        // substring should be the same as the string
        String str("Hello, World");
        String subStr = str.substr(-5, 200);
        
        // Verify
        assert(subStr == "Hello, World");
    }

    {
        //------------------------------------------------------
        // Test case 14: Start and ending positions one digit apart
        String str("Hello, world");
        String subStr = str.substr(1, 2);
        
        // Verify
        assert(subStr == "el");
    }

    {
        //------------------------------------------------------
        // Test case 15: Start and ending positions the same
        String str("Hello, world");
        String subStr = str.substr(1, 1);
        
        // Verify
        assert(subStr == "e");
    }

    std::cout << "Done testing substr operator" << std::endl;
    return 0;
}

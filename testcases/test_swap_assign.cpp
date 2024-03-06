// Author: Gabe Colbrunn
//
// test_swap_assign.cpp
//
// Tests: swap, operator= (assignment)
// 

#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Swap two non-empty strings
        String str1("Apple");
        String str2("Banana");
        
        // Perform swap
        str1.swap(str2);
        
        // Verify
        assert(str1 == "Banana"); // str1 should be "Banana"
        assert(str2 == "Apple");  // str2 should be "Apple"
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Swap an empty string with a non-empty string
        String str1("");
        String str2("Cherry");
        
        // Perform swap
        str1.swap(str2);
        
        // Verify
        assert(str1 == "Cherry"); // str1 should be "Cherry"
        assert(str2 == "");      // str2 should be empty
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Assign a non-empty string to an empty string
        String str1("Grapes");
        String str2("");
        
        // Perform assignment
        str2 = str1;
        
        // Verify
        assert(str1 == "Grapes"); // str1 should be "Grapes"
        assert(str2 == "Grapes"); // str2 should also be "Grapes"
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Assign an empty string to a non-empty string
        String str1("Orange");
        String str2("Pear");
        
        // Perform assignment
        str1 = str2;
        
        // Verify
        assert(str1 == "Pear");   // str1 should be "Pear"
        assert(str2 == "Pear");   // str2 should also be "Pear"
    }

    {
        //------------------------------------------------------
        // Test case 5: Swap two empty strings
        String str1("");
        String str2("");
        
        // Perform swap
        str1.swap(str2);
        
        // Verify
        assert(str1 == ""); // str1 should be empty
        assert(str2 == ""); // str2 should be empty
    }

    {
        //------------------------------------------------------
        // Test case 6: Assign a non-empty string to itself
        String str1("Lemon");
        
        // Perform assignment
        str1 = str1;
        
        // Verify
        assert(str1 == "Lemon"); // str1 should remain "Lemon"
    }

    {
        //------------------------------------------------------
        // Test case 7: Swap two identical non-empty strings
        String str1("Strawberry");
        String str2("Strawberry");
        
        // Perform swap
        str1.swap(str2);
        
        // Verify
        assert(str1 == "Strawberry"); // str1 should still be "Strawberry"
        assert(str2 == "Strawberry"); // str2 should still be "Strawberry"
    }

    {
        //------------------------------------------------------
        // Test case 8: Assign an empty string to itself
        String str1("");
        
        // Perform assignment
        str1 = str1;
        
        // Verify
        assert(str1 == ""); // str1 should remain empty
    }

    std::cout << "Additional test cases completed." << std::endl;

    std::cout << "Done testing swap and assignment operators" << std::endl;
    return 0;
}

// Author: Gabe Colbrunn
//
// String Input Test Program
//
// Tests: friend std::istream& operator>>(std::istream&, String&);
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    // Commented out so you don't have to do input process everytime
    // Uncomment to test input
    /*
    {
        //------------------------------------------------------
        // Test case 1: Input a string with characters
        String str;
        std::cout << "Enter this string: 'Hello'";
        std::cin >> str;
        std::cout << str << std::endl;
        // Verify
        assert(str == "Hello");
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Input a string with spaces
        String str;
        std::cout << "Enter this string with spaces: 'Hello World'";
        std::cin >> str;
        std::cout << str;
        
        // Verify First Word
        assert(str == "Hello");

        // Verify Second Word
        std::cin >> str;
        std::cout << " " << str << std::endl;
        assert(str == "World");
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Input a string with digits
        String str;
        std::cout << "Enter this string with digits: '12345'";
        std::cin >> str;
        std::cout << str << std::endl;
        // Verify
        assert(str == "12345");
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Input an empty string
        String str;
        std::cout << "Enter a space and an exclamation point: ' !'";
        std::cin >> str;
        std::cout << str << std::endl;
        // Verify
        assert(str == "!");
    }
    */
    
    std::cout << "Done testing input operator" << std::endl;
    return 0;
}

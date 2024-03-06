// Author: Gabe Colbrunn
//

#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {
    {
        //------------------------------------------------------
        // Test case 1: Split a string with multiple characters
        String str("123:456:789:0");
        std::vector<String> parts = str.split(':');

        // Verify
        assert(parts.size() == 4);
        assert(parts[0] == "123");
        assert(parts[1] == "456");
        assert(parts[2] == "789");
        assert(parts[3] == "0");
    }

    {
        //------------------------------------------------------
        // Test case 2: Split a string starting with a delimiter
        String str(":apple:banana:cherry");
        std::vector<String> parts = str.split(':');

        // Verify
        assert(parts.size() == 4);
        assert(parts[0] == "");
        assert(parts[1] == "apple");
        assert(parts[2] == "banana");
        assert(parts[3] == "cherry");
    }

    {
        //------------------------------------------------------
        // Test case 3: Split a string ending with a delimiter
        String str("apple,banana,cherry,");
        std::vector<String> parts = str.split(',');

        // Verify
        assert(parts.size() == 4);
        assert(parts[0] == "apple");
        assert(parts[1] == "banana");
        assert(parts[2] == "cherry");
        assert(parts[3] == "");
    }

    {
        //------------------------------------------------------
        // Test case 4: Split a string with multiple character delimiter
        String str("applebanana.cherrymelon");
        std::vector<String> parts = str.split('.');

        // Verify
        assert(parts.size() == 2);
        assert(parts[0] == "applebanana");
        assert(parts[1] == "cherrymelon");
    }

    {
        //------------------------------------------------------
        // Test case 5: Split a string using a letter as a delimiter
        String str("AappleBbananaCcherry");
        std::vector<String> parts = str.split('B');

        // Verify
        assert(parts.size() == 2);
        assert(parts[0] == "Aapple");
        assert(parts[1] == "bananaCcherry");
    }

    {
        //------------------------------------------------------
        // Test case 6: Split a string using a number as a delimiter
        String str("1apple234banana567cherry");
        std::vector<String> parts = str.split('4');

        // Verify
        assert(parts.size() == 2);
        assert(parts[0] == "1apple23");
        assert(parts[1] == "banana567cherry");
    }

    {
        //------------------------------------------------------
        // Test case 7: Split a string using a space as a delimiter
        String str("apple banana cherry melon ");
        std::vector<String> parts = str.split(' ');

        // Verify
        assert(parts.size() == 5);
        assert(parts[0] == "apple");
        assert(parts[1] == "banana");
        assert(parts[2] == "cherry");
        assert(parts[3] == "melon");
        assert(parts[4] == "");        
    }

    std::cout << "Done testing split function" << std::endl;
    return 0;
}

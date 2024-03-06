// Author: Gabe Colbrunn
//
// String Concatenation Test Program
//
// Tests: String& operator+= (const String&)
//        String operator+ (String, const String&)
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Test case 1: Concatenate two empty strings using operator+=
        String empty1;
        String empty2;
        
        // Perform concatenation
        empty1 += empty2;
        
        // Verify
        assert(empty1.length() == 0); // Resulting string should be empty
    }
    
    {
        //------------------------------------------------------
        // Test case 2: Concatenate an empty string with a non-empty string using operator+=
        String empty;
        String nonEmpty("Apple");
        
        // Perform concatenation
        empty += nonEmpty;

        // Verify
        assert(empty == "Apple"); // Resulting string should be "Apple"
    }
    
    {
        //------------------------------------------------------
        // Test case 3: Concatenate two non-empty strings using operator+=
        String str1("Banana");
        String str2("Grapes");
        
        // Perform concatenation
        str1 += str2;
        
        // Verify
        assert(str1 == "BananaGrapes"); // Resulting string should be "BananaGrapes"
    }
    
    {
        //------------------------------------------------------
        // Test case 4: Concatenate two empty strings using operator+
        String empty1;
        String empty2;
        // Perform concatenation
        String result = empty1 + empty2;

        // Verify
        assert(result.length() == 0); // Resulting string should be empty
    } 

    {
        //------------------------------------------------------
        // Test case 5: Concatenate an empty string with a non-empty string using operator+
        String empty;
        String nonEmpty("Orange");
        
        // Perform concatenation
        String result = nonEmpty + empty;
        
        // Verify
        assert(result == "Orange"); // Resulting string should be "Orange"
    }

    {
        //------------------------------------------------------
        // Test case 6: Concatenate two non-empty strings using operator+
        String str1("Pineapple");
        String str2("Watermelon");
        
        // Perform concatenation
        String result = str1 + str2;

        std::cout << result << std::endl;
        
        // Verify
        assert(result == "PineappleWatermelon"); // Resulting string should be "PineappleWatermelon"
    }

    {
        //------------------------------------------------------
        // Test case 7: Concatenate two non-empty strings using operator+=
        String str1("Cherry");
        String str2("Strawberry");
        
        // Perform concatenation
        str1 += str2;
        
        // Verify
        assert(str1 == "CherryStrawberry"); // Resulting string should be "CherryStrawberry"
    }

    {
        //------------------------------------------------------
        // Test case 8: Concatenate two long strings using operator+=
        String longStr1("This is a very long string. ");
        String longStr2("And this is another very long string. ");
        
        // Perform concatenation
        longStr1 += longStr2;
        
        // Verify
        assert(longStr1 == "This is a very long string. And this is another very long string. ");
    }

    {
        //------------------------------------------------------
        // Test case 9: Concatenate two very long equal strings using operator+=
        const char longWord[] = "Supercalifragilisticexpialidocious";
        String longStr1(longWord);
        String longStr2(longWord);
        
        // Perform concatenation
        longStr1 += longStr2;
        
        // Verify
        assert(longStr1 == "SupercalifragilisticexpialidociousSupercalifragilisticexpialidocious"); // Resulting string should be twice as long
    }

    {
        //------------------------------------------------------
        // Test case 10: Concatenate two long strings using operator+
        String longStr3("Antidisestablishmentarianism");
        String longStr4("Hippopotomonstrosesquipedaliophobia");
        
        // Perform concatenation
        String result = longStr3 + longStr4;
        
        // Verify
        assert(result == "AntidisestablishmentarianismHippopotomonstrosesquipedaliophobia"); // Resulting string should be longer
    }

    {
        //------------------------------------------------------
        // Test case 11: Concatenate a very long string with a shorter one using operator+
        const char longWord[] = "Supercalifragilisticexpialidocious";
        String veryLongStr(longWord);
        String shortStr("Short");
        
        // Perform concatenation
        String result = veryLongStr + shortStr;
        
        // Verify
        assert(result.length() > veryLongStr.length()); // Resulting string should be longer
    }

    {
        //------------------------------------------------------
        // Test case 12: Concatenate a short string with a very long one using operator+
        String shortStr("Short");
        const char longWord[] = "Supercalifragilisticexpialidocious";
        String veryLongStr(longWord);
        
        // Perform concatenation
        String result = shortStr + veryLongStr;
        
        // Verify
        assert(result.length() > veryLongStr.length()); // Resulting string should be longer
    }

    std::cout << "Done testing concatenation operators" << std::endl;
    return 0;
}

// Author: Gabe Colbrunn
//
// String Default Constructor Test Program
//
// Tests: String()
// 

#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main() {
    
    {
        //------------------------------------------------------
        // Setup fixture
        
        // Test 
        String str;
        
        // Verify
        assert(str.length() == 0); // The default-constructed string should have length 0
        assert(str.capacity() == 0); // The default capacity should be the same as length
    }

    std::cout << "Done testing String default constructor" << std::endl;
    return 0;
}

string removeDuplicates(string str) {
	    char mapping[256]={0};
	    string ans="";
	    for(auto it:str){
	        if(mapping[static_cast<unsigned char>(it-'a')]==0){
	            ans.push_back(it);
	            mapping[static_cast<unsigned char>(it-'a')]=1;
	        }
	    }
	    return ans;
}
// time complexity:O(n)

// In C++, the static_cast is a type of casting operator that performs compile-time type checking. In the context of your code, static_cast<unsigned char>(it) is used to explicitly cast the variable it to an unsigned char type

// It ensures that the ASCII value of the character it is within the valid range of the mapping array, preventing potential issues related to negative values or values outside the range of 0 to 255 (assuming ASCII characters). This helps avoid undefined behavior, such as accessing an array out of bounds, and ensures correct behavior when dealing with character values in array indices.
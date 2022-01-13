#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void printArray( VECTOR<int>& theArray ){
	
	COUT << "[";
	
	for(long unsigned int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray.at(iter);
		
		if( iter < theArray.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}
//Function to find maximum 
int maximum(int p, int i) {
	if(i > p)
		return i;
	else
		return p;
}

// Function to find minimum
int minimum(int p, int i) {
	if(i < p)
		return i;
	else
		return p;
}

int max_prod_sub( VECTOR<int>& theArray ) {
	
	// Your work goes here

	if(theArray.size() == 0)
		return 0;

	int max = theArray.at(0);
	int min = theArray.at(0);
	int product = theArray.at(0);

	for(unsigned int i = 1; i < theArray.size(); i++) {

		if(theArray.at(i) < 0) {
			int temp = max;
			max = min;
			min = temp;

		}

		max = maximum(max*theArray.at(i), theArray.at(i));
		min = minimum(min*theArray.at(i), theArray.at(i));
		product = maximum(product, max);

	}

	return product;
	
}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
		
	}	
	
	printArray(the_array);
	COUT << ENDL;
	COUT << "Max Product Subarray Solution = " << max_prod_sub(the_array) << ENDL;
	
	return EXIT_SUCCESS;
}


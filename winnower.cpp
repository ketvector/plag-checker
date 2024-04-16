#include"preprocess.hpp"
#include"hasher.hpp"
#include"winnower.hpp"


vector<hash_structure> selectFingerPrint(vector<hash_structure> H , int w)
{
	vector<hash_structure> F ;
	int len = H.size() ;
	int relIndex = -1 ;
	for(int i = w-1 ,k = 0 ; i < len ; i++ , k++ )
	{
		// Start of a new window
		if(relIndex == -1)
		{
			long long min = H[i].hash;
			int minIndex = i ;
			//select the minimum from this window
			for(int j = i-1 ; j > i-w ; j--)
			{
				if(H[j].hash < min)
				{
					minIndex = j;
					min = H[j].hash ;
				}	
			}
			//add the minimum to the fingerprint
			F.push_back(H[minIndex]);
			relIndex = minIndex-(i-w+1) ;
			cout << minIndex << "a" << relIndex << endl;
		}
		else
		{
			// Minimum exists in the previous window
			if(H[k+relIndex].hash <= H[i].hash)
			{
				//
			}
			// New minimum in this window , add it fingerprint.
			else
			{
				F.push_back(H[i]);
				relIndex = w-1;
				cout << i << "b" << relIndex <<endl ;
			}	
		}
		relIndex--;
	}
	//return the Fingerprint.
	return F;	
}

#include"preprocess.hpp"
#include"hasher.hpp"
#include"winnower.hpp"
#include"finger_main.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<unordered_map>
int main(int argc , char** argv)
{
	if(argc == 4)
	{
		// file_one -> first C file . file_two -> second C file.  file_three -> Text file with relevant locations for keyword,comments.
		char* file_one = argv[1] , *file_two = argv[2] , *file_three = argv[3] ;
		FILE* data_file = fopen(file_three , "r");
		char** data = (char**)malloc(sizeof(char*)*4);
		for(int i = 0 ; i < 4 ; i++)
		{
			data[i] = (char*)malloc(sizeof(char)*20);
			fscanf(data_file , "%s", data[i] );
			printf("%s\n",data[i]);
		}
		fclose(data_file);
		char* keywordFile = data[0]  , *noIdFile = data[1] , *singleCommFile= data[2] , *multiCommFile = data[3];
		
		//create fingerprint of first file.
		vector<hash_structure> finger_one = fingerprintDocument(file_one,data);
		
		//create fingerprint of second file.
		vector<hash_structure> finger_two = fingerprintDocument(file_two,data);
		
		// map to store the fingerprint of first file.
		map<long long , pair<int,int> > h1 ;
		
		// vector to store the matched hashesh.
		vector<pair <hash_structure,hash_structure> > h2 ;
		for(vector<hash_structure>::iterator it = finger_one.begin() ; it != finger_one.end() ; ++it)
		{
			hash_structure x = *it ;
			pair<int,int> newp =  {x.start,x.end};
			pair<long long , pair<int,int> > y = {x.hash , newp} ;
			h1.insert(y);
		}
		
		// Find out all the matches in the two fingerprints.
		for(vector<hash_structure>::iterator it = finger_two.begin() ; it != finger_two.end() ; ++it)
		{
			hash_structure x = *it ;
			map<long long , pair<int,int> >::iterator i =  h1.find(x.hash) ;
			if( i !=  h1.end() )
			{
				hash_structure y ; y.hash = (*i).first ; y.start = (*i).second.first ; y.end = (*i).second.second ;
				pair<hash_structure , hash_structure> p = {x,y};
				h2.push_back(p);
			}
		}
		
		// Report the results.
		int one_size = finger_one.size() , two_size = finger_two.size() ;
		int match_size = h2.size();
		cout << match_size<<endl;
		cout << one_size << endl ;
		cout << two_size << endl ;
		double one_match_percent = ( ((double)match_size) / ((double)one_size) ) * 100 ;
		double two_match_percent = ( ((double)match_size) / ((double)two_size) ) * 100 ;
		fstream tout("testdata.txt",std::fstream::in | std::fstream::out | std::fstream::app);
		tout << file_one << "\t" << file_two << "\t" << one_match_percent <<"\t" << two_match_percent << endl ;
	}
}

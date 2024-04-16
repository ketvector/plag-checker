#include"preprocess.hpp"
#include"hasher.hpp"
#include"winnower.hpp"
#include"finger_main.hpp"
#include<stdio.h>
vector<hash_structure> fingerprintDocument(char* file , char** argv)
{
	static int id = 0 ;
	id++;
	// Read the source file and all relevant data into memory.
	char* inputFile = file , *keywordFile = argv[0]  , *noIdFile = argv[1] , *singleCommFile= argv[2] , *multiCommFile = argv[3];
	string textToProcess = readInputFile(inputFile);
	unordered_set<string> keywords = readList(keywordFile);
	unordered_set<string> noId = readList(noIdFile);
	vector<string> singleComm  = readListV(singleCommFile);
	vector<string> multiComm  = readListV(multiCommFile);
	
	/* Process the source file. The Sequence of events is : source-file --> convert to lower case --> remove comments from source and 
	   collect them into a vector --> create spaces between punctuations -->  replace all identifiers with "v" --> remove all 
	   non-newline whitespace. */
	lowerCase(textToProcess) ;
	
	vector<string> V = collectComments(textToProcess,singleComm,multiComm);
	
	createSpace(textToProcess);
	
	textToProcess = removeIdentifiers(textToProcess,noId,keywords);
	
	removeWhiteSpace(textToProcess);
	//Preprocessing over.
	
	char clonefile[20] ;
	sprintf(clonefile,"clone_%d.c",id);
	ofstream fout(clonefile);
	fout << textToProcess;
	
	//hashing starts.
	vector<info> V1= getInfo(textToProcess); //Store the string with line numbers and character ranges.
	char infofile[20] , stringfile[20] ;
	sprintf(infofile,"info_%d",id);sprintf(stringfile,"stringfile_%d",id); 
	ofstream infout(infofile) , ftout(stringfile);
	ftout << textToProcess ;
	for(vector<info>::iterator it = V1.begin() ; it != V1.end() ; it++)
		infout << (*it).line << "\t" << (*it).start << "\t" << (*it).end << endl ;
	
	//Main hashing
	vector<hash_structure> V2 = generateHashes(textToProcess,3,999983,V1);
	char hashfile[20];
	sprintf(hashfile,"hashfile_%d",id);
	ofstream hasout(hashfile);
	for(vector<hash_structure>::iterator it = V2.begin() ; it != V2.end() ; it++)
		hasout << (*it).hash << "\t" << (*it).start << "\t" << (*it).end << endl ;
	
	//MAIN WINNOWING ALGORITHM
	vector<hash_structure> V3 = selectFingerPrint(V2,4);
	char fingerfile[20];
	sprintf(fingerfile,"fingerfile_%d",id);
	ofstream fingout(fingerfile);
	for(vector<hash_structure>::iterator it = V3.begin() ; it != V3.end() ; it++)
		fingout << (*it).hash << "\t" << (*it).start << "\t" << (*it).end << endl ;
	return  V3;
}


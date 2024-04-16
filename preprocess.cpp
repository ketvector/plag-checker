#include"preprocess.hpp"
string readInputFile(char* inputFile)
{
	ifstream myFile (inputFile);
	stringstream buffer;
	buffer << myFile.rdbuf();
	string myStr(buffer.str());
	return myStr ;
}
vector<string> readListV(char* file)
{
	ifstream myFile (file) ;
	string str ;
	vector<string> V;
	while(getline(myFile,str))
		V.push_back(str);
	return V;
}
unordered_set<string> readList(char* listFile)
{
	ifstream myFile (listFile) ;
	string str ;
	unordered_set<string> h;
	while(getline(myFile,str))
		h.insert(str);
	return h;
}
void switchText(string& a , string &b)
{
	a.assign(b);
	b.clear();
}
void lowerCase(string& a)
{
	transform(a.begin() , a.end() , a.begin() , [&](char c){ return tolower(c); });
}
string removeIdentifiers(string &a , unordered_set<string>& noId , unordered_set<string>& keywords)
{
	stringstream fss ;
	stringstream as(a) ;
	string str ;
	// break the input at newlines.
	while(getline(as,str,'\n'))
	{
		str = trim(str);
		// if empty line (maybe left by the user , maybe comment removed)
		if(str.empty() )
			str.assign("$");
		//is the first token in this line , a # or something,then add this line as is to the output.
		vector<string> V = splitString(str);
		unordered_set<string>::iterator got = noId.find(V[0]);
		if(got != noId.end())
		{
			fss << str << endl ;
		}
		
		
		else
		{
			stringstream nl ;
			// regular expression for an identifier.
			string pattern = "^[a-z_][a-z0-9_]*$" ;
			boost::regex idr(pattern) ;
			for(vector<string>::iterator it = V.begin() ; it != V.end() ; it++)
			{
				// if the token matches the regular expression , check if its a keyword.
				if(boost::regex_match(*it , idr))
				{
					got = keywords.find(*it);
					// if a keyword , then don't change it.
					if(got != keywords.end())
					{
						nl << *it << " ";
					}
					// if not a keyword , replace the identifier by a v.
					else
					{
						(*it).assign(" v ");
						nl << *it ;
					}
					
				}
				else
					nl << *it << " " ;
			}
			// put the newline back into the output stream.
			fss << nl.str() << endl ;
		}
	}
	string rts(fss.str()) ;
	//cout << rts << endl;
	return rts;
}
string trim(string& str,const std::string& whitespace )
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
vector<string> splitString(string& a)
{
	istringstream iss(a);
	vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
	return tokens;
}
vector<string> collectComments(string& a , vector<string>& single , vector<string>& multi)
{
	vector<string> V;
	bool multiline = false ;
	stringstream as(a);
	string str ;
	stringstream fss;
	int found;
	//read it line by line.
	while(getline(as,str,'\n'))
	{
		str = trim(str);
		// if already in a multiline
		if(multiline == true)
		{
			//does it end in the middle
			if (str.find(multi[1]) != string::npos)
			{
				V.push_back(str);
				fss << endl ;
				multiline = false;
				continue;
			} 
			else
			{
				V.push_back(str);
				fss << endl ;
				continue;
			}
		}
		bool singleline = false ;
		for(vector<string>::iterator it = single.begin() ; it != single.end() ; ++it)
		{
			//Checks for a match at the start of a line .
			auto res = mismatch((*it).begin() , (*it).end() , str.begin());
			if( res.first == (*it).end() )
			{
				singleline = true;
				V.push_back(str);
				fss << endl ;
				break;
			}
			//Checks for a match in the middle of the line.
			if( (found = str.find(*it) ) != string::npos)
			{
				string temp(str.begin() + found + (*it).length() , str.end());
				V.push_back(temp);
				str.assign(str.begin() , str.begin() + found);
			}
		}
		// Is there a multiline at the start
		auto res = mismatch(multi[0].begin() , multi[0].end() , str.begin());
		if( res.first == multi[0].end() )
		{
			multiline = true;
			// Does the multiline end in the middle
			if( ( found = str.find(multi[1]) ) != string::npos)
			{
				string temp(str.begin() , str.begin() + found + multi[1].length());
				V.push_back(temp);
				str.assign(str.begin() +found +multi[1].length()  , str.end() );
				multiline = false;
			}
			//If it does not , add it to the comments vector.
			else
			{
				V.push_back(str);
				fss << endl ;
			}
		}
		//if not a comment , add to the result string.
		if(singleline == false && multiline == false)
			fss << str << endl ;
	}
	string rts(fss.str());
	a = rts ;
	return V ;
} 
void replaceAll(std::string& str, const std::string& from, const std::string& to) 
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) 
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
void createSpace(string& a)
{
  
	pair<string,string> arr[] = { {"{"," { "} , {"}"," } "} , {"["," [ "} , {"]"," ] "} , {"(", " ( " }  , { ")"," ) "} ,
								{"+"," + " } , {"-"," - "}	, {"="," = "} , {":"," : "} , {"<"," < "} , {">"," > "}  , {"," ," , "}	, {"&"," & "}} ;
	for(int i =0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
		replaceAll(a,arr[i].first,arr[i].second);
}
void removeWhiteSpace(string& a)
{
	replaceAll(a," ","");
	replaceAll(a,"\t","");
}

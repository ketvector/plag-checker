#define BASE 256 
typedef struct Info
{
	int line , start , end ;
}info;
typedef struct Hash_Structure
{
	long long hash ;
	int start ,end ;
}hash_structure;
long long mod(long long a , long long m);
vector<hash_structure> generateHashes(string& a , long long  k , long long q , vector<info> I);
vector<info> getInfo(string& a);
int findline(int i , vector<info> I);

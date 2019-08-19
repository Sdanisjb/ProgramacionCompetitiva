#include <iostream>
#include <string>

using namespace std;

string r_horizontal(string cubo){
	string aux = cubo;
	aux[0] = cubo[4];
	aux[1] = cubo[0];
	aux[5] = cubo[1];
	aux[4] = cubo[5];
	
	return aux;
}

string r_vertical(string cubo){
	string aux = cubo;
	aux[1] = cubo[2];
	aux[3] = cubo[1];
	aux[4] = cubo[3];
	aux[2] = cubo[4];
	
	return aux;
}


string existe(string cuboA, string cuboB, unsigned short it = 0){
	if(cuboA == cuboB) return "TRUE";
	if(it > 4) return "FALSE";
	if(existe(r_horizontal(cuboA),cuboB,it+1) == "TRUE") return "TRUE";
	if(existe(r_vertical(cuboA),cuboB,it+1) == "TRUE") return "TRUE";
	return "FALSE";
}




int main() {
	string input;
	while(cin>>input){
		cout<<existe(input.substr(0,6),input.substr(6))<<endl;
	}
	
	return 0;
}


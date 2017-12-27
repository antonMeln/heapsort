#include <iostream>
#include <sstream>
using namespace std;

bool read(int n,int *a) {
	string str;
	getline(cin, str);
	istringstream stream(str);
	for (unsigned int i = 0; i < n; ++i) {
		if (!(stream >> a[i])) {
			return false;
		}
	}
	return true;
}

void heap(int n,int *a) {
	
	while (1)
	{ 
	  int c;
		int b = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i * 2 + 2 + c < n)
			{
				if (a[i + c] > a[i * 2 + 1 + c] || a[i + c] > a[i * 2 + 2 + c])
				{
					if (a[i * 2 + 1 + c] < a[i * 2 + 2 + c])
					{
						swap(a[i + c], a[i * 2 + 1 + c]);
						b = 1;
					}
					else if (a[i * 2 + 2 + c] < a[i * 2 + 1 + c])
					{
						swap(a[i + c], a[i * 2 + 2 + c]);
						b = 1;
					}
				}
			}
			else if (i * 2 + 1 + c < n)
			{
				if (a[i + c] > a[i * 2 + 1 + c])
				{
					swap(a[i + c], a[i * 2 + 1 + c]);
					b = 1;
				}
			}
		}
		if (!b) c++;
		if (c + 2 == n)
			break;
	}
}


int main() {
	 int i,n,j;
	 int *a = new int[n];
    
    
    string str;
    getline(cin,str);
    istringstream stream(str);
     
     if (stream >> n) {
        if (read(n,a)) {
          heap (n,a);
          
          for (int i =0;i<n;i++)
            cout << a[i] << " ";
        }
        else cout << " An error has occured while reading input data.";
     }
	delete[] a;
    return 0;
      
  }
          

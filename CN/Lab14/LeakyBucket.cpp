// program to implement leakybucket

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, output_size, input_size, bucket_size;
  
  
  int storage = 0;
  
	cout<<"Enter the no. of queries: ";
	cin>>n;

	t
  cout<<"Enter the Bucket size: ";
	cin>>bucket_size;

	
	input_pkt_size = 4;

	// no. of packets that exits the bucket at a time
  cout<<"Packet Output Rate: ";
  cin>>output_size;
  
	for (int i = 0; i < no_of_queries; i++) // space left
	{

    cout<<"Enter the Input packet size: ";
    cin>>input_size;
		int size_left = bucket_size - storage;
		if (input_pkt_size <= size_left) {
			// update storage
			storage += input_size;
		}
		else {
			printf("Packet loss = %d\n", input_size);
		}
		printf("Buffer size= %d out of bucket size= %d\n",
			storage, bucket_size);
		storage -= output_size;
	}
  
	return 0;
}

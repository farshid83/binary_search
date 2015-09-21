/*
 * search.cpp
 *
 */

#include <iostream>
using namespace std;

#define size 10
int sequence[size] = {20, 13, 3, 5, 15, 8, 34, 1, 7, 2};

void PrintSeq(int * seq)
{
	for(int i = 0; i < size; i++)
		cout << seq[i] << " ";
	cout << "\n";
}

void R_insertion(int* seq, int index)
{
	if(index == 0)
		return;
	else
	{
		R_insertion(seq, index-1);
		int i = index - 1;
		int key = seq[index];
		while((i >= 0) && (key < seq[i]))
		{
			seq[i+1] = seq[i];
			i--;
			//PrintSeq(seq);
		}
		seq[i+1] = key;
	}
}

int binary(int * seq, int i1, int i2, int key)
{
	int i3 = (i1+i2)/2;
	cout << i3 << "\n";
	if(key < seq[i3])
		return binary(seq, i1, i3-1, key);
	else if(key > seq[i3])
		return binary(seq, i3+1, i2, key);
	else if(key == seq[i3])
		return i3;
	return -1;
}

int main()
{
	//Recursive insertion sort
	R_insertion(sequence, size-1);
	PrintSeq(sequence);

	//Binary search
	int key;
	cin >> key;
	binary(sequence, 0, size-1, key);

	return 0;
}

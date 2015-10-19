#pragma once
typedef unsigned int TELEM;
class TBitField
{
	TELEM * mas;
	int size;
	int BitSize;
public:
	TBitField(int _BitSize)
	{
	   BitSize = _BitSize;
	   size = BitSize/(32)+1;
	   mas = new TELEM[size];
	   for(int i=0;i<size;i++)
	      	mas[i] = 0;
    }

	~TBitField(void);

	TBitField(const TBitField& c);
    int GetIndex(int num);
	TELEM GetMask(int num);
	void SetBit(int num);
	void ZeroBit(int num);
	int LookBit(int num);

};


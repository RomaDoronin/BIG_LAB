#include "StdAfx.h"
#include "TBitField.h"


TBitField::~TBitField(void)
{
	delete [] mas;
}

TBitField::TBitField(const TBitField& c)
{
	size = c.size;
	mas = new TELEM[size];
	for(int i=0;i<size;i++)
		mas[i]=c.mas[i];
}

int TBitField::GetIndex(int num)
{
	return(num / 32);
}

TELEM TBitField::GetMask(int num)
{
	TELEM Mask;
	Mask = Mask << num;
	return(Mask);
}


void TBitField::SetBit(int num)
{
	int m = GetIndex(num);
	TELEM Mask = GetMask(num);
	mas[m] = mas[m] | Mask;
}

void TBitField::ZeroBit(int num)
{
	int m = GetIndex(num);
	TELEM Mask = ~GetMask(num);
	mas[m] = mas[m] & Mask;
}

int TBitField::LookBit(int num)
{
	int m = GetIndex(num);
	TELEM Mask = GetMask(num);
	if (mas[m] = (mas[m] | Mask))
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
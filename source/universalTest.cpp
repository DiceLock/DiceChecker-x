//
// Creator:    http://www.dicelocksecurity.com
// Version:    vers.6.0.0.1
//
// Copyright (C) 2008-2012 DiceLock Security, LLC. All rights reserved.
//
//                               DISCLAIMER
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// DICELOCK IS A REGISTERED TRADEMARK OR TRADEMARK OF THE OWNERS.
// 

#include <stdlib.h>
#include <math.h>
#include "universalTest.h"


namespace DiceLockSecurity {
	
  namespace RandomTest {

	// Random Test Class enumerator name
	const RandomTests UniversalTest::test = Universal;
	// Random Test Class minimum stream length
	const unsigned long int	UniversalTest::minimumLength = 387840;

	// Maurer's expected value constants
	const double UniversalTest::expectedValue[17] = {
		0,0,0,0,0,0,5.2177052,6.1962507,7.1836656,
	    8.1764248, 9.1723243, 10.170032, 11.168765,
		12.168070, 13.167693, 14.167488, 15.167379};

	// Maurer's variance constants
	const double UniversalTest::variance[17] = {
		0,0,0,0,0,0,2.954,3.125,3.238,3.311,3.356,3.384,
	    3.401,3.410,3.416,3.419,3.421};

		// Constructor, default 
	UniversalTest::UniversalTest() {

		this->L = 0;
		this->Q = 0;
		this->K = 0;
		this->sigma = 0.0;
		this->phi = 0.0;
		this->sum = 0.0;
		this->expectedValueResult = 0.0;
		this->varianceResult = 0.0;
		this->bitsDiscarded = 0;
	}


	// Constructor with a MathematicalFunctions object instantiated 
	UniversalTest::UniversalTest(MathematicalFunctions* mathFuncObj) {

		this->L = 0;
		this->Q = 0;
		this->K = 0;
		this->sigma = 0.0;
		this->phi = 0.0;
		this->sum = 0.0;
		this->expectedValueResult = 0.0;
		this->varianceResult = 0.0;
		this->bitsDiscarded = 0;
	}

	// Destructor
	UniversalTest::~UniversalTest() {

		this->L = 0;
		this->Q = 0;
		this->K = 0;
		this->sigma = 0.0;
		this->phi = 0.0;
		this->sum = 0.0;
		this->expectedValueResult = 0.0;
		this->varianceResult = 0.0;
		this->bitsDiscarded = 0;
	}
	
	// Gets the BaseRandomTest random state of the last executed BaseCryptoRandomStream
	bool UniversalTest::IsRandom(void) {

		return BaseRandomTest::IsRandom();
	}

	// Tests randomness of the BaseCryptoRandomStream and returns the random value
	bool UniversalTest::IsRandom(BaseCryptoRandomStream* bitStream) {
		unsigned long int i, j, p;
		double arg, sqrt2, c;
		unsigned long int* T, decRep;

		if (bitStream->GetBitLength() < this->GetMinimumLength()) {
			this->error = InsufficientNumberOfBits;
			this->random = false;
			this->pValue = 0.0;
			return this->random;
		}
		this->error = NoError;
		bitStream->SetBitPosition(0);
		if (bitStream->GetBitLength() >= 1059061760) this->L = 16;
		else if (bitStream->GetBitLength() >= 496435200)  this->L = 15;
		else if (bitStream->GetBitLength() >= 231669760)  this->L = 14;
		else if (bitStream->GetBitLength() >= 107560960)  this->L = 13;
		else if (bitStream->GetBitLength() >= 49643520)   this->L = 12;
		else if (bitStream->GetBitLength() >= 22753280)   this->L = 11;
		else if (bitStream->GetBitLength() >= 10342400)   this->L = 10;
		else if (bitStream->GetBitLength() >= 4654080)    this->L = 9;
		else if (bitStream->GetBitLength() >= 2068480)    this->L = 8;
		else if (bitStream->GetBitLength() >= 904960)     this->L = 7;
		else if (bitStream->GetBitLength() >= 387840)     this->L = 6;

		T = NULL;
		this->Q = 10*(int)pow((double)2, (int)this->L);
		this->K = (int)((long double)floor((double)(bitStream->GetBitLength()/this->L)) - (double)this->Q);	 		    
		if ((double)this->Q < 10*pow((double)2,(int)this->L)) {
			this->random = false;
			this->error = LOrQOutOfRange;
		}
		else {
			this->varianceResult = variance[this->L];
			this->expectedValueResult = expectedValue[this->L];
			this->bitsDiscarded = bitStream->GetBitLength()-(this->Q+this->K)*this->L;
			c = 0.7 - 0.8/(double)this->L + (4 + 32/(double)this->L)*pow(this->K,-3/(double)this->L)/15;
			this->sigma = c * sqrt(this->varianceResult /(double)this->K);
			sqrt2 = sqrt((double)2);
			this->sum = 0.0;
			p = (int)pow((double)2,(int)this->L);
			T = (unsigned long int*) calloc(p, sizeof(unsigned long int));
			if (T == NULL) {
				this->error = InsufficientMemory;
				this->random = false;
				return this->random ;
			}
			for(i = 0; i < p; i++) 
				T[i] = 0;
			for(i = 1; i <= this->Q; i++) {			
				decRep = 0;
				for(j = 0; j < this->L; j++) 
					decRep += bitStream->GetBitPosition((i-1)*this->L+j) * (long)pow((double)2, (int)(this->L-1-j));
				T[decRep] = i;
			}
			for(i = this->Q+1; i <= this->Q+this->K; i++) { 	
				decRep = 0;
				for(j = 0; j < this->L; j++) 
					decRep += bitStream->GetBitPosition((i-1)*this->L+j) * (long)pow((double)2,(int)(this->L-1-j));
				this->sum += log((double)(i - T[decRep]))/log((double)2);
				T[decRep] = i;
			}
			this->phi = (double)(this->sum/(double)this->K);
			arg = fabs(this->phi-this->expectedValueResult)/(sqrt2 * this->sigma);
			this->pValue = this->mathFuncs->ErFc(arg);
			if (isNegative(this->pValue) || isGreaterThanOne(this->pValue))
	    		this->error = PValueOutOfRange;
			if (this->pValue < this->alpha) {				    
	    		this->random = false;
			}
			else {
	    		this->random = true;
			}
		}
		free(T);
		return this->random;
	}

	// Initializes the object
	void UniversalTest::Initialize(void) {

		BaseRandomTest::Initialize();
		this->L = 0;
		this->Q = 0;
		this->K = 0;
		this->sigma = 0.0;
		this->phi = 0.0;
		this->sum = 0.0;
		this->expectedValueResult = 0.0;
		this->varianceResult = 0.0;
		this->bitsDiscarded = 0;
	}

	// Gets the type of the object
	RandomTests UniversalTest::GetType(void) {

		return this->test;
	}

	// Gets the minimum random stream length
	unsigned long int UniversalTest::GetMinimumLength(void) {

		return this->minimumLength;
	}

	// Gets the "L" result
	unsigned long int UniversalTest::GetL(void) {

		return this->L;
	}

	// Gets the "Q" result
	unsigned long int UniversalTest::GetQ(void) {

		return this->Q;
	}

	// Gets the "K" result
	unsigned long int UniversalTest::GetK(void) {

		return this->K;
	}

	// Gets the "sigma" result
	double UniversalTest::GetSigma(void) {

		return this->sigma;
	}

	// Gets the "phi" result
	double UniversalTest::GetPhi(void) {

		return this->phi;
	}

	// Gets the "sum" result
	double UniversalTest::GetSum(void) {

		return this->sum;
	}

	// Gets the "expectedValue" result
	double UniversalTest::GetExpectedValue(void) {

		return this->expectedValueResult;
	}

	// Gets the "variance" result
	double UniversalTest::GetVariance(void) {

		return this->varianceResult;
	}

	// Gets the "bitsDiscarded" result
	unsigned long int UniversalTest::GetBitsDiscarded(void) {

		return this->bitsDiscarded;
	}
  }
}

//
// Creator:    http://www.dicelocksecurity.com
// Version:    vers.4.0.0.1
//
// Copyright � 2008-2010 DiceLock Security, LLC. All rigths reserved.
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
//
// DICELOCK IS A REGISTERED TRADEMARK OR TRADEMARK OF THE OWNERS.
//

#ifndef UNIVERSALTEST_HPP

#define UNIVERSALTEST_HPP


#include "baseRandomTest.h"
#include "mathematicalFunctions.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class UniversalTest : public BaseRandomTest {

		private:

			// Random Test Class enumerator name
			static const RandomTests	test;
			// Random Test Class minimum stream length
			static const unsigned int	minimumLength;

			static const double expectedValue[17];
			static const double variance[17];

		protected:

			int		L;
			int     Q;
			int     K;
			double  sigma;
			double  phi;
			double  sum;
			double  expectedValueResult;
			double  varianceResult;
			int     bitsDiscarded;

		public:

			// Constructor, default
			UniversalTest();

			// Constructor with a MathematicalFunctions object instantiated
			UniversalTest(MathematicalFunctions*);

			// Destructor
			~UniversalTest();

			// Gets the BaseRandomTest random state of the last executed BaseCryptoRandomStream
			bool IsRandom(void);

			// Tests randomness of the BaseCryptoRandomStream and returns the random value
			bool IsRandom(BaseCryptoRandomStream*);

			// Initializes the object
			void Initialize(void);

			// Gets the type of the object
			RandomTests GetType(void);

			// Gets the minimum random stream length
			unsigned int GetMinimumLength(void);

			// Gets the "L" result
			int GetL(void);

			// Gets the "Q" result
			int GetQ(void);

			// Gets the "K" result
			int GetK(void);

			// Gets the "sigma" result
			double GetSigma(void);

			// Gets the "phi" result
			double GetPhi(void);

			// Gets the "sum" result
			double GetSum(void);

			// Gets the "expectedValue" result
			double GetExpectedValue(void);

			// Gets the "variance" result
			double GetVariance(void);

			// Gets the "bitsDiscarded" result
			int GetBitsDiscarded(void);
	};
  }
}

#endif
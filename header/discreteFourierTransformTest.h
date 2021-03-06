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

#ifndef DISCRETEFOURIERTRANSFORMTEST_HPP

#define DISCRETEFOURIERTRANSFORMTEST_HPP

#include "baseRandomTest.h"
#include "mathematicalFunctions.h"

using namespace DiceLockSecurity::CryptoRandomStream;


namespace DiceLockSecurity {

  namespace RandomTest {

	  class DiscreteFourierTransformTest : public BaseRandomTest {

		protected:

			/// Random Test Class enumerator name
			static const RandomTests	test;
			/// Random Test Class minimum stream length
			static const unsigned long int	minimumLength;

			static const signed long int ntryh[4];
			static const double	tpi;
			static const double	hsqt2;

			double      percentile;
			double      observedPeaks;
			double      expectedPeaks;
			double      normalizedDifference;

			void drfti1(signed long int, double *, signed long int *);
			void dradf2(signed long int, signed long int, double *, double *, double *);
			void dradf4(signed long int, signed long int, double *, double *, double *, double *, double *);
			void drftf1(signed long int, double *, double *, double *, signed long int *);
			void dradfg(signed long int, signed long int, signed long int, signed long int, double *, double *, double *, double *, double *, double *);

		public:

			/// Constructor, default 
			DiscreteFourierTransformTest();

			/// Constructor with a MathematicalFunctions object instantiated 
			DiscreteFourierTransformTest(MathematicalFunctions*);

			/// Destructor
			~DiscreteFourierTransformTest();

			/// Gets the BaseRandomTest random state of the last executed BaseCryptoRandomStream
			bool IsRandom(void);

			/// Tests randomness of the BaseCryptoRandomStream and returns the random value
			bool IsRandom(BaseCryptoRandomStream*);

			/// Initializes the object
			void Initialize(void);

			/// Gets the type of the object
			RandomTests GetType(void);

			/// Gets the minimum random stream length
			unsigned long int GetMinimumLength(void);

			/// Gets the "percentile" result
			double GetPercentile(void);

			/// Gets the "observedPeaks" result
			double GetObservedPeaks(void);

			/// Gets the "expectedPeaks" result
			double GetExpectedPeaks(void);

			/// Gets the "normalizedDifference" result
			double GetNormalizedDifference (void);
	};
  }
}

#endif

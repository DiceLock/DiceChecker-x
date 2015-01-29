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

			// Random Test Class enumerator name
			static const RandomTests	test;
			// Random Test Class minimum stream length
			static const unsigned int	minimumLength;

			static const int	ntryh[4];
			static const double	tpi;
			static const double	hsqt2;

			double      percentile;
			double      observedPeaks;
			double      expectedPeaks;
			double      normalizedDifference;

			void drfti1(int, double *, int *);
			void dradf2(int, int, double *, double *, double *);
			void dradf4(int, int, double *, double *, double *, double *, double *);
			void drftf1(int, double *, double *, double *, int *);
			void dradfg(int, int, int, int, double *, double *, double *, double *, double *, double *);

		public:

			// Constructor, default
			DiscreteFourierTransformTest();

			// Constructor with a MathematicalFunctions object instantiated
			DiscreteFourierTransformTest(MathematicalFunctions*);

			// Destructor
			~DiscreteFourierTransformTest();

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

			// Gets the "percentile" result
			double GetPercentile(void);

			// Gets the "observedPeaks" result
			double GetObservedPeaks(void);

			// Gets the "expectedPeaks" result
			double GetExpectedPeaks(void);

			// Gets the "normalizedDifference" result
			double GetNormalizedDifference (void);
	};
  }
}

#endif
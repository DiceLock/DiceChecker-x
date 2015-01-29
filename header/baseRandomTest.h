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

#ifndef BASERANDOMTEST_HPP

#define BASERANDOMTEST_HPP


#include "baseCryptoRandomStream.h"
#include "mathematicalFunctions.h"

using namespace DiceLockSecurity::CryptoRandomStream;


namespace DiceLockSecurity {

  namespace RandomTest {

	enum RandomTestErrors {
		NoError,
		MultipleErrors,
		InsufficientMemory,
		PValueOutOfRange,
		InsufficientNumberOfBits,
		EstimationCriteriaNotMet,
		ResultsInaccurate,
		LOrQOutOfRange,
		MathematicianNAN,
		LongRunsCaseError,
		MathematicalFunctionsError
	};

	enum RandomTests {
		Frequency,
		BlockFrequency,
		CumulativeSumForward,
		CumulativeSumReverse,
		Runs,
		LongestRunOfOnes,
		Rank,
		Universal,
		ApproximateEntropy,
		Serial,
		DiscreteFourierTransform,
		NumberOfTests,		// Indication of the number of tests, any added test must be inserted before
		NotDefined,
	};

	class BaseRandomTest {

		protected:

			double					alpha;
			double					pValue;
			bool					random;
			RandomTestErrors		error;
			MathematicalFunctions	*mathFuncs;
			bool					autoMathFunc;

		public:

			// Constructor, default
			BaseRandomTest();

			// Constructor with a MathematicalFunctions object instantiated
			BaseRandomTest(MathematicalFunctions *);

			// Destructor
			virtual ~BaseRandomTest();

			// Sets the BaseRandomTest alpha margin
			void SetAlpha(double);

			// Gets the BaseRandomTest alpha margin
			double GetAlpha(void);

			// Gets the BaseRandomTest pValue
			double GetPValue(void);

			// Gets the BaseRandomTest error of the last executed BaseCryptoRandomStream
			RandomTestErrors GetError(void);

			// Gets the BaseRandomTest random state of the last executed BaseCryptoRandomStream
			bool IsRandom(void);

			// Tests the BaseCryptoRandomStream executed and returns the random value
			virtual bool IsRandom(BaseCryptoRandomStream*) {return false;};

			// Initialize the object
			void Initialize(void);

			// Gets the type of the object
			virtual RandomTests GetType(void) {return NotDefined;};

			// Gets the minimum stream length
			virtual unsigned int GetMinimumLength(void) {return 0;};
	};
  }
}

#endif

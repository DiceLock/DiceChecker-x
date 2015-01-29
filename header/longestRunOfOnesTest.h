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

#ifndef LONGESTRUNOFONES_HPP

#define LONGESTRUNOFONES_HPP


#include "baseRandomTest.h"
#include "mathematicalFunctions.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class LongestRunOfOnesTest : public BaseRandomTest {

		protected:

			// Random Test Class enumerator name
			static const RandomTests	test;
			// Random Test Class minimum stream length
			static const unsigned int	minimumLength;

			// Random Test Class block sizes and minimum lengths
			struct blockSizeMinimumLength {
				int blockSize;
				int minimumLength;
			};
			static const short	numberBlockSizes;
			static const blockSizeMinimumLength	blockSizes[3];

			static const int NumAssignments;	// 7
			int          longRunCase;
			int          substringNumber;
			int          substringLength;
			double       chiSquared;
			unsigned int *assignment;

		public:

			// Constructor, default
			LongestRunOfOnesTest();

			// Constructor, setting longRunCase
			LongestRunOfOnesTest(int);

			// Constructor with a MathematicalFunctions object instantiated
			LongestRunOfOnesTest(MathematicalFunctions*);

			// Destructor
			~LongestRunOfOnesTest();

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

			// Sets the longRunCase parameter
			void SetLongRunCase(int);

			// Gets the longRunCase parameter
			int GetLongRunCase(void);

			// Gets the "substringNumber" result
			int GetSubstringNumber(void);

			// Gets the "substringLength" result
			int GetSubstringLength(void);

			// Gets the chiSquared result
			double GetChiSquared(void);

			// Gets the Assignment result
			void GetAssignment(unsigned int *);

			// Gets the Assignment result based on the index
			unsigned int GetAssignmentOfIndex(int);
	};
  }
}

#endif

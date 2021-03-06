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

#ifndef LONGESTRUNOFONES_HPP

#define LONGESTRUNOFONES_HPP

#include "baseRandomTest.h"
#include "mathematicalFunctions.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class LongestRunOfOnesTest : public BaseRandomTest {

		protected:

			/// Random Test Class enumerator name
			static const RandomTests	test;
			/// Random Test Class minimum stream length
			static const unsigned long int	minimumLength;

			/// Random Test Class block sizes and minimum lengths
			struct blockSizeMinimumLength {
				unsigned long int blockSize;
				unsigned long int minimumLength;
			};
			static const unsigned short int numberBlockSizes;
			static const blockSizeMinimumLength	blockSizes[3];

			static const unsigned short int NumAssignments;	// 7 
			unsigned long int longRunCase;
			unsigned long int substringNumber;
			unsigned long int substringLength;
			unsigned long int *assignment;
			double       chiSquared;
			
		public:

			/// Constructor, default 
			LongestRunOfOnesTest();

			/// Constructor with a MathematicalFunctions object instantiated 
			LongestRunOfOnesTest(MathematicalFunctions*);

			/// Destructor
			~LongestRunOfOnesTest();

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

			/// Sets the longRunCase parameter 
			void SetLongRunCase(unsigned long int);

			/// Gets the longRunCase parameter 
			unsigned long int GetLongRunCase(void);

			/// Gets the "substringNumber" result 
			unsigned long int GetSubstringNumber(void);

			/// Gets the "substringLength" result
			unsigned long int GetSubstringLength(void);

			/// Gets the chiSquared result
			double GetChiSquared(void);

			/// Gets the Assignment result
			void GetAssignment(unsigned long int *);

			/// Gets the Assignment result based on the index
			unsigned long int GetAssignmentOfIndex(unsigned long int);
	};
  }
}

#endif

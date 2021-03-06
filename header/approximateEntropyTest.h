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

#ifndef APPROXIMATEENTROPYTEST_HPP

#define APPROXIMATEENTROPYTEST_HPP

#include "baseRandomTest.h"
#include "mathematicalFunctions.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class ApproximateEntropyTest : public BaseRandomTest {

		protected:

			/// Random Test Class enumerator name
			static const RandomTests	test;
			/// Random Test Class minimum stream length
			static const unsigned long int	minimumLength;

			unsigned long int blockLength;
			double	chiSquared;
			double	phi;
			double	phiPlusOne;
			double	apEn;
			bool	blockSizeExceeded;		
			unsigned long int maximumBlockSizeRecommended;	 

		public:

			/// Constructor, default 
			ApproximateEntropyTest();

			/// Constructor with a MathematicalFunctions object instantiated 
			ApproximateEntropyTest(MathematicalFunctions*);

			/// Destructor
			~ApproximateEntropyTest();

			/// Gets the BaseRandomTest random state of the last executed BaseCryptoRandomStream
			bool IsRandom(void);

			/// Tests the BaseCryptoRandomStream executed and returns the random value
			bool IsRandom(BaseCryptoRandomStream*);

			/// Initializes the object
			void Initialize(void);

			/// Gets the type of the object
			RandomTests GetType(void);

			/// Gets the minimum random stream length
			unsigned long int GetMinimumLength(void);

			/// Sets the "m" parameter
			void SetBlockLength(unsigned long int);

			/// Gets the "m" parameter
			unsigned long int GetBlockLength(void);

			/// Gets the "ChiSquared" result
			double GetChiSquared(void);

			/// Gets the "Phi" result
			double GetPhi(void);

			/// Gets the "PhiPlusOne" result
			double GetPhiPlusOne(void);

			/// Gets the "apEn" result
			double GetApEn(void);

			/// Gets the "BlockSizeExceeded" result
			bool GetBlockSizeExceeded(void);		

			/// Gets the "BlockSizeRecommended" result
			unsigned long int GetMaximumBlockSizeRecommended(void);	 

			/// Gets the "BlockSizeRecommended" for the indicated stream length
			unsigned long int MaximumBlockSizeRecommended(unsigned long int);
	};
  }
}

#endif

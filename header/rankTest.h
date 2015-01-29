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

#ifndef RANKTEST_HPP

#define RANKTEST_HPP


#include "baseRandomTest.h"
#include "mathematicalFunctions.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class RankTest : public BaseRandomTest {

		protected:

			// Random Test Class enumerator name
			static const RandomTests	test;
			// Random Test Class minimum stream length
			static const unsigned int	minimumLength;

			double  chiSquared;
			int     matrixNumber;
			int     bitsDiscarded;
			double  p30, p31, p32;		 	// Probabilities
			double	f30, f31, f32;			// Frequencies

			// Create Matrix
			unsigned char**	CreateMatrix(int, int);

			// Define Matrix
			void		DefineMatrix(BaseCryptoRandomStream*, int, int, unsigned char**, int);

			// Deletes matrix
			void		DeleteMatrix(int, unsigned char**);

			// Computes rank
			int			ComputeRank(int, int, unsigned char**);

			// Perform Elementary Row Operations
			void		PerformElementaryRowOperations(int, int, int, int, unsigned char**);

			// Find Unit Element And Swap
			int			FindUnitElementAndSwap(int, int, int, int, unsigned char**);

			// Swap Rows
			int			SwapRows(int, int, int, unsigned char**);

			// Determine Rank
			int			DetermineRank(int, int, int, unsigned char**);

		public:

			// Constructor, default
			RankTest();

			// Constructor with a MathematicalFunctions object instantiated
			RankTest(MathematicalFunctions*);

			// Destructor
			~RankTest();

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

			// Gets the "chiSquared" result
			double GetChiSquared(void);

			// Gets the "matrixNumber" result
			int GetMatrixNumber(void);

			// Gets the "bitsDiscarded" result
			int GetBitsDiscarded(void);

			// Gets the "p30" result
			double GetP30(void);

			// Gets the "p31" result
			double GetP31(void);

			// Gets the "p32" result
			double GetP32(void);

			// Gets the "f30" result
			double GetF30(void);

			// Gets the "f31" result
			double GetF31(void);

			// Gets the "f32" result
			double GetF32(void);

	};
  }
}

#endif
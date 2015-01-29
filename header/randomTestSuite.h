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

#ifndef RANDOMTESTSUITE_HPP

#define RANDOMTESTSUITE_HPP


#include "diceChecker.h"


namespace DiceLockSecurity {

  namespace RandomTest {

	  class RandomTestSuite {

		protected:

			// Points the first random test in the suite
			static const	RandomTests firstTest;

			BaseRandomTest*			suite[NumberOfTests];
			bool					selfCreatedTest[NumberOfTests];
			bool					random;
			MathematicalFunctions*  mathFunctions;
			bool					selfCreatedMaths;
			RandomTestErrors		error;
			int						instantiatedTests;
			int						numberOfErrors;
			RandomTests				errorTest;
			RandomTests				nonRandomTest;

		public:

			// Constructor, default, initializes suite and instantiates MathematicalFunctions
			RandomTestSuite();

			// Constructor, initializes suite and assigns MathematicalFunctions parameter
			RandomTestSuite(MathematicalFunctions*);

			// Destructor
			~RandomTestSuite();

			// ADDING RANDOM TESTS

			// Adds a random test to the suite
			void Add(BaseRandomTest*);

			// Creates and adds a random test to the suite based in the enumerated random tests
			void Add(RandomTests);

			// Creates and adds all random test to the suite
			void AddAll(void);

			// Creates and adds the defined random test to the suite
			void AddFrequencyTest(void);

			// Creates and adds the defined random test to the suite
			void AddBlockFrequencyTest(void);

			// Creates and adds the defined random test to the suite
			void AddRunsTest(void);

			// Creates and adds the defined random test to the suite
			void AddLongestRunOfOnesTest(void);

			// Creates and adds the defined random test to the suite
			void AddCumulativeSumForwardTest(void);

			// Creates and adds the defined random test to the suite
			void AddCumulativeSumReverseTest(void);

			// Creates and adds the defined random test to the suite
			void AddRankTest(void);

			// Creates and adds the defined random test to the suite
			void AddUniversalTest(void);

			// Creates and adds the defined random test to the suite
			void AddApproximateEntropyTest(void);

			// Creates and adds the defined random test to the suite
			void AddSerialTest(void);

			// Creates and adds the defined random test to the suite
			void AddDiscreteFourierTransformTest(void);

			// GETTING RANDOM TESTS

			// Gets a random test to the suite based in the enumerated random tests
			BaseRandomTest* GetRandomTest(RandomTests);

			// Gets the defined random test to the suite
			FrequencyTest* GetFrequencyTest(void);

			// Gets the defined random test to the suite
			BlockFrequencyTest* GetBlockFrequencyTest(void);

			// Gets the defined random test to the suite
			RunsTest* GetRunsTest(void);

			// Gets the defined random test to the suite
			LongestRunOfOnesTest* GetLongestRunOfOnesTest(void);

			// Gets the defined random test to the suite
			CumulativeSumForwardTest* GetCumulativeSumForwardTest(void);

			// Gets the defined random test to the suite
			CumulativeSumReverseTest* GetCumulativeSumReverseTest(void);

			// Gets the defined random test to the suite
			RankTest* GetRankTest(void);

			// Gets the defined random test to the suite
			UniversalTest* GetUniversalTest(void);

			// Gets the defined random test to the suite
			ApproximateEntropyTest* GetApproximateEntropyTest(void);

			// Gets the defined random test to the suite
			SerialTest* GetSerialTest(void);

			// Gets the defined random test to the suite
			DiscreteFourierTransformTest* GetDiscreteFourierTransformTest(void);

			// REMOVING RANDOM TESTS

			// Removes a random test to the suite
			void Remove(BaseRandomTest*);

			// Removes a random test to the suite based in the enumerated random tests
			void Remove(RandomTests);

			// Removes all random test of the suite
			void RemoveAll(void);

			// Removes the defined random test to the suite
			void RemoveFrequencyTest(void);

			// Removes the defined random test to the suite
			void RemoveBlockFrequencyTest(void);

			// Removes the defined random test to the suite
			void RemoveRunsTest(void);

			// Removes the defined random test to the suite
			void RemoveLongestRunOfOnesTest(void);

			// Removes the defined random test to the suite
			void RemoveCumulativeSumForwardTest(void);

			// Removes the defined random test to the suite
			void RemoveCumulativeSumReverseTest(void);

			// Removes the defined random test to the suite
			void RemoveRankTest(void);

			// Removes the defined random test to the suite
			void RemoveUniversalTest(void);

			// Removes the defined random test to the suite
			void RemoveApproximateEntropyTest(void);

			// Removes the defined random test to the suite
			void RemoveSerialTest(void);

			// Removes the defined random test to the suite
			void RemoveDiscreteFourierTransformTest(void);

			// CHECKING RANDOMNESS

			// Tests the BaseCryptoRandomStream untill an error is found with all instantiated random tests and returns the random value
			bool IsRandom(BaseCryptoRandomStream*);

			// Tests the BaseCryptoRandomStream with all instantiated random tests and returns the random value
			bool TestRandom(BaseCryptoRandomStream*);

			// INITIALIZE SUITE

			// Initializes all random tests in the suite
			void Initialize(void);

			// Sets Alpha all random tests in the suite
			void SetAlpha(double);

			// GETTING SUITE RESULTS

			// Gets the RandomTestSuite random state of the last executed BaseCryptoRandomStream
			bool IsRandom(void);

			// Gets the number of Random Tests that contains the suite
			int GetInstantiatedTests(void);

			// Gets the failed random test in the RandomTestSuite
			RandomTests GetNonRandomTest(void);

			// Gets the RandomTestError error of the last executed BaseCryptoRandomStream
			RandomTestErrors GetError(void);

			// Gets the RandomTest that produced the error of the last executed BaseCryptoRandomStream
			RandomTests GetErrorTest(void);

			// Indicates if a random test object exists in the suite
			bool Exist(RandomTests);

			// Gets the first random test in the RandomTestSuite
			RandomTests GetFirstTest(void);

			// Gets the number of random tests that can be used in the RandomTestSuite
			RandomTests GetMaximumNumberOfTests(void);
	};
  }
}

#endif

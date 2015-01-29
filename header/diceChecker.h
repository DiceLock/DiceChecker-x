//
// Creator:    http://www.dicelocksecurity.com
// Version:    vers.5.0.0.1
//
// Copyright  2008-2011 DiceLock Security, LLC. All rights reserved.
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

/*! \mainpage DiceChecker-x 5.0.0.1 Documentation
 *
 * \section intro_sec DiceChecker-x implements Random number tests as per NIST FIPS 800-22 rev1a for Linux operating systems
 *
 *     DiceChecker-x implements following random number tests
 *
 *     - Frequency Random Number Test
 *
 *     - Block Frequency Random Number Test
 *
 *     - Cumulative Sum Forward Random Number Test
 *
 *     - Cumulative Sum Reverse Random Number Test
 *
 *     - Longest Run Of Ones Random Number Test
 *
 *     - Runs Random Number Test
 *
 *     - Serial Random Number Test
 *
 *     - Approximate Entropy Random Number Test
 *
 *     - Rank Random Number Test
 *
 *     - Universal Random Number Test
 *
 *     - Discrete Fourier Transform Random Number Test
 *
 */
 
#ifndef DICECHECKER_HPP

#define DICECHECKER_HPP

#include "baseCryptoRandomStream.h"
#include "defaultCryptoRandomStream.h"
#include "baseRandomTest.h"
#include "baseRandomTest.h"
#include "frequencyTest.h"
#include "blockFrequencyTest.h"
#include "cumulativeSumForwardTest.h"
#include "cumulativeSumReverseTest.h"
#include "longestRunOfOnesTest.h"
#include "runsTest.h"
#include "serialTest.h"
#include "approximateEntropyTest.h"
#include "rankTest.h"
#include "universalTest.h"
#include "discreteFourierTransformTest.h"
#include "randomTestSuite.h"

#endif

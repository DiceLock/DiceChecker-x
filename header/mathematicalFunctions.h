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
// 
// DICELOCK IS A REGISTERED TRADEMARK OR TRADEMARK OF THE OWNERS.
// 

#ifndef MATHEMATICALFUNCTIONS_HPP

#define MATHEMATICALFUNCTIONS_HPP

#define MAX(x,y)             ((x) <  (y)  ? (y)  : (x))
#define MIN(x,y)             ((x) >  (y)  ? (y)  : (x))
#define isNonPositive(x)     ((x) <= 0.e0 ?   1  : 0)
#define isPositive(x)        ((x) >  0.e0 ?   1 : 0)
#define isNegative(x)        ((x) <  0.e0 ?   1 : 0)
#define isGreaterThanOne(x)  ((x) >  1.e0 ?   1 : 0)
#define isZero(x)            ((x) == 0.e0 ?   1 : 0)
#define isOne(x)             ((x) == 1.e0 ?   1 : 0)


namespace DiceLockSecurity {

  namespace RandomTest {

		enum MathematicalErrors {
			None,
			Overflow,
			Underflow,
			MathematicianNan
		};

	  class MathematicalFunctions {

	   private: 
		
		static const double MACHEP;	// 2**-53 
		static const double MAXLOG;	// log(MAXNUM) 
		static const double MAXNUM; // 2**1024*(1-MACHEP) 
		static const double PI;		// pi
		static const double LOGPI;	// log(pi) 
		static const double LS2PI;	//( log( sqrt( 2*pi ) ) 
		static const double big;
		static const double biginv;
		// A[]: Stirling's formula expansion of log gamma
		// B[], C[]: log gamma function between 2 and 3
		static double A_lgam[];
		static double B_lgam[];
		static double C_lgam[];
		static const double MAXLGM;
	   
	   protected:
		
		bool Error;
		MathematicalErrors MathError;

	   public:

			/// Constructor, default 
			MathematicalFunctions();

			/// Destructor
			~MathematicalFunctions();

			/// Logarithm of gamma function
			double	LGamma(double);

			/// incomplete gamma function
			double	IGamma(double, double);
			
			/// Complemented incomplete gamma integral
			double	IGammaC(double, double);

			/// Evaluate polynomial of degree N
			double	PolEvl(double, double *, signed long int);
			
			///                                          N
			/// Evaluate polynomial when coefficient of x  is 1.0.
			double	P1Evl(double, double *, signed long int);
			
			/// Error function in double precision 
			double	ErF(double);
			
			/// Error function in double precision 
			double	ErFc(double);
			
			/// Statistical Normal function
			double	 Normal(double);
			
			/// Class common error handling member
			unsigned short int	GetError();

			/// Class common error handling member
			MathematicalErrors GetMathError();
	  };
  }
}

#endif

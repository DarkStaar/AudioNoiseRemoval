#pragma once

#define F1_COEFFS 33

Int16 filter1_coeffs[F1_COEFFS] = { 
		// TO DO: Add filter coeffs calculated in task No.2
	    0,
	          669,
	         -279,
	         -655,
	          603,
	          517,
	         -947,
	         -222,
	         1281,
	         -285,
	        -1579,
	         1140,
	         1814,
	        -2844,
	        -1963,
	        10066,
	        18137,
	        10066,
	        -1963,
	        -2844,
	         1814,
	         1140,
	        -1579,
	         -285,
	         1281,
	         -222,
	         -947,
	          517,
	          603,
	         -655,
	         -279,
	          669,
	            0
    };

#define F2_COEFFS 121

Int16 filter2_coeffs[F2_COEFFS] = {
       // TO DO: Add filter coeffs calculated in task No.3
		-118,
		          -94,
		          160,
		           34,
		         -180,
		           35,
		          172,
		         -106,
		         -137,
		          165,
		           77,
		         -203,
		            0,
		          212,
		          -85,
		         -189,
		          164,
		          132,
		         -225,
		          -48,
		          257,
		          -51,
		         -250,
		          154,
		          202,
		         -245,
		         -116,
		          307,
		            0,
		         -328,
		          132,
		          297,
		         -262,
		         -214,
		          369,
		           81,
		         -434,
		           88,
		          438,
		         -276,
		         -369,
		          457,
		          222,
		         -603,
		            0,
		          684,
		         -286,
		         -670,
		          617,
		          529,
		         -968,
		         -227,
		         1311,
		         -292,
		        -1615,
		         1166,
		         1855,
		        -2909,
		        -2008,
		        10296,
		        18551,
		        10296,
		        -2008,
		        -2909,
		         1855,
		         1166,
		        -1615,
		         -292,
		         1311,
		         -227,
		         -968,
		          529,
		          617,
		         -670,
		         -286,
		          684,
		            0,
		         -603,
		          222,
		          457,
		         -369,
		         -276,
		          438,
		           88,
		         -434,
		           81,
		          369,
		         -214,
		         -262,
		          297,
		          132,
		         -328,
		            0,
		          307,
		         -116,
		         -245,
		          202,
		          154,
		         -250,
		          -51,
		          257,
		          -48,
		         -225,
		          132,
		          164,
		         -189,
		          -85,
		          212,
		            0,
		         -203,
		           77,
		          165,
		         -137,
		         -106,
		          172,
		           35,
		         -180,
		           34,
		          160,
		          -94,
		         -118
	};

Int16 iir_notch_coeffs[6] = {
       // TO DO: Add filter coeffs calculated in task No.5
		32767,
		 -10145,
		  32767,
		  32767,
		  -9638,
		  29572
    };


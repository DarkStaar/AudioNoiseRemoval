//////////////////////////////////////////////////////////////////////////////
// * File name: main.c
// *
// *
// * Description: Course assignment 1 - Noise removal
// * Course: OAiS DSP1
// * Year: 2020
// *
// * Author: Milan Kapetanovic RA 184/2018
// * Faculty of Technical Sciences, Novi Sad
// *
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "ezdsp5535.h"
#include "aic3204.h"
#include "ezdsp5535_aic3204_dma.h"
#include "WAVheader.h"
#include "fir.h"
#include "iir.h"
#include "coeff.h"

#define CHANNEL_NUM 2
#define GAIN_IN_dB 0
#define SAMPLE_RATE 48000L

static WAV_HEADER outputWAVhdr;
static WAV_HEADER inputWAVhdr;

#pragma DATA_ALIGN(outputBufferL, 4)
Int16 inputBufferL[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(outputBufferR, 4)
Int16 inputBufferR[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(outputBufferL, 4)
Int16 outputBufferL[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(outputBufferR, 4)
Int16 outputBufferR[AUDIO_IO_SIZE];

//Int16 sesti_zadatak_priv1[AUDIO_IO_SIZE];
//Int16 sesti_zadatak_priv2[AUDIO_IO_SIZE];

//TO DO: Create history buffer here
//Zadatak 2
//Int16 historyI[F1_COEFFS];
//Int16 historyO[F1_COEFFS];

//Zadatak 3
//Int16 historyI[F2_COEFFS];
//Int16 historyO[F2_COEFFS];

//Zadatak 5
Int16 historyI[3];
Int16 historyO[3];

//Zadatak 6
//Int16 x_history[3];
//Int16 y_history[3];
//Int16 x_history1[3];
//Int16 y_history1[3];
//Int16 x_history2[3];
//Int16 y_history2[3];

Uint16* p_state = NULL;


/*
 *
 *  main( )
 *
 */
void main( void )
{
	Int32 i, j;
	Int32 number_of_blocks;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Initializatition
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Initialize BSL
    EZDSP5535_init( );

    printf("\n OAiS DSP 1 - Second assignment 2018. \n");

    // Initialise hardware interface and I2C for code
    aic3204_hardware_init();

    aic3204_set_input_filename("../signal2.wav");
    //Zadatak 2
	//aic3204_set_output_filename("../Zadatak2.wav");
	//Zadatak 3
	//aic3204_set_output_filename("../Zadatak3.wav");
    //Zadatak 5
    //aic3204_set_output_filename("../Zadatak5.wav");
    //Zadatak 6
    aic3204_set_output_filename("../Zadatak6.wav");

    // Initialise the AIC3204 codec
	aic3204_init();

    // Setup sampling frequency and 30dB gain for microphone
    set_sampling_frequency_and_gain(SAMPLE_RATE, GAIN_IN_dB);

    aic3204_read_wav_header(&inputWAVhdr);

	// Set up output WAV header
	outputWAVhdr = inputWAVhdr;

	number_of_blocks = inputWAVhdr.data.SubChunk2Size/
			(inputWAVhdr.fmt.NumChannels*inputWAVhdr.fmt.BitsPerSample*AUDIO_IO_SIZE/8);

	aic3204_write_wav_header(&outputWAVhdr);

	//Zadatak 2
	/*
	for(j = 0; j < F1_COEFFS; j++)
	{
		historyI[j] = 0;
		historyO[j] = 0;
	}
	outputBufferR[0] = fir_basic(32767, filter1_coeffs, historyI, F1_COEFFS);

	for(j = 1; j < AUDIO_IO_SIZE; j++)
	{
		outputBufferR[j] = fir_basic(0, filter1_coeffs, historyI, F1_COEFFS);
	}

	*/
	/*
	//Zadatak 3
	for(j = 0; j < F2_COEFFS; j++)
		{
			historyI[j] = 0;
			historyO[j] = 0;
		}
		outputBufferR[0] = fir_basic(32767, filter2_coeffs, historyI, F2_COEFFS);

	for(j = 1; j < AUDIO_IO_SIZE; j++)
	{
		outputBufferR[j] = fir_basic(0, filter2_coeffs, historyI, F2_COEFFS);
	}

	*/


	for(i=0; i < 3; i++)
	{
		historyI[i] = 0;
		historyO[i] = 0;
	}


	/*
	for(i=0; i < 3; i++)
	{
		x_history[i] = 0;
		y_history[i] = 0;
		x_history1[i] = 0;
		y_history1[i] = 0;
		x_history2[i] = 0;
		y_history2[i] = 0;
	}
	*/
	// Processing loop. Place your code here...
    for(i = 0; i < number_of_blocks; i++)
    {
    	aic3204_read_block(inputBufferL, inputBufferR);

    	//Zadatak 2
    	/*
    	for(j = 0; j < AUDIO_IO_SIZE; j++)
    	{
			//TO DO: Call filter routine here. Use coefficients from coeffs.h
    		outputBufferL[j] = fir_basic(inputBufferL[j], filter1_coeffs, historyO, F1_COEFFS);
    		outputBufferR[j] = fir_circular(inputBufferR[j], filter1_coeffs, historyO, F1_COEFFS, p_state);
    	}
		*/
    	/*
    	//Zadatak 3
    	for(j = 0; j < AUDIO_IO_SIZE; j++)
    	{
    		//TO DO: Call filter routine here. Use coefficients from coeffs.h
    	    outputBufferL[j] = fir_basic(inputBufferL[j], filter2_coeffs, historyO, F2_COEFFS);
 	   		outputBufferR[j] = fir_circular(inputBufferR[j], filter2_coeffs, historyO, F2_COEFFS, p_state);
    	}
		*/


    	//Zadatak 5
    	for(j = 0; j < AUDIO_IO_SIZE; j++)
    	{
    		//TO DO: Call filter routine here. Use coefficients from coeffs.h
    	    outputBufferL[j] = second_order_IIR(inputBufferL[j], iir_notch_coeffs, historyI, historyO);
    	}

    	//Zadatak 6
    	/*
    	for(j = 0; j < AUDIO_IO_SIZE; j++)
    	{
    		//TO DO: Call filter routine here. Use coefficients from coeffs.h
    		sesti_zadatak_priv1[j] = second_order_IIR(inputBufferL[j], iir_notch_coeffs, x_history, y_history);
			sesti_zadatak_priv2[j] = second_order_IIR(sesti_zadatak_priv1[j], iir_notch_coeffs, x_history1, y_history1);
    	    outputBufferL[j] = second_order_IIR(sesti_zadatak_priv2[j], iir_notch_coeffs, x_history2, y_history2);
    	}

		*/
    	printf("Obradjujem...\n");

    	/*
    	for(j = 0; j < AUDIO_IO_SIZE; j++)
    	{
    		outputBufferL[j] = inputBufferL[j];
    		outputBufferR[j] = inputBufferR[j];
    	}
		*/

    	//OutputL, OutputL za Zadatak 5
    	aic3204_write_block(outputBufferL, outputBufferL);
	}

    printf("Zvuk je obradjen.");
	/* Disable I2S and put codec into reset */
    aic3204_disable();

    printf( "\n***Program has Terminated***\n" );
	SW_BREAKPOINT;
}


/*
 *
 *
 *
 */

#include <math.h>
#include "radarcalculations.h"
#include <iostream>
#include <string>

using namespace std;
#define SPEED_OF_LIGHT 299792460
#define PI 3.14159265358979
#define RECTANGULAR_EFFECIENCY 0.7
#define ELLIPTICAL_EFFECIENCY 0.55
namespace rcs{

  /*
   *
  */
  double RadarCalculations::antennaApertureArea(double height,double width){
  
    return height * width;
  }

  /*
  *
  */
  double RadarCalculations::antennaGainFrequency(double frequency,double antennaApertureArea,string effeciency){
    
    double wavelength = SPEED_OF_LIGHT/frequency;
    
    if (effeciency == "Rectangular")
      return (4*PI*RECTANGULAR_EFFECIENCY*antennaApertureArea)/(pow(wavelength,2));
    else if(effeciency == "Elliptical")
      return (4*PI*ELLIPTICAL_EFFECIENCY*antennaApertureArea)/(pow(wavelength,2));
    else 
      return (4*PI*1*antennaApertureArea)/(pow(wavelength,2));
  }

  /*
   *
   */
  double RadarCalculations::antennaGainBeamwidth(double horizontalBeamwidth,double verticalBeamwidth,string antennaType){
      
    if (antennaType == "Rectangular")
      return (41253*RECTANGULAR_EFFECIENCY)/( horizontalBeamwidth* verticalBeamwidth);
    else if(antennaType == "Elliptical")
      return (52525*ELLIPTICAL_EFFECIENCY)/( horizontalBeamwidth* verticalBeamwidth);
    else
      return -1;
  }

  /*
   *
   */
  double RadarCalculations::radarCell(double pulsewidth){
  
    return (pulsewidth * SPEED_OF_LIGHT)/2;
  }

  /*
   *
   */
  double RadarCalculations::radarCell(double beamwidth,double rangeFromRadar){
  
    return 0.0;
  }



}


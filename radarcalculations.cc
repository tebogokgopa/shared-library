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
   * */
    double toRadians(double degrees){
        
        return (degrees * PI)/180;
    }
  /*
   *
   */
  double RadarCalculations::radarCell(double beamwidth,double rangeFromRadar,string rangeMetric){
    
      if (rangeMetric == "Kilometers")
        return tan(toRadians(beamwidth))*(rangeFromRadar*1000);
      else if (rangeMetric == "Nautical Miles")
        return tan(toRadians(beamwidth))*(rangeFromRadar*1852);
      else if (rangeMetric == "Yards")
        return tan(toRadians(beamwidth))*(rangeFromRadar*0.9114);
      else 
        return tan(toRadians(beamwidth))*rangeFromRadar;

  }
    /*
     *
     */
    double RadarCalculations::maximumUnambiguousRange(double pulseRepetitionInterval){
        
        return (SPEED_OF_LIGHT*pulseRepetitionInterval)/2;
    }

    /*
     *
     */
    double RadarCalculations::radarHorizon(double heightRadar,double heightRcsEsm,string rangeMetric){
         
        if (rangeMetric == "meters")
            return (1.23*(sqrt(heightRadar) + sqrt(heightRcsEsm)))* 3.28084;
        else 
            return (1.23*(sqrt(heightRadar) + sqrt(heightRcsEsm)));
    }

    /*
     *
     */
    double RadarCalculations::twoWayMonostaticRadarRange(double powerTransmitter,double gainTransmitter,
                                                        double gainReciever,double frequency,
                                                        double radarCrossSection,double range){
        double wavelength = SPEED_OF_LIGHT/frequency;
        return (powerTransmitter*gainTransmitter*gainReciever*pow(wavelength,2) * radarCrossSection)/(pow((4*PI),3)*pow(range,4));
    }
    
    /*
     *
     */
    double RadarCalculations::powerAtReciever(double pulseWidth,double bandWidth,double signalToNoise,double noiseFigure){
        
        return 0.0;
    }



}


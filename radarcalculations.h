/*
 *
 *
 *
 *
 *
 */
#ifndef RADARCALCULATIONS_H
#define RADARCALCULATIONS_H
#include<string>
using namespace std;
namespace rcs{


  class RadarCalculations{
  
  
    private:



    public:

      static double antennaApertureArea(double height,double width);
      static double antennaGainFrequency(double frequency,double antennaApertureArea,string effeciency);
      static double antennaGainBeamwidth(double horizontalBeamwidth,double verticalBeamwidth,string antennaType);
      static double radarCell(double pulsewidth);
      static double radarCell(double beamwidth,double rangeFromRadar,string rangeMetric);
      static double maximumUnambiguousRange(double pulseRepetitionInterval);
      static double radarHorizon(double heightRadar,double heightRadarCrossSection,string rangeMetric);
      static double twoWayMonostaticRadarRange(double powerTransmitter,double gainTransmitter,double gainReciever,
                                                    double frequency,double radarCrossSection,double range);
      static double powerAtReciever(double pulseWidth,double bandWidth,double signalToNoise,double noiseFigure);
      static double twoWayRadarRangeOne(double powerAtTransmitter,double gainTransmitter,double gainReciever,double frequency,
                                        double waveLength,double radarCrossSection,double powerOfReciever);
      static double twoWayRadarRange(double powerAtTransmitter,double gainTransmitter,double gainReciever,double frequency,
                                        double waveLength,double radarCrossSection,double rangeToTarget,double rangeToReciever);
  };


}

#endif

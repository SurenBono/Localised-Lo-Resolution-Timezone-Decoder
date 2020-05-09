
// E.Lo-Res.L.S.G.T.D.F.P.E.C.I.A V.0.3
// Experimental Lo-Resolution Localized squared Global Timezone decoder for Planet Earth Coordinate including the Antartica V.0.3
// Valid LAT input between -90(South) to 90(North) Valid LNG in-between -179.99(West) to 180(East)else return Invalid Input.
// Experimented on UnoArduSim V2.5 for Global S&G NEO-6M GPS Precision Clock Auto Timezone decode by Coordinate.
// Averaged Decoding accuracy since countries are not a squared border.Refer(1---8-UTC.png)
// Not Cellular nor Internet but locally decode and adjusted by MCU from UTC±0(NEO-6M).
// Requires little more higher sram & program space than UNO(Atmega326),recommends Mega(Atmega2560).
// Only decodes when a valid coor exist else display UTC±0 time.(NEO-6M = 5~30 min)
// Pending DST encoding.https://www.timeanddate.com/time/dst/
// Daylight Saving Time (DST) is the practice of setting the clocks forward one hour from standard time during the summer months, and back again in the fall, in order to make better use of natural daylight.
// Other reference https://en.wikipedia.org/wiki/List_of_UTC_time_offsets.
// Coded and tested by Suren,Malaysia.March 2020 during Covid-19 lockdown.
// “Given the complexity of how global time zones work, there are likely errors and inconsistencies with most/all of these maps and none of this data should be considered “official”.”



float LAT;
float LNG;
float UTC;
bool newLAT=false;
bool newLNG=false;

void setup() {
Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
Serial.println(" Input Coordinate (LAT,LNG) ");
Serial.println(" ,add(-)for South & West ");
Serial.println(" Pending DST ");
Serial.println();
}

void loop() {
	
	if(Serial.available()> 0 && newLAT == false) {
		
		LAT= Serial.parseFloat();
		Serial.print(LAT,5);
		Serial.print(",");
	newLAT = true;}
		while (Serial.available()> 0 && newLAT == true && newLNG==false)
		{
		LNG = Serial.parseFloat();newLNG=true;
		//Serial.print(LAT);
		//Serial.print(",");
		Serial.println(LNG,5);delay(500);decode();
		newLAT = false; newLNG=false;
	}
	
}

void decode(){
	
	//(1/38TZ)UTC+14,3 Region
	if(LAT>=  0      && LAT <= 4      && LNG >= -160.5 && LNG <= -158    ||LAT>= -6      && LAT <=  4     && LNG >= -158    && LNG <= -150     ||LAT>= -12      && LAT <= -6      && LNG >= -155    && LNG <= -150    ){ UTC=14;}//+14 UTC.R1/3
	
	//(2/38TZ)UTC+13,5 Region
	if(LAT>= -6      && LAT <= -2.5   && LNG >= -179   && LNG <= -158    ||LAT>= -10     && LAT <= -6     && LNG >= -179    && LNG <= -169     ||LAT>= -15      && LAT <= -10     && LNG >= -174    && LNG <= -171    ){ UTC=13;}//+13 UTC.R1-3/5
	if(LAT>= -26     && LAT <= -15    && LNG >= -178.5 && LNG <= -172.5  ||LAT>= -26     && LAT <= -22    && LNG >= -179.99 && LNG <= -178.5   ){	UTC=13;}//+13 UTC.R4-5/5
	
	//(3/38TZ)UTC+12:45,1 Region
	if(LAT>= -45     && LAT <= -42    && LNG >= -179.9 && LNG <= -172.5  ){ UTC=12.75;}//+12 3/4 UTC.R1/1
	
	//(4/38TZ)UTC+12,19 Region
	if(LAT>=  59.00  && LAT <=  90.00 && LNG >=  172.5 && LNG <=  180    ||LAT>=  70.00  && LAT <=  75.00 && LNG >= -179.9  && LNG <= -172.5   ||LAT>=  63.5    && LAT <=  70.00  && LNG >= -179.9  && LNG <= -168    ){ UTC=12;}//+12 UTC.R1-3/20
	if(LAT>=  54     && LAT <=  70.00 && LNG >=  162   && LNG <=  172.5  ||LAT>=  65     && LAT <=  67.7  && LNG >=  159.5  && LNG <=  162     ||LAT>=  58.6    && LAT <=  60.5   && LNG >=  159.5  && LNG <=  162    ){ UTC=12;}//+12 UTC.R4-6/20
	if(LAT>=  51     && LAT <=  58.6  && LNG >=  153   && LNG <=  162    ||LAT>=  51     && LAT <=  54    && LNG >=  162    && LNG <=  167     ||LAT>=  20      && LAT <=  48     && LNG >=  172.5  && LNG <=  180    ){ UTC=12;}//+12 UTC.R7-9/20
	if(LAT>=  9      && LAT <=  20    && LNG >=  160   && LNG <=  180    ||LAT>= -3      && LAT <=  9     && LNG >=  165    && LNG <=  180     ||LAT>= -8       && LAT <= -3      && LNG >=  172.5  && LNG <=  180    ){ UTC=12;}//+12 UTC.R10-12/20
	if(LAT>= -15     && LAT <= -8     && LNG >= -179.9 && LNG <= -179    ||LAT>= -15     && LAT <= -8     && LNG >=  172.5  && LNG <=  180     ||LAT>= -26      && LAT <= -22     && LNG >=  172.5  && LNG <=  180    ){ UTC=12;}//+12 UTC.R13&15/20
	if(LAT>= -22     && LAT <= -15    && LNG >=  172.5 && LNG <=  180    ||LAT>= -22     && LAT <= -15    && LNG >= -179.9  && LNG <= -177     ||LAT>= -42      && LAT <= -26     && LNG >=  172.5  && LNG <=  180    ){ UTC=12;}//+12 UTC.R14,17,18/20
	if(LAT>= -42     && LAT <= -26    && LNG >= -179.9 && LNG <= -172.5  ||LAT>= -42     && LAT <= -30    && LNG >=  165    && LNG <=  172.5   ||LAT>= -53      && LAT <= -42     && LNG >=  165    && LNG <=  180    ){ UTC=12;}//+12 UTC.R16/20	
	if(LAT>= -60     && LAT <= -53    && LNG >=  172.5 && LNG <=  180    ||LAT>= -15     && LAT <= -12    && LNG >= -179    && LNG <= -174     ){ UTC=12;}//+12 UTC.R19&20/20
	
	//(5/38TZ)UTC+11,16 Region
	if(LAT>=  70     && LAT <=  90    && LNG >= 157.5  && LNG <= 172.5   ||LAT>=  65     && LAT <=  72.38 && LNG >=  141    && LNG <=  150     ||LAT>=  70      && LAT <=  72.38  && LNG >=  150    && LNG <=  157.5  ){ UTC=11;}//+11 UTC.R1-3/16
	if(LAT>=  67.7   && LAT <=  70    && LNG >= 150    && LNG <= 162     ||LAT>=  65     && LAT <=  67.5  && LNG >=  150    && LNG <=  159.5   ||LAT>=  60.5    && LAT <=  65     && LNG >=  145.5  && LNG <=  162    ){ UTC=11;}//+11 UTC.R4-6/16
	if(LAT>=  58.6   && LAT <=  60.5  && LNG >= 145.5  && LNG <= 159     ||LAT>=  51     && LAT <=  58.6  && LNG >=  141    && LNG <=  153     ||LAT>=  45.7    && LAT <=  51     && LNG >=  141    && LNG <=  157.5  ){ UTC=11;}//+11 UTC.R7-9/16
	if(LAT>=  42.8   && LAT <=  45.7  && LNG >= 145.26 && LNG <= 157.5   ||LAT>=  20     && LAT <=  51    && LNG >=  157.5  && LNG <=  172.5   ||LAT>=  9       && LAT <=  20     && LNG >=  157.5  && LNG <=  160    ){ UTC=11;}//+11 UTC.R10-12/16
	if(LAT>=  3      && LAT <=  9     && LNG >= 154    && LNG <= 165     ||LAT>= -10     && LAT <= -3     && LNG >=  154    && LNG <=  172.5   ||LAT>= -30      && LAT <= -10     && LNG >=  157.5  && LNG <=  172.5  ){ UTC=11;}//+11 UTC.R13-15/16
	if(LAT>= -53     && LAT <= -32    && LNG >= 157.5  && LNG <= 165     ||LAT>= -60     && LAT <= -53    && LNG >=  157.5  && LNG <=  172.5   ){ UTC=11;}//+11 UTC.16/16R
	
	//(6/38TZ)UTC+10:30,1 Region
	if(LAT>= -32     && LAT <= -30    && LNG >= 157.5  && LNG <= 165     ){ UTC=10.5;}//+10 1/2 UTC.1R
	
	//(7/38TZ)UTC+10,18 Region
	if(LAT>=  77     && LAT <=  90    && LNG >= 142.5  && LNG <= 157.5   ||LAT>=  73    && LAT <=  77     && LNG >=  153    && LNG <=  157.5   ||LAT>=  72.38   && LAT <=  73     && LNG >=  130    && LNG <=  157.5  ){ UTC=10;}//+10 UTC.1-3/18R
	if(LAT>=  65     && LAT <=  72.38 && LNG >= 130    && LNG <= 141     ||LAT>=  58.6  && LAT <=  65     && LNG >=  137    && LNG <=  145.5   ||LAT>=  45.7    && LAT <=  58.6   && LNG >=  131    && LNG <=  141    ){ UTC=10;}//+10 UTC.4-6/18R
	if(LAT>=  42.8   && LAT <=  45.7  && LNG >= 131    && LNG <= 137.5   ||LAT>=  30    && LAT <=  42.8   && LNG >=  145.26 && LNG <=  157.5   ||LAT>=  24.5    && LAT <=  30     && LNG >=  150    && LNG <=  157.5  ){ UTC=10;}//+10 UTC.7-9/18R
	if(LAT>=  16     && LAT <=  30    && LNG >= 142.5  && LNG <= 150     ||LAT>=  16    && LAT <=  24     && LNG >=  150    && LNG <=  157.5   ||LAT>=  7.5     && LAT <=  16     && LNG >=  136    && LNG <=  140.9  ){ UTC=10;}//+10 UTC.10,11,18-12/18R
	if(LAT>= -15     && LAT <=  16    && LNG >= 140.9  && LNG <= 154     ||LAT>=  9     && LAT <=  16     && LNG >=  154    && LNG <=  157.5   ||LAT>= -15      && LAT <= -10     && LNG >=  154    && LNG <=  157.5  ){ UTC=10;}//+10 UTC.13-15/18R
	if(LAT>= -26     && LAT <= -15    && LNG >= 138    && LNG <= 140.9   ||LAT>= -38    && LAT <= -15     && LNG >=  140.9  && LNG <=  157.5   ||LAT>= -60      && LAT <= -38     && LNG >=  142.5  && LNG <=  157.5  ){ UTC=10;}//+10 UTC.16&17/18R
	
	//(8/38TZ)UTC+09:30,
	if(LAT>= -15     && LAT <= -11    && LNG >=127.5   && LNG <=140.9    ||LAT>= -33    && LAT <= -15     && LNG >=  129    && LNG <=  138     ){ UTC=9.5;}//+9 1/2 UTC.1-2/4R
	if(LAT>= -33     && LAT <= -26    && LNG >=138     && LNG <=140.9    ||LAT>= -38    && LAT <= -33     && LNG >=  127.5  && LNG <=  140.9   ){ UTC=9.5;}//+9 1/2 UTC.3-4/4R
	
	//(9/38TZ)UTC+9,18 Region
	if(LAT>=  77     && LAT <=  90    && LNG >=  127.5 && LNG <=  142.5  ||LAT>=  73    && LAT <=  77     && LNG >=  115.5  && LNG <=  153     ||LAT>=  69.5    && LAT <=  73     && LNG >=  110    && LNG <= 130     ){ UTC=9;}//+9 UTC.1-3/18R
	if(LAT>=  65     && LAT <=  69.5  && LNG >=  105.5 && LNG <=  130    ||LAT>=  58.6  && LAT <=  65     && LNG >=  109    && LNG <=  137.5   ||LAT>=  54      && LAT <=  58.6   && LNG >=  116    && LNG <= 131     ){ UTC=9;}//+9 UTC.4-6/18R
	if(LAT>=  51     && LAT <=  54    && LNG >=  113.2 && LNG <=  120    ||LAT>=  49.5  && LAT <=  51     && LNG >=  107    && LNG <=  120     ||LAT>=  49.5    && LAT <=  54     && LNG >=  127    && LNG <= 131     ){ UTC=9;}//+9 UTC.7-9/18R
	if(LAT>=  42.8   && LAT <=  45.7  && LNG >=  137.5 && LNG <=  145.26 ||LAT>=  30    && LAT <=  42.8   && LNG >=  124.2  && LNG <=  145.26  ||LAT>=  23      && LAT <=  30     && LNG >=  123    && LNG <= 127.5   ){ UTC=9;}//+9 UTC.10-12/18R
	if(LAT>=  16     && LAT <=  30    && LNG >=  127.5 && LNG <=  142.5  ||LAT>=  7.5   && LAT <=  16     && LNG >=  127.5  && LNG <=  136     ||LAT>= -11      && LAT <=  7.5    && LNG >=  127.5  && LNG <= 140.9   ){ UTC=9;}//+9 UTC.13-15/18R
	if(LAT>= -11     && LAT <=  0     && LNG >=  127.5 && LNG <=  125.5  ||LAT>=  24    && LAT <=  24.5   && LNG >=  150    && LNG <=  157.5   ||LAT>=  73      && LAT <=  75     && LNG >=  110    && LNG <= 115.5   ){ UTC=9;}//+9 UTC.16,17,2b/18R
	
	//(10/38TZ)UTC+08:45,1 Region
	if(LAT>= -33     && LAT <= -30    && LNG >=  126   && LNG <=  129    ){ UTC=8.75;}//+8 3/4 UTC.R1/1
	
	//(11/38TZ)UTC+8,30+2 Region
	if(LAT>=  77     && LAT <=  90    && LNG >=  115.5 && LNG <=  127.5  ||LAT>=  58.6   && LAT <=  65     && LNG >=  105.5  && LNG <=  109    ||LAT>=  53      && LAT <=  58.3   && LNG >=  97     && LNG <= 105.5  ){ UTC=8;}//+8 UTC.1-3/30R
	if(LAT>=  54     && LAT <=  58.6  && LNG >=  105.5 && LNG <=  116.3  ||LAT>=  51     && LAT <=  53     && LNG >=  98.4   && LNG <=  105.5  ||LAT>=  51      && LAT <=  54     && LNG >=  105.5  && LNG <= 113.2  ){ UTC=8;}//+8 UTC.4-6/30R
	if(LAT>=  49.5   && LAT <=  51    && LNG >=  98.4  && LNG <=  107    ||LAT>=  42.8   && LAT <=  49.5   && LNG >=  98.4   && LNG <=  131    ||LAT>=  45      && LAT <=  47     && LNG >=  82.6   && LNG <= 85.6   ){ UTC=8;}//+8 UTC.7-9/30R
	if(LAT>=  45     && LAT <=  48    && LNG >=  85.6  && LNG <=  90.88  ||LAT>=  41.1   && LAT <=  45     && LNG >=  82     && LNG <=  82.5   ||LAT>=  34      && LAT <=  41.4   && LNG >=  75     && LNG <= 82.5   ){ UTC=8;}//+8 UTC.10-12/30R
	if(LAT>=  31.3   && LAT <=  45    && LNG >=  82.5  && LNG <=  97     ||LAT>=  29.6   && LAT <=  31.3   && LNG >=  88.4   && LNG <=  97     ||LAT>=  31.3    && LAT <=  34     && LNG >=  79.2   && LNG <= 82.5   ){ UTC=8;}//+8 UTC.13,13b,14/30R	
	if(LAT>=  28.8   && LAT <=  42.8  && LNG >=  97    && LNG <=  98.7   ||LAT>=  30     && LAT <=  42.8   && LNG >=  98.7   && LNG <=  124.2  ||LAT>=  22.26   && LAT <=  30     && LNG >=  98.7   && LNG <= 123    ){ UTC=8;}//+8 UTC.15-17/30R	
	if(LAT>=  15     && LAT <=  22.26 && LNG >=  108   && LNG <=  123    ||LAT>=  0      && LAT <=  23     && LNG >=  123    && LNG <=  127.5  ||LAT>=  1.2     && LAT <=  15     && LNG >=  112.5  && LNG <= 123    ){ UTC=8;}//+8 UTC.18-20/30R
	if(LAT>=  0      && LAT <=  1.2   && LNG >=  112.5 && LNG <=  123    ||LAT>= -9      && LAT <=  0      && LNG >=  114.6  && LNG <=  125.5  ||LAT>= -9       && LAT <= -9      && LNG >=  112.5  && LNG <= 125.5  ){ UTC=8;}//+8 UTC.20b,21,22/30R
	if(LAT>= -30     && LAT <= -11    && LNG >=  112.5 && LNG <=  127.5  ||LAT>= -30     && LAT <= -15     && LNG >=  127.5  && LNG <=  129    ||LAT>= -33      && LAT <= -30     && LNG >=  112.5  && LNG <= 126    ){ UTC=8;}//+8 UTC.23-25/30R
	if(LAT>= -60     && LAT <= -33    && LNG >=  112.5 && LNG <=  127.5  ||LAT>=  4.7    && LAT <=  6.67   && LNG >=  99     && LNG <=  112.5  ||LAT>=  3       && LAT <=  4.7    && LNG >=  100    && LNG <= 105    ){ UTC=8;}//+8 UTC.26-28/30R
	if(LAT>=  1.2    && LAT <=  3     && LNG >=  101   && LNG <=  105    ||LAT>=  1.2    && LAT <=  4.7    && LNG >=  109.5  && LNG <=  112.5  ){ UTC=8;}//+8 UTC.29-30/30R
	
	//(12/38TZ)UTC+7,26 Region
	if(LAT>=  81.6   && LAT <=  90    && LNG >=  97.5  && LNG <=  112.5  ||LAT>=  79     && LAT <=  81.6   && LNG >=  75     && LNG <=  112.5  ||LAT>=  77      && LAT <=  79     && LNG >=  78.2   && LNG <= 112.5  ){ UTC=7;}//+7 UTC.1-3/26R
	if(LAT>=  71.4   && LAT <=  77    && LNG >=  78.2  && LNG <=  110    ||LAT>=  75     && LAT <=  77     && LNG >=  112.5  && LNG <=  115.5  ||LAT>=  65      && LAT <=  71.4   && LNG >=  82.5   && LNG <= 105.5  ){ UTC=7;}//+7 UTC.4-6/26R	
	if(LAT>=  69.5   && LAT <=  71.4  && LNG >=  105.5 && LNG <=  110    ||LAT>=  61     && LAT <=  65     && LNG >=  86     && LNG <=  105.5  ||LAT>=  58.3    && LAT <=  61     && LNG >=  75.8   && LNG <= 105.5  ){ UTC=7;}//+7 UTC.7-9/26R		
	if(LAT>=  54.51  && LAT <=  58.3  && LNG >=  75.8  && LNG <=  97     ||LAT>=  51     && LAT <=  54.51  && LNG >=  78.2   && LNG <=  84.3   ||LAT>=  50      && LAT <=  54.51  && LNG >=  84.3   && LNG <= 97     ){ UTC=7;}//+7 UTC.10-12/26R	
	if(LAT>=  48     && LAT <=  50    && LNG >=  85.6  && LNG <=  90.88  ||LAT>=  45     && LAT <=  50     && LNG >=  90.88  && LNG <=  97     ||LAT>=  42.8    && LAT <=  53     && LNG >=  97     && LNG <= 98.4   ){ UTC=7;}//+7 UTC.13-15/26R
	if(LAT>=  20     && LAT <=  22.26 && LNG >=  101   && LNG <=  108    ||LAT>=  9.92   && LAT <=  20     && LNG >=  98.7   && LNG <=  108    ||LAT>=  9.92    && LAT <=  15     && LNG >=  108    && LNG <= 112.5  ){ UTC=7;}//+7 UTC.16-18/26R
	if(LAT>=  6.67   && LAT <=  9.92  && LNG >=  97.5  && LNG <=  112.5  ||LAT>=  0      && LAT <=  6.67   && LNG >=  95     && LNG <=  99     ||LAT>=  1.2     && LAT <=  4.7    && LNG >=  105    && LNG <= 109.5  ){ UTC=7;}//+7 UTC.19-21/26R
	if(LAT>=  0      && LAT <=  3     && LNG >=  99    && LNG <=  101    ||LAT>=  0      && LAT <=  1.2    && LNG >=  101    && LNG <=  112.5  ||LAT>= -9       && LAT <=  1.2    && LNG >=  112.5  && LNG <= 114.6  ){ UTC=7;}//+7 UTC.22-24/26R	
	if(LAT>= -60     && LAT <=  0     && LNG >=  97.5  && LNG <=  112.5  ||LAT>=  3      && LAT <=  4.7    && LNG >=  99     && LNG <=  100.5  ){ UTC=7;}//+7 UTC.25-26/26R	
	
	//(13/38TZ)UTC+06:30,6 Region
    if(LAT>=  25.54  && LAT <=  28.8  && LNG >=  97    && LNG <=  98.7   ||LAT>=  20     && LAT <=  25.54  && LNG <=  98.7   && LNG >=  92.5   ||LAT>=  20      && LAT <=  22.26  && LNG <=  101    && LNG >= 98.7   ){ UTC=6.5;}//+06:30 UTC.R9,1-3/6		
	if(LAT>=  15     && LAT <=  20    && LNG >=  87.4  && LNG <=  92.5   ||LAT>=  9.92   && LAT <=  20     && LNG <=  98.7   && LNG >=  97.5   ||LAT>= -15      && LAT <= -11.5   && LNG <=  97.5   && LNG >= 96.5   ){ UTC=6.5;}//+06:30 UTC.R9,4-6/6
	
	//(14/38TZ)UTC+6,17 Region
	if(LAT>= -8      && LAT <= -5     && LNG >=  71    && LNG <=  75     ||LAT>=  26.37  && LAT <=  29.6   && LNG <=  92.5   && LNG >=  88.4   ||LAT>=  20      && LAT <=  25.54  && LNG <=  92.5   && LNG >= 88.4   ){ UTC=6;}//+6 UTC.R9,1&2/17	
	if(LAT>=  81.6   && LAT <=  90    && LNG >=  82.5  && LNG <=  97.5   ||LAT>=  15     && LAT <=  20     && LNG <=  92.5   && LNG >=  87.4   ||LAT>=  6.67    && LAT <=  15     && LNG <=  90     && LNG >= 82.5   ){ UTC=6;}//+6 UTC.R3-5/17		
	if(LAT>=  0      && LAT <=  6.67  && LNG >=  82.5  && LNG <=  95     ||LAT>=  6.67   && LAT <=  15     && LNG <=  97.5   && LNG >=  95     ||LAT>= -11.5    && LAT <=  0      && LNG <=  97.5   && LNG >= 82.5   ){ UTC=6;}//+6 UTC.R6-8/17
	if(LAT>= -15     && LAT <= -11.5  && LNG >=  82.5  && LNG <=  96.5   ||LAT>=  -60    && LAT <= -15     && LNG <=  97.5   && LNG >=  82.5   ||LAT>=  54.51   && LAT <=  58.3   && LNG <=  75.8   && LNG >= 69.64  ){ UTC=6;}//+6 UTC.R10-12/17
	if(LAT>=  50     && LAT <=  54.51 && LNG >=  60.6  && LNG <=  78.2   ||LAT>=   50    && LAT <=  51     && LNG <=  84.3   && LNG >=  78.2   ||LAT>=  41.1    && LAT <=  50     && LNG <=  82     && LNG >= 67.5   ){ UTC=6;}//+6 UTC.R13-15/17	
	if(LAT>=  47     && LAT <=  50    && LNG >=  82    && LNG <=  85.6   ||LAT>=   45    && LAT <=  47     && LNG <=  82.5   && LNG >=  82     ){ UTC=6;}//+6 UTC.R16-17/17
	
	//(15/38TZ)UTC+05:45,1 Region
	if(LAT>= 26.37   && LAT <=  31.3  && LNG >=  80    && LNG <=  88.4   ){ UTC=5.75;}//+05:45 UTC.R1/1

	//(16/38TZ)UTC+05:30,9 Region
	if(LAT>=  31.3   && LAT <=  34    && LNG <=  79.2  && LNG >=  75     ||LAT>=  26.37  && LAT <=  31.3   && LNG <=  80     && LNG >=  75     ||LAT>=  25.54   && LAT <=  26.37  && LNG <=  92.5   && LNG >= 82.5   ){ UTC=5.5;}//+05:30 UTC.R1,2ab,2c/9
	if(LAT>=  25.54  && LAT <=  29.6  && LNG <=  97    && LNG >=  92.5   ||LAT>=  20     && LAT <=  29.6   && LNG <=  75     && LNG >=  70     ){ UTC=5.5;}//+05:30 UTC.R2d&3/9
	if(LAT>=  5.66   && LAT <=  26.37 && LNG <=  82.5  && LNG >=  75     ||LAT>=  25.54  && LAT <=  29.6   && LNG <=  97     && LNG >=  82.5   ||LAT>=  20      && LAT <=  25.54  && LNG <=  92.5   && LNG >= 82.5   ){ UTC=5.5;}//+05:30 UTC.R4-6/9	
	if(LAT>=  15     && LAT <=  20    && LNG <=  87.4  && LNG >=  82.5   ||LAT>=  8      && LAT <=  12     && LNG <=  75     && LNG >=  71.5   ||LAT>=  6.67    && LAT <=  15     && LNG <=  95     && LNG >= 90     ){ UTC=5.5;}//+05:30 UTC.R4-6/9
	
	//(17/38TZ)UTC+5,26 Region
	if(LAT>=  83     && LAT <=  90    && LNG <=  82.5  && LNG >=  67.5   ||LAT>=  79     && LAT <=  83     && LNG <=  75     && LNG >=  67.5   ||LAT>=  81      && LAT <=  83     && LNG <=  82.5   && LNG >= 75     ){ UTC=5;}//+5 UTC.R1-3/26
	if(LAT>=  61     && LAT <=  79    && LNG <=  78.2  && LNG >=  69.64  ||LAT>=  65.7   && LAT <=  75     && LNG <=  69.64  && LNG >=  65.3   ||LAT>=  61      && LAT <=  71.4   && LNG <=  82.5   && LNG >= 78.2   ){ UTC=5;}//+5 UTC.R4-6/26
	if(LAT>=  61     && LAT <=  65.7  && LNG <=  69.64 && LNG >=  60     ||LAT>=  61     && LAT <=  65     && LNG <=  86     && LNG >=  82.5   ||LAT>=  54.51   && LAT <=  61     && LNG <=  69.64  && LNG >= 54.4   ){ UTC=5;}//+5 UTC.R7-9/26
	if(LAT>=  58.3   && LAT <=  61    && LNG <=  75.8  && LNG >=  69.64  ||LAT>=  50     && LAT <=  54.51  && LNG <=  60.6   && LNG >=  51.7   ||LAT>=  37.27   && LAT <=  50     && LNG <=  60.6   && LNG >= 48.9   ){ UTC=5;}//+5 UTC.R10-12/26	
	if(LAT>=  37.27  && LAT <=  50    && LNG <=  67.5  && LNG >=  60.6   ||LAT>=  37.27  && LAT <=  41.1   && LNG <=  69     && LNG >=  67.5   ||LAT>=  37.27   && LAT <=  39.5   && LNG <=  75     && LNG >= 69     ){ UTC=5;}//+5 UTC.R13-15/26	
	if(LAT>=  34     && LAT <=  37.27 && LNG <=  75    && LNG >=  71.5   ||LAT>=  31.3   && LAT <=  34     && LNG <=  75     && LNG >=  69.2   ||LAT>=  29.6    && LAT <=  31.3   && LNG <=  75     && LNG >= 67.5   ){ UTC=5;}//+5 UTC.R16-18/26	
	if(LAT>=  25.77  && LAT <=  29.6  && LNG <=  70    && LNG >=  60.6   ||LAT>=  20     && LAT <=  25.77  && LNG <=  70     && LNG >=  67.5   ||LAT>=  12      && LAT <=  20     && LNG <=  71.5   && LNG >= 67.5   ){ UTC=5;}//+5 UTC.R19-21/26
	if(LAT>=  8      && LAT <=  12    && LNG <=  71.5  && LNG >=  67.5   ||LAT>= -5      && LAT <=  8      && LNG <=  75     && LNG >=  67.5   ||LAT>= -8       && LAT <=  5.66   && LNG <=  82.5   && LNG >= 75     ){ UTC=5;}//+5 UTC.R22-24/26	
	if(LAT>= -8      && LAT <= -5     && LNG <=  71    && LNG >=  67.5   ||LAT>= -60     && LAT <= -8      && LNG <=  82.5   && LNG >=  67.5   ){ UTC=5;}//+5 UTC.R25-26/26
	
	//(18/38TZ)UTC+04:30,3 Region
	if(LAT>=  34     && LAT <=  37.27 && LNG <=  71.5  && LNG >=  60.6   ||LAT>=  29.6   && LAT <=  34     && LNG <=  70     && LNG >=  60.6   ||LAT>=  31.3    && LAT <=  34     && LNG <=  69     && LNG >= 67.5   ){ UTC=4.5;}//+4.5 UTC.R1-3/3	
	
	//(19/38TZ)UTC+4,16 Region
	if(LAT>=  83     && LAT <=  90    && LNG <=  67.5  && LNG >=  52.5   ||LAT>=  52.4   && LAT <=  54.51  && LNG <=  51.7   && LNG >=  46     ||LAT>=  47.7    && LAT <=  52.4   && LNG <=  46     && LNG >= 42.13   ){ UTC=4;}//+4 UTC.R1-3/15
	if(LAT>=  50     && LAT <=  52.4  && LNG <=  51.7  && LNG >=  46     ||LAT>=  45     && LAT <=  47.7   && LNG <=  48.9   && LNG >=  46     ||LAT>=  41.3    && LAT <=  43.2   && LNG <=  44     && LNG >= 41.8    ){ UTC=4;}//+4 UTC.R4-6/15
	if(LAT>=  39.4   && LAT <=  43.2  && LNG <=  48.9  && LNG >=  44     ||LAT>=  22.84  && LAT <=  25.77  && LNG <=  67.5   && LNG >=  51.3   ||LAT>=  20      && LAT <=  22     && LNG <=  67.5   && LNG >= 55      ){ UTC=4;}//+4 UTC.R7-9/15
	if(LAT>=  13     && LAT <=  20    && LNG <=  67.7  && LNG >=  52.5   ||LAT>=  11     && LAT <=  13     && LNG <=  67.5   && LNG >=  54     ||LAT>= -60      && LAT <=  11     && LNG <=  67.5   && LNG >= 52.5    ){ UTC=4;}//+4 UTC.R10-12/15	
	if(LAT>= -10.86  && LAT <= -4     && LNG <=  52.5  && LNG >=  45     ||LAT>= -47.23  && LAT <= -45     && LNG <=  52.5   && LNG >=  49.5   ||LAT>=  54.51   && LAT <=  58.6   && LNG <=  54.4   && LNG >= 51.7    ){ UTC=4;}//+4 UTC.R13-15/15
	
	//(20/38TZ)UTC+03:30,4 Region
	if(LAT>=  37.27  && LAT <=  39.4  && LNG <=  48.9  && LNG >=  44     ||LAT>=  33     && LAT <=  37.27  && LNG <=  51.3   && LNG >=  45.5   ){ UTC=3.5;}//+3.5 UTC.R1-2/4
	if(LAT>=  33     && LAT <=  37.27 && LNG <=  60.6  && LNG >=  51.3   ||LAT>=  29.96  && LAT <=  33     && LNG <=  51.3   && LNG >=  47.86  ){ UTC=3.5;}//+3.5 UTC.R3-4/4
	
	//(21/29TZ)UT+3,28 Region
	if(LAT>=  83     && LAT <=  90    && LNG <=  52.5  && LNG >=  37.5   ||LAT>=  75     && LAT <=  81     && LNG <=  37.5   && LNG >=  34     ||LAT>=  75      && LAT <=  83     && LNG <=  69.64  && LNG >=  37.5   ){ UTC=3;}//+3 UTC.R1-3/29
	if(LAT>=  71.4   && LAT <=  75    && LNG <=  65.3  && LNG >=  37.5   ||LAT>=  63     && LAT <=  71.4   && LNG <=  60     && LNG >=  30     ||LAT>=  65.7    && LAT <=  71.4   && LNG <=  65.3   && LNG >=  60     ){ UTC=3;}//+3 UTC.R4-6/29	
	if(LAT>=  54.51  && LAT <=  63    && LNG <=  51.7  && LNG >=  28     ||LAT>=  61     && LAT <=  63     && LNG <=  60     && LNG >=  51.7   ||LAT>=  58.6    && LAT <=  61     && LNG <=  54.4   && LNG >=  51.7   ){ UTC=3;}//+3 UTC.R7-10/29 Omit R8
	if(LAT>=  51.67  && LAT <=  54.51 && LNG <=  40    && LNG >=  23.6   ||LAT>=  52.4   && LAT <=  54.51  && LNG <=  46     && LNG >=  40     ||LAT>=  45      && LAT <=  52.4   && LNG <=  42.5   && LNG >=  40     ){ UTC=3;}//+3 UTC.R11-13/29	
	if(LAT>=  45     && LAT <=  47.7  && LNG <=  46    && LNG >=  42.13  ||LAT>=  43.2   && LAT <=  45     && LNG <=  48.9   && LNG >=  40     ||LAT>=  37.27   && LAT <=  41.3   && LNG <=  44     && LNG >=  26     ){ UTC=3;}//+3 UTC.R14-16/29
	if(LAT>=  33     && LAT <=  37.27 && LNG <=  44    && LNG >=  41.2   ||LAT>=  29.96  && LAT <=  33     && LNG <=  47.86  && LNG >=  37.5   ||LAT>=  22.84   && LAT <=  29.96  && LNG <=  51.3   && LNG >=  37.5   ){ UTC=3;}//+3 UTC.R17-19/29	
	if(LAT>=  9.68   && LAT <=  22.84 && LNG <=  52.5  && LNG >=  37.5   ||LAT>=  20     && LAT <=  22.84  && LNG <=  55     && LNG >=  52.5   ||LAT>=  11      && LAT <=  13     && LNG <=  54     && LNG >=  52.5   ){ UTC=3;}//+3 UTC.R20-22/29
	if(LAT>=  6      && LAT <=  9.68  && LNG <=  23.9  && LNG >=  30.65  ||LAT>= -4      && LAT <=  9.68   && LNG <=  52.5   && LNG >=  30.65  ||LAT>= -10.86   && LAT <= -4      && LNG <=  45     && LNG >=  30.65  ){ UTC=3;}//+3 UTC.R23-25/29
	if(LAT>= -17.38  && LAT <= -10.86 && LNG <=  52.5  && LNG >=  40.67  ||LAT>= -45     && LAT <= -17.38  && LNG <=  52.5   && LNG >=  37.5   ){ UTC=3;}//+3 UTC.R26-27/29
	if(LAT>= -47.23  && LAT <= -45    && LNG <=  49.5  && LNG >=  37.5   ||LAT>= -60     && LAT <= -47.23  && LNG <=  52.5   && LNG >=  37.5   ){ UTC=3;}//+3 UTC.R28-29/29
	
	//(22/38TZ)UTC+2,17 Region
	if(LAT>=  81    && LAT <=  90     && LNG <=  37.5  && LNG >=  22.5   ||LAT>=  71.4   && LAT <=  75     && LNG <=  37.5   && LNG >=  22.5   ||LAT>=  63      && LAT <=  69.7   && LNG <=  30     && LNG >=  22.5   ){ UTC=2;}//+2 UTC.R1-3/17
	if(LAT>=  54.51 && LAT <=  63     && LNG <=  28    && LNG >=  19.8   ||LAT>=  50     && LAT <=  51.67  && LNG <=  40     && LNG >=  23.6   ||LAT>=  45      && LAT <=  50     && LNG <=  40     && LNG >=  21.67  ){ UTC=2;}//+2 UTC.R4-6/17
	if(LAT>=  41.3  && LAT <=  45     && LNG <=  40    && LNG >=  22.5   ||LAT>=  41.3   && LAT <=  43.2   && LNG <=  41.8   && LNG >=  40     ||LAT>=  39.7    && LAT <=  41.3   && LNG <=  26     && LNG >=  20.5   ){ UTC=2;}//+2 UTC.R7a,7b,8/17
	if(LAT>=  33    && LAT <=  39.7   && LNG <=  26    && LNG >=  19.8   ||LAT>=  33     && LAT <=  37.27  && LNG <=  41.2   && LNG >=  26     ||LAT>=  21      && LAT <=  33     && LNG <=  37.5   && LNG >=  9.5    ){ UTC=2;}//+2 UTC.R9-11/17
	if(LAT>=  9.68  && LAT <=  21     && LNG <=  37.5  && LNG >=  23.9   ||LAT>= -17.38  && LAT <= -6      && LNG <=  30.65  && LNG >=  22     ||LAT>= -17.38   && LAT <= -10.86  && LNG <=  40.67  && LNG >=  30.65  ){ UTC=2;}//+2 UTC.R12-14/17
	if(LAT>= -30    && LAT <= -17.38  && LNG <=  37.5  && LNG >=  11.58  ||LAT>= -34.9   && LAT <= -30     && LNG <=  30.65  && LNG >=  22     ||LAT>= -60      && LAT <= -34.9   && LNG <=  37.5   && LNG >=  22.5   ){ UTC=2;}//+2 UTC.R15-17/17	
	
	//(23/38TZ)UTC+1,24 Region
	if(LAT>=  63    && LAT <=  90     && LNG <=  22.5  && LNG >=  7.5    ||LAT>=  75     && LAT <=  81     && LNG <=  34     && LNG >=  22.5   ||LAT>=  57.5    && LAT <=  63     && LNG <=  19.8   && LNG >=  3.7    ){ UTC=1;}//+1 UTC.R1-3/24
	if(LAT>=  54    && LAT <=  57.5   && LNG <=  19.8  && LNG >=  7      ||LAT>=  50     && LAT <=  54     && LNG <=  19.8   && LNG >=  2.3    ||LAT>=  50      && LAT <=  54.51  && LNG <=  23.6   && LNG >=  19.8   ){ UTC=1;}//+1 UTC.R4-6/24
	if(LAT>=  33    && LAT <=  50     && LNG <=  19.8  && LNG >= -5      ||LAT>=  45     && LAT <=  50     && LNG <=  21.67  && LNG >=  19.8   ||LAT>=  41.3    && LAT <=  45     && LNG <=  22.5   && LNG >=  19.8   ){ UTC=1;}//+1 UTC.R7-9/24	
	if(LAT>=  26    && LAT <=  45     && LNG <= -5     && LNG >= -18.75  ||LAT>=  25     && LAT <=  33     && LNG <=  9.5    && LNG >= -5      ||LAT>=  21      && LAT <=  25     && LNG <=  9.5    && LNG >=  0      ){ UTC=1;}//+1 UTC.R10-12/24	
	if(LAT>=  14    && LAT <=  21     && LNG <=  23.9  && LNG >=  4.2    ||LAT>=  6      && LAT <=  14     && LNG <=  23.9   && LNG >=  1.96   ||LAT>=  2.1     && LAT <=  6      && LNG <=  22     && LNG >=  6      ){ UTC=1;}//+1 UTC.R13-15/24
	if(LAT>=  0     && LAT <=  2.1    && LNG <=  22    && LNG >=  7.5    ||LAT>= -1.5    && LAT <=  0      && LNG <=  7      && LNG >=  5.2    ||LAT>= -17.38   && LAT <=  0      && LNG <=  22     && LNG >=  7      ){ UTC=1;}//+1 UTC.R16-18/24
	if(LAT>= -30    && LAT <= -17.38  && LNG <=  11.58 && LNG >=  7.5    ||LAT>= -34.9   && LAT <= -30     && LNG <=  17     && LNG >=  7.5    ||LAT>= -60      && LAT <= -34.9   && LNG <=  22.5   && LNG >=  7.5    ){ UTC=1;}//+1 UTC.R19-21/24
	if(LAT>= -56    && LAT <= -50     && LNG <=  7.5   && LNG >=  1.5    ||LAT>=  69.7   && LAT <=  71.4   && LNG <=  30     && LNG >=  22.5   ||LAT>=  39.7    && LAT <=  41.3   && LNG <=  20.5   && LNG >=  19.8   ){ UTC=1;}//+1 UTC.R22-24/24
	
	//(24/38TZ)UTC±0,20+1 Region
	if(LAT>=  76    && LAT <=  79.2   && LNG <= -15    && LNG >= -22.5   ||LAT>=  63     && LAT <=  90     && LNG <=  7.5    && LNG >= -7.5    ||LAT>=  63      && LAT <=  67     && LNG <= -7.5    && LNG >= -25     ){ UTC=0;}//±0 UTC.R1-3/20
	if(LAT>=  60    && LAT <=  63     && LNG <=  3.7   && LNG >= -7.5    ||LAT>=  54     && LAT <=  60     && LNG <=  3.7    && LNG >= -11.25  ||LAT>=  54      && LAT <=  57.5   && LNG <=  3.5    && LNG >= -7.5    ){ UTC=0;}//±0 UTC.R4-6/20	
	if(LAT>=  50    && LAT <=  54     && LNG <=  2.3   && LNG >= -11.25  ||LAT>=  45     && LAT <=  50     && LNG <= -5      && LNG >= -7.5    ||LAT>=  0       && LAT <=  20     && LNG <= -5      && LNG >= -18.75  ){ UTC=0;}//±0 UTC.R7-9/20	
	if(LAT>=  0     && LAT <=  25     && LNG <=  0     && LNG >= -5      ||LAT>=  14     && LAT <=  21     && LNG <=  4.2    && LNG >=  0      ||LAT>=  6       && LAT <=  14     && LNG <=  1.96   && LNG >=  0      ){ UTC=0;}//±0 UTC.R10-12/20	
	if(LAT>=  0     && LAT <=  6      && LNG <=  6     && LNG >=  0      ||LAT>=  0      && LAT <=  2.1    && LNG <=  7.5    && LNG >=  6      ||LAT>= -1.5     && LAT <=  0      && LNG <=  5.2    && LNG >= -7.5    ){ UTC=0;}//±0 UTC.R13-15/20	
	if(LAT>= -50    && LAT <= -1.5    && LNG <=  7.5   && LNG >= -7.5    ||LAT>= -8      && LAT <= -7.8    && LNG <= -7.5    && LNG >= -15     ||LAT>= -41      && LAT <= -35     && LNG <= -7.5    && LNG >= -15     ){ UTC=0;}//±0 UTC.R16-18/20	
	if(LAT>= -60    && LAT <= -50     && LNG <=  1.5   && LNG >= -7.5    ||LAT>= -60     && LAT <= -56     && LNG <=  7.5    && LNG >= 1.5     ||LAT>=  20      && LAT <=  26     && LNG <= -5      && LNG >= -12     ){ UTC=0;}//±0 UTC.R19,19.2,20/20
	
	//(25/38TZ)UTC-1,16 Region
	if(LAT>=  84    && LAT <=  90    && LNG <= -7.5    && LNG >= -22.5   ||LAT>=  79.2   && LAT <=  84     && LNG <= -7.5    && LNG >= -9      ||LAT>=  71.5    && LAT <=  79.2   && LNG <= -7.5    && LNG >= -15     ){ UTC=-1;}//-1 UTC.R1-3/16
	if(LAT>=  70.2  && LAT <=  71.5  && LNG <= -22.5   && LNG >= -25.5   ||LAT>=  67     && LAT <=  71.5   && LNG <= -7.5    && LNG >= -22.5   ||LAT>=  45      && LAT <=  63     && LNG <= -15     && LNG >= -22.5   ){ UTC=-1;}//-1 UTC.R4-6/16	
	if(LAT>=  60    && LAT <=  63    && LNG <= -7.5    && LNG >= -15     ||LAT>=  50     && LAT <=  60     && LNG <= -11.25  && LNG >= -15     ||LAT>=  45      && LAT <=  50     && LNG <= -7.5    && LNG >= -15     ){ UTC=-1;}//-1 UTC.R7-9/16		
	if(LAT>=  36.5  && LAT <=  40    && LNG <= -22.5   && LNG >= -32     ||LAT>= -60     && LAT <=  45     && LNG <= -18.75  && LNG >= -22.5   ||LAT>= -41      && LAT <=  0      && LNG <= -15     && LNG >= -18.75  ){ UTC=-1;}//-1 UTC.R10-12/16
	if(LAT>= -7.8   && LAT <=  0     && LNG <= -7.5    && LNG >= -15     ||LAT>= -35     && LAT <= -8      && LNG <= -7.5    && LNG >= -15     ){ UTC=-1;}//-1 UTC.R13,14/16		
	if(LAT>= -60    && LAT <= -41    && LNG <= -7.5    && LNG >= -18.75  ||LAT>=  14     && LAT <=  18     && LNG <= -22.5   && LNG >= -30     ){ UTC=-1;}//-1 UTC.R15,16/16	
	
	//(26/38TZ)UTC-2,11 Region
	if(LAT>=  84    && LAT <=  90    && LNG <= -22.5   && LNG >= -37.5   ||LAT>=  63     && LAT <=  65.5   && LNG <= -30     && LNG >= -37.5   ||LAT>=  63      && LAT <=  67     && LNG <= -25     && LNG >= -30     ){ UTC=-2;}//-2 UTC.R1-3/11
	if(LAT>=  40    && LAT <=  63    && LNG <= -22.5   && LNG >= -37.5   ||LAT>=  36.5   && LAT <=  40     && LNG <= -32     && LNG >= -37.5   ||LAT>=  18      && LAT <=  36.5   && LNG <= -22.5   && LNG >= -37.5   ){ UTC=-2;}//-2 UTC.R4-6/11
	if(LAT>=  14    && LAT <=  18    && LNG <= -30     && LNG >= -37.5   ||LAT>= -4      && LAT <= -14     && LNG <= -22.5   && LNG >= -37.5   ||LAT>= -12      && LAT <= -4      && LNG <= -22.5   && LNG >= -34     ){ UTC=-2;}//-2 UTC.R7-9/11	
	if(LAT>= -60    && LAT <= -12    && LNG <= -22.5   && LNG >= -37.5   ||LAT>= -55.5   && LAT <= -52.7   && LNG <= -37.5   && LNG >= -45     ){ UTC=  -2;}//-2 UTC.R10-11/11
	
	//(27/38TZ)UTC-3,23 Region
	if(LAT>= -9.3   && LAT <=  90    && LNG <= -37.5   && LNG >= -52.5   ||LAT>=  79.2   && LAT <=  83     && LNG <= -52.5   && LNG >= -61     ||LAT>=  79.2    && LAT <=  81     && LNG <= -61     && LNG >= -67.5  ){ UTC=-3;}//-3 UTC.R1-3/23
	if(LAT>=  77    && LAT <=  79.2  && LNG <= -52.5   && LNG >= -73.2   ||LAT>=  76     && LAT <=  84     && LNG <= -22.5   && LNG >= -37.5   ||LAT>=  79.2    && LAT <=  84     && LNG <= -9      && LNG >= -22.5  ){ UTC=-3;}//-3 UTC.R4-6/23
	if(LAT>=  71.5  && LAT <=  76    && LNG <= -15     && LNG >= -37.5   ||LAT>=  70.2   && LAT <=  71.5   && LNG <= -25.5   && LNG >= -37.5   ||LAT>=  67      && LAT <=  70.2   && LNG <= -22.5   && LNG >= -37.5  ){ UTC=-3;}//-3 UTC.R7-9/23
	if(LAT>=  65.5  && LAT <=  67    && LNG <= -30     && LNG >= -37.5   ||LAT>= -9.3    && LAT <=  5.8    && LNG <= -52.5   && LNG >= -57     ||LAT>= -12      && LAT <= -4      && LNG <= -34     && LNG >= -37.5  ){ UTC=-3;}//-3 UTC.R10-12/23	
	if(LAT>= -21.5  && LAT <= -9.3   && LNG <= -37.5   && LNG >= -54     ||LAT>= -27.5   && LAT <= -21.5   && LNG <= -37.5   && LNG >= -54     ||LAT>= -52.7    && LAT <= -27.5   && LNG <= -37.5   && LNG >= -67.5  ){ UTC=-3;}//-3 UTC.R13-15/23
	if(LAT>= -27.5  && LAT <= -21.5  && LNG <= -59     && LNG >= -67.5   ||LAT>= -60     && LAT <= -52.7   && LNG <= -45     && LNG >= -52.5   ||LAT>= -60      && LAT <= -55.5   && LNG <= -37.5   && LNG >= -45    ){ UTC=-3;}//-3 UTC.R16-18/23
	if(LAT>= -49    && LAT <= -31    && LNG <= -67.5   && LNG >= -71.7   ||LAT>= -56     && LAT <= -49     && LNG <= -67.5   && LNG >= -75.5   ||LAT>=  70.8    && LAT <=  76     && LNG <= -52.5   && LNG >= -60    ){ UTC=-3;}//-3 UTC.R19-21/23
	if(LAT>=  60    && LAT <=  70.8  && LNG <= -52.5   && LNG >= -57     ||LAT>=  46     && LAT <=  47.2   && LNG <= -55     && LNG >= -57     ){ UTC= -3;}//-3 .R22-23/23
	
	//(28/38TZ)UTC−03:30,1 Region
	if(LAT>=  47.2  && LAT <= 52     && LNG <= -52.5   && LNG >= -57     ||LAT>=  46     && LAT <=  50.2   && LNG <= -57     && LNG >= -59     ||LAT>=  46      && LAT <=  47.2   && LNG <= -52.5   && LNG >= -55    ){ UTC=-3.5;}//-3 1/2 1/2UTC.R1/1
	
	//(29/38TZ)UTC-4,18 Region
	if(LAT>=  83    && LAT <=  90    && LNG <= -52.5   && LNG >= -67.5   ||LAT>=  70.8   && LAT <=  76    && LNG <= -60     && LNG >= -67.5    ||LAT>=  60      && LAT <=  70.8   && LNG <= -57     && LNG >= -60    ){ UTC=-4;}//-4 UTC.R1-3/18
	if(LAT>=  54    && LAT <=  60    && LNG <= -52.5   && LNG >= -64     ||LAT>=  52     && LAT <=  54    && LNG <= -52.5   && LNG >= -67.5    ||LAT>=  48.3    && LAT <=  52     && LNG <= -59     && LNG >= -61.5  ){ UTC=-4;}//-4 UTC.R4-6/18
	if(LAT>=  50.2  && LAT <=  52    && LNG <= -57     && LNG >= -59     ||LAT>= -21.5   && LAT <=  48.3  && LNG <= -59     && LNG >= -67.5    ||LAT>=  5.8     && LAT <=  46     && LNG <= -52.5   && LNG >= -59    ){ UTC=-4;}//-4 UTC.R7,9,10/18
	if(LAT>=  7     && LAT <=  27.7  && LNG <= -67.5   && LNG >= -71.7   ||LAT>= -21.5   && LAT <=  5.8   && LNG <= -57     && LNG >= -59      ||LAT>=- 21.5    && LAT <= -9.3    && LNG <= -51     && LNG >= -57    ){ UTC=-4;}//-4 UTC.R11-13/18
	if(LAT>= -18.5  && LAT <=  1.3   && LNG <= -67.5   && LNG >= -69     ||LAT>= -27.5   && LAT <= -21.5  && LNG <= -54     && LNG >= -59      ||LAT>= -60      && LAT <= -52.7   && LNG <= -52.5   && LNG >= -67.5  ){ UTC=-4;}//-4 UTC.R8,14,15/18
	if(LAT>= -25    && LAT <= -18.5  && LNG <= -67.5   && LNG >= -71.7   ||LAT>= -31     && LAT <= -25    && LNG <= -67.5   && LNG >= -81.6    ||LAT>= -49      && LAT <= -31     && LNG <= -71.7   && LNG >= -75.5  ){ UTC=-4;}//-4 UTC.R16-18/18
	
	//(30/38TZ)UTC-5,15 Region
	if(LAT>=  79.2  && LAT <=  90    && LNG <= -67.5   && LNG >= -85     ||LAT>=  81     && LAT <=  83    && LNG <= -61     && LNG >= -67.5    ||LAT>=  76      && LAT <=  79.2   && LNG <= -73.2   && LNG >= -85   ){ UTC=-5;}//-5 UTC.R1-3/15
	if(LAT>=  28    && LAT <=  76    && LNG <= -67.5   && LNG >= -85     ||LAT>=  60     && LAT <=  70.8  && LNG <= -60     && LNG >= -67.5    ||LAT>=  46      && LAT <=  60     && LNG <= -85     && LNG >= -90   ){ UTC=-5;}//-5 UTC.R4-6/15
	if(LAT>=  54    && LAT <=  60    && LNG <= -64     && LNG >= -67.5   ||LAT>=  48.3   && LAT <=  52    && LNG <= -61.5   && LNG >= -67.5    ||LAT>=  22.7    && LAT <=  28     && LNG <= -67.5   && LNG >= -82.5 ){ UTC=-5;}//-5 UTC.R7-9/15
	if(LAT>= -25    && LAT <=  22.7  && LNG <= -71.7   && LNG >= -82.5   ||LAT>=  1.3    && LAT <=  7     && LNG <= -67.5   && LNG >= -71.7    ||LAT>= -18.5    && LAT <=  1.3    && LNG <= -69     && LNG >= -71.7 ){ UTC=-5;}//-5 UTC.R10-12/15
	if(LAT>= -31    && LAT <= -25    && LNG <= -81.6   && LNG >= -82.5   ||LAT>= -60     && LAT <= -31    && LNG <= -75.5   && LNG >= -82.5    ||LAT>= -60      && LAT <= -56     && LNG <= -67.5   && LNG >= -75.5 ){ UTC=-5;}//-5 UTC.R13-15/15
	
	//(31/38TZ)UTC-6,10 Region
	if(LAT>=  80    && LAT <=  90    && LNG <= -85     && LNG >= -97.5   ||LAT>=  71     && LAT <= 80     && LNG <= -85     && LNG >= -103     ||LAT>=  67      && LAT <=  71     && LNG <= -85     && LNG >= -90   ){ UTC=-6;}//-6 UTC.R1-3/10
	if(LAT>=  60    && LAT <=  67    && LNG <= -85     && LNG >= -103    ||LAT>=  49     && LAT <= 60     && LNG <= -90     && LNG >= -110     ||LAT>=  28      && LAT <=  49     && LNG <= -90     && LNG >= -100  ){ UTC=-6;}//-6 UTC.R4-6/10
	if(LAT>=  28    && LAT <=  46    && LNG <= -85     && LNG >= -90     ||LAT>=  15     && LAT <= 28     && LNG <= -82.5   && LNG >= -105     ){ UTC= -6;}//-6 UTC.R7-8/10
	if(LAT>= -28    && LAT <= -26    && LNG <= -97.5   && LNG >= -112.5  ||LAT>= -60     && LAT <= 15     && LNG <= -82.5   && LNG >= -97.5    ){ UTC= -6;}//-6 UTC.R9-10/10
	
	//(32/38TZ)UTC-7,14 Region
	if(LAT>=  80    && LAT <=  90    && LNG <= -97.5   && LNG >= -112.5  ||LAT>=  71     && LAT <=  80    && LNG <= -103    && LNG >= -112.5   ||LAT>=  71      && LAT <=  79     && LNG <= -112.5  && LNG >= -127.5 ){ UTC=-7;}//-7 UTC.R1-3/14
	if(LAT>=  60    && LAT <=  71    && LNG <= -103    && LNG >= -141    ||LAT>=  67     && LAT <=  71    && LNG <= -90     && LNG >= -103     ||LAT>=  55      && LAT <=  60     && LNG <= -110    && LNG >= -122   ){ UTC=-7;}//-7 UTC.R4-6/14
	if(LAT>=  49    && LAT <=  55    && LNG <= -110    && LNG >= -116    ||LAT>=  45     && LAT <=  49    && LNG <= -100    && LNG >= -116     ||LAT>=  28      && LAT <=  45     && LNG <= -100    && LNG >= -114   ){ UTC=-7;}//-7 UTC.R7-9/14
	if(LAT>=  24    && LAT <=  28    && LNG <= -112.5  && LNG >= -116    ||LAT>=  10.3   && LAT <=  28    && LNG <= -105    && LNG >= -112.5   ||LAT>=  10.2    && LAT <=  15     && LNG <= -97.5   && LNG >= -105   ){ UTC=-7;}//-7 UTC.R10-12/14
	if(LAT>= -26    && LAT <=  10.2  && LNG <= -105    && LNG >= -112.5  ||LAT>= -60     && LAT <= -28    && LNG <= -97.5   && LNG >= -112.5   ){ UTC= -7;}//-7 UTC.R13&14/14
	
	//(33/38TZ)UTC-8,8 Region
	if(LAT>=  79    && LAT <=  90    && LNG <= -112    && LNG >= -127.5  ||LAT>=  55     && LAT <=  60    && LNG <= -116    && LNG >= -129     ||LAT>=  45      && LAT <=  55     && LNG <= -116    && LNG >= -135   ){ UTC=-8;}//-8 UTC.R1-3/8
	if(LAT>=  28    && LAT <=  45    && LNG <= -114    && LNG >= -127.5  ||LAT>=  24     && LAT <=  28    && LNG <= -116    && LNG >= -127.5   ||LAT>= -60      && LAT <=  24     && LNG <= -112.5  && LNG >= -127.5 ){ UTC=-8;}//-8 UTC.R4-6/8
	if(LAT>=  10.2  && LAT <=  10.3  && LNG <= -105    && LNG >= -112.5  ||LAT>= -27     && LAT <= -22    && LNG <= -127.5  && LNG >= -132     ){ UTC=-8;}//-8 UTC.R7&8/8
	
	//(34/38TZ)UTC-9,11 Region
	if(LAT>=  71    && LAT <=  90    && LNG <= -127.5  && LNG >= -142.5  ||LAT>=  51.5   && LAT <=  71    && LNG <= -141    && LNG >= -168     ||LAT>=  60      && LAT <=  63.5   && LNG <= -168    && LNG >= -172.5 ){ UTC=-9;}//-9 UTC.R1-3/11
	if(LAT>=  55    && LAT <=  60    && LNG <= -129    && LNG >= -141    ||LAT>=  51.5   && LAT <=  55    && LNG <= -135    && LNG >= -141     ||LAT>=  45      && LAT <=  51.5   && LNG <= -135    && LNG >= -142.5 ){ UTC=-9;}//-9 UTC.R4-6/11
	if(LAT>= -26    && LAT <= -22    && LNG <= -133    && LNG >= -135    ||LAT>= -30     && LAT <= -26    && LNG <= -127.5  && LNG >= -135     ||LAT>= -60      && LAT <= -30     && LNG <= -127    && LNG >= -142.5 ){ UTC=-9;}//-9 UTC.R9-11/11
	if(LAT>= -7     && LAT <=  45    && LNG <= -127.5  && LNG >= -142.5  ||LAT>= -22     && LAT <= -7     && LNG <= -127.5  && LNG >= -135     ){ UTC=-9;}//-9 UTC.R7-9/11
	
	//(35/38TZ)UTC-9 1/2,1 Region
	if(LAT>= -13    && LAT <= -6     && LNG <= -135    && LNG >= -142.5  ){UTC=-9.5;}//-9 1/2UTC.R1/1
	
	//(36/38TZ)UTC-10,18 Region
	if(LAT>=  71    && LAT <=  90    && LNG <= -142.5  && LNG >= -157.5  ||LAT>=  59     && LAT <=  63.5  && LNG <= -172.5  && LNG >= -179.9   ||LAT>=  54      && LAT <=  59     && LNG <= -168    && LNG >= -179.9 ){ UTC=-10;}//-10 UTC.R1-3/18
	if(LAT>=  54    && LAT <=  59    && LNG <=  180    && LNG >=  172.5  ||LAT>=  48     && LAT <=  54    && LNG <= -168    && LNG >= -179.9   ||LAT>=  48      && LAT <=  54     && LNG <=  180    && LNG >=  168   ){ UTC=-10;}//-10 UTC.R3-4/18
	if(LAT>=  48    && LAT <=  51    && LNG <= -142.5  && LNG >= -168    ||LAT>=  30     && LAT <=  48    && LNG <= -142.5  && LNG >= -157.5   ||LAT>=  27      && LAT <=  30     && LNG <= -179    && LNG >= -179.9 ){ UTC=-10;}//-10 UTC.R5-7/18
	if(LAT>=  24.7  && LAT <=  27    && LNG <= -176.5  && LNG >= -179.9  ||LAT>=  24.7   && LAT <=  30    && LNG <= -172.5  && LNG >= -176.5   ||LAT>=  15      && LAT <=  30     && LNG <= -142.5  && LNG >= -172.5 ){ UTC=-10;}//-10 UTC.R8-10/18	
	if(LAT>=  4     && LAT <=  15    && LNG <= -150    && LNG >= -157.5  ||LAT>= -13     && LAT <=  15    && LNG <= -142.5  && LNG >= -150     ||LAT>= -13      && LAT <= -6      && LNG <= -155    && LNG >= -167.5 ){ UTC=-10;}//-10 UTC.R11-13/18
	if(LAT>= -13    && LAT <= -12    && LNG <= -150    && LNG >= -155    ||LAT>= -22     && LAT <= -13    && LNG <= -135    && LNG >= -167     ||LAT>= -25      && LAT <= -22     && LNG <= -157.5  && LNG >= -163   ){ UTC=-10;}//-10 UTC.R14-16/18
	if(LAT>= -30    && LAT <= -22    && LNG <= -135    && LNG >= -142.5  ||LAT>= -60     && LAT <= -22    && LNG <= -142.5  && LNG >= -157.5   ){ UTC=-10;}//-10 UTC.R17&18/18
	
	//(37/38TZ)UTC-11,13 Region
	if(LAT>=  71    && LAT <=  90    && LNG <= -157.5  && LNG >= -172.5  ||LAT>=  30     && LAT <=  48    && LNG <= -157.5  && LNG >= -172.5   ||LAT>=  30      && LAT <=  35     && LNG <= -172.5  && LNG >= -179.9 ){ UTC=-11;}//-11 UTC.R1-3/13
	if(LAT>=  27    && LAT <=  30    && LNG <= -176.5  && LNG >= -179    ||LAT>= -2.5    && LAT <=  15    && LNG <= -160.5  && LNG >= -172.5   ||LAT>=  4       && LAT <=  15     && LNG <= -157.5  && LNG >= -160.5 ){ UTC=-11;}//-11 UTC.R4-6/13
	if(LAT>= -2.5   && LAT <=  0     && LNG <= -158.5  && LNG >= -160.5  ||LAT>= -10     && LAT <= -6     && LNG <= -167.5  && LNG >= -169     ||LAT>= -13      && LAT <= -10     && LNG <= -167.5  && LNG >= -171   ){ UTC=-11;}//-11 UTC.R7-9/13
	if(LAT>= -15    && LAT <= -13    && LNG <= -167    && LNG >= -171    ||LAT>= -22     && LAT <= -15    && LNG <= -167    && LNG >= -172.5   ||LAT>= -25      && LAT <= -22     && LNG <= -163    && LNG >= -172.5 ){ UTC=-11;}//-11 UTC.R10-12/13
	if(LAT>= -60    && LAT <= -25    && LNG <= -157.5  && LNG >= -172.5  ){ UTC=-11;}//-11 UTC.R13/13
	
	//(38/38TZ)UTC-12,4 Region
	if(LAT>=  75.00 && LAT <= 90.00  && LNG >= -179.99 && LNG <= -172.5  ||LAT>=  75.00  && LAT <=  90.00 && LNG >= -179.99 && LNG <= -172.5   ||LAT>= -2.50    && LAT <=  24.70  && LNG >= -179.99 && LNG <= -172.5 ){ UTC=-12;}//-12 UTC.R1&2/4
	if(LAT>= -2.50  && LAT <= 24.70  && LNG >= -179.99 && LNG <= -172.5  ||LAT>= -90.0   && LAT <= -45.00 && LNG >= -179.99 && LNG <= -172.5   ){ UTC=-12;}//-12 UTC.R3&4/4
	
	//Antartica,
	if(LAT>=  -90    && LAT < -60     && LNG >= -179.99 && LNG <=  180    ){ Serial.println("Antartica");UTC=0;}//-12 UTC.R1&2/4

    //Coor Input Err , Returns Invalid if input >360 degrees
	if(LAT> -99999  && LAT < -90     && LNG > -99999   && LNG < 99999    ||LAT> 90.0     && LAT <  99999  && LNG > -99999   && LNG < 99999     ){ Serial.println("Invalid LAT >180 Degrees");UTC=0;}//Return Invalid if LAT  >360 degrees
	if(LAT> -99999  && LAT <  99999  && LNG > 180      && LNG < 99999    ||LAT> -99999   && LAT <  99999  && LNG > -99999   && LNG < -179.99   ){ Serial.println("Invalid LNG >360 Degrees");UTC=0;}//Return Invalid if LONG >360 degrees
	
Serial.print("Time Zone : ");Serial.println(UTC);Serial.println();}

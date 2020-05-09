# Localised-Lo-Resolution-Timezone-Decoder
...Decode UTC without GSM or the Internet ( non-DST) by Coordinate 

- Experimental Lo-Resolution Localized squared Global Timezone decoder for Planet Earth Coordinate including the Antartica V.0.3
- Valid LAT input between -90(South) to 90(North) Valid LNG in-between -179.99(West) to 180(East)else return Invalid Input.
- Experimented on UnoArduSim V2.5 for Global S&G NEO-6M GPS Precision Clock Auto Timezone decode by Coordinate.
- Averaged Decoding accuracy since countries are not a squared border.Refer(1---8-UTC.png)
- Incorporated boolean to Accepts 2 different Serial input,LAT & LNG in one go or one after another.
- Not Cellular nor Internet but locally decode and adjusted by MCU from UTC±0(NEO-6M).
- Requires little more higher sram & program space than UNO(Atmega326),recommends Mega(Atmega2560) but later fixed this issue by removing   Region naming strings.
- Only decodes when a valid coor exist else display UTC±0 time.(NEO-6M = 5~30 min)
- Pending DST encoding.https://www.timeanddate.com/time/dst/
- Daylight Saving Time (DST) is the practice of setting the clocks forward one hour from standard time during the summer months, and back   again in the fall, in order to make better use of natural daylight.
- Other reference https://en.wikipedia.org/wiki/List_of_UTC_time_offsets.
- Coded and tested by Suren,Malaysia.March 2020 during Covid-19 lockdown.

“Given the complexity of how global time zones work, there are likely errors and inconsistencies with most/all of these maps and none of this data should be considered “official”.”



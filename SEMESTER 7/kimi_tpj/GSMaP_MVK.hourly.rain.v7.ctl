*
* GrADS control file for GSMaP_MVK Hourly Rain Rate (ver.7).
*
*  Negative value indicates missing due to following reason.
* 	-4: missing due to sea ice in microwave retrieval
*       -8: missing due to low temperature in microwave retrieval
*      -99: missing due to no observation by IR and/or microwave
*   
*   DSET   ^gsmap_mvk.%y4%m2%d2.%h200.v7.0000.0.dat
DSET   D:\data_himawari\gsmap_mvk.20251111.2300.v7.4112.0.dat
TITLE  GSMaP_MVK 0.1deg Hourly (ver.7)
OPTIONS YREV LITTLE_ENDIAN TEMPLATE
UNDEF  -99.0
XDEF   3600 LINEAR  0.05 0.1
YDEF   1200  LINEAR -59.95 0.1
ZDEF     1 LEVELS 1013
TDEF   87600 LINEAR 00Z1jan2014 1hr
VARS    1
precip    0  99   hourly averaged rain rate [mm/hr]
ENDVARS

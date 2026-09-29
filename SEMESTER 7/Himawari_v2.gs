### Plot data Himawari-8 ###

#buka data NC
'sdfopen C:/Users/wendi/PROGRAMMING/HImawari-8/NC_H08_20200823_0600_R21_FLDK.02401_02401.nc'

#buka data Radar
#'open C:/Users/wendi/PROGRAMMING/.ctl'


#set lokasi Indonesia
'set lon 95 140'
'set lat -10 10'

#set warna

#'set clevs 200 210 220 230 240 250 260 270 280 290'
'set clevs 0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1'     
'set ccols 1 2 3 4 5 6 7 8 9'        


#plot data
'set gxout shaded'
'd albedo_03'
#'d tbb_13'
'cbarn'


#simpan data
'printim C:/Users/wendi/PROGRAMMING/HImawari-8/Himawari_8.png white'    #simpan dat
#'disable print'
     
'close 1' 




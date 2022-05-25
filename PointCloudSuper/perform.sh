

#!/bin/sh  
exe="PointCloudSuper" 
des="/home/alexkity/source/PointCloudSuper"
deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')  
cp $deplist $des


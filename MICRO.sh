ant="1895000000;"
var=";" # Here between quotes goes the speed of the new processor

sed -i -e 's/'$ant'/'$var'/' ./SOURCE/dsa_512.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/dsa_1024.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/dsa_2048.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_prime192v1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_secp224r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_prime256v1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_secp384r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_secp521r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect163k1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect233k1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect283k1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect409k1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect571k1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect163r2.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect233r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect283r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect409r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/ecdsa_sect571r1.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_512.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_1024.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_2048.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_3072.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_4096.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_7680.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa15_15360.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_512.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_1024.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_2048.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_3072.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_4096.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_7680.c
sed -i -e 's/'$ant'/'$var'/' ./SOURCE/rsa22_15360.c


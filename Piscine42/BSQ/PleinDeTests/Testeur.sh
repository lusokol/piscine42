#!/bin/bash

cd ../
echo "Test du Makefile"
echo ""
make clean
make fclean
make all
make re
echo ""
echo "Test de differentes grilles"
echo ""
echo "1-1-0 :"
./bsq ./PleinDeTests/map/1-1-0 > ./PleinDeTests/myResult/myResult-1-1-0
diff -U 1 ./PleinDeTests/myResult/myResult-1-1-0 ./PleinDeTests/result/result-1-1-0 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "1-1-1 :"
./bsq ./PleinDeTests/map/1-1-1 > ./PleinDeTests/myResult/myResult-1-1-1
diff -U 1 ./PleinDeTests/myResult/myResult-1-1-1 ./PleinDeTests/result/result-1-1-1 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "5-1-1 :"
./bsq ./PleinDeTests/map/5-1-1 > ./PleinDeTests/myResult/myResult-5-1-1
diff -U 1 ./PleinDeTests/myResult/myResult-5-1-1 ./PleinDeTests/result/result-5-1-1 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "1-5-1 :"
./bsq ./PleinDeTests/map/1-5-1 > ./PleinDeTests/myResult/myResult-1-5-1
diff -U 1 ./PleinDeTests/myResult/myResult-1-5-1 ./PleinDeTests/result/result-1-5-1 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "5-5-1 :"
./bsq ./PleinDeTests/map/5-5-1 > ./PleinDeTests/myResult/myResult-5-5-1
diff -U 5 ./PleinDeTests/myResult/myResult-5-5-1 ./PleinDeTests/result/result-5-5-1 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "5-5-vide :"
./bsq ./PleinDeTests/map/5-5-vide > ./PleinDeTests/myResult/myResult-5-5-vide
diff -U 5 ./PleinDeTests/myResult/myResult-5-5-vide ./PleinDeTests/result/result-5-5-vide > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "5-5-plein :"
./bsq ./PleinDeTests/map/5-5-plein > ./PleinDeTests/myResult/myResult-5-5-plein
diff -U 5 ./PleinDeTests/myResult/myResult-5-5-plein ./PleinDeTests/result/result-5-5-plein > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "dammier :"
./bsq ./PleinDeTests/map/dammier > ./PleinDeTests/myResult/myResult-dammier
diff -U 8 ./PleinDeTests/myResult/myResult-dammier ./PleinDeTests/result/result-dammier > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "10-10-2 :"
./bsq ./PleinDeTests/map/10-10-2 > ./PleinDeTests/myResult/myResult-10-10-2
diff -U 10 ./PleinDeTests/myResult/myResult-10-10-2 ./PleinDeTests/result/result-10-10-2 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "50-50-5 :"
./bsq ./PleinDeTests/map/50-50-5 > ./PleinDeTests/myResult/myResult-50-50-5
diff -U 50 ./PleinDeTests/myResult/myResult-50-50-5 ./PleinDeTests/result/result-50-50-5 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "100-100-10 :"
./bsq ./PleinDeTests/map/100-100-10 > ./PleinDeTests/myResult/myResult-100-100-10
diff -U 100 ./PleinDeTests/myResult/myResult-100-100-10 ./PleinDeTests/result/result-100-100-10 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "1000-1000-10 :"
./bsq ./PleinDeTests/map/1000-1000-10 > ./PleinDeTests/myResult/myResult-1000-1000-10
diff -U 1000 ./PleinDeTests/myResult/myResult-1000-1000-10 ./PleinDeTests/result/result-1000-1000-10 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo ""
echo "Test de differents characteres"
echo ""
echo "',' au lieu de '.' :"
./bsq ./PleinDeTests/map/char, > ./PleinDeTests/myResult/myResult-char,
diff -U 1 ./PleinDeTests/myResult/myResult-char, ./PleinDeTests/result/result-char, > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "'D' au lieu de 'o' :"
./bsq ./PleinDeTests/map/charD > ./PleinDeTests/myResult/myResult-charD
diff -U 1 ./PleinDeTests/myResult/myResult-charD ./PleinDeTests/result/result-charD > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "'X' au lieu de 'x' :"
./bsq ./PleinDeTests/map/charX > ./PleinDeTests/myResult/myResult-charX
diff -U 1 ./PleinDeTests/myResult/myResult-charX ./PleinDeTests/result/result-charX > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "',iJ' au lieu de '.ox' :"
./bsq ./PleinDeTests/map/char,iJ > ./PleinDeTests/myResult/myResult-char,iJ
diff -U 1 ./PleinDeTests/myResult/myResult-char,iJ ./PleinDeTests/result/result-char,iJ > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo "'123' au lieu de '.ox' :"
./bsq ./PleinDeTests/map/char123 > ./PleinDeTests/myResult/myResult-char123
diff -U 1 ./PleinDeTests/myResult/myResult-char123 ./PleinDeTests/result/result-char123 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo ""
echo "Test dans l'entré standard"
echo ""
echo "10-10-2 :"
./bsq < ./PleinDeTests/map/10-10-2 > ./PleinDeTests/myResult/myResult-standard-10-10-2
diff -U 10 ./PleinDeTests/myResult/myResult-standard-10-10-2 ./PleinDeTests/result/result-10-10-2 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
echo ""
echo "Test de cas d'erreurs"
echo "Doit afficher 'map error'"
echo ""
echo "10,ox a la place de 10.ox"
rm test.txt
./bsq < ./PleinDeTests/map/error-, > ./PleinDeTests/myResult/myResult-error-,
diff -U 10 ./PleinDeTests/myResult/myResult-error-, ./PleinDeTests/result/result-error-, > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
rm test.txt
echo "11.ox pour 10 lignes :"
./bsq < ./PleinDeTests/map/error-11 > ./PleinDeTests/myResult/myResult-error-11
diff -U 10 ./PleinDeTests/myResult/myResult-error-11 ./PleinDeTests/result/result-error-11 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
rm test.txt
echo "9.ox pour 10 lignes :"
./bsq < ./PleinDeTests/map/error-9 > ./PleinDeTests/myResult/myResult-error-9
diff -U 10 ./PleinDeTests/myResult/myResult-error-9 ./PleinDeTests/result/result-error-9 > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
rm test.txt
echo "10.ix au lieu de 10.ox :"
./bsq < ./PleinDeTests/map/error-i > ./PleinDeTests/myResult/myResult-error-i
diff -U 10 ./PleinDeTests/myResult/myResult-error-i ./PleinDeTests/result/result-error-i > test.txt
if [ -s ./test.txt ]; then
	echo "KO"
else
	echo "OK"
	fi
rm test.txt

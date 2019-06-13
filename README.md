# DIGITAL_SIGNATURES_OPENSSL_BENCHMARKS

This repository contains the benchmarks of the OpenSSL's Standardized EVP Digital Signatures (RSA, DSA, ECDSA, EdDSA)

This project is finished, the main purpose was to measure the "signature" and "verification" in clock cycles of the EVP (Envelope) versions of the implementations of digital signatures in the OpenSSL library, here you can download the modified versions of the schemes and test it yourself.

OpenSSL MAN pages recomends always use EVP libraries unless you develop some low level implementation in order to make them more efficient.

I am the owner of the implementation of benchmarks of the OpenSSL EVP digital signature schemes, all the parts in the sourcecode including the function "rdtsc" was developed and tested by me, they not include validation errors in order to make them more efficient, and for the above I do not recommend to use this codes in real life applications, only for test benchmarks, here in my root repository you will find another repository named "DIGITAL_SIGNATURES_OPENSSL_IMPLEMENTATIONS", in this repository you will find versions with error validations in order to use in real life developments, next you will find the instructions to execute them:

1. Download this repository and extract the content, in the main folder create a folder named RESULTS and another folder named BIN.

2. The version of OpenSSL used is 1.1.1b from Feb 26, 2019, I recommend to install this specific version of the library but if you cannot install it, the codes will work with almost other versions from version 1 and onwards.

3. In the main of this repository you will find 4 shell scripts to automate the operations; COMPILE.sh performs a gcc command in every implementation in order to compile the codes and creating the binary executables in the BIN folder, RUN.sh performs the benchmarks of every implemtation and writes the results in the RESULTS folder, CYCLES1K.sh modify the number of executing cycles of every implementation from 10k to 1k, since some schemes take so much time to run it, if you leave this number up high the complete process could take several hours to finish, that is why I recomend to down the number of cycles to 1k, this reduce the number of the process to a couple of hours only, finally the MICRO.sh modify in every source file the speed of the processor of the computer that will perform the test process, this is in the order of gigahertz, you will have to modify the code and write down the correct speed of your processor, when I ran the tests my computer was 1895000000 hz of raw speed, the test must be performed with an Intel(R) processor of almost every architecture, it has to have the TurboBoost(TM) technology disabled.

This software is distributed on an "AS IS" basis WITHOUT WARRANTY OF ANY KIND.

The original OpenSSL library belongs to the RESPECTIVE OWNERS.

If you have any questions, recomendations or corrections regarding this repository feel free to contact me to: jose.rodriguez@cimat.mx

The machine where I performed the original test has the following characteristics:

- Intel(R) Core(TM) i5-4300U CPU @ 1.90GHz, 1895Mhz
- 4GB of RAM DDR3, 3824MiB
- SSD 128GB Sata3

Next I include a table with the results of measuring the digital signature algorithms; it includes the RSA PKCS#1v1.5 and PKCS#1v2.2, DSA, ECDSA NIST Curves and EdDSA, all signatures were tested 10000 cycles; the results are in the clasifications mentions above sorted by the fastest signature.

|	**Size Key Bits**	|	**Signature Name**	|	**Signature Clock Cycles**	|	**Signature Time Seconds**	|	**Verification Clock Cycles**	|	**Verification Time Seconds**	|
|	---	|	---	|	---	|	---	|	---	|	---	|
|	256	|	ECDSA_prime256v1	|	116304	|	0.000029	|	353872	|	0.000088	|
|	512	|	RSA1.5_512	|	216195	|	0.000054	|	21055	|	0.000005	|
|	512	|	RSA2.2_512	|	220955	|	0.000055	|	25125	|	0.000006	|
|	512	|	DSA_512	|	237705	|	0.000059	|	144544	|	0.000036	|
|	1024	|	DSA_1024	|	486954	|	0.000122	|	356984	|	0.000089	|
|	1024	|	RSA2.2_1024	|	577370	|	0.000144	|	48790	|	0.000012	|
|	1024	|	RSA1.5_1024	|	583745	|	0.000146	|	45455	|	0.000011	|
|	192	|	ECDSA_prime192v1	|	961336	|	0.000240	|	876500	|	0.000219	|
|	163	|	ECDSA_sec163k1	|	1089790	|	0.000272	|	2174745	|	0.000544	|
|	163	|	ECDSA_sec163r2	|	1243345	|	0.000311	|	2477345	|	0.000619	|
|	2048	|	DSA_2048	|	1278986	|	0.000320	|	1165440	|	0.000291	|
|	233	|	ECDSA_sec233r1	|	1499635	|	0.000375	|	2930005	|	0.000733	|
|	233	|	ECDSA_sec233k1	|	1557045	|	0.000389	|	3058320	|	0.000765	|
|	283	|	ECDSA_sec283k1	|	2756005	|	0.000689	|	5375475	|	0.001344	|
|	283	|	ECDSA_sec283r1	|	2783855	|	0.000696	|	5593895	|	0.001398	|
|	224	|	ECDSA_secp224r1	|	2800692	|	0.000700	|	2360116	|	0.000590	|
|	2048	|	RSA2.2_2048	|	3033910	|	0.000758	|	171410	|	0.000043	|
|	2048	|	RSA1.5_2048	|	3133288	|	0.000783	|	149508	|	0.000037	|
|	384	|	ECDSA_secp384r1	|	4216632	|	0.001054	|	3275324	|	0.000819	|
|	409	|	ECDSA_sec409k1	|	4392610	|	0.001098	|	8738375	|	0.002185	|
|	409	|	ECDSA_sec409r1	|	4678180	|	0.00117	|	9087685	|	0.002272	|
|	521	|	ECDSA_secp521r1	|	10914350	|	0.002729	|	7309250	|	0.001827	|
|	571	|	ECDSA_sec571k1	|	11419236	|	0.002855	|	22024986	|	0.005506	|
|	571	|	ECDSA_sec571r1	|	11505815	|	0.002876	|	21956915	|	0.005489	|
|	3072	|	RSA1.5_3072	|	13339755	|	0.003335	|	278995	|	0.000070	|
|	3072	|	RSA2.2_3072	|	13856765	|	0.003464	|	291845	|	0.000073	|
|	4096	|	RSA1.5_4096	|	30902285	|	0.007726	|	474770	|	0.000119	|
|	4096	|	RSA2.2_4096	|	30982280	|	0.007746	|	497820	|	0.000124	|
|	7680	|	RSA1.5_7680	|	268500823	|	0.067125	|	1790554	|	0.000448	|
|	7680	|	RSA2.2_7680	|	288491795	|	0.072123	|	1920852	|	0.00048	|
|	15360	|	RSA2.2_15360	|	1498892245	|	0.374723	|	6321415	|	0.00158	|
|	15360	|	RSA1.5_15360	|	1548275170	|	0.387069	|	6247540	|	0.001562	|



















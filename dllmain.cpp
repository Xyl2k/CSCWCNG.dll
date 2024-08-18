/*
Based on Archi73ct work, edit by Xyl2k
Fixed acknowledgement buffer, ordinals and added more dummies apis based on some samples.

Tested successfully on these samples:
HelloWorld f6609bb3c3197ace26ebdeb372ba657ac84b05a3e9e265b5211e1ea42da70dbe
Winpot     3f5ff48aa4dc2c1af3deeb33a9cc576616dad37156ae9182831b1b2a5ae4ae20
Winpotv3   b57bc410683aba4c211e407320e6b7746ce25e06d81ddf480711228efd921a6c
Winpotv3   acc9be34ac6effb6a87cd5110f68e7c59a982f44fa53619a07e5c67da1b99a53
Cutlet     fe1634318e27e3af856506d49a54d1d12e1cf650cbc31eeb0c805949edc8fc85
ATMSpitter 8770f760af320d30681a4eb4ded331eab2481f54c657aac607df8babe8c11a6b

Still need some tweaking for this ATMSpitter sample
f27e27244233f2bb5b02412d4b05315625928adaa340708e91d61ad3bce54bf6
*/

#include <stdio.h>
#include <windows.h>

#define DllExport   __declspec( dllexport )

typedef struct test {
	int a;
	int b;
	int c;
	int d;
	int e;
	char* string;
} _unk_struct;

extern "C" DllExport BOOL _cdecl CscCngClose() { // Close the CNG DLL
	Sleep(10);
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngDispense(_unk_struct * hello) { // Dispense banknotes
	Sleep(1000);
	sprintf_s(hello->string, 12, "1,01,000,O;");
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngLock() { // Lock the device for exclusive access
	return 0;
	Sleep(20);
}

extern "C" DllExport BOOL _cdecl CscCngOpen() { // Open the CNG DLL
	Sleep(30);
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngReset() { // Reset the device
	Sleep(40);
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngStatusRead(_unk_struct * hello) { // Get device or cassette status
	/*
	Breakdown of CscCngStatusRead acknowledgement buffer:
	LEN=0511      -> Total length (incl. length specification)
	RSTA=R        -> Status of the reject/retract cassette (R: cassette ready, M: cassette missing, N: cassette inserted new)
	RACT=0131     -> Number of rejected banknotes
	RRET=00       -> Number of retracts
	nSTA=R        -> Status of cash-out cassette n (n = 1...6) - (R: cassette ready, E: cassette physically empty, M: cassette missing, N: new cassette, D: cassette is defective, P: parameters are unknown in measuring station, D: cassette is defective, V: printing cassette (receipt available))
	nNUM=0059021  -> Cassette ID
	nCUR=EUR      -> Currency code (ISO 4217)
	nREL=0000     -> Release date (YYMM)
	nVAL=00001000 -> Value of banknote
	nLEN=000      -> Width of the banknote
	nTOL=00       -> Width tolerance of the banknote
	nACT=1024,    -> Current number of banknotes
	nNDV=1097,    -> Number of banknotes in device
	nLOW=0000,    -> Minimum filling level
	nL_D=00       -> Last dispensing: no. of notes
	nREJ=000      -> Last dispensing: no. of rejected notes
	*/
	sprintf_s(hello->string, 512, "LEN=0511,RSTA=R,RACT=0131,RRET=00,1STA=R,1NUM=0059021,1CUR=EUR,1REL=0000,1VAL=00001000,1LEN=000,1TOL=00,1ACT=1024,1NDV=1097,1LOW=0000,1L_D=00,1REJ=000,2STA=M,2NUM=0059012,2CUR=EUR,2REL=0000,2VAL=00000500,2LEN=000,2TOL=00,2ACT=1048,2NDV=1049,2LOW=0000,2L_D=00,2REJ=000,3STA=R,3NUM=0059013,3CUR=EUR,3REL=0000,3VAL=00000200,3LEN=000,3TOL=00,3ACT=1485,3NDV=1528,3LOW=0000,3L_D=00,3REJ=000,4STA=R,4NUM=0059014,4CUR=XYL,4REL=0000,4VAL=00000500,4LEN=000,4TOL=00,4ACT=1371,4NDV=1386,4LOW=0000,4L_D=00,4REJ=000,SRACT=00;");
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngTransport() {  // Transport or offer banknotes
	Sleep(500);
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngUnlock() {  // Unlock the device for exclusive access
	Sleep(50);
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngCasRefInit() {  // Compute the reference value for a cassette
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngConfigure() {  // Configure different items in the firmware
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngControl() { // Inquire capabilities of the device handler
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngEco() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngEncryption() { // Handle the en-/decryption of the CNG V.24 line
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngGetRelease() { // Read version information
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngGetTrace() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngInit() { // Initialize the CNG DLL
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngOptimization() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngPowerOff() { // Switch off or reboot the ProCash Compact
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngPsm() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngSelStatus() { // Get SEL status from the ProCash Compact
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngSelftest() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngService() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngShutter() { // Move or test the shutter
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngStatistics() {
	return 0;
}

extern "C" DllExport BOOL _cdecl CscCngBim() {
	return 0;
}

#include "chess.h"

#include <windows.h>
#include <time.h>

#include <stdio.h>
#include <string.h>
#include <intrin.h>


const char* szFeatures[] =
{
	"x87 FPU On Chip",
	"Virtual-8086 Mode Enhancement",
	"Debugging Extensions",
	"Page Size Extensions",
	"Time Stamp Counter",
	"RDMSR and WRMSR Support",
	"Physical Address Extensions",
	"Machine Check Exception",
	"CMPXCHG8B Instruction",
	"APIC On Chip",
	"Unknown1",
	"SYSENTER and SYSEXIT",
	"Memory Type Range Registers",
	"PTE Global Bit",
	"Machine Check Architecture",
	"Conditional Move/Compare Instruction",
	"Page Attribute Table",
	"36-bit Page Size Extension",
	"Processor Serial Number",
	"CFLUSH Extension",
	"Unknown2",
	"Debug Store",
	"Thermal Monitor and Clock Ctrl",
	"MMX Technology",
	"FXSAVE/FXRSTOR",
	"SSE Extensions",
	"SSE2 Extensions",
	"Self Snoop",
	"Multithreading Technology",
	"Thermal Monitor",
	"Unknown4",
	"Pending Break Enable"
};


void GetCpuInfo(CPUINFO &sCPU){

	__cpuid(sCPU.CPUInfo, 0);
	sCPU.nIds = sCPU.CPUInfo[0];
	memset(sCPU.CPUString, 0, sizeof(sCPU.CPUString));
	*((int*)sCPU.CPUString) = sCPU.CPUInfo[1];
	*((int*)(sCPU.CPUString + 4)) = sCPU.CPUInfo[3];
	*((int*)(sCPU.CPUString + 8)) = sCPU.CPUInfo[2];


	// Get the information associated with each valid Id
	for (uint32 i = 0; i <= sCPU.nIds; ++i)
	{
		__cpuid(sCPU.CPUInfo, i);		//printf_s("\nFor InfoType %d\n", i);
		//printf_s("CPUInfo[0] = 0x%x\n", CPUInfo[0]);
		//printf_s("CPUInfo[1] = 0x%x\n", CPUInfo[1]);
		//printf_s("CPUInfo[2] = 0x%x\n", CPUInfo[2]);
		//printf_s("CPUInfo[3] = 0x%x\n", CPUInfo[3]);


		// Interpret CPU feature information.
		if (i == 1)
		{
			sCPU.nSteppingID = sCPU.CPUInfo[0] & 0xf;
			sCPU.nModel = (sCPU.CPUInfo[0] >> 4) & 0xf;
			sCPU.nFamily = (sCPU.CPUInfo[0] >> 8) & 0xf;
			sCPU.nProcessorType = (sCPU.CPUInfo[0] >> 12) & 0x3;
			sCPU.nExtendedmodel = (sCPU.CPUInfo[0] >> 16) & 0xf;
			sCPU.nExtendedfamily = (sCPU.CPUInfo[0] >> 20) & 0xff;
			sCPU.nBrandIndex = sCPU.CPUInfo[1] & 0xff;
			sCPU.nCLFLUSHcachelinesize = ((sCPU.CPUInfo[1] >> 8) & 0xff) * 8;
			sCPU.nLogicalProcessors = ((sCPU.CPUInfo[1] >> 16) & 0xff);
			sCPU.nAPICPhysicalID = (sCPU.CPUInfo[1] >> 24) & 0xff;
			sCPU.bSSE3Instructions = (sCPU.CPUInfo[2] & 0x1) || false;
			sCPU.bMONITOR_MWAIT = (sCPU.CPUInfo[2] & 0x8) || false;
			sCPU.bCPLQualifiedDebugStore = (sCPU.CPUInfo[2] & 0x10) || false;
			sCPU.bVirtualMachineExtensions = (sCPU.CPUInfo[2] & 0x20) || false;
			sCPU.bEnhancedIntelSpeedStepTechnology = (sCPU.CPUInfo[2] & 0x80) || false;
			sCPU.bThermalMonitor2 = (sCPU.CPUInfo[2] & 0x100) || false;
			sCPU.bSupplementalSSE3 = (sCPU.CPUInfo[2] & 0x200) || false;
			sCPU.bL1ContextID = (sCPU.CPUInfo[2] & 0x300) || false;
			sCPU.bCMPXCHG16B = (sCPU.CPUInfo[2] & 0x2000) || false;
			sCPU.bxTPRUpdateControl = (sCPU.CPUInfo[2] & 0x4000) || false;
			sCPU.bPerfDebugCapabilityMSR = (sCPU.CPUInfo[2] & 0x8000) || false;
			sCPU.bSSE41Extensions = (sCPU.CPUInfo[2] & 0x80000) || false;
			sCPU.bSSE42Extensions = (sCPU.CPUInfo[2] & 0x100000) || false;
			sCPU.bPOPCNT = (sCPU.CPUInfo[2] & 0x800000) || false;
			sCPU.nFeatureInfo = sCPU.CPUInfo[3];
			sCPU.bMultithreading = (sCPU.nFeatureInfo & (1 << 28)) || false;
		}
	}

	// Calling __cpuid with 0x80000000 as the InfoType argument
	// gets the number of valid extended IDs.
	__cpuid(sCPU.CPUInfo, 0x80000000);
	sCPU.nExIds = sCPU.CPUInfo[0];
	memset(sCPU.CPUBrandString, 0, sizeof(sCPU.CPUBrandString));

	// Get the information associated with each extended ID.
	for (uint32 i = 0x80000000; i <= sCPU.nExIds; ++i)
	{
		__cpuid(sCPU.CPUInfo, i);
		//printf_s("\nFor InfoType %x\n", i);
		//printf_s("CPUInfo[0] = 0x%x\n", CPUInfo[0]);
		//printf_s("CPUInfo[1] = 0x%x\n", CPUInfo[1]);
		//printf_s("CPUInfo[2] = 0x%x\n", CPUInfo[2]);
		//printf_s("CPUInfo[3] = 0x%x\n", CPUInfo[3]);

		if (i == 0x80000001)
		{
			sCPU.bLAHF_SAHFAvailable = (sCPU.CPUInfo[2] & 0x1) || false;
			sCPU.bCmpLegacy = (sCPU.CPUInfo[2] & 0x2) || false;
			sCPU.bSVM = (sCPU.CPUInfo[2] & 0x4) || false;
			sCPU.bExtApicSpace = (sCPU.CPUInfo[2] & 0x8) || false;
			sCPU.bAltMovCr8 = (sCPU.CPUInfo[2] & 0x10) || false;
			sCPU.bLZCNT = (sCPU.CPUInfo[2] & 0x20) || false;
			sCPU.bSSE4A = (sCPU.CPUInfo[2] & 0x40) || false;
			sCPU.bMisalignedSSE = (sCPU.CPUInfo[2] & 0x80) || false;
			sCPU.bPREFETCH = (sCPU.CPUInfo[2] & 0x100) || false;
			sCPU.bSKINITandDEV = (sCPU.CPUInfo[2] & 0x1000) || false;
			sCPU.bSYSCALL_SYSRETAvailable = (sCPU.CPUInfo[3] & 0x800) || false;
			sCPU.bExecuteDisableBitAvailable = (sCPU.CPUInfo[3] & 0x10000) || false;
			sCPU.bMMXExtensions = (sCPU.CPUInfo[3] & 0x40000) || false;
			sCPU.bFFXSR = (sCPU.CPUInfo[3] & 0x200000) || false;
			sCPU.b1GBSupport = (sCPU.CPUInfo[3] & 0x400000) || false;
			sCPU.bRDTSCP = (sCPU.CPUInfo[3] & 0x8000000) || false;
			sCPU.b64Available = (sCPU.CPUInfo[3] & 0x20000000) || false;
			sCPU.b3DNowExt = (sCPU.CPUInfo[3] & 0x40000000) || false;
			sCPU.b3DNow = (sCPU.CPUInfo[3] & 0x80000000) || false;
		}

		// Interpret CPU brand string and cache information.
		if (i == 0x80000002)
			memcpy(sCPU.CPUBrandString, sCPU.CPUInfo, sizeof(sCPU.CPUInfo));
		else if (i == 0x80000003)
			memcpy(sCPU.CPUBrandString + 16, sCPU.CPUInfo, sizeof(sCPU.CPUInfo));
		else if (i == 0x80000004)
			memcpy(sCPU.CPUBrandString + 32, sCPU.CPUInfo, sizeof(sCPU.CPUInfo));
		else if (i == 0x80000006)
		{
			sCPU.nCacheLineSize = sCPU.CPUInfo[2] & 0xff;
			sCPU.nL2Associativity = (sCPU.CPUInfo[2] >> 12) & 0xf;
			sCPU.nCacheSizeK = (sCPU.CPUInfo[2] >> 16) & 0xffff;
		}
		else if (i == 0x80000008)
		{
			sCPU.nPhysicalAddress = sCPU.CPUInfo[0] & 0xff;
			sCPU.nVirtualAddress = (sCPU.CPUInfo[0] >> 8) & 0xff;
		}
		else if (i == 0x8000000A)
		{
			sCPU.bNestedPaging = (sCPU.CPUInfo[3] & 0x1) || false;
			sCPU.bLBRVisualization = (sCPU.CPUInfo[3] & 0x2) || false;
		}
		else if (i == 0x8000001A)
		{
			sCPU.bFP128 = (sCPU.CPUInfo[0] & 0x1) || false;
			sCPU.bMOVOptimization = (sCPU.CPUInfo[0] & 0x2) || false;
		}
	}

	// Display all the information in user-friendly format.

	//printf_s("\n\nCPU String: %s\n", CPUString);

	if (sCPU.nIds >= 1)
	{
		//if (sCPU.nSteppingID)
		//	printf_s("Stepping ID = %d\n", nSteppingID);
		//if (nModel)
		//	printf_s("Model = %d\n", nModel);
		//if (nFamily)
		//	printf_s("Family = %d\n", nFamily);
		//if (nProcessorType)
		//	printf_s("Processor Type = %d\n", nProcessorType);
		//if (nExtendedmodel)
		//	printf_s("Extended model = %d\n", nExtendedmodel);
		//if (nExtendedfamily)
		//	printf_s("Extended family = %d\n", nExtendedfamily);
		//if (nBrandIndex)
		//	printf_s("Brand Index = %d\n", nBrandIndex);
		//if (nCLFLUSHcachelinesize)
		//	printf_s("CLFLUSH cache line size = %d\n",
		//	nCLFLUSHcachelinesize);
		//if (bMultithreading && (nLogicalProcessors > 0))
		//	printf_s("Logical Processor Count = %d\n", nLogicalProcessors);
		//if (nAPICPhysicalID)
		//	printf_s("APIC Physical ID = %d\n", nAPICPhysicalID);

		//if (nFeatureInfo || bSSE3Instructions ||
		//	bMONITOR_MWAIT || bCPLQualifiedDebugStore ||
		//	bVirtualMachineExtensions || bEnhancedIntelSpeedStepTechnology ||
		//	bThermalMonitor2 || bSupplementalSSE3 || bL1ContextID ||
		//	bCMPXCHG16B || bxTPRUpdateControl || bPerfDebugCapabilityMSR ||
		//	bSSE41Extensions || bSSE42Extensions || bPOPCNT ||
		//	bLAHF_SAHFAvailable || bCmpLegacy || bSVM ||
		//	bExtApicSpace || bAltMovCr8 ||
		//	bLZCNT || bSSE4A || bMisalignedSSE ||
		//	bPREFETCH || bSKINITandDEV || bSYSCALL_SYSRETAvailable ||
		//	bExecuteDisableBitAvailable || bMMXExtensions || bFFXSR || b1GBSupport ||
		//	bRDTSCP || b64Available || b3DNowExt || b3DNow || bNestedPaging ||
		//	bLBRVisualization || bFP128 || bMOVOptimization)
		//{
		//	printf_s("\nThe following features are supported:\n");

		//	if (bSSE3Instructions)
		//		printf_s("\tSSE3\n");
		//	if (bMONITOR_MWAIT)
		//		printf_s("\tMONITOR/MWAIT\n");
		//	if (bCPLQualifiedDebugStore)
		//		printf_s("\tCPL Qualified Debug Store\n");
		//	if (bVirtualMachineExtensions)
		//		printf_s("\tVirtual Machine Extensions\n");
		//	if (bEnhancedIntelSpeedStepTechnology)
		//		printf_s("\tEnhanced Intel SpeedStep Technology\n");
		//	if (bThermalMonitor2)
		//		printf_s("\tThermal Monitor 2\n");
		//	if (bSupplementalSSE3)
		//		printf_s("\tSupplemental Streaming SIMD Extensions 3\n");
		//	if (bL1ContextID)
		//		printf_s("\tL1 Context ID\n");
		//	if (bCMPXCHG16B)
		//		printf_s("\tCMPXCHG16B Instruction\n");
		//	if (bxTPRUpdateControl)
		//		printf_s("\txTPR Update Control\n");
		//	if (bPerfDebugCapabilityMSR)
		//		printf_s("\tPerf\\Debug Capability MSR\n");
		//	if (bSSE41Extensions)
		//		printf_s("\tSSE4.1 Extensions\n");
		//	if (bSSE42Extensions)
		//		printf_s("\tSSE4.2 Extensions\n");
		//	if (bPOPCNT)
		//		printf_s("\tPPOPCNT Instruction\n");

	//		i = 0;
	//		nIds = 1;
	//		while (i < (sizeof(szFeatures) / sizeof(const char*)))
	//		{
	//			if (nFeatureInfo & nIds)
	//			{
	//				printf_s("\t");
	//				printf_s(szFeatures[i]);
	//				printf_s("\n");
	//			}

	//			nIds <<= 1;
	//			++i;
	//		}
	//		if (bLAHF_SAHFAvailable)
	//			printf_s("\tLAHF/SAHF in 64-bit mode\n");
	//		if (bCmpLegacy)
	//			printf_s("\tCore multi-processing legacy mode\n");
	//		if (bSVM)
	//			printf_s("\tSecure Virtual Machine\n");
	//		if (bExtApicSpace)
	//			printf_s("\tExtended APIC Register Space\n");
	//		if (bAltMovCr8)
	//			printf_s("\tAltMovCr8\n");
	//		if (bLZCNT)
	//			printf_s("\tLZCNT instruction\n");
	//		if (bSSE4A)
	//			printf_s("\tSSE4A (EXTRQ, INSERTQ, MOVNTSD, MOVNTSS)\n");
	//		if (bMisalignedSSE)
	//			printf_s("\tMisaligned SSE mode\n");
	//		if (bPREFETCH)
	//			printf_s("\tPREFETCH and PREFETCHW Instructions\n");
	//		if (bSKINITandDEV)
	//			printf_s("\tSKINIT and DEV support\n");
	//		if (bSYSCALL_SYSRETAvailable)
	//			printf_s("\tSYSCALL/SYSRET in 64-bit mode\n");
	//		if (bExecuteDisableBitAvailable)
	//			printf_s("\tExecute Disable Bit\n");
	//		if (bMMXExtensions)
	//			printf_s("\tExtensions to MMX Instructions\n");
	//		if (bFFXSR)
	//			printf_s("\tFFXSR\n");
	//		if (b1GBSupport)
	//			printf_s("\t1GB page support\n");
	//		if (bRDTSCP)
	//			printf_s("\tRDTSCP instruction\n");
	//		if (b64Available)
	//			printf_s("\t64 bit Technology\n");
	//		if (b3DNowExt)
	//			printf_s("\t3Dnow Ext\n");
	//		if (b3DNow)
	//			printf_s("\t3Dnow! instructions\n");
	//		if (bNestedPaging)
	//			printf_s("\tNested Paging\n");
	//		if (bLBRVisualization)
	//			printf_s("\tLBR Visualization\n");
	//		if (bFP128)
	//			printf_s("\tFP128 optimization\n");
	//		if (bMOVOptimization)
	//			printf_s("\tMOVU Optimization\n");
	//	}
	}

	//if (nExIds >= 0x80000004)
	//	printf_s("\nCPU Brand String: %s\n", CPUBrandString);

	//if (nExIds >= 0x80000006)
	//{
	//	printf_s("Cache Line Size = %d\n", nCacheLineSize);
	//	printf_s("L2 Associativity = %d\n", nL2Associativity);
	//	printf_s("Cache Size = %dK\n", nCacheSizeK);
	//}


	for (uint32 i = 0;; i++)
	{
		__cpuidex(sCPU.CPUInfo, 0x4, i);
		if (!(sCPU.CPUInfo[0] & 0xf0)) break;

		if (i == 0)
		{
			sCPU.nCores = sCPU.CPUInfo[0] >> 26;
			//printf_s("\n\nNumber of Cores = %d\n", nCores + 1);
		}

		sCPU.nCacheType = (sCPU.CPUInfo[0] & 0x1f);
		sCPU.nCacheLevel = (sCPU.CPUInfo[0] & 0xe0) >> 5;
		sCPU.bSelfInit = (sCPU.CPUInfo[0] & 0x100) >> 8;
		sCPU.bFullyAssociative = (sCPU.CPUInfo[0] & 0x200) >> 9;
		sCPU.nMaxThread = (sCPU.CPUInfo[0] & 0x03ffc000) >> 14;
		sCPU.nSysLineSize = (sCPU.CPUInfo[1] & 0x0fff);
		sCPU.nPhysicalLinePartitions = (sCPU.CPUInfo[1] & 0x03ff000) >> 12;
		sCPU.nWaysAssociativity = (sCPU.CPUInfo[1]) >> 22;
		sCPU.nNumberSets = sCPU.CPUInfo[2];

		//printf_s("\n");

		//printf_s("ECX Index %d\n", i);
		//switch (sCPU.nCacheType)
		//{
		//case 0:
		//	printf_s("   Type: Null\n");
		//	break;
		//case 1:
		//	printf_s("   Type: Data Cache\n");
		//	break;
		//case 2:
		//	printf_s("   Type: Instruction Cache\n");
		//	break;
		//case 3:
		//	printf_s("   Type: Unified Cache\n");
		//	break;
		//default:
		//	printf_s("   Type: Unknown\n");
		//}

		//printf_s("   Level = %d\n", nCacheLevel + 1);
		//if (bSelfInit)
		//{
		//	printf_s("   Self Initializing\n");
		//}
		//else
		//{
		//	printf_s("   Not Self Initializing\n");
		//}
		//if (bFullyAssociative)
		//{
		//	printf_s("   Is Fully Associatve\n");
		//}
		//else
		//{
		//	printf_s("   Is Not Fully Associatve\n");
		//}
		//printf_s("   Max Threads = %d\n",
		//	nMaxThread + 1);
		//printf_s("   System Line Size = %d\n",
		//	nSysLineSize + 1);
		//printf_s("   Physical Line Partions = %d\n",
		//	nPhysicalLinePartitions + 1);
		//printf_s("   Ways of Associativity = %d\n",
		//	nWaysAssociativity + 1);
		//printf_s("   Number of Sets = %d\n",
		//	nNumberSets + 1);
	}

}

#ifndef __FAKE_WINDDK_H__
#define __FAKE_WINDDK_H__
#pragma once

#include "winmisc.h"
//////////////////////////////////////////////////////////////////////////
enum EObjectAttributes
{
	OBJ_INHERIT = 0x2,
	OBJ_PERMANENT = 0x10,
	OBJ_EXCLUSIVE = 0x20,
	OBJ_CASE_INSENSITIVE = 0x40,
	OBJ_OPENIF = 0x80,
	OBJ_OPENLINK = 0x100,
	OBJ_KERNEL_HANDLE = 0x200,
	OBJ_FORCE_ACCESS_CHECK = 0x400,
	OBJ_IGNORE_IMPERSONATED_DEVICEMAP = 0x800,
	OBJ_DONT_REPARSE = 0x1000,
	OBJ_VALID_ATTRIBUTES = 0x1FF2,
};

typedef struct _CLIENT_ID
{
	void *UniqueProcess;
	void *UniqueThread;
}CLIENT_ID, *PCLIENT_ID;

typedef LONG KPRIORITY;
typedef ULONG_PTR KAFFINITY;
typedef LARGE_INTEGER PHYSICAL_ADDRESS, *PPHYSICAL_ADDRESS;

typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation, // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters, // q: IO_COUNTERS
	ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
	ProcessTimes, // q: KERNEL_USER_TIMES
	ProcessBasePriority, // s: KPRIORITY
	ProcessRaisePriority, // s: ULONG
	ProcessDebugPort, // q: HANDLE
	ProcessExceptionPort, // s: HANDLE
	ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation, // qs: PROCESS_LDT_INFORMATION // 10
	ProcessLdtSize, // s: PROCESS_LDT_SIZE
	ProcessDefaultHardErrorMode, // qs: ULONG
	ProcessIoPortHandlers, // (kernel-mode only)
	ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
	ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information,	//HANDLE Wx86Info;
	ProcessHandleCount, // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
	ProcessAffinityMask, // s: KAFFINITY
	ProcessPriorityBoost, // qs: ULONG
	ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information, // q: ULONG_PTR
	ProcessImageFileName, // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled, // q: ULONG
	ProcessBreakOnTermination, // qs: ULONG
	ProcessDebugObjectHandle, // q: HANDLE // 30
	ProcessDebugFlags, // qs: ULONG
	ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
	ProcessIoPriority, // qs: IO_PRIORITY_HINT
	ProcessExecuteFlags, // qs: ULONG
	ProcessResourceManagement,	//ProcessTlsInformation
	ProcessCookie, // q: ULONG
	ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
	ProcessPagePriority, // q: ULONG
	ProcessInstrumentationCallback, // 40
	ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
	ProcessImageFileNameWin32, // q: UNICODE_STRING
	ProcessImageFileMapping, // q: HANDLE (input)
	ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation, // q: USHORT[]
	ProcessTokenVirtualizationEnabled, // s: ULONG
	ProcessConsoleHostProcess, // q: ULONG_PTR
	ProcessWindowInformation, // q: PROCESS_WINDOW_INFORMATION // 50
	ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,
	ProcessHandleCheckingMode,
	ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
	ProcessHandleTable, // since WINBLUE
	ProcessCheckStackExtentsMode,
	ProcessCommandLineInformation, // q: UNICODE_STRING // 60
	ProcessProtectionInformation, // q: PS_PROTECTION
	ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
	ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
	ProcessTelemetryIdInformation, // PROCESS_TELEMETRY_ID_INFORMATION
	ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
	ProcessDefaultCpuSetsInformation,
	ProcessAllowedCpuSetsInformation,
	ProcessReserved1Information,
	ProcessReserved2Information,
	ProcessSubsystemProcess, // 70
	ProcessJobMemoryInformation, // PROCESS_JOB_MEMORY_INFO
	ProcessInPrivate, // since THRESHOLD2
	ProcessRaiseUMExceptionOnInvalidHandleClose,
	MaxProcessInfoClass
}PROCESSINFOCLASS;


typedef struct _PROCESS_BASIC_INFORMATION
{
	LONG		ExitStatus;
	///	PX_PEB		PebBaseAddress;
	PVOID		PebBaseAddress;
	KAFFINITY	AffinityMask;
	KPRIORITY	BasePriority;
	PVOID		UniqueProcessId;
	PVOID		InheritedFromUniqueProcessId;
}PROCESS_BASIC_INFORMATION, *PPROCESS_BASIC_INFORMATION, *LPPROCESS_BASIC_INFORMATION;

//////////////////////////////////////////////////////////////////////////
//http://mirrors.arcadecontrols.com/www.sysinternals.com/Information/AclEditors.html
typedef struct _ACLHELPCONTROL
{
	PCWSTR	HelpFile;
	DWORD	MainDialogTopic;
	DWORD	ACLEditDialogTopic;
	DWORD	Reserved1;
	DWORD	AddEntryDialogTopic;
	DWORD	Reserved2;
	DWORD	Reserved3;
	DWORD	AccountDialogTopic;
}ACLHELPCONTROL, *PACLHELPCONTROL;

typedef struct _ACLDLGCONTROL
{
	DWORD	Version;
	PGENERIC_MAPPING GenericAccessMap;
	PGENERIC_MAPPING SpecificAccessMap;
	PCWSTR			 DialogTitle;
	PACLHELPCONTROL  HelpInfo;
	PCWSTR			 SubReplaceTitle;
	DWORD			 Reserved;
	PCWSTR			 SubReplaceConfirmation;
	PCWSTR			 SpecialAccess;
}ACLDLGCONTROL, *PACLDLGCONTROL;

typedef struct _ACLEDITENTRY
{
	DWORD	Type;
	DWORD	AccessMask;
	DWORD	Reserved;
	PCWSTR	Name;
}ACLEDITENTRY, *PACLEDITENTRY;

typedef struct _ACLEDITCONTROL
{
	DWORD	NumberOfEntries;
	PACLEDITENTRY Entries;
}ACLEDITCONTROL, *PACLEDITCONTROL;



typedef struct _THREAD_BASIC_INFORMATION
{
	NTSTATUS ExitStatus;
	///PXTEB	TebBaseAddrss;
	PVOID	TebBaseAddress;
	CLIENT_ID ClientId;
	KAFFINITY AffinityMask;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
}THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION, *LPTHREAD_BASIC_INFORMATION;


typedef enum _THREADINFOCLASS
{
	ThreadBasicInformation, // q: THREAD_BASIC_INFORMATION
	ThreadTimes, // q: KERNEL_USER_TIMES
	ThreadPriority, // s: KPRIORITY
	ThreadBasePriority, // s: LONG
	ThreadAffinityMask, // s: KAFFINITY
	ThreadImpersonationToken, // s: HANDLE
	ThreadDescriptorTableEntry, // q: DESCRIPTOR_TABLE_ENTRY (or WOW64_DESCRIPTOR_TABLE_ENTRY)
	ThreadEnableAlignmentFaultFixup, // s: BOOLEAN
	ThreadEventPair,
	ThreadQuerySetWin32StartAddress, // q: PVOID
	ThreadZeroTlsCell, // 10
	ThreadPerformanceCount, // q: LARGE_INTEGER
	ThreadAmILastThread, // q: ULONG
	ThreadIdealProcessor, // s: ULONG
	ThreadPriorityBoost, // qs: ULONG
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending, // q: ULONG
	ThreadHideFromDebugger, // s: void
	ThreadBreakOnTermination, // qs: ULONG
	ThreadSwitchLegacyState,
	ThreadIsTerminated, // q: ULONG // 20
	ThreadLastSystemCall, // q: THREAD_LAST_SYSCALL_INFORMATION
	ThreadIoPriority, // qs: IO_PRIORITY_HINT
	ThreadCycleTime, // q: THREAD_CYCLE_TIME_INFORMATION
	ThreadPagePriority, // q: ULONG
	ThreadActualBasePriority,
	ThreadTebInformation, // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_SET_CONTEXT)
	ThreadCSwitchMon,
	ThreadCSwitchPmu,
	ThreadWow64Context, // q: WOW64_CONTEXT
	ThreadGroupInformation, // q: GROUP_AFFINITY // 30
	ThreadUmsInformation,
	ThreadCounterProfiling,
	ThreadIdealProcessorEx, // q: PROCESSOR_NUMBER
	ThreadCpuAccountingInformation, // since WIN8
	ThreadSuspendCount, // since WINBLUE
	ThreadHeterogeneousCpuPolicy, // q: KHETERO_CPU_POLICY // since THRESHOLD
	ThreadContainerId, // q: GUID
	ThreadNameInformation,
	ThreadSelectedCpuSets,
	ThreadSystemThreadInformation, // q: SYSTEM_THREAD_INFORMATION // 40
	ThreadActualGroupAffinity, // since THRESHOLD2
	MaxThreadInfoClass
} THREADINFOCLASS;

typedef enum _SYSTEM_INFORMATION_CLASS
{
	SystemBasicInformation, // q: SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation, // q: SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation, // q: SYSTEM_PERFORMANCE_INFORMATION
	SystemTimeOfDayInformation, // q: SYSTEM_TIMEOFDAY_INFORMATION
	SystemPathInformation, // not implemented
	SystemProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemCallCountInformation, // q: SYSTEM_CALL_COUNT_INFORMATION
	SystemDeviceInformation, // q: SYSTEM_DEVICE_INFORMATION
	SystemProcessorPerformanceInformation, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
	SystemFlagsInformation, // q: SYSTEM_FLAGS_INFORMATION
	SystemCallTimeInformation, // not implemented // 10
	SystemModuleInformation, // q: RTL_PROCESS_MODULES
	SystemLocksInformation,
	SystemStackTraceInformation,
	SystemPagedPoolInformation, // not implemented
	SystemNonPagedPoolInformation, // not implemented
	SystemHandleInformation, // q: SYSTEM_HANDLE_INFORMATION
	SystemObjectInformation, // q: SYSTEM_OBJECTTYPE_INFORMATION mixed with SYSTEM_OBJECT_INFORMATION
	SystemPageFileInformation, // q: SYSTEM_PAGEFILE_INFORMATION
	SystemVdmInstemulInformation, // q
	SystemVdmBopInformation, // not implemented // 20
	SystemFileCacheInformation, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemCache)
	SystemPoolTagInformation, // q: SYSTEM_POOLTAG_INFORMATION
	SystemInterruptInformation, // q: SYSTEM_INTERRUPT_INFORMATION
	SystemDpcBehaviorInformation, // q: SYSTEM_DPC_BEHAVIOR_INFORMATION; s: SYSTEM_DPC_BEHAVIOR_INFORMATION (requires SeLoadDriverPrivilege)
	SystemFullMemoryInformation, // not implemented
	SystemLoadGdiDriverInformation, // s (kernel-mode only)
	SystemUnloadGdiDriverInformation, // s (kernel-mode only)
	SystemTimeAdjustmentInformation, // q: SYSTEM_QUERY_TIME_ADJUST_INFORMATION; s: SYSTEM_SET_TIME_ADJUST_INFORMATION (requires SeSystemtimePrivilege)
	SystemSummaryMemoryInformation, // not implemented
	SystemMirrorMemoryInformation, // s (requires license value "Kernel-MemoryMirroringSupported") (requires SeShutdownPrivilege) // 30
	SystemPerformanceTraceInformation, // s
	SystemObsolete0, // not implemented
	SystemExceptionInformation, // q: SYSTEM_EXCEPTION_INFORMATION
	SystemCrashDumpStateInformation, // s (requires SeDebugPrivilege)
	SystemKernelDebuggerInformation, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION
	SystemContextSwitchInformation, // q: SYSTEM_CONTEXT_SWITCH_INFORMATION
	SystemRegistryQuotaInformation, // q: SYSTEM_REGISTRY_QUOTA_INFORMATION; s (requires SeIncreaseQuotaPrivilege)
	//https://www.cnblogs.com/fanzi2009/archive/2010/03/19/1689645.html	
	//http://www.360doc.com/content/16/0312/14/3242454_541576394.shtml
	SystemExtendServiceTableInformation, // s (requires SeLoadDriverPrivilege) // loads win32k only
	//SystemLoadAndCallImage				//_SYSTEM_LOAD_AND_CALL_IMAGE		
	SystemPrioritySeperation, // s (requires SeTcbPrivilege)
	SystemVerifierAddDriverInformation, // s (requires SeDebugPrivilege) // 40
	SystemVerifierRemoveDriverInformation, // s (requires SeDebugPrivilege)
	SystemProcessorIdleInformation, // q: SYSTEM_PROCESSOR_IDLE_INFORMATION
	SystemLegacyDriverInformation, // q: SYSTEM_LEGACY_DRIVER_INFORMATION

	SystemCurrentTimeZoneInformation, // q
	SystemLookasideInformation, // q: SYSTEM_LOOKASIDE_INFORMATION
	SystemTimeSlipNotification, // s (requires SeSystemtimePrivilege)
	SystemSessionCreate, // not implemented
	SystemSessionDetach, // not implemented
	SystemSessionInformation, // not implemented
	SystemRangeStartInformation, // q // 50
	SystemVerifierInformation, // q: SYSTEM_VERIFIER_INFORMATION; s (requires SeDebugPrivilege)

	SystemVerifierThunkExtend, // s (kernel-mode only)
	SystemSessionProcessInformation, // q: SYSTEM_SESSION_PROCESS_INFORMATION
	SystemLoadGdiDriverInSystemSpace, // s (kernel-mode only) (same as SystemLoadGdiDriverInformation)

	SystemNumaProcessorMap, // q
	SystemPrefetcherInformation, // q: PREFETCHER_INFORMATION; s: PREFETCHER_INFORMATION // PfSnQueryPrefetcherInformation
	SystemExtendedProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemRecommendedSharedDataAlignment, // q
	SystemComPlusPackage, // q; s
	SystemNumaAvailableMemory, // 60
	SystemProcessorPowerInformation, // q: SYSTEM_PROCESSOR_POWER_INFORMATION
	SystemEmulationBasicInformation, // q
	SystemEmulationProcessorInformation,
	SystemExtendedHandleInformation, // q: SYSTEM_HANDLE_INFORMATION_EX
	SystemLostDelayedWriteInformation, // q: ULONG
	SystemBigPoolInformation, // q: SYSTEM_BIGPOOL_INFORMATION
	SystemSessionPoolTagInformation, // q: SYSTEM_SESSION_POOLTAG_INFORMATION
	SystemSessionMappedViewInformation, // q: SYSTEM_SESSION_MAPPED_VIEW_INFORMATION
	SystemHotpatchInformation, // q; s
	SystemObjectSecurityMode, // q // 70

	SystemWatchdogTimerHandler, // s (kernel-mode only)
	SystemWatchdogTimerInformation, // q (kernel-mode only); s (kernel-mode only)

	SystemLogicalProcessorInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION
	SystemWow64SharedInformationObsolete, // not implemented
	SystemRegisterFirmwareTableInformationHandler, // s (kernel-mode only)
	SystemFirmwareTableInformation, // not implemented
	SystemModuleInformationEx, // q: RTL_PROCESS_MODULE_INFORMATION_EX
	SystemVerifierTriageInformation, // not implemented
	SystemSuperfetchInformation, // q: SUPERFETCH_INFORMATION; s: SUPERFETCH_INFORMATION // PfQuerySuperfetchInformation
	SystemMemoryListInformation, // q: SYSTEM_MEMORY_LIST_INFORMATION; s: SYSTEM_MEMORY_LIST_COMMAND (requires SeProfileSingleProcessPrivilege) // 80
	SystemFileCacheInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (same as SystemFileCacheInformation)
	SystemThreadPriorityClientIdInformation, // s: SYSTEM_THREAD_CID_PRIORITY_INFORMATION (requires SeIncreaseBasePriorityPrivilege)
	SystemProcessorIdleCycleTimeInformation, // q: SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION[]
	SystemVerifierCancellationInformation, // not implemented // name:wow64:whNT32QuerySystemVerifierCancellationInformation
	SystemProcessorPowerInformationEx, // not implemented
	SystemRefTraceInformation, // q; s // ObQueryRefTraceInformation
	SystemSpecialPoolInformation, // q; s (requires SeDebugPrivilege) // MmSpecialPoolTag, then MmSpecialPoolCatchOverruns != 0
	SystemProcessIdInformation, // q: SYSTEM_PROCESS_ID_INFORMATION
	SystemErrorPortInformation, // s (requires SeTcbPrivilege)
	SystemBootEnvironmentInformation, // q: SYSTEM_BOOT_ENVIRONMENT_INFORMATION // 90
	SystemHypervisorInformation, // q; s (kernel-mode only)
	SystemVerifierInformationEx, // q; s
	SystemTimeZoneInformation, // s (requires SeTimeZonePrivilege)
	SystemImageFileExecutionOptionsInformation, // s: SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION (requires SeTcbPrivilege)
	SystemCoverageInformation, // q; s // name:wow64:whNT32QuerySystemCoverageInformation; ExpCovQueryInformation
	SystemPrefetchPatchInformation, // not implemented
	SystemVerifierFaultsInformation, // s (requires SeDebugPrivilege)
	SystemSystemPartitionInformation, // q: SYSTEM_SYSTEM_PARTITION_INFORMATION
	SystemSystemDiskInformation, // q: SYSTEM_SYSTEM_DISK_INFORMATION
	SystemProcessorPerformanceDistribution, // q: SYSTEM_PROCESSOR_PERFORMANCE_DISTRIBUTION // 100
	SystemNumaProximityNodeInformation, // q
	SystemDynamicTimeZoneInformation, // q; s (requires SeTimeZonePrivilege)
	SystemCodeIntegrityInformation, // q // SeCodeIntegrityQueryInformation
	SystemProcessorMicrocodeUpdateInformation, // s
	SystemProcessorBrandString, // q // HaliQuerySystemInformation -> HalpGetProcessorBrandString, info class 23
	SystemVirtualAddressInformation, // q: SYSTEM_VA_LIST_INFORMATION[]; s: SYSTEM_VA_LIST_INFORMATION[] (requires SeIncreaseQuotaPrivilege) // MmQuerySystemVaInformation
	SystemLogicalProcessorAndGroupInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX // since WIN7 // KeQueryLogicalProcessorRelationship
	SystemProcessorCycleTimeInformation, // q: SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION[]
	SystemStoreInformation, // q; s // SmQueryStoreInformation
	SystemRegistryAppendString, // s: SYSTEM_REGISTRY_APPEND_STRING_PARAMETERS // 110
	SystemAitSamplingValue, // s: ULONG (requires SeProfileSingleProcessPrivilege)
	SystemVhdBootInformation, // q: SYSTEM_VHD_BOOT_INFORMATION
	SystemCpuQuotaInformation, // q; s // PsQueryCpuQuotaInformation
	SystemNativeBasicInformation, // not implemented
	SystemSpare1, // not implemented
	SystemLowPriorityIoInformation, // q: SYSTEM_LOW_PRIORITY_IO_INFORMATION
	SystemTpmBootEntropyInformation, // q: TPM_BOOT_ENTROPY_NT_RESULT // ExQueryTpmBootEntropyInformation
	SystemVerifierCountersInformation, // q: SYSTEM_VERIFIER_COUNTERS_INFORMATION
	SystemPagedPoolInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypePagedPool)
	SystemSystemPtesInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemPtes) // 120
	SystemNodeDistanceInformation, // q
	SystemAcpiAuditInformation, // q: SYSTEM_ACPI_AUDIT_INFORMATION // HaliQuerySystemInformation -> HalpAuditQueryResults, info class 26
	SystemBasicPerformanceInformation, // q: SYSTEM_BASIC_PERFORMANCE_INFORMATION // name:wow64:whNtQuerySystemInformation_SystemBasicPerformanceInformation
	SystemQueryPerformanceCounterInformation, // q: SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION // since WIN7 SP1
	SystemSessionBigPoolInformation, // since WIN8
	SystemBootGraphicsInformation,
	SystemScrubPhysicalMemoryInformation,
	SystemBadPageInformation,
	SystemProcessorProfileControlArea,
	SystemCombinePhysicalMemoryInformation, // 130
	SystemEntropyInterruptTimingCallback,
	SystemConsoleInformation,
	SystemPlatformBinaryInformation,
	SystemThrottleNotificationInformation,
	SystemHypervisorProcessorCountInformation,
	SystemDeviceDataInformation,
	SystemDeviceDataEnumerationInformation,
	SystemMemoryTopologyInformation,
	SystemMemoryChannelInformation,
	SystemBootLogoInformation, // 140
	SystemProcessorPerformanceInformationEx, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX // since WINBLUE
	SystemSpare0,
	SystemSecureBootPolicyInformation,
	SystemPageFileInformationEx, // q: SYSTEM_PAGEFILE_INFORMATION_EX
	SystemSecureBootInformation,
	SystemEntropyInterruptTimingRawInformation,
	SystemPortableWorkspaceEfiLauncherInformation,
	SystemFullProcessInformation, // q: SYSTEM_PROCESS_INFORMATION with SYSTEM_PROCESS_INFORMATION_EXTENSION (requires admin)
	SystemKernelDebuggerInformationEx, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION_EX
	SystemBootMetadataInformation, // 150
	SystemSoftRebootInformation,
	SystemElamCertificateInformation,
	SystemOfflineDumpConfigInformation,
	SystemProcessorFeaturesInformation, // q: SYSTEM_PROCESSOR_FEATURES_INFORMATION
	SystemRegistryReconciliationInformation,
	SystemEdidInformation,
	SystemManufacturingInformation, // q: SYSTEM_MANUFACTURING_INFORMATION // since THRESHOLD
	SystemEnergyEstimationConfigInformation, // q: SYSTEM_ENERGY_ESTIMATION_CONFIG_INFORMATION
	SystemHypervisorDetailInformation, // q: SYSTEM_HYPERVISOR_DETAIL_INFORMATION
	SystemProcessorCycleStatsInformation, // q: SYSTEM_PROCESSOR_CYCLE_STATS_INFORMATION // 160
	SystemVmGenerationCountInformation,
	SystemTrustedPlatformModuleInformation, // q: SYSTEM_TPM_INFORMATION
	SystemKernelDebuggerFlags,
	SystemCodeIntegrityPolicyInformation,
	SystemIsolatedUserModeInformation,
	SystemHardwareSecurityTestInterfaceResultsInformation,
	SystemSingleModuleInformation, // q: SYSTEM_SINGLE_MODULE_INFORMATION
	SystemAllowedCpuSetsInformation,
	SystemDmaProtectionInformation, // q: SYSTEM_DMA_PROTECTION_INFORMATION
	SystemInterruptCpuSetsInformation,
	SystemSecureBootPolicyFullInformation,
	SystemCodeIntegrityPolicyFullInformation,
	SystemAffinitizedInterruptProcessorInformation,
	SystemRootSiloInformation, // q: SYSTEM_ROOT_SILO_INFORMATION
	SystemCpuSetInformation, // q: SYSTEM_CPU_SET_INFORMATION // since THRESHOLD2
	SystemCpuSetTagInformation, // q: SYSTEM_CPU_SET_TAG_INFORMATION
	SystemWin32WerStartCallout,
	SystemSecureKernelProfileInformation,
	MaxSystemInfoClass

} SYSTEM_INFORMATION_CLASS;

typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO
{
	USHORT UniqueProcessId;			//进程标识符
	USHORT CreatorBackTraceIndex;
	UCHAR ObjectTypeIndex;			//打开的对象的类型
	UCHAR HandleAttributes;
	USHORT HandleValue;				// 句柄数值,在进程打开的句柄中唯一标识某个句柄
	PVOID Object;					//句柄对象
	ULONG GrantedAccess;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO, *PSYSTEM_HANDLE_TABLE_ENTRY_INFO;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
	ULONG NumberOfHandles;
	SYSTEM_HANDLE_TABLE_ENTRY_INFO Handles[1];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;

typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX
{
	PVOID Object;				//这个就是句柄对应的EPROCESS的地址
	ULONG_PTR UniqueProcessId;	//进程标识符 
	ULONG_PTR HandleValue;
	ULONG GrantedAccess;		//句柄对象的访问权限	
	USHORT CreatorBackTraceIndex;
	USHORT ObjectTypeIndex;		//打开的对象的类型
	ULONG HandleAttributes;
	ULONG Reserved;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX, *PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX;

typedef struct _SYSTEM_HANDLE_INFORMATION_EX
{
	ULONG_PTR NumberOfHandles;
	ULONG_PTR Reserved;
	SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Handles[1];
} SYSTEM_HANDLE_INFORMATION_EX, *PSYSTEM_HANDLE_INFORMATION_EX;

typedef struct _SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION
{
	ULONGLONG CycleTime;
} SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION, *PSYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION;

typedef struct _OBJECT_ATTRIBUTES
{
	ULONG Length;
	PVOID RootDirectory;
	PUNICODE_STRING ObjectName;
	ULONG Attributes;
	PVOID SecurityDescriptor;
	PVOID SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef enum _KWAIT_REASON
{
	Executive,
	FreePage,
	PageIn,
	PoolAllocation,
	DelayExecution,
	Suspended,
	UserRequest,
	WrExecutive,
	WrFreePage,
	WrPageIn,
	WrPoolAllocation,
	WrDelayExecution,
	WrSuspended,
	WrUserRequest,
	WrEventPair,
	WrQueue,
	WrLpcReceive,
	WrLpcReply,
	WrVirtualMemory,
	WrPageOut,
	WrRendezvous,
	WrKeyedEvent,
	WrTerminated,
	WrProcessInSwap,
	WrCpuRateControl,
	WrCalloutStack,
	WrKernel,
	WrResource,
	WrPushLock,
	WrMutex,
	WrQuantumEnd,
	WrDispatchInt,
	WrPreempted,
	WrYieldExecution,
	WrFastMutex,
	WrGuardedMutex,
	WrRundown,
	WrAlertByThreadId,
	WrDeferredPreempt,
	MaximumWaitReason
} KWAIT_REASON, *PKWAIT_REASON;
typedef struct _SYSTEM_THREAD_INFORMATION
{
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	LONG BasePriority;
	ULONG ContextSwitches;
	ULONG ThreadState;
	KWAIT_REASON WaitReason;
} SYSTEM_THREAD_INFORMATION, *PSYSTEM_THREAD_INFORMATION;


typedef struct _SYSTEM_PROCESS_INFORMATION
{
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	LARGE_INTEGER WorkingSetPrivateSize; // since VISTA
	ULONG HardFaultCount; // since WIN7
	ULONG NumberOfThreadsHighWatermark; // since WIN7
	ULONGLONG CycleTime; // since WIN7
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ImageName;
	KPRIORITY BasePriority;
	HANDLE UniqueProcessId;
	HANDLE InheritedFromUniqueProcessId;
	ULONG HandleCount;
	ULONG SessionId;
	ULONG_PTR UniqueProcessKey; // since VISTA (requires SystemExtendedProcessInformation)
	SIZE_T PeakVirtualSize;
	SIZE_T VirtualSize;
	ULONG PageFaultCount;
	SIZE_T PeakWorkingSetSize;
	SIZE_T WorkingSetSize;
	SIZE_T QuotaPeakPagedPoolUsage;
	SIZE_T QuotaPagedPoolUsage;
	SIZE_T QuotaPeakNonPagedPoolUsage;
	SIZE_T QuotaNonPagedPoolUsage;
	SIZE_T PagefileUsage;
	SIZE_T PeakPagefileUsage;
	SIZE_T PrivatePageCount;
	LARGE_INTEGER ReadOperationCount;
	LARGE_INTEGER WriteOperationCount;
	LARGE_INTEGER OtherOperationCount;
	LARGE_INTEGER ReadTransferCount;
	LARGE_INTEGER WriteTransferCount;
	LARGE_INTEGER OtherTransferCount;
	SYSTEM_THREAD_INFORMATION Threads[1]; // SystemProcessInformation
										  // SYSTEM_EXTENDED_THREAD_INFORMATION Threads[1]; // SystemExtendedProcessinformation
										  // SYSTEM_EXTENDED_THREAD_INFORMATION + SYSTEM_PROCESS_INFORMATION_EXTENSION // SystemFullProcessInformation
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
{
	LARGE_INTEGER IdleTime;
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER DpcTime;
	LARGE_INTEGER InterruptTime;
	ULONG InterruptCount;
} SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION, *PSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;

typedef struct _SYSTEM_INTERRUPT_INFORMATION
{
	ULONG ContextSwitches;
	ULONG DpcCount;
	ULONG DpcRate;
	ULONG TimeIncrement;
	ULONG DpcBypassCount;
	ULONG ApcBypassCount;
} SYSTEM_INTERRUPT_INFORMATION, *PSYSTEM_INTERRUPT_INFORMATION;

typedef struct _RTL_PROCESS_MODULE_INFORMATION
{
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES
{
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES, *PRTL_PROCESS_MODULES;

typedef struct _RTL_PROCESS_HEAP_INFORMATION
{
	PVOID Base;
	ULONG Flags;
	USHORT Granularity;
	USHORT Unknown;
	ULONG Allocated;
	ULONG Committed;
	ULONG TagCount;
	ULONG BlockCount;
	ULONG Reserved[7];
	PVOID Tags;
	PVOID Blocks;
} RTL_PROCESS_HEAP_INFORMATION, *PRTL_PROCESS_HEAP_INFORMATION;

typedef struct _RTL_PROCESS_HEAPS
{
	ULONG HeapCount;
	RTL_PROCESS_HEAP_INFORMATION HeapEntry[1];
} RTL_PROCESS_HEAPS, *PRTL_PROCESS_HEAPS;

typedef struct _RTL_PROCESS_LOCK_INFORMATION
{
	PVOID Address;
	USHORT Type;
	USHORT CreatorBackTraceIndex;
	ULONG OwnerThreadId;
	ULONG ActiveCount;
	ULONG ContentionCount;
	ULONG EntryCount;
	ULONG RecursionCount;
	ULONG NumberOfSharedWaiters;
	ULONG NumberOfExclusiveWaiters;
} RTL_PROCESS_LOCK_INFORMATION, *PRTL_PROCESS_LOCK_INFORMATION;

typedef struct _RTL_PROCESS_LOCKS
{
	ULONG LockCount;
	RTL_PROCESS_LOCK_INFORMATION LockEntry[1];
} RTL_PROCESS_LOCKS, *PRTL_PROCESS_LOCKS;

typedef struct _RTL_PROCESS_BACKTRACE_INFORMATION
{
	PVOID SymbolicBackTrace;
	ULONG TraceCount;
	USHORT Index;
	USHORT Depth;
	PVOID BackTrace[16];
} RTL_PROCESS_BACKTRACE_INFORMATION, *PRTL_PROCESS_BACKTRACE_INFORMATION;

typedef struct _RTL_PROCESS_BACKTRACES
{
	ULONG CommittedMemory;
	ULONG ReservedMemory;
	ULONG NumberOfBackTraceLookups;
	ULONG NumberOfBackTraces;
	RTL_PROCESS_BACKTRACE_INFORMATION BackTraces[1];
} RTL_PROCESS_BACKTRACES, *PRTL_PROCESS_BACKTRACES;


typedef struct _RTL_DEBUG_BUFFER
{
	HANDLE SectionHandle;
	PVOID SectionBase;
	PVOID RemoteSectionBase;
	ULONG SectionBaseDelta;
	HANDLE EventPairHandle;
	ULONG Unknown[2];
	HANDLE RemoteThreadHandle;
	ULONG InfoClassMask;
	ULONG SizeOfInfo;
	ULONG AllocatedSize;
	ULONG SectionSize;
	PRTL_PROCESS_MODULES ModuleInformation;
	PRTL_PROCESS_BACKTRACES BackTraceInformation;
	PRTL_PROCESS_HEAPS HeapInformation;
	PRTL_PROCESS_LOCKS LockInformation;
	PVOID Reserved[8];
} RTL_DEBUG_BUFFER, *PRTL_DEBUG_BUFFER;

typedef BOOL(WINAPI *LPFN_IsXXXX)();
typedef BOOL(WINAPI* LPFN_LockWorkStation)();
typedef BOOL(WINAPI* LPFN_SetSuspendState)(BOOLEAN bHibernate, BOOLEAN bForce, BOOLEAN bWakeupEventsDisabled);
typedef BOOL(WINAPI *LPFN_IsWow64Process)(HANDLE, PBOOL);
typedef BOOL(WINAPI* LPFN_CreateRestrictedToken)(HANDLE ExistingTokenHandle, DWORD Flags, DWORD DisableSidCount, PSID_AND_ATTRIBUTES SidsToDisable, DWORD DeletePrivilegeCount, PLUID_AND_ATTRIBUTES PrivilegesToDelete, DWORD RestrictedSidCount, PSID_AND_ATTRIBUTES SidsToRestrict, PHANDLE NewTokenHandle);
typedef BOOLEAN(WINAPI *LPFN_IsPwrHibernateAllowed)();
typedef BOOLEAN(WINAPI *LPFN_IsPwrSuspendAllowed)();
typedef int(WINAPI *LPFN_SetLayeredWindowAttributes)(DWORD, DWORD, DWORD, DWORD);
typedef HRESULT(WINAPI* LPFN_SHAutoComplete)(HWND hWndEdit, DWORD dwFlags);
typedef CRYPT_PROVIDER_SGNR *  (WINAPI* LPFN_WinVerifyTrust)(CRYPT_PROVIDER_DATA *pProvData, DWORD idxSigner, BOOL fCounterSigner, DWORD idxCounterSigner);
typedef CRYPT_PROVIDER_DATA *  (WINAPI* LPFN_WTHelperGetProvSignerFromChain)(HANDLE hStateData);
typedef BOOL(WINAPI* LPFN_WTHelperProvDataFromStateData)(HCATADMIN hCatAdmin, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_CryptCATAdminReleaseContext)(HCATADMIN hCatAdmin, HCATINFO hCatInfo, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_CryptCATAdminReleaseCatalogContext)(HCATINFO hCatInfo, CATALOG_INFO *psCatInfo, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_CryptCATCatalogInfoFromContext)(HCATINFO hCatInfo, CATALOG_INFO *psCatInfo, DWORD dwFlags);
typedef HCATINFO(WINAPI* LPFN_CryptCATAdminEnumCatalogFromHash)(HCATADMIN hCatAdmin, BYTE *pbHash, DWORD cbHash, DWORD dwFlags, HCATINFO *phPrevCatInfo);
typedef BOOL(WINAPI* LPFN_CryptCATAdminCalcHashFromFileHandle)(HANDLE hFile, DWORD *pcbHash, BYTE *pbHash, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_CryptCATAdminAcquireContext)(HCATADMIN *phCatAdmin, const GUID *pgSubsystem, DWORD dwFlags);
typedef DWORD(WINAPI* LPFN_CertNameToStrW)(DWORD dwCertEncodingType, PCERT_NAME_BLOB pName, DWORD dwStrType, LPWSTR psz, DWORD csz);
typedef HCATINFO(WINAPI* LPFN_CryptCATAdminAddCatalog)(HCATADMIN hCatAdmin, PWSTR pwszCatalogFile, PWSTR pwszSelectBaseName, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_CryptCATAdminRemoveCatalog)(HCATADMIN hCatAdmin, LPCWSTR pwszCatalogFile, DWORD dwFlags);
typedef BOOL(WINAPI* LPFN_IsCatalogFile)(HANDLE hFile, WCHAR *pwszFileName);
typedef DWORD(WINAPI* LPFN_AllocateAndGetUdpExTable2FromStack)(PVOID* ppUDPTable, BOOL bOrder, HANDLE hHeap, DWORD dwFlags, DWORD dwFamily, UDP_TABLE_CLASS  UdpTableClass);
typedef DWORD(WINAPI* LPFN_AllocateAndGetTcpExTable2FromStack)(PVOID* ppTcpTable, BOOL bOrder, HANDLE hHeap, DWORD dwFlags, DWORD dwFamily, TCP_TABLE_CLASS  TcpTableClass);

typedef DWORD (CALLBACK *PACLCHANGE)(HWND Owner, HANDLE Instance, PVOID CallbackContext, PSECURITY_DESCRIPTOR NewSD, PSECURITY_DESCRIPTOR NewObjectSD, BOOLEAN ApplyToSubContainers, BOOLEAN ApplyToSubObjects, PDWORD ChangeContextStatus);

typedef DWORD(WINAPI* LPFN_SedDiscretionaryAclEditor)(HWND Owner, HINSTANCE Instance, PWCHAR MachineName, PACLDLGCONTROL AclDlgControl, PACLEDITCONTROL AclEditControl, PWCHAR ObjectName, PACLCHANGE ChangeCallback, PVOID ChangeCallbackContext, PSECURITY_DESCRIPTOR ObjectSecurity, BOOLEAN NoReadPermission, BOOLEAN ReadOnly, PDWORD ChangeContextStatus, PVOID MustBeZero);
typedef DWORD(WINAPI* LPFN_SedTakeOwnership)(HWND Owner, HINSTANCE Instance, PWCHAR MachineName, PWCHAR ObjectType, PWCHAR ObjectName, DWORD ObjectCount, PACLCHANGE ChangeCallback, PVOID ChangeCallbackContext, PSECURITY_DESCRIPTOR ObjectSecurity, BOOLEAN NoReadPermission, BOOLEAN NoOwnerChange, PDWORD ChangeContextStatus, PACLHELPCONTROL HelpInfo, PVOID MustBeZero);
typedef DWORD(WINAPI* LPFN_SedSystemAclEditor)(HWND Owner, HINSTANCE Instance, PWCHAR MachineName, PACLDLGCONTROL AclDlgControl, PACLEDITCONTROL AclEditControl, PWCHAR ObjectName, PACLCHANGE ChangeCallback, PVOID ChangeCallbackContext, PSECURITY_DESCRIPTOR ObjectSecurity, BOOLEAN NoReadPermission, PDWORD ChangeContextStatus, PVOID MustBeZero);
typedef NTSTATUS(NTAPI* LPFN_NtSetInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength);
typedef NTSTATUS(NTAPI* LPFN_NtQueryInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
typedef NTSTATUS(NTAPI* LPFN_NtSetInformationThread)(HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength);
typedef NTSTATUS(NTAPI* LPFN_NtQueryInformationThread)(HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength, PULONG ReturnLength);
typedef NTSTATUS(NTAPI* LPFN_NtQuerySystemInformationEx)(SYSTEM_INFORMATION_CLASS SystemInformationClass, PULONG QueryType, ULONG Alignment, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);
typedef NTSTATUS(NTAPI* LPFN_NtQuerySystemInformation)(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG Length, PULONG ResultLength);
typedef NTSTATUS(NTAPI* LPFN_NtQueryInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
//////////////////////////////////////////////////////////////////////////
//Physical Address Extension
//
typedef BOOL(WINAPI* LPFN_IsProcessorFeaturePresent)(DWORD ProcessorFeature);
typedef VOID(WINAPI *LPFN_RunFileDlg)(HWND hwndOwner, HICON hIcon, LPCWSTR lpstrDirectory, LPCWSTR lpstrTitle, LPCWSTR lpstrDescription, UINT uFlags);
typedef NTSTATUS(WINAPI* LPFN_NtLoadDriver)(IN PUNICODE_STRING DriverServiceName);
typedef VOID(WINAPI* LPFN_RtlInitUnicodeString)(PUNICODE_STRING DestinationString, IN LPCWSTR SourceString);
typedef ULONG(WINAPI* LPFN_RtlNtStatusToDosError)(IN NTSTATUS Status);
typedef ULONG(WINAPI* LPFN_NtOpenSymbolicLinkObject)(PHANDLE LinkHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes);
typedef ULONG(WINAPI* LPFN_NtQuerySymbolicLinkObject)(HANDLE LinkHandle, PUNICODE_STRING LinkTarget, PULONG ReturnedLength);
typedef NTSTATUS(WINAPI *LPFN_NtOpenThread)(IN PHANDLE ThreadHandle, ACCESS_MASK AccessMask, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientID);
typedef NTSTATUS(WINAPI *LPFN_NtQueryInformationThread)(HANDLE, THREADINFOCLASS, PVOID, ULONG, PULONG);
typedef PIMAGE_NT_HEADERS(WINAPI* LPFN_ImageNtHeader)(PVOID Base);
typedef PRTL_DEBUG_BUFFER(WINAPI *RTLCREATEQUERYDEBUGBUFFER)(IN ULONG Size, IN BOOLEAN EventPair);
typedef DWORD(WINAPI *RTLDESTROYQUERYDEBUGBUFFER)(IN PRTL_DEBUG_BUFFER Buf);
typedef DWORD(WINAPI *RTLQUERYPROCESSDEBUGINFORMATION)(IN ULONG ProcessId, IN ULONG DebugInfoMask, IN OUT PRTL_DEBUG_BUFFER Buf);
typedef DWORD(WINAPI *LPFN_I_QueryTagInformation)(
	_In_opt_ LPCWSTR pszMachineName,
	_In_ TAG_INFO_LEVEL eInfoLevel,
	_Inout_ PVOID pTagInfo
	);
///待注释

typedef ULONG (WINAPI* LPFN_EnableTraceEx)(
	_In_     LPCGUID                  ProviderId,
	_In_opt_ LPCGUID                  SourceId,
	_In_     TRACEHANDLE              TraceHandle,
	_In_     ULONG                    IsEnabled,
	_In_     UCHAR                    Level,
	_In_     ULONGLONG                MatchAnyKeyword,
	_In_     ULONGLONG                MatchAllKeyword,
	_In_     ULONG                    EnableProperty,
	_In_opt_ PEVENT_FILTER_DESCRIPTOR EnableFilterDesc
);
typedef NTSYSAPI NTSTATUS(*LPFN_ZwOpenKey)(PHANDLE KeyHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes);
typedef NTSYSAPI NTSTATUS(*LPFN_ZwCreateKey)(PHANDLE KeyHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, ULONG TitleIndex, PUNICODE_STRING Class, ULONG CreateOptions, PULONG Disposition);
typedef NTSYSAPI NTSTATUS(*LPFN_ZwDeleteKey)(HANDLE KeyHandle);

typedef BOOLEAN(WINAPI* LPFN_Wow64EnableWow64FsRedirection)(BOOLEAN);
typedef BOOL(WINAPI* LPFN_Wow64DisableWow64FsRedirection)(PVOID* OldValue);
typedef BOOL(WINAPI* LPFN_Wow64RevertWow64FsRedirection)(PVOID OldValue);
typedef LONG(WINAPI* LPFN_RegDeleteKeyExW)(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved);


typedef UINT (WINAPI * LPFN_GetSystemWindowsDirectoryW)(
	_Out_writes_to_opt_(uSize, return +1) LPWSTR lpBuffer,
	_In_ UINT uSize
);

typedef UINT(WINAPI * LPFN_GetSystemWow64DirectoryW)(
	_Out_writes_to_opt_(uSize, return +1) LPWSTR lpBuffer,
	_In_ UINT uSize
);

typedef DWORD(WINAPI *LPFN_GetVersion)(VOID);

typedef DWORD(WINAPI *LPFN_WNetAddConnection2A)(LPNETRESOURCEA lpNetResource, LPCSTR lpPassword, LPCSTR lpUserName, DWORD dwFlags);
typedef DWORD(WINAPI *LPFN_WNetCancelConnection2A)(LPCSTR lpName, DWORD dwFlags, BOOL fForce);
typedef DWORD(WINAPI *LPFN_NetServerEnum)(LPCWSTR servername, DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread, LPDWORD totalentries, DWORD servertype, LPCWSTR domain, LPDWORD resume_handle);
typedef DWORD(WINAPI *LPFN_NetApiBufferFree)(LPVOID Buffer);

typedef NTSYSAPI NTSTATUS(*LPFN_LsaQueryInformationPolicy)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID *Buffer);
typedef NTSYSAPI NTSTATUS(*LPFN_LsaOpenPolicy)(PLSA_UNICODE_STRING SystemName, PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle);
typedef NTSYSAPI NTSTATUS(*LPFN_LsaClose)(LSA_HANDLE ObjectHandle);
typedef LONG(WINAPI* LPFN_LsaNtStatusToWinError)(NTSTATUS Status);

#endif //

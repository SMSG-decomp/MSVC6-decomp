typedef struct DelayLoadInfo DelayLoadInfo, *PDelayLoadInfo;

typedef struct ImgDelayDescr ImgDelayDescr, *PImgDelayDescr;

typedef struct DelayLoadProc DelayLoadProc, *PDelayLoadProc;

typedef union IMAGE_THUNK_DATA32 IMAGE_THUNK_DATA32, *PIMAGE_THUNK_DATA32;

typedef union _union_29 _union_29, *P_union_29;

union _union_29 {
    char *szProcName;
    uint dwOrdinal;
};

struct DelayLoadProc {
    int fImportByName;
    union _union_29 u;
};

struct DelayLoadInfo {
    uint cb;
    struct ImgDelayDescr *pidd;
    void **ppfn;
    char *szDll;
    struct DelayLoadProc dlp;
    void *hmodCur;
    void *pfnCur;
    uint dwLastError;
};

struct ImgDelayDescr {
    uint grAttrs;
    char *szName;
    void **phmod;
    union IMAGE_THUNK_DATA32 *pIAT;
    union IMAGE_THUNK_DATA32 *pINT;
    union IMAGE_THUNK_DATA32 *pBoundIAT;
    union IMAGE_THUNK_DATA32 *pUnloadIAT;
    uint dwTimeStamp;
};

union IMAGE_THUNK_DATA32 {
    uint *Function;
    uint Ordinal;
    void *AddressOfData;
    uchar *ForwarderString;
};

typedef void * (*PfnDliHook)(uint, struct DelayLoadInfo *);

typedef struct UnloadInfo UnloadInfo, *PUnloadInfo;

struct UnloadInfo {
    struct UnloadInfo *puiNext;
    struct ImgDelayDescr *pidd;
};

typedef struct tagVS_FIXEDFILEINFO tagVS_FIXEDFILEINFO, *PtagVS_FIXEDFILEINFO;

typedef struct tagVS_FIXEDFILEINFO VS_FIXEDFILEINFO;

struct tagVS_FIXEDFILEINFO {
    uint dwSignature;
    uint dwStrucVersion;
    uint dwFileVersionMS;
    uint dwFileVersionLS;
    uint dwProductVersionMS;
    uint dwProductVersionLS;
    uint dwFileFlagsMask;
    uint dwFileFlags;
    uint dwFileOS;
    uint dwFileType;
    uint dwFileSubtype;
    uint dwFileDateMS;
    uint dwFileDateLS;
};

typedef void (*_PVFV)(void);

typedef void (*cl_abort_pass)(int);

typedef struct cl_compile_node cl_compile_node, *Pcl_compile_node;

typedef struct cl_srcfile cl_srcfile, *Pcl_srcfile;

typedef struct cl_mre_srctarg cl_mre_srctarg, *Pcl_mre_srctarg;

struct cl_mre_srctarg {
    struct cl_mre_srctarg *next;
    int is_cpp;
    char *source;
    char *target;
    char *options;
    void *unk14;
    char *browse;
};

struct cl_compile_node {
    struct cl_compile_node *next;
    struct cl_srcfile *file;
    int failed;
    struct cl_mre_srctarg mre;
};

struct cl_srcfile {
    struct cl_srcfile *next;
    char *name;
    char *fullname;
    int type;
    short explicit_type;
    short batch_index;
};

typedef char * (*cl_copy_fn)(char *, char *);

typedef struct cl_ctx cl_ctx, *Pcl_ctx;

typedef struct cl_optrec cl_optrec, *Pcl_optrec;

typedef struct cl_pass cl_pass, *Pcl_pass;

typedef uchar cl_u8;

typedef union cl_optrec_src cl_optrec_src, *Pcl_optrec_src;

typedef uint cl_u32;

typedef int (*cl_invoke_pass)(int, char **, int);

typedef struct cl_optdesc cl_optdesc, *Pcl_optdesc;

typedef struct cl_optdesc optdesc;

typedef struct cl_optrec optrec;

typedef int (*cl_opt_handler)(char **, int *);

union cl_optrec_src {
    optdesc *desc;
    optrec *owner;
};

struct cl_optrec {
    cl_u8 flags;
    cl_u8 refcount;
    cl_u8 pad[2];
    struct cl_optrec *next;
    char *passes;
    char *name;
    char *value;
    union cl_optrec_src src;
};

struct cl_pass {
    char *program;
    char *extra;
    char *envvar;
    char letter;
    char prefix;
    char pad[2];
    cl_u32 flags;
    void *module;
    cl_invoke_pass invoke;
    cl_abort_pass abort;
    char *host;
};

struct cl_optdesc {
    char *pattern;
    char *actions;
    char *incompatible;
    char *overridden;
    cl_opt_handler handler;
};

struct cl_ctx {
    struct cl_optrec *pass_options;
    struct cl_optrec *user_options;
    struct cl_pass *pass;
    struct cl_srcfile *files;
    struct cl_compile_node *batch;
    struct cl_mre_srctarg *skipped;
    struct cl_mre_srctarg **skipped_tail;
    struct cl_srcfile *file;
    char *temp_prefix;
    char *cl_dir;
};

typedef struct cl_drvvar cl_drvvar, *Pcl_drvvar;

struct cl_drvvar {
    char *name;
    int kind;
    int *target;
};

typedef union cl_drvvar_target cl_drvvar_target, *Pcl_drvvar_target;

union cl_drvvar_target {
    int *flag;
    char **string;
    void (*handler)(struct cl_optrec *);
};

typedef struct cl_filetype cl_filetype, *Pcl_filetype;

struct cl_filetype {
    char *extension;
    int kind;
    int *passes;
};

typedef struct cl_il_suffix cl_il_suffix, *Pcl_il_suffix;

struct cl_il_suffix {
    char *suffix;
    int per_file;
};

typedef struct cl_letter_group cl_letter_group, *Pcl_letter_group;

struct cl_letter_group {
    char *prefix;
    char *letters;
};

typedef void (*cl_message_fn)(uint, ...);

typedef struct cl_mre_files cl_mre_files, *Pcl_mre_files;

struct cl_mre_files {
    struct cl_mre_srctarg *out_of_date;
    struct cl_mre_srctarg *pending;
    struct cl_mre_srctarg *up_to_date;
    struct cl_mre_srctarg *succeeded;
    struct cl_mre_srctarg *failed;
};

typedef struct cl_seh_scope cl_seh_scope, *Pcl_seh_scope;

struct cl_seh_scope {
    int enclosing;
    void *filter;
    void *handler;
};

typedef struct cl_timeb cl_timeb, *Pcl_timeb;

struct cl_timeb {
    long time;
    ushort millitm;
    short timezone;
    short dstflag;
};

typedef struct cl_ctx driver_ctx;

typedef struct cl_letter_group letters;

typedef struct cl_mre_files mre_state;

typedef struct cl_compile_node node;

typedef struct cl_pass passrec;

typedef struct cl_srcfile srcfile;

typedef short int16_t;

typedef int int32_t;

typedef longlong int64_t;

typedef char int8_t;

typedef ushort uint16_t;

typedef uint uint32_t;

typedef ulonglong uint64_t;

typedef uchar uint8_t;

typedef char *va_list;


int __cdecl argv_count(char * * v);
int __cdecl uint_to_string(uint v, char * out, uint radix);
char * __cdecl load_message(UINT id);

int __cdecl cl_main(int argc, char * * argv);
void __cdecl driver_ctx_init(char * argv0, driver_ctx * ctx);
void __cdecl compile_all(driver_ctx * ctx);
node * __cdecl compile_list_new(driver_ctx * ctx);
node * __cdecl compile_node_new(srcfile * f);
int __cdecl compile_batch(driver_ctx * ctx, node * files);
__noreturn noreturn void __cdecl cl_exit(int code);
__noreturn noreturn void __cdecl cl_error(UINT n, ...);
void __cdecl cl_warning(UINT n, ...);
void __cdecl install_ctrl_handler(void);
int __stdcall cl_ctrl_handler(ulong ctrl_type);
void __cdecl mainCRTStartup(void);

int __cdecl file_type_from_extension(char * path);
srcfile * __cdecl srcfile_new(char * name, int type);
void __cdecl srcfile_append(char * name, int type, short explicit_type);
void __cdecl srcfiles_make_full_paths(void);
void __cdecl temp_prefix_create(driver_ctx * ctx);
char * __cdecl path_set_default_extension(char * ext, char * path, char * base);
char * __cdecl path_directory_of(char * path);
char * __cdecl path_search_program(char * cl_dir, char * name, uint * where);
int __cdecl path_search_PATH(char * name, char * out, int size);
void __cdecl response_file_read(char * path);
char * __cdecl path_base_name(char * out, char * path);
char * __cdecl path_file_name(char * out, char * path);
char * __cdecl path_strip_extension(char * out, char * path);
char * __cdecl path_full(char * out, char * path, size_t n);
void __cdecl file_printf(FILE * f, char * fmt, ...);

node * __cdecl mre_filter_out_of_date(driver_ctx * ctx, node * files, mre_state * st);
node * __cdecl mre_report_and_next(driver_ctx * ctx, mre_state * st);
char * __cdecl mre_options_string(driver_ctx * ctx);
int __cdecl mre_option_compare(char * * a, char * * b);

void __cdecl options_make_full_paths(void);
int __cdecl option_goes_to_pass(optrec * opt, passrec * pass);
char __cdecl option_pass_letter_in(optrec * opt, char * letters);
void __cdecl option_check_numeric_range(char * name, char * value, char * spec);
optrec * __cdecl option_match_and_take_argument(optdesc * desc, char * * argv, int * index);
optrec * __cdecl optrec_new(char * name, char * value, char * passes, uint8_t flags);
int __cdecl option_pattern_match_length(optdesc * desc, char * * argv, int index);
int __cdecl action_expand_alternative(char * p, char * out, char * value, char * * alt);
char * __cdecl action_expand_value(char * p, char * out, char * value);
optrec * __cdecl action_parse_list(char * actions, optrec * opt);
int __cdecl optrec_matches(optrec * a, optrec * b);
int __cdecl option_apply(char * * argv, int * index, int user);
void __cdecl optrec_free(optrec * r);
void __cdecl optrec_list_free(optrec * list);
optdesc * __cdecl option_lookup(char * * argv, int index);
optrec * __cdecl optrec_list_extract_matching(optrec * * list, optrec * pattern, optrec * * removed);
optrec * __cdecl optrec_clone(optrec * r);
void __cdecl option_conflict_message(int msg, optrec * a, optrec * b);
void __cdecl options_parse_argv(char * * argv, int argc);
letters * __cdecl option_letter_group_lookup(char * sw);
void __cdecl option_letter_group_split(letters * g, char * sw);
void __cdecl options_add_include_env(void);
void __cdecl option_add_include_dir(char * dir, optdesc * idesc);
int __cdecl option_prescan(char * * argv, int argc, char * name, int * value);
void __cdecl drv_bp_set_pass_path(optrec * r);
void __cdecl drv_bx_set_pass_host(optrec * r);
void __cdecl drv_ba_enable_pass(optrec * r);
void __cdecl drv_bd_disable_pass(optrec * r);
void __cdecl drv_bc_copy_pass_enable(optrec * r);
void __cdecl drv_bU_undefine(optrec * r);
void __cdecl drv_bu_undefine_all(optrec * r);
void __cdecl drv_bo_check_output_name(optrec * r);
void __cdecl drv_bA_listing_kind(optrec * r);
void __cdecl drv_LD_build_dll(optrec * r);
void __cdecl options_check_requirements(void);
int __cdecl optrec_list_any_match(optrec * list, optrec * pats);
int __cdecl opt_link_handler(char * * argv, int * index);
int __cdecl opt_D_handler(char * * argv, int * index);
int __cdecl opt_To_handler(char * * argv, int * index);
int __cdecl opt_Tc_handler(char * * argv, int * index);
int __cdecl opt_Tp_handler(char * * argv, int * index);
void __cdecl opt_T_file_handler(char * sw, char * * argv, int * index, int type);
char * __cdecl action_expand_percent(char * out, char * tmpl, driver_ctx * ctx);
char * __cdecl map_file_name(char * out, char * exe);
int __cdecl action_expand_length(char * tmpl, driver_ctx * ctx);
char * * __cdecl cmdline_split(char * s, int unquote);

char * __cdecl program_path(void);
void __cdecl pass_set_driver_vars(driver_ctx * ctx);
void __cdecl pass_resolve_program(driver_ctx * ctx);
int __cdecl run_pass_list(int * passes, driver_ctx * ctx, run_pass_list_fn * fn);
int __cdecl run_compiler_pass(driver_ctx * ctx);
int __cdecl run_linker(driver_ctx * ctx);
void __cdecl linker_response_write(driver_ctx * ctx);
void __cdecl il_files_delete(int after_file);
void __cdecl il_file_delete(int suffix_index);
void __cdecl pass_timer_start(void);
void __cdecl pass_timer_report(char * program);
void __cdecl pass_unload(passrec * p);
int __cdecl run_program(int mode, passrec * pass, char * program, char * envvar, char * * argv);

void __cdecl list_append(optrec * * head, optrec * node);
optrec * __cdecl list_unlink(optrec * * head, optrec * node);
int __cdecl str_has_prefix(char * prefix, char * s);
__noreturn noreturn void __cdecl print_usage_and_exit(void);
void __cdecl print_banner(void);
void __cdecl print_pass_versions(void);
void __cdecl print_file_version(char * path);
node * __cdecl list_from_inner_links(cl_mre_srctarg * l);
cl_mre_srctarg * __cdecl list_to_inner_links(node * l);
node * __cdecl list_reverse(node * l);
void __cdecl enc_set_environment(driver_ctx * ctx, char * program);
void __cdecl enc_clear_environment(void);
char * __cdecl str_skip_spaces(char * s);
char * __cdecl strcat_end(char * dst, char * src);
char * __cdecl strcat_double_percent(char * dst, char * src);
char * __cdecl strcpy_end(char * dst, char * src);
char * __cdecl str_concat_new(char * a, char * b);
int __cdecl quoted_length(char * s);
char * __cdecl quote_argument(char * out, char * s);
char * __cdecl str_last_of(char * s, char * set);
void __cdecl msg_write(int fd, char * fmt, ...);
char * __cdecl msg_format(int * len, char * fmt, va_list args);
void __cdecl msg_write_va(int fd, char * fmt, va_list args);
void __cdecl print_help(void);
void * __cdecl xmalloc(size_t n);
void __cdecl xfree(void * p);
char * __cdecl xstrdup(char * s);
void __cdecl stderr_to_stdout(void);
int __cdecl console_height(void);
void __stdcall delayload_thunk_dispatch(void);
FARPROC __stdcall __delayLoadHelper(ImgDelayDescr * pidd, FARPROC * ppfnIATEntry);
void __stdcall delayload_copy_iat(IMAGE_THUNK_DATA32 * pitdDst, IMAGE_THUNK_DATA32 * pitdSrc);
void __cdecl __setargv(void);
void __cdecl _setdefaultprecision(void);

extern int * __imp___adjust_fdiv;
extern cl_drvvar g_driver_vars[37];
extern cl_seh_scope g_cl_main_scopetable;
extern cl_letter_group g_option_letter_groups[5];
extern cl_il_suffix g_il_temp_suffixes[8];
extern cl_optdesc g_option_table[193];
extern cl_filetype g_file_types[11];
extern cl_seh_scope g_run_program_scopetable;
extern cl_seh_scope g_crt_startup_scopetable;
extern ImgDelayDescr __DELAY_IMPORT_DESCRIPTOR_VERSION;
extern ImgDelayDescr __NULL_DELAY_IMPORT_DESCRIPTOR;
extern _PVFV __xc_a[1];
extern _PVFV __xc_z[1];
extern _PVFV __xi_a[1];
extern _PVFV __xi_z[1];
extern int g_use_include_env;
extern int g_parsing_defaults;
extern int g_mre_ok;
extern int g_batch_allowed;
extern cl_ctx * g_driver_ctx_ptr;
extern int g_merge_stderr;
extern int g_batch_limit;
extern char * g_include_argv[2];
extern char * g_gi_off_argv[2];
extern int g_predefines_live;
extern int g_LD_enabled;
extern int g_first_var_pass;
extern int g_response_first_line;
extern char * g_default_switches[22];
extern int g_default_switch_is_typed[21];
extern cl_pass g_passes[5];
extern int g_passes_c[3];
extern int g_passes_cpp[3];
extern int g_passes_link[2];
extern int g_passes_none;
extern int g_first_batch;
extern int32_t g_format_buffer_size;
extern int __defaultmatherr;
extern char * g_bt_type;
extern int g_Gi;
extern char * g_Fd_name;
extern char * g_Fo_name;
extern int g_Bz_no_run;
extern int g_show_commands;
extern char * g_enc_event_name;
extern int g_any_pass_run;
extern int g_preprocess_only;
extern cl_ctx g_driver_ctx;
extern int g_Brepro;
extern int g_map_wanted;
extern int g_compilable_files;
extern int g_noover;
extern cl_optrec * g_unknown_options;
extern char * g_Fm_name;
extern int g_echoed_response;
extern char * g_Fe_name;
extern char * g_browse_name;
extern int g_Bt_time;
extern int g_exit_failed;
extern int g_Bv;
extern int g_dll;
extern int g_help;
extern int g_nologo;
extern int g_enc;
extern int g_keep_il;
extern int g_Gm;
extern int g_ZM_batch;
extern cl_optrec * g_optrec_free_list;
extern int g_switch_after_file;
extern int g_D4026_issued;
extern int g_response_depth;
extern cl_timeb g_pass_end_time;
extern cl_timeb g_pass_start_time;
extern char * g_format_buffer;
extern int g_ctrl_c_seen;
extern cl_pass * g_current_pass;
extern int g_pass_running;
extern UnloadInfo * __puiHead;
extern PfnDliHook __pfnDliFailureHook;
extern PfnDliHook __pfnDliNotifyHook;
extern int _dowildcard;
extern int _newmode;
extern int _commode;
extern int _fmode;
extern _PVFV * __onexitend;
extern _PVFV * __onexitbegin;
extern int _adjust_fdiv;
extern VS_VERSION_INFO Rsrc_Version_1_409;
extern void * ExceptionList;
extern void * StackBase;
extern void * StackLimit;
extern void * SubSystemTib;
extern void * FiberData;
extern void * ArbitraryUserPointer;
extern void * Self;
extern void * EnvironmentPointer;
extern CLIENT_ID ClientId;
extern void * ActiveRpcHandle;
extern void * ThreadLocalStoragePointer;
extern void * ProcessEnvironmentBlock;
extern dword LastErrorValue;
extern dword CountOfOwnedCriticalSections;
extern void * CsrClientThread;
extern void * Win32ThreadInfo;
extern dword User32Reserved[26];
extern dword UserReserved[5];
extern void * WOW32Reserved;
extern dword CurrentLocale;
extern dword FpSoftwareStatusRegister;
extern void * SystemReserved1[54];
extern dword ExceptionCode;
extern void * ActivationContextStackPointer;
extern dword TxFsContext;
extern dword GdiTebBatch;
extern CLIENT_ID RealClientId;
extern void * GdiCachedProcessHandle;
extern dword GdiClientPID;
extern dword GdiCLientTID;
extern void * GdiThreadLocalInfo;
extern void * Win32ClientInfo[62];
extern void * glDispatchTable[233];
extern void * glReserved1[29];
extern void * glReserved2;
extern void * glSectionInfo;
extern void * glSection;
extern void * glTable;
extern void * glCurrentRC;
extern void * glContext;
extern dword LastStatusValue;
extern void * DeallocationStack;
extern void * TlsSlots[64];
extern void * Vdm;
extern void * ReservedForNtRpc;
extern void * DbgSsReserved[2];
extern dword HardErrorMode;
extern void * Instrumentation[9];
extern GUID ActivityId;
extern void * SubProcessTag;
extern void * EtwLocalData;
extern void * EtwTraceData;
extern void * WinSockData;
extern dword GdiBatchCount;
extern dword IdealProcessorValue;
extern dword GuaranteedStackBytes;
extern void * ReservedForPerf;
extern void * ReservedForOle;
extern dword WaitingOnLoaderLock;
extern void * SavedPriorityState;
extern void * SoftPatchPtr1;
extern void * ThreadPoolData;
extern void * TlsExpansionSlots;
extern dword MuiGeneration;
extern dword IsImpersonating;
extern void * NlsCache;
extern void * pShimData;
extern dword HeapVirtualAffinity;
extern void * CurrentTransactionHandle;
extern void * ActiveFrame;
extern void * FlsData;
extern void * PreferredLanguages;
extern void * UserPrefLanguages;
extern void * MergedPrefLanguages;
extern dword MuiImpersonation;
extern ushort CrossTebFlags;
extern ushort SameTebFlags;
extern void * TxnScopeEnterCallback;
extern void * TxnScopeExitCallback;
extern void * TxnScopeContext;
extern dword LockCount;
extern void * ResourceRetValue;

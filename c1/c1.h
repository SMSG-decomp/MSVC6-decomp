typedef struct c1_asm_code_row c1_asm_code_row, *Pc1_asm_code_row;

typedef ushort c1_u16;

typedef uchar c1_u8;

struct c1_asm_code_row {
    c1_u16 code;
    c1_u8 cond_or_size;
    c1_u8 x03;
};

typedef struct c1_asm_expr c1_asm_expr, *Pc1_asm_expr;

typedef struct c1_symbol c1_symbol, *Pc1_symbol;

typedef struct fe_name fe_name, *Pfe_name;

typedef struct c1_sym_link c1_sym_link, *Pc1_sym_link;

typedef uint c1_u32;

typedef struct c1_type c1_type, *Pc1_type;

typedef union c1_symbol_x28 c1_symbol_x28, *Pc1_symbol_x28;

typedef union c1_symbol_x2c c1_symbol_x2c, *Pc1_symbol_x2c;

typedef struct fe_macro fe_macro, *Pfe_macro;

typedef union c1_type_x08 c1_type_x08, *Pc1_type_x08;

typedef struct c1_symbol_x28_bytes c1_symbol_x28_bytes, *Pc1_symbol_x28_bytes;

typedef struct fe_function_record fe_function_record, *Pfe_function_record;

typedef struct c1_symbol_cell c1_symbol_cell, *Pc1_symbol_cell;

typedef struct fe_macro_definition fe_macro_definition, *Pfe_macro_definition;

typedef struct c1_tag_symbol c1_tag_symbol, *Pc1_tag_symbol;

typedef struct c1_param_list c1_param_list, *Pc1_param_list;

struct c1_symbol_x28_bytes {
    c1_u8 bit_position;
    c1_u8 depth;
    c1_u16 unk2a;
};

struct fe_macro_definition {
    uint browse_id;
    char kind;
    uchar pad05[3];
    int position;
    uchar text[1];
};

struct c1_asm_expr {
    struct c1_symbol *sym;
    int disp;
    c1_u8 kind;
    c1_u8 seg_scale;
    c1_u8 base;
    c1_u8 index;
};

union c1_symbol_x28 {
    struct c1_symbol_x28_bytes bytes;
    struct fe_function_record *function;
    int value;
};

struct fe_name {
    struct fe_name *next;
    char *text;
    uint flags;
    struct fe_macro *macro;
    uchar token_kind;
    uchar keyword_class;
    uchar pad12[2];
};

struct c1_sym_link {
    struct fe_name *name;
    struct c1_sym_link *next;
    c1_u32 position;
    struct c1_type *type;
};

struct fe_function_record {
    void *symbol_entry;
    int ex_offset;
    int sy_offset;
    int source_file;
    int tuple_count;
    void *references;
    int formal_count;
    uint start_line;
    uint flags;
};

struct c1_param_list {
    int count;
    int debug_index;
    struct c1_type *types[1];
};

struct c1_tag_symbol {
    c1_u8 kind;
    c1_u8 flags1;
    c1_u8 flags2;
    c1_u8 flags3;
    c1_u8 flags4;
    c1_u8 flags5;
    c1_u16 scope_index;
    struct fe_name *name;
    struct c1_sym_link *next;
    c1_u32 position;
    struct c1_type *type;
    c1_u32 key_ref;
    c1_u32 entity;
    c1_u8 storage;
    c1_u8 flags21;
    c1_u8 flags22;
    c1_u8 flags23;
    void *detail;
    int size;
    c1_u32 debug_index;
    c1_u16 alignment;
    c1_u16 unk32;
    void *members;
};

struct c1_symbol_cell {
    struct c1_symbol *sym;
    struct c1_symbol_cell *next;
};

union c1_symbol_x2c {
    struct c1_symbol_cell *references;
    struct c1_symbol *debug_object;
    c1_u8 function_flags;
};

struct c1_symbol {
    c1_u8 kind;
    c1_u8 flags1;
    c1_u8 flags2;
    c1_u8 flags3;
    c1_u8 flags4;
    c1_u8 flags5;
    c1_u16 scope_index;
    struct fe_name *name;
    struct c1_sym_link *next;
    c1_u32 position;
    struct c1_type *type;
    c1_u32 key_ref;
    c1_u32 entity;
    c1_u8 storage;
    c1_u8 flags21;
    c1_u8 flags22;
    c1_u8 flags23;
    void *detail;
    union c1_symbol_x28 x28;
    union c1_symbol_x2c x2c;
    c1_u16 tag_alignment;
    c1_u16 unk32;
    void *tag_members;
};

union c1_type_x08 {
    struct c1_symbol *sym;
    struct c1_tag_symbol *tag;
    struct c1_param_list *params;
    c1_u32 count;
};

struct fe_macro {
    struct fe_name *name;
    struct fe_macro_definition *def;
};

struct c1_type {
    c1_u16 code;
    c1_u16 flags;
    struct c1_type *base;
    union c1_type_x08 extra;
    c1_u32 debug_index;
};

typedef struct c1_asm_instruction c1_asm_instruction, *Pc1_asm_instruction;

struct c1_asm_instruction {
    short code;
    c1_u8 size_class;
    c1_u8 pad03;
    c1_u8 opcode_flags;
    c1_u8 pad05[3];
    struct c1_asm_expr *exprs[3];
};

typedef struct c1_asm_opcode c1_asm_opcode, *Pc1_asm_opcode;

struct c1_asm_opcode {
    int form;
    int aux;
};

typedef struct c1_asm_operand c1_asm_operand, *Pc1_asm_operand;

struct c1_asm_operand {
    struct c1_asm_expr *expr;
    c1_u8 size_class;
    c1_u8 flags;
    c1_u8 pad06[2];
    struct c1_symbol *sym;
    struct c1_symbol *frame_sym;
};

typedef struct c1_block_scope c1_block_scope, *Pc1_block_scope;

typedef struct c1_block_scope_vtbl c1_block_scope_vtbl, *Pc1_block_scope_vtbl;

typedef struct c1_scope_object c1_scope_object, *Pc1_scope_object;

typedef struct c1_scope_lookup c1_scope_lookup, *Pc1_scope_lookup;

typedef struct c1_tag_lookup c1_tag_lookup, *Pc1_tag_lookup;

typedef union c1_scope_entries c1_scope_entries, *Pc1_scope_entries;

typedef struct c1_scope_symbol_list c1_scope_symbol_list, *Pc1_scope_symbol_list;

union c1_scope_entries {
    void **buckets;
    struct c1_scope_symbol_list *list;
};

struct c1_scope_object {
    struct c1_block_scope_vtbl *vtbl;
    struct c1_scope_object *parent;
    c1_u8 level;
    c1_u8 pad09[7];
    union c1_scope_entries entries;
    uint mask;
};

struct c1_scope_lookup {
    struct c1_symbol *sym;
    struct c1_scope_object *scope;
};

struct c1_scope_symbol_list {
    int arena;
    int *first;
    int *last;
};

struct c1_block_scope_vtbl {
    bool (*has_entries)(struct c1_scope_object *);
    void (*insert)(struct c1_scope_object *, struct c1_symbol *);
    c1_scope_lookup * (*lookup)(struct c1_scope_object *, int);
    c1_tag_lookup * (*lookup_tag)(struct c1_scope_object *, int);
    c1_scope_lookup * (*lookup_by_kind)(struct c1_scope_object *, int);
    void (*lookup_anonymous_member)(struct c1_scope_object *, void *, int *);
    int * (*find_link)(struct c1_scope_object *, int *);
    void (*pch_fixup)(struct c1_scope_object *);
    void (*emit_il)(struct c1_scope_object *);
    void (*link)(struct c1_scope_object *, int);
};

struct c1_tag_lookup {
    struct c1_tag_symbol *tag;
    struct c1_scope_object *scope;
};

struct c1_block_scope {
    struct c1_block_scope_vtbl *vtbl;
};

typedef struct c1_browse_record c1_browse_record, *Pc1_browse_record;

struct c1_browse_record {
    c1_u8 kind;
    c1_u8 sub_kind;
    c1_u16 pad02;
    int line;
    c1_u32 id;
    char *name;
    void *name_record;
    c1_u16 attributes;
    c1_u16 pad16;
};

typedef struct c1_byte_block c1_byte_block, *Pc1_byte_block;

struct c1_byte_block {
    c1_u8 data[2040];
    struct c1_byte_block *next;
    c1_u32 used;
};

typedef struct c1_byte_block_list c1_byte_block_list, *Pc1_byte_block_list;

struct c1_byte_block_list {
    c1_u32 used;
    c1_u8 *cur;
    struct c1_byte_block *block;
    struct c1_byte_block *first;
};

typedef struct c1_call_context c1_call_context, *Pc1_call_context;

struct c1_call_context {
    struct c1_call_context *outer;
    struct c1_type **formal;
    struct c1_symbol *callee;
    char *name;
    struct c1_type *type;
    int nformals;
    int nargs;
    int call_depth;
    c1_u8 flags;
    c1_u8 pad21[3];
};

typedef struct c1_case_list_cell c1_case_list_cell, *Pc1_case_list_cell;

typedef struct c1_case_record c1_case_record, *Pc1_case_record;

struct c1_case_record {
    struct c1_case_record *next;
    c1_u32 unk04;
    c1_u32 value_lo;
    int value_hi;
    c1_u32 label_key;
    c1_u32 unk14;
};

struct c1_case_list_cell {
    struct c1_case_list_cell *next;
    struct c1_case_record *cases;
};

typedef struct c1_constant_value c1_constant_value, *Pc1_constant_value;

struct c1_constant_value {
    struct c1_type *type;
    c1_u32 unk04;
    c1_u32 lo;
    int hi;
};

typedef struct c1_decl_specifiers c1_decl_specifiers, *Pc1_decl_specifiers;

typedef struct c1_specifier_words c1_specifier_words, *Pc1_specifier_words;

typedef union c1_specifier_symbol c1_specifier_symbol, *Pc1_specifier_symbol;

union c1_specifier_symbol {
    struct c1_symbol *sym;
    struct c1_tag_symbol *tag;
};

struct c1_specifier_words {
    c1_u8 storage;
    c1_u8 inlining;
    c1_u8 declspec;
    c1_u8 allocate;
    void *segment;
    c1_u8 flags8;
    c1_u8 pad09[3];
};

struct c1_decl_specifiers {
    struct c1_specifier_words words;
    struct c1_type *type;
    union c1_specifier_symbol named;
    void (*tag_insert)(struct c1_symbol *);
};

typedef struct c1_declaration c1_declaration, *Pc1_declaration;

typedef struct c1_type_declarator c1_type_declarator, *Pc1_type_declarator;

struct c1_type_declarator {
    struct c1_type *base;
    struct c1_type *first;
    struct c1_type *last;
    c1_u32 modifiers;
    c1_u32 modifiers2;
    c1_u8 flags14;
    c1_u8 pad15[3];
    void *params;
    struct c1_specifier_words spec;
    struct c1_symbol *sym;
    struct c1_type *type;
    c1_u8 flags30;
    c1_u8 pad31[3];
    void *name;
};

struct c1_declaration {
    void *name;
    struct c1_type_declarator *declarator;
    struct c1_type *type;
    struct c1_specifier_words spec;
    int position;
    struct c1_tag_symbol *owner;
    struct c1_symbol *sym;
    int context;
    c1_u16 tag_kind;
    c1_u8 width;
    c1_u8 unk2b;
    c1_u8 flags2c;
    c1_u8 flags2d;
    c1_u8 flags2e;
    c1_u8 flags2f;
};

typedef struct c1_declspec_attribute c1_declspec_attribute, *Pc1_declspec_attribute;

struct c1_declspec_attribute {
    char *name;
    int kind;
    int value;
    int has_argument;
};

typedef struct c1_diag_format_frame c1_diag_format_frame, *Pc1_diag_format_frame;

typedef struct fe_message fe_message, *Pfe_message;

typedef struct fe_line_map_row fe_line_map_row, *Pfe_line_map_row;

typedef union c1_diag_token_cell c1_diag_token_cell, *Pc1_diag_token_cell;

typedef struct sehtable_entry sehtable_entry, *Psehtable_entry;

typedef union fe_message_arg fe_message_arg, *Pfe_message_arg;

typedef struct fe_file_record fe_file_record, *Pfe_file_record;

struct fe_line_map_row {
    int position;
    int line;
    struct fe_file_record *file;
};

union fe_message_arg {
    struct c1_symbol *sym;
    struct c1_type *type;
    char *text;
    uint value;
    char ch;
    uint half[2];
    struct fe_name *name;
};

struct sehtable_entry {
    int enclosing;
    void *filter;
    void *handler;
};

struct fe_file_record {
    struct fe_name *name;
    uchar kind;
    uchar pad05[3];
    uint key_ref;
    uint entity;
    struct fe_name *canonical_name;
    struct fe_file_record *next;
};

union c1_diag_token_cell {
    c1_u8 code;
    c1_u32 word;
};

struct fe_message {
    ushort base;
    ushort id;
    char *text;
    union fe_message_arg args[8];
};

struct c1_diag_format_frame {
    c1_u8 pad000[8];
    struct fe_message *msg;
    c1_u8 pad00c[32];
    char *append_text;
    c1_u32 append_length;
    char append_retry_ok;
    c1_u8 pad035[3];
    char append_fits;
    c1_u8 pad039[3];
    struct fe_name *s_name;
    c1_u32 p_line_position;
    struct fe_line_map_row *p_line_row;
    c1_u32 p_position;
    c1_u32 n_indent_left;
    char n_indent_fits;
    c1_u8 pad051[3];
    c1_u32 n_indent;
    char n_newline_fits;
    c1_u8 pad059[3];
    struct fe_name *c_name;
    struct c1_type *b_base_cursor;
    char c_char;
    c1_u8 pad065[3];
    char c_fits;
    c1_u8 pad069[3];
    c1_u32 literal_length;
    c1_u8 *literal_start;
    c1_u8 pad074[8];
    struct c1_type *t_type;
    c1_u32 s_position;
    struct c1_symbol *s_symbol;
    int p_file_position;
    struct fe_message p_message;
    int m_string_id;
    union c1_diag_token_cell l_token;
    struct fe_name *i_name;
    c1_u32 o_error;
    char *o_text;
    c1_u32 e_error;
    int errno_value;
    c1_u32 d_position;
    struct c1_symbol *d_symbol;
    c1_u32 c_position;
    struct c1_symbol *c_symbol;
    struct c1_type *b_type;
    char directive;
    c1_u8 pad105[3];
    c1_u32 int64_lo;
    c1_u32 int64_hi;
    c1_u32 int_value;
    char see_declaration;
    c1_u8 pad115[3];
    int radix;
    char number_text[64];
    int arg_index;
    char *piece;
    c1_u8 *cursor;
    void *seh_saved_esp;
    void *seh_exception_pointers;
    void *seh_next;
    void *seh_handler;
    struct sehtable_entry *seh_scope_table;
    int seh_try_level;
};

typedef struct c1_emitter_suspend c1_emitter_suspend, *Pc1_emitter_suspend;

typedef struct c1_il_emitter c1_il_emitter, *Pc1_il_emitter;

typedef struct c1_il_emitter_vtbl c1_il_emitter_vtbl, *Pc1_il_emitter_vtbl;

struct c1_il_emitter_vtbl {
    void (*finish)(void);
    void (*flush)(void);
    void (*end_block)(void);
    void (*begin_block)(void);
    void (*end_module)(void);
    void (*end_module_if)(void);
    void (*begin_module)(void);
    void (*reference_symbol)(void);
    void (*define_symbol)(struct c1_il_emitter *, struct c1_symbol *);
    void (*reference_macro)(void);
    void (*define_macro)(struct c1_il_emitter *, int *);
    void (*input_refilled)(void);
    void (*set_owner)(void);
    void (*record_11)(void);
    void (*abort)(void);
    void (*pch_name)(void);
    void (*pch_mark)(void);
    void (*open)(void);
    char (*reopen)(struct c1_il_emitter *);
    void (*region_boundary)(void);
    uint (*entity_id)(struct c1_il_emitter *, struct c1_symbol *);
    void (*assign_entity_id)(struct c1_il_emitter *, uint *, uint);
    void (*discard)(void);
    void (*begin_region)(void);
};

struct c1_il_emitter {
    struct c1_il_emitter_vtbl *vtbl;
};

struct c1_emitter_suspend {
    c1_u8 active;
    c1_u8 browse_on;
    c1_u16 pad02;
    int depth;
    struct c1_il_emitter *saved;
};

typedef struct _iobuf _iobuf, *P_iobuf;

typedef struct _iobuf FILE;

typedef int (*c1_fputc_fn)(int, FILE *);

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef uint (*c1_fwrite_fn)(void *, uint, uint, FILE *);

typedef struct c1_hash_scope c1_hash_scope, *Pc1_hash_scope;

typedef struct c1_hash_scope_vtbl c1_hash_scope_vtbl, *Pc1_hash_scope_vtbl;

struct c1_hash_scope {
    struct c1_hash_scope_vtbl *vtbl;
};

struct c1_hash_scope_vtbl {
    bool (*has_entries)(struct c1_scope_object *);
    void (*insert)(struct c1_scope_object *, struct c1_symbol *);
    c1_scope_lookup * (*lookup)(struct c1_scope_object *, int);
    c1_tag_lookup * (*lookup_tag)(struct c1_scope_object *, void *);
    c1_scope_lookup * (*lookup_by_kind)(struct c1_scope_object *, void *);
    void (*lookup_anonymous_member)(struct c1_scope_object *, void *, int *);
    int * (*find_link)(struct c1_scope_object *, int *);
    void (*pch_fixup)(struct c1_scope_object *);
    void (*emit_il)(struct c1_scope_object *);
    void (*link)(struct c1_scope_object *, struct c1_symbol *);
};

typedef struct c1_idb c1_idb, *Pc1_idb;

typedef struct c1_idb_vtbl c1_idb_vtbl, *Pc1_idb_vtbl;

typedef struct c1_idb_state c1_idb_state, *Pc1_idb_state;

typedef struct fe_idb_include_stack fe_idb_include_stack, *Pfe_idb_include_stack;

typedef struct Map_DWORD_DWORD Map_DWORD_DWORD, *PMap_DWORD_DWORD;

typedef struct fe_idb_include_state fe_idb_include_state, *Pfe_idb_include_state;

typedef struct fe_idb_browse_table fe_idb_browse_table, *Pfe_idb_browse_table;

typedef struct ISet ISet, *PISet;

typedef struct PDB PDB, *PPDB;

typedef struct c1_source_tracker_iface c1_source_tracker_iface, *Pc1_source_tracker_iface;

typedef struct NameMap NameMap, *PNameMap;

typedef struct Stream Stream, *PStream;

typedef struct Array_DWORD Array_DWORD, *PArray_DWORD;

typedef struct fe_idb_region_array fe_idb_region_array, *Pfe_idb_region_array;

typedef struct fe_idb_region fe_idb_region, *Pfe_idb_region;

typedef struct fe_idb_class_record fe_idb_class_record, *Pfe_idb_class_record;

typedef struct MREFile MREFile, *PMREFile;

typedef struct fe_idb_browse_entry fe_idb_browse_entry, *Pfe_idb_browse_entry;

typedef struct PDB_vtbl PDB_vtbl, *PPDB_vtbl;

typedef ulong INTV;

typedef ulong IMPV;

typedef long EC;

typedef ulong SIG;

typedef ulong AGE;

typedef struct DBI DBI, *PDBI;

typedef struct TPI TPI, *PTPI;

typedef struct Enum Enum, *PEnum;

typedef int (*PFNfReadPDBRawBytes)(void *, long);

typedef int (*PfnFindDebugInfoFile)(void *);

typedef struct c1_source_tracker_iface_vtbl c1_source_tracker_iface_vtbl, *Pc1_source_tracker_iface_vtbl;

typedef struct NameMap_vtbl NameMap_vtbl, *PNameMap_vtbl;

typedef ulong NI;

typedef struct Stream_vtbl Stream_vtbl, *PStream_vtbl;

typedef struct MREFile_vtbl MREFile_vtbl, *PMREFile_vtbl;

typedef struct MREBag MREBag, *PMREBag;

typedef struct DBI_vtbl DBI_vtbl, *PDBI_vtbl;

typedef struct Mod Mod, *PMod;

typedef struct GSI GSI, *PGSI;

typedef struct SO SO, *PSO;

typedef uchar ITSM;

typedef ulong TI;

typedef enum DBGTYPE {
    dbgtypeFPO=0,
    dbgtypeException=1,
    dbgtypeFixup=2,
    dbgtypeOmapToSrc=3,
    dbgtypeOmapFromSrc=4,
    dbgtypeSectionHdr=5
} DBGTYPE;

typedef struct Dbg Dbg, *PDbg;

typedef struct LinkInfo LinkInfo, *PLinkInfo;

typedef struct TPI_vtbl TPI_vtbl, *PTPI_vtbl;

typedef ushort TI16;

typedef struct Enum_vtbl Enum_vtbl, *PEnum_vtbl;

typedef struct MREBag_vtbl MREBag_vtbl, *PMREBag_vtbl;

typedef struct Mod_vtbl Mod_vtbl, *PMod_vtbl;

typedef struct GSI_vtbl GSI_vtbl, *PGSI_vtbl;

typedef struct EnumThunk EnumThunk, *PEnumThunk;

typedef struct Dbg_vtbl Dbg_vtbl, *PDbg_vtbl;

typedef struct EnumThunk_vtbl EnumThunk_vtbl, *PEnumThunk_vtbl;

struct Enum {
    struct Enum_vtbl *vtbl;
};

struct EnumThunk_vtbl {
    void (*release)(struct EnumThunk *);
    void (*reset)(struct EnumThunk *);
    int (*next)(struct EnumThunk *);
    void (*get)(struct EnumThunk *, ushort *, long *, long *);
};

struct c1_source_tracker_iface_vtbl {
    char (*take)(struct c1_source_tracker_iface *, uint *, int *);
    char (*seek)(struct c1_source_tracker_iface *, int, uint *, int *);
    void (*reset)(struct c1_source_tracker_iface *);
};

struct NameMap_vtbl {
    int (*close)(struct NameMap *);
    int (*reinitialize)(struct NameMap *);
    int (*getNi)(struct NameMap *, char *, NI *);
    int (*getName)(struct NameMap *, NI, char **);
    int (*getEnumNameMap)(struct NameMap *, struct Enum **);
    int (*contains)(struct NameMap *, char *, NI *);
    int (*commit)(struct NameMap *);
    int (*isValidNi)(struct NameMap *, NI);
};

struct fe_idb_browse_table {
    struct fe_idb_browse_entry *data;
    uint count;
    uint capacity;
};

struct c1_source_tracker_iface {
    struct c1_source_tracker_iface_vtbl *vtbl;
    uint signature;
    int count;
    char *mark;
};

struct MREFile {
    struct MREFile_vtbl *vtbl;
};

struct Dbg {
    struct Dbg_vtbl *vtbl;
};

struct DBI {
    struct DBI_vtbl *vtbl;
};

struct TPI {
    struct TPI_vtbl *vtbl;
};

struct c1_idb_vtbl {
    int (*idb_commit)(struct c1_idb_state *);
    uint (*idb_release)(struct c1_idb_state *);
    void (*idb_begin_unit)(struct c1_idb_state *, int *);
    void (*idb_begin_unit_no_check)(struct c1_idb_state *, int *);
    int (*idb_begin_source_file)(struct c1_idb_state *);
    uint (*idb_function_begin)(struct c1_idb_state *, uint, uint, int, int *, int *, short *, int *);
    uint (*idb_function_end)(struct c1_idb_state *, uint, uint, int, int *, int *);
    void (*idb_note_macro_change)(struct c1_idb_state *);
    int (*idb_note_pragma)(struct c1_idb_state *, int);
    int (*idb_note_pragma_output)(struct c1_idb_state *, int);
    int (*idb_conditional_enter)(struct c1_idb_state *);
    int (*idb_conditional_leave)(struct c1_idb_state *);
    int (*idb_include_enter)(struct c1_idb_state *, char *, byte);
    int (*idb_include_leave)(struct c1_idb_state *, c1_u16);
    int (*idb_class_begin)(struct c1_idb_state *, c1_u16, int);
    int (*idb_class_end)(struct c1_idb_state *, uint, int, int *);
    int (*idb_note_warning)(struct c1_idb_state *);
    int (*idb_note_error)(struct c1_idb_state *);
    int (*idb_note_global_il_record)(struct c1_idb_state *);
    int (*idb_note_line_dependency)(struct c1_idb_state *);
    int (*idb_note_predefined_macro)(struct c1_idb_state *);
    int (*idb_check_options)(struct c1_idb_state *, int, int *);
    int (*idb_pch_written)(struct c1_idb_state *, int *);
    uint (*idb_pch_read)(struct c1_idb_state *, int *);
    void (*idb_force_recompile)(struct c1_idb_state *);
    int (*idb_note_dependency_64)(struct c1_idb_state *);
    int (*idb_note_special_members)(struct c1_idb_state *);
    int (*idb_note_first_use)(struct c1_idb_state *);
    void (*vtable_nop)(void);
    int (*idb_add_name)(struct c1_idb_state *, char *);
    int (*idb_has_name)(struct c1_idb_state *, char *);
    int (*idb_in_function)(struct c1_idb_state *);
    void (*idb_note_helper_call)(struct c1_idb_state *);
    int (*idb_helper_called)(struct c1_idb_state *);
    int (*idb_set_tracker)(struct c1_idb_state *, void *);
    int (*idb_function_body_begin)(struct c1_idb_state *, uint, int);
    int (*idb_function_body_end)(struct c1_idb_state *, uint, int, int *);
    int (*idb_tracker_note)(struct c1_idb_state *, int, int);
    int (*idb_note_layout_dependency)(struct c1_idb_state *);
    int (*idb_scope_kind3_to_4)(struct c1_idb_state *, uint, int);
    int (*idb_scope_kind4_end)(struct c1_idb_state *, uint, int);
    int (*idb_note_pragma_begin)(struct c1_idb_state *);
    int (*idb_scope_kind3_to_2)(struct c1_idb_state *, uint, int);
    int (*idb_scope_kind2_to_3)(struct c1_idb_state *, uint, int);
    void (*idb_note_access_declaration)(struct c1_idb_state *);
    void (*idb_note_decl_specifier)(struct c1_idb_state *);
    void (*idb_note_sizeof)(struct c1_idb_state *);
    int (*idb_browse_table_reset)(struct c1_idb_state *);
    int (*idb_browse_set_region)(struct c1_idb_state *, int, int, int);
    int (*idb_browse_set_lines)(struct c1_idb_state *, short, short);
    int (*idb_browse_region_count)(struct c1_idb_state *);
    int (*idb_browse_region)(struct c1_idb_state *, uint, void **);
    int (*idb_browse_truncate)(struct c1_idb_state *);
    int (*idb_invalidate)(struct c1_idb_state *);
    void (*idb_browse_set_size)(struct c1_idb_state *, int);
    int (*idb_browse_size)(struct c1_idb_state *);
    int (*idb_set_pdb_signature)(struct c1_idb_state *, int, uint);
    void (*idb_disable_incremental)(struct c1_idb_state *);
};

struct PDB_vtbl {
    INTV (*QueryInterfaceVersion)(struct PDB *);
    IMPV (*QueryImplementationVersion)(struct PDB *);
    EC (*QueryLastError)(struct PDB *, char *);
    char * (*QueryPDBName)(struct PDB *, char *);
    SIG (*QuerySignature)(struct PDB *);
    AGE (*QueryAge)(struct PDB *);
    int (*CreateDBI)(struct PDB *, char *, struct DBI **);
    int (*OpenDBI)(struct PDB *, char *, char *, struct DBI **);
    int (*OpenTpi)(struct PDB *, char *, struct TPI **);
    int (*Commit)(struct PDB *);
    int (*Close)(struct PDB *);
    int (*OpenStream)(struct PDB *, char *, struct Stream **);
    int (*GetEnumStreamNameMap)(struct PDB *, struct Enum **);
    int (*GetRawBytes)(struct PDB *, PFNfReadPDBRawBytes);
    IMPV (*QueryPdbImplementationVersion)(struct PDB *);
    int (*OpenDBIEx)(struct PDB *, char *, char *, struct DBI **, PfnFindDebugInfoFile);
    int (*CopyTo)(struct PDB *, char *, ulong, ulong);
};

struct PDB {
    struct PDB_vtbl *vtbl;
};

struct fe_idb_region_array {
    struct fe_idb_region *data;
    uint count;
    uint capacity;
};

struct DBI_vtbl {
    IMPV (*QueryImplementationVersion)(struct DBI *);
    INTV (*QueryInterfaceVersion)(struct DBI *);
    int (*OpenMod)(struct DBI *, char *, char *, struct Mod **);
    int (*DeleteMod)(struct DBI *, char *);
    int (*QueryNextMod)(struct DBI *, struct Mod *, struct Mod **);
    int (*OpenGlobals)(struct DBI *, struct GSI **);
    int (*OpenPublics)(struct DBI *, struct GSI **);
    int (*AddSec)(struct DBI *, ushort, ushort, long, long);
    int (*QueryModFromAddr)(struct DBI *, ushort, long, struct Mod **, ushort *, long *, long *);
    int (*QuerySecMap)(struct DBI *, uchar *, long *);
    int (*QueryFileInfo)(struct DBI *, uchar *, long *);
    void (*DumpMods)(struct DBI *);
    void (*DumpSecContribs)(struct DBI *);
    void (*DumpSecMap)(struct DBI *);
    int (*Close)(struct DBI *);
    int (*AddThunkMap)(struct DBI *, long *, uint, long, struct SO *, uint, ushort, long);
    int (*AddPublic)(struct DBI *, char *, ushort, long);
    int (*getEnumContrib)(struct DBI *, struct Enum **);
    int (*QueryTypeServer)(struct DBI *, ITSM, struct TPI **);
    int (*QueryItsmForTi)(struct DBI *, TI, ITSM *);
    int (*QueryNextItsm)(struct DBI *, ITSM, ITSM *);
    int (*QueryLazyTypes)(struct DBI *);
    int (*SetLazyTypes)(struct DBI *, int);
    int (*FindTypeServers)(struct DBI *, EC *, char *);
    void (*DumpTypeServers)(struct DBI *);
    int (*OpenDbg)(struct DBI *, enum DBGTYPE, struct Dbg **);
    int (*QueryDbgTypes)(struct DBI *, enum DBGTYPE *, long *);
    int (*QueryAddrForSec)(struct DBI *, ushort *, long *, ushort, long, ulong, ulong);
    int (*QuerySupportsEC)(struct DBI *);
    int (*QueryPdb)(struct DBI *, struct PDB **);
    int (*AddLinkInfo)(struct DBI *, struct LinkInfo *);
    int (*QueryLinkInfo)(struct DBI *, struct LinkInfo *, long *);
    AGE (*QueryAge)(struct DBI *);
    void * (*QueryHeader)(struct DBI *);
};

struct c1_idb {
    struct c1_idb_vtbl *vtbl;
};

struct Dbg_vtbl {
    int (*Close)(struct Dbg *);
    long (*QuerySize)(struct Dbg *);
    void (*Reset)(struct Dbg *);
    int (*Skip)(struct Dbg *, ulong);
    int (*QueryNext)(struct Dbg *, ulong, void *);
    int (*Find)(struct Dbg *, void *);
    int (*Clear)(struct Dbg *);
    int (*Append)(struct Dbg *, ulong, void *);
    int (*ReplaceNext)(struct Dbg *, ulong, void *);
};

struct Stream {
    struct Stream_vtbl *vtbl;
};

struct fe_idb_include_stack {
    struct fe_idb_include_state *data;
    uint count;
    uint capacity;
};

struct GSI {
    struct GSI_vtbl *vtbl;
};

struct SO {
    long off;
    ushort isect;
    ushort pad;
};

struct fe_idb_class_record {
    uint class_ni;
    uint first_region;
    uint unk08;
    uint depth;
    uint change;
};

struct fe_idb_region {
    uint signature;
    int length;
    ushort start_line;
    ushort line_count;
    uchar flags;
    uchar pad0d[3];
};

struct fe_idb_include_state {
    struct fe_idb_region_array regions;
    uint cursor;
    struct fe_idb_region current;
    struct fe_idb_class_record pending_class;
    struct MREFile *tracker;
    uint name_ni;
    int mtime;
    uint unk40;
    uchar changed;
    uchar untracked;
    uchar pad46[2];
};

struct EnumThunk {
    struct EnumThunk_vtbl *vtbl;
};

struct MREBag {
    struct MREBag_vtbl *vtbl;
};

struct Mod_vtbl {
    INTV (*QueryInterfaceVersion)(struct Mod *);
    IMPV (*QueryImplementationVersion)(struct Mod *);
    int (*AddTypes)(struct Mod *, uchar *, long);
    int (*AddSymbols)(struct Mod *, uchar *, long);
    int (*AddPublic)(struct Mod *, char *, ushort, long);
    int (*AddLines)(struct Mod *, char *, ushort, long, long, long, ushort, uchar *, long);
    int (*AddSecContrib)(struct Mod *, ushort, long, long, ulong);
    int (*QueryCBName)(struct Mod *, long *);
    int (*QueryName)(struct Mod *, char *, long *);
    int (*QuerySymbols)(struct Mod *, uchar *, long *);
    int (*QueryLines)(struct Mod *, uchar *, long *);
    int (*SetPvClient)(struct Mod *, void *);
    int (*GetPvClient)(struct Mod *, void **);
    int (*QuerySecContrib)(struct Mod *, ushort *, long *, long *, ulong *);
    int (*QueryImod)(struct Mod *, ushort *);
    int (*QueryDBI)(struct Mod *, struct DBI **);
    int (*Close)(struct Mod *);
    int (*QueryCBFile)(struct Mod *, long *);
    int (*QueryFile)(struct Mod *, char *, long *);
    int (*QueryTpi)(struct Mod *, struct TPI **);
    int (*AddSecContribEx)(struct Mod *, ushort, long, long, ulong, ulong, ulong);
    int (*QueryItsm)(struct Mod *, ushort *);
    int (*QuerySrcFile)(struct Mod *, char *, long *);
    int (*QuerySupportsEC)(struct Mod *);
};

struct Array_DWORD {
    ulong *rgt;
    uint itMac;
    uint itMax;
};

struct ISet {
    struct Array_DWORD rgw;
};

struct Map_DWORD_DWORD {
    struct Array_DWORD rgd;
    struct Array_DWORD rgr;
    struct ISet isetPresent;
    struct ISet isetDeleted;
    uint cdr;
};

struct c1_idb_state {
    struct c1_idb_vtbl *vtbl;
    int incremental;
    int second_pdb;
    int read_second_pdb;
    int state;
    int recompile;
    int open_conditionals;
    int invalidated;
    int force_tracking;
    struct fe_idb_include_stack include_stack;
    struct Map_DWORD_DWORD file_times;
    c1_u32 pch_generation_used;
    c1_u32 pch_generation;
    struct Map_DWORD_DWORD dependencies;
    struct Map_DWORD_DWORD dependencies_2;
    struct fe_idb_include_state file;
    struct fe_idb_browse_table browse_regions;
    c1_u32 pch_generation_seen;
    c1_u32 options_signature;
    c1_u32 unk130;
    c1_u32 browse_size;
    struct ISet names;
    struct Map_DWORD_DWORD unit_files;
    struct PDB *pdb;
    struct PDB *pdb_2;
    struct c1_source_tracker_iface *tracker;
    struct NameMap *name_map;
    struct Stream *deps_stream;
    struct Stream *deps_stream_2;
    struct Stream *regions_stream;
    struct Stream *regions_stream_2;
    c1_u32 pdb_signature;
    c1_u32 pdb_age;
    c1_u8 in_function;
    c1_u8 helper_called;
    c1_u8 regions_disabled;
    c1_u8 pad1a3;
};

struct Mod {
    struct Mod_vtbl *vtbl;
};

struct TPI_vtbl {
    INTV (*QueryInterfaceVersion)(struct TPI *);
    IMPV (*QueryImplementationVersion)(struct TPI *);
    int (*QueryTi16ForCVRecord)(struct TPI *, uchar *, TI16 *);
    int (*QueryCVRecordForTi16)(struct TPI *, TI16, uchar *, long *);
    int (*QueryPbCVRecordForTi16)(struct TPI *, TI16, uchar **);
    TI16 (*QueryTi16Min)(struct TPI *);
    TI16 (*QueryTi16Mac)(struct TPI *);
    long (*QueryCb)(struct TPI *);
    int (*Close)(struct TPI *);
    int (*Commit)(struct TPI *);
    int (*QueryTi16ForUDT)(struct TPI *, char *, int, TI16 *);
    int (*SupportQueryTiForUDT)(struct TPI *);
    int (*fIs16bitTypePool)(struct TPI *);
    int (*QueryTiForUDT)(struct TPI *, char *, int, TI *);
    int (*QueryTiForCVRecord)(struct TPI *, uchar *, TI *);
    int (*QueryCVRecordForTi)(struct TPI *, TI, uchar *, long *);
    int (*QueryPbCVRecordForTi)(struct TPI *, TI, uchar **);
    TI (*QueryTiMin)(struct TPI *);
    TI (*QueryTiMac)(struct TPI *);
    int (*AreTypesEqual)(struct TPI *, TI, TI);
    int (*IsTypeServed)(struct TPI *, TI);
};

struct NameMap {
    struct NameMap_vtbl *vtbl;
};

struct Stream_vtbl {
    long (*QueryCb)(struct Stream *);
    int (*Read)(struct Stream *, long, void *, long *);
    int (*Write)(struct Stream *, long, void *, long);
    int (*Replace)(struct Stream *, void *, long);
    int (*Append)(struct Stream *, void *, long);
    int (*Delete)(struct Stream *);
    int (*Release)(struct Stream *);
    int (*Read2)(struct Stream *, long, void *, long);
    int (*Truncate)(struct Stream *, long);
};

struct LinkInfo {
};

struct fe_idb_browse_entry {
    ushort old_first_line;
    ushort old_last_line;
    ushort first_line;
    ushort last_line;
    int sbr_offset;
};

struct MREFile_vtbl {
    int (*FOpenBag)(struct MREFile *, struct MREBag **, NI);
    int (*note_end_of_source)(struct MREFile *, ulong);
    int (*note_class_modification)(struct MREFile *, NI, ulong);
    void *slot0c;
    int (*note_line_delta)(struct MREFile *, ulong, long);
    void *slot14;
    void *slot18;
    void *slot1c;
    void *slot20;
};

struct GSI_vtbl {
    INTV (*QueryInterfaceVersion)(struct GSI *);
    IMPV (*QueryImplementationVersion)(struct GSI *);
    uchar * (*NextSym)(struct GSI *, uchar *);
    uchar * (*HashSym)(struct GSI *, char *, uchar *);
    uchar * (*NearestSym)(struct GSI *, ushort, long, long *);
    int (*Close)(struct GSI *);
    int (*getEnumThunk)(struct GSI *, ushort, long, struct EnumThunk **);
};

struct Enum_vtbl {
    void (*release)(struct Enum *);
    void (*reset)(struct Enum *);
    int (*next)(struct Enum *);
};

struct MREBag_vtbl {
    void *FAddDep;
    int (*FClose)(struct MREBag *);
};

typedef struct c1_idb_base c1_idb_base, *Pc1_idb_base;

typedef struct c1_idb_base_vtbl c1_idb_base_vtbl, *Pc1_idb_base_vtbl;

struct c1_idb_base {
    struct c1_idb_base_vtbl *vtbl;
};

struct c1_idb_base_vtbl {
    void *slot00;
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
    void *slot18;
    void *slot1c;
    void *slot20;
    void *slot24;
    void *slot28;
    void *slot2c;
    void *slot30;
    void *slot34;
    void *slot38;
    void *slot3c;
    void *slot40;
    void *slot44;
    void *slot48;
    void *slot4c;
    void *slot50;
    void *slot54;
    void *slot58;
    void *slot5c;
    void *slot60;
    void *slot64;
    void *slot68;
    void *slot6c;
    void *slot70;
    void *slot74;
    void *slot78;
    void *slot7c;
    void *slot80;
    void *slot84;
    void *slot88;
    void *slot8c;
    void *slot90;
    void *slot94;
    void *slot98;
    void *slot9c;
    void *slota0;
    void *slota4;
    void *slota8;
    void *slotac;
    void *slotb0;
    void *slotb4;
    void *slotb8;
    void *slotbc;
    void *slotc0;
    void *slotc4;
    void *slotc8;
    void *slotcc;
    void *slotd0;
    void *slotd4;
    void *slotd8;
    void *slotdc;
    void *slote0;
    void *slote4;
};

typedef struct c1_idb_stub c1_idb_stub, *Pc1_idb_stub;

typedef struct c1_idb_stub_vtbl c1_idb_stub_vtbl, *Pc1_idb_stub_vtbl;

struct c1_idb_stub_vtbl {
    int (*vtable_true)(void);
    int (*idb_stub_delete)(struct c1_idb_stub *);
    int (*vtable_set_out_true)(int *);
    int (*vtable_set_out_true_2)(int *);
    int (*vtable_true_2)(void);
    uint (*idb_stub_function_begin)(struct c1_idb_stub *, uint, uint, int, uint *, int *, ushort *, uint *);
    uint (*idb_stub_function_end)(struct c1_idb_stub *, uint, uint, uint, uint *, uint *);
    int (*vtable_true_3)(void);
    int (*vtable_true_arg1)(int);
    int (*vtable_true_arg1_2)(int);
    int (*vtable_true_4)(void);
    int (*vtable_true_5)(void);
    int (*vtable_true_arg2)(int, int);
    int (*vtable_true_arg1_3)(int);
    int (*vtable_true_arg2_2)(int, int);
    uint (*idb_stub_clear_third_out)(struct c1_idb_stub *, uint, uint, uint *);
    int (*vtable_true_6)(void);
    int (*vtable_true_7)(void);
    int (*vtable_true_8)(void);
    int (*vtable_true_9)(void);
    int (*vtable_true_10)(void);
    uint (*idb_stub_check_options)(struct c1_idb_stub *, int, uint *);
    int (*vtable_set_out_true_3)(int *);
    int (*vtable_set_out_true_4)(int *);
    void (*vtable_nop)(void);
    int (*vtable_true_11)(void);
    int (*vtable_true_12)(void);
    int (*vtable_true_13)(void);
    void (*vtable_nop_2)(void);
    int (*vtable_true_arg1_4)(int);
    int (*vtable_true_arg1_5)(int);
    int (*vtable_false)(void);
    int (*vtable_true_14)(void);
    int (*vtable_false_2)(void);
    int (*vtable_true_arg1_6)(int);
    int (*vtable_true_arg2_3)(int, int);
    uint (*idb_stub_clear_third_out_2)(struct c1_idb_stub *, uint, uint, uint *);
    int (*vtable_true_arg2_4)(int, int);
    int (*vtable_true_15)(void);
    int (*vtable_true_arg2_5)(int, int);
    int (*vtable_true_arg2_6)(int, int);
    int (*vtable_true_16)(void);
    int (*vtable_true_arg2_7)(int, int);
    int (*vtable_true_arg2_8)(int, int);
    int (*vtable_true_17)(void);
    int (*vtable_true_18)(void);
    int (*vtable_true_19)(void);
    int (*vtable_true_20)(void);
    int (*idb_stub_true_3)(struct c1_idb_stub *, int, int, int);
    int (*vtable_true_arg2_9)(int, int);
    int (*vtable_false_3)(void);
    int (*idb_stub_region_none)(struct c1_idb_stub *, uint, int *);
    int (*vtable_true_21)(void);
    int (*vtable_true_22)(void);
    void (*vtable_nop_arg1)(void);
    int (*vtable_false_4)(void);
    int (*vtable_true_arg2_10)(int, int);
    int (*vtable_true_23)(void);
};

struct c1_idb_stub {
    struct c1_idb_stub_vtbl *vtbl;
};

typedef struct c1_il_emitter_browse c1_il_emitter_browse, *Pc1_il_emitter_browse;

typedef struct c1_il_emitter_browse_vtbl c1_il_emitter_browse_vtbl, *Pc1_il_emitter_browse_vtbl;

struct c1_il_emitter_browse_vtbl {
    void (*finish)(struct c1_il_emitter_browse *);
    void (*flush)(void);
    void (*end_block)(void);
    void (*begin_block)(void);
    void (*end_module)(void);
    void (*end_module_if)(struct c1_il_emitter_browse *, int);
    void (*begin_module)(void);
    void (*reference_symbol)(struct c1_il_emitter_browse *, struct c1_symbol *);
    void (*define_symbol)(struct c1_il_emitter_browse *, struct c1_symbol *);
    void (*reference_macro)(struct c1_il_emitter_browse *, int *);
    void (*define_macro)(struct c1_il_emitter_browse *, uint **);
    void (*input_refilled)(void);
    void (*set_owner)(struct c1_il_emitter_browse *, struct c1_symbol *);
    void (*record_11)(void);
    void (*abort)(struct c1_il_emitter_browse *);
    void (*pch_name)(struct c1_il_emitter_browse *, char *);
    void (*pch_mark)(struct c1_il_emitter_browse *);
    void (*open)(struct c1_il_emitter_browse *);
    char (*reopen)(struct c1_il_emitter_browse *);
    void (*region_boundary)(struct c1_il_emitter_browse *);
    uint (*entity_id)(struct c1_il_emitter_browse *, struct c1_symbol *);
    void (*assign_entity_id)(struct c1_il_emitter_browse *, uint *, uint);
    void (*discard)(struct c1_il_emitter_browse *);
    void (*begin_region)(struct c1_il_emitter_browse *);
};

struct c1_il_emitter_browse {
    struct c1_il_emitter_browse_vtbl *vtbl;
};

typedef struct c1_include_alias c1_include_alias, *Pc1_include_alias;

struct c1_include_alias {
    struct c1_include_alias *next;
    char *from;
    char *to;
    char from_angle;
    char to_angle;
    c1_u16 pad0e;
};

typedef struct c1_init_level c1_init_level, *Pc1_init_level;

struct c1_init_level {
    struct c1_symbol *cursor;
    c1_u32 unk04;
    struct c1_type *type;
    c1_u32 count;
    c1_u8 flags;
    c1_u8 from_string;
    c1_u16 pad12;
};

typedef struct c1_label_cell c1_label_cell, *Pc1_label_cell;

typedef struct c1_node c1_node, *Pc1_node;

struct c1_label_cell {
    struct c1_label_cell *next;
    struct c1_node *label;
};

struct c1_node {
    c1_u8 op;
    c1_u8 kind;
    c1_u8 flags;
    c1_u8 pad03;
    struct c1_type *type;
    struct c1_node *link;
    c1_u32 unk0c;
    void *left;
    void *right;
};

typedef struct c1_lex_position_record c1_lex_position_record, *Pc1_lex_position_record;

typedef struct fe_line_map fe_line_map, *Pfe_line_map;

struct fe_line_map {
    struct fe_line_map_row *rows;
    uint count;
    uint capacity;
};

struct c1_lex_position_record {
    int position;
    struct fe_line_map map;
    struct fe_line_map_row cached_row;
};

typedef struct c1_list_cell c1_list_cell, *Pc1_list_cell;

struct c1_list_cell {
    struct c1_list_cell *next;
    void *value;
};

typedef struct c1_list_node c1_list_node, *Pc1_list_node;

struct c1_list_node {
    void *value;
    struct c1_list_node *next;
    struct c1_list_node *prev;
};

typedef struct c1_obj_10654898 c1_obj_10654898, *Pc1_obj_10654898;

typedef struct c1_vtbl_10654898 c1_vtbl_10654898, *Pc1_vtbl_10654898;

struct c1_obj_10654898 {
    struct c1_vtbl_10654898 *vtbl;
};

struct c1_vtbl_10654898 {
    char (*source_tracker_stub_true_0)(void *, int);
    char (*source_tracker_stub_true_1)(void *, int);
    void (*source_tracker_stub_nop_2)(void *);
    void (*source_tracker_stub_nop_3)(void *);
    void (*idb_object_delete)(struct c1_obj_10654898 *);
    void (*source_tracker_stub_nop_5)(void *, void *, int);
};

typedef struct c1_obj_1065b190 c1_obj_1065b190, *Pc1_obj_1065b190;

typedef struct c1_vtbl_1065b190 c1_vtbl_1065b190, *Pc1_vtbl_1065b190;

typedef struct c1_source_tracker c1_source_tracker, *Pc1_source_tracker;

struct c1_vtbl_1065b190 {
    char (*source_tracker_push)(struct c1_source_tracker *, int);
    char (*source_tracker_pop)(struct c1_source_tracker *, int);
    void (*source_tracker_accumulate)(struct c1_source_tracker *);
    void (*source_tracker_mark)(struct c1_source_tracker *);
    void (*source_tracker_delete)(struct c1_source_tracker *);
    void (*source_tracker_add_bytes)(struct c1_source_tracker *, void *, int);
};

struct c1_source_tracker {
    struct c1_vtbl_1065b190 *vtbl;
    void *iface_vtbl;
    uint signature;
    int count;
    char *mark;
};

struct c1_obj_1065b190 {
    struct c1_vtbl_1065b190 *vtbl;
};

typedef struct c1_obj_1065b4b4 c1_obj_1065b4b4, *Pc1_obj_1065b4b4;

typedef struct c1_vtbl_1065b4b4 c1_vtbl_1065b4b4, *Pc1_vtbl_1065b4b4;

typedef struct c1_pch_segment c1_pch_segment, *Pc1_pch_segment;

typedef void *HANDLE;

typedef struct c1_vtbl_1065b500 c1_vtbl_1065b500, *Pc1_vtbl_1065b500;

typedef struct fe_arena fe_arena, *Pfe_arena;

typedef struct c1_pch_image c1_pch_image, *Pc1_pch_image;

typedef struct fe_arena_desc fe_arena_desc, *Pfe_arena_desc;

struct c1_vtbl_1065b4b4 {
    void *slot00;
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
    void (*pch_segment_write_base_header)(struct c1_pch_segment *, HANDLE);
    void *slot1c;
    void *slot20;
    void *slot24;
    void *slot28;
    void *slot2c;
    void *slot30;
    void *slot34;
    void *slot38;
};

struct c1_pch_segment {
    struct c1_vtbl_1065b500 *vtbl;
    c1_u32 header_offset;
    int kind;
    int state;
    struct c1_pch_image *owner;
    c1_u32 file_offset;
    c1_u8 *base;
    c1_u32 size;
    void *saved_bitmap;
    c1_u32 descriptor_word;
    c1_u8 *address;
    void *mapping;
    void *file;
    c1_u8 *block;
    c1_u8 allocated;
    c1_u8 pad39[3];
    void *reloc_bitmap;
    int delta;
    c1_u8 *saved_end;
    c1_u8 *loaded_end;
};

struct fe_arena_desc {
    uint id;
    uint reserve_size;
    uint granule;
    uchar flags;
    uchar pad0d[3];
    uint pch_word;
};

struct c1_obj_1065b4b4 {
    struct c1_vtbl_1065b4b4 *vtbl;
};

struct fe_arena {
    uchar *cur;
    uchar *end;
    uchar *base;
    uint committed;
    struct fe_arena_desc *desc;
    uint limit;
    uint unk18;
    uchar mapped;
    uchar pad1d[3];
};

struct c1_pch_image {
    int count;
    struct c1_pch_segment *root;
    struct c1_pch_segment **segments;
    c1_u32 end_offset;
    char *file_name;
    c1_u32 directory_offset;
    void *file;
    void *mapping;
    void *mapping_kept;
    void *handle24;
    void *handle28;
    void *handle2c;
    void *handle30;
    int next_index;
    struct fe_arena *relocation_arena;
    struct c1_pch_segment **saved_page_table;
    struct c1_pch_segment **loaded_page_table;
};

struct c1_vtbl_1065b500 {
    int (*pch_segment_map_view)(struct c1_pch_segment *, void *, char, void *);
    int (*pch_segment_alloc_at_base)(struct c1_pch_segment *, void *);
    int (*pch_segment_alloc_anywhere)(struct c1_pch_segment *, void *, int);
    void (*pch_segment_release)(struct c1_pch_segment *);
    void (*pch_segment_append_to_file)(struct c1_pch_segment *, HANDLE);
    void (*pch_segment_write_contents)(struct c1_pch_segment *, uint);
    void (*pch_arena_segment_write_header)(struct c1_pch_segment *, HANDLE);
    void (*pch_segment_create_reloc_bitmap)(struct c1_pch_segment *, struct fe_arena *);
    char (*pch_segment_open_reloc_bitmap)(struct c1_pch_segment *, struct c1_pch_segment *);
    void (*pch_segment_apply_relocations)(struct c1_pch_segment *, struct c1_pch_image *);
    c1_pch_segment * (*pch_segment_self)(struct c1_pch_segment *);
    uint (*pch_segment_descriptor_word)(struct c1_pch_segment *);
    void * (*pch_segment_base)(struct c1_pch_segment *);
    void * (*pch_segment_loaded_address)(struct c1_pch_segment *);
    uint (*pch_segment_size)(struct c1_pch_segment *);
};

typedef struct c1_obj_1065b500 c1_obj_1065b500, *Pc1_obj_1065b500;

struct c1_obj_1065b500 {
    struct c1_vtbl_1065b500 *vtbl;
};

typedef char * (*c1_option_next_fn)(void);

typedef struct c1_param_list_entry c1_param_list_entry, *Pc1_param_list_entry;

struct c1_param_list_entry {
    struct c1_param_list_entry *next;
    struct c1_param_list list;
};

typedef struct c1_pch_options c1_pch_options, *Pc1_pch_options;

struct c1_pch_options {
    c1_u8 opt_ZE;
    c1_u8 pad01[3];
    c1_u8 ms_extensions;
    c1_u8 opt_ZBe;
    c1_u8 pad06[2];
    int integral_max_bytes;
    c1_u8 opt_Gr;
    c1_u8 opt_Jd;
    c1_u8 opt_J_unsigned_char;
    c1_u8 opt_vmb;
    c1_u8 opt_vmg;
    c1_u8 opt_vms;
    c1_u8 opt_vmm;
    c1_u8 opt_vmv;
    c1_u8 opt_vd;
    c1_u8 pad15[3];
    int opt_MD;
    int opt_MT;
    c1_u8 opt_Gc;
    c1_u8 opt_Zi;
    c1_u8 pch_debug_in_object;
    c1_u8 pad23;
    c1_u16 name_sizes[2];
    c1_u8 opt_EP;
    c1_u8 opt_pf;
    c1_u8 pad2a[2];
    int autoinline_tuple_limit;
    c1_u8 opt_Brepro;
    c1_u8 pad31;
    c1_u8 opt_Oi;
    c1_u8 opt_Gs;
    c1_u8 pad34[8];
    int opt_Gd;
    int opt_Gz;
    c1_u8 opt_Gf;
    c1_u8 string_pooling;
    c1_u8 opt_GF;
    c1_u8 string_pooling_readonly;
    c1_u8 opt_cbstring;
    c1_u8 pad49[3];
    int opt_G_cpu;
    c1_u8 opt_GM;
    c1_u8 pad51[3];
    int inline_level;
    c1_u8 browse_info;
    c1_u8 browse_full;
    c1_u8 pad5a[2];
    c1_u32 optimize_word;
    c1_u8 unk60;
    c1_u8 opt_FD;
    c1_u8 minimal_rebuild;
    c1_u8 pragma_check_stack;
    c1_u8 opt_Ot;
    c1_u8 opt_Oa;
    c1_u8 opt_Ow;
    c1_u8 opt_Og;
    c1_u8 opt_Op;
    c1_u8 opt_Oy;
    c1_u8 debug_types_in_pdb;
    char pdb_file_name[256];
    char yl_name[256];
    char header_file_name[260];
    c1_u8 opt_Oq;
    c1_u8 opt_Oq_effective;
    c1_u8 opt_Ov;
    c1_u8 pad372[2];
    int pdb_signature;
    int idb_signature;
    c1_u8 c9il_mode;
    c1_u8 opt_Gi;
    c1_u8 opt_GI;
    c1_u8 pad37f;
    c1_u8 opt_GFR;
    c1_u8 split_pdbs;
    c1_u8 opt_NoEHForNew;
    c1_u8 opt_ZI;
};

typedef void (*c1_pch_relocator)(void);

typedef struct c1_pdb_source_file c1_pdb_source_file, *Pc1_pdb_source_file;

struct c1_pdb_source_file {
    char *name;
    struct MREFile *object;
    struct c1_pdb_source_file *next;
    c1_u8 by_handle;
    c1_u8 pad0d[3];
};

typedef struct c1_pdb_state c1_pdb_state, *Pc1_pdb_state;

typedef struct MREngine MREngine, *PMREngine;

typedef struct MRECmp MRECmp, *PMRECmp;

typedef struct fe_pdb_blob_table fe_pdb_blob_table, *Pfe_pdb_blob_table;

typedef struct MREngine_vtbl MREngine_vtbl, *PMREngine_vtbl;

typedef struct MREDrv MREDrv, *PMREDrv;

typedef struct MREUtil MREUtil, *PMREUtil;

typedef struct MRECmp_vtbl MRECmp_vtbl, *PMRECmp_vtbl;

typedef struct fe_pdb_blob_entry fe_pdb_blob_entry, *Pfe_pdb_blob_entry;

typedef struct MREDrv_vtbl MREDrv_vtbl, *PMREDrv_vtbl;

typedef struct MREUtil_vtbl MREUtil_vtbl, *PMREUtil_vtbl;

struct MREDrv {
    struct MREDrv_vtbl *vtbl;
};

struct MREUtil {
    struct MREUtil_vtbl *vtbl;
};

struct c1_pdb_state {
    struct PDB *pdb;
    struct NameMap *name_map;
    struct TPI *tpi;
    struct MREngine *mre;
    struct MRECmp *mre_driver;
    struct fe_pdb_blob_table *stream_table;
    c1_u8 read_only;
    c1_u8 pad19[3];
};

struct MRECmp_vtbl {
    int (*FRelease)(struct MRECmp *);
    int (*FOpenCompiland)(struct MRECmp *, struct MREFile **, char *, char *);
    int (*FCloseCompiland)(struct MRECmp *, struct MREFile *, int);
    int (*FPushFile)(struct MRECmp *, struct MREFile **, char *, void *);
    MREFile * (*PmrefilePopFile)(struct MRECmp *);
    int (*store_pch_deps)(struct MRECmp *, void *);
    int (*restore_pch_deps)(struct MRECmp *, void *);
    void (*ClassIsBoring)(struct MRECmp *, NI);
};

struct MREngine_vtbl {
    int (*FDelete)(struct MREngine *);
    int (*FClose)(struct MREngine *, int);
    void *slot08;
    void *slot0c;
    int (*QueryMreDrv)(struct MREngine *, struct MREDrv **);
    int (*QueryMreCmp)(struct MREngine *, struct MRECmp **, struct TPI *);
    int (*QueryMreUtil)(struct MREngine *, struct MREUtil **);
    int (*commit)(struct MREngine *);
};

struct fe_pdb_blob_entry {
    struct fe_pdb_blob_entry *next;
    char *name;
    uint size;
    void *data;
};

struct MREUtil_vtbl {
    int (*FRelease)(struct MREUtil *);
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
};

struct MRECmp {
    struct MRECmp_vtbl *vtbl;
};

struct MREngine {
    struct MREngine_vtbl *vtbl;
};

struct fe_pdb_blob_table {
    struct Stream *stream;
    uchar dirty;
    uchar pad05[3];
    struct fe_pdb_blob_entry *entries;
    int count;
};

struct MREDrv_vtbl {
    int (*FRelease)(struct MREDrv *);
    int (*FRefreshFileSysInfo)(struct MREDrv *);
    int (*FSuccessfulCompile)(struct MREDrv *, int, char *, char *);
    void *YnmFileOutOfDate;
    void *FFilesOutOfDate;
    int (*FUpdateTargetFile)(struct MREDrv *, char *, int);
    void (*OneTimeInit)(struct MREDrv *);
};

typedef struct c1_pragma_optimize_letter c1_pragma_optimize_letter, *Pc1_pragma_optimize_letter;

struct c1_pragma_optimize_letter {
    char letter;
    char on_value;
    c1_u16 pad02;
    char *flag;
};

typedef struct c1_pushed_macro c1_pushed_macro, *Pc1_pushed_macro;

struct c1_pushed_macro {
    struct fe_name *name;
    struct fe_macro *definition;
    struct c1_pushed_macro *next;
    struct c1_pushed_macro *prev;
};

typedef struct c1_saved_token_stream c1_saved_token_stream, *Pc1_saved_token_stream;

typedef struct c1_token_stream_vtbl c1_token_stream_vtbl, *Pc1_token_stream_vtbl;

typedef struct c1_token c1_token, *Pc1_token;

typedef struct c1_token_stream c1_token_stream, *Pc1_token_stream;

typedef struct c1_token_cursor c1_token_cursor, *Pc1_token_cursor;

typedef union c1_yystype c1_yystype, *Pc1_yystype;

typedef struct c1_token_block c1_token_block, *Pc1_token_block;

typedef struct c1_string_value c1_string_value, *Pc1_string_value;

struct c1_token_cursor {
    struct c1_token_block *block;
    int index;
    int arena;
};

struct c1_string_value {
    char *text;
    c1_u16 length;
    c1_u16 flags;
};

union c1_yystype {
    void *ptr;
    longlong value;
    struct c1_string_value string;
    struct c1_node *node;
    struct c1_decl_specifiers spec;
    struct c1_declaration *decl;
    c1_u16 half;
    struct c1_symbol *sym;
    struct fe_name *name;
    c1_u32 words[6];
    struct c1_constant_value constant;
};

struct c1_saved_token_stream {
    struct c1_token_stream_vtbl *vtbl;
    int position;
    int position_end;
    struct c1_token_cursor start;
    struct c1_token_cursor read;
    struct c1_token_cursor write;
    int arena;
    c1_u8 flags;
    c1_u8 pad35[3];
};

struct c1_token_block {
    struct c1_token_block *next;
    c1_u8 *slot[31];
};

struct c1_token_stream_vtbl {
    c1_token * (*next)(struct c1_saved_token_stream *);
    c1_token * (*peek)(struct c1_saved_token_stream *);
    void (*unget)(struct c1_saved_token_stream *, struct c1_token *);
    void (*append)(struct c1_saved_token_stream *, struct c1_token *);
    int (*at_end)(void);
    void (*start)(struct c1_saved_token_stream *);
    c1_token_stream * (*scalar_deleting_dtor)(struct c1_token_stream *, byte);
};

struct c1_token {
    c1_u8 code;
    c1_u8 pad01[3];
    c1_u32 unk04;
    union c1_yystype value;
};

struct c1_token_stream {
    struct c1_token_stream_vtbl *vtbl;
};

typedef struct c1_scope_stack c1_scope_stack, *Pc1_scope_stack;

struct c1_scope_stack {
    struct c1_scope_object *file_scope;
    struct c1_scope_object *current;
    struct c1_scope_object *objects[128];
    c1_u8 depth;
    c1_u8 unk209;
    c1_u8 pad20a[2];
    c1_u32 unk20c;
    c1_u32 unk210;
    struct fe_file_record *file_records;
};

typedef struct c1_source_stream c1_source_stream, *Pc1_source_stream;

typedef struct c1_source_token_stream_vtbl c1_source_token_stream_vtbl, *Pc1_source_token_stream_vtbl;

struct c1_source_token_stream_vtbl {
    c1_token * (*next)(struct c1_source_stream *);
    c1_token * (*peek)(struct c1_source_stream *);
    void (*unget)(struct c1_source_stream *, struct c1_token *);
    void (*append)(void);
    int (*at_end)(void);
    void (*start)(void);
    c1_token_stream * (*scalar_deleting_dtor)(struct c1_token_stream *, byte);
};

struct c1_source_stream {
    struct c1_source_token_stream_vtbl *vtbl;
    c1_u8 unk04[52];
    int unget_count;
    struct c1_token *unget[1];
};

typedef struct c1_source_token_stream c1_source_token_stream, *Pc1_source_token_stream;

struct c1_source_token_stream {
    struct c1_source_token_stream_vtbl *vtbl;
};

typedef struct c1_specifier_state c1_specifier_state, *Pc1_specifier_state;

struct c1_specifier_state {
    struct c1_token *token;
    struct c1_type *type;
    c1_u32 unk08;
    struct c1_token *spec_token;
    c1_u32 unk10;
    struct c1_specifier_words words;
    c1_u8 storage_given;
    c1_u8 pad21[3];
    struct c1_type *named_type;
    union c1_specifier_symbol named;
    c1_u8 type_given;
    c1_u8 pad2d[3];
    void *tag_insert;
    c1_u16 basic_type;
    c1_u16 qualifiers;
    c1_u8 size_keyword;
    c1_u8 pad39[3];
};

typedef void (*c1_static_initializer)(void);

typedef struct c1_struct_layout c1_struct_layout, *Pc1_struct_layout;

struct c1_struct_layout {
    struct c1_tag_symbol *tag;
    c1_u32 unk04;
    struct c1_type *type;
    int offset;
    c1_u16 bitfield_type;
    c1_u16 alignment;
    c1_u8 bitfield_bits;
    c1_u8 flags;
    c1_u16 pad16;
};

typedef struct c1_symbol_stack_node c1_symbol_stack_node, *Pc1_symbol_stack_node;

struct c1_symbol_stack_node {
    struct c1_symbol *sym;
    struct c1_symbol_stack_node *next;
};

typedef struct c1_symbol_vector c1_symbol_vector, *Pc1_symbol_vector;

struct c1_symbol_vector {
    c1_u16 count;
    c1_u16 capacity;
    struct c1_symbol *entries[1];
};

typedef struct c1_tag_record c1_tag_record, *Pc1_tag_record;

struct c1_tag_record {
    void *name;
    struct c1_tag_symbol *tag;
    c1_u32 unk08;
    c1_u16 kind;
    c1_u16 pad0e;
    struct c1_specifier_words words;
    struct c1_specifier_words *storage;
    void *insert;
    c1_u8 name_pending;
    c1_u8 pad25[3];
};

typedef struct c1_token_source_frame c1_token_source_frame, *Pc1_token_source_frame;

struct c1_token_source_frame {
    struct c1_saved_token_stream *stream;
    struct c1_token_source_frame *prev;
    int position;
    int kind;
    void (*on_pop)(void);
};

typedef struct c1_vector_iterator c1_vector_iterator, *Pc1_vector_iterator;

struct c1_vector_iterator {
    void *vector;
    c1_u16 index;
    c1_u16 pad06;
};

typedef struct c1_warning_default c1_warning_default, *Pc1_warning_default;

struct c1_warning_default {
    uint number;
    uint state;
};

typedef struct c1_yy_token_insertion c1_yy_token_insertion, *Pc1_yy_token_insertion;

struct c1_yy_token_insertion {
    short state;
    short token;
    short next_state;
};

typedef struct c1_yyparse_state c1_yyparse_state, *Pc1_yyparse_state;

struct c1_yyparse_state {
    struct c1_token *lookahead;
    int nerrs;
    int errflag;
    short state;
    short pad0e;
    short *ssp;
    union c1_yystype *vsp;
    union c1_yystype vs[1024];
    short ss[1024];
};

typedef short int16_t;

typedef int int32_t;

typedef longlong int64_t;

typedef char int8_t;

typedef ushort uint16_t;

typedef uint uint32_t;

typedef ulonglong uint64_t;

typedef uchar uint8_t;

typedef struct fe_bitvec fe_bitvec, *Pfe_bitvec;

struct fe_bitvec {
    struct fe_arena *arena;
    uchar in_arena;
    uchar owns_bits;
    uchar pad06[2];
    int nbits;
    uchar *bits;
    int nbytes;
    int iter_bit;
    int iter_byte;
    uchar iter_bits;
    uchar pad1d[3];
};

typedef struct fe_diag_cell fe_diag_cell, *Pfe_diag_cell;

struct fe_diag_cell {
    struct fe_message *msg;
    struct fe_diag_cell *next;
};

typedef struct fe_diag_context fe_diag_context, *Pfe_diag_context;

typedef struct fe_diag_queue fe_diag_queue, *Pfe_diag_queue;

typedef struct fe_diag_note_cell fe_diag_note_cell, *Pfe_diag_note_cell;

typedef struct fe_diag_note_object fe_diag_note_object, *Pfe_diag_note_object;

typedef struct fe_diag_note_vtbl fe_diag_note_vtbl, *Pfe_diag_note_vtbl;

struct fe_diag_note_cell {
    struct fe_diag_note_object *object;
    struct fe_diag_note_cell *next;
};

struct fe_diag_queue {
    struct fe_diag_cell *head;
    struct fe_diag_cell *tail;
};

struct fe_diag_note_object {
    struct fe_diag_note_vtbl *vtbl;
};

struct fe_diag_note_vtbl {
    void *note;
};

struct fe_diag_context {
    struct fe_diag_queue queue;
    struct fe_diag_queue *insert_list;
    struct fe_diag_cell *insert_after;
    uchar busy;
    uchar pad11[3];
    struct fe_diag_queue pending;
    struct fe_diag_note_cell *context_notes;
    int nesting;
    int state;
    int position;
    uint indent;
};

typedef struct fe_function_record_block fe_function_record_block, *Pfe_function_record_block;

struct fe_function_record_block {
    struct fe_function_record_block *next;
    struct fe_function_record records[20];
};

typedef struct fe_il_buffer fe_il_buffer, *Pfe_il_buffer;

typedef struct Buffer Buffer, *PBuffer;

typedef uchar *PB;

typedef long CB;

struct Buffer {
    PB pbStart;
    PB pbEnd;
    CB cbAlloc;
    void (*pfnMove)(void *, void *, void *);
    void *pfnMoveArg;
};

struct fe_il_buffer {
    struct Buffer bytes;
    FILE *file;
    uchar open;
    char name[260];
    uchar pad11d[3];
    int unk120;
    struct Stream *ilstore_stream;
    uchar ilstore_space;
    uchar pad129[3];
    char *ilstore_stream_name;
};

typedef struct fe_input_file fe_input_file, *Pfe_input_file;

struct fe_input_file {
    int handle;
    int position;
    struct fe_file_record *file;
    uchar *saved_input;
    uchar *buffer;
    int last_read;
    int block_offset;
    int pack;
    int cond_depth;
    uchar flags;
    uchar pad25[3];
    struct fe_input_file *next;
};

typedef struct fe_int64_words fe_int64_words, *Pfe_int64_words;

struct fe_int64_words {
    uint lo;
    int hi;
};

typedef struct fe_intrinsic_row fe_intrinsic_row, *Pfe_intrinsic_row;

struct fe_intrinsic_row {
    ushort number;
    ushort pad02;
    ushort return_code;
    ushort return_layer;
    ushort attributes;
    ushort x0a;
};

typedef struct fe_macro_frame fe_macro_frame, *Pfe_macro_frame;

struct fe_macro_frame {
    uchar *saved_input;
    short *args;
    uchar *text;
    struct fe_macro *macro;
    char arg_count;
    char next_arg;
    uchar pad12[2];
    int active;
};

typedef struct fe_message_buffer fe_message_buffer, *Pfe_message_buffer;

struct fe_message_buffer {
    char *cur;
    uint room;
    char *start;
    uchar flags;
    uchar pad0d[3];
};

typedef struct fe_misc_string fe_misc_string, *Pfe_misc_string;

struct fe_misc_string {
    uint id;
    char *text;
};

typedef struct fe_pack_cell fe_pack_cell, *Pfe_pack_cell;

struct fe_pack_cell {
    struct fe_pack_cell *next;
    int packing;
    void *ident;
};

typedef struct fe_pack_stack fe_pack_stack, *Pfe_pack_stack;

struct fe_pack_stack {
    struct fe_pack_cell *top;
    struct fe_pack_cell *free_cells;
};

typedef struct fe_pch_header fe_pch_header, *Pfe_pch_header;

struct fe_pch_header {
    char stamp[8];
    uint unk08;
    uint version;
    uint magic;
    char compiler_date[20];
    int sy_size;
    int gl_size;
    int ex_size;
    int in_size;
    int db_size;
    int browse_size;
    int pdb_copy_offset;
    int pdb_copy_size;
    int idb_copy_size;
    int records_size;
    int records_offset;
    int arenas_offset;
    int include_key;
    int include_key_alt;
    int time;
    uint flags;
};

typedef struct fe_pdb_blob_index_record fe_pdb_blob_index_record, *Pfe_pdb_blob_index_record;

struct fe_pdb_blob_index_record {
    uint name_size;
    uint name_offset;
    uint data_size;
    uint data_offset;
};

typedef struct fe_pdb_blob_stream_header fe_pdb_blob_stream_header, *Pfe_pdb_blob_stream_header;

struct fe_pdb_blob_stream_header {
    uint signature;
    int count;
    uint index_size;
    uint data_size;
};

typedef struct fe_pool fe_pool, *Pfe_pool;

struct fe_pool {
    uchar *cur;
    uint left;
    uint min_pages;
    struct fe_arena *arena;
};

typedef struct fe_pp_value fe_pp_value, *Pfe_pp_value;

struct fe_pp_value {
    ushort type;
    ushort unk02;
    uint unk04;
    struct fe_int64_words value;
};

typedef struct fe_pragma_comment fe_pragma_comment, *Pfe_pragma_comment;

struct fe_pragma_comment {
    struct fe_pragma_comment *next;
    int kind;
    char *text;
};

typedef struct fe_symtab fe_symtab, *Pfe_symtab;

typedef struct fe_symtab_entry fe_symtab_entry, *Pfe_symtab_entry;

struct fe_symtab {
    uint arena;
    uint compare;
    uint hash;
    ushort nbuckets;
    uchar flags;
    uchar pad0f;
    struct fe_symtab_entry **buckets;
    uint count;
};

struct fe_symtab_entry {
    void *key;
    void *value;
    struct fe_symtab_entry *next;
};

typedef struct fe_symtab_iter fe_symtab_iter, *Pfe_symtab_iter;

struct fe_symtab_iter {
    struct fe_symtab *tab;
    struct fe_symtab_entry *entry;
    uint next_bucket;
    void *key;
    void *value;
};

typedef struct fe_vector fe_vector, *Pfe_vector;

struct fe_vector {
    ushort count;
    ushort capacity;
    uint arena;
    void **data;
};

typedef struct fe_warning_record fe_warning_record, *Pfe_warning_record;

struct fe_warning_record {
    uint next;
    uint value;
};

typedef struct fe_warning_state fe_warning_state, *Pfe_warning_state;

struct fe_warning_state {
    char state[1000];
    int level;
    struct fe_warning_record *saved;
    struct fe_warning_state *outer;
};

typedef struct il_code_row il_code_row, *Pil_code_row;

struct il_code_row {
    char *codes;
    uint x04;
};

typedef enum il_label_role {
    il_label_user=0,
    il_label_do_top=5,
    il_label_do_break=6,
    il_label_do_continue=7,
    il_label_for_test=8,
    il_label_loop_break=11,
    il_label_loop_continue=12,
    il_label_switch_dispatch=17,
    il_label_switch_break=18,
    il_label_case=19,
    il_label_default=20,
    il_label_cond=30,
    il_label_return=31,
    il_label_goto_out=71,
    il_label_try_end=72
} il_label_role;

typedef enum il_op {
    il_op_nop01=1,
    il_op_add=2,
    il_op_sub=3,
    il_op_mul=4,
    il_op_div=5,
    il_op_mod=6,
    il_op_neg=8,
    il_op_shl=9,
    il_op_shr=10,
    il_op_and=11,
    il_op_or=12,
    il_op_xor=13,
    il_op_bnot=14,
    il_op_asg_add=15,
    il_op_asg_sub=16,
    il_op_asg_mul=17,
    il_op_asg_div=18,
    il_op_asg_mod=19,
    il_op_asg_shl=21,
    il_op_asg_shr=22,
    il_op_asg_and=23,
    il_op_asg_xor=24,
    il_op_asg_or=25,
    il_op_lnot=26,
    il_op_oror=27,
    il_op_andand=28,
    il_op_cmp_eq=31,
    il_op_cmp_ne=32,
    il_op_cmp_le=33,
    il_op_cmp_lt=34,
    il_op_cmp_ge=35,
    il_op_cmp_gt=36,
    il_op_sym=38,
    il_op_addoff=39,
    il_op_index=40,
    il_op_label=41,
    il_op_rec2a=42,
    il_op_rec2b=43,
    il_op_cvt=44,
    il_op_param=45,
    il_op_load=48,
    il_op_asg=50,
    il_op_const=51,
    il_op_cvt2=52,
    il_op_postinc=53,
    il_op_postdec=54,
    il_op_bitfield=55,
    il_op_brfalse=56,
    il_op_brtrue=57,
    il_op_goto=58,
    il_op_switch=59,
    il_op_caselist=60,
    il_op_case=61,
    il_op_call=62,
    il_op_icall=64,
    il_op_ret=65,
    il_op_cond=66,
    il_op_colon=67,
    il_op_comma=68,
    il_op_entry=70,
    il_op_exit=71,
    il_op_discard=75,
    il_op_endlist=76,
    il_op_eof=77,
    il_op_pragma=79,
    il_op_scope=83,
    il_op_endscope=84,
    il_op_arg=85,
    il_op_file=86,
    il_op_op59=89,
    il_op_loadv=90,
    il_op_exhead=91,
    il_op_eh_live=92,
    il_op_eh_unwind=93,
    il_op_eh_leave=94,
    il_op_eh_try=96,
    il_op_eh_catch=97,
    il_op_eh_trymap=98,
    il_op_ptradd=104,
    il_op_nulladj=119,
    il_op_ptrsub=139,
    il_op_seh_except=141,
    il_op_seh_finally=142,
    il_op_seh_try=143,
    il_op_seh_end=144,
    il_op_thisarg=153,
    il_op_thisarg2=154,
    il_op_ctemp=155,
    il_op_op9d=157,
    il_op_assume=160,
    il_op_xb9=185
} il_op;

typedef enum il_op_attr {
    il_attr_volatile_type=1024,
    il_attr_ends_statement=4096,
    il_attr_temp_first=32768
} il_op_attr;

typedef struct il_op_row il_op_row, *Pil_op_row;

struct il_op_row {
    uint attr;
    char *codes;
};

typedef enum il_pragma_subop {
    il_sub_x00=0,
    il_sub_line=1,
    il_sub_file=2,
    il_sub_x03=3,
    il_sub_x04=4,
    il_sub_x05=5,
    il_sub_x06=6,
    il_sub_x07=7,
    il_sub_x08=8,
    il_sub_x09=9,
    il_sub_x0a=10,
    il_sub_x0b=11,
    il_sub_x0c=12,
    il_sub_x0d=13,
    il_sub_x0e=14,
    il_sub_mark1b4=15,
    il_sub_mark1b5=16,
    il_sub_dbg1b6=17,
    il_sub_dbg1b7=18,
    il_sub_x13=19,
    il_sub_x14=20,
    il_sub_x15=21,
    il_sub_inasm=22,
    il_sub_x17=23,
    il_sub_mark1ba=24,
    il_sub_op19=25,
    il_sub_op1a=26,
    il_sub_x1b=27,
    il_sub_x1c=28,
    il_sub_x1d=29,
    il_sub_x1e=30,
    il_sub_optflags=31,
    il_sub_mark1b8=32,
    il_sub_x21=33,
    il_sub_x22=34,
    il_sub_warnings=35,
    il_sub_line24=36,
    il_sub_op25=37,
    il_sub_x26=38,
    il_sub_x27=39,
    il_sub_x28=40,
    il_sub_x29=41,
    il_sub_x2a=42,
    il_sub_x2b=43,
    il_sub_x2c=44,
    il_sub_x2d=45,
    il_sub_x2e=46,
    il_sub_x2f=47,
    il_sub_x30=48
} il_pragma_subop;

typedef enum il_symbol_class {
    il_sym_x00=0,
    il_sym_var=1,
    il_sym_gvar=2,
    il_sym_label=3,
    il_sym_func=4,
    il_sym_alias5=5,
    il_sym_end=6,
    il_sym_rec7=7,
    il_sym_rec8=8,
    il_sym_segment=9,
    il_sym_glend=10,
    il_sym_typedef=11,
    il_sym_x0c=12,
    il_sym_block=13,
    il_sym_fdef=14,
    il_sym_x0f=15,
    il_sym_fref10=16,
    il_sym_x11=17,
    il_sym_srcfile=18,
    il_sym_x13=19,
    il_sym_x14=20,
    il_sym_x15=21,
    il_sym_rec16=22,
    il_sym_pchblob=23,
    il_sym_x18=24,
    il_sym_rec19=25
} il_symbol_class;

typedef enum il_type_bits {
    il_type_kind_mask=15,
    il_type_size_mask=496,
    il_type_volatile=4096,
    il_type_const=8192,
    il_type_x4000=16384
} il_type_bits;

typedef enum il_type_kind {
    il_type_none=0,
    il_type_signed=1,
    il_type_unsigned=2,
    il_type_pointer=3,
    il_type_x4=4,
    il_type_float=5,
    il_type_aggregate=6,
    il_type_void=7,
    il_type_real=10,
    il_type_xb=11
} il_type_kind;

typedef struct ESV ESV, *PESV;

typedef struct ESV_vtbl ESV_vtbl, *PESV_vtbl;

struct ESV {
    struct ESV_vtbl *vtbl;
};

struct ESV_vtbl {
    void *Release;
    void *Reset;
    void *Next;
    void *Get;
};

typedef struct EnumContrib EnumContrib, *PEnumContrib;

typedef struct EnumContrib_vtbl EnumContrib_vtbl, *PEnumContrib_vtbl;

struct EnumContrib {
    struct EnumContrib_vtbl *vtbl;
};

struct EnumContrib_vtbl {
    void (*release)(struct EnumContrib *);
    void (*reset)(struct EnumContrib *);
    int (*next)(struct EnumContrib *);
    void (*get)(struct EnumContrib *, ushort *, ushort *, long *, long *, ulong *);
    void (*getCrcs)(struct EnumContrib *, ulong *, ulong *);
};

typedef struct EnumNameMap EnumNameMap, *PEnumNameMap;

typedef struct EnumNameMap_vtbl EnumNameMap_vtbl, *PEnumNameMap_vtbl;

struct EnumNameMap {
    struct EnumNameMap_vtbl *vtbl;
};

struct EnumNameMap_vtbl {
    void (*release)(struct EnumNameMap *);
    void (*reset)(struct EnumNameMap *);
    int (*next)(struct EnumNameMap *);
    void (*get)(struct EnumNameMap *, char **, NI *);
};

typedef struct FunctionSymbols FunctionSymbols, *PFunctionSymbols;

typedef struct FunctionSymbols_vtbl FunctionSymbols_vtbl, *PFunctionSymbols_vtbl;

struct FunctionSymbols {
    struct FunctionSymbols_vtbl *vtbl;
};

struct FunctionSymbols_vtbl {
    void *GetEnumLocals;
    void *GetEnumParams;
    void *GetFrameInfo;
    void *Release;
};

typedef struct ILMod ILMod, *PILMod;

typedef struct ILMod_vtbl ILMod_vtbl, *PILMod_vtbl;

struct ILMod_vtbl {
    int (*Release)(struct ILMod *);
    int (*Reset)(struct ILMod *);
    int (*GetIL)(struct ILMod *, ulong, uchar, void *, ulong *);
    int (*GetILVer)(struct ILMod *, ulong, ushort *);
    int (*PutIL)(struct ILMod *, ulong, uchar, PB, CB, uchar);
    void *slot14;
    void *slot18;
    int (*get_kind_il)(struct ILMod *, uchar, void *);
    int (*delete_il)(struct ILMod *, ulong, uchar);
};

struct ILMod {
    struct ILMod_vtbl *vtbl;
};

typedef struct ILStore ILStore, *PILStore;

typedef struct ILStore_vtbl ILStore_vtbl, *PILStore_vtbl;

struct ILStore {
    struct ILStore_vtbl *vtbl;
};

struct ILStore_vtbl {
    int (*Release)(struct ILStore *);
    int (*Reset)(struct ILStore *);
    int (*GetILMod)(struct ILStore *, char *, struct ILMod **);
    void *slot0c;
    int (*GetILSType)(struct ILStore *, char *, uchar *);
    int (*GetILSpace)(struct ILStore *, char *, uchar *);
};

typedef struct MreToPdb MreToPdb, *PMreToPdb;

struct MreToPdb {
    struct PDB *pdb;
    struct NameMap *name_map;
    struct TPI *tpi;
    struct PDB *types_pdb;
    ulong x10;
    ulong x14;
};

typedef enum PDBConsts {
    niNil=0,
    PDB_MAX_PATH=260,
    cbErrMax=1024
} PDBConsts;

typedef enum PDBIMPV {
    PDBImpvVC98=19970604
} PDBIMPV;

typedef enum PDBINTV {
    PDBIntv50=19960502,
    PDBIntv50a=19970116
} PDBINTV;

typedef struct SV SV, *PSV;

typedef struct SV_vtbl SV_vtbl, *PSV_vtbl;

struct SV {
    struct SV_vtbl *vtbl;
};

struct SV_vtbl {
    void *OffBP;
    void *TypeIndex;
    void *Name;
    void *Release;
};

typedef struct StreamImage StreamImage, *PStreamImage;

typedef struct StreamImage_vtbl StreamImage_vtbl, *PStreamImage_vtbl;

struct StreamImage_vtbl {
    long (*size)(struct StreamImage *);
    void * (*base)(struct StreamImage *);
    int (*noteRead)(struct StreamImage *, long, long, void **);
    int (*noteWrite)(struct StreamImage *, long, long, void **);
    int (*writeBack)(struct StreamImage *);
    int (*release)(struct StreamImage *);
};

struct StreamImage {
    struct StreamImage_vtbl *vtbl;
};

typedef struct objf_Image objf_Image, *Pobjf_Image;

struct objf_Image {
};

typedef struct objf_Library objf_Library, *Pobjf_Library;

struct objf_Library {
};

typedef struct objf_ObjectCode objf_ObjectCode, *Pobjf_ObjectCode;

struct objf_ObjectCode {
    void **vtbl;
    long x04;
};

typedef struct objf_Section objf_Section, *Pobjf_Section;

struct objf_Section {
};

typedef struct tagARRAYDESC tagARRAYDESC, *PtagARRAYDESC;

typedef struct tagARRAYDESC ARRAYDESC;

typedef struct tagTYPEDESC tagTYPEDESC, *PtagTYPEDESC;

typedef struct tagTYPEDESC TYPEDESC;

typedef struct tagSAFEARRAYBOUND tagSAFEARRAYBOUND, *PtagSAFEARRAYBOUND;

typedef struct tagSAFEARRAYBOUND SAFEARRAYBOUND;

typedef union tagTYPEDESC_u tagTYPEDESC_u, *PtagTYPEDESC_u;

typedef ushort VARTYPE;

typedef uint HREFTYPE;

union tagTYPEDESC_u {
    struct tagTYPEDESC *lptdesc;
    struct tagARRAYDESC *lpadesc;
    HREFTYPE hreftype;
};

struct tagTYPEDESC {
    union tagTYPEDESC_u u;
    VARTYPE vt;
};

struct tagSAFEARRAYBOUND {
    uint cElements;
    long lLbound;
};

struct tagARRAYDESC {
    TYPEDESC tdescElem;
    ushort cDims;
    SAFEARRAYBOUND rgbounds[1];
};

typedef wchar_t OLECHAR;

typedef OLECHAR *BSTR;

typedef enum tagCALLCONV {
    CC_FASTCALL=0,
    CC_CDECL=1,
    CC_MSCPASCAL=2,
    CC_PASCAL=2,
    CC_MACPASCAL=3,
    CC_STDCALL=4,
    CC_FPFASTCALL=5,
    CC_SYSCALL=6,
    CC_MPWCDECL=7,
    CC_MPWPASCAL=8,
    CC_MAX=9
} tagCALLCONV;

typedef enum tagCALLCONV CALLCONV;

typedef struct tagCY tagCY, *PtagCY;

typedef struct tagCY CY;

struct tagCY {
    longlong int64;
};

typedef double DATE;

typedef struct tagDEC tagDEC, *PtagDEC;

typedef struct tagDEC DECIMAL;

struct tagDEC {
    ushort wReserved;
    uchar scale;
    uchar sign;
    uint Hi32;
    ulonglong Lo64;
};

typedef long DISPID;

typedef struct tagDISPPARAMS tagDISPPARAMS, *PtagDISPPARAMS;

typedef struct tagDISPPARAMS DISPPARAMS;

typedef struct tagVARIANT tagVARIANT, *PtagVARIANT;

typedef struct tagVARIANT VARIANT;

typedef VARIANT VARIANTARG;

typedef union tagVARIANT_n1 tagVARIANT_n1, *PtagVARIANT_n1;

typedef struct __tagVARIANT __tagVARIANT, *P__tagVARIANT;

typedef union __tagVARIANT_n3 __tagVARIANT_n3, *P__tagVARIANT_n3;

typedef short VARIANT_BOOL;

typedef long SCODE;

typedef struct IUnknown IUnknown, *PIUnknown;

typedef struct IDispatch IDispatch, *PIDispatch;

typedef struct tagSAFEARRAY tagSAFEARRAY, *PtagSAFEARRAY;

typedef struct tagSAFEARRAY SAFEARRAY;

typedef struct __tagBRECORD __tagBRECORD, *P__tagBRECORD;

typedef struct IUnknownVtbl IUnknownVtbl, *PIUnknownVtbl;


typedef GUID IID;

typedef struct IDispatchVtbl IDispatchVtbl, *PIDispatchVtbl;

typedef struct IRecordInfo IRecordInfo, *PIRecordInfo;

typedef struct IRecordInfoVtbl IRecordInfoVtbl, *PIRecordInfoVtbl;

struct __tagBRECORD {
    void *pvRecord;
    struct IRecordInfo *pRecInfo;
};

union __tagVARIANT_n3 {
    long lVal;
    uchar bVal;
    short iVal;
    float fltVal;
    double dblVal;
    VARIANT_BOOL boolVal;
    SCODE scode;
    CY cyVal;
    DATE date;
    BSTR bstrVal;
    struct IUnknown *punkVal;
    struct IDispatch *pdispVal;
    SAFEARRAY *parray;
    uchar *pbVal;
    short *piVal;
    long *plVal;
    float *pfltVal;
    double *pdblVal;
    VARIANT_BOOL *pboolVal;
    SCODE *pscode;
    CY *pcyVal;
    DATE *pdate;
    BSTR *pbstrVal;
    struct IUnknown **ppunkVal;
    struct IDispatch **ppdispVal;
    SAFEARRAY **pparray;
    VARIANT *pvarVal;
    void *byref;
    char cVal;
    ushort uiVal;
    uint ulVal;
    int intVal;
    uint uintVal;
    DECIMAL *pdecVal;
    char *pcVal;
    ushort *puiVal;
    uint *pulVal;
    int *pintVal;
    uint *puintVal;
    struct __tagBRECORD brecVal;
};

struct tagSAFEARRAY {
    ushort cDims;
    ushort fFeatures;
    uint cbElements;
    uint cLocks;
    void *pvData;
    SAFEARRAYBOUND rgsabound[1];
};

struct __tagVARIANT {
    VARTYPE vt;
    ushort wReserved1;
    ushort wReserved2;
    ushort wReserved3;
    union __tagVARIANT_n3 n3;
};

union tagVARIANT_n1 {
    struct __tagVARIANT n2;
    DECIMAL decVal;
};

struct IRecordInfo {
    struct IRecordInfoVtbl *lpVtbl;
};

struct IRecordInfoVtbl {
};

struct tagDISPPARAMS {
    VARIANTARG *rgvarg;
    DISPID *rgdispidNamedArgs;
    uint cArgs;
    uint cNamedArgs;
};

struct IDispatch {
    struct IDispatchVtbl *lpVtbl;
};

struct IUnknownVtbl {
    long (*QueryInterface)(struct IUnknown *, IID *, void **);
    uint (*AddRef)(struct IUnknown *);
    uint (*Release)(struct IUnknown *);
};

struct IDispatchVtbl {
};

struct IUnknown {
    struct IUnknownVtbl *lpVtbl;
};

struct tagVARIANT {
    union tagVARIANT_n1 n1;
};

typedef struct DelayLoadInfo DelayLoadInfo, *PDelayLoadInfo;

typedef struct ImgDelayDescr ImgDelayDescr, *PImgDelayDescr;

typedef struct DelayLoadProc DelayLoadProc, *PDelayLoadProc;

typedef union IMAGE_THUNK_DATA32 IMAGE_THUNK_DATA32, *PIMAGE_THUNK_DATA32;

typedef union DelayLoadProc_u DelayLoadProc_u, *PDelayLoadProc_u;

union IMAGE_THUNK_DATA32 {
    uint *Function;
    uint Ordinal;
    void *AddressOfData;
    uchar *ForwarderString;
};

union DelayLoadProc_u {
    char *szProcName;
    uint dwOrdinal;
};

struct DelayLoadProc {
    int fImportByName;
    union DelayLoadProc_u u;
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

typedef struct tagELEMDESC tagELEMDESC, *PtagELEMDESC;

typedef struct tagELEMDESC ELEMDESC;

typedef struct tagPARAMDESC tagPARAMDESC, *PtagPARAMDESC;

typedef struct tagPARAMDESC PARAMDESC;

typedef struct tagPARAMDESCEX tagPARAMDESCEX, *PtagPARAMDESCEX;

typedef struct tagPARAMDESCEX PARAMDESCEX;

struct tagPARAMDESCEX {
    uint cBytes;
    VARIANTARG varDefaultValue;
};

struct tagPARAMDESC {
    PARAMDESCEX *pparamdescex;
    ushort wParamFlags;
};

struct tagELEMDESC {
    TYPEDESC tdesc;
    PARAMDESC paramdesc;
};

typedef struct tagEXCEPINFO tagEXCEPINFO, *PtagEXCEPINFO;

typedef struct tagEXCEPINFO EXCEPINFO;

struct tagEXCEPINFO {
    ushort wCode;
    ushort wReserved;
    BSTR bstrSource;
    BSTR bstrDescription;
    BSTR bstrHelpFile;
    uint dwHelpContext;
    void *pvReserved;
    long (*pfnDeferredFillIn)(struct tagEXCEPINFO *);
    SCODE scode;
};

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME FILETIME;

struct _FILETIME {
    uint dwLowDateTime;
    uint dwHighDateTime;
};

typedef struct tagFUNCDESC tagFUNCDESC, *PtagFUNCDESC;

typedef struct tagFUNCDESC FUNCDESC;

typedef DISPID MEMBERID;

typedef enum tagFUNCKIND {
    FUNC_VIRTUAL=0,
    FUNC_PUREVIRTUAL=1,
    FUNC_NONVIRTUAL=2,
    FUNC_STATIC=3,
    FUNC_DISPATCH=4
} tagFUNCKIND;

typedef enum tagFUNCKIND FUNCKIND;

typedef enum tagINVOKEKIND {
    INVOKE_FUNC=1,
    INVOKE_PROPERTYGET=2,
    INVOKE_PROPERTYPUT=4,
    INVOKE_PROPERTYPUTREF=8
} tagINVOKEKIND;

typedef enum tagINVOKEKIND INVOKEKIND;

struct tagFUNCDESC {
    MEMBERID memid;
    SCODE *lprgscode;
    ELEMDESC *lprgelemdescParam;
    FUNCKIND funckind;
    INVOKEKIND invkind;
    CALLCONV callconv;
    short cParams;
    short cParamsOpt;
    short oVft;
    short cScodes;
    ELEMDESC elemdescFunc;
    ushort wFuncFlags;
};

typedef enum tagFUNCFLAGS {
    FUNCFLAG_FRESTRICTED=1,
    FUNCFLAG_FSOURCE=2,
    FUNCFLAG_FBINDABLE=4,
    FUNCFLAG_FREQUESTEDIT=8,
    FUNCFLAG_FDISPLAYBIND=16,
    FUNCFLAG_FDEFAULTBIND=32,
    FUNCFLAG_FHIDDEN=64,
    FUNCFLAG_FUSESGETLASTERROR=128,
    FUNCFLAG_FDEFAULTCOLLELEM=256,
    FUNCFLAG_FUIDEFAULT=512,
    FUNCFLAG_FNONBROWSABLE=1024,
    FUNCFLAG_FREPLACEABLE=2048,
    FUNCFLAG_FIMMEDIATEBIND=4096
} tagFUNCFLAGS;

typedef enum tagFUNCFLAGS FUNCFLAGS;

typedef struct tagIDLDESC tagIDLDESC, *PtagIDLDESC;

typedef struct tagIDLDESC IDLDESC;

struct tagIDLDESC {
    uint dwReserved;
    ushort wIDLFlags;
};

typedef struct ITypeComp ITypeComp, *PITypeComp;

typedef struct ITypeCompVtbl ITypeCompVtbl, *PITypeCompVtbl;

struct ITypeCompVtbl {
};

struct ITypeComp {
    struct ITypeCompVtbl *lpVtbl;
};

typedef struct ITypeInfo ITypeInfo, *PITypeInfo;

typedef struct ITypeInfoVtbl ITypeInfoVtbl, *PITypeInfoVtbl;

typedef struct tagTYPEATTR tagTYPEATTR, *PtagTYPEATTR;

typedef struct tagTYPEATTR TYPEATTR;

typedef struct tagVARDESC tagVARDESC, *PtagVARDESC;

typedef struct tagVARDESC VARDESC;

typedef OLECHAR *LPOLESTR;

typedef struct ITypeLib ITypeLib, *PITypeLib;

typedef uint LCID;

typedef enum tagTYPEKIND {
    TKIND_ENUM=0,
    TKIND_RECORD=1,
    TKIND_MODULE=2,
    TKIND_INTERFACE=3,
    TKIND_DISPATCH=4,
    TKIND_COCLASS=5,
    TKIND_ALIAS=6,
    TKIND_UNION=7,
    TKIND_MAX=8
} tagTYPEKIND;

typedef enum tagTYPEKIND TYPEKIND;

typedef union tagVARDESC_u tagVARDESC_u, *PtagVARDESC_u;

typedef enum tagVARKIND {
    VAR_PERINSTANCE=0,
    VAR_STATIC=1,
    VAR_CONST=2,
    VAR_DISPATCH=3
} tagVARKIND;

typedef enum tagVARKIND VARKIND;

typedef struct ITypeLibVtbl ITypeLibVtbl, *PITypeLibVtbl;

typedef struct tagTLIBATTR tagTLIBATTR, *PtagTLIBATTR;

typedef struct tagTLIBATTR TLIBATTR;

typedef enum tagSYSKIND {
    SYS_WIN16=0,
    SYS_WIN32=1,
    SYS_MAC=2
} tagSYSKIND;

typedef enum tagSYSKIND SYSKIND;

union tagVARDESC_u {
    uint oInst;
    VARIANT *lpvarValue;
};

struct tagVARDESC {
    MEMBERID memid;
    LPOLESTR lpstrSchema;
    union tagVARDESC_u u;
    ELEMDESC elemdescVar;
    ushort wVarFlags;
    VARKIND varkind;
};

struct ITypeInfoVtbl {
    long (*QueryInterface)(struct ITypeInfo *, IID *, void **);
    uint (*AddRef)(struct ITypeInfo *);
    uint (*Release)(struct ITypeInfo *);
    long (*GetTypeAttr)(struct ITypeInfo *, TYPEATTR **);
    long (*GetTypeComp)(struct ITypeInfo *, struct ITypeComp **);
    long (*GetFuncDesc)(struct ITypeInfo *, uint, FUNCDESC **);
    long (*GetVarDesc)(struct ITypeInfo *, uint, VARDESC **);
    long (*GetNames)(struct ITypeInfo *, MEMBERID, BSTR *, uint, uint *);
    long (*GetRefTypeOfImplType)(struct ITypeInfo *, uint, HREFTYPE *);
    long (*GetImplTypeFlags)(struct ITypeInfo *, uint, int *);
    long (*GetIDsOfNames)(struct ITypeInfo *, LPOLESTR *, uint, MEMBERID *);
    long (*Invoke)(struct ITypeInfo *, void *, MEMBERID, ushort, DISPPARAMS *, VARIANT *, EXCEPINFO *, uint *);
    long (*GetDocumentation)(struct ITypeInfo *, MEMBERID, BSTR *, BSTR *, uint *, BSTR *);
    long (*GetDllEntry)(struct ITypeInfo *, MEMBERID, INVOKEKIND, BSTR *, BSTR *, ushort *);
    long (*GetRefTypeInfo)(struct ITypeInfo *, HREFTYPE, struct ITypeInfo **);
    long (*AddressOfMember)(struct ITypeInfo *, MEMBERID, INVOKEKIND, void **);
    long (*CreateInstance)(struct ITypeInfo *, struct IUnknown *, IID *, void **);
    long (*GetMops)(struct ITypeInfo *, MEMBERID, BSTR *);
    long (*GetContainingTypeLib)(struct ITypeInfo *, struct ITypeLib **, uint *);
    void (*ReleaseTypeAttr)(struct ITypeInfo *, TYPEATTR *);
    void (*ReleaseFuncDesc)(struct ITypeInfo *, FUNCDESC *);
    void (*ReleaseVarDesc)(struct ITypeInfo *, VARDESC *);
};

struct ITypeLibVtbl {
    long (*QueryInterface)(struct ITypeLib *, IID *, void **);
    uint (*AddRef)(struct ITypeLib *);
    uint (*Release)(struct ITypeLib *);
    uint (*GetTypeInfoCount)(struct ITypeLib *);
    long (*GetTypeInfo)(struct ITypeLib *, uint, struct ITypeInfo **);
    long (*GetTypeInfoType)(struct ITypeLib *, uint, TYPEKIND *);
    long (*GetTypeInfoOfGuid)(struct ITypeLib *, GUID *, struct ITypeInfo **);
    long (*GetLibAttr)(struct ITypeLib *, TLIBATTR **);
    long (*GetTypeComp)(struct ITypeLib *, struct ITypeComp **);
    long (*GetDocumentation)(struct ITypeLib *, int, BSTR *, BSTR *, uint *, BSTR *);
    long (*IsName)(struct ITypeLib *, LPOLESTR, uint, int *);
    long (*FindName)(struct ITypeLib *, LPOLESTR, uint, struct ITypeInfo **, MEMBERID *, ushort *);
    void (*ReleaseTLibAttr)(struct ITypeLib *, TLIBATTR *);
};

struct tagTLIBATTR {
    GUID guid;
    LCID lcid;
    SYSKIND syskind;
    ushort wMajorVerNum;
    ushort wMinorVerNum;
    ushort wLibFlags;
};

struct tagTYPEATTR {
    GUID guid;
    LCID lcid;
    uint dwReserved;
    MEMBERID memidConstructor;
    MEMBERID memidDestructor;
    LPOLESTR lpstrSchema;
    uint cbSizeInstance;
    TYPEKIND typekind;
    ushort cFuncs;
    ushort cVars;
    ushort cImplTypes;
    ushort cbSizeVft;
    ushort cbAlignment;
    ushort wTypeFlags;
    ushort wMajorVerNum;
    ushort wMinorVerNum;
    TYPEDESC tdescAlias;
    IDLDESC idldescType;
};

struct ITypeLib {
    struct ITypeLibVtbl *lpVtbl;
};

struct ITypeInfo {
    struct ITypeInfoVtbl *lpVtbl;
};

typedef enum tagLIBFLAGS {
    LIBFLAG_FRESTRICTED=1,
    LIBFLAG_FCONTROL=2,
    LIBFLAG_FHIDDEN=4,
    LIBFLAG_FHASDISKIMAGE=8
} tagLIBFLAGS;

typedef enum tagLIBFLAGS LIBFLAGS;

typedef void * (*PfnDliHook)(uint, struct DelayLoadInfo *);

typedef enum tagTYPEFLAGS {
    TYPEFLAG_FAPPOBJECT=1,
    TYPEFLAG_FCANCREATE=2,
    TYPEFLAG_FLICENSED=4,
    TYPEFLAG_FPREDECLID=8,
    TYPEFLAG_FHIDDEN=16,
    TYPEFLAG_FCONTROL=32,
    TYPEFLAG_FDUAL=64,
    TYPEFLAG_FNONEXTENSIBLE=128,
    TYPEFLAG_FOLEAUTOMATION=256,
    TYPEFLAG_FRESTRICTED=512,
    TYPEFLAG_FAGGREGATABLE=1024,
    TYPEFLAG_FREPLACEABLE=2048,
    TYPEFLAG_FDISPATCHABLE=4096,
    TYPEFLAG_FREVERSEBIND=8192
} tagTYPEFLAGS;

typedef enum tagTYPEFLAGS TYPEFLAGS;

typedef struct UnloadInfo UnloadInfo, *PUnloadInfo;

struct UnloadInfo {
    struct UnloadInfo *puiNext;
    struct ImgDelayDescr *pidd;
};

typedef enum VARENUM {
    VT_EMPTY=0,
    VT_NULL=1,
    VT_I2=2,
    VT_I4=3,
    VT_R4=4,
    VT_R8=5,
    VT_CY=6,
    VT_DATE=7,
    VT_BSTR=8,
    VT_DISPATCH=9,
    VT_ERROR=10,
    VT_BOOL=11,
    VT_VARIANT=12,
    VT_UNKNOWN=13,
    VT_DECIMAL=14,
    VT_I1=16,
    VT_UI1=17,
    VT_UI2=18,
    VT_UI4=19,
    VT_I8=20,
    VT_UI8=21,
    VT_INT=22,
    VT_UINT=23,
    VT_VOID=24,
    VT_HRESULT=25,
    VT_PTR=26,
    VT_SAFEARRAY=27,
    VT_CARRAY=28,
    VT_USERDEFINED=29,
    VT_LPSTR=30,
    VT_LPWSTR=31,
    VT_RECORD=36,
    VT_FILETIME=64,
    VT_BLOB=65,
    VT_STREAM=66,
    VT_STORAGE=67,
    VT_STREAMED_OBJECT=68,
    VT_STORED_OBJECT=69,
    VT_BLOB_OBJECT=70,
    VT_CF=71,
    VT_CLSID=72,
    VT_BSTR_BLOB=4095,
    VT_ILLEGALMASKED=4095,
    VT_TYPEMASK=4095,
    VT_VECTOR=4096,
    VT_ARRAY=8192,
    VT_BYREF=16384,
    VT_RESERVED=32768,
    VT_ILLEGAL=65535
} VARENUM;

typedef enum tagVARFLAGS {
    VARFLAG_FREADONLY=1,
    VARFLAG_FSOURCE=2,
    VARFLAG_FBINDABLE=4,
    VARFLAG_FREQUESTEDIT=8,
    VARFLAG_FDISPLAYBIND=16,
    VARFLAG_FDEFAULTBIND=32,
    VARFLAG_FHIDDEN=64,
    VARFLAG_FRESTRICTED=128,
    VARFLAG_FDEFAULTCOLLELEM=256,
    VARFLAG_FUIDEFAULT=512,
    VARFLAG_FNONBROWSABLE=1024,
    VARFLAG_FREPLACEABLE=2048,
    VARFLAG_FIMMEDIATEBIND=4096
} tagVARFLAGS;

typedef enum tagVARFLAGS VARFLAGS;

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

typedef struct _GUID _GUID, *P_GUID;

struct _GUID {
    uint Data1;
    ushort Data2;
    ushort Data3;
    uchar Data4[8];
};

typedef struct __JUMP_BUFFER __JUMP_BUFFER, *P__JUMP_BUFFER;

typedef struct __JUMP_BUFFER _JUMP_BUFFER;

struct __JUMP_BUFFER {
    ulong Ebp;
    ulong Ebx;
    ulong Edi;
    ulong Esi;
    ulong Esp;
    ulong Eip;
    ulong Registration;
    ulong TryLevel;
    ulong Cookie;
    ulong UnwindFunc;
    ulong UnwindData[6];
};

typedef void (*_PVFV)(void);

typedef uint _dev_t;

typedef ushort _ino_t;

typedef long _off_t;

typedef struct _stat _stat, *P_stat;

typedef long time_t;

struct _stat {
    _dev_t st_dev;
    _ino_t st_ino;
    ushort st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
};

typedef struct _timeb _timeb, *P_timeb;

struct _timeb {
    time_t time;
    ushort millitm;
    short timezone;
    short dstflag;
};

typedef struct _utimbuf _utimbuf, *P_utimbuf;

struct _utimbuf {
    time_t actime;
    time_t modtime;
};

typedef int jmp_buf[16];

typedef struct float_const float_const, *Pfloat_const;

struct float_const {
    uint mantissa_lo;
    uint mantissa_hi;
    ushort sign_exponent;
    ushort size;
};

typedef struct getflags_letter_row getflags_letter_row, *Pgetflags_letter_row;

struct getflags_letter_row {
    int letter;
    int kind;
    uchar *flag;
};

typedef struct getflags_row getflags_row, *Pgetflags_row;

typedef union getflags_variable getflags_variable, *Pgetflags_variable;

union getflags_variable {
    uchar *flag;
    char **text;
    struct getflags_letter_row *letters;
    long *number;
    struct fe_vector **list;
};

struct getflags_row {
    char *pattern;
    union getflags_variable variable;
    uchar result;
    uchar kind;
    uchar pad0a[2];
};


c1_tag_symbol * __cdecl class_check_tag_kind_consistency(c1_tag_symbol * tag, short kind);
c1_tag_symbol * __cdecl class_check_tag_redefinition(void * name, ushort kind, int * insert);
void __thiscall class_check_member_declaration(c1_declaration * decl, c1_decl_specifiers * spec);
int __cdecl class_check_member_redefinition(void * name);
int __cdecl class_check_member_redefinition_fragment(void);
int __cdecl class_check_zero_sized_array_member(c1_symbol * member);
uint __thiscall class_member_natural_alignment(c1_type * type, uint pack);
void __cdecl class_warn_packing_sensitive_alignment(uint alignment);
uint __cdecl class_member_padding(uint alignment);
uint __cdecl class_padding_for_offset(uint alignment, uint offset);
uint __cdecl class_member_offset_add(uint offset, uint delta);
void __cdecl class_append_member(c1_symbol * member);
void __cdecl class_add_padding_member(uint size);
void __cdecl class_new_member_symbol(c1_type * type);
void __cdecl class_check_bit_field(c1_symbol * member, ushort type_code);
void __stdcall class_close_bit_field_unit(void);
uint __cdecl class_check_member_type_complete(uint size, c1_type * type, c1_symbol * member);

longlong __fastcall _allshr(byte count, int hi, uint lo);
int __stdcall yy_error_flag(void);
longlong __fastcall _allshl(byte count, uint lo, uint hi);
longlong __stdcall _allmul(uint a_lo, int a_hi, uint b_lo, int b_hi);
void __thiscall block_scope_new(c1_scope_stack * scopes, void * parameter_scope);
void * __cdecl segment_lookup_or_declare(void * name, void * seg_class, char cls);
void __cdecl emit_version_string_literal(void);
int __cdecl fclose_if_open(FILE * f);
char * __cdecl int64_to_string(int * value, char * buffer, int radix, int is_unsigned);
void __cdecl block_list_rewind(c1_byte_block_list * list);
void __cdecl block_list_open_or_rewind(c1_byte_block_list * * slot);
void __cdecl buffer_chain_append_bytes(void * src, int count, int size, c1_byte_block_list * chain);
int __cdecl counted_array_size(short count);
int * __thiscall hash_scope_find_link(c1_scope_object * hash_scope, int * entry);
void __thiscall hash_scope_lookup_anonymous_member(c1_scope_object * hash_scope, void * name, int * out);
void __cdecl _chkstk(uint size);

int __cdecl vtable_true(void);
void __stdcall vtable_nop(void);
int __stdcall vtable_true_arg2(int a, int b);
int __stdcall vtable_true_arg1(int a);
c1_tag_symbol * __cdecl esu_check_tag_and_begin_enum(c1_tag_symbol * tag, ushort specifier_code);
c1_tag_symbol * __cdecl esu_struct_body_begin(c1_tag_symbol * tag, c1_type * type);
c1_type * __cdecl esu_finish_struct_specifier(void);
uint __thiscall idb_stub_clear_third_out(c1_idb_stub * stub, uint a, uint b, uint * out_zero);
void __cdecl pdb_state_construct(void);
void __cdecl pdb_state_construct_2(void);
c1_pch_image * __fastcall pch_arena_writer_clear(c1_pch_image * image);
void __cdecl pdb_open(void);
int __cdecl pdb_open_file(PDB * pdb, PDB * pdb_2, NameMap * name_map, char * source_name, char * object_name, c1_source_tracker_iface * tracker, int incremental, int second_pdb, int read_second_pdb, c1_idb_state * * out_idb);
uint __thiscall idb_stub_check_options(c1_idb_stub * stub, int a, uint * out_status);
int __stdcall vtable_set_out_true(int * out);
void __cdecl pdb_make_idb_name(char * out);
char * __cdecl decorate_check_name_length(c1_symbol * sym);
int __cdecl vtable_false(void);
uint __thiscall idb_stub_function_end(c1_idb_stub * stub, uint a, uint b, uint c, uint * out_status, uint * out_zero);
uint __thiscall idb_stub_function_begin(c1_idb_stub * stub, uint a, uint b, int c, uint * out_status, int * d, ushort * e, uint * out_zero);
char * __cdecl decorate_number(char * out, uint n);
char * __cdecl decorate_string_literal_name_body(char * out, ushort * text, uint length, char wide);
uint __stdcall crc16_update(c1_u8 * data, int n, uint crc);
byte * __cdecl decorate_string_literal_char(byte * out, byte c);
char * __cdecl iccline_check_incremental(void);
char * __cdecl decorate_name(c1_symbol * sym, ushort scope_number);
void __cdecl pch_check_after_options(void);
void __stdcall pch_finish_files(void);
void __fastcall pch_image_close(c1_pch_image * image);
void __cdecl pdb_state_2_destroy(void);
void __cdecl pdb_state_destroy(void);
int __fastcall idb_stub_delete(c1_idb_stub * idb_stub);
void __fastcall pdb_close(c1_pdb_state * session);
void __cdecl browse_add_record(byte kind, c1_symbol * sym);
void __cdecl browse_record_fill(c1_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_type(c1_browse_record * rec);
void __cdecl browse_record_write(c1_browse_record * rec);
void __stdcall browse_record_write_fragment(void);
void __cdecl browse_record_fill_kind12(c1_browse_record * rec, fe_macro * macro);
void __cdecl browse_record_fill_definition(c1_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_set_symbol_with_id(c1_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_set_symbol(c1_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_fill_owner(c1_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_fill_reference(c1_browse_record * rec, c1_symbol * sym);
char __fastcall pdb_source_file_pop(c1_pdb_source_file * * stack);
void __cdecl browse_record_finish_kind13(c1_browse_record * rec, fe_macro * macro);
char __thiscall pdb_file_stack_push(c1_pdb_source_file * * stack, char * name, int fd, c1_u8 by_handle);
void __cdecl browse_record_set_file(c1_browse_record * rec);
int __cdecl debug_identifier_length(char * out, char * name);
char * __cdecl debug_put_length_prefixed_name(char * out, char * name);
uint __cdecl debug_type_pad_to_4(char * out, char length);
c1_u32 __cdecl debug_type_index(c1_type * type);
c1_u32 __cdecl debug_type_index_compute(c1_type * type);
int __cdecl debug_cv_primitive_type_index(ushort code);
byte __thiscall pdb_open_validated(c1_pdb_state * state, char * name, int * out_signature, int * out_age, long page_size, char * mode);
char __thiscall pdbmgr_open(c1_pdb_state * state, char * name, PDB * * out_pdb, char retry, long page_size, char * mode);
char __thiscall pdb_open_for_minimal_rebuild(c1_pdb_state * pdb_state, char * source_name);
char __thiscall pdb_open_minimal_rebuild_engine(c1_pdb_state * state, c1_pdb_state * gi_state);
void __cdecl debug_begin(char no_header);
char __fastcall pdb_open_type_info(c1_pdb_state * pdb_state);
c1_u32 __cdecl debug_type_index_derived(c1_type * type);
int __cdecl debug_cv_primitive_pointer_index(c1_type * type);
c1_u32 __cdecl debug_type_record_class_forward(c1_symbol * sym);
int __cdecl debug_cv_unsigned_numeric_leaf(ushort * out, uint lo, int hi);
int __cdecl debug_put_symbol_name(char * out, c1_symbol * sym);
int __cdecl cvserver_emit_type(uint length);
int __cdecl debug_type_record_pointer(c1_type * type, int pointee_index);
c1_u32 __cdecl debug_type_record_struct_complete(c1_symbol * tag);
int __cdecl debug_type_record_struct(c1_symbol * tag);
int __cdecl debug_emit_types_twice(c1_symbol * tag, int * count, ushort * property);
int __cdecl debug_type_record_class_fieldlist(int pass, c1_symbol * tag, int * count);
int __cdecl debug_type_record_member(int pass, c1_symbol * member, ushort * out);
uint __cdecl pdb_numeric_leaf(ushort * out, uint lo, int hi);
int __cdecl debug_type_record_array(c1_type * type, int element_index);
int __cdecl debug_type_record_procedure_leaf(c1_type * type, uint return_index);
int __cdecl debug_type_record_arglist(c1_param_list * params);
int __cdecl debug_cv_calling_convention(ushort flags);
void __cdecl debug_type_record_modifier(c1_type * type);
int __cdecl debug_type_record_bitfield(c1_symbol * sym);
void __stdcall vtable_nop_arg1(void);
char __thiscall pdb_gi_end_unit(c1_pdb_source_file * * stack, uint flag);
void __thiscall pdb_session_close_gi(c1_pdb_state * session, char flag);
void __fastcall debug_finish(void);
void __fastcall pdb_session_close_types(c1_pdb_state * session);
void __cdecl pch_relocate_line_map(void);
void __cdecl pch_relocate_line_map_pointer(void);
void __thiscall line_map_set_cached_row(c1_lex_position_record * position_record, void * file);
void __fastcall line_map_clear_cached_row(c1_lex_position_record * position_record);
void __fastcall pch_relocate_token(c1_token * token);
void __cdecl pch_relocate_list_1444(void);
void __cdecl pch_relocate_pack_stack(void);
void __cdecl pch_use(byte * header_name, char is_yu_header);
void __cdecl pch_set_name(char * file);
char * __cdecl pch_default_name(char * file);
c1_u32 __cdecl debug_type_record_enum_forward(c1_symbol * sym);
c1_u32 __cdecl debug_type_record_enum(c1_symbol * tag);
int __cdecl debug_type_record_enum_fieldlist(c1_symbol * tag);
int __stdcall debug_type_record_struct_fragment(int member_count, uint attributes, ushort type_code, c1_symbol * sym);
uint __cdecl debug_cv_signed_numeric_leaf(ushort * out, uint lo, uint hi);
int __cdecl debug_tag_reference_record(short * rec, c1_symbol * base);
void __cdecl debug_begin_file(char * pch_name);
void __cdecl debug_pad_record(int length, ushort * record);
void __cdecl pch_creation_point(void);
int __cdecl pch_read_options(void);
void __cdecl pch_hdrstop(void);
void __cdecl pch_rebind_include_stack_files(void);
void __cdecl browse_record_finish_kind11(c1_browse_record * rec);
void __cdecl browse_next_region_id(void);
void __fastcall browse_emit_records(c1_il_emitter_browse * emitter);
bool __stdcall browse_seek_to_saved_offset(void);
void __cdecl browse_restart_region_after_pch(void);
int __cdecl pch_write_blocks(c1_byte_block_list * list, FILE * f, c1_byte_block_list * dst);
byte __cdecl block_list_equals_bytes(c1_byte_block_list * list, c1_u8 * bytes, uint n);
char * __cdecl pdb_relative_path(char * file);
char * __cdecl decorate_warn_name_truncated(c1_symbol * sym);
char * __cdecl decorate_c_symbol_name(char * buf, c1_symbol * sym);
char * __cdecl decorate_calling_convention(char * out, c1_type * type);
char * __cdecl decorate_name_4(void);
void * __cdecl debug_segment_symbol_name(c1_symbol * sym);
void __cdecl pch_write_end_precomp_types(void);
void __cdecl pch_relocate_segment_table(void);
uint __cdecl pdb_namemap_symbol_name(c1_symbol * sym);
void __cdecl debug_type_emit_if_needed(c1_type * type);
void __cdecl pch_relocate_function_records(void);
int __cdecl decorate_based_text(uchar flags, int base);
int __cdecl decorate_cv_text(int buf, c1_u16 quals);
void __stdcall pdb_open_fragment(void);
int __cdecl pch_record_entry(int kind, int value, char * text);
int __cdecl pch_record_macro_definition(byte * name, byte * body, ushort value);
int __cdecl pch_record_or_replay_if_value(int value);
void __cdecl pch_directive_reopen_source(void);
int __cdecl pch_record_or_match_directive(void);
int __cdecl pch_record_include(byte * file);
void __stdcall pch_auto_start_recording(void);
int __cdecl pch_auto_match_end(void);
void __cdecl pch_auto_begin(void);
void __cdecl pch_rle_begin(int * counter);
void __cdecl pch_rle_flush_run(void);
int __cdecl pch_rle_write_bytes(byte * bytes, long n);
void __cdecl pch_extract_file_rle(char * file, int n);
void __stdcall pch_check_defines(void);
void __cdecl pch_read(void);
char __cdecl pch_check_options(char quiet);
void __cdecl pch_open(void);
void __cdecl pch_write_file(void);
void __cdecl pch_write(void);
void __stdcall pch_save_il(void);
void __cdecl pch_reload_il_streams(char with_db);
char __cdecl pch_auto_check_usable(char * header_name);
char __cdecl pch_check_recorded_entry(uint kind, uint value, char * text, char exact);
void __stdcall pch_record_environment(void);
char * __cdecl pch_stream_name(char * out, char * file, char * ext);
void __cdecl pch_emit_pchsym_include_directive(void);
void __cdecl pch_relocate_misc_globals(void);
void __cdecl pch_relocate_global_tables(void);
void __cdecl pch_relocate_current_scope(void);
void __cdecl pch_relocate_warning_state(void);
void __fastcall pch_relocate_tagged_list(uint * link);
void __fastcall pch_relocate_warning_state_chain(int state);
void __fastcall pch_relocate_list_1b6c(int node);
void __cdecl pch_relocate_symbol_free_lists(void);
void __cdecl pch_relocate_global_1b70(void);
void __fastcall pch_fixup_block_scope(c1_scope_object * hash_scope);
void __fastcall pch_fixup_hash_scope(c1_scope_object * scope);
void __cdecl pch_relocate_symbol_chain(c1_symbol * sym);
void __cdecl pch_relocate_symbol(byte * sym);
void __cdecl pch_relocate_symbol_symtab(c1_symbol * sym);
void __cdecl pch_relocate_type_hash(void);
void __cdecl pch_relocate_type_chain(uint * entry);
void __cdecl pch_relocate_type_descriptor(c1_type * type);
void __cdecl pch_relocate_parameter_list_hash(void);
void __cdecl pch_relocate_parameter_list_chain(uint * entry);
void __cdecl pch_relocate_token_records(void);
void __cdecl pch_relocate_pragma_comment_list(void);
void __cdecl pch_relocate_counted_slot_array(int * array);
void __cdecl pch_relocate_tree(c1_node * node);
void __cdecl pch_relocate_pair(uint slots);
void __cdecl pch_relocate_name_hash(void);
void __cdecl pch_relocate_name_chain(uint * entry);
void __cdecl pch_relocate_pointer_array(uint slots, int count);
void __cdecl pch_mark_vector_slots(fe_vector * vec, void * callback);
void __cdecl pch_relocate_symtab_entries(fe_symtab * tab, void * key_fn, void * value_fn);
void __cdecl pch_fixup_symtab_chain(fe_symtab_entry * entry, void * key_fn, void * value_fn, char fix_key, char fix_value);
void __cdecl pch_relocate_define_list(void);
void __cdecl pch_relocate_include_path_list(void);
void __cdecl pch_fixup_global_roots(void);
void __fastcall pch_relocate_symbol_list(void * cell);
void __fastcall pch_relocate_symbol_list_simple(int element);
void __fastcall pch_relocate_tag_symbol_list(void * cell);
void __fastcall pch_relocate_record_chain(void * record);
void __thiscall pch_read_into_buffer(fe_il_buffer * buf, FILE * file, int n);
char * __cdecl pch_and_pdb_names(void);
void __cdecl pch_finish_il(void);
void __cdecl pch_begin_write(void);
void __cdecl pch_write_finish(void);
void __cdecl pch_reload_il(char with_db);
int __thiscall array16_save(fe_idb_region_array * array, Buffer * buf);
int __thiscall idb_region_array_reload(fe_idb_region_array * regions, c1_u32 * * cursor);
c1_idb_state * __thiscall idb_construct(c1_idb_state * idb, PDB * pdb, PDB * pdb_2, NameMap * name_map, c1_source_tracker_iface * tracker, int incremental, int second_pdb, int read_second_pdb);
int __thiscall pdb_open_module_stream(c1_idb_state * idb, char * source_name, char * object_name);
int __fastcall idb_commit(c1_idb_state * idb);
int __fastcall idb_write_dependencies(c1_idb_state * idb);
int __fastcall idb_write_regions(c1_idb_state * idb);
int __thiscall idb_read_dependencies(c1_idb_state * idb, Stream * stream, int * complete);
int __thiscall idb_read_regions(c1_idb_state * idb, Stream * stream);
uint __fastcall idb_release(c1_idb_state * idb);
void __thiscall idb_begin_unit(c1_idb_state * idb, int * state);
void __thiscall idb_begin_unit_no_check(c1_idb_state * idb, int * state);
int __fastcall idb_begin_source_file(c1_idb_state * idb);
int __fastcall idb_check_file_times(c1_idb_state * idb);
int __thiscall idb_check_next_region(c1_idb_state * idb, int check, int unused);
int __thiscall gi_region_record_begin(c1_idb_state * idb, byte kind);
uint __thiscall idb_function_begin(c1_idb_state * idb, uint close_header_region, uint start_line, int force, int * state_out, int * stored_count_out, short * stored_start_out, int * matched_out);
uint __thiscall idb_function_end(c1_idb_state * idb, uint close_header_region, uint end_line, int unused, int * state_out, int * result_out);
void __fastcall idb_note_macro_change(c1_idb_state * idb);
int __thiscall idb_note_pragma(c1_idb_state * idb, int pragma);
int __thiscall idb_note_pragma_output(c1_idb_state * idb, int pragma);
int __fastcall idb_conditional_enter(c1_idb_state * idb);
int __fastcall idb_conditional_leave(c1_idb_state * idb);
int __thiscall idb_include_enter(c1_idb_state * idb, char * file, byte registered);
int __thiscall idb_include_leave(c1_idb_state * idb, c1_u16 line);
int __thiscall idb_class_begin(c1_idb_state * idb, c1_u16 position, int key);
int __thiscall idb_class_end(c1_idb_state * idb, uint line, int arg2, int * result_out);
int __thiscall idb_function_body_begin(c1_idb_state * idb, uint position, int key);
int __thiscall idb_function_body_end(c1_idb_state * idb, uint position, int key, int * changed);
int __thiscall idb_function_region_in_header(c1_idb_state * idb, uint key, uint position, int context);
int __thiscall idb_function_region_end(c1_idb_state * idb, uint key, uint position, int context, int * changed);
int __thiscall idb_tracker_note(c1_idb_state * idb, int first, int second);
int __thiscall idb_scope_kind3_to_4(c1_idb_state * idb, uint position, int key);
int __thiscall idb_scope_kind4_end(c1_idb_state * idb, uint position, int key);
int __thiscall idb_set_tracker(c1_idb_state * idb, void * tracker);
int __fastcall idb_note_layout_dependency(c1_idb_state * idb);
int __fastcall idb_note_pragma_begin(c1_idb_state * idb);
int __thiscall idb_scope_kind3_to_2(c1_idb_state * idb, uint position, int key);
int __thiscall idb_scope_kind2_to_3(c1_idb_state * idb, uint position, int key);
void __fastcall idb_note_access_declaration(c1_idb_state * idb);
void __fastcall idb_note_decl_specifier(c1_idb_state * idb);
void __fastcall idb_note_sizeof(c1_idb_state * idb);
int __fastcall idb_note_warning(c1_idb_state * idb);
int __fastcall idb_note_error(c1_idb_state * idb);
int __fastcall idb_note_global_il_record(c1_idb_state * idb);
int __fastcall idb_note_line_dependency(c1_idb_state * idb);
int __fastcall idb_note_predefined_macro(c1_idb_state * idb);
int __thiscall idb_check_options(c1_idb_state * idb, int signature, int * result);
int __thiscall idb_set_pdb_signature(c1_idb_state * idb, int signature, uint age);
int __thiscall idb_pch_written(c1_idb_state * idb, int * state);
uint __thiscall idb_pch_read(c1_idb_state * idb, int * state_out);
int __fastcall idb_note_dependency_64(c1_idb_state * idb);
int __fastcall idb_note_special_members(c1_idb_state * idb);
int __fastcall idb_note_first_use(c1_idb_state * idb);
int __thiscall idb_add_name(c1_idb_state * idb, char * name);
int __thiscall idb_has_name(c1_idb_state * idb, char * name);
int __thiscall idb_browse_set_lines(c1_idb_state * idb, short first_line, short last_line);
int __thiscall idb_browse_set_region(c1_idb_state * idb, int first_line, int last_line, int value);
int __fastcall idb_browse_region_count(c1_idb_state * idb);
int __thiscall idb_browse_region(c1_idb_state * idb, uint index, void * * entry);
int __fastcall idb_browse_truncate(c1_idb_state * idb);
int __fastcall idb_browse_table_reset(c1_idb_state * idb);
int __fastcall idb_invalidate(c1_idb_state * idb);
int __fastcall idb_in_function(c1_idb_state * idb);
void __fastcall idb_note_helper_call(c1_idb_state * idb);
int __fastcall idb_helper_called(c1_idb_state * idb);
int __thiscall idb_stub_true_3(c1_idb_stub * idb_stub, int line, int offset, int extra);
int __thiscall idb_stub_region_none(c1_idb_stub * idb_stub, uint region, int * out);
void __thiscall gi_region_entry_init(fe_idb_region * region, byte kind);
void __thiscall idb_browse_set_size(c1_idb_state * idb, int size);
int __fastcall idb_browse_size(c1_idb_state * idb);
void __fastcall idb_force_recompile(c1_idb_state * idb);
void __fastcall idb_disable_incremental(c1_idb_state * idb);
int __thiscall iset_contains(ISet * set, uint n);
int __thiscall iset_add(ISet * set, uint n);
int __thiscall iset_remove(ISet * set, uint n);
int __thiscall iset_ensure_room(ISet * set, uint n);
fe_idb_region * __thiscall gi_region_entry_set(fe_idb_region * region, byte kind, int hash_lo, int hash_hi, short start_line, byte flag);
fe_idb_include_state * __thiscall idb_include_state_assign(fe_idb_include_state * state, fe_idb_include_state * from);
void __fastcall pdb_array_destroy(Array_DWORD * array);
void __thiscall dword_array_fill(Array_DWORD * array, c1_u32 * value);
fe_idb_region_array * __thiscall region_array_assign(fe_idb_region_array * array, fe_idb_region_array * from);
Map_DWORD_DWORD * __thiscall map_init(Map_DWORD_DWORD * map, uint slots);
void * __thiscall pdb_ipm_elem48_vector_deleting_dtor(fe_idb_include_state * elements, byte flags);
Array_DWORD * __thiscall array_init_count(Array_DWORD * array, uint n);
int __thiscall array_set_size(Array_DWORD * array, uint n);
int __thiscall array_save(Array_DWORD * array, Buffer * buf);
int __thiscall array_reload(Array_DWORD * array, c1_u32 * * cursor);
int __thiscall region_array_set_size(fe_idb_region_array * array, uint n);
int __thiscall idb_include_stack_set_size(fe_idb_include_stack * stack, uint n);
int __thiscall map_save(Map_DWORD_DWORD * map, Buffer * buf);
int __thiscall array12_set_size(fe_idb_browse_table * array, uint n);
int __thiscall map_arrays_set_size(Map_DWORD_DWORD * map, uint n);
int __thiscall pdb_map_find(Map_DWORD_DWORD * map, uint key, uint * slot);
int __fastcall map_grow_2(Map_DWORD_DWORD * map);
void __fastcall map_destroy(Map_DWORD_DWORD * map);
void __thiscall array_swap(Array_DWORD * array, Array_DWORD * other);
fe_bitvec * __fastcall bitvec_init_empty(fe_bitvec * bitvec);
int __thiscall bitvec_alloc(fe_bitvec * bitvec, int nbits, fe_arena * a);
char __thiscall bitvec_attach(fe_bitvec * bitvec, int nbits, c1_u8 * bits);
c1_u8 * __fastcall bitvec_release_bits(fe_bitvec * bitvec);
void __thiscall pch_block_mark_visited(void * block, int n);
c1_u8 __thiscall pch_block_is_visited(void * block, int n);
char __fastcall bitvec_iter_first(fe_bitvec * iter);
char __fastcall bitvec_iter_next(fe_bitvec * iter);
int __fastcall bitvec_iter_index(fe_bitvec * iter);
c1_u8 __cdecl os_is_windows_nt(void);
void __thiscall pch_segment_write_base_header(c1_pch_segment * obj, HANDLE file);
c1_pch_segment * __cdecl pch_image_read_segment(HANDLE file, c1_pch_image * image);
c1_pch_segment * __thiscall pch_arena_segment_ctor(c1_pch_segment * segment, fe_arena * a, c1_pch_image * image);
c1_pch_segment * __thiscall pch_stream_reader_new(c1_pch_segment * reader, void * file, int kind, uint owner);
int __thiscall pch_segment_map_view(c1_pch_segment * segment, void * mapping, char keep, void * file);
int __thiscall pch_segment_alloc_at_base(c1_pch_segment * segment, void * file);
int __thiscall pch_segment_alloc_anywhere(c1_pch_segment * segment, void * file, int unused);
void __thiscall pch_segment_read_bytes(c1_pch_segment * segment, HANDLE file);
void __thiscall pch_segment_write_bytes(c1_pch_segment * segment, HANDLE file);
void __fastcall pch_segment_force_relocation(c1_pch_segment * segment);
void __fastcall pch_segment_release(c1_pch_segment * segment);
void __thiscall pch_segment_append_to_file(c1_pch_segment * segment, HANDLE file);
void __thiscall pch_segment_write_contents(c1_pch_segment * segment, uint file);
void __thiscall pch_arena_segment_write_header(c1_pch_segment * segment, HANDLE file);
void __fastcall pch_segment_compute_delta(c1_pch_segment * segment);
void __thiscall pch_segment_create_reloc_bitmap(c1_pch_segment * segment, fe_arena * a);
char __thiscall pch_segment_open_reloc_bitmap(c1_pch_segment * segment, c1_pch_segment * holder);
void __thiscall pch_segment_apply_relocations(c1_pch_segment * segment, c1_pch_image * image);
void __thiscall pch_page_table_fill(c1_pch_segment * * table, c1_pch_segment * value, uint base, int size);
void __thiscall pch_image_init(c1_pch_image * image, int n);
void __thiscall pch_image_init_from_loaded(c1_pch_image * image, c1_pch_image * loaded, int extra);
void __thiscall pch_image_index_read(c1_pch_image * index, LPCSTR file_name, DWORD offset);
void __thiscall pch_arena_record_append(c1_pch_image * image, fe_arena * a);
void __thiscall pch_heap_write_parts(c1_pch_image * image, char * name, int offset);
void __fastcall pch_image_write_directory(c1_pch_image * image);
void * __thiscall pch_image_create_mapping(c1_pch_image * index, uint protect, uint * handle);
byte __fastcall pch_image_map_segments(c1_pch_image * index);
void __thiscall pch_image_relocate(c1_pch_image * image, int unused);
c1_pch_segment * * __thiscall pch_image_page_table_new(c1_pch_image * image, void * segment_address);
void __fastcall pch_heap_write_file(c1_pch_image * image);
char __thiscall pch_relocate_slot_once(c1_pch_image * image, uint slot);
char __thiscall pch_relocate_pointer(c1_pch_image * image, uint * slot);
void __cdecl pch_write_arenas(char * file, int offset);
byte __cdecl pch_reload_arenas(char * name, uint offset);
c1_pch_segment * __fastcall pch_segment_self(c1_pch_segment * segment);
void * __fastcall pch_segment_base(c1_pch_segment * segment);
void * __thiscall pch_segment_loaded_address(c1_pch_segment * segment);
uint __fastcall pch_segment_size(c1_pch_segment * segment);
uint __fastcall pch_segment_descriptor_word(c1_pch_segment * segment);
void * __fastcall pch_segment_vcall_base(c1_pch_segment * seg);
void * __fastcall pch_segment_vcall_loaded_address(c1_pch_segment * seg);
char __thiscall pdb_file_stack_top_object(c1_pdb_source_file * * stack, MREFile * * out);
char __cdecl pdb_gi_read_blob_for_pch(void);
uint __cdecl pdb_gi_restore_pch_blob(void);
void __fastcall pdb_session_close(c1_pdb_state * session);
char __fastcall pdb_open_pch_contrib_stream(c1_pdb_state * session);
byte __thiscall pdb_contrib_lookup_file(c1_pdb_state * pdb, char * file, int * value);
void __thiscall pdb_record_pch_contribution(c1_pdb_state * pdb, char * file, int value);
byte __fastcall pdb_commit_session(c1_pdb_state * pdb);
char __cdecl pdb_blob_stream_open(PDB * pdb, char * name, fe_pdb_blob_table * * out);
fe_pdb_blob_table * __fastcall pdb_blob_stream_init(fe_pdb_blob_table * table);
void __fastcall pdb_blob_stream_destroy(fe_pdb_blob_table * table);
char __fastcall pdb_blob_stream_load(fe_pdb_blob_table * table);
char __fastcall pdb_blob_stream_flush(fe_pdb_blob_table * table);
char __thiscall named_blob_list_store(fe_pdb_blob_table * table, char * name, void * data, uint size);
byte __thiscall pdb_contrib_find_entry(fe_pdb_blob_table * table, char * file, void * * data, uint * size);
byte __fastcall pdb_stream_table_close(fe_pdb_blob_table * table);

int __cdecl sym_element_size(c1_symbol * sym);
uint __cdecl hash_table_bucket(void * table, void * key);
fe_symtab_entry * __cdecl symtab_find_in_bucket(fe_symtab * tab, void * key, int bucket);
uint __cdecl hash_fn_identity(uint key);
int __stdcall decl_default_calling_convention(c1_type * type);
c1_symbol * __thiscall sym_init_kind(c1_symbol * sym, c1_u8 kind, void * name, int unused);
void __fastcall decl_finish_declarator(c1_type_declarator * declarator);
void __cdecl decl_apply_declarator_modifiers(ushort convention, c1_type * base, c1_type * layer, c1_type_declarator * declarator);
void __fastcall decl_check_declarator_type(c1_type_declarator * declarator);
void __fastcall decl_warn_modifiers_on_data(c1_type_declarator * declarator);
c1_symbol * __cdecl sym_take_free_record(byte kind, void * name, int arena);
void __thiscall hash_scope_insert(c1_scope_object * block, c1_symbol * sym);
void __thiscall hash_scope_link(c1_scope_object * hash_scope, c1_symbol * sym);
c1_scope_lookup * __thiscall scope_stack_lookup(c1_scope_stack * scopes, int name);
c1_scope_lookup * __thiscall hash_scope_lookup_by_kind(c1_scope_object * hash_scope, void * name);
void __fastcall sym_mark_referenced(c1_symbol * sym);
void __thiscall scope_push_child(c1_scope_stack * scopes, c1_scope_object * scope);
void __thiscall scope_push_block(c1_scope_stack * scopes, c1_scope_object * block);
bool __fastcall scope_has_entries(c1_scope_object * scope);
void __fastcall scope_pop_child(c1_scope_stack * scopes);
void __fastcall scope_pop_block(c1_scope_stack * scopes);
c1_token * __cdecl decl_specifier_from_tag(c1_token * token);
c1_token * __fastcall decl_parse_declaration_specifiers(c1_specifier_state * spec);
void __fastcall decl_combine_type_specifiers(c1_specifier_state * spec);
void __stdcall decl_check_illegal_token_pair_fragment(void);
void __fastcall decl_parse_pointer_qualifiers(c1_specifier_state * spec);
c1_type * __cdecl decl_basic_type_from_specifiers(c1_u16 code, c1_u16 flags);
c1_token * __thiscall decl_specifier_token(c1_specifier_state * spec, c1_u8 code);
c1_type_declarator * __thiscall decl_new_declarator(c1_type_declarator * declarator, void * name);
void __thiscall decl_apply_specifiers(c1_type_declarator * declarator, c1_decl_specifiers * spec);
void __fastcall decl_abstract_declarator(c1_declaration * decl);
void __cdecl decl_abstract_declarator_fragment(c1_declaration * decl);
void __fastcall decl_check_declarator_kind(c1_declaration * decl);
c1_symbol * __thiscall sym_new_from_declarator(c1_declaration * decl, int arena);
c1_symbol * __cdecl sym_new_numbered(c1_symbol * sym, c1_declaration * decl);
void __thiscall sym_set_or_clear_segment_2(c1_symbol * sym, void * value);
void __fastcall decl_specifier_set_type_name(c1_specifier_state * spec);
c1_type * __cdecl sym_type_for_specifier(c1_symbol * sym);
void __thiscall decl_add_pointer_modifier(c1_type_declarator * declarator, ushort * mods, ushort * extra);
int __fastcall decl_specifier_try_typedef_name(c1_specifier_state * spec);
c1_symbol * __thiscall decl_declare_function_or_variable(c1_declaration * decl, c1_decl_specifiers * spec);
c1_symbol * __thiscall decl_declare_declarator(c1_declaration * decl, c1_decl_specifiers * spec);
int * __thiscall decl_find_redeclared_symbol(void * scope, c1_declaration * decl);
c1_scope_lookup * __thiscall hash_scope_lookup(c1_scope_object * hash_scope, int name);
int * __cdecl sym_list_find_non_tag(int * link, int name);
c1_symbol * __thiscall decl_check_redefinition(c1_declaration * decl, c1_symbol * sym);
void __thiscall block_scope_insert(c1_scope_object * block, c1_symbol * sym);
void * __fastcall decl_pop_parameter_scope(void * scopes);
int __cdecl decl_check_old_style_formal_names(void * params);
void __fastcall decl_warn_old_style_declarator(c1_declaration * decl);
int * __thiscall sym_list_find_ordinary(void * scope, int name);
void __thiscall decl_append_function_layer(c1_type_declarator * declarator, int * params);
void __fastcall decl_function_modifier_end_parameters(int * params);
void __thiscall decl_function_modifier_check_parameters(void * modifier, int list, int kind);
int * __cdecl decl_check_void_parameter(void * list, c1_u8 * fn_type, int context);
void __cdecl decl_specifiers_merge(c1_specifier_words * words, byte storage_class, char modifier, int value);
void __fastcall decl_specifiers_add_storage_class(c1_specifier_state * spec);
c1_param_list * __cdecl decl_empty_parameter_list(void);
int __thiscall decl_function_flags_compatible(void * self, ushort flags1, ushort flags2, int unused);
void * __fastcall scope_skip_prototype_scopes(c1_scope_stack * scopes);
char __thiscall decl_check_redeclaration(c1_declaration * decl, c1_symbol * sym);
uint __thiscall decl_check_function_redeclaration_varargs(c1_declaration * decl, c1_symbol * sym);
c1_u8 __thiscall decl_check_storage_compatible(c1_declaration * decl, c1_symbol * sym);
void __thiscall decl_merge_redeclaration(c1_declaration * decl, c1_symbol * sym);
void __thiscall decl_append_array_layer(c1_type_declarator * declarator, int * bound);
void __cdecl symtab_insert(fe_symtab * tab, void * key, void * value);
fe_symtab * __cdecl symtab_new(int nbuckets, int arena, int hash, int compare, c1_u8 flag0, c1_u8 flag1);
c1_symbol * __thiscall sym_copy_unlinked(c1_symbol * dst, c1_symbol * sym, int unused);
c1_param_list * __cdecl decl_void_parameter_list(void);
int * __thiscall sym_list_find_tag(void * scope, int name);
int __fastcall decl_check_tag_specifier(c1_specifier_state * spec);
c1_token * __cdecl decl_new_tag_record(ushort kind, c1_specifier_words * storage);
c1_type * __cdecl sym_type_enum_as_int(c1_symbol * sym);
c1_u8 __thiscall decl_tag_take_name(c1_tag_record * tag, c1_token * token);
c1_tag_lookup * __thiscall hash_scope_lookup_tag(c1_scope_object * hash_scope, void * name);
c1_tag_symbol * __cdecl decl_tag_reference_lookup(int name, ushort kind, void * * insert_fn);
c1_tag_lookup * __thiscall scope_stack_lookup_tag(c1_scope_stack * scopes, int name);
c1_tag_symbol * __cdecl decl_tag_check_kind_and_browse(c1_tag_symbol * tag, ushort kind);
void __cdecl decl_tag_copy_specifier_flags(c1_tag_symbol * tag, c1_specifier_words * specifier);
c1_tag_symbol * __cdecl decl_warn_type_definition_in_parentheses(void * name, ushort kind, int * insert, int definition);
c1_tag_symbol * __cdecl decl_tag_definition_lookup(int name, ushort kind, void * * insert_fn);
void __thiscall decl_tag_declarator_set_kind(c1_declaration * decl, ushort kind, void * * insert_fn, int unused);
void __thiscall scope_insert_through_object(void * scopes, c1_symbol * sym);
int __fastcall decl_specifier_from_type_token(c1_specifier_state * spec);
c1_tag_lookup * __thiscall scope_lookup_tag_here(c1_scope_stack * scopes, int name, char file_scope);
void __cdecl decl_declare_enumerator(void * name, c1_type * type, longlong value);
uint __stdcall hash_fn_pointer(uint key);
bool __stdcall hash_key_equal(int a, int b);
c1_type * __stdcall decl_check_empty_enumeration(void);
longlong __cdecl enum_warn_value_wrapped(longlong value, void * name);
int __fastcall decl_specifier_add_qualifier(c1_specifier_state * spec);
ushort __stdcall decl_check_varargs_calling_convention(c1_type * type, ushort flags);
void __cdecl decl_check_empty_declaration(c1_u8 * spec);
void __cdecl decl_parse_declspec(c1_specifier_words * words);
void __thiscall decl_parameter_list_set(int * list, int first, int unused);
void __thiscall decl_parameter_list_end(int * list, c1_symbol * param);
int * __thiscall scope_lookup_segment(void * this, int name);
c1_symbol * __cdecl sym_new_builtin(void * name, void * seg_class, uint id, c1_u8 cls);
c1_scope_stack * __fastcall scope_file_init(c1_scope_stack * state);
c1_type_declarator * __thiscall decl_init_declarator_over_type(c1_type_declarator * declarator, c1_type * type, c1_specifier_words * specifiers);
c1_symbol * __cdecl sym_new_declarator_placeholder(void);
ushort __cdecl decl_apply_default_calling_convention(uint code, ushort flags);
c1_symbol * __cdecl sym_new_kind12(void);
void __fastcall decl_specifiers_add_modifier(c1_specifier_state * spec);
int __fastcall sym_is_data_or_function_2(c1_symbol * sym);
void __thiscall hash_scope_emit_il(c1_scope_object * hash_scope);
c1_node * __cdecl label_new(int label_kind);
void __cdecl label_register(c1_symbol * label);
void __thiscall scope_link_closed_block(void * scope, int block);
void __cdecl label_emit_definition(c1_node * node);
void __cdecl sym_set_nesting_depth(c1_symbol * sym);
c1_symbol * __cdecl sym_alloc_record(int unused, uint kind, int arena);
c1_u8 * __thiscall decl_declare_formal_parameter(int * scope_stack, c1_declaration * decl);
void __cdecl decl_hoist_to_file_scope(c1_symbol * sym);
int __cdecl decl_begin_initialized_definition(c1_symbol * sym);
int __cdecl sym_has_scalar_type(c1_symbol * sym);
void __cdecl decl_finish_initialization(c1_symbol * sym, c1_node * node);
void __cdecl sym_set_segment_from(c1_symbol * sym, int value);
void __cdecl sym_set_segment(c1_symbol * sym, void * value);
void * __cdecl sym_segment_record(c1_symbol * sym);
void * __cdecl symtab_lookup(fe_symtab * tab, void * key);
bool __stdcall hash_key_equal_2(int a, int b);
c1_symbol * __fastcall sym_from_list_link(int symref);
int __fastcall sym_decl_position(c1_symbol * sym);
c1_symbol * __cdecl label_find_in_function(void * name);
c1_symbol * __cdecl label_find_in_function_fragment_2(c1_symbol * label);
c1_symbol * __cdecl label_new_user(int name);
uint __stdcall hash_fn_pointer_2(uint key);
c1_symbol * __cdecl decl_lookup_file_scope_twin(c1_symbol * sym);
bool __stdcall hash_key_equal_3(int a, int b);
void __cdecl decl_record_file_scope_twin(c1_symbol * key, void * value);
c1_u8 __cdecl scope_symbol_emits_late(c1_symbol * sym);
int * __thiscall dlist_insert_before(void * this, int * iter, int * pos, int * value);
char __cdecl sym_check_owner_scope(char * out, c1_symbol * sym);
c1_symbol * __cdecl decl_old_style_parameter_name(void * name);
c1_symbol * __thiscall decl_check_old_style_formal(c1_declaration * decl, c1_decl_specifiers * spec);
c1_u8 __fastcall decl_tag_parse_declspec(c1_tag_record * tag);
void __stdcall decl_check_illegal_token_pair(void);
void __cdecl decl_combine_type_specifiers_fragment(c1_u8 size_keyword, uint code, c1_specifier_state * spec);
void __cdecl decl_check_multiple_storage_classes(c1_specifier_words * words);
uint __stdcall hash_fn_name(int key);
int __cdecl sym_compare_by_entity_id(c1_symbol * * a, c1_symbol * * b);
int __cdecl decl_check_based_argument(int name);
c1_tag_symbol * __cdecl decl_report_type_redefinition(c1_tag_symbol * tag);
void __cdecl decl_warn_enum_value_out_of_range(c1_u32 value_lo, int value_hi, c1_symbol * sym);
c1_symbol * __cdecl sym_new_implicit_function(int name);
void __cdecl decl_report_bad_specifier(short n, byte * spec);
c1_symbol * __cdecl label_find_in_function_fragment(void * label_name, void * name, c1_symbol * label);
ushort __stdcall decl_check_calling_convention_fragment(void);
c1_symbol * __cdecl sym_new_object(void * name, char level);
c1_symbol * __cdecl sym_new_in_scope_arena_2(void * name);
void __cdecl decl_check_void_variable(c1_u8 flag_bit, c1_declaration * decl);
void __cdecl decl_check_formal_parameter_type(c1_u8 flag_bit, c1_tag_symbol * tag, c1_declaration * decl);
void __cdecl decl_report_illegal_storage_class(c1_declaration * decl);
void __cdecl decl_abstract_declarator_fragment_2(c1_u8 class_bits, c1_declaration * decl);
void __cdecl decl_abstract_declarator_fragment_3(c1_declaration * decl);
void __cdecl decl_abstract_declarator_fragment_4(c1_specifier_words * spec, c1_declaration * decl);
void __cdecl decl_check_export_linkage(c1_declaration * decl);
void __cdecl decl_abstract_declarator_fragment_5(c1_declaration * decl);
c1_u8 * __cdecl symtab_record_new_4(void);
c1_u8 * __cdecl symtab_record_new(int count);
int __cdecl symtab_entry_count(fe_symtab * tab);
void __cdecl symtab_iterator_init(fe_symtab_iter * it, fe_symtab * tab);
char __cdecl symtab_iterator_next(fe_symtab_iter * it);
void __cdecl decl_define_variable(c1_symbol * sym);
c1_symbol * __cdecl decl_check_extern_block_initializer(c1_u8 storage_class, c1_symbol * sym, c1_declaration * decl, c1_decl_specifiers * spec);
c1_symbol * __cdecl decl_check_dllimport_definition(c1_u8 storage_class, c1_symbol * sym, c1_declaration * decl, c1_decl_specifiers * spec);
c1_symbol * __cdecl decl_based_variable_tail(c1_symbol * sym, c1_declaration * decl);
c1_symbol * __cdecl decl_check_variable_attributes(char is_member, c1_specifier_words * spec, c1_declaration * decl);
void __cdecl decl_warn_inconsistent_dll_linkage(c1_u8 dllexport_bit, c1_declaration * decl, c1_symbol * sym);
void __cdecl decl_merge_redeclaration_fragment(char allocate_bit, c1_u8 flags22, c1_symbol * sym);
int __cdecl decl_warn_benign_type_redefinition(c1_u16 code1, c1_u16 code2);
void __cdecl sym_new_numbered_3(c1_symbol * sym);
void __cdecl decl_error_once_per_symbol(int n, c1_symbol * sym);
c1_symbol * __fastcall decl_symbol_or_new(c1_declaration * decl);
uint __fastcall decl_dll_linkage_kind(c1_specifier_words * spec);
int __fastcall sym_kind_is_declared_entity(c1_symbol * sym);
c1_type * __cdecl decl_basic_type_from_specifiers_fragment(c1_u16 code);
void __cdecl sym_set_or_clear_segment(c1_symbol * sym, int value);
void __cdecl sym_set_segment_checked(c1_symbol * sym, void * value);
void __cdecl decl_check_declarator_void_fragment(c1_type_declarator * declarator);
void __cdecl sym_new_builtin_variable(void);
c1_symbol * __cdecl sym_chain_find_name(c1_symbol * chain, void * name);
c1_symbol * __thiscall scope_stack_lookup_anonymous_member(void * scopes, int name);
void __cdecl sym_defer_emission(c1_symbol * sym);
c1_u8 __cdecl sym_is_deferrable(c1_symbol * sym);
void __stdcall sym_emit_deferred(void);
uint __stdcall sym_namemap_key(uint name_index);
uint __fastcall sym_assign_namemap_key(int * entry);
void __stdcall sym_ensure_global_helper_function(void);
void __cdecl sym_global_helper_set_decorated_name(char unique);
void __cdecl sym_global_helper_set_decorated_name_2(void);

byte __cdecl diag_warning(int level, int n, ...);
void __cdecl diag_extension_warning_or_error(int warning, int error, ...);
void __cdecl diag_write_stderr(char * text);
void __cdecl diag_begin_global(int position);
void __thiscall diag_begin(fe_diag_context * list, int position);
void __stdcall diag_end_global(void);
int __fastcall diag_end(fe_diag_context * list);
void __thiscall diag_message_collect_args(fe_message * m, va_list * args);
void __thiscall diag_format_message(fe_message * m, fe_message_buffer * buf);
void __stdcall diag_format_message_append_fragment(char * piece, fe_message_buffer * buf, int index, c1_diag_format_frame * frame);
void __cdecl diag_error_C2296_or_C2297(c1_u8 op, int operand, c1_type * type);
void __stdcall _AbortCompilerPass@4(void);
void __cdecl diag_error(short n, ...);
void __cdecl diag_error_emit(short n);
int __cdecl diag_fatal_file_errno(int n, int what, char * file);
void __cdecl diag_fatal_file_lasterror(int n);
int __cdecl diag_fatal_file(int err, int n);
__noreturn noreturn void __cdecl diag_fatal_simple(int n);
void __cdecl diag_write_fatal_C1063(char enabled);
__noreturn noreturn void __cdecl diag_fatal(int n, ...);
void __cdecl diag_note(int n, ...);
void __fastcall diag_message_list_set_state_3(fe_diag_context * list);
void __thiscall diag_message_list_add(fe_diag_context * list, int kind, short number, char * args);
void __thiscall diag_format_report_line(fe_diag_context * list, fe_message_buffer * buf, fe_message * m);
void __fastcall diag_queue_print(fe_diag_context * list);
void __cdecl diag_write_line_stderr(char * line);
void __fastcall diag_queue_release_pending(fe_diag_context * list);
void __fastcall diag_run_context_notes(fe_diag_context * list);
fe_message_buffer * __fastcall diag_message_buffer_new(fe_message_buffer * buf);
char __fastcall diag_message_buffer_grow(fe_message_buffer * buf);
void __fastcall diag_message_buffer_rewind(fe_message_buffer * buf);
fe_message * __stdcall diag_message_alloc(void);
void __cdecl diag_message_from_format(ushort * fe_message, char * format, ...);
void __thiscall diag_message_load(fe_message * m, short base, short id, va_list a);
void __thiscall diag_message_collect_args_dollar_fragment(fe_message * m, int * * ap, char * fmt, int index);
void __stdcall diag_format_message_literal_fragment(byte * scan, byte * literal, fe_message_buffer * buf, fe_message * m, int index, c1_diag_format_frame * frame);
void __stdcall diag_format_message_conversions_fragment(fe_message_buffer * buf, fe_message * m, int index, c1_diag_format_frame * frame);
void __thiscall diag_message_buffer_fill(fe_message_buffer * buf, char c, uint n);
void __thiscall diag_message_buffer_append_n(fe_message_buffer * buf, char * s, uint n);
int * __thiscall block_scope_find_link_unimplemented(c1_scope_object * scope, int * key);

int __cdecl file_read_or_fatal(void);
void __fastcall source_tracker_stub_nop_2(void * tracker);
void __fastcall source_tracker_stub_nop_3(void * tracker);
c1_token * __thiscall source_stream_next_token(c1_source_stream * stream);
int __cdecl file_read_source_block(void * buf);
void __thiscall source_tracker_stub_nop_5(void * tracker, void * p, int n);
char __thiscall source_tracker_stub_true_1(void * tracker, int arg);
int __cdecl file_make_canonical_path(char * out, char * file, uint size);
void __cdecl file_name_canonicalize(byte * name);
int __cdecl file_open_or_fatal(char * file, uint hash, int mode, int arg, int report);
int __thiscall file_record_find_canonical(void * scope, int name);
int __cdecl file_open_read_retry(char * file);
c1_u8 * __cdecl file_name_for_FAT(c1_u8 * file);
char __thiscall source_tracker_stub_true_0(void * tracker, int arg);
int __stdcall _InvokeCompilerPass@12(int argc, char * * argv, char last_in_batch);
int __cdecl c1_reset_data_section(void);
void __stdcall dynamic_init_token_save_frame(void);
void __stdcall dynamic_init_token_position(void);
void __stdcall dynamic_init_token_position_table(void);
void __stdcall static_init_il_db_buffer(void);
void __stdcall static_ctor_il_db_buffer(void);
int __cdecl c1_atexit(void * handler);
void __stdcall static_init_il_sy_buffer(void);
void __stdcall static_ctor_il_sy_buffer(void);
void __stdcall static_init_il_gl_buffer(void);
void __stdcall static_ctor_il_gl_buffer(void);
void __stdcall static_init_il_ex_buffer(void);
void __stdcall static_ctor_il_ex_buffer(void);
void __stdcall static_init_il_in_buffer(void);
void __stdcall static_ctor_il_in_buffer(void);
void __stdcall static_init_il_pending_init_buffer(void);
void __stdcall static_ctor_il_pending_init_buffer(void);
void __stdcall static_init_il_gi_buffer(void);
void __stdcall static_ctor_il_gi_buffer(void);
void __stdcall static_init_il_gi_fdef_buffer(void);
void __stdcall static_ctor_il_gi_fdef_buffer(void);
void __stdcall dynamic_init_saved_yylval(void);
void __stdcall dynamic_init_options_signature(void);
void __stdcall dynamic_init_g_pdb(void);
void __stdcall dynamic_init_pdb_state_1066eb40(void);
void __stdcall dynamic_init_pool_106681b4(void);
void __stdcall dynamic_init_pool_106681a4(void);
void __stdcall dynamic_init_pool_10668194(void);
void __stdcall dynamic_init_pool_10668184(void);
void __stdcall dynamic_init_g_name_pool(void);
void __stdcall dynamic_init_pool_10668164(void);
void __stdcall dynamic_init_g_pool_default(void);
void __stdcall dynamic_init_pool_10668144(void);
void __stdcall dynamic_init_pool_10668134(void);
void __stdcall static_init_format_template_args(void);
void __stdcall dynamic_init_msvcrt_handle(void);
void __stdcall msvcrt_handle_init(void);
void __cdecl static_init_undname(void);
void __stdcall dynamic_init_lex_position_1066c89c(void);
void __stdcall idb_clear_empty_class_record(void);
void * __cdecl static_init_pch_image(void);
int __cdecl c1_main_guarded(int argc, char * * argv);
int __cdecl c1_main(int argc, char * * argv);
void __cdecl opt_prescan_memory_switches(char * * argv);
int __cdecl opt_prescan_Bm_ZB_Zm(char * word, int pending);
void __stdcall c1_main_hook_nop(void);
void __cdecl opt_parse_command_line(int argc, char * * argv);
void __cdecl crc16_tables_init(void);
void __cdecl file_name_case_table_init(void);
void __cdecl opt_parse_switch_string(byte * s);
char * __cdecl option_next_argument(void);
int __cdecl opt_match_switch(getflags_row * table, char * word, c1_option_next_fn next_arg, int dup);
void __cdecl opt_set_switch_value(getflags_row * row, char * value, int dup);
int __cdecl opt_match_suffix(char * pattern, char * word);
long __cdecl opt_parse_number(byte * item);
int __stdcall c1_compile(void);
void __stdcall c1_compile_begin(void);
char __cdecl source_tracker_new(char minimal_rebuild, void * * object, void * * iface);
void __cdecl opt_set_target_cpu_mask(void);
void __stdcall compile_begin_nop(void);
void __cdecl c1_declare_intrinsics(void);
void __cdecl c1_new_builtin_labels(void);
void __stdcall c1_cleanup(void);
void __stdcall text_buffers_free(void);
void __cdecl block_lists_free(void);
int __cdecl c1_run_exit_handlers(void);
void __cdecl c1_main_exit_nop(void);
void __fastcall idb_object_delete(c1_obj_10654898 * obj);
void __cdecl opt_unpack_optimize_flags(int flags);
void __cdecl file_put_string_with_nul(char * s, FILE * file);
c1_u8 * __stdcall cwd_string(void);
void __cdecl file_write_or_fatal(FILE * f);
char * __cdecl misc_string_get(int id);
void __stdcall misc_strings_load(void);
char * __cdecl misc_string_find(int id);
void __cdecl fpu_store_st0_tbyte_esi(float10 value, float10 * out);
int __cdecl fpu_compare_abs(void);
uint __cdecl file_current_at_eof(void);
long __cdecl file_tell_current_source(void);
long __cdecl file_seek_current_source(long offset);
char * __cdecl path_make_default_pch_name(char * path);
char __cdecl file_name_equal(byte * a, byte * b);
ulong __cdecl opt_parse_number_2(char * item);
int * __stdcall opt_check_switch_count(void);
int __cdecl file_mtime_of_handle(int fd, int * mtime);
char * __cdecl file_copy_name_canonical(char terminator, char * file, char * out);
char * __cdecl path_make_relative(char * out, char * base_dir, char * path, size_t size);
void __cdecl c1_declare_intrinsics_fragment(c1_u16 return_code, int zero, int row_offset, c1_symbol * sym, char * * name_cursor, char * * letter_end);
void __cdecl c1_compile_begin_fragment(int zero);
byte * __cdecl opt_check_switch_length(byte * s, byte * out, int size);
void __stdcall c1_abort_cleanup(void);
void __stdcall c1_abort_if_running(void);
void __cdecl c1_set_phase(int phase);
__noreturn noreturn void __cdecl c1_raise_exit(ULONG_PTR code);
uint __stdcall opt_float_consistency_enabled(void);
uint __cdecl file_mtime(char * file);
uint __cdecl file_mtime_or_zero(int fd);
int __cdecl file_copy_contents(FILE * from, FILE * to, uint n);
char __thiscall source_tracker_stub_iface_false_0(void * iface, uint * signature, int * count);
char __thiscall source_tracker_stub_iface_false_1(void * iface, int n, uint * signature, int * count);
char __thiscall source_tracker_push(c1_source_tracker * tracker, int arg);
char __thiscall source_tracker_pop(c1_source_tracker * tracker, int arg);
void __fastcall source_tracker_mark(c1_source_tracker * tracker);
void __fastcall source_tracker_accumulate(c1_source_tracker * tracker);
void __fastcall source_tracker_delete(c1_source_tracker * tracker);
char __thiscall source_tracker_take(c1_source_tracker_iface * iface, uint * signature, int * count);
char __thiscall file_tell_seek_or_fatal(c1_source_tracker_iface * iface, int n, uint * signature, int * count);
void __thiscall source_tracker_add_bytes(c1_source_tracker * tracker, void * p, int n);
void __fastcall source_tracker_reset(c1_source_tracker_iface * iface);
int * __thiscall file_record_find(void * scope, int name);
int * __thiscall file_record_lookup_or_new(void * scope, char * file, uint hash);
void __cdecl file_skip_header_2(HANDLE h, char * file_name);
void __cdecl file_skip_header(HANDLE h, char * file_name);
int __cdecl fpu_store_float_if_in_range(longdouble * value, float * out);
int __cdecl fpu_store_float_constant(float * value, float_const * out);
longdouble __cdecl fpu_round_st0(void);
int __cdecl fpu_store_constant_rounded(float10 value, float10 * out);

int __cdecl expr_apply_implicit_conversion(c1_node * node);
c1_node * __cdecl tree_new_constant(c1_type * type, c1_u32 * value, int arena);
c1_node * __cdecl tree_new_node(c1_u8 op, c1_node * left, c1_node * right, c1_type * type);
int __cdecl expr_check_illegal_for_type(c1_u8 op, char form, c1_node * left, c1_node * right);
ulonglong __fastcall _aullshr(byte count, uint hi, uint lo);
int __cdecl fold_add_overflows(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
longlong __cdecl expr_eval_constant_expression(c1_node * node);
c1_node * __cdecl expr_build_binary(c1_u8 op, c1_node * left, c1_node * right);
void __cdecl conv_balance_binary_operands(c1_node * * left, c1_node * * right);
c1_type * __cdecl conv_arithmetic_result_type(c1_type * type, c1_node * * other);
c1_node * __cdecl fold_binary_constant_expression(c1_node * node, c1_node * left, c1_node * right);
c1_type * __cdecl conv_usual_arithmetic(c1_u8 op, c1_type * type, c1_type * type2);
c1_node * __cdecl expr_identifier(int name);
c1_node * __cdecl expr_reference_identifier(c1_symbol * sym);
c1_node * __cdecl expr_reference_named_entity(c1_symbol * sym);
c1_node * __cdecl tree_new_enumerator_constant(c1_symbol * sym);
c1_node * __cdecl expr_check_binary_operand_types(c1_node * node);
c1_node * __cdecl expr_build_unary(c1_u8 op, c1_node * operand);
c1_node * __cdecl fold_truncate_to_type_width(uint lo, int hi, c1_type * type, c1_node * operand, c1_node * typed_by);
c1_node * __cdecl fold_unary_constant(c1_node * operand, c1_node * node);
c1_node * __cdecl tree_new_unary(c1_u8 op, c1_type * type, c1_node * operand);
char __cdecl intrinsic_is_enabled(int index);
void __cdecl intrinsic_mark_function(c1_symbol * sym, int index);
c1_node * __cdecl tree_new_int_constant(int value);
c1_node * __cdecl tree_new_int_constant_raw(int value);
c1_node * __cdecl tree_new_symbol_ref(c1_symbol * sym);
c1_node * __cdecl tree_new_binary(c1_u8 op, c1_node * left, c1_node * right);
c1_node * __cdecl tree_new_three_fields_flagged(c1_u32 low, c1_u32 high, int size);
c1_node * __cdecl tree_new_sized_int_constant(c1_u32 low, c1_u32 high, int size);
c1_node * __cdecl tree_new_rvalue(c1_node * operand);
c1_node * __cdecl expr_warn_no_effect(c1_node * expr, char statement);
c1_node * __cdecl expr_build_member_access(c1_u8 op, c1_node * object, int name);
int __cdecl expr_refers_to_local_variable(c1_node * node);
int __cdecl conv_check_conversion_to_type(c1_u8 op, c1_type * type, c1_node * node);
c1_node * __cdecl tree_strip_casts_and_segment_bases(c1_node * node);
c1_node * __cdecl conv_convert_to_type(c1_u8 op, c1_type * type, c1_node * node);
c1_node * __cdecl conv_convert_basic(c1_u8 op, c1_type * type, c1_node * node);
c1_node * __cdecl tree_new_cast(c1_type * type, c1_node * operand);
c1_node * __cdecl expr_build_cast_expression(c1_u8 op, int type_name, c1_node * operand);
c1_node * __cdecl expr_build_cast(c1_u8 op, c1_type * type, c1_node * node);
int __cdecl conv_classify_cast(c1_type * type, c1_node * node, int mode);
c1_node * __cdecl expr_sizeof_type(c1_type * type);
int __cdecl conv_classify_types(c1_type * to, c1_type * from, int mode);
int __cdecl conv_classify_types_fragment(int classification);
int __cdecl conv_classify_pointer_types(c1_type * to, c1_type * from, int mode);
int __cdecl conv_compare_pointee_qualifiers(int mode, int rank, ushort to_flags, ushort from_flags);
int __cdecl conv_rank_based_pointers(int rank, c1_u8 to_flags, c1_u8 from_flags);
uint __cdecl fold_check_multiply_overflow(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
uint64_t __stdcall _aulldiv(uint32_t lo, uint32_t hi, uint32_t dlo, uint32_t dhi);
uint __cdecl fold_check_subtract_overflow(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
void __cdecl conv_warn_arithmetic_conversion(c1_u8 op, c1_node * node, c1_type * type);
void __cdecl conv_warn_arithmetic_conversion_fragment(ushort code, char ms_extensions, uint lo, uint hi, c1_type * target, int op, c1_type * type);
int __cdecl conv_constant_out_of_range(uint size, int target_unsigned, int source_unsigned, uint lo, uint hi);
ulonglong __cdecl conv_cast_constant(char op, int node, c1_type * type);
ulonglong __cdecl conv_truncate_constant_to_type(uint lo, int hi, c1_type * source_type, int value_high, char op, int target_size, c1_type * type);
ulonglong __cdecl conv_warn_cast_truncates_constant(uint check_hi, char ms_extensions, uint lo, uint check_lo, int value_high, byte op, int target_size, c1_type * type);
ulonglong __cdecl conv_cast_constant_fragment(uint lo, c1_type * type);
c1_node * __cdecl fold_float_constant_conversion(c1_u8 op, c1_type * type, c1_node * node);
int __cdecl expr_fold_string_intrinsic(c1_node * call);
c1_node * __cdecl conv_convert_node_to_type(c1_u8 op, c1_type * type, c1_node * node);
c1_node * __cdecl expr_build_sizeof(c1_node * operand);
int __cdecl conv_rank_to_void_pointer(int rank, c1_type * to_layer, c1_type * from_layer);
int __cdecl expr_call_argument_size(c1_node * node);
c1_type * __cdecl conv_array_to_pointer_type(c1_node * node);
int __cdecl conv_warn_different_qualifiers(c1_u8 op, c1_u16 target_qualifiers, c1_u16 source_qualifiers, int relaxed, int unused);
void __cdecl expr_check_operand_conversion_unless_null(c1_u8 op, c1_node * left, c1_node * right);
c1_node * __cdecl expr_warn_cast_on_lvalue(c1_node * node, uint mode);
c1_node * __cdecl expr_build_address_of(c1_node * operand, uint mode);
char * __cdecl expr_address_of_through_casts(c1_node * node);
c1_symbol * __cdecl expr_find_base_symbol(c1_node * node);
int __cdecl conv_promote_operand(c1_type * type, c1_node * node);
bool __cdecl expr_builtin_operator_valid_for_class(byte op, char form, int is_left);
c1_node * __cdecl expr_find_lvalue_symbol_node(c1_node * node);
c1_node * __cdecl expr_declare_undefined_function(int name);
c1_node * __cdecl expr_call_begin(c1_node * callee);
void __cdecl expr_push_call_context(c1_type * type);
c1_symbol * __cdecl expr_lvalue_symbol_counting_calls(c1_node * node);
c1_node * __cdecl tree_append_list_item(c1_node * list, c1_node * expr, int mode);
c1_node * __cdecl expr_check_call_arguments(c1_node * node, int mode);
c1_node * __cdecl expr_build_call(c1_node * node);
c1_type * __cdecl expr_check_based_void_pointer(c1_type * type);
c1_node * __cdecl tree_new_node_typed(c1_u8 op, void * left, c1_type * type);
c1_node * __cdecl expr_string_literal(c1_node * literal);
int __cdecl expr_string_pooling_enabled(void);
char * __cdecl expr_string_literal_lookup_name(char * * text, char wide);
int __cdecl intrinsic_name_lookup(void * name);
void __cdecl intrinsic_unmark_function(c1_symbol * sym);
uint __cdecl float_const_from_string(char * text, float_const * out);
int __cdecl fold_float_to_double_checked(float10 * in, double * out);
int __cdecl float_const_set_double(double * value, float_const * out);
int __cdecl float_const_compare_mask(ushort mask, float10 * a, float10 * b);
ushort __cdecl expr_warn_array_bounds_overflow(c1_symbol * sym, c1_node * node);
uint64_t __stdcall _alldiv(uint32_t lo, uint32_t hi, uint32_t dlo, uint32_t dhi);
uint64_t __stdcall _aullrem(uint32_t lo, uint32_t hi, uint32_t dlo, uint32_t dhi);
void __cdecl conv_warn_float_truncation_1(c1_u8 op, c1_node * node, c1_type * target, uint * out_value, char check_round_trip);
void __cdecl conv_warn_float_truncation_2(byte op, c1_node * node, c1_type * target);
void __cdecl int64_to_digits(int * value, char * buf, uint32_t radix, int negative);
int __cdecl fold_float_to_int64_checked(float10 * value, longlong * out);
c1_node * __cdecl expr_based_pointer_fixup(c1_node * node);
bool __cdecl expr_same_based_base(c1_node * a, c1_node * b);
c1_node * __cdecl expr_find_based_base(c1_node * node);
c1_node * __cdecl conv_warn_negative_to_unsigned(uint op, int is_unsigned, c1_node * right, c1_node * left, char long_operand, char op_char, uint left_size, uint op_saved, uint right_size, c1_node * node, c1_type * result_type, uint size);
c1_node * __cdecl fold_integer_overflow_fragment(int is_unsigned, int hi, uint lo, char long_operand, char op, c1_node * node, c1_type * result_type, int size);
c1_node * __cdecl fold_binary_constant_expression_fragment(uint code, int is_unsigned, int hi, uint lo, c1_node * result, char long_operand, c1_type * result_type, int size);
c1_node * __cdecl fold_float_constant(c1_node * node, float_const * a, float_const * b);
c1_node * __stdcall expr_report_not_a_member(void);
c1_node * __cdecl expr_build_member_access_fragment(uint qualifiers, c1_node * member, int lvalue_flag);
c1_node * __stdcall expr_report_not_a_function(void);
c1_node * __cdecl expr_warn_no_prototype(int level, c1_symbol * sym, c1_node * callee);
c1_node * __cdecl expr_check_too_many_arguments(uint flags, c1_call_context * ctx, c1_node * item, c1_node * node);
c1_node * __cdecl expr_check_intrinsic_argument_count(int nargs, c1_call_context * ctx, int expected, c1_node * call);
c1_node * __cdecl expr_report_too_few_arguments(c1_call_context * ctx, c1_node * call);
c1_node * __cdecl expr_report_argument_bytes_differ(c1_node * call);
c1_symbol * __cdecl expr_report_undeclared_identifier(int name);
c1_node * __cdecl expr_report_register_address(c1_symbol * sym, c1_type pointer_type);
void __cdecl fold_float_binary(c1_type * type, int is_unsigned, fe_il_buffer * buf, c1_node * value, uint addr_offset, c1_symbol * addr_symbol, int addr_mode, char * format, float fvalue, longlong value64, uint value_lo, int value_hi, double dvalue, float_const xvalue, c1_symbol * init_sym, c1_node * init, char value_is_integral);
c1_node * __cdecl expr_warn_operator_precedence(c1_node * node, c1_node * left, c1_node * right);
c1_node * __cdecl expr_build_binary_fragment(c1_node * inner, c1_type * type, c1_node * node, c1_node * left, c1_node * right);
c1_node * __cdecl expr_build_binary_fragment_2(byte kind_bits, c1_node * node);
c1_type * __cdecl conv_warn_nonlvalue_array_2(c1_type pointer_type, c1_node * object, c1_node * node);
c1_node * __cdecl expr_report_register_address_2(uint storage, c1_node * node, c1_type * type);
c1_node * __cdecl expr_warn_signed_unsigned_compare(c1_node * right, c1_node * left, c1_node * node);
c1_node * __cdecl expr_check_binary_operand_types_fragment(c1_node * right, c1_type * type);
int __cdecl conv_warn_indirection_levels(c1_u8 op, c1_type * type1, c1_type * type2);
void __stdcall conv_warn_function_data_pointer(void);
int __cdecl conv_report_function_pointer_attributes(c1_u8 op);
int __cdecl conv_warn_indirection_levels_2(c1_u8 op);
void __cdecl conv_warn_different_bases(c1_u8 op, c1_type * type, c1_type * type2);
c1_node * __cdecl expr_warn_cast_on_lvalue_fragment(c1_node * found, c1_node * node, byte mode);
c1_node * __cdecl expr_report_const_lvalue(char is_const, c1_node * object, c1_node * node, byte mode);
c1_node * __cdecl expr_check_based_operator(c1_node * right, c1_node * left);
c1_node * __cdecl conv_warn_function_to_data_pointer(uint code, c1_node * node, c1_type * type, c1_u8 op);
c1_node * __cdecl conv_warn_greater_size(c1_node * node, c1_type * type, c1_u8 op);
void __cdecl conv_warn_constant_conversion(uint source_code, uint target_code, char ms_extensions, uint lo, uint hi, c1_type * source_type, int op, c1_type * type);
void __cdecl conv_warn_arithmetic_conversion_fragment_2(void);
c1_node * __cdecl conv_convert_basic_fragment(c1_u8 op, c1_node * node, c1_type * type);
c1_node * __cdecl fold_float_overflow_check(byte target_code, uint source_code, c1_node * node, c1_type * type, float_const value);
c1_node * __cdecl fold_float_constant_conversion_fragment(char ms_extensions, uint code, char char_unsigned, c1_type * source_type, c1_node * node, c1_type * type, c1_type type_copy, float_const value);
ulonglong __cdecl conv_warn_cast_truncates(uint lo, int hi, c1_type * source_type, int value_high, char op, int target_size, c1_type * type);
ulonglong __cdecl conv_warn_cast_truncates_2(uint lo, int hi, c1_type * source_type, int value_high, char op, int target_size, c1_type * type);
ulonglong __cdecl conv_warn_constant_truncation(uint lo, int hi, c1_type * source_type, int value_high, char op, int target_size, c1_type * type);
c1_node * __cdecl conv_convert_to_type_fragment(c1_node * node, c1_type * type);
int __cdecl fold_float_round_to_width(float_const * value, int width);
int __cdecl float_fold_add_constants(float_const * a, float_const * b, float_const * out);
int __cdecl float_fold_subtract_constants(float_const * a, float_const * b, float_const * out);
int __cdecl float_fold_multiply_constants(float_const * a, float_const * b, float_const * out);
int __cdecl fold_float_store_result_3(float_const * a, float_const * b, float_const * out);
int __cdecl fold_float_to_int32_checked(float10 * in, int * out);

void __stdcall il_emit_line_record(void);
int __thiscall il_buffer_reserve(Buffer * buf, int n);
void __cdecl il_emit_symbol(int record_class, c1_symbol * sym);
void __cdecl il_emit_symbol_fragment_5(uint kind_bits, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_record_fragment(uint type_code, uint kind_bits, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __thiscall il_buffer_put_compact_u16_unchecked(fe_il_buffer * buf, ushort value);
void __thiscall il_buffer_put_id(fe_il_buffer * buf, uint id);
char __cdecl il_emit_pragma_or_segment_record(int kind);
void __cdecl il_emit_byte_record(c1_u8 b);
int __cdecl il_line_number_emit_limit(void);
c1_u8 * __cdecl record_pos_new(short a, short b, int * p);
void __stdcall tu_external_declaration_end(void);
void __thiscall il_emitter_plain_define_macro(c1_il_emitter * this, int * macro);
uint __fastcall il_symbol_key_2(int sym_keys);
void __cdecl il_emitters_create(char * browse_file);
char __thiscall il_emitter_plain_reopen(c1_il_emitter * this);
void __thiscall il_file_open(fe_il_buffer * buf, byte * prefix, char * suffix, char * mode);
int __thiscall il_buffer_put_byte7(fe_il_buffer * buf, uint value);
c1_il_emitter * __stdcall il_emitter_get_preferred(void);
c1_u8 __thiscall il_buffer_reserve_ok(fe_il_buffer * buf, int n);
c1_il_emitter * __cdecl il_emitter_get_default(void);
void __stdcall il_open_ex(void);
void __fastcall il_buffer_flush(fe_il_buffer * buf);
void __stdcall il_emitter_begin_region_at_top_level(char browse);
void __stdcall vtable_nop_2(void);
uint __cdecl il_function_option_word(void);
int __thiscall il_buffer_grow(Buffer * buf, int n);
void __stdcall il_globals_rewind(void);
void __cdecl il_emit_tuple(int op, c1_node * node);
void __cdecl il_emit_global_symbol(int * sym_link);
int __thiscall il_buffer_put_bytes(fe_il_buffer * buf, uint * src, uint n);
void __cdecl il_emit_symbol_with_mode(int kind, int symref, char mode);
void __cdecl il_emit_symbol_reference(fe_il_buffer * buf, c1_symbol * sym, uint id);
void __cdecl il_emit_expression_tree(c1_node * node);
int __cdecl il_key_is_global_helper_function(int key);
void __fastcall il_emit_function_symbols(int * scope);
void __stdcall il_emit_function_labels(void);
void __fastcall block_scope_emit_il(c1_scope_object * block_scope);
void __stdcall il_symbol_key_counter_reset(void);
void __cdecl il_reset_last_line_and_file(void);
void __cdecl il_begin_function_body(int generated);
void __cdecl il_emit_type_descriptor(int op, c1_node * node, int mode);
void __cdecl il_emit_type_descriptor_fragment(uint type_flag_bits, c1_type * type, uint aggregate_size, uint descriptor);
void __cdecl il_emit_integer_constant(uint lo, int hi, int size);
void __cdecl il_buffer_put_int_sized(uint * value, int size, fe_il_buffer * buf);
void __fastcall tu_end_emit_global_scope(int * scope);
void __stdcall tu_emit_function_records(void);
void __cdecl il_emit_source_file(char * file_name);
void __fastcall il_buffer_destroy(fe_il_buffer * buf);
void __fastcall il_buffer_close(fe_il_buffer * buf);
int __fastcall il_buffer_close_file(fe_il_buffer * buf);
void __stdcall il_emitters_free(void);
void __thiscall il_emitter_browse_assign_entity_id(c1_il_emitter_browse * this, uint * out_id, uint id);
void __thiscall il_emitter_browse_reference_macro(c1_il_emitter_browse * this, int * macro);
void __thiscall il_emitter_browse_define_symbol(c1_il_emitter_browse * this, c1_symbol * sym);
void __stdcall il_emitter_browse_begin_block(void);
void __thiscall il_emitter_browse_set_owner(c1_il_emitter_browse * this, c1_symbol * sym);
uint __thiscall il_emitter_browse_entity_id(c1_il_emitter_browse * this, c1_symbol * sym);
void __stdcall il_emitter_browse_end_block(void);
void __thiscall il_emitter_browse_reference_symbol(c1_il_emitter_browse * this, c1_symbol * sym);
void __thiscall il_emitter_browse_end_module_if(c1_il_emitter_browse * this, int force);
void __stdcall il_emitter_browse_end_module(void);
void __thiscall il_emitter_browse_define_macro(c1_il_emitter_browse * this, uint * * macro);
void __stdcall il_emitter_browse_begin_module(void);
void __fastcall il_emitter_browse_begin_region(c1_il_emitter_browse * il_emitter_browse);
void __cdecl il_emit_debug_record(int kind, ...);
void __cdecl il_emit_global_symbol_debug_types(int * symref);
void __thiscall il_emitter_plain_define_symbol(c1_il_emitter * this, c1_symbol * sym);
char __fastcall il_emitter_browse_reopen(c1_il_emitter_browse * emitter);
void __fastcall il_emitter_browse_open(c1_il_emitter_browse * il_emitter_browse);
void __thiscall il_buffer_put_byte(fe_il_buffer * buf, c1_u8 b);
void __cdecl il_emit_debug_record_10(void);
void __thiscall il_buffer_put_counted_bytes(fe_il_buffer * buf, ushort length, void * bytes);
void __fastcall il_emitter_browse_finish(c1_il_emitter_browse * emitter);
void __stdcall il_emitter_browse_flush(void);
void * __cdecl record3_new_from(int * src, int arena);
c1_u8 * __cdecl record3_new(int a, int b, int c, int arena);
void __fastcall il_emitter_suspend_enter(char * state);
void __cdecl il_emit_debug_record_body(uint offset, uint * args, char * format, int kind);
void __cdecl il_emitters_discard(void);
void __fastcall il_emitter_browse_discard(c1_il_emitter_browse * il_emitter_browse);
void __fastcall il_emitter_browse_region_boundary(c1_il_emitter_browse * il_emitter_browse);
void __stdcall il_emitter_plain_region_boundary(void);
void __thiscall il_emitter_browse_abort(c1_il_emitter_browse * emitter);
void __stdcall il_emitter_browse_record_11(void);
void __stdcall il_emitter_browse_input_refilled(void);
void __thiscall il_emitter_browse_pch_name(c1_il_emitter_browse * emitter, char * pch_name);
void __thiscall il_emitter_browse_pch_mark(c1_il_emitter_browse * emitter);
uint __thiscall il_emitter_plain_entity_id(c1_il_emitter * emitter, c1_symbol * sym);
void __thiscall il_emitter_plain_assign_entity_id(c1_il_emitter * emitter, uint * out_id, uint id);
void __stdcall il_emitter_plain_open(void);
ushort __cdecl counted_array_count(ushort * array);
void __cdecl il_emit_type_descriptor_fragment_2(uint descriptor, uint descriptor_size, ushort type_class, uint aggregate_size);
void __cdecl il_emit_global_symbol_fragment(c1_symbol * sym, char from_pch);
void __cdecl il_emit_symbol_fragment_4(c1_symbol * sym, int typedef_class, uint saved_esi, uint saved_ebp, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, int frame_20, c1_type * base_type, uint basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, uint rec_word2, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_part(c1_type * unsized_type, uint field_value, c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_fragment(uint field_value, c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_fragment_2(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_fragment_3(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_record_fragment_2(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_record_fragment_3(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_inline_fragment(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * type, c1_type * derived_type, uint * stored_record, c1_type * base_type, ushort basic_code, int is_array, char * codes, uint elem_flag_bits, uint rec_word0, uint rec_word1, ushort rec_fflags, ushort rec_fflags_high, int record_class, c1_symbol * sym_arg);
void __cdecl il_emit_tuple_symbol_operand(char * shape, c1_symbol * sym, c1_node * cur_node, char * shape_cursor, int op, c1_node * node);
void __cdecl il_emit_tuple_fragment(c1_node * cur_node, char * shape_cursor, int op, c1_node * node);
uint __cdecl il_symbol_key_assign(c1_symbol * sym);
char __cdecl il_emit_source_file_change(int kind, int kind_arg);
void __thiscall il_buffer_append_buffer(fe_il_buffer * src, fe_il_buffer * dst);
void __cdecl il_emitter_select(char keep);
void __cdecl ilstore_open(void * pdb);
void __cdecl ilstore_report_error(void);
void __stdcall ilstore_release(void);
void __cdecl ilstore_open_streams(void * pdb);
void __stdcall ilstore_release_module(void);
void __thiscall ilstore_put_record(fe_il_buffer * buf, int key, int value);
void __thiscall ilstore_delete_record(fe_il_buffer * buf, int key);
void __thiscall ilstore_open_stream(fe_il_buffer * buf, char * prefix, char * suffix);
void __fastcall ilstore_flush(fe_il_buffer * buf);
void __fastcall ilstore_close(fe_il_buffer * buf);
int __thiscall il_buffer_put_pch_reference(fe_il_buffer * buf, int * unused);
void __cdecl ilstore_query_record(int key, int kind, void * out);
void __cdecl ilstore_fatal_write_error(int key, int size);
void __cdecl ilstore_open_for_gi(void);
void __cdecl il_emit_end_of_globals(void);
void __cdecl il_files_close(char keep_db);
void __stdcall il_files_open(void);
size_t __cdecl il_file_write_buffer(size_t buf);
void __fastcall il_buffer_init_empty(int * buf);
int __thiscall il_buffer_set_memory(Buffer * buf, c1_u8 * start, c1_u8 * cur);
void __fastcall il_buffer_free(int * buf);
int __thiscall il_buffer_reserve_get_cur(Buffer * buf, int n, c1_u8 * * cur);
int __thiscall il_buffer_reserve_advance(Buffer * buf, int n, c1_u8 * * pos);
int __thiscall il_buffer_append(Buffer * buf, void * src, uint n, c1_u8 * * pos);
void __cdecl tu_defer_symbols_in_list(c1_symbol_cell * list);

int __cdecl lex_trigraph(void);
int __cdecl lex_trigraph_replace(byte * input, char qmark);
c1_token * __fastcall token_next(int * reader);
c1_token * __cdecl lex_scan_token_directive_fragment(c1_fputc_fn put_char, uint ch, c1_fwrite_fn write_text, char wide_string, uint ch_cell);
c1_token * __cdecl lex_scan_token_fragment(void);
c1_token * __cdecl lex_scan_token_fragment_2(void);
c1_token * __cdecl lex_scan_token_fragment_3(void);
c1_u8 * __cdecl lex_scan_new_line(void);
c1_token * __cdecl lex_scan_new_line_fragment(c1_token * token);
int __cdecl lex_skip_line_start_comment(void);
void __cdecl lex_skip_line_comment(void);
int __cdecl lex_scan_identifier(byte first);
c1_token_cursor * __thiscall token_buffer_init(c1_token_cursor * buffer, int arena);
void __thiscall token_source_push(int * stack, int stream, int arena, int kind, int on_pop, int * position);
c1_token * __cdecl lex_scan_number_token(byte first, int in_asm);
int __cdecl lex_line_splice(void);
byte __cdecl lex_get_char(void);
c1_token * __cdecl yylex_c(void);
int __cdecl lex_buffer_refill(void);
byte __stdcall lex_getc(void);
longlong __cdecl lex_scan_integer_constant(byte * digits, int count, int base);
int __cdecl lex_hex_digit_value(uint c);
c1_type * __cdecl lex_decimal_literal_type(uint * value);
c1_token * __cdecl yylex_classify_identifier(c1_token * token);
c1_type * __cdecl lex_hex_octal_literal_type(uint * value);
fe_name * __cdecl name_intern_hashed(c1_u8 * text, uint hash, uint len, byte * is_new);
void __thiscall lex_source_unget_token(c1_source_stream * stream, c1_token * token);
uint __cdecl lex_scan_identifier_slow(c1_u8 * start, uint hash, byte c);
void __stdcall lex_check_end_of_file(void);
byte __cdecl lex_next_significant_char(byte c);
byte __cdecl lex_skip_comment(byte c);
byte __cdecl lex_skip_comment_check_slash_star(uint white_class, uint keep_comment_bit, uint keep_comment_mask);
void __cdecl lex_skip_to_char(byte quote);
void __stdcall lex_skip_whitespace(void);
void __cdecl lex_skip_line_comment_check(uint keep_comment_bit, uint keep_comment_mask);
void __thiscall token_stream_append(c1_saved_token_stream * stream, c1_token * token);
void __fastcall token_reader_mark_position(c1_saved_token_stream * stream);
c1_token * __fastcall token_stream_next_raw(c1_saved_token_stream * stream);
void __thiscall token_stream_unget(c1_saved_token_stream * stream, c1_token * token);
c1_token * __cdecl token_new_position_marker(int arena);
fe_name * __cdecl name_intern(char * s);
c1_saved_token_stream * __thiscall token_stream_init(c1_saved_token_stream * stream, int arena, byte flag);
void __cdecl lex_copy_text_to_arena(c1_string_value * out, c1_u8 * text, uint len, int arena);
void __cdecl lex_scan_string_literal_entry(c1_u8 wide, char quote);
void __stdcall lex_scan_string_literal(undefined4 ebx, undefined4 edi, undefined4 esi);
fe_name * __cdecl name_intern_file_name(char * file);
void __stdcall token_buffers_init(void);
LPVOID __cdecl virtual_reserve_commit_or_fatal(SIZE_T reserve, SIZE_T commit);
void __cdecl lex_mark_mbcs_lead_bytes(void);
void __cdecl token_static_records_init(void);
void __stdcall name_table_init(void);
void __cdecl keywords_init(void);
void __cdecl name_intern_keyword(byte * text);
void __cdecl name_intern_keyword_fragment(int * link, int * * bucket, uint length, uint hash, c1_u8 * text, uint saved_length, int * * saved_bucket);
void __cdecl keyword_unreserve(byte * name);
void __cdecl keyword_mark_cpp_only(byte * spelling);
void __cdecl keyword_mark_reserved_future_use(byte * name);
void __cdecl keyword_mark_obsolete(byte * name);
void __cdecl keyword_mark_obsolete_export(byte * spelling);
void __cdecl keyword_mark_not_supported(byte * name);
void __cdecl keyword_mark_not_yet_supported(byte * spelling);
void __stdcall token_arenas_reset(void);
void __cdecl keywords_intern(void);
void __cdecl lex_begin_source_file(fe_vector * defines);
long __cdecl lex_time_now(long * timer);
void __stdcall lex_reset_buffers(void);
bool __stdcall lex_input_at_end(void);
char __cdecl lex_try_forced_include(void);
char __cdecl lex_push_next_forced_include(void);
int __fastcall lex_line_number_of_position(int * pos);
c1_type * __cdecl lex_long_literal_type(uint * value);
c1_type * __cdecl lex_unsigned_literal_type(uint * value);
ushort __cdecl lex_scan_escape_sequence(byte c, int wide);
ushort __cdecl lex_scan_escape_sequence_return_char(byte ch);
fe_name * __cdecl name_intern_symbol_decorated(c1_symbol * sym);
c1_u8 * __cdecl lex_scan_character_constant(int wide, ushort * chars, ushort count);
void __stdcall token_buffers_free(void);
c1_token * __cdecl lex_scan_number(char * out);
int __cdecl lex_scan_pp_number_text(byte * buffer);
void __cdecl lex_concatenate_strings(c1_string_value * dst, c1_yystype * src);
c1_type * __cdecl lex_unsigned_long_literal_type(uint * value);
void __stdcall lex_clear_lead_byte_classes(void);
c1_token * __cdecl lex_report_unexpected_eof_fragment(void * tag, c1_token * token);
c1_token * __cdecl lex_scan_token(c1_fputc_fn put_char, c1_fwrite_fn write_text, char wide_string, uint ch_cell);
c1_token * __cdecl lex_scan_token_fragment_4(void);
c1_token_stream * __thiscall token_stream_scalar_deleting_dtor(c1_token_stream * stream, byte flags);
c1_token * __fastcall token_stream_peek_non_marker(c1_saved_token_stream * stream);
int __cdecl lex_skip_comment_in_directive(void);
uint __cdecl lex_report_unexpected_eof_2(void);
uint __cdecl lex_scan_identifier_slow_overflow(void);
void __cdecl lex_push_injected_text(int arg);
void * __cdecl lex_input_base_ptr(void);
int __stdcall lex_input_bytes_left(void);
int __cdecl lex_trigraph_replace_refill(byte * input, char qmark);
void * __cdecl lex_source_input_ptr(void);
c1_token * __cdecl token_next_fragment(c1_token * token);
void __cdecl lex_skip_whitespace_fragment(uint keep_comment_bit, uint keep_comment_mask);
void __cdecl lex_warn_comment_continuation(void);
void __stdcall lex_skip_line_comment_fragment_2(void);
void __cdecl lex_skip_line_comment_fragment(void);
char * __cdecl lex_check_string_length(char * text, size_t len);
void __cdecl lex_warn_pascal_string_length(c1_string_value * lit);
c1_u8 * __cdecl lex_scan_new_line_fragment_2(uint flags_c4, int first_line, c1_fputc_fn put_char);
c1_u8 * __cdecl lex_scan_new_line_fragment_4(int first_line, c1_fputc_fn put_char);
c1_u8 * __cdecl lex_scan_new_line_fragment_3(void);
c1_u8 * __cdecl lex_check_hex_digits(byte next_char, byte * digits_end, int radix, c1_type * type, longlong value);
c1_u8 * __cdecl lex_scan_integer_literal_radix_suffix(uint suffix, byte next_char, byte * digits_end, int radix, c1_type * type, longlong value);
c1_token * __cdecl lex_scan_number_token_fragment(void);
c1_type * __cdecl lex_scan_sized_int_suffix(char is_unsigned);
c1_type * __cdecl lex_sized_literal_type(uint * value);
c1_type * __cdecl lex_sized_unsigned_literal_type(uint * value);
byte __cdecl lex_skip_mbcs_trail_byte(void);
void __cdecl lex_put_string_byte(byte c, c1_byte_block_list * buf);
fe_name * __cdecl name_new_S(void);
c1_token * __fastcall lex_source_peek_token(c1_source_stream * stream);
char * __cdecl name_encode_for_stream(char * out, byte * name);
void __cdecl lex_line_comment_copy_or_skip(void);

void * __thiscall arena_alloc(fe_arena * a, int n);
int __fastcall arena_grow(fe_arena * a);
void * __cdecl mem_xmalloc(uint n);
void __fastcall arena_reset_ptr(fe_arena * a);
c1_scope_lookup * __thiscall block_scope_lookup_by_kind(c1_scope_object * block_scope, int name);
void __thiscall vector_push_triple(int * v, int a, int b, int c);
void * __fastcall vector_push_12(int * vector);
void __thiscall pool_reserve(fe_pool * pool, int bytes);
c1_u8 * __thiscall pool_commit_pages(fe_arena * a, int pages, int * bytes_left);
int __cdecl str_differ_n(char * a, char * b, int n);
byte * __cdecl str_find_trailing_space(byte * text, byte * end);
int * __fastcall list_alloc_cell(int * list);
void __fastcall list_pop_cell(int * list);
void __cdecl list_cell_clear(int * cell);
c1_u8 * __cdecl arena_alloc_copy(c1_u8 * s, int arena, uint n);
void __thiscall pool_construct(fe_pool * pool, int min_pages);
void __cdecl arenas_init_all(void);
void __cdecl arenas_init_all_fragment(fe_arena * arena, void * descriptor);
void __cdecl arenas_init(void);
byte __thiscall arena_reserve(fe_arena * a, void * descriptor, void * address);
uint __cdecl arena_scaled_reserve_size(void * descriptor);
void __fastcall arena_reset_to_base(fe_arena * a);
void __cdecl pools_init_all(void);
void __thiscall pool_init_on_arena(fe_pool * pool, int arena);
fe_vector * __cdecl vector_new(c1_u16 capacity, int arena);
void __cdecl vector_push(fe_vector * v, void * item);
c1_u8 * __cdecl arena_alloc_aligned(int n);
void __fastcall vector_new_main_arena(int * vector);
c1_u8 * __thiscall pool_alloc_raw(fe_pool * pool, uint n);
int __stdcall DllMain(void * instance, ulong reason, void * reserved);
int __cdecl list_push_in_arena(int * head, int arena);
void __cdecl mem_free(void * p);
void __stdcall arenas_free_all(void);
void __fastcall arena_release(fe_arena * a);
void __cdecl free_list_destroy(c1_byte_block_list * * owner);
char * __cdecl mem_xstrdup(char * s);
c1_u8 * __cdecl arena_or_pool_alloc(uint n, int arena);
int __cdecl str_compare_nocase(char * a, char * b);
void __cdecl free_list_push_124c(c1_symbol * sym);
void __stdcall free_list_pop_124c(void);
void __cdecl list_pop_head(int * head);
uint * __cdecl pair_init_zero_value(uint * out, int value);
void __stdcall vector_constructor_iterator(void * array, int size, int count, void * ctor);
int __cdecl mem_chain_read(c1_byte_block_list * cursor, void * dest, uint n);
void __cdecl free_list_mark_block_end(c1_byte_block_list * list);
char * __cdecl str_concat_malloc(char * a, char * b);
c1_symbol_vector * __cdecl vector_grow_checked(c1_symbol_vector * v);
void __cdecl vector_release(int sym);
short * __cdecl vector_find_or_add(short * set, int value);
c1_vector_iterator * __cdecl vector_iterator_init(c1_vector_iterator * it, void * vector);
char __cdecl vector_iter_next(int * it);
fe_vector * __cdecl vector_grow(fe_vector * v);
fe_vector * __cdecl vector_copy(fe_vector * src, int arena, void * copy_fn);
int __cdecl str_ends_with(char * s, char * suffix);
void * __cdecl mem_xrealloc(void * p, uint n);
c1_u8 * __cdecl str_dup_arena(char * s, int arena);
c1_u8 * __cdecl arena_or_heap_object_new(int size, char in_arena, fe_arena * a);
void __stdcall pools_reset(void);
void __fastcall pool_clear(fe_pool * pool);
void * __thiscall arena_alloc_copy_bytes(fe_arena * a, void * src, uint src_size, uint new_size);
void __thiscall nheap_object_base_ctor(c1_pch_segment * obj, int kind, c1_pch_image * owner);
c1_pch_segment * __cdecl nheap_record_new_4c(c1_pch_segment * tmpl, c1_pch_image * image);
c1_pch_segment * __thiscall nheap_record_init_4c(c1_pch_segment * obj, c1_pch_segment * tmpl, c1_pch_image * image);
void __stdcall mem_alloc_or_fatal_6(void);
void __cdecl arenas_init_fatal_fragment(fe_arena * arena, void * descriptor);
void __stdcall arenas_free_flagged(void);

void __thiscall block_scope_link(c1_scope_object * block_scope, int symbol);
c1_scope_lookup * __thiscall block_scope_lookup(c1_scope_object * block_scope, int name);
c1_tag_lookup * __thiscall block_scope_lookup_tag(c1_scope_object * block_scope, int name);
int __stdcall _DllMainCRTStartup(void * hinst, int reason, void * reserved);
int __stdcall _DllMainCRTStartup_chunk(void * hinst, void * reserved, int reason, int * frame);
int __stdcall _CRT_INIT(void * hinst, int reason, void * reserved);
void __cdecl msvcrt_handle_destroy(void);
void __cdecl static_dtor_il_gi_fdef_buffer(void);
void __cdecl static_dtor_il_db_buffer(void);
void __cdecl static_dtor_il_gi_buffer(void);
void __cdecl static_dtor_il_pending_init_buffer(void);
void __cdecl static_dtor_il_in_buffer(void);
void __cdecl static_dtor_il_ex_buffer(void);
void __cdecl static_dtor_il_gl_buffer(void);
void __cdecl static_dtor_il_sy_buffer(void);
void __fastcall idb_region_ctor(fe_idb_region * region);
void __thiscall block_scope_lookup_anonymous_member(c1_scope_object * block_scope, void * name, int * out);
uint __fastcall bitvec_iter_scan_to_set_bit(int iter);
void __fastcall bitvec_iter_from_bit(int bit, int iter);
longlong __stdcall _allrem(uint32_t lo, int32_t hi, uint32_t dlo, int32_t dhi);

int __stdcall parse_translation_unit(void);
c1_yyparse_state * __fastcall yyparse_state_new(c1_yyparse_state * state);
void __fastcall yyparse_state_init(c1_yyparse_state * state);
int __fastcall yyparse_c(c1_yyparse_state * parser);
void __stdcall parse_end_nop(void);
void __stdcall asm_statement(void);
void __stdcall asm_instruction_reset(void);
c1_asm_operand * __cdecl asm_operand_reset(int operand);
int __cdecl yyparse_asm(void);
int __stdcall yyparse_asm_fragment(short state, short * ssp, c1_yystype * vsp);
c1_token * __stdcall asm_yylex(void);
int __cdecl asm_is_statement_end(c1_u8 token);
c1_token * __cdecl asm_classify_name(c1_token * token);
short __cdecl asm_lookup_instruction(void * name);
void __cdecl asm_instruction_begin(short op);
short __cdecl asm_lookup_operand_keyword(void * name);
c1_u8 * __cdecl asm_check_register_1(short reg);
c1_u8 * __cdecl asm_check_symbol(int name);
c1_symbol * __cdecl asm_lookup_name(int name, int labels_allowed);
int __cdecl asm_symbol_operand_size(c1_symbol * sym);
char __cdecl asm_size_class_of_bytes(int size);
c1_u8 * __cdecl asm_check_register_2(short reg);
void __cdecl asm_operand_add_displacement(int value);
void __cdecl asm_check_operand_count(void);
int __cdecl asm_operand_count_valid(void);
int __cdecl asm_operand_kinds_valid(void);
void __cdecl asm_finalize_instruction(void);
char __cdecl asm_instruction_size_class(void);
char __stdcall asm_instruction_size_class_fragment(c1_u8 size_class);
char __cdecl asm_operands_size_class(void);
char __stdcall asm_operands_size_class_fragment(short opcode, int operand_count);
void __cdecl asm_encode_operand_registers(void);
void __cdecl asm_build_instruction_record(void);
void __cdecl asm_build_instruction_record_operands(byte size_byte);
c1_u8 __cdecl asm_operand_mode(c1_asm_expr * expr);
void __cdecl asm_check_ptr_type(char size_code);
short * __cdecl asm_operand_node_new(int value);
short * __cdecl asm_check_constant_expression(short op, short * left, short * right);
short * __cdecl asm_check_segment_override(short seg_reg, short * operand);
int __stdcall yyparse_c_external_declaration_fragment(c1_yyparse_state * parser);
int __stdcall yyparse_c_actions_fragment(c1_token * token, c1_yyparse_state * parser, c1_yystype * rhs_top);
int __stdcall yyparse_c_actions_array_bound(c1_yyparse_state * parser);
int __stdcall yy_stack_overflow(void);
void __fastcall yy_errok(c1_yyparse_state * state);
void __cdecl parse_report_missing_token(c1_token * found, int missing);
c1_yystype * __cdecl yyparse_c_value_for_token(c1_yystype * value, int kind);
void __cdecl yyerror_c(char * message);
void __stdcall parse_skip_to_closing_brace(void);
c1_token * __cdecl parse_skip_to_token_in_set(c1_token * token, ...);
c1_token * __cdecl yy_lookahead_token(void);
void __cdecl asm_check_label_redefinition(int name);
int __stdcall yyparse_asm_fragment_2(void);
void __cdecl asm_report_syntax_error(char * message, int state);
c1_yystype * __cdecl asm_parser_value_for_token(c1_yystype * value, int kind);
void __cdecl asm_check_parser_stack(char * message);
void __stdcall asm_check_end_of_file(void);
void __cdecl asm_warn_ptr_operator(short size_keyword);
int __cdecl asm_symbol_length(c1_symbol * sym);
char __stdcall asm_size_class_of_bytes_fragment(void);
int __cdecl asm_check_member_operand(void * name);
int __cdecl asm_operand_description_id(void);
void __cdecl asm_warn_directive(short directive, uint value);
char __stdcall asm_warn_instruction_size(c1_u8 size_class);
void __cdecl asm_swap_words(int * a, int * b);
int __cdecl asm_supply_float_operands(void);
void __cdecl asm_report_operand_error(int n, int operand_count);
void __stdcall asm_encode_operand_registers_fragment(c1_u8 base, int operand_number, c1_asm_operand * operand);
void __stdcall asm_finalize_instruction_fragment(int swap_operands);
int __cdecl asm_value_fits_bits(char bits, int value);
int __cdecl asm_operand_type_allows_size(c1_asm_operand * operand, short type_bit);
int __cdecl asm_operand_size_matches(c1_asm_operand * operand, char size_class);
int __stdcall asm_operand_kinds_valid_fragment(void);
short * __cdecl asm_check_constant_operand(short op, short * left, short * right);
int __cdecl asm_check_scale(uint scale);
short * __cdecl asm_check_index_register(short op, short * left, short * right);
c1_u8 * __cdecl asm_check_constant_operand_2(short op, short * operand);
c1_u8 * __cdecl asm_check_operand_type(c1_u8 * operand);
short * __cdecl asm_check_register_3(short * operand);
c1_u8 * __cdecl asm_check_float_register(short reg, int st_index);

void __cdecl pp_macro_text_append_string(uchar * text);
fe_line_map_row * __thiscall pp_line_map_find_entry(fe_line_map * line_map, uint position);
void __cdecl pp_output_copy_comment(void);
int * __thiscall include_line_map_find(void * line_map, int line);
int __cdecl pp_skip_blanks_in_macro_text(void);
int __cdecl pp_macro_expand(fe_macro * macro);
char __cdecl pp_macro_is_being_expanded(fe_macro * macro);
void __cdecl pp_macro_check_nesting(fe_macro * macro);
void __cdecl pp_macro_begin_replacement(void);
int __cdecl pp_macro_expansion_end(void);
char __cdecl pp_macro_scan_identifier(uint first_char);
char __cdecl pp_macro_scan_identifier_return_false(void);
c1_u8 * __cdecl pp_scan_directive(void);
byte __cdecl pp_directive_lookup_name(char * name);
void __cdecl pp_warn_extra_tokens(char * directive);
int __cdecl pp_check_expected_endif(int group_kind);
c1_u8 __cdecl pp_skip_to_directive(void);
uint __stdcall pp_cond_stack_push(void);
byte * __cdecl pp_copy_quoted_text(byte * out, uint * limit, byte quote);
int __cdecl pragma_process_saved_tokens(c1_token * token);
int __cdecl pragma_dispatch(void);
int __cdecl pragma_dispatch_return_zero_tail(void);
char __cdecl pragma_expect_dash_token(void);
c1_token * __cdecl pragma_warn_expected_token(uchar want);
int __cdecl pp_include_pop_file(void);
void __cdecl pp_block_comment_dispatch(void);
void __cdecl pp_skip_block_comment(void);
char * __fastcall pp_position_file_name(int * position);
longlong __cdecl pp_if_evaluate_expression(void);
fe_pp_value * __cdecl pp_if_parse_conditional(void);
fe_pp_value * __cdecl pp_if_parse_logical_or(void);
fe_pp_value * __cdecl pp_if_parse_logical_and(void);
fe_pp_value * __cdecl pp_if_parse_bit_or(void);
fe_pp_value * __cdecl pp_if_parse_bit_xor(void);
fe_pp_value * __cdecl pp_if_parse_bit_and(void);
fe_pp_value * __cdecl pp_if_parse_equality(void);
fe_pp_value * __cdecl pp_if_parse_relational(void);
fe_pp_value * __cdecl pp_if_parse_shift(void);
fe_pp_value * __cdecl pp_if_parse_additive(void);
fe_pp_value * __cdecl pp_if_parse_multiplicative(void);
fe_pp_value * __cdecl pp_if_parse_primary(void);
int __cdecl pp_if_accept_token(byte token);
int __cdecl pp_if_parse_defined(int name);
fe_pp_value * __cdecl pp_if_fold_operator(byte op, fe_pp_value * left, fe_pp_value * right);
void __cdecl pp_macro_collect_argument_text(fe_macro * macro, int formal_count);
void __cdecl pp_macro_save_expansion(uint * start, int end);
void __cdecl pp_macro_next_text_segment(void);
short * __cdecl pp_macro_formal_argument_text(char * pasted);
int __cdecl pp_macro_formal_is_pasted(void);
void __cdecl pp_define_finish(c1_u8 * text, uint length, int formal_count);
void __cdecl pp_define_parse(char notify_idb);
void __stdcall pp_define_directive(void);
byte * __cdecl pp_define_body(void);
void __cdecl pp_define_parse_formals(void);
int __cdecl pp_define_find_formal(byte * name);
void __stdcall pp_undef_directive(void);
void __cdecl pp_include_push_file(int * file_record, int mode, int handle, byte pch_part);
int __cdecl pp_include_open_file_2(byte * name, char angle);
char * __thiscall pp_include_alias_lookup(c1_include_alias * * list, char * name, char * angle);
c1_u8 * __stdcall include_record_new(void * name, void * canonical_name);
c1_token * __cdecl pp_include_directive_token(int value);
char * __cdecl pp_include_parse_filename(char report, char * angle);
c1_u8 * __cdecl pp_include_directive_open(byte * name, char angle);
int __cdecl pp_include_search_path(byte * name, byte * dir, char parent_mode, char open, byte * out);
int __cdecl pp_include_check_path(char * name, int report, char * found);
int __cdecl pp_include_search_parents(byte * file, char quoted, byte * file2);
c1_u8 * __cdecl pp_pragma_directive(void);
int __cdecl pragma_lookup_name(char * name);
void __cdecl pragma_warning_check_number(uint n, byte state);
c1_token * __cdecl pragma_string_argument(void);
void __stdcall pragma_pack_parse(void);
int __cdecl pragma_check_pack_value(int n);
char * __cdecl pp_include_parse_angle_name(char report);
void __cdecl pragma_once(void);
bool __stdcall pp_include_top_is_pseudo_file(void);
void __cdecl pragma_pack_push(int value, int ident);
void __cdecl pragma_pack_pop(int value, int name);
void __stdcall include_alias_table_new(void);
void __stdcall pragma_pack_stack_init(void);
char * __cdecl pp_format_date_time_strings(uint time);
void __cdecl pp_define_from_switch(byte * s);
void __cdecl pp_define_from_switch_copy_value_loop(void * is_space, byte * cursor, byte * text);
void __cdecl pragma_warning_state_emit(c1_u8 kind);
byte * __cdecl pp_quote_file_name(byte * dst, byte * name);
c1_token * __cdecl pragma_check_on_off(void);
void __cdecl pragma_parse_list(void * each);
void __cdecl pragma_function_name(int name);
void __stdcall pp_run_preprocess_only(void);
void __cdecl pp_run_preprocess_only_fragment(void * writer);
void __cdecl pp_output_copy_literal(byte first, char wide);
void __stdcall pp_emit_line_directive(void);
short * __cdecl pp_macro_argument_text(void);
void __cdecl pp_macro_stringize(uint quote, byte * text);
void __cdecl pragma_intrinsic_name(int name);
void __cdecl pp_if_fold_operator_fragment(fe_pp_value * right, int is_unsigned, fe_pp_value * left);
void __stdcall pp_output_skip_comment(void);
int __cdecl pp_current_file_mtime(void);
char __cdecl include_close_outer_handle(void);
void __cdecl pp_line_output_reset(void);
void __cdecl pp_include_push_file_fragment(void);
void __cdecl include_close_all(void);
byte * __fastcall pp_quote_file_name_fragment(byte * dst, byte * name);
void __cdecl pp_define_finish_text_fragment(byte * trailing_space);
void __stdcall pp_undef_macro_with_pch_check(void);
void __cdecl pp_define_body_fragment(uint ch);
void __cdecl pp_define_check_formals_token(uint ch, byte cur_ch);
void __cdecl pp_define_install(void * name, int kind, fe_macro * binding, uint length, c1_u8 * text);
byte * __cdecl pp_define_scan_replacement(c1_u8 ch, byte * cursor, int stringize_pending, int charize_pending);
void __cdecl pp_define_check_size(uint cursor, int base, int * limit);
int __cdecl pp_macro_expand_fragment_2(int expanded);
int __cdecl pp_macro_expand_fragment(uchar * text_cursor, int expanded);
void __cdecl pp_macro_location(int n);
c1_token * __cdecl pragma_parse_argument(int kind);
c1_token * __cdecl pragma_parse_identifier(int kind);
void __stdcall pragma_warning_push(void);
void __stdcall pragma_warning_pop(void);
void __cdecl pragma_component_set_name_references(fe_name * name);
void __stdcall pragma_component(void);
void __cdecl pragma_component_minrebuild(void);
void __cdecl pragma_component_mintypeinfo(void);
void __cdecl pragma_skip_to_dash(c1_token * token);
int __cdecl pragma_warn_unknown(c1_token * token);
int __cdecl pragma_warning(void);
int __cdecl pragma_dispatch_fragment(void);
int __cdecl pragma_push_pop_macro(int code);
void __thiscall slist_push_front(void * * head, void * * node);
void __cdecl pragma_include_alias(void);
c1_u8 * __cdecl pp_output_pragma(void);
void __cdecl pragma_hdrstop(char * * name);
void __stdcall pp_skip_line_comments(void);
void __cdecl pragma_message_indent(int indent, char * file);
int __cdecl pp_include_open_file_2_fragment(byte * name, char angle, byte * file_name);
c1_u8 * __cdecl pp_directive(int if_value, int pch_mode_two, char include_angle, int if_value_high);
c1_u8 * __cdecl pp_scan_directive_fragment(void);
c1_u8 * __cdecl pp_line_directive(void);
void __cdecl pp_output_skip_comment_slow_char(uint c, byte * input, void * put_char_to, void * put_char);
void __cdecl pp_skip_line_tokens(char lead_class, c1_fputc_fn fputc_fn);
void __cdecl pp_skip_line_whitespace_fragment_newline(char lead_class, c1_fputc_fn fputc_fn);
void __stdcall pp_line_after_pch_options(void);
void __cdecl pragma_message_text(void * list, char * format, ...);
void __thiscall pragma_warning_record_set_link(uint * record, uint link, int is_mark);
void __cdecl pragma_alloc_text_name(fe_name * name);
void __cdecl pragma_section_record(int kind, int id, char * text);
void __cdecl pragma_section_attribute(char * file, int fd);
void __cdecl pp_warn_include_depth(void);

void __stdcall stmt_loop_end(void);
void __stdcall stmt_do_head(void);
void __stdcall stmt_block_begin(void);
void __fastcall hash_scope_new_block(c1_scope_stack * scopes);
void __cdecl stmt_block_end(void);
void __stdcall stmt_emit_pending_destructors(void);
void __stdcall func_definition_end(void);
void __cdecl func_emit_body_end_il(int has_return);
void __cdecl func_finish_il(c1_symbol * sym);
void __thiscall func_in_write_key(fe_il_buffer * buf, uint key);
void __stdcall func_reset_helper_key(void);
void __cdecl implicit_function_table_clear(void);
void __thiscall func_definition_begin(void * declarator, int * spec);
c1_symbol * __cdecl func_parameter_scope_begin(c1_symbol * func);
void __cdecl func_record_alloc(c1_symbol * sym);
void __cdecl func_body_begin(void);
void __cdecl func_body_begin_fragment(char formal_kind, c1_symbol * formal, c1_type * * proto_types, int formal_number, int formal_link, c1_type * fn_type);
void __stdcall func_emit_body_begin_il(void);
int __cdecl func_argument_bytes(int scope);
void __cdecl stmt_return(c1_node * value, int has_value);
int __cdecl init_is_char_array_string_init(c1_symbol * sym, c1_node * node);
void __cdecl init_begin_variable(c1_symbol * sym);
void __cdecl init_end_record(c1_symbol * sym);
void __cdecl init_check_aggregate_or_constant(c1_symbol * sym, c1_node * init);
c1_node * __cdecl init_emit_runtime_assignment(c1_node * object, c1_node * value);
int __cdecl init_unsized_array_count(void);
void __cdecl func_check_argument_bytes_and_prototype(c1_symbol * sym);
void __cdecl stmt_emit_expression(c1_node * node);
void __cdecl stmt_check_controlling_expression(c1_node * cond, c1_node * target, uint jump_if_true);
void __cdecl stmt_new_loop_label(c1_label_cell * * label_stack, int kind);
void __cdecl stmt_loop_begin(c1_node * node, int node2, c1_node * node3);
void __cdecl stmt_case_label(c1_node * value);
void __stdcall stmt_switch_end(void);
void __cdecl stmt_switch_head(c1_node * node);
void __cdecl stmt_define_label(int name);
void __cdecl init_emit_symbol_data(c1_symbol * key, c1_node * node, fe_il_buffer * buf);
void __cdecl init_emit_initializer(c1_symbol * sym, c1_node * init, fe_il_buffer * buf);
void __cdecl init_emit_initializer_fragment_2(char is_unsigned, fe_il_buffer * buf, c1_node * value, uint addr_offset, c1_symbol * addr_symbol, int addr_mode, char * format, float fvalue, longlong value64, uint value_lo, int value_hi, double dvalue, float_const xvalue, c1_symbol * init_sym, c1_node * init, char value_is_integral);
int __cdecl init_is_constant_initializer(c1_symbol * sym, c1_node * * value);
void __cdecl init_check_dllimport_address(c1_symbol * sym, c1_node * node);
int __cdecl func_wants_inline(c1_symbol * fn);
c1_node * __cdecl func_new_compiler_generated(c1_node * value, void * name, c1_u8 local, char named);
void __cdecl init_emit_relocations_to_buffer(c1_symbol * key, c1_node * node);
void __cdecl func_emit_definition_record(fe_function_record * rec);
void __cdecl init_begin(c1_symbol * sym);
void __cdecl init_push_brace_level(c1_symbol * sym);
void __thiscall init_new_brace_level(c1_symbol * level, c1_symbol * rec, int arena);
void __cdecl init_process_initializer(c1_node * element);
int __cdecl init_descend_to_scalar(c1_node * node);
int __cdecl init_check_undefined_type(c1_node * element);
int __cdecl init_advance_member(void);
int __cdecl init_advance_member_fragment(void);
void __cdecl init_finish(c1_symbol * sym);
void __cdecl init_finish_variable(c1_symbol * sym);
void __stdcall init_pop_brace_level(void);
int __stdcall init_count_remaining_elements(void);
int * __cdecl init_skip_padding_members(int sym, int * member);
void __cdecl init_nested_brace_begin(void);
int __cdecl init_split_address_constant(c1_node * node, void * * symbol, int * offset);
int __cdecl init_split_address_constant_fragment(c1_u8 op, c1_node * node, int * offset, void * * symbol);
int __cdecl init_split_address_constant_fragment_2(c1_node * node, void * * symbol);
void __cdecl init_emit_data(int sym);
void __cdecl init_emit_data_fragment(void);
int __stdcall init_partial_array_remainder(void);
void __cdecl init_set_array_dimension(c1_symbol * sym);
void __cdecl init_finish_array(int sym);
void __cdecl func_emit_function_symbol(void);
void __cdecl eh_try_begin(void);
void __cdecl eh_try_block_end(void);
void __stdcall eh_labels_leave_try_scope(void);
void __cdecl eh_labels_leave_try_scope_fragment(c1_symbol * label, c1_u8 mark);
void __cdecl eh_except_filter_begin(void);
void __cdecl eh_except_emit_filter(c1_node * node);
void __cdecl eh_except_filter_end(void);
void __cdecl eh_except_end(void);
int __cdecl init_string_array_room(c1_symbol * sym, uint str);
void __cdecl func_emit_register_parameter(c1_symbol * sym);
void __cdecl init_check_automatic_address(c1_symbol * sym, c1_node * init);
void __cdecl init_emit_runtime_element(c1_symbol * sym, c1_node * init);
c1_node * __cdecl init_element_lvalue(c1_type * type);
char __cdecl func_skip_unchanged_body(int body_bytes, ushort position_delta);
void __cdecl func_reset_state(void);
void __cdecl func_report_formal_bytes_differ(void * parameter_scope, c1_type * fn_type);
void __cdecl func_warn_formal_list_differs(c1_type * * proto_types, int formal_number, int formal_link, c1_type * fn_type);
void __cdecl func_body_begin_fragment_3(void);
void __cdecl func_body_begin_fragment_2(c1_type * type);
int __cdecl func_formal_types_compatible(c1_type * declared, c1_type * defined);
void __cdecl stmt_report_undefined_label(c1_symbol * label);
void __cdecl stmt_warn_unreferenced_label(c1_symbol * label);
int __cdecl init_is_constant_initializer_fragment(c1_type * value_type, c1_symbol * addr_symbol, int addr_offset, c1_type * type, c1_symbol * sym, c1_node * node);
void __stdcall init_emit_zero_fill(void);
void __cdecl stmt_emit_intrinsic_call(int value, c1_node * right);
void __cdecl func_static_guard_variable(c1_node * value);
void __cdecl init_check_string_initializer(char kind, c1_type * type, c1_node * element, c1_node * init);
void __cdecl init_check_aggregate_or_constant_fragment(c1_symbol * sym);
int __cdecl init_descend_to_scalar_fragment(void);
int * __cdecl init_next_member_shares_unit(int offset, int * cell, void * unused);
void __cdecl init_finish_variable_fragment(c1_symbol * sym);
void __fastcall func_warn_must_return_value(char naked, c1_symbol * sym);
void __cdecl stmt_check_switch_expression(c1_node * node);
void __cdecl stmt_check_duplicate_case(c1_case_record * prev, c1_case_record * next, int value_hi, c1_case_record * rec);
void __stdcall eh_check_leave(void);
void __cdecl eh_finally_begin(void);
void __cdecl eh_finally_end(void);
void __cdecl func_report_static_not_defined(void * name, fe_il_buffer * buf, char fdef_mode, c1_type * sym_type, c1_type * derived_type, int part, c1_type * elem_type, ushort base_code, int is_array, char * format, uint storage_bits, uint rec_word0, uint rec_word1, ushort rec_word2, int record_class, c1_symbol * record_sym);
void __cdecl func_check_inline_definitions(c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * sym_type, c1_type * derived_type, c1_type * elem_type, ushort base_code, int is_array, char * format, uint storage_bits, uint rec_word0, uint rec_word1, ushort rec_word2, int record_class, c1_symbol * record_sym);
void __cdecl func_emit_inline_candidate(uint key, c1_symbol * sym, fe_il_buffer * buf, char fdef_mode, c1_type * sym_type, c1_type * derived_type, c1_type * elem_type, ushort base_code, int is_array, char * format, uint storage_bits, uint rec_word0, uint rec_word1, int record_class, c1_symbol * record_sym);
void __stdcall stmt_report_jump_into_try(c1_symbol * sym);
void __cdecl func_emit_definition_record_fragment(fe_function_record * rec, c1_symbol * sym, int symref);
void __cdecl init_emit_initializer_fragment(c1_symbol * sym, fe_il_buffer * buf, c1_node * value, uint addr_offset, c1_symbol * addr_symbol, int addr_mode, char * format, float fvalue, longlong value64, uint value_lo, int value_hi, double dvalue, float_const xvalue, c1_symbol * init_sym, c1_node * init, char value_is_integral);
void __cdecl init_report_illegal(char null_allowed, ushort code, fe_il_buffer * buf, c1_node * value, uint size, uint addr_offset, c1_symbol * addr_symbol, int addr_mode, char * format, float fvalue, longlong value64, uint value_lo, int value_hi, double dvalue, float_const xvalue, c1_symbol * init_sym, c1_node * init, char value_is_integral);
int __cdecl init_split_address_constant_fragment_3(void);
void __cdecl p1inl_new_key_default(int str);
c1_node * __cdecl func_new_compiler_generated_fragment(void * segment, char named, c1_symbol * object, c1_node * result, c1_u8 saved_il_block_level, c1_u8 saved_block_depth);
void __cdecl zg_write_function_prototype(c1_symbol * sym, FILE * out);
void __cdecl init_write_reloc_record(int kind, int value, int length);
void __stdcall func_emit_global_helper_symbol(void);

int __cdecl type_argument_size(c1_type * type, char promote_float);
int __fastcall type_size(c1_type * type);
int __fastcall type_size_scalar(c1_type * type);
int __fastcall type_size_derived(c1_type * type);
c1_type * __fastcall type_skip_arrays(c1_type * t);
c1_type * __cdecl type_promoted_integral(c1_type * type);
c1_type * __cdecl type_intern(c1_type * proto);
c1_type * __thiscall type_rebuild_chain(c1_type * type, c1_type * stop);
void __fastcall type_check_based_allocation(c1_declaration * decl);
void __stdcall type_check_based_allocation_fragment(void);
c1_param_list * __cdecl type_intern_parameter_list(c1_param_list * list);
uint __cdecl type_param_list_hash(int * list);
void __thiscall type_check_array_of_functions(c1_type_declarator * declarator, c1_type * layer);
c1_type * __cdecl type_descriptor_copy_transient(c1_type * desc);
void __thiscall type_build_array(c1_type_declarator * declarator, c1_type * layer);
c1_type * __fastcall type_pointer_to_function(c1_type * function_type);
c1_type * __fastcall type_strip_cv_qualifiers(c1_type * type);
c1_token * __thiscall type_check_tag_kind(c1_tag_record * tag, c1_token * token);
c1_token * __thiscall type_check_tag_kind_2(c1_tag_record * tag, c1_token * token);
c1_u16 __cdecl type_merge_qualifiers(c1_u16 first, c1_u16 second);
c1_type * __thiscall type_with_added_qualifiers(c1_type * type, ushort bits);
c1_type * __thiscall type_replace_in_chain(c1_type * type, c1_type * layer, c1_type * replacement);
void __thiscall type_check_based_form(c1_type_declarator * declarator, uint * based);
c1_u8 __cdecl type_check_bitfield_width(c1_symbol * member, uint width_lo, int width_hi);
c1_type * __cdecl type_compare_function_prototypes(c1_type * new_type, c1_type * old_type, char outer, char recurse, int pass_through);
void __stdcall type_tables_init(void);
void __fastcall type_descriptor_clear(c1_type * type);
c1_type * __cdecl type_new_function_returning(ushort convention, c1_type * type);
c1_type * __cdecl type_basic(ushort code);
c1_type * __fastcall type_function_return(c1_type * type);
int __cdecl type_size_checked(c1_type * type);
c1_type * __fastcall type_skip_arrays_and_functions(c1_type * type);
int __cdecl type_check_compatible(c1_u8 op, c1_type * to, c1_type * from);
c1_type * __fastcall type_intern_pointer_to(c1_type * array_type);
c1_type * __cdecl type_member_pointer_to_3(c1_type * type, int plain);
c1_u8 __thiscall type_derivations_equal(c1_type * type, c1_type * type2);
c1_type * __thiscall type_add_flags(c1_type * type, ushort bits);
c1_type * __cdecl type_intern_from_parts(c1_type * type, c1_u16 code, c1_u16 flags, c1_u32 * extra);
c1_type * __thiscall type_pointer_with_qualifiers(c1_type * type, ushort flags);
int __cdecl type_modifier_bits_match(c1_u16 flags1, c1_u16 flags2);
int __cdecl type_is_pointer_to_void(c1_type * type);
int __cdecl type_parameter_list_bytes(c1_param_list * list);
int __cdecl format_snprintf(char * buf, char * fmt, int size, ...);
int __cdecl format_vsnprintf(char * buf, char * fmt, int size, va_list args);
void __thiscall format_args_init(fe_message * m, char * format, int * args);
int __cdecl format_buffer_acquire(void);
int __cdecl format_buffer_alloc(void);
int __cdecl text_buffers_grow(int count, int * table);
void __cdecl format_buffer_free(int handle);
int * __cdecl format_buffer_find(int handle);
void __cdecl format_buffer_leave(void);
bool __fastcall type_is_plain_char_unsigned(c1_type * type);
void __cdecl type_string_literal_array(c1_node * literal);
int __cdecl type_function_param_count(c1_param_list * params);
c1_type * __cdecl type_strip_modifier_bits(c1_type * type);
c1_symbol * __cdecl type_emission_stack_top(void);
int __cdecl type_based_on_pointer_variable(c1_type * type);
c1_node * __cdecl type_based_base(c1_type * type);
c1_node * __cdecl type_based_pointer_from_node(c1_type * type, c1_node * left);
int __cdecl type_modifier_depth_at_most(c1_type * declared, c1_type * defined);
int __cdecl type_set_find(short * set, int value, int * index);
void __cdecl type_check_size_known(c1_type * type);
int __fastcall type_alignment_scalar(c1_type * type, c1_u8 skip_layers);
bool __cdecl type_is_function(byte * type_code);
int __fastcall type_is_class_or_enum(c1_type * type);
c1_type * __fastcall type_innermost_base(c1_type * type);
int __cdecl type_check_compatible_fragment(int result);
int __cdecl type_check_pointer_compatible(c1_type * type, c1_type * type2);
c1_type * __cdecl type_member_pointer_checked(c1_type * type);
c1_type * __fastcall type_base(c1_type * type);
c1_type * __thiscall type_with_qualifier_bits(c1_type * type, ushort bits);
c1_u8 __cdecl type_derivations_equal_fragment(void);
void __cdecl type_check_function_return_fragment(ushort extra_bits, uint extra_based, ushort mods_bits, c1_type_declarator * declarator);
void __cdecl format_buffer_append_string(int buf, char * s);
void __cdecl format_buffer_prepend_char(int buf, char c);
void __cdecl format_buffer_append_char(int buf, char c);
void __cdecl format_buffer_prepend_string(int buf, char * s);
char * __cdecl type_keyword_text(ushort code);
int __cdecl format_declaration_text(c1_symbol * sym, c1_type * type);
int __cdecl format_calling_convention_text(int ctx, void * emit, c1_u16 modifier, int based, c1_type * type);
int __cdecl format_declarator_name_text(c1_symbol * sym, c1_type * type);
int __cdecl format_type_declarator_text(int buf, c1_type * type);
int __cdecl format_basic_type_name(int buf, c1_type * type, char declarator_follows);
int __cdecl format_declspec_attributes(int buf, uint storage, void * declspec, int unused);
void __cdecl format_storage_class_to_file(uint spec0, uint spec1, uint spec2, FILE * out);
int __cdecl format_storage_class(int buf, uint spec0, uint spec1, uint spec2);
int __cdecl format_parameter_list_text(int buf, int * list);
int __cdecl format_pointer_layer_text(int buf, c1_type * layer);
char * __cdecl format_buffer_text(int handle);
int __cdecl format_buffer_reserve(int buf, int at_end, uint n);

extern undefined1 g_empty_string;
extern undefined1 DAT_10652219;
extern undefined1 DAT_1065221a;
extern undefined DAT_1065221c;
extern undefined4 DAT_10652238;
extern undefined1 DAT_1065223c;
extern undefined g_type_rank_table;
extern undefined1 DAT_10652249;
extern undefined1 DAT_1065224a;
extern undefined1 DAT_1065224b;
extern undefined1 DAT_1065224f;
extern undefined DAT_10652274;
extern undefined DAT_10652276;
extern undefined DAT_10652278;
extern undefined DAT_1065227a;
extern undefined DAT_1065227c;
extern undefined DAT_1065227e;
extern il_code_row g_il_symbol_record_templates[25];
extern undefined DAT_10652348;
extern undefined DAT_1065234c;
extern undefined DAT_10652350;
extern undefined DAT_10652354;
extern undefined DAT_10652358;
extern undefined DAT_1065235e;
extern undefined DAT_10652362;
extern undefined DAT_10652368;
extern undefined DAT_10652370;
extern undefined DAT_1065237c;
extern undefined DAT_10652380;
extern undefined DAT_10652392;
extern undefined DAT_10652398;
extern undefined DAT_106523a0;
extern undefined DAT_106523a4;
extern undefined DAT_106523ac;
extern undefined DAT_106523b8;
extern undefined DAT_106523c8;
extern undefined DAT_106523d0;
extern undefined DAT_106523dc;
extern undefined DAT_106523e4;
extern undefined DAT_106523f4;
extern undefined DAT_10652404;
extern undefined DAT_10652408;
extern undefined g_token_class;
extern c1_u8 g_empty_source_text;
extern sehtable_entry g_pp_position_file_name_scopetable;
extern c1_pragma_optimize_letter g_pragma_optimize_letters[10];
extern char g_pp_if_elif_spelling;
extern byte g_directive_letter_index_base;
extern byte g_directive_letter_end;
extern pointer g_directive_names;
extern uint g_directive_codes[15];
extern undefined DAT_10652670;
extern undefined DAT_10652680;
extern undefined DAT_10652684;
extern undefined DAT_1065268a;
extern undefined DAT_1065268c;
extern undefined DAT_106526ac;
extern undefined DAT_106526b0;
extern undefined DAT_106526b4;
extern undefined DAT_106526bc;
extern il_code_row g_pragma_subop_codes[41];
extern undefined DAT_10652830;
extern undefined DAT_10652832;
extern undefined DAT_10652834;
extern undefined DAT_10652836;
extern undefined DAT_10652838;
extern undefined DAT_1065283a;
extern undefined DAT_1065283c;
extern undefined DAT_1065283e;
extern undefined DAT_10652840;
extern undefined DAT_10652842;
extern undefined DAT_10652844;
extern undefined1 DAT_10652846;
extern undefined1 DAT_10652847;
extern undefined DAT_10652848;
extern undefined DAT_1065284c;
extern undefined DAT_10652850;
extern uint g_tree_op_to_il_op[250];
extern uint g_op_flags_table[249];
extern c1_declspec_attribute g_declspec_attributes[9];
extern undefined DAT_10653140;
extern undefined DAT_10653144;
extern undefined DAT_10653146;
extern undefined DAT_1065314a;
extern il_code_row g_debug_record_formats[18];
extern undefined DAT_106531e0;
extern undefined DAT_106531e4;
extern undefined DAT_106531e8;
extern undefined DAT_106531ec;
extern undefined DAT_106531f0;
extern undefined DAT_106531f4;
extern undefined DAT_106531f8;
extern undefined DAT_106531fc;
extern undefined DAT_10653200;
extern undefined1 DAT_10653208;
extern undefined1 DAT_10653209;
extern undefined1 DAT_1065320a;
extern undefined1 DAT_1065320b;
extern undefined1 DAT_1065320c;
extern undefined1 DAT_1065320d;
extern undefined1 DAT_1065320e;
extern undefined1 DAT_1065320f;
extern undefined1 DAT_10653210;
extern undefined1 DAT_10653211;
extern undefined1 DAT_10653212;
extern undefined1 DAT_10653213;
extern undefined1 DAT_10653214;
extern undefined1 DAT_10653215;
extern il_op_row g_il_op_shapes[186];
extern undefined DAT_106537e8;
extern undefined DAT_106537ec;
extern undefined DAT_106537ee;
extern undefined DAT_106537f0;
extern undefined DAT_106537f4;
extern undefined DAT_106537f8;
extern undefined DAT_106537fc;
extern undefined DAT_10653800;
extern undefined DAT_10653804;
extern undefined DAT_10653808;
extern undefined DAT_1065380c;
extern undefined DAT_10653810;
extern undefined DAT_10653814;
extern undefined DAT_10653818;
extern undefined DAT_1065381c;
extern undefined DAT_10653820;
extern undefined DAT_10653824;
extern undefined DAT_1065382a;
extern undefined DAT_1065382e;
extern undefined DAT_10653832;
extern undefined DAT_10653836;
extern undefined DAT_10653838;
extern undefined g_token_attributes;
extern sehtable_entry g_diag_format_message_scopetable;
extern undefined DAT_10653a2c;
extern sehtable_entry g_run_exit_handlers_scope_table;
extern undefined1 DAT_10653a4b;
extern pointer g_pragma_names;
extern byte g_pragma_name_first_by_char;
extern byte g_pragma_letter_end;
extern int g_pragma_codes[58];
extern undefined DAT_10653c58;
extern undefined DAT_10653c88;
extern undefined DAT_10653cd8;
extern undefined DAT_10653cdc;
extern undefined DAT_10653cf4;
extern undefined DAT_10653cf8;
extern undefined DAT_10653d10;
extern undefined DAT_10653d28;
extern undefined DAT_10653d38;
extern uint g_browse_record_zero[6];
extern byte g_browse_kind_by_symbol_kind[28];
extern byte g_browse_symbol_kind_excluded[28];
extern sehtable_entry g_reset_data_section_scope_table;
extern c1_static_initializer g_static_initializer_table[31];
extern c1_static_initializer g_static_initializer_table_end;
extern sehtable_entry g_main_guarded_scope_table;
extern undefined1 DAT_10653fc8;
extern undefined1 DAT_10653fc9;
extern undefined1 DAT_10653fcc;
extern undefined1 DAT_10653fcd;
extern undefined1 DAT_10653fd0;
extern undefined1 DAT_10653fd1;
extern undefined g_arena_descriptors;
extern undefined1 g_arena_pch_flags;
extern undefined1 DAT_10653ff8;
extern undefined DAT_10654064;
extern undefined DAT_10654070;
extern undefined DAT_10654078;
extern getflags_letter_row g_switch_table_Z_letters[13];
extern getflags_row g_switch_table[91];
extern undefined DAT_10654564;
extern undefined DAT_10654574;
extern undefined DAT_106545bc;
extern undefined DAT_106545c4;
extern undefined DAT_106545cc;
extern undefined DAT_106545d0;
extern undefined DAT_106545e0;
extern undefined DAT_106545f0;
extern undefined DAT_106545f8;
extern undefined DAT_106545fc;
extern undefined DAT_10654604;
extern undefined DAT_1065460c;
extern undefined DAT_10654610;
extern undefined DAT_10654614;
extern undefined DAT_1065461c;
extern undefined DAT_10654620;
extern undefined DAT_10654638;
extern undefined DAT_1065463c;
extern undefined DAT_10654640;
extern undefined DAT_10654644;
extern undefined DAT_10654648;
extern undefined DAT_1065464c;
extern undefined DAT_10654650;
extern undefined DAT_10654654;
extern undefined DAT_10654658;
extern undefined DAT_1065465c;
extern undefined DAT_10654664;
extern undefined DAT_10654674;
extern undefined DAT_10654678;
extern undefined DAT_1065467c;
extern undefined DAT_10654684;
extern undefined DAT_1065468c;
extern undefined DAT_10654694;
extern undefined DAT_1065469c;
extern undefined DAT_106546a4;
extern undefined DAT_106546a8;
extern undefined DAT_106546b0;
extern undefined DAT_106546b8;
extern undefined DAT_106546bc;
extern undefined DAT_106546c0;
extern undefined DAT_106546c4;
extern undefined DAT_106546c8;
extern undefined DAT_106546cc;
extern undefined DAT_106546d0;
extern undefined DAT_106546d4;
extern undefined DAT_106546d8;
extern undefined DAT_106546dc;
extern undefined DAT_106546f0;
extern undefined DAT_106546f8;
extern undefined DAT_106546fc;
extern undefined DAT_10654704;
extern undefined DAT_1065470c;
extern undefined DAT_10654714;
extern undefined DAT_10654718;
extern undefined DAT_1065471c;
extern undefined DAT_10654720;
extern undefined DAT_10654724;
extern undefined DAT_10654730;
extern undefined DAT_10654738;
extern undefined DAT_10654740;
extern undefined DAT_10654748;
extern undefined DAT_10654750;
extern undefined DAT_10654754;
extern undefined DAT_10654758;
extern undefined DAT_1065475c;
extern undefined DAT_10654764;
extern undefined DAT_10654768;
extern undefined DAT_10654770;
extern undefined DAT_10654774;
extern undefined DAT_10654778;
extern undefined DAT_1065477c;
extern undefined DAT_10654780;
extern undefined DAT_10654784;
extern undefined DAT_10654788;
extern undefined DAT_10654790;
extern undefined DAT_106547a0;
extern char g_options_signature_tag;
extern c1_warning_default g_warning_defaults[15];
extern int g_crc16_feedback_bits[8];
extern undefined1 DAT_10654840;
extern undefined1 DAT_10654841;
extern undefined DAT_10654848;
extern undefined DAT_10654858;
extern undefined DAT_1065485c;
extern undefined DAT_1065487c;
extern undefined DAT_10654880;
extern undefined DAT_10654884;
extern undefined DAT_10654888;
extern undefined1 DAT_106548bd;
extern undefined1 DAT_106548be;
extern undefined1 DAT_106548bf;
extern undefined1 DAT_106548c0;
extern undefined1 DAT_106549cc;
extern undefined DAT_106551c0;
extern undefined DAT_10655228;
extern undefined DAT_10655230;
extern undefined DAT_10655234;
extern undefined DAT_1065523c;
extern undefined DAT_10655250;
extern undefined DAT_10655258;
extern undefined DAT_10655268;
extern undefined DAT_10655288;
extern undefined DAT_10655290;
extern undefined DAT_106552a6;
extern pointer g_keyword_table;
extern pointer g_entry_point_name_slots;
extern undefined DAT_106553ae;
extern undefined DAT_106553f4;
extern undefined DAT_10655410;
extern undefined DAT_1065545e;
extern undefined * g_idb_stub_vtbl;
extern undefined1 DAT_1065554c;
extern undefined1 DAT_1065554d;
extern pointer g_intrinsic_names;
extern char g_intrinsic_first_by_char;
extern char g_intrinsic_end_by_char;
extern sbyte g_intrinsic_letter_ranges[29];
extern fe_intrinsic_row g_intrinsic_table[64];
extern undefined DAT_10655978;
extern undefined DAT_1065597c;
extern undefined DAT_10655980;
extern undefined DAT_10655984;
extern undefined DAT_106559ae;
extern undefined DAT_106559b4;
extern undefined DAT_106559b8;
extern undefined DAT_106559c0;
extern undefined DAT_106559de;
extern undefined DAT_106559e4;
extern undefined DAT_106559ea;
extern undefined DAT_106559f0;
extern undefined DAT_106559f4;
extern undefined DAT_106559f8;
extern undefined DAT_106559fc;
extern undefined DAT_10655a00;
extern undefined DAT_10655a04;
extern undefined DAT_10655a08;
extern undefined DAT_10655a0c;
extern undefined DAT_10655a10;
extern undefined DAT_10655a14;
extern undefined DAT_10655a18;
extern undefined1 DAT_10655a1c;
extern undefined1 DAT_10655a1d;
extern undefined DAT_10655b60;
extern undefined DAT_10655b64;
extern undefined DAT_10655b6c;
extern undefined DAT_10655b84;
extern undefined DAT_10655b9c;
extern undefined DAT_10655ba4;
extern undefined4 DAT_10655bbc;
extern short g_yy_exca[30];
extern byte g_yy_exidx[248];
extern short g_yy_action[1326];
extern short g_yy_pact[396];
extern short g_yy_pgo[96];
extern byte g_yy_r1[240];
extern byte g_yy_r2[240];
extern short g_yy_chk[396];
extern short g_yy_def[396];
extern undefined1 DAT_1065733c;
extern short g_asm_yy_exca[22];
extern byte g_asm_yy_exidx[12];
extern short g_asm_yy_action[260];
extern short g_asm_yy_pact[136];
extern short g_asm_yy_pgo[24];
extern byte g_asm_yy_r1[84];
extern byte g_asm_yy_r2[84];
extern short g_asm_yy_chk[136];
extern undefined2 g_asm_yy_def;
extern undefined g_asm_size_class_by_keyword;
extern pointer g_asm_mnemonics;
extern undefined g_asm_mnemonic_index_by_char;
extern undefined * g_asm_mnemonic_letter_end;
extern undefined g_asm_mnemonic_codes;
extern undefined DAT_106587d8;
extern undefined DAT_106587dc;
extern undefined DAT_106587e0;
extern undefined DAT_106587e8;
extern undefined DAT_106587f0;
extern undefined DAT_106587fc;
extern undefined DAT_10658804;
extern undefined DAT_10658808;
extern undefined DAT_1065880c;
extern undefined DAT_10658810;
extern undefined DAT_10658814;
extern undefined DAT_10658818;
extern undefined DAT_1065881c;
extern undefined DAT_10658820;
extern undefined DAT_10658828;
extern undefined DAT_10658830;
extern undefined DAT_10658838;
extern undefined DAT_1065883c;
extern undefined DAT_10658844;
extern undefined DAT_10658848;
extern undefined DAT_10658850;
extern undefined DAT_10658854;
extern undefined DAT_10658858;
extern undefined DAT_1065885c;
extern undefined DAT_10658864;
extern undefined DAT_10658868;
extern undefined DAT_10658870;
extern undefined DAT_10658880;
extern undefined DAT_10658890;
extern undefined DAT_10658898;
extern undefined DAT_106588a0;
extern undefined DAT_106588b0;
extern undefined DAT_106588c0;
extern undefined DAT_106588c8;
extern undefined DAT_106588d0;
extern undefined DAT_106588d8;
extern undefined DAT_106588e0;
extern undefined DAT_106588e4;
extern undefined DAT_106588f0;
extern undefined DAT_106588f8;
extern undefined DAT_106588fc;
extern undefined DAT_10658900;
extern undefined DAT_10658904;
extern undefined DAT_10658908;
extern undefined DAT_1065890c;
extern undefined DAT_10658914;
extern undefined DAT_1065891c;
extern undefined DAT_10658922;
extern undefined DAT_10658926;
extern undefined DAT_1065892a;
extern undefined DAT_10658930;
extern undefined DAT_10658938;
extern undefined DAT_10658940;
extern undefined DAT_10658946;
extern undefined DAT_1065894c;
extern undefined DAT_10658950;
extern undefined DAT_10658958;
extern undefined DAT_10658960;
extern undefined DAT_10658964;
extern undefined DAT_10658968;
extern undefined DAT_1065896c;
extern undefined DAT_10658970;
extern undefined DAT_1065899c;
extern undefined DAT_106589a4;
extern undefined DAT_106589ac;
extern undefined DAT_106589e4;
extern undefined DAT_106589ec;
extern undefined DAT_106589f4;
extern undefined DAT_10658a6c;
extern undefined DAT_10658a70;
extern undefined DAT_10658a78;
extern undefined DAT_10658a7c;
extern undefined DAT_10658a84;
extern undefined DAT_10658a88;
extern undefined DAT_10658a90;
extern undefined DAT_10658a98;
extern undefined DAT_10658aa0;
extern undefined DAT_10658aa4;
extern undefined DAT_10658aac;
extern undefined DAT_10658ab4;
extern undefined DAT_10658ab8;
extern undefined DAT_10658ac0;
extern undefined DAT_10658ac8;
extern undefined DAT_10658ad0;
extern undefined DAT_10658ad8;
extern undefined DAT_10658ae0;
extern undefined DAT_10658b18;
extern undefined DAT_10658b78;
extern undefined DAT_10658b88;
extern undefined DAT_10658b96;
extern undefined DAT_10658b9c;
extern undefined DAT_10658ba0;
extern undefined DAT_10658ba8;
extern undefined DAT_10658bb0;
extern undefined DAT_10658bb8;
extern undefined DAT_10658bbe;
extern undefined DAT_10658bc4;
extern undefined DAT_10658bd0;
extern undefined DAT_10658bd4;
extern undefined DAT_10658bd8;
extern undefined DAT_10658be0;
extern undefined DAT_10658be8;
extern undefined DAT_10658bf0;
extern undefined DAT_10658bf8;
extern undefined DAT_10658c00;
extern undefined DAT_10658c06;
extern undefined DAT_10658c0c;
extern undefined DAT_10658c10;
extern undefined DAT_10658c14;
extern undefined DAT_10658c18;
extern undefined DAT_10658c1e;
extern undefined DAT_10658c22;
extern undefined DAT_10658c28;
extern undefined DAT_10658c2c;
extern undefined DAT_10658c30;
extern undefined DAT_10658c34;
extern undefined DAT_10658c38;
extern undefined DAT_10658c3c;
extern undefined DAT_10658c40;
extern undefined DAT_10658c44;
extern undefined DAT_10658c4c;
extern undefined DAT_10658c54;
extern undefined DAT_10658c5c;
extern undefined DAT_10658c64;
extern undefined DAT_10658c68;
extern undefined DAT_10658c80;
extern undefined DAT_10658c86;
extern undefined DAT_10658c8a;
extern undefined DAT_10658c8e;
extern undefined DAT_10658c90;
extern undefined DAT_10658c94;
extern undefined DAT_10658c98;
extern undefined DAT_10658c9c;
extern undefined DAT_10658ca0;
extern undefined DAT_10658ca6;
extern undefined DAT_10658ca8;
extern undefined DAT_10658cac;
extern undefined DAT_10658cb0;
extern undefined DAT_10658cb4;
extern undefined DAT_10658cb8;
extern undefined DAT_10658cbc;
extern undefined DAT_10658cc0;
extern undefined DAT_10658cc4;
extern undefined DAT_10658cc8;
extern undefined DAT_10658ccc;
extern undefined DAT_10658cd0;
extern undefined DAT_10658cd4;
extern undefined DAT_10658cd8;
extern undefined DAT_10658cdc;
extern undefined DAT_10658cde;
extern undefined DAT_10658ce2;
extern undefined DAT_10658ce6;
extern undefined DAT_10658ce8;
extern undefined DAT_10658cea;
extern undefined DAT_10658cee;
extern undefined DAT_10658cf4;
extern undefined DAT_10658cf8;
extern undefined DAT_10658cfc;
extern undefined DAT_10658d00;
extern undefined DAT_10658d04;
extern undefined DAT_10658d08;
extern undefined DAT_10658d14;
extern undefined DAT_10658d18;
extern undefined DAT_10658d1e;
extern undefined DAT_10658d24;
extern undefined DAT_10658d2c;
extern undefined DAT_10658d30;
extern undefined DAT_10658d38;
extern undefined DAT_10658d3c;
extern undefined DAT_10658d44;
extern undefined DAT_10658d48;
extern undefined DAT_10658d90;
extern undefined DAT_10658d94;
extern undefined DAT_10658da4;
extern undefined DAT_10658dbc;
extern undefined DAT_10658dc4;
extern undefined DAT_10658dc8;
extern undefined DAT_10658dd0;
extern undefined DAT_10658de0;
extern undefined DAT_10658de4;
extern undefined DAT_10658dec;
extern undefined DAT_10658df4;
extern undefined DAT_10658e04;
extern undefined DAT_10658e14;
extern undefined DAT_10658e18;
extern undefined DAT_10658e28;
extern undefined DAT_10658e30;
extern undefined DAT_10658e34;
extern undefined DAT_10658e3c;
extern undefined DAT_10658e4c;
extern undefined DAT_10658e50;
extern undefined DAT_10658e80;
extern undefined DAT_10658e88;
extern undefined DAT_10658e8c;
extern undefined DAT_10658e90;
extern undefined DAT_10658ea8;
extern undefined DAT_10658eb8;
extern undefined DAT_10658ee4;
extern undefined DAT_10658ef4;
extern undefined DAT_10658f0c;
extern undefined DAT_10658f2c;
extern undefined DAT_10658f32;
extern undefined DAT_10658f38;
extern undefined DAT_10658f48;
extern undefined DAT_10658f4c;
extern undefined DAT_10658f54;
extern undefined DAT_10658f58;
extern undefined DAT_10658f60;
extern undefined DAT_10658f70;
extern undefined DAT_10658f74;
extern undefined DAT_10658f9c;
extern undefined DAT_10658fa4;
extern undefined DAT_10658fa8;
extern undefined DAT_10658fb4;
extern undefined DAT_10658fc4;
extern undefined DAT_10658fc8;
extern undefined DAT_10658fce;
extern undefined DAT_10658fd4;
extern undefined DAT_10658fd8;
extern undefined DAT_10658fdc;
extern undefined DAT_10658fe0;
extern undefined DAT_10658fe4;
extern undefined DAT_10658fe8;
extern undefined DAT_10658fec;
extern undefined DAT_10658ff0;
extern undefined DAT_10658ff4;
extern undefined DAT_10658ff8;
extern undefined DAT_10658ffc;
extern undefined DAT_10659000;
extern undefined DAT_10659004;
extern undefined DAT_10659014;
extern undefined DAT_10659024;
extern undefined DAT_1065902c;
extern undefined DAT_10659034;
extern undefined DAT_10659044;
extern undefined DAT_106590c4;
extern undefined DAT_106590cc;
extern undefined DAT_106590e4;
extern undefined DAT_106590ec;
extern undefined DAT_106590f2;
extern undefined DAT_106590f8;
extern undefined DAT_106590fc;
extern undefined DAT_10659104;
extern undefined DAT_1065910c;
extern undefined DAT_10659114;
extern undefined DAT_10659130;
extern undefined DAT_10659136;
extern undefined DAT_1065913c;
extern undefined DAT_10659140;
extern undefined DAT_10659148;
extern undefined DAT_1065914e;
extern undefined DAT_10659152;
extern undefined DAT_10659158;
extern undefined DAT_1065915e;
extern undefined DAT_10659162;
extern undefined DAT_10659166;
extern undefined DAT_1065916a;
extern undefined DAT_1065916e;
extern undefined DAT_10659172;
extern undefined DAT_10659176;
extern undefined DAT_1065917a;
extern undefined DAT_10659180;
extern undefined DAT_10659188;
extern undefined DAT_106591b0;
extern undefined DAT_10659200;
extern undefined DAT_10659250;
extern undefined DAT_10659258;
extern undefined DAT_1065925e;
extern undefined DAT_10659262;
extern undefined DAT_10659266;
extern undefined DAT_1065926a;
extern undefined DAT_1065926e;
extern undefined DAT_10659270;
extern undefined DAT_10659274;
extern undefined DAT_10659276;
extern undefined DAT_10659278;
extern c1_asm_opcode g_asm_opcodes[269];
extern pointer g_asm_keywords;
extern undefined g_asm_keyword_index_by_char;
extern undefined * g_asm_keyword_letter_end;
extern undefined g_asm_keyword_codes;
extern undefined DAT_10659dc4;
extern undefined DAT_10659dc8;
extern undefined DAT_10659dce;
extern undefined DAT_10659dd2;
extern undefined DAT_10659dd8;
extern undefined DAT_10659ddc;
extern undefined DAT_10659de4;
extern undefined DAT_10659df0;
extern undefined DAT_10659df4;
extern undefined DAT_10659df8;
extern undefined DAT_10659dfc;
extern undefined DAT_10659e00;
extern undefined DAT_10659e04;
extern undefined DAT_10659e08;
extern undefined DAT_10659e0c;
extern undefined DAT_10659e10;
extern undefined DAT_10659e14;
extern undefined DAT_10659e20;
extern undefined DAT_10659e24;
extern undefined DAT_10659e28;
extern undefined DAT_10659e30;
extern undefined DAT_10659e34;
extern undefined DAT_10659e38;
extern undefined DAT_10659e3c;
extern undefined DAT_10659e40;
extern undefined DAT_10659e44;
extern undefined DAT_10659e48;
extern undefined DAT_10659e4c;
extern undefined DAT_10659e50;
extern undefined DAT_10659e56;
extern undefined DAT_10659e5a;
extern undefined DAT_10659e5e;
extern undefined DAT_10659e64;
extern undefined DAT_10659e68;
extern undefined DAT_10659e6a;
extern undefined1 g_asm_register_classes;
extern undefined1 g_asm_register_size_class;
extern undefined1 DAT_10659e84;
extern undefined1 DAT_10659e88;
extern ushort g_asm_form_words[70];
extern byte g_asm_kind_class[12];
extern byte g_asm_kind_index[32];
extern undefined DAT_10659ff0;
extern undefined DAT_10659ff4;
extern undefined DAT_10659ff8;
extern undefined DAT_10659ffa;
extern undefined DAT_10659ffe;
extern undefined DAT_1065a002;
extern undefined DAT_1065a008;
extern undefined DAT_1065a024;
extern undefined DAT_1065a02c;
extern undefined DAT_1065a032;
extern undefined DAT_1065a036;
extern undefined1 DAT_1065a03a;
extern undefined1 DAT_1065a03b;
extern undefined DAT_1065a072;
extern undefined DAT_1065a160;
extern undefined DAT_1065a168;
extern undefined DAT_1065a210;
extern c1_yy_token_insertion g_yy_token_insertions[49];
extern undefined DAT_1065a364;
extern undefined g_pdb_error_messages;
extern undefined DAT_1065a3f8;
extern undefined1 DAT_1065a400;
extern undefined1 DAT_1065a401;
extern undefined DAT_1065a404;
extern char * g_token_spelling[249];
extern undefined DAT_1065ab68;
extern undefined DAT_1065ab74;
extern undefined DAT_1065ab78;
extern undefined DAT_1065ac10;
extern undefined DAT_1065ac12;
extern undefined DAT_1065ac32;
extern undefined DAT_1065acd2;
extern undefined DAT_1065ace8;
extern undefined DAT_1065acec;
extern undefined DAT_1065acee;
extern undefined DAT_1065acf0;
extern undefined DAT_1065acf4;
extern undefined DAT_1065acf8;
extern undefined DAT_1065acfa;
extern undefined DAT_1065acfe;
extern undefined DAT_1065ad02;
extern undefined DAT_1065ad04;
extern undefined DAT_1065ad06;
extern undefined DAT_1065ad0a;
extern undefined DAT_1065ad0e;
extern undefined DAT_1065ad10;
extern undefined DAT_1065ad14;
extern undefined DAT_1065ad18;
extern undefined DAT_1065ad1e;
extern undefined DAT_1065ad24;
extern undefined DAT_1065ad28;
extern undefined DAT_1065ad2c;
extern undefined DAT_1065ad30;
extern undefined DAT_1065ad32;
extern undefined DAT_1065ad36;
extern undefined DAT_1065ad3a;
extern undefined DAT_1065ad3c;
extern undefined DAT_1065ad40;
extern undefined DAT_1065ad44;
extern undefined DAT_1065ad46;
extern undefined DAT_1065ad4a;
extern undefined DAT_1065ad56;
extern undefined DAT_1065ad58;
extern undefined DAT_1065ad5c;
extern undefined DAT_1065ad60;
extern undefined DAT_1065adb8;
extern undefined * g_calling_convention_names;
extern undefined DAT_1065af20;
extern undefined DAT_1065af70;
extern undefined DAT_1065afd8;
extern undefined1 g_pch_stamp;
extern undefined1 DAT_1065b0ad;
extern undefined1 DAT_1065b0ae;
extern undefined1 DAT_1065b0af;
extern undefined DAT_1065b0b4;
extern undefined DAT_1065b0b8;
extern undefined DAT_1065b0bc;
extern undefined DAT_1065b0c4;
extern undefined4 DAT_1065b0e4;
extern c1_pch_relocator g_pch_relocation_table[16];
extern undefined DAT_1065b180;
extern byte g_lowest_set_bit_table[256];
extern uint g_pch_relocation_arena_desc[4];
extern undefined DAT_1065b540;
extern c1_yy_token_insertion g_asm_yy_token_insertions[2];
extern c1_asm_code_row g_asm_mnemonic_aliases[178];
extern undefined DAT_1065b9a8;
extern undefined DAT_1065b9b0;
extern undefined DAT_1065b9b8;
extern undefined DAT_1065b9bc;
extern undefined DAT_1065b9c8;
extern undefined DAT_1065b9d4;
extern undefined DAT_1065b9dc;
extern undefined DAT_1065b9e0;
extern undefined DAT_1065b9e4;
extern undefined DAT_1065b9e8;
extern undefined DAT_1065b9ec;
extern undefined DAT_1065b9f0;
extern undefined DAT_1065b9f4;
extern undefined DAT_1065b9f8;
extern undefined DAT_1065b9fc;
extern undefined DAT_1065ba00;
extern undefined DAT_1065ba04;
extern undefined DAT_1065ba08;
extern undefined DAT_1065ba0c;
extern undefined DAT_1065ba1a;
extern ImageBaseOffset32 DAT_1065ba68;
extern ImageBaseOffset32 DAT_1065ba70;
extern undefined4 g_data_section_begin;
extern undefined1 DAT_1065d004;
extern byte g_pp_if_lookahead;
extern int g_pp_if_paren_depth;
extern c1_u8 g_yylex_end_seen;
extern c1_u8 g_lex_source_ended;
extern fe_input_file * g_input_file;
extern fe_input_file * g_primary_input_file;
extern fe_input_file * g_input_file_free_list;
extern int g_include_depth;
extern undefined4 g_source_handle;
extern int g_token_buffers_freed;
extern int g_comment_record_kind;
extern char * g_comment_record_text;
extern char * g_pch_name_buffer;
extern uint g_pp_cond_capacity;
extern uint g_cv_zero_attributes;
extern c1_symbol_stack_node * * g_type_emission_stack;
extern byte g_debug_begun;
extern int g_cv_real_type_by_size[11];
extern int g_cv_uint_type_by_size[17];
extern int g_cv_int_type_by_size[17];
extern int g_cv_unsigned_type_by_size[17];
extern int g_cv_signed_type_by_size[17];
extern uint * g_debug_index_queue;
extern char * * g_switch_words;
extern c1_yyparse_state * g_parser_state;
extern int g_browse_suspended;
extern int g_browse_last_line;
extern byte g_browse_line_absolute;
extern int g_emitter_region_mode;
extern long g_browse_sbr_header_end;
extern c1_il_emitter * g_il_emitter;
extern c1_il_emitter_browse * g_il_emitter_browse;
extern c1_il_emitter * g_il_emitter_plain;
extern int g_browse_block_depth;
extern byte g_eh_declarations_injected;
extern int g_ilstore_status;
extern c1_call_context * g_call_context;
extern void * g_pch_saved_globals;
extern c1_symbol * g_builtin_label_1;
extern c1_symbol * g_builtin_label_10;
extern fe_function_record_block * g_function_record_first_block;
extern fe_function_record_block * g_function_record_block;
extern int g_lex_unread_word;
extern c1_type * g_current_enum_type;
extern c1_param_list_entry * * g_param_list_hash;
extern fe_name * * g_name_hash;
extern void * * g_type_tables_spare_hash;
extern fe_pack_stack * g_pack_stack;
extern c1_include_alias * * g_include_alias_table;
extern fe_name * g_last_name;
extern void * g_name_alignment_member;
extern void * g_name_abstract_declarator;
extern fe_name * g_name_defined;
extern void * g_name_dollar;
extern void * g_name_drectve;
extern void * g_name_local_size;
extern void * g_name_ellipsis;
extern void * g_name_formal;
extern undefined DAT_1065d448;
extern void * g_name_main;
extern void * g_name_setjmp;
extern void * g_name_Catch;
extern void * g_name_WinMain;
extern void * g_name_DllMain;
extern void * g_name_wmain;
extern void * g_name_wWinMain;
extern fe_name * g_name_unnamed;
extern void * g_alloc_text_segment;
extern c1_type * g_type_const_char;
extern c1_type * g_type_const_int;
extern c1_type * g_type_const_unsigned_char;
extern c1_type * g_type_float;
extern c1_type * g_type_double;
extern c1_type * g_type_long_double;
extern c1_type * g_type_int;
extern c1_type * g_type_int8;
extern c1_type * g_type_uint8;
extern c1_type * g_type_int16;
extern c1_type * g_type_uint16;
extern c1_type * g_type_int32;
extern c1_type * g_type_uint32;
extern c1_type * g_type_int64;
extern c1_type * g_type_uint64;
extern c1_type * g_type_int128;
extern c1_type * g_type_code_803;
extern c1_type * g_type_long;
extern c1_type * g_type_unsigned_long;
extern c1_type * g_type_segment;
extern c1_type * g_type_short;
extern c1_type * g_type_unsigned_short;
extern c1_type * g_type_char;
extern c1_type * g_type_unsigned_char;
extern c1_type * g_type_unsigned_int;
extern c1_type * g_type_unsigned_int_2;
extern c1_type * g_type_none;
extern c1_type * g_type_void;
extern c1_type * g_type_function_returning_int;
extern c1_type * g_type_void_basic;
extern c1_scope_stack * g_current_scope;
extern uint * g_symbol_free_lists[32];
extern fe_pragma_comment * g_pragma_comment_list;
extern c1_u8 * g_empty_symbol_vector;
extern c1_param_list * g_param_list_void;
extern c1_param_list * g_param_list_empty;
extern void * g_bss_seg_name;
extern void * g_const_seg_name;
extern void * g_data_seg_name;
extern void * g_code_seg_name;
extern void * g_default_data_segment;
extern void * g_default_code_segment;
extern undefined4 g_token_static_records;
extern undefined4 g_token_newline;
extern c1_token * g_token_pragma_hdrstop;
extern c1_token * g_token_line_for_pch;
extern c1_token * g_token_pch_creation_point;
extern c1_token * g_token_end_of_file;
extern c1_token * g_token_directive_end;
extern c1_token * g_token_amp;
extern c1_token * g_token_and_and;
extern c1_token * g_token_amp_assign;
extern c1_token * g_token_assign;
extern c1_token * g_token_colon;
extern c1_token * g_token_comma;
extern c1_token * g_token_minus_minus;
extern c1_token * g_token_slash;
extern c1_token * g_token_slash_assign;
extern c1_token * g_token_equal_equal;
extern c1_token * g_token_not;
extern c1_token * g_token_greater;
extern c1_token * g_token_greater_equal;
extern c1_token * g_token_plus_plus;
extern c1_token * g_token_lbracket;
extern c1_token * g_token_shift_left_assign;
extern c1_token * g_token_shift_left;
extern c1_token * g_token_less;
extern c1_token * g_token_less_equal;
extern c1_token * g_token_minus;
extern c1_token * g_token_minus_assign;
extern c1_token * g_token_percent;
extern c1_token * g_token_percent_assign;
extern c1_token * g_token_star;
extern c1_token * g_token_star_assign;
extern c1_token * g_token_not_equal;
extern c1_token * g_token_bar;
extern c1_token * g_token_bar_assign;
extern c1_token * g_token_bar_bar;
extern c1_token * g_token_dot;
extern c1_token * g_token_plus;
extern c1_token * g_token_plus_assign;
extern c1_token * g_token_arrow;
extern c1_token * g_token_question;
extern c1_token * g_token_shift_right_assign;
extern c1_token * g_token_shift_right;
extern c1_token * g_token_tilde;
extern c1_token * g_token_caret;
extern c1_token * g_token_caret_assign;
extern c1_token * g_token_colon_greater;
extern c1_token * g_token_end_marker;
extern c1_token * g_token_lbrace;
extern c1_token * g_token_lparen;
extern c1_token * g_token_rbracket;
extern c1_token * g_token_rbrace;
extern c1_token * g_token_rparen;
extern c1_token * g_token_semicolon;
extern c1_token * g_token_internal;
extern undefined4 g_token_end_of_stream;
extern undefined DAT_1065d9ac;
extern uint * g_pdb_gi_pch_blob;
extern fe_name * g_name_LINE_Var;
extern c1_symbol * g_line_var_symbol;
extern fe_symtab * g_segment_record_table;
extern fe_warning_state * g_warning_state;
extern fe_warning_record * g_warning_record_free_list;
extern c1_pushed_macro * * g_pushed_macros;
extern c1_symbol * g_empty_list_sentinel;
extern undefined4 g_type_hash;
extern int g_function_record_index;
extern uint g_next_entity_id;
extern uint g_next_local_key;
extern undefined4 g_max_namemap_key;
extern undefined4 g_next_global_key;
extern uint g_name_S_counter;
extern int g_pch_sy_file_offset;
extern int g_cv_next_type_index;
extern uint g_cv_precomp_signature;
extern uint g_cv_type_stream_size;
extern uint g_warning_state_emit_min;
extern uint g_warning_state_emit_max;
extern undefined4 g_compile_flags_c4;
extern undefined4 g_compile_flags_c8;
extern c1_u32 g_compile_flags_cc;
extern uint g_pdb_age;
extern uint g_pdb_gi_age;
extern c1_u8 g_pch_needs_symbol;
extern byte g_browse_id_module_byte;
extern int g_lex_position;
extern fe_line_map g_line_map;
extern fe_line_map_row g_line_map_cached_row;
extern undefined4 g_pch_option_block;
extern c1_u8 g_ms_extensions;
extern c1_u8 g_opt_ZBe;
extern int g_integral_max_bytes;
extern c1_u8 g_opt_Gr;
extern c1_u8 g_opt_Jd;
extern c1_u8 g_opt_J_unsigned_char;
extern c1_u8 g_opt_vmb;
extern c1_u8 g_opt_vmg;
extern c1_u8 g_opt_vms;
extern c1_u8 g_opt_vmm;
extern c1_u8 g_opt_vmv;
extern c1_u8 g_opt_vd;
extern int g_opt_MD;
extern int g_opt_MT;
extern c1_u8 g_opt_Gc;
extern c1_u8 g_opt_Zi;
extern char g_pch_debug_in_object;
extern c1_u16 g_pch_saved_name_sizes[2];
extern c1_u8 g_opt_EP_no_line;
extern int g_autoinline_tuple_limit;
extern byte g_opt_Brepro;
extern undefined1 g_opt_Oi;
extern c1_u8 g_opt_stack_probes;
extern int g_opt_Gd;
extern int g_opt_Gz;
extern c1_u8 g_opt_Gf;
extern c1_u8 g_string_pooling;
extern char g_string_pooling_readonly;
extern c1_u8 g_string_pooling_readonly_active;
extern c1_u8 g_opt_cbstring;
extern undefined4 g_opt_G_cpu;
extern undefined1 g_opt_GM;
extern undefined4 g_inline_level;
extern char g_opt_browse_info;
extern byte g_browse_full;
extern uint g_pch_optimize_word;
extern c1_u8 g_declare_statics_thread;
extern c1_u8 g_opt_FD;
extern char g_minimal_rebuild;
extern byte g_pragma_check_stack;
extern undefined DAT_1065dbac;
extern undefined1 g_opt_Oa;
extern undefined1 g_opt_Ow;
extern undefined DAT_1065dbaf;
extern undefined g_opt_Op;
extern undefined DAT_1065dbb1;
extern char g_debug_types_in_pdb;
extern undefined g_pdb_file_name;
extern undefined DAT_1065dbb4;
extern undefined4 DAT_1065dbb7;
extern byte g_opt_Oq;
extern byte g_pragma_optimize_q;
extern c1_u8 g_opt_Ov;
extern uint g_pdb_signature;
extern uint g_pdb_gi_signature;
extern undefined1 g_c9il_mode;
extern char g_incremental;
extern char g_opt_GI;
extern undefined1 g_opt_GFR;
extern char g_split_pdbs;
extern c1_u8 g_opt_ZI;
extern undefined4 g_opt_Bm;
extern char g_use_pch;
extern char * g_use_pch_header_name;
extern char g_pch_create;
extern char * g_create_pch_header_name;
extern char g_pch_automatic;
extern undefined4 g_opt_YX_header;
extern char * g_opt_Yl_symbol;
extern char * g_pch_file_name;
extern char * g_il_pch_name;
extern c1_u8 g_pch_create_header_reached;
extern c1_u8 g_pch_written;
extern byte g_pch_creating;
extern c1_u8 g_pch_in_ex_file;
extern undefined1 g_opt_pch_types_in_pdb;
extern c1_u8 g_pch_precomp_types;
extern char g_function_in_pch;
extern c1_u8 g_function_body_reused;
extern c1_u8 g_function_uses_line_helper;
extern int g_function_cleared_word;
extern int g_trial_error_count;
extern int g_pp_cond_depth;
extern char g_opt_Ct;
extern char g_dlp;
extern char * g_opt_Fo_name;
extern char * g_object_file_name;
extern int g_class_depth;
extern ushort g_pragma_inline_depth;
extern ushort g_pragma_inline_recursion;
extern int g_pragma_auto_inline;
extern undefined4 g_function_auto_inline;
extern int g_function_has_body;
extern int g_function_not_inlinable;
extern uint g_enum_last_value;
extern int g_enum_last_value_high;
extern ushort g_block_scope_number;
extern char * g_string_literal_cur;
extern char * g_opt_pc;
extern char * g_opt_il_prefix;
extern int g_opt_Zp;
extern int g_seh_try_depth;
extern int g_seh_except_depth;
extern int g_seh_finally_depth;
extern int g_sizeof_depth;
extern int g_format_buffer_depth;
extern c1_u8 g_opt_noexpinl;
extern float_const g_float_zero;
extern float_const g_float_one;
extern void * * g_pdb_file_stack;
extern undefined4 g_compile_phase;
extern c1_symbol * g_function_labels;
extern char * g_unknown_option;
extern byte g_opt_Z7;
extern int g_opt_W_level;
extern c1_u8 g_pdb_directory_split;
extern int g_init_brace_depth;
extern c1_u8 g_init_pending_flag;
extern int g_init_pending_value;
extern int g_init_pending_value_high;
extern fe_symtab * g_file_scope_twins;
extern uint g_symbol_size_table[28];
extern uint g_symbol_size_class_table[28];
extern char g_il_emit_mode;
extern char * g_il_last_source_file_ni;
extern uint g_il_last_line_offset;
extern uint g_il_line_base;
extern uint g_il_last_file_key;
extern char g_il_line_numbers_in_range;
extern char * g_zg_unnamed_tag_keyword;
extern int g_format_parameter_names;
extern c1_u8 g_format_omit_tag_keyword;
extern int * g_text_buffers;
extern int g_text_buffer_count;
extern int g_format_buffer_next_handle;
extern int g_abort_requested;
extern _SYSTEM_INFO g_system_info;
extern void * g_abort_semaphore;
extern int g_first_compiler_pass;
extern fe_pch_header g_pch_header;
extern c1_byte_block_list * g_pch_record_list;
extern c1_byte_block_list * g_pch_directive_text_blocks;
extern short g_pch_include_count[2];
extern c1_u8 g_pch_file_time_changed;
extern c1_u8 g_pch_auto_never_recreate;
extern char * g_pch_auto_note;
extern int * g_pch_rle_counter;
extern int g_pch_rle_byte;
extern int g_pch_rle_run_length;
extern c1_u8 g_pch_file_unfinished;
extern c1_u8 g_pch_write_file_unfinished;
extern int g_pch_files_closed;
extern char * g_pch_symbol_prefix;
extern int g_expr_arena_index;
extern int g_context_arena_index;
extern fe_misc_string g_misc_strings[91];
extern char g_misc_strings_loaded;
extern FILE * g_browse_out_file;
extern uint g_pragma_optimize_mask;
extern uint g_pragma_optimize_off_mask;
extern char * g_option_flag_pointers[21];
extern undefined DAT_1065e510;
extern PDB * g_ilstore_pdb;
extern ILStore * g_ilstore;
extern ILMod * g_ilmod;
extern uint g_ilstore_module_ni;
extern c1_u8 g_pch_db_reloaded;
extern char g_il_files_opened;
extern int g_source_tracker_depth;
extern char g_source_signature_eof_byte;
extern c1_u8 * g_source_signature_buffer;
extern c1_u8 g_idb_outside_function;
extern c1_scope_symbol_list * g_scope_symbol_list_free;
extern undefined1 g_opt_BMOVE;
extern int g_zm_percent;
extern byte g_os_is_windows_nt;
extern undefined4 g_mre_engine;
extern uint g_global_helper_key;
extern c1_u8 * g_asm_lookahead;
extern int g_asm_yy_nerrs;
extern short g_asm_yy_errflag;
extern undefined DAT_1065e584;
extern undefined4 g_bss_section_begin;
extern undefined1 g_idb_file_name;
extern int g_pp_if_suppress_depth;
extern fe_pp_value g_pp_if_constant;
extern int g_macro_blanks_skipped;
extern int g_macro_invocation_line;
extern int g_macro_arg_count;
extern byte * g_macro_arg_start;
extern uchar * g_macro_expansion_text_start;
extern byte * g_macro_arg_cursor;
extern int g_macro_rescan_level;
extern uchar * g_macro_text_cursor;
extern uchar * g_define_text_ptr;
extern int g_define_formal_count;
extern fe_macro_frame g_macro_expansion_frames[256];
extern uchar * g_macro_text_buffer_limit;
extern uchar * g_macro_text_buffer;
extern undefined4 g_macro_arg_buffer_limit;
extern undefined4 g_macro_arg_buffer;
extern int g_token_arena_index;
extern int * g_token_arena_stack;
extern uint g_yylval;
extern undefined4 g_yylval_word1;
extern undefined g_yylval_word2;
extern undefined g_yylval_word3;
extern c1_specifier_symbol g_yylval_word4;
extern void * g_yylval_word5;
extern c1_emitter_suspend * g_emitter_suspend;
extern int g_token_position_table[14];
extern int g_token_position;
extern c1_token_source_frame * g_token_source;
extern int g_token_record_position;
extern c1_token_source_frame * g_token_save_frame;
extern uint * g_pp_cond_states;
extern undefined4 DAT_1065ff58;
extern undefined1 DAT_1065ff5c;
extern undefined1 DAT_1065ff5d;
extern ushort * g_cv_record_body;
extern ushort * g_debug_record_buffer;
extern char * g_switch_word;
extern undefined1 g_crc16_byte_table;
extern undefined1 g_crc16_table_lo;
extern undefined1 DAT_10667d65;
extern undefined1 g_crc16_table_hi;
extern undefined1 DAT_10667e65;
extern c1_yystype g_yyval;
extern int g_nested_declaration_depth;
extern ushort g_region_start_line;
extern int g_macro_text_pending;
extern char g_browse_pch_mark_written;
extern c1_symbol * g_browse_skip_symbol;
extern undefined1 DAT_10667f98;
extern undefined1 DAT_10667f99;
extern c1_struct_layout g_struct_layouts[16];
extern int g_fastcall_check_stack_warned;
extern int g_callee_call_depth;
extern c1_u8 g_pch_record_references;
extern byte g_pch_use_only;
extern void * g_deferred_symbols;
extern byte * g_function_record_pool;
extern int g_function_record_pool_left;
extern fe_pool g_scope_pool;
extern fe_pool g_pool_default;
extern fe_pool g_macro_definition_pool;
extern fe_pool g_name_pool;
extern fe_pool g_symtab_entry_pool;
extern c1_u8 * g_function_type_entry_pool;
extern c1_u8 * g_spare_pool;
extern undefined4 g_type_entry_pool;
extern uint g_type_entry_pool_left;
extern c1_idb_state * g_idb;
extern c1_source_tracker * g_source_tracker;
extern c1_u8 g_compile_function_body;
extern uint g_options_signature;
extern int g_source_file_ni;
extern uint g_function_start_line;
extern undefined4 g_function_tuple_count;
extern int g_paren_level_pending;
extern undefined g_decl_specifiers_by_level_base;
extern c1_decl_specifiers g_decl_specifiers_by_level[60];
extern int g_paren_depth;
extern c1_tag_symbol * g_current_enum_tag;
extern c1_byte_block_list * g_injected_text_list;
extern undefined4 g_target_cpu_mask;
extern c1_u8 g_il_pragma_byte_operand;
extern ushort g_asm_align_size;
extern char * g_pp_time_text;
extern char * g_pp_date_text;
extern undefined DAT_10668901;
extern undefined g_opt_Binl;
extern char * g_pragma_optimize_list;
extern undefined4 g_opt_FAT;
extern undefined1 g_string_literal_buffer;
extern undefined1 DAT_10668991;
extern undefined1 DAT_10668992;
extern undefined1 DAT_10668993;
extern undefined1 DAT_10668994;
extern undefined1 DAT_10668995;
extern undefined DAT_10669190;
extern undefined1 g_asm_no_lookahead;
extern uint g_saved_yylval[6];
extern byte * g_input_ptr;
extern c1_u8 g_il_block_level;
extern c1_u8 g_block_depth;
extern int g_warnings_as_errors;
extern c1_u8 g_opt_Zf;
extern undefined1 g_opt_FC;
extern c1_u8 g_symbol_scope_level;
extern int g_loop_label_count;
extern undefined DAT_10669248;
extern undefined4 g_opt_Fr_browse;
extern undefined4 g_opt_FR_browse;
extern char * g_browse_file;
extern FILE * g_browse_sbr_file;
extern undefined1 g_opt_BnoWorkList;
extern undefined1 g_opt_Bshow_incl;
extern int g_opt_E_preprocess;
extern c1_u8 g_opt_Zg;
extern int g_pragma_optimize_on;
extern int g_error_count;
extern int g_macro_expansion_depth;
extern int g_function_context_word;
extern int g_pending_function_word;
extern int g_opt_ZX;
extern int g_tag_found_in_current_scope;
extern int g_prototype_scope_depth;
extern int g_file_scope_decl_since_body;
extern int g_opt_xc;
extern undefined1 g_opt_nologo;
extern byte g_opt_C_keep_comments;
extern undefined4 g_opt_V_string;
extern char * g_opt_Fi_file;
extern undefined4 g_opt_source_file;
extern undefined4 g_constant_value;
extern int g_constant_value_high;
extern c1_node * g_case_run_label;
extern c1_symbol * g_static_guard_variable;
extern undefined4 g_forced_include_files;
extern int g_forced_include_index;
extern byte * g_forced_include_current;
extern fe_vector * g_forced_include_list;
extern fe_vector * g_define_list;
extern fe_vector * g_include_path_list;
extern c1_scope_symbol_list * g_function_parameter_scope;
extern c1_scope_symbol_list * g_pending_parameter_scope;
extern int g_function_formal_count;
extern int g_function_sy_offset;
extern int g_function_ex_offset;
extern int g_function_string_count;
extern c1_symbol * g_current_function;
extern c1_label_cell * g_loop_top_label_stack;
extern c1_list_cell * g_pending_destructor_list;
extern c1_label_cell * g_leave_label_stack;
extern c1_label_cell * g_default_label_stack;
extern c1_label_cell * g_continue_label_stack;
extern c1_case_list_cell * g_switch_case_stack;
extern c1_label_cell * g_break_label_stack;
extern fe_il_buffer g_il_gi_fdef;
extern fe_il_buffer g_il_gi_buffer;
extern fe_il_buffer g_il_pending_init;
extern fe_il_buffer g_il_in;
extern fe_il_buffer g_il_ex;
extern fe_il_buffer g_il_gl;
extern fe_il_buffer g_il_sy;
extern fe_il_buffer g_il_db;
extern undefined4 g_pp_output_stream;
extern FILE * g_preprocess_output_file;
extern char g_auto_pch_saved_use_pch;
extern char * g_auto_pch_saved_header;
extern byte g_auto_pch_using;
extern byte g_auto_pch_creating;
extern FILE * g_pch_file;
extern undefined g_pdb_relative_path;
extern undefined4 g_pdb_directory;
extern undefined g_pdb_dir_part;
extern undefined1 DAT_10669dc4;
extern undefined1 DAT_10669dc5;
extern char * * g_option_argv_cursor;
extern int g_option_args_left;
extern ushort g_file_name_case_table[256];
extern undefined g_opt_Zm;
extern undefined1 g_opt_debugBreak;
extern char * g_decorated_name_start;
extern undefined DAT_1066b8e0;
extern int g_init_runtime_bitfield_allowed;
extern int g_bitfield_word_needs_reset;
extern int g_init_offset;
extern int g_init_bitfield_unit;
extern uint g_init_bitfield_value;
extern uint g_init_bitfield_value_high;
extern int g_init_bitfield_unit_open;
extern int g_init_too_many_reported;
extern c1_init_level * g_init_level;
extern c1_symbol * g_init_symbol;
extern c1_init_level g_init_levels[32];
extern uint g_il_line_offset;
extern c1_specifier_words g_empty_specifier_words;
extern undefined g_undecorate_hook;
extern HMODULE g_msvcrt_module;
extern byte g_msvcrt_module_borrowed;
extern c1_list_node * g_format_template_arg_stack;
extern c1_list_node g_format_template_arg_anchor;
extern int g_format_template_arg_depth;
extern int g_atexit_count;
extern void * g_atexit_table[32];
extern int g_set_phase_count;
extern undefined4 g_pch_write_file;
extern fe_pch_header g_pch_header_read;
extern int g_pch_directive_mode;
extern int * g_pch_record_cursor;
extern int * g_pch_records_buffer;
extern void * g_file_copy_buffer;
extern c1_pch_options g_pch_option_block_read;
extern undefined g_io_result;
extern fe_diag_context g_diag_message_list;
extern undefined4 g_opt_ef;
extern undefined1 DAT_1066c8a8;
extern uint g_command_line_option_word;
extern c1_source_tracker * g_source_tracker_stack[1024];
extern fe_idb_class_record g_idb_empty_class_record;
extern c1_source_tracker_iface * g_source_tracker_iface;
extern void * g_pch_mapping_handle;
extern c1_pch_image g_pch_image;
extern fe_arena g_arenas[7];
extern undefined g_arena_top_decl;
extern undefined g_arena_top_decl_end;
extern undefined g_arena_temp;
extern undefined g_arena_case_labels;
extern undefined g_arena_case_labels_end;
extern undefined g_arena_pp_if;
extern undefined g_arena_pp_if_end;
extern undefined g_arena_diag;
extern undefined g_arena_diag_end;
extern c1_u8 g_pch_image_map_guard;
extern undefined2 g_asm_yy_states;
extern undefined2 DAT_1066dafe;
extern undefined g_asm_yy_values_start;
extern undefined g_asm_yy_states_last;
extern c1_yystype g_asm_yy_values[150];
extern c1_asm_instruction g_asm_instruction;
extern c1_asm_expr g_asm_exprs[3];
extern void * g_asm_member_struct;
extern c1_asm_operand * g_asm_operand;
extern c1_asm_operand g_asm_operands[3];
extern c1_asm_operand * g_asm_operand_order[3];
extern short g_asm_mnemonic_opcode;
extern short g_asm_opcode;
extern int g_asm_cleared_word;
extern int g_asm_form;
extern int g_asm_operand_index;
extern int g_asm_statement_start;
extern int g_asm_operands_begun;
extern int g_asm_size_without_ptr;
extern byte g_asm_ptr_form;
extern int g_asm_after_period;
extern int g_asm_in_brackets;
extern int g_asm_brace_depth;
extern undefined DAT_1066eaec;
extern c1_pdb_state * g_pdb_gi;
extern void * g_module_handle;
extern undefined4 __proc_attached;
extern undefined4 _pRawDllMain;
extern undefined __xc_a;
extern undefined __xc_z;
extern uint * __onexitend;
extern uint * __onexitbegin;
extern int _adjust_fdiv;
extern uint * g_data_section_copy;
extern undefined1 g_last_in_batch;
extern c1_pdb_state g_pdb;
extern c1_u8 g_batch_continuing;
extern c1_pdb_state g_pdb_split;
extern undefined g_fpu_double_limit;
extern ushort g_fpu_status_word;
extern uint32_t g_fpu_scratch;
extern undefined g_fpu_float_limit;
extern undefined g_fpu_long_double_limit;
extern undefined g_fpu_int32_limit;
extern ushort g_fpu_saved_control_word;
extern ushort g_fpu_chop_control_word;
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
extern undefined DAT_ffdfffff;

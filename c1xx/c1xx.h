typedef struct _iobuf _iobuf, *P_iobuf;

typedef struct _iobuf FILE;

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

typedef struct c1_arena c1_arena, *Pc1_arena;

typedef struct c1_arena arena;

typedef uchar c1_u8;

typedef uint c1_u32;

typedef struct c1_arena_desc c1_arena_desc, *Pc1_arena_desc;

struct c1_arena_desc {
    c1_u32 id;
    c1_u32 reserve_size;
    c1_u32 granule;
    c1_u8 flags;
    c1_u8 pad0d[3];
    c1_u32 pch_word;
};

struct c1_arena {
    c1_u8 *cur;
    c1_u8 *end;
    c1_u8 *base;
    c1_u32 committed;
    struct c1_arena_desc *desc;
    c1_u32 limit;
    c1_u32 unk18;
    c1_u8 mapped;
    c1_u8 pad1d[3];
};

typedef struct c1_arg_item c1_arg_item, *Pc1_arg_item;

typedef union c1_arg_value c1_arg_value, *Pc1_arg_value;

typedef struct c1_type c1_type, *Pc1_type;

typedef struct c1_node c1_node, *Pc1_node;

typedef ushort c1_u16;

typedef union c1_type_extra c1_type_extra, *Pc1_type_extra;

typedef struct c1_symbol c1_symbol, *Pc1_symbol;

typedef struct c1_function_params c1_function_params, *Pc1_function_params;

typedef struct fe_name fe_name, *Pfe_name;

typedef union c1_symbol_detail c1_symbol_detail, *Pc1_symbol_detail;

typedef union c1_symbol_x28 c1_symbol_x28, *Pc1_symbol_x28;

typedef union c1_symbol_tail c1_symbol_tail, *Pc1_symbol_tail;

typedef struct c1_type_list c1_type_list, *Pc1_type_list;

typedef struct fe_macro fe_macro, *Pfe_macro;

typedef struct c1_class_record c1_class_record, *Pc1_class_record;

typedef struct c1_symbol_halves c1_symbol_halves, *Pc1_symbol_halves;

typedef struct c1_sym_list c1_sym_list, *Pc1_sym_list;

typedef struct c1_symtab c1_symtab, *Pc1_symtab;

typedef struct c1_symbol_x28_bytes c1_symbol_x28_bytes, *Pc1_symbol_x28_bytes;

typedef struct c1_symbol_fn_tail c1_symbol_fn_tail, *Pc1_symbol_fn_tail;

typedef struct c1_symbol_data_tail c1_symbol_data_tail, *Pc1_symbol_data_tail;

typedef struct fe_macro_definition fe_macro_definition, *Pfe_macro_definition;

typedef struct c1_vtable_vector c1_vtable_vector, *Pc1_vtable_vector;

typedef struct c1_vbase_vector c1_vbase_vector, *Pc1_vbase_vector;

typedef struct c1_symbol_vector c1_symbol_vector, *Pc1_symbol_vector;

typedef struct c1_sym_link c1_sym_link, *Pc1_sym_link;

typedef struct c1_symtab_entry c1_symtab_entry, *Pc1_symtab_entry;

typedef struct c1xx_function_record c1xx_function_record, *Pc1xx_function_record;

typedef struct c1_vtable_record c1_vtable_record, *Pc1_vtable_record;

typedef struct c1_vbase_record c1_vbase_record, *Pc1_vbase_record;

typedef union c1_symbol_type_word c1_symbol_type_word, *Pc1_symbol_type_word;

typedef struct c1_vtable_slot c1_vtable_slot, *Pc1_vtable_slot;

typedef struct c1_vector c1_vector, *Pc1_vector;

typedef struct c1_using_alias c1_using_alias, *Pc1_using_alias;

typedef struct c1_namespace_info c1_namespace_info, *Pc1_namespace_info;

typedef struct c1_keyed_list c1_keyed_list, *Pc1_keyed_list;

typedef struct c1_lookup_entry c1_lookup_entry, *Pc1_lookup_entry;

typedef struct c1xx_hash_scope c1xx_hash_scope, *Pc1xx_hash_scope;

typedef struct c1_keyed_cell c1_keyed_cell, *Pc1_keyed_cell;

typedef struct c1xx_scope c1xx_scope, *Pc1xx_scope;

typedef struct c1xx_hash_scope_vtbl c1xx_hash_scope_vtbl, *Pc1xx_hash_scope_vtbl;

typedef struct c1_lookup_result c1_lookup_result, *Pc1_lookup_result;

typedef struct c1_using_directive c1_using_directive, *Pc1_using_directive;

typedef struct c1_using_cell c1_using_cell, *Pc1_using_cell;

typedef struct c1xx_scope_vtbl c1xx_scope_vtbl, *Pc1xx_scope_vtbl;

typedef union c1_scope_body c1_scope_body, *Pc1_scope_body;

typedef struct c1_namespace_symbol c1_namespace_symbol, *Pc1_namespace_symbol;

struct c1_vbase_record {
    struct c1_symbol *base;
    int offset;
    int vbptr_offset;
    int vbase_index;
    struct c1_symbol *member;
    struct c1_vtable_vector *vftables;
    struct c1_vtable_vector *vbtables;
    c1_u8 access;
    c1_u8 needs_vtordisp;
    c1_u16 pad1e;
};

union c1_scope_body {
    struct c1_sym_list *symbols;
    struct c1_sym_link **buckets;
    struct c1_symbol *cls;
};

struct c1_symbol_fn_tail {
    c1_u16 unk2c;
    c1_u8 special_kind;
    c1_u8 op_token;
    struct c1xx_function_record *record;
    c1_u32 flags;
};

struct c1_symbol_vector {
    c1_u16 count;
    c1_u16 capacity;
    struct c1_symbol *entries[1];
};

struct c1_symbol_halves {
    c1_u16 lo;
    c1_u16 hi;
};

struct c1xx_function_record {
    struct c1_sym_link *symbol_entry;
    int ex_offset;
    int sy_offset;
    int source_file;
    int tuple_count;
    c1_u32 unk14;
    int formal_count;
    c1_u32 start_line;
    c1_u32 flags;
};

struct c1_symtab {
    c1_u32 arena;
    c1_u32 compare;
    c1_u32 hash;
    c1_u16 nbuckets;
    c1_u8 flags;
    c1_u8 pad0f;
    struct c1_symtab_entry **buckets;
    c1_u32 count;
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

struct c1_symbol_data_tail {
    c1_u32 value_lo;
    c1_u32 value_hi;
    void *dependents;
};

union c1_symbol_detail {
    struct c1_class_record *cls;
    void *ptr;
    int value;
    struct c1_symbol_halves halves;
    struct fe_name *segment_class;
};

struct c1_sym_list {
    c1_u32 arena;
    struct c1_sym_link *head;
    struct c1_sym_link *tail;
};

struct c1_vtable_record {
    int kind;
    struct c1_symbol *table;
    struct c1_symbol *vptr_member;
    c1_u16 cv;
    c1_u16 pad0e;
    int nslots;
    int capacity;
    struct c1_vtable_slot *slots;
    int table_size;
    int off20;
    int off24;
    struct c1_symbol *via_base;
    struct c1_vtable_record *outer;
    struct c1_symbol *subobject_class;
    struct c1_vector *for_classes;
    c1_u8 emitted;
    c1_u8 pad39[3];
    struct c1_symbol *alt_table;
    c1_u8 alt_used;
    c1_u8 pad41[3];
};

struct c1_symbol_x28_bytes {
    c1_u8 bit_position;
    c1_u8 depth;
    c1_u16 unk2a;
};

union c1_symbol_x28 {
    struct c1_sym_list *members;
    struct c1_symtab *enumerators;
    struct c1_symbol_x28_bytes bytes;
    c1_u16 block_number;
};

union c1_symbol_tail {
    struct c1_symbol_fn_tail fn;
    struct c1_symbol_data_tail data;
    struct c1_node *tparam_value;
    struct c1_symbol *seg_helper;
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
    struct c1_symbol *next;
    c1_u32 position;
    struct c1_type *type;
    c1_u32 key_ref;
    c1_u32 entity;
    c1_u8 storage;
    c1_u8 flags21;
    c1_u8 flags22;
    c1_u8 flags23;
    union c1_symbol_detail detail;
    union c1_symbol_x28 x28;
    union c1_symbol_tail tail;
};

struct c1_lookup_result {
    struct c1_lookup_entry *head;
    struct c1_lookup_entry *tail;
};

struct c1xx_hash_scope_vtbl {
    int (*has_entries)(struct c1xx_hash_scope *);
    c1_u8 (*has_usings)(void *);
    void (*insert)(struct c1xx_hash_scope *, struct c1_symbol *);
    c1_lookup_result * (*lookup)(struct c1xx_hash_scope *, struct fe_name *, int);
    c1_u8 * (*lookup_tag)(void *, void *);
    c1_lookup_result * (*lookup_by_kind)(struct c1xx_hash_scope *, struct fe_name *, uint, byte *);
    void (*lookup_anonymous_member)(struct c1xx_hash_scope *, void *, struct c1_symbol **);
    int * (*find_link)(void *, int *);
    void (*pch_fixup)(struct c1xx_hash_scope *);
    void (*emit_il)(struct c1xx_hash_scope *);
    void (*link)(struct c1xx_hash_scope *, struct c1_symbol *);
};

struct c1_type_list {
    int count;
    c1_u32 unk04;
    struct c1_type *types[1];
};

union c1_type_extra {
    struct c1_symbol *cls;
    struct c1_function_params *params;
    c1_u32 count;
};

struct fe_macro {
    struct fe_name *name;
    struct fe_macro_definition *def;
};

struct c1xx_scope {
    struct c1xx_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    union c1_scope_body body;
};

struct c1_function_params {
    struct c1_type *this_type;
    c1_u8 default_count;
    c1_u8 flags;
    c1_u8 pad06[2];
    struct c1_node *defaults;
    struct c1_type_list *list;
};

union c1_symbol_type_word {
    struct c1_type *type;
    struct c1_using_alias *alias;
    struct c1_namespace_info *ns;
    struct c1_keyed_list *list;
    struct c1_sym_link *members;
    struct c1_lookup_entry **entries;
};

struct c1_using_cell {
    struct c1_namespace_symbol *ns;
    struct c1_using_cell *next;
    int active;
};

union c1_arg_value {
    struct c1_type *type;
    struct c1_node *expr;
};

struct c1_arg_item {
    void *vtbl;
    struct c1_arg_item *next;
    struct c1_arg_item *prev;
    c1_u8 kind;
    c1_u8 pad0d[3];
    union c1_arg_value value;
};

struct c1_vbase_vector {
    c1_u16 count;
    c1_u16 capacity;
    c1_u32 arena;
    struct c1_vbase_record **data;
};

struct c1_keyed_list {
    struct c1_keyed_cell *head;
    struct c1_keyed_cell *tail;
};

struct c1_class_record {
    c1_u32 size;
    c1_u32 members_end;
    struct c1_vtable_vector *vftables;
    struct c1_vtable_vector *vbtables;
    struct c1_vbase_vector *vbases;
    struct c1_symbol *vfptr_member;
    struct c1_symbol_vector *conversion_functions;
    short *repeated_conversion_types;
    c1_u32 member_count;
    void **sorted_members;
    c1_u32 gm_name_index;
    c1_u16 scope_index;
    c1_u16 pad2e;
    int vbptr_offset;
    c1_u32 debug_index;
    c1_u16 unk38;
    c1_u8 layout_flags3a;
    c1_u8 layout_flags3b;
    c1_u8 layout_flags3c;
    c1_u8 pm_model;
    c1_u8 flags3e;
    c1_u8 flags3f;
    c1_u8 flags40;
    c1_u8 implicit_state41;
    c1_u8 implicit_state42;
    c1_u8 implicit_state43;
    c1_u8 implicit_state44;
    c1_u8 implicit_state45;
    c1_u16 pad46;
};

struct fe_macro_definition {
    uint browse_id;
    char kind;
    uchar pad05[3];
    int position;
    uchar text[1];
};

struct c1_lookup_entry {
    struct c1_symbol *sym;
    struct c1xx_scope *scope;
    struct c1_lookup_entry *next;
};

struct c1_namespace_info {
    struct c1xx_hash_scope *scope;
    c1_u16 scope_index;
    c1_u8 flags;
    c1_u8 pad07;
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

struct c1_vtable_vector {
    c1_u16 count;
    c1_u16 capacity;
    c1_u32 arena;
    struct c1_vtable_record **data;
};

struct c1_using_alias {
    struct c1_symbol *target;
    struct c1_symbol *qualifier;
    c1_u16 class_index;
    c1_u8 hidden;
    c1_u8 pad0b;
};

struct c1_sym_link {
    struct fe_name *name;
    struct c1_sym_link *next;
    c1_u32 position;
    union c1_symbol_type_word type;
};

struct c1_vector {
    c1_u16 count;
    c1_u16 capacity;
    c1_u32 arena;
    void **data;
};

struct c1_using_directive {
    struct c1_symbol *name;
    struct c1_namespace_symbol *ns;
    struct c1xx_hash_scope *visible_in;
    int depth;
    struct c1_using_directive *next;
};

struct c1_vtable_slot {
    int *member;
    int path_offset;
    short vbase_index;
    short pad0a;
    c1_u32 flags;
};

struct c1_keyed_cell {
    struct c1_keyed_cell *key;
    struct c1_keyed_cell *next;
    struct c1_symbol *sym;
};

struct c1xx_hash_scope {
    struct c1xx_hash_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    struct c1_sym_link **buckets;
    c1_u32 mask;
    struct c1_using_cell **using_list;
    struct c1_symbol *ns;
};

struct c1_type {
    c1_u16 code;
    c1_u16 flags;
    struct c1_type *base;
    union c1_type_extra extra;
    c1_u32 debug_index;
};

struct c1_symtab_entry {
    void *key;
    void *value;
    struct c1_symtab_entry *next;
};

struct c1xx_scope_vtbl {
    char (*has_entries)(void);
    byte (*has_usings)(void);
    void *insert;
    c1_lookup_result * (*lookup)(struct c1xx_scope *, void *, int);
    c1_lookup_entry * (*lookup_tag)(struct c1xx_scope *, void *);
    c1_lookup_result * (*lookup_by_kind)(struct c1xx_scope *, void *, uint, c1_u8 *);
    void *lookup_anonymous_member;
    void *find_link;
    void (*pch_fixup)(struct c1xx_hash_scope *);
    void (*emit_il)(void *);
    void (*link)(struct c1xx_scope *, struct c1_symbol *);
};

struct c1_namespace_symbol {
    c1_u8 kind;
    c1_u8 flags1;
    c1_u8 flags2;
    c1_u8 flags3;
    c1_u8 flags4;
    c1_u8 flags5;
    c1_u16 scope_index;
    struct fe_name *name;
    struct c1_symbol *next;
    c1_u32 position;
    struct c1_namespace_info *info;
};

typedef struct c1_arg_iter c1_arg_iter, *Pc1_arg_iter;

struct c1_arg_iter {
    struct c1_node *args;
    struct c1_node *list;
    struct c1_node *current;
    struct c1_node *next;
};

typedef struct c1_arg_list c1_arg_list, *Pc1_arg_list;

struct c1_arg_list {
    struct c1_arg_item *first;
    struct c1_arg_item *last;
    c1_u8 flags;
    c1_u8 pad09[3];
};

typedef struct c1_arraydesc c1_arraydesc, *Pc1_arraydesc;

typedef struct c1_typedesc c1_typedesc, *Pc1_typedesc;

typedef struct c1_safearraybound c1_safearraybound, *Pc1_safearraybound;

typedef union c1_typedesc_ref c1_typedesc_ref, *Pc1_typedesc_ref;

struct c1_safearraybound {
    c1_u32 cElements;
    int lLbound;
};

union c1_typedesc_ref {
    struct c1_typedesc *lptdesc;
    struct c1_arraydesc *lpadesc;
    c1_u32 hreftype;
};

struct c1_typedesc {
    union c1_typedesc_ref u;
    c1_u16 vt;
    c1_u16 pad06;
};

struct c1_arraydesc {
    struct c1_typedesc tdescElem;
    c1_u16 cDims;
    c1_u16 pad0a;
    struct c1_safearraybound rgbounds[1];
};

typedef struct c1_asm_code_row c1_asm_code_row, *Pc1_asm_code_row;

struct c1_asm_code_row {
    c1_u16 code;
    c1_u8 cond_or_size;
    c1_u8 x03;
};

typedef struct c1_asm_instruction_row c1_asm_instruction_row, *Pc1_asm_instruction_row;

struct c1_asm_instruction_row {
    int form;
    c1_u32 cpu_mask;
};

typedef struct c1_asm_operand c1_asm_operand, *Pc1_asm_operand;

struct c1_asm_operand {
    struct c1_symbol *sym;
    int value;
    c1_u8 kind;
    c1_u8 seg_scale;
    c1_u8 base;
    c1_u8 index;
};

typedef struct c1_asm_operand_slot c1_asm_operand_slot, *Pc1_asm_operand_slot;

struct c1_asm_operand_slot {
    struct c1_asm_operand *record;
    c1_u8 size_class;
    c1_u8 size_given;
    c1_u8 x06[2];
    struct c1_symbol *ref_symbol;
    struct c1_symbol *frame_symbol;
};

typedef struct c1_asm_record c1_asm_record, *Pc1_asm_record;

struct c1_asm_record {
    c1_u8 length;
    c1_u16 opcode;
    c1_u8 operand_form;
    c1_u8 operands[124];
};

typedef struct c1_builtin_helper c1_builtin_helper, *Pc1_builtin_helper;

struct c1_builtin_helper {
    char *name;
    c1_u16 convention;
    c1_u16 pad06;
    c1_u32 unk08;
};

typedef struct c1_builtin_operand_iter c1_builtin_operand_iter, *Pc1_builtin_operand_iter;

typedef struct c1_conversion_type_iter c1_conversion_type_iter, *Pc1_conversion_type_iter;

typedef struct c1_symbol_vector_iter c1_symbol_vector_iter, *Pc1_symbol_vector_iter;

struct c1_symbol_vector_iter {
    struct c1_symbol_vector *vector;
    short index;
    c1_u16 pad06;
    struct c1_symbol *current;
};

struct c1_conversion_type_iter {
    void *types;
    struct c1_symbol_vector_iter functions;
    struct c1_type *type;
    c1_u8 seen;
    c1_u8 pad15[3];
};

struct c1_builtin_operand_iter {
    struct c1_node *operand;
    struct c1_type *pattern;
    c1_u8 need_lvalue;
    c1_u8 via_class;
    c1_u8 pad0a[2];
    struct c1_conversion_type_iter conversions;
    struct c1_type *type;
};

typedef struct c1_builtin_operator_row c1_builtin_operator_row, *Pc1_builtin_operator_row;

struct c1_builtin_operator_row {
    c1_u32 op;
    struct c1_type *left;
    struct c1_type *right;
    c1_u32 need_lvalue;
    struct fe_name *name;
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

typedef struct c1_byte_buffer c1_byte_buffer, *Pc1_byte_buffer;

typedef void (*c1_il_buffer_move_fn)(void *, c1_u8 *, c1_u8 *);

struct c1_byte_buffer {
    c1_u8 *start;
    c1_u8 *cur;
    c1_u32 size;
    c1_il_buffer_move_fn on_move;
    void *move_ctx;
};

typedef struct c1_call_record c1_call_record, *Pc1_call_record;

struct c1_call_record {
    struct c1_node *expr;
    struct c1_node *call;
    struct c1_node *callee;
    struct c1_node *this_arg;
    struct c1_symbol *function;
    struct c1_node *object;
    struct c1_node *args;
    struct c1_node *arg_slot;
    struct c1_node *arg_expr;
    c1_u8 flags;
    c1_u8 pad25[3];
};

typedef struct c1_catch_handler c1_catch_handler, *Pc1_catch_handler;

typedef struct c1_catchable_type c1_catchable_type, *Pc1_catchable_type;

typedef struct c1_member_iter c1_member_iter, *Pc1_member_iter;

typedef struct c1_list_cursor c1_list_cursor, *Pc1_list_cursor;

struct c1_list_cursor {
    c1_u8 valid;
    c1_u8 pad01[3];
    void *current;
};

struct c1_member_iter {
    struct c1_list_cursor cursor;
    void *current;
    void *next;
    void *cls;
    int filter;
};

struct c1_catchable_type {
    struct c1_catchable_type *derived;
    c1_u32 flags;
    struct c1_type *type;
    struct c1_type *type_unref;
    struct c1_symbol *copy_ctor;
    struct c1_symbol *dtor;
    struct c1_symbol *cls;
    struct c1_symbol *base;
    int this_offset;
    int *path;
    struct c1_catchable_type *same_type;
    struct c1_member_iter bases;
};

struct c1_catch_handler {
    struct c1_type *type;
    struct c1_type *match_type;
    struct c1_type *object_type;
    c1_u16 cv;
    c1_u16 pad0e;
    c1_u32 flags;
    struct c1_catchable_type *catchable;
    int position;
    struct c1_symbol *variable;
    struct c1_symbol *type_descriptor;
};

typedef struct c1_class_def_entry c1_class_def_entry, *Pc1_class_def_entry;

struct c1_class_def_entry {
    struct c1_symbol *cls;
    c1_u32 unk04;
    struct c1_type *type;
    c1_u32 unk0c;
    c1_u32 unk10;
    int offset;
    c1_u16 bitfield_type;
    c1_u16 alignment;
    c1_u8 bit_offset;
    c1_u8 flags;
    c1_u8 pad1e[2];
};

typedef struct c1_class_instance_cell c1_class_instance_cell, *Pc1_class_instance_cell;

struct c1_class_instance_cell {
    struct c1_symbol *instance;
    void *bodies;
    struct c1_class_instance_cell *next;
};

typedef struct c1_conversion c1_conversion, *Pc1_conversion;

typedef union c1_conversion_via c1_conversion_via, *Pc1_conversion_via;

union c1_conversion_via {
    struct c1_symbol *function;
    struct c1_vector *cv_levels;
};

struct c1_conversion {
    c1_u8 op;
    c1_u8 mode;
    c1_u8 flags;
    c1_u8 pad03;
    struct c1_node *expr;
    struct c1_type *source;
    struct c1_type *target;
    int source_class;
    int target_class;
    int rank;
    void *build;
    void *build_constant;
    void *note_fn;
    int note;
    int extension_note;
    struct c1_conversion *first;
    struct c1_conversion *second;
    union c1_conversion_via via;
    struct c1_symbol *overload_set;
    struct c1_node *function_ref;
    struct c1_symbol *target_symbol;
    int target_kind;
    c1_u16 cv_added;
    c1_u8 flags4e;
    c1_u8 flags4f;
};

typedef struct c1_conversion_rule c1_conversion_rule, *Pc1_conversion_rule;

struct c1_conversion_rule {
    void *handler;
    int note;
};

typedef struct c1_cv_lf_array c1_cv_lf_array, *Pc1_cv_lf_array;

struct c1_cv_lf_array {
    c1_u16 leaf;
    c1_u32 elemtype;
    c1_u32 idxtype;
    c1_u8 data[64244];
};

typedef struct c1_cv_lf_mfunction c1_cv_lf_mfunction, *Pc1_cv_lf_mfunction;

struct c1_cv_lf_mfunction {
    c1_u16 leaf;
    c1_u32 rvtype;
    c1_u32 classtype;
    c1_u32 thistype;
    c1_u8 calltype;
    c1_u8 reserved;
    c1_u16 parmcount;
    c1_u32 arglist;
    c1_u32 thisadjust;
};

typedef struct c1_cv_lf_pointer c1_cv_lf_pointer, *Pc1_cv_lf_pointer;

typedef union c1_cv_lf_pointer_tail c1_cv_lf_pointer_tail, *Pc1_cv_lf_pointer_tail;

union c1_cv_lf_pointer_tail {
    c1_u16 pmenum;
    c1_u8 name_length;
};

struct c1_cv_lf_pointer {
    c1_u16 leaf;
    c1_u32 utype;
    c1_u32 attr;
    c1_u32 pbase;
    union c1_cv_lf_pointer_tail tail;
};

typedef struct c1_cv_lf_procedure c1_cv_lf_procedure, *Pc1_cv_lf_procedure;

struct c1_cv_lf_procedure {
    c1_u16 leaf;
    c1_u32 rvtype;
    c1_u8 calltype;
    c1_u8 reserved;
    c1_u16 parmcount;
    c1_u32 arglist;
};

typedef struct c1_cv_lf_vtshape c1_cv_lf_vtshape, *Pc1_cv_lf_vtshape;

struct c1_cv_lf_vtshape {
    c1_u16 leaf;
    c1_u16 count;
    c1_u8 desc[64250];
};

typedef struct c1_decl_modifier c1_decl_modifier, *Pc1_decl_modifier;

struct c1_decl_modifier {
    c1_u32 bits;
    void *based;
};

typedef struct c1_decl_record c1_decl_record, *Pc1_decl_record;

typedef struct c1_param_clause c1_param_clause, *Pc1_param_clause;

typedef struct c1_overload_set c1_overload_set, *Pc1_overload_set;

struct c1_overload_set {
    c1_u8 kind;
    c1_u8 flags1;
    c1_u8 flags2;
    c1_u8 flags3;
    c1_u8 pad04[4];
    struct fe_name *name;
    void *next;
    c1_u32 unk10;
    struct c1_keyed_list *list;
};

struct c1_param_clause {
    struct c1_sym_list *params;
    c1_u32 cv;
    void *cv_based;
    struct c1_arg_list *defaults;
    c1_u32 kind;
    c1_u8 pop_scope;
    c1_u8 pad15[7];
};

struct c1_decl_record {
    struct c1_type *spec_type;
    struct c1_type *chain_head;
    struct c1_type *chain_tail;
    c1_u32 cc_bits;
    void *based;
    c1_u8 layer_flags;
    c1_u8 pad15[3];
    struct c1_param_clause *params;
    c1_u32 spec[6];
    struct c1_symbol *sym;
    struct c1_type *type;
    c1_u8 flags;
    c1_u8 pad3d[3];
    struct c1_node *bound_expr;
    struct c1_overload_set *qualifier;
    struct fe_name *name;
};

typedef struct c1_decl_spec_scan c1_decl_spec_scan, *Pc1_decl_spec_scan;

struct c1_decl_spec_scan {
    c1_u8 *token;
    struct c1_type *type;
    int ntokens;
    c1_u8 *result;
    c1_u32 unk10;
    c1_u8 spec[24];
    c1_u8 has_declspec;
    c1_u8 pad2d[3];
    struct c1_type *named_type;
    struct c1_symbol *type_sym;
    c1_u8 from_token;
    c1_u8 pad39[3];
    void *insert_fn;
    c1_u16 basic_type;
    c1_u16 cv;
    c1_u8 combined_int;
    c1_u8 pad45[3];
};

typedef struct c1_decl_state c1_decl_state, *Pc1_decl_state;

struct c1_decl_state {
    struct c1xx_scope *current;
    c1_u8 depth;
    c1_u8 pad05[3];
    struct c1xx_scope **contexts;
    struct c1_symbol *qual_class;
    c1_u8 access_op;
    c1_u8 reported;
    c1_u8 qualified;
    c1_u8 keep_aliases;
    c1_u8 kept;
    c1_u8 pad15[3];
    struct c1_decl_state *next;
};

typedef struct c1_declarator c1_declarator, *Pc1_declarator;

struct c1_declarator {
    struct fe_name *name;
    struct c1_decl_record *decl;
    struct c1_type *type;
    c1_u8 spec[24];
    c1_u32 position;
    struct c1_overload_set *qualifier;
    c1_u8 unk2c[4];
    c1_u8 op_token;
    c1_u8 unk31[3];
    struct c1_symbol *owner;
    struct c1_symbol *sym;
    c1_u32 unk3c;
    c1_u8 unk40;
    c1_u8 unk41;
    c1_u8 unk42;
    c1_u8 unk43;
    struct c1_symbol *specialized_template;
    struct c1_arg_list *template_args;
    c1_u32 kind;
    c1_u16 unk50;
    c1_u8 depth;
    c1_u8 special_kind;
    c1_u8 flags54;
    c1_u8 flags55;
    c1_u8 flags56;
    c1_u8 flags57;
};

typedef struct c1_declspec_attribute c1_declspec_attribute, *Pc1_declspec_attribute;

struct c1_declspec_attribute {
    char *name;
    int kind;
    c1_u8 storage_class;
    c1_u8 pad09[3];
    c1_u8 has_arguments;
    c1_u8 pad0d[3];
};

typedef struct c1_deferred_action c1_deferred_action, *Pc1_deferred_action;

typedef union c1_deferred_detail c1_deferred_detail, *Pc1_deferred_detail;

union c1_deferred_detail {
    struct c1_type *type;
    c1_u8 type_expected;
};

struct c1_deferred_action {
    void **vtbl;
    struct c1_symbol *sym;
    struct c1_deferred_action *next;
    void *arg;
    union c1_deferred_detail detail;
    c1_u32 unk14;
};

typedef struct c1_deferred_body c1_deferred_body, *Pc1_deferred_body;

struct c1_deferred_body {
    struct c1_symbol *fn;
    struct c1_deferred_body *next;
};

typedef struct c1_deferred_body_list c1_deferred_body_list, *Pc1_deferred_body_list;

struct c1_deferred_body_list {
    struct c1_deferred_body *first;
    struct c1_deferred_body *cursor;
    struct c1_deferred_body_list *outer;
};

typedef struct c1_deferred_parse c1_deferred_parse, *Pc1_deferred_parse;

typedef struct c1xx_token_stream c1xx_token_stream, *Pc1xx_token_stream;

typedef struct c1xx_token_stream_vtbl c1xx_token_stream_vtbl, *Pc1xx_token_stream_vtbl;

typedef struct c1xx_lex_source_stream c1xx_lex_source_stream, *Pc1xx_lex_source_stream;

typedef struct c1xx_token_cursor c1xx_token_cursor, *Pc1xx_token_cursor;

typedef struct c1xx_lex_source_stream_vtbl c1xx_lex_source_stream_vtbl, *Pc1xx_lex_source_stream_vtbl;

typedef struct c1xx_token c1xx_token, *Pc1xx_token;

typedef struct c1_token_chunk c1_token_chunk, *Pc1_token_chunk;

struct c1_deferred_parse {
    struct c1_symbol *fn;
    struct c1_function_params *params;
    struct c1_node *last_default;
    struct c1_node *default_arg;
    struct c1_type **param_type;
    struct c1_node *saved_tokens;
    struct c1_deferred_parse *prev;
    struct c1xx_token_stream *stream;
    c1_u8 keep_state;
    c1_u8 parse_pending;
    c1_u8 set_cc_10;
    c1_u8 pad23;
};

struct c1xx_token {
    c1_u8 code;
    c1_u8 unk01[7];
    void *value;
    c1_u32 value1;
    c1_u32 value2;
    c1_u32 value3;
    c1_u32 value4[2];
    struct c1_type *type_value;
    struct c1_symbol *type_symbol;
    c1_u32 value8[2];
};

struct c1_token_chunk {
    struct c1_token_chunk *next;
    struct c1xx_token *slots[31];
};

struct c1xx_token_stream_vtbl {
    int (*next)(struct c1xx_token_stream *);
    char * (*peek)(struct c1xx_token_stream *);
    void (*unget)(struct c1xx_token_stream *, char *);
    void (*append)(struct c1xx_token_stream *, int);
    int (*at_end)(void);
    void (*start)(struct c1xx_token_stream *);
    c1xx_lex_source_stream * (*scalar_deleting_dtor)(struct c1xx_lex_source_stream *, byte);
};

struct c1xx_token_cursor {
    struct c1_token_chunk *chunk;
    int index;
    int arena;
};

struct c1xx_token_stream {
    struct c1xx_token_stream_vtbl *vtbl;
    int start_position;
    int position;
    struct c1xx_token_cursor first;
    struct c1xx_token_cursor read;
    struct c1xx_token_cursor write;
    int arena;
    c1_u8 flags;
    c1_u8 pad35[3];
};

struct c1xx_lex_source_stream {
    struct c1xx_lex_source_stream_vtbl *vtbl;
    int start_position;
    int position;
    struct c1xx_token_cursor first;
    struct c1xx_token_cursor read;
    struct c1xx_token_cursor write;
    int arena;
    c1_u8 flags;
    c1_u8 pad35[3];
    int pushed_count;
    struct c1xx_token *pushed[5];
};

struct c1xx_lex_source_stream_vtbl {
    c1_u8 * (*lex_source_next_token)(struct c1xx_lex_source_stream *);
    c1_u8 * (*lex_source_peek_token)(struct c1xx_lex_source_stream *);
    void (*lex_source_unget_token)(struct c1xx_lex_source_stream *, c1_u8 *);
    void (*vtable_nop_arg1)(int);
    int (*vtable_true)(void);
    void (*vtable_nop)(void);
    c1xx_lex_source_stream * (*token_stream_scalar_deleting_dtor)(struct c1xx_lex_source_stream *, byte);
};

typedef struct c1_diag_context c1_diag_context, *Pc1_diag_context;

typedef struct c1xx_diag_list c1xx_diag_list, *Pc1xx_diag_list;

typedef struct c1xx_diag_cell c1xx_diag_cell, *Pc1xx_diag_cell;

typedef struct c1_diag_note_cell c1_diag_note_cell, *Pc1_diag_note_cell;

typedef struct c1_message c1_message, *Pc1_message;

typedef struct c1xx_diag_note_object c1xx_diag_note_object, *Pc1xx_diag_note_object;

typedef union c1_message_arg c1_message_arg, *Pc1_message_arg;

typedef struct c1_diag_note_vtbl c1_diag_note_vtbl, *Pc1_diag_note_vtbl;

union c1_message_arg {
    struct c1_symbol *sym;
    struct c1_type *type;
    char *text;
    c1_u32 value;
    char ch;
    c1_u32 half[2];
    struct fe_name *name;
};

struct c1_message {
    c1_u16 base;
    c1_u16 id;
    char *text;
    union c1_message_arg args[8];
};

struct c1xx_diag_list {
    struct c1xx_diag_cell *head;
    struct c1xx_diag_cell *tail;
};

struct c1_diag_context {
    struct c1xx_diag_list queue;
    struct c1xx_diag_list *insert_list;
    struct c1xx_diag_cell *insert_after;
    c1_u8 busy;
    c1_u8 pad11[3];
    struct c1xx_diag_list pending;
    struct c1_diag_note_cell *context_notes;
    int nesting;
    int state;
    int position;
    c1_u32 indent;
};

struct c1_diag_note_cell {
    struct c1xx_diag_note_object *object;
    struct c1_diag_note_cell *next;
};

struct c1_diag_note_vtbl {
    void *note;
};

struct c1xx_diag_cell {
    struct c1_message *msg;
    struct c1xx_diag_cell *next;
};

struct c1xx_diag_note_object {
    struct c1_diag_note_vtbl *vtbl;
};

typedef struct c1_diag_format_frame c1_diag_format_frame, *Pc1_diag_format_frame;

typedef struct c1_line_map_row c1_line_map_row, *Pc1_line_map_row;

typedef struct c1_seh_scope c1_seh_scope, *Pc1_seh_scope;

typedef struct fe_file_record fe_file_record, *Pfe_file_record;

struct fe_file_record {
    struct fe_name *name;
    uchar kind;
    uchar pad05[3];
    uint key_ref;
    uint entity;
    struct fe_name *canonical_name;
    struct fe_file_record *next;
};

struct c1_seh_scope {
    int enclosing;
    void *filter;
    void *handler;
};

struct c1_line_map_row {
    int position;
    int line;
    struct fe_file_record *file;
};

struct c1_diag_format_frame {
    c1_u8 pad000[8];
    struct c1_message *msg;
    c1_u8 pad00c[32];
    char *append_text;
    c1_u32 append_length;
    char append_retry_ok;
    c1_u8 pad035[3];
    char append_fits;
    c1_u8 pad039[3];
    c1_u32 p_line_position;
    struct c1_line_map_row *p_line_row;
    c1_u32 p_position;
    c1_u32 n_indent_left;
    char n_indent_fits;
    c1_u8 pad04d[3];
    c1_u32 n_indent;
    char n_newline_fits;
    c1_u8 pad055[3];
    struct c1_symbol *c_scope_symbol;
    struct c1_type *b_base_cursor;
    char c_char;
    c1_u8 pad061[3];
    char c_fits;
    c1_u8 pad065[3];
    c1_u32 literal_length;
    c1_u8 *literal_start;
    c1_u8 pad070[8];
    struct c1_type *t_type;
    c1_u32 s_position;
    struct c1_symbol *s_symbol;
    c1_u32 p_file_position;
    struct c1_message p_message;
    int m_string_id;
    c1_u8 l_token;
    c1_u8 pad0d5[3];
    struct fe_name *i_name;
    c1_u32 o_error;
    char *o_text;
    c1_u32 e_error;
    int errno_value;
    c1_u32 d_position;
    struct c1_symbol *d_symbol;
    c1_u32 c_position;
    int c_buffer;
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
    struct c1_seh_scope *seh_scope_table;
    int seh_try_level;
};

typedef struct c1_dlist_node c1_dlist_node, *Pc1_dlist_node;

struct c1_dlist_node {
    void *value;
    struct c1_dlist_node *next;
    struct c1_dlist_node *prev;
};

typedef struct c1_eh_state c1_eh_state, *Pc1_eh_state;

struct c1_eh_state {
    c1_u8 unwound;
    c1_u8 pad01[3];
    int kind;
    struct c1_symbol *cls;
    int source_number;
};

typedef struct c1_elemdesc c1_elemdesc, *Pc1_elemdesc;

struct c1_elemdesc {
    struct c1_typedesc tdesc;
    void *pparamdescex;
    c1_u16 wParamFlags;
    c1_u16 pad0e;
};

typedef int (*c1_fflush_fn)(void *);

typedef struct c1_flow_state c1_flow_state, *Pc1_flow_state;

struct c1_flow_state {
    int kind;
    c1_u8 flags;
    c1_u8 flags5;
    c1_u16 depth;
    struct c1_flow_state *next;
    struct c1_flow_state *prev;
    void *subject;
    int word14;
    int word18;
    int word1c;
    int word20;
    c1_u32 more[7];
};

typedef int (*c1_fputc_fn)(int, void *);

typedef struct c1_funcdesc c1_funcdesc, *Pc1_funcdesc;

struct c1_funcdesc {
    int memid;
    int *lprgscode;
    struct c1_elemdesc *lprgelemdescParam;
    int funckind;
    int invkind;
    int callconv;
    short cParams;
    short cParamsOpt;
    short oVft;
    short cScodes;
    struct c1_elemdesc elemdescFunc;
    c1_u16 wFuncFlags;
    c1_u16 pad32;
};

typedef struct c1_function_record_block c1_function_record_block, *Pc1_function_record_block;

struct c1_function_record_block {
    struct c1_function_record_block *next;
    struct c1xx_function_record records[20];
};

typedef struct c1_guid c1_guid, *Pc1_guid;

struct c1_guid {
    c1_u32 Data1;
    c1_u16 Data2;
    c1_u16 Data3;
    c1_u8 Data4[8];
};

typedef struct c1_idb_browse_entry c1_idb_browse_entry, *Pc1_idb_browse_entry;

struct c1_idb_browse_entry {
    c1_u16 old_first_line;
    c1_u16 old_last_line;
    c1_u16 first_line;
    c1_u16 last_line;
    int sbr_offset;
};

typedef struct c1_idb_browse_table c1_idb_browse_table, *Pc1_idb_browse_table;

struct c1_idb_browse_table {
    struct c1_idb_browse_entry *data;
    c1_u32 count;
    c1_u32 capacity;
};

typedef struct c1_idb_class_record c1_idb_class_record, *Pc1_idb_class_record;

struct c1_idb_class_record {
    c1_u32 class_ni;
    c1_u32 first_region;
    c1_u32 unk08;
    c1_u32 depth;
    c1_u32 change;
};

typedef struct c1_idb_include_stack c1_idb_include_stack, *Pc1_idb_include_stack;

typedef struct c1_idb_include_state c1_idb_include_state, *Pc1_idb_include_state;

typedef struct c1_idb_region_array c1_idb_region_array, *Pc1_idb_region_array;

typedef struct c1_idb_region c1_idb_region, *Pc1_idb_region;

typedef struct c1_mre_file c1_mre_file, *Pc1_mre_file;

typedef struct c1_mre_file_vtbl c1_mre_file_vtbl, *Pc1_mre_file_vtbl;

struct c1_idb_region_array {
    struct c1_idb_region *data;
    c1_u32 count;
    c1_u32 capacity;
};

struct c1_idb_include_stack {
    struct c1_idb_include_state *data;
    c1_u32 count;
    c1_u32 capacity;
};

struct c1_idb_region {
    c1_u32 signature;
    int length;
    c1_u16 start_line;
    c1_u16 line_count;
    c1_u8 flags;
    c1_u8 pad0d[3];
};

struct c1_idb_include_state {
    struct c1_idb_region_array regions;
    c1_u32 cursor;
    struct c1_idb_region current;
    struct c1_idb_class_record pending_class;
    struct c1_mre_file *tracker;
    c1_u32 name_ni;
    int mtime;
    c1_u32 unk40;
    c1_u8 changed;
    c1_u8 untracked;
    c1_u8 pad46[2];
};

struct c1_mre_file_vtbl {
    void *open_recorder;
    void *note_end_include;
    void *note_class_mod;
    void *note_inline_method_mod;
    void *note_line_delta;
    void *slot14;
    void *note_class_ti;
    void *query_minrebuild_off;
};

struct c1_mre_file {
    struct c1_mre_file_vtbl *vtbl;
};

typedef struct c1_il_buffer c1_il_buffer, *Pc1_il_buffer;

typedef struct c1xx_pdb_stream c1xx_pdb_stream, *Pc1xx_pdb_stream;

typedef struct c1xx_pdb_stream_vtbl c1xx_pdb_stream_vtbl, *Pc1xx_pdb_stream_vtbl;

struct c1xx_pdb_stream_vtbl {
    void *query_cb;
    void *slot04;
    void *slot08;
    void *replace;
    void *append;
    void *slot14;
    void *release;
    void *read_at;
    void *truncate;
};

struct c1xx_pdb_stream {
    struct c1xx_pdb_stream_vtbl *vtbl;
};

struct c1_il_buffer {
    struct c1_byte_buffer bytes;
    FILE *file;
    c1_u8 open;
    char name[260];
    c1_u8 pad11d[3];
    int unk120;
    struct c1xx_pdb_stream *ilstore_stream;
    c1_u8 ilstore_space;
    c1_u8 pad129[3];
    char *ilstore_stream_name;
};

typedef struct c1_il_code_row c1_il_code_row, *Pc1_il_code_row;

struct c1_il_code_row {
    char *codes;
    c1_u32 flags;
};

typedef struct c1_ilstore c1_ilstore, *Pc1_ilstore;

typedef struct c1xx_ilstore_vtbl c1xx_ilstore_vtbl, *Pc1xx_ilstore_vtbl;

struct c1_ilstore {
    struct c1xx_ilstore_vtbl *vtbl;
};

struct c1xx_ilstore_vtbl {
    void *release;
    void *slot04;
    void *get_module;
    void *slot0c;
    void *query_version;
};

typedef struct c1_ilstore_blob c1_ilstore_blob, *Pc1_ilstore_blob;

struct c1_ilstore_blob {
    c1_u8 *data;
    c1_u32 size;
};

typedef struct c1_import_attribute c1_import_attribute, *Pc1_import_attribute;

struct c1_import_attribute {
    char *name;
    struct c1_vector *args;
};

typedef struct c1_import_depgraph c1_import_depgraph, *Pc1_import_depgraph;

typedef struct c1_import_edge c1_import_edge, *Pc1_import_edge;

struct c1_import_edge {
    struct c1_import_edge *next;
    int from;
    int to;
};

struct c1_import_depgraph {
    int n;
    int first_pending;
    c1_u8 *emitted;
    int *unmet;
    int *dependents;
    struct c1_import_edge *edges;
    struct c1_import_edge *free_edges;
};

typedef struct c1_import_enum_entry c1_import_enum_entry, *Pc1_import_enum_entry;

struct c1_import_enum_entry {
    struct c1_import_enum_entry *next;
    char *constant;
    char *enum_name;
    int value;
};

typedef struct c1_import_enum_table c1_import_enum_table, *Pc1_import_enum_table;

struct c1_import_enum_table {
    struct c1_import_enum_entry *buckets[256];
    c1_u32 bucket;
    char *name;
    struct c1_import_enum_entry *found;
};

typedef struct c1_import_key_list c1_import_key_list, *Pc1_import_key_list;

typedef struct c1_import_key_node c1_import_key_node, *Pc1_import_key_node;

struct c1_import_key_node {
    struct c1_import_key_node *next;
    struct c1_import_key_node *prev;
    c1_u32 key;
};

struct c1_import_key_list {
    struct c1_import_key_node *head;
    struct c1_import_key_node *tail;
};

typedef void (*c1_import_param_writer_fn)(struct c1_il_buffer *, struct c1_typedesc *, void *, wchar_t *);

typedef struct c1_int64_words c1_int64_words, *Pc1_int64_words;

struct c1_int64_words {
    c1_u32 lo;
    int hi;
};

typedef struct c1_itypeinfo c1_itypeinfo, *Pc1_itypeinfo;

typedef struct c1_itypeinfo_vtbl c1_itypeinfo_vtbl, *Pc1_itypeinfo_vtbl;

struct c1_itypeinfo {
    struct c1_itypeinfo_vtbl *vtbl;
};

struct c1_itypeinfo_vtbl {
    void *QueryInterface;
    void *AddRef;
    void *Release;
    void *GetTypeAttr;
    void *GetTypeComp;
    void *GetFuncDesc;
    void *GetVarDesc;
    void *GetNames;
    void *GetRefTypeOfImplType;
    void *GetImplTypeFlags;
    void *GetIDsOfNames;
    void *Invoke;
    void *GetDocumentation;
    void *GetDllEntry;
    void *GetRefTypeInfo;
    void *AddressOfMember;
    void *CreateInstance;
    void *GetMops;
    void *GetContainingTypeLib;
    void *ReleaseTypeAttr;
    void *ReleaseFuncDesc;
    void *ReleaseVarDesc;
};

typedef struct c1_itypelib c1_itypelib, *Pc1_itypelib;

typedef struct c1_itypelib_vtbl c1_itypelib_vtbl, *Pc1_itypelib_vtbl;

struct c1_itypelib_vtbl {
    void *QueryInterface;
    void *AddRef;
    void *Release;
    void *GetTypeInfoCount;
    void *GetTypeInfo;
    void *GetTypeInfoType;
    void *GetTypeInfoOfGuid;
    void *GetLibAttr;
    void *GetTypeComp;
    void *GetDocumentation;
    void *IsName;
    void *FindName;
    void *ReleaseTLibAttr;
};

struct c1_itypelib {
    struct c1_itypelib_vtbl *vtbl;
};

typedef struct c1_keyword_row c1_keyword_row, *Pc1_keyword_row;

struct c1_keyword_row {
    char *text;
    c1_u8 token;
    c1_u8 pad05[3];
};

typedef struct c1_line_map c1_line_map, *Pc1_line_map;

struct c1_line_map {
    struct c1_line_map_row *rows;
    c1_u32 count;
    c1_u32 capacity;
};

typedef struct c1_line_map_state c1_line_map_state, *Pc1_line_map_state;

struct c1_line_map_state {
    int position;
    struct c1_line_map map;
    struct c1_line_map_row cached;
};

typedef struct c1_map_region_group c1_map_region_group, *Pc1_map_region_group;

struct c1_map_region_group {
    struct fe_name *file;
    struct c1_import_key_list keys;
    struct c1_map_region_group *next;
};

typedef struct c1_map_region_queue c1_map_region_queue, *Pc1_map_region_queue;

struct c1_map_region_queue {
    struct c1_map_region_group *head;
    struct c1_map_region_group *tail;
};

typedef struct c1_member_lookup_ctx c1_member_lookup_ctx, *Pc1_member_lookup_ctx;

struct c1_member_lookup_ctx {
    struct fe_name *name;
    c1_u32 flags;
    struct c1_symtab *visited;
    struct c1_symtab *hidden;
    struct c1_vector *found;
};

typedef struct c1_member_walk c1_member_walk, *Pc1_member_walk;

struct c1_member_walk {
    c1_u8 valid;
    c1_u8 pad01[3];
    int *link;
};

typedef struct c1_message_buffer c1_message_buffer, *Pc1_message_buffer;

struct c1_message_buffer {
    char *cur;
    c1_u32 room;
    char *start;
    c1_u8 flags;
    c1_u8 pad0d[3];
};

typedef struct c1_mre_compiler c1_mre_compiler, *Pc1_mre_compiler;

typedef struct c1_mre_compiler_vtbl c1_mre_compiler_vtbl, *Pc1_mre_compiler_vtbl;

struct c1_mre_compiler {
    struct c1_mre_compiler_vtbl *vtbl;
};

struct c1_mre_compiler_vtbl {
    void *release;
    void *open_compiland;
    void *close_compiland;
    void *push_file;
    void *pop_file;
    void *save_state;
    void *restore_state;
    void *note_untracked_class;
};

typedef struct c1_mre_engine c1_mre_engine, *Pc1_mre_engine;

typedef struct c1_mre_engine_vtbl c1_mre_engine_vtbl, *Pc1_mre_engine_vtbl;

struct c1_mre_engine {
    struct c1_mre_engine_vtbl *vtbl;
};

struct c1_mre_engine_vtbl {
    void *slot00;
    void *close;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *query_compiler;
    void *slot18;
    void *commit;
};

typedef struct c1_mre_note c1_mre_note, *Pc1_mre_note;

struct c1_mre_note {
    int kind;
    struct c1_symbol *cls;
    void *member;
    struct c1_mre_note *next;
};

typedef struct c1_mre_tracker c1_mre_tracker, *Pc1_mre_tracker;

typedef struct c1_source_file_record c1_source_file_record, *Pc1_source_file_record;

struct c1_mre_tracker {
    struct c1_source_file_record *current;
    struct c1_mre_note *pending;
    c1_u8 busy;
    c1_u8 draining;
    c1_u8 pad0a[2];
};

struct c1_source_file_record {
    char *name;
    struct c1_mre_file *file;
    struct c1_source_file_record *prev;
    c1_u8 tracked;
    c1_u8 pad0d[3];
    int minrebuild_off;
};

typedef struct c1_ovl_candidate c1_ovl_candidate, *Pc1_ovl_candidate;

typedef struct c1_tmpl_deduction c1_tmpl_deduction, *Pc1_tmpl_deduction;

struct c1_tmpl_deduction {
    struct c1_symbol *tmpl;
    struct c1_symbol *specialization;
    struct c1_sym_list *tparams;
    int tparam_count;
    struct c1_arg_list *args;
    struct c1_arg_item *cur_arg;
    c1_u8 *param_bytes;
    void *pending_parameter_scope;
    int pending_function_word;
    struct c1_type *param_type;
    struct c1_type *arg_type;
    c1_u8 flags;
    c1_u8 pad_2d[3];
};

struct c1_ovl_candidate {
    struct c1_symbol *function;
    struct c1_symbol *alias;
    struct c1_symbol *overload_set;
    struct c1_type **params;
    struct c1_type **param_cursor;
    struct c1_type *param_type;
    struct c1_type *object_type;
    struct c1_ovl_candidate *next;
    struct c1_ovl_candidate *prev;
    struct c1_conversion *conversions;
    c1_u32 argument;
    struct c1_builtin_operator_row *row;
    struct c1_type *builtin_left;
    struct c1_type *builtin_right;
    struct c1_tmpl_deduction *deduction;
    c1_u8 flags;
    c1_u8 pad3d[3];
};

typedef union c1_ovl_extra c1_ovl_extra, *Pc1_ovl_extra;

union c1_ovl_extra {
    struct c1_node *right;
    struct c1_arg_list *template_args;
};

typedef struct c1_ovl_resolution c1_ovl_resolution, *Pc1_ovl_resolution;

struct c1_ovl_resolution {
    struct c1_symbol *set;
    struct c1_symbol_vector *specializations;
    int count;
    int live;
    c1_u32 nargs;
    struct c1_ovl_candidate *candidates;
    struct c1_ovl_candidate *head;
    struct c1_ovl_candidate *tail;
    struct c1_conversion *conversions;
    int ncandidates;
    int nconversions;
    int failure_argument;
    int failure_count;
    c1_u8 flags;
    c1_u8 pad35[3];
    int failure;
    c1_u8 failed;
    c1_u8 op;
    c1_u8 pad3e[2];
    struct c1_node *args;
    union c1_ovl_extra extra;
};

typedef struct c1_pack_cell c1_pack_cell, *Pc1_pack_cell;

struct c1_pack_cell {
    struct c1_pack_cell *next;
    int packing;
    void *ident;
};

typedef struct c1_pack_stack c1_pack_stack, *Pc1_pack_stack;

struct c1_pack_stack {
    struct c1_pack_cell *top;
    struct c1_pack_cell *free_cells;
};

typedef struct c1_pair_array c1_pair_array, *Pc1_pair_array;

typedef struct c1_u32_pair c1_u32_pair, *Pc1_u32_pair;

struct c1_pair_array {
    struct c1_u32_pair *data;
    c1_u32 count;
    c1_u32 capacity;
};

struct c1_u32_pair {
    c1_u32 first;
    c1_u32 second;
};

typedef struct c1_parse_state c1_parse_state, *Pc1_parse_state;

typedef struct c1xx_decl_specifiers c1xx_decl_specifiers, *Pc1xx_decl_specifiers;

struct c1xx_decl_specifiers {
    c1_u8 spec[24];
    struct c1_type *type;
    struct c1_symbol *type_sym;
    void *insert_fn;
};

struct c1_parse_state {
    c1_u8 block_depth;
    c1_u8 il_block_level;
    short block_number;
    struct c1_symbol *member_function_class;
    struct c1_symbol *current_function;
    struct c1_symbol *tmpl_current_template;
    struct c1_symbol *tmpl_current_instance;
    void *tmpl_bound_scope;
    c1_u8 unk18[40];
    c1_u32 compile_flags_c4;
    c1_u32 compile_flags_c8;
    c1_u32 compile_flags_cc;
    c1_u32 compile_flags_d0;
    int prototype_scope_depth;
    void *access_report_class;
    void *access_report_vbase;
    void *access_report_member;
    void *access_report_base;
    c1_u8 access_report_inherit_access;
    c1_u8 access_report_member_access;
    c1_u8 special_member_context;
    c1_u8 pad67;
    int parse_block_record_depth;
    int sizeof_depth;
    int class_depth;
    struct c1_class_def_entry *class_def_stack;
    c1_u8 member_access_op;
    c1_u8 pad79[3];
    int paren_depth;
    struct c1xx_decl_specifiers *paren_declspecs;
    struct c1_symbol **pending_access;
    c1_u8 *paren_flags;
    struct c1_arg_list **paren_arg_lists;
    void *pending_parameter_scope;
    int pending_function_word;
    void *function_parameter_scope;
    int function_context_word;
    int scope_restore_kind;
    struct c1_decl_state *decl_state;
    int token_position;
    int qualified_lookup_found_overloads;
    c1_u8 byte_de316;
    c1_u8 padb1[3];
    int word_d2cd4;
    struct c1_deferred_parse *default_argument_parse_stack;
    c1_u32 word_d2190;
};

typedef struct c1_parse_translation_unit_frame c1_parse_translation_unit_frame, *Pc1_parse_translation_unit_frame;

typedef union c1_yy_value c1_yy_value, *Pc1_yy_value;

typedef struct c1_yy_parser c1_yy_parser, *Pc1_yy_parser;

typedef struct c1_ptr_operator c1_ptr_operator, *Pc1_ptr_operator;

typedef struct c1_template_header_record c1_template_header_record, *Pc1_template_header_record;

typedef struct c1_string_value c1_string_value, *Pc1_string_value;

typedef struct c1xx_warning_state c1xx_warning_state, *Pc1xx_warning_state;

typedef struct c1_warning_record c1_warning_record, *Pc1_warning_record;

struct c1_ptr_operator {
    c1_u16 kind;
    c1_u16 modifiers;
    c1_u16 cv;
    c1_u16 pad06;
    void *extra;
};

struct c1_string_value {
    c1_u8 *text;
    c1_u16 length;
    c1_u16 flags;
};

union c1_yy_value {
    c1_u32 words[10];
    void *ptr;
    struct c1_declarator *declarator;
    struct c1_node *node;
    struct c1_symbol *sym;
    struct c1_arg_list *args;
    c1_u32 flags;
    struct c1_symbol **cell;
    struct c1_decl_modifier mods;
    struct c1_ptr_operator ptr_op;
    struct c1xx_decl_specifiers spec;
    struct c1_template_header_record *header;
    struct c1_param_clause *params;
    struct fe_name *name;
    struct c1_type *type;
    struct c1_arg_item *arg;
    struct c1_string_value str;
    struct c1_overload_set *qualified;
    struct c1_sym_list *template_params;
};

struct c1_yy_parser {
    c1_u32 unk00;
    int error_count;
    int errflag;
    c1_u32 unk0c;
    c1_u32 unk10;
    c1_u32 unk14;
    union c1_yy_value values[1024];
    int states[1024];
};

struct c1_template_header_record {
    void *parameter_scope;
    int function_word;
    struct c1_symbol *tmpl;
    struct c1_symbol *instance;
    struct c1_symbol *member;
    void *bound_scope;
    struct c1_symbol *ns;
    int position;
    struct c1xx_warning_state *warning_state;
};

struct c1_parse_translation_unit_frame {
    int result;
    union c1_yy_value saved_value;
    struct c1_yy_parser *saved_parser;
    void *saved_esp;
    void *exception_pointers;
    void *next_registration;
    void *handler;
    struct c1_seh_scope *scope_table;
    int try_level;
};

struct c1xx_warning_state {
    char state[1000];
    int level;
    struct c1_warning_record *saved;
    struct c1xx_warning_state *outer;
};

struct c1_warning_record {
    c1_u32 next;
    c1_u32 value;
};

typedef struct c1_pch_include_count c1_pch_include_count, *Pc1_pch_include_count;

struct c1_pch_include_count {
    short count;
    short last_key;
};

typedef struct c1_pch_name_lengths c1_pch_name_lengths, *Pc1_pch_name_lengths;

struct c1_pch_name_lengths {
    c1_u16 object_name_length;
    c1_u16 browse_name_length;
};

typedef struct c1_pch_option_block c1_pch_option_block, *Pc1_pch_option_block;

struct c1_pch_option_block {
    int opt_ZE;
    c1_u8 ms_extensions;
    c1_u8 opt_ZBe;
    c1_u8 pad006[2];
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
    c1_u8 pad015[3];
    int opt_MD;
    c1_u8 opt_MT;
    c1_u8 pad01d[3];
    c1_u8 opt_Gc;
    c1_u8 opt_Zi;
    c1_u8 pch_debug_in_object;
    c1_u8 pad023;
    struct c1_pch_name_lengths name_lengths;
    c1_u8 opt_EP_no_line;
    c1_u8 opt_pf;
    c1_u8 pad02a[2];
    int autoinline_tuple_limit;
    c1_u8 opt_Brepro;
    c1_u8 pad031;
    c1_u8 opt_Oi;
    c1_u8 opt_stack_probes;
    c1_u8 pad034[8];
    int opt_Gd;
    int default_stdcall;
    c1_u8 opt_Gf;
    c1_u8 string_pooling;
    c1_u8 string_pooling_readonly;
    c1_u8 string_pooling_readonly_state;
    c1_u8 opt_cbstring;
    c1_u8 pad049[3];
    int opt_G_cpu;
    c1_u8 opt_GM;
    c1_u8 pad051[3];
    int inline_level;
    c1_u8 browse_info;
    c1_u8 browse_info_full;
    c1_u8 pad05a[2];
    c1_u32 function_option_word;
    c1_u8 pad060;
    c1_u8 opt_eh;
    c1_u8 rtti;
    c1_u8 opt_noBool;
    c1_u8 unk064;
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
    char pch_library_id[256];
    char header_name[260];
    c1_u8 opt_Oq;
    c1_u8 unk374;
    c1_u8 opt_Ov;
    c1_u8 pad376[2];
    c1_u32 pdb_signature;
    c1_u32 pdb_gi_signature;
    c1_u8 c9il_mode;
    c1_u8 incremental;
    c1_u8 opt_GI;
    c1_u8 pad383;
    c1_u8 opt_GFR;
    c1_u8 split_pdbs;
    c1_u8 opt_NoEHForNew;
    c1_u8 gi_forced_by_gm;
    c1_u8 opt_EHc;
    c1_u8 opt_ZI;
    c1_u8 pad38a[2];
};

typedef struct c1_pdb_blob_entry c1_pdb_blob_entry, *Pc1_pdb_blob_entry;

struct c1_pdb_blob_entry {
    struct c1_pdb_blob_entry *next;
    char *name;
    c1_u32 size;
    void *data;
};

typedef struct c1_pdb_blob_index_record c1_pdb_blob_index_record, *Pc1_pdb_blob_index_record;

struct c1_pdb_blob_index_record {
    c1_u32 name_size;
    c1_u32 name_offset;
    c1_u32 data_size;
    c1_u32 data_offset;
};

typedef struct c1_pdb_blob_stream_header c1_pdb_blob_stream_header, *Pc1_pdb_blob_stream_header;

struct c1_pdb_blob_stream_header {
    c1_u32 signature;
    int count;
    c1_u32 index_size;
    c1_u32 data_size;
};

typedef struct c1_pdb_blob_table c1_pdb_blob_table, *Pc1_pdb_blob_table;

struct c1_pdb_blob_table {
    struct c1xx_pdb_stream *stream;
    c1_u8 dirty;
    c1_u8 pad05[3];
    struct c1_pdb_blob_entry *entries;
    int count;
};

typedef struct c1_pdb_namemap c1_pdb_namemap, *Pc1_pdb_namemap;

typedef struct c1xx_pdb_namemap_vtbl c1xx_pdb_namemap_vtbl, *Pc1xx_pdb_namemap_vtbl;

struct c1xx_pdb_namemap_vtbl {
    void *close;
    void *slot04;
    void *get_ni;
    void *get_name;
    void *slot10;
    void *slot14;
    void *commit;
};

struct c1_pdb_namemap {
    struct c1xx_pdb_namemap_vtbl *vtbl;
};

typedef struct c1_pdb_session c1_pdb_session, *Pc1_pdb_session;

typedef struct c1xx_pdb c1xx_pdb, *Pc1xx_pdb;

typedef struct c1_pdb_tpi c1_pdb_tpi, *Pc1_pdb_tpi;

typedef struct c1xx_pdb_vtbl c1xx_pdb_vtbl, *Pc1xx_pdb_vtbl;

typedef struct c1_pdb_tpi_vtbl c1_pdb_tpi_vtbl, *Pc1_pdb_tpi_vtbl;

struct c1_pdb_tpi {
    struct c1_pdb_tpi_vtbl *vtbl;
};

struct c1_pdb_session {
    struct c1xx_pdb *pdb;
    struct c1_pdb_namemap *namemap;
    struct c1_pdb_tpi *tpi;
    struct c1_mre_engine *mre;
    struct c1_mre_compiler *mre_compiler;
    struct c1_pdb_blob_table *blob_table;
    c1_u8 read_only;
    c1_u8 pad19[3];
    c1_u32 unk1c;
};

struct c1_pdb_tpi_vtbl {
    void *slot00;
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
    void *slot18;
    void *slot1c;
    void *close;
    void *commit;
};

struct c1xx_pdb {
    struct c1xx_pdb_vtbl *vtbl;
};

struct c1xx_pdb_vtbl {
    void *slot00;
    void *slot04;
    void *slot08;
    void *query_pdb_name;
    void *query_signature;
    void *query_age;
    void *slot18;
    void *slot1c;
    void *open_tpi;
    void *commit;
    void *close;
    void *open_stream;
    void *slot30;
    void *get_raw_bytes;
};

typedef union c1_placement_slot c1_placement_slot, *Pc1_placement_slot;

union c1_placement_slot {
    struct c1_arg_iter *iter;
    struct c1_node *operand;
};

typedef struct c1_pp_value c1_pp_value, *Pc1_pp_value;

struct c1_pp_value {
    c1_u16 type;
    c1_u16 unk02;
    c1_u32 unk04;
    struct c1_int64_words value;
};

typedef struct c1_pragma_comment c1_pragma_comment, *Pc1_pragma_comment;

struct c1_pragma_comment {
    struct c1_pragma_comment *next;
    int kind;
    char *text;
};

typedef struct c1_saved_operand c1_saved_operand, *Pc1_saved_operand;

struct c1_saved_operand {
    struct c1_node *root;
    struct c1_node *slot1;
    struct c1_node *slot2;
    struct c1_node *replacement;
};

typedef struct c1_scope_stack c1_scope_stack, *Pc1_scope_stack;

struct c1_scope_stack {
    struct c1xx_scope *global_scope;
    struct c1xx_scope *current;
    struct c1xx_scope *contexts[128];
    c1_u8 depth;
    c1_u8 pad209[3];
    struct c1_decl_state *saved;
    struct c1_symbol *qual_class;
    struct c1_using_cell **using_namespaces;
    struct c1_symbol_vector *visited_namespaces;
    c1_u8 access_op;
    c1_u8 reported;
    c1_u8 keep_aliases;
    c1_u8 qualified;
    struct c1_symbol *global_ns;
    struct c1xx_scope *closed_blocks;
    void *segments;
    struct fe_file_record *file_records;
};

typedef struct c1_stat c1_stat, *Pc1_stat;

struct c1_stat {
    c1_u32 st_dev;
    c1_u16 st_ino;
    c1_u16 st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    c1_u8 pad0e[2];
    c1_u32 st_rdev;
    long st_size;
    long st_atime;
    long st_mtime;
    long st_ctime;
};

typedef struct c1_static_guard c1_static_guard, *Pc1_static_guard;

struct c1_static_guard {
    struct c1_symbol *guard;
    c1_u8 mask;
    c1_u8 pad05[3];
};

typedef struct c1_switch_cases_cell c1_switch_cases_cell, *Pc1_switch_cases_cell;

struct c1_switch_cases_cell {
    struct c1_switch_cases_cell *next;
    void *cases;
};

typedef struct c1_switch_letter_row c1_switch_letter_row, *Pc1_switch_letter_row;

struct c1_switch_letter_row {
    int letter;
    int action;
    c1_u8 *variable;
};

typedef struct c1_switch_row c1_switch_row, *Pc1_switch_row;

struct c1_switch_row {
    char *pattern;
    c1_u8 *variable;
    c1_u8 continue_parse;
    c1_u8 kind;
    c1_u16 pad;
};

typedef struct c1_symbol_attrs c1_symbol_attrs, *Pc1_symbol_attrs;

struct c1_symbol_attrs {
    c1_u8 storage;
    c1_u8 flags21;
    c1_u8 flags22;
    c1_u8 flags23;
    struct c1_symbol *segment;
    void *declarator_record;
    void *declspec;
    int earlier_entity;
    c1_u8 flags;
    c1_u8 pad15[3];
};

typedef char (*c1_symtab_equal_fn)(void *, void *);

typedef struct c1_symtab_iter c1_symtab_iter, *Pc1_symtab_iter;

struct c1_symtab_iter {
    struct c1_symtab *tab;
    struct c1_symtab_entry *entry;
    c1_u32 next_bucket;
    void *key;
    void *value;
};

typedef struct c1_system_info c1_system_info, *Pc1_system_info;

struct c1_system_info {
    c1_u32 dwOemId;
    c1_u32 dwPageSize;
    void *lpMinimumApplicationAddress;
    void *lpMaximumApplicationAddress;
    c1_u32 dwActiveProcessorMask;
    c1_u32 dwNumberOfProcessors;
    c1_u32 dwProcessorType;
    c1_u32 dwAllocationGranularity;
    c1_u16 wProcessorLevel;
    c1_u16 wProcessorRevision;
};

typedef struct c1_text_buffer c1_text_buffer, *Pc1_text_buffer;

struct c1_text_buffer {
    int handle;
    char *data;
    c1_u32 front;
    c1_u32 end;
    c1_u32 capacity;
};

typedef struct c1_throw_info_item c1_throw_info_item, *Pc1_throw_info_item;

struct c1_throw_info_item {
    struct c1_symbol *sym;
    struct c1_symbol *dtor;
    struct c1_symbol *catchable_array;
    struct c1_type *type;
    struct c1_type *match_type;
    struct c1_type *object_type;
    c1_u16 cv;
    c1_u16 pad1a;
    c1_u32 flags;
};

typedef struct c1_thunk_key c1_thunk_key, *Pc1_thunk_key;

struct c1_thunk_key {
    int kind;
    struct c1_symbol *target;
    int delta;
    int vtordisp;
};

typedef struct c1_tlibattr c1_tlibattr, *Pc1_tlibattr;

struct c1_tlibattr {
    struct c1_guid guid;
    c1_u32 lcid;
    int syskind;
    c1_u16 wMajorVerNum;
    c1_u16 wMinorVerNum;
    c1_u16 wLibFlags;
    c1_u16 pad1e;
};

typedef struct c1_tmpl_context_note c1_tmpl_context_note, *Pc1_tmpl_context_note;

struct c1_tmpl_context_note {
    struct c1_diag_note_vtbl *vtbl;
    int position;
    struct c1_symbol *sym;
    int note;
};

typedef struct c1_tmpl_work_item c1_tmpl_work_item, *Pc1_tmpl_work_item;

struct c1_tmpl_work_item {
    void *vtbl;
    struct c1_symbol *sym;
    c1_u8 armed;
    c1_u8 pad09[3];
    struct c1_tmpl_work_item *next;
};

typedef struct c1_tmpl_work_queue c1_tmpl_work_queue, *Pc1_tmpl_work_queue;

struct c1_tmpl_work_queue {
    struct c1_tmpl_work_item *first;
    struct c1_tmpl_work_item *last;
    c1_u8 armed;
    c1_u8 pad09[3];
};

typedef struct c1_token_reader c1_token_reader, *Pc1_token_reader;

typedef struct c1_token_source_frame c1_token_source_frame, *Pc1_token_source_frame;

struct c1_token_reader {
    int position;
    struct c1_token_source_frame *top;
};

struct c1_token_source_frame {
    struct c1xx_token_stream *stream;
    struct c1_token_source_frame *prev;
    int position;
    int kind;
    void (*on_pop)(void);
};

typedef struct c1_tree_visitor c1_tree_visitor, *Pc1_tree_visitor;

struct c1_tree_visitor {
    void **vtbl;
    c1_u8 kind_mask;
    c1_u8 pad05[3];
};

typedef struct c1_try_block c1_try_block, *Pc1_try_block;

struct c1_try_block {
    int line;
    c1_u32 x04;
    c1_u32 x08;
    struct c1_vector *handlers;
    struct c1_node *end_label;
    c1_u8 flag14;
    c1_u8 pad15[3];
};

typedef struct c1_type_chain_cell c1_type_chain_cell, *Pc1_type_chain_cell;

struct c1_type_chain_cell {
    struct c1_type_chain_cell *next;
    struct c1_type *type;
};

typedef struct c1_type_emission_cell c1_type_emission_cell, *Pc1_type_emission_cell;

struct c1_type_emission_cell {
    struct c1_symbol *sym;
    struct c1_type_emission_cell *next;
};

typedef struct c1_typeattr c1_typeattr, *Pc1_typeattr;

struct c1_typeattr {
    struct c1_guid guid;
    c1_u32 lcid;
    c1_u32 dwReserved;
    int memidConstructor;
    int memidDestructor;
    wchar_t *lpstrSchema;
    c1_u32 cbSizeInstance;
    int typekind;
    c1_u16 cFuncs;
    c1_u16 cVars;
    c1_u16 cImplTypes;
    c1_u16 cbSizeVft;
    c1_u16 cbAlignment;
    c1_u16 wTypeFlags;
    c1_u16 wMajorVerNum;
    c1_u16 wMinorVerNum;
    struct c1_typedesc tdescAlias;
    c1_u32 idldescType_dwReserved;
    c1_u16 idldescType_wIDLFlags;
    c1_u16 pad4a;
};

typedef struct c1_value_cell c1_value_cell, *Pc1_value_cell;

struct c1_value_cell {
    struct c1_value_cell *next;
    int value;
};

typedef struct c1_vardesc c1_vardesc, *Pc1_vardesc;

struct c1_vardesc {
    int memid;
    wchar_t *lpstrSchema;
    void *lpvarValue;
    struct c1_elemdesc elemdescVar;
    c1_u16 wVarFlags;
    c1_u16 pad1e;
    int varkind;
};

typedef struct c1_vbase_map_key c1_vbase_map_key, *Pc1_vbase_map_key;

struct c1_vbase_map_key {
    struct c1_symbol *cls_a;
    struct c1_symbol *cls_b;
    c1_u8 reverse;
    c1_u8 emitted;
    c1_u8 pad0a[2];
};

typedef struct c1_vcall_thunk_key c1_vcall_thunk_key, *Pc1_vcall_thunk_key;

struct c1_vcall_thunk_key {
    struct c1_symbol *member;
    int vtable_offset;
    c1_u16 convention;
    c1_u8 emitted;
    c1_u8 pad0b;
};

typedef struct c1_vtable_slot_iter c1_vtable_slot_iter, *Pc1_vtable_slot_iter;

struct c1_vtable_slot_iter {
    struct c1_vtable_record *table;
    int index;
    int *current;
};

typedef struct c1_x87_tail c1_x87_tail, *Pc1_x87_tail;

struct c1_x87_tail {
    c1_u16 sign_exponent;
    c1_u16 pad;
};

typedef union c1_yy_action_slot c1_yy_action_slot, *Pc1_yy_action_slot;

union c1_yy_action_slot {
    struct c1_symbol *sym;
    struct c1_declarator *declarator;
};

typedef struct c1_yy_correction c1_yy_correction, *Pc1_yy_correction;

struct c1_yy_correction {
    short state;
    short terminal;
    short new_state;
};

typedef struct c1_yy_lookahead_parser c1_yy_lookahead_parser, *Pc1_yy_lookahead_parser;

struct c1_yy_lookahead_parser {
    struct c1xx_token *lookahead;
    int error_count;
    int errflag;
    short state;
    c1_u16 pad0e;
    short *ps;
    union c1_yy_value *pv;
    union c1_yy_value values[150];
    short states[152];
};

typedef struct c1xx_bitvec c1xx_bitvec, *Pc1xx_bitvec;

struct c1xx_bitvec {
    struct c1_arena *arena;
    c1_u8 in_arena;
    c1_u8 owns_bits;
    c1_u8 pad06[2];
    int nbits;
    c1_u8 *bits;
    int nbytes;
    int iter_bit;
    int iter_byte;
    c1_u8 iter_bits;
    c1_u8 pad1d[3];
};

typedef struct c1xx_block_scope c1xx_block_scope, *Pc1xx_block_scope;

typedef struct c1xx_block_scope_vtbl c1xx_block_scope_vtbl, *Pc1xx_block_scope_vtbl;

struct c1xx_block_scope {
    struct c1xx_block_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    struct c1_sym_list *symbols;
};

struct c1xx_block_scope_vtbl {
    bool (*has_entries)(struct c1xx_block_scope *);
    byte (*has_usings)(void);
    void (*insert)(void *, struct c1_symbol *);
    c1_u8 * (*lookup)(void *, int, int);
    c1_u8 * (*lookup_tag)(struct c1xx_block_scope *, int);
    c1_u8 * (*lookup_by_kind)(struct c1xx_block_scope *, int, uint, byte *);
    void (*lookup_anonymous_member)(struct c1xx_block_scope *, void *, int *);
    void * (*find_link)(struct c1xx_block_scope *, int);
    void (*pch_fixup)(struct c1xx_hash_scope *);
    void (*emit_il)(struct c1xx_block_scope *);
    void (*link)(struct c1xx_block_scope *, struct c1_symbol *);
};

typedef struct c1xx_browse_record c1xx_browse_record, *Pc1xx_browse_record;

struct c1xx_browse_record {
    c1_u8 kind;
    c1_u8 flags;
    c1_u8 type;
    c1_u8 pad03;
    int line;
    c1_u32 entity;
    char *name;
    struct fe_name *name_record;
    c1_u16 attributes;
    c1_u16 pad16;
};

typedef struct c1xx_class_scope c1xx_class_scope, *Pc1xx_class_scope;

typedef struct c1xx_class_scope_vtbl c1xx_class_scope_vtbl, *Pc1xx_class_scope_vtbl;

struct c1xx_class_scope {
    struct c1xx_class_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    struct c1_symbol *cls;
    struct c1xx_block_scope *binding;
    c1_u8 reached;
    c1_u8 pad1d[3];
};

struct c1xx_class_scope_vtbl {
    char (*has_entries)(void);
    byte (*has_usings)(void);
    void (*insert)(struct c1xx_class_scope *, struct c1_symbol *);
    c1_u8 * (*lookup)(struct c1xx_class_scope *, int, int);
    c1_u8 * (*lookup_tag)(struct c1xx_class_scope *, void *);
    c1_u8 * (*lookup_by_kind)(struct c1xx_class_scope *, int *, uint, char *);
    void (*lookup_anonymous_member)(struct c1xx_class_scope *, void *, int *);
    int * (*find_link)(struct c1xx_class_scope *, int *);
    void (*pch_fixup)(struct c1xx_hash_scope *);
    void (*emit_il)(void *);
    void (*link)(struct c1xx_scope *, struct c1_symbol *);
};

typedef struct c1xx_debug_method_iter c1xx_debug_method_iter, *Pc1xx_debug_method_iter;

typedef struct c1xx_debug_method_iter_vtbl c1xx_debug_method_iter_vtbl, *Pc1xx_debug_method_iter_vtbl;

struct c1xx_debug_method_iter {
    struct c1xx_debug_method_iter_vtbl *vtbl;
    struct c1_sym_link *next;
    struct c1_sym_link *current;
    struct c1_sym_link *start;
};

struct c1xx_debug_method_iter_vtbl {
    char (*debug_member_iter_next)(struct c1xx_debug_method_iter *);
};

typedef struct c1xx_emitter_suspend c1xx_emitter_suspend, *Pc1xx_emitter_suspend;

typedef struct c1xx_il_emitter c1xx_il_emitter, *Pc1xx_il_emitter;

typedef struct c1xx_il_emitter_vtbl c1xx_il_emitter_vtbl, *Pc1xx_il_emitter_vtbl;

struct c1xx_emitter_suspend {
    c1_u8 enabled;
    c1_u8 references;
    c1_u8 pad02[2];
    int depth;
    struct c1xx_il_emitter *saved;
};

struct c1xx_il_emitter_vtbl {
    void (*finish)(void);
    void (*flush)(void);
    void (*end_block)(void);
    void (*begin_block)(void);
    void (*end_module)(void);
    void (*end_module_if)(int);
    void (*begin_module)(void);
    void (*reference_symbol)(int);
    void (*define_symbol)(struct c1xx_il_emitter *, struct c1_symbol *);
    void (*reference_macro)(int);
    void (*define_macro)(struct c1xx_il_emitter *, int *);
    void (*input_refilled)(void);
    void (*set_owner)(int);
    void (*record_11)(void);
    void (*abort)(void);
    void (*pch_name)(int);
    void (*pch_mark)(void);
    void (*begin_instantiation)(int);
    void (*end_instantiation)(void);
    void (*record_c)(int);
    void (*record_d)(int);
    int (*mark_definition)(int, int);
    void (*open)(struct c1xx_il_emitter *);
    char (*reopen)(struct c1xx_il_emitter *);
    void (*region_boundary)(void);
    uint (*entity_id)(struct c1xx_il_emitter *, struct c1_symbol *);
    int * (*assign_entity_id)(struct c1xx_il_emitter *, int *, int);
    void (*discard)(void);
    void (*begin_region)(void);
};

struct c1xx_il_emitter {
    struct c1xx_il_emitter_vtbl *vtbl;
};

typedef struct c1xx_float_const c1xx_float_const, *Pc1xx_float_const;

struct c1xx_float_const {
    c1_u32 mantissa_lo;
    c1_u32 mantissa_hi;
    c1_u16 sign_exponent;
    c1_u16 size;
};

typedef struct c1xx_idb c1xx_idb, *Pc1xx_idb;

typedef struct c1xx_idb_vtbl c1xx_idb_vtbl, *Pc1xx_idb_vtbl;

typedef struct c1xx_pdb_map c1xx_pdb_map, *Pc1xx_pdb_map;

typedef struct c1xx_pdb_array c1xx_pdb_array, *Pc1xx_pdb_array;

typedef struct c1xx_source_tracker_iface c1xx_source_tracker_iface, *Pc1xx_source_tracker_iface;

typedef struct c1xx_pdb_array c1xx_pdb_iset;

typedef struct c1xx_source_tracker_iface_vtbl c1xx_source_tracker_iface_vtbl, *Pc1xx_source_tracker_iface_vtbl;

struct c1xx_pdb_array {
    c1_u32 *data;
    c1_u32 count;
    c1_u32 capacity;
};

struct c1xx_pdb_map {
    struct c1xx_pdb_array domain;
    struct c1xx_pdb_array range;
    c1xx_pdb_iset present;
    c1xx_pdb_iset deleted;
    c1_u32 count;
};

struct c1xx_source_tracker_iface_vtbl {
    void *take;
    void *sign_next;
    void *reset;
};

struct c1xx_source_tracker_iface {
    struct c1xx_source_tracker_iface_vtbl *vtbl;
    c1_u32 signature;
    int count;
    c1_u8 *mark;
};

struct c1xx_idb {
    struct c1xx_idb_vtbl *vtbl;
    int incremental;
    int backup_on_write;
    int read_from_backup;
    int state;
    int force_recompile;
    int cond_depth;
    int invalidated;
    int reused;
    struct c1_idb_include_stack include_stack;
    struct c1xx_pdb_map old_file_times;
    int pch_generation_loaded;
    int pch_generation;
    struct c1xx_pdb_map header_times;
    struct c1xx_pdb_map header_signatures;
    struct c1_idb_include_state file;
    struct c1_idb_browse_table browse_lines;
    int regions_pch_generation;
    int options_signature;
    int unk130;
    int browse_size;
    struct c1xx_pdb_array name_hash_bits;
    struct c1xx_pdb_map file_times;
    struct c1xx_pdb *pdb;
    struct c1xx_pdb *pdb_backup;
    struct c1xx_source_tracker_iface *source_tracker;
    struct c1_pdb_namemap *name_map;
    struct c1xx_pdb_stream *deps_stream;
    struct c1xx_pdb_stream *deps_stream_backup;
    struct c1xx_pdb_stream *module_stream;
    struct c1xx_pdb_stream *module_stream_backup;
    c1_u32 pdb_signature;
    c1_u32 pdb_age;
    c1_u8 in_function;
    c1_u8 helper_called;
    c1_u8 regions_disabled;
    c1_u8 pad1a3;
};

struct c1xx_idb_vtbl {
    int (*idb_commit)(struct c1xx_idb *);
    uint (*idb_release)(struct c1xx_idb *);
    int (*idb_begin_unit)(struct c1xx_idb *, int *);
    int (*idb_begin_unit_no_check)(struct c1xx_idb *, int *);
    int (*idb_begin_source_file)(struct c1xx_idb *);
    uint (*idb_function_begin)(struct c1xx_idb *, uint, uint, int, int *, int *, short *, int *);
    uint (*idb_function_end)(struct c1xx_idb *, uint, uint, int, int *, int *);
    void (*idb_note_macro_change)(struct c1xx_idb *);
    int (*idb_note_pragma)(struct c1xx_idb *, int);
    int (*idb_note_pragma_output)(struct c1xx_idb *, int);
    int (*idb_conditional_enter)(struct c1xx_idb *);
    int (*idb_conditional_leave)(struct c1xx_idb *);
    int (*idb_include_enter)(struct c1xx_idb *, char *, byte);
    int (*idb_include_leave)(struct c1xx_idb *, uint);
    int (*idb_class_begin)(struct c1xx_idb *, uint, int);
    int (*idb_class_end)(struct c1xx_idb *, uint, int, uint *);
    int (*idb_note_warning)(struct c1xx_idb *);
    int (*idb_note_error)(struct c1xx_idb *);
    int (*idb_note_global_il_record)(struct c1xx_idb *);
    int (*idb_note_line_dependency)(struct c1xx_idb *);
    int (*idb_note_predefined_macro)(struct c1xx_idb *);
    int (*idb_check_options)(struct c1xx_idb *, int, int *);
    uint (*idb_pch_written)(struct c1xx_idb *, int *);
    uint (*idb_pch_read)(struct c1xx_idb *, int *);
    void (*idb_force_recompile)(struct c1xx_idb *);
    int (*idb_note_dependency_64)(struct c1xx_idb *);
    int (*idb_note_special_members)(struct c1xx_idb *);
    int (*idb_note_first_use)(struct c1xx_idb *);
    void (*vtable_nop)(void);
    int (*idb_add_name)(struct c1xx_idb *, char *);
    int (*idb_has_name)(struct c1xx_idb *, char *);
    int (*idb_in_function)(struct c1xx_idb *);
    void (*idb_note_helper_call)(struct c1xx_idb *);
    int (*idb_helper_called)(struct c1xx_idb *);
    int (*idb_set_tracker)(struct c1xx_idb *, struct c1_mre_file *);
    int (*idb_function_body_begin)(struct c1xx_idb *, uint, int);
    uint (*idb_function_body_end)(struct c1xx_idb *, uint, int, int *);
    int (*idb_tracker_note)(struct c1xx_idb *, int, char *);
    int (*idb_note_layout_dependency)(struct c1xx_idb *);
    int (*idb_scope_kind3_to_4)(struct c1xx_idb *, uint, int);
    int (*idb_scope_kind4_end)(struct c1xx_idb *, uint, int);
    int (*idb_note_pragma_begin)(struct c1xx_idb *);
    int (*idb_scope_kind3_to_2)(struct c1xx_idb *, uint, int);
    int (*idb_scope_kind2_to_3)(struct c1xx_idb *, uint, int);
    void (*idb_note_access_declaration)(struct c1xx_idb *);
    void (*idb_note_decl_specifier)(struct c1xx_idb *);
    void (*idb_note_sizeof)(struct c1xx_idb *);
    int (*idb_browse_table_reset)(struct c1xx_idb *);
    int (*idb_browse_set_region)(struct c1xx_idb *, int, int, int);
    int (*idb_browse_set_lines)(struct c1xx_idb *, short, short);
    int (*idb_browse_region_count)(struct c1xx_idb *);
    int (*idb_browse_region)(struct c1xx_idb *, uint, struct c1_idb_browse_entry **);
    int (*idb_browse_truncate)(struct c1xx_idb *);
    int (*idb_invalidate)(struct c1xx_idb *);
    void (*idb_browse_set_size)(struct c1xx_idb *, int);
    int (*idb_browse_size)(struct c1xx_idb *);
    int (*idb_set_pdb_signature)(struct c1xx_idb *, int, uint);
    void (*idb_disable_incremental)(struct c1xx_idb *);
};

typedef struct c1xx_idb_base c1xx_idb_base, *Pc1xx_idb_base;

typedef struct c1xx_idb_base_vtbl c1xx_idb_base_vtbl, *Pc1xx_idb_base_vtbl;

struct c1xx_idb_base_vtbl {
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

struct c1xx_idb_base {
    struct c1xx_idb_base_vtbl *vtbl;
};

typedef struct c1xx_idb_stub c1xx_idb_stub, *Pc1xx_idb_stub;

typedef struct c1xx_idb_stub_vtbl c1xx_idb_stub_vtbl, *Pc1xx_idb_stub_vtbl;

struct c1xx_idb_stub_vtbl {
    int (*vtable_true)(void);
    int (*idb_stub_release)(struct c1xx_idb_stub *);
    int (*vtable_set_out_true)(int *);
    int (*vtable_set_out_true_2)(int *);
    int (*vtable_true_2)(void);
    uint (*idb_stub_function_begin)(struct c1xx_idb_stub *, uint, uint, int, uint *, int *, ushort *, uint *);
    uint (*idb_stub_function_end)(struct c1xx_idb_stub *, uint, uint, uint, uint *, uint *);
    int (*vtable_true_3)(void);
    int (*vtable_true_arg1)(int);
    int (*vtable_true_arg1_2)(int);
    int (*vtable_true_4)(void);
    int (*vtable_true_5)(void);
    int (*vtable_true_arg2)(int, int);
    int (*vtable_true_arg1_3)(int);
    int (*vtable_true_arg2_2)(int, int);
    uint (*idb_stub_clear_third_out)(struct c1xx_idb_stub *, uint, uint, uint *);
    int (*vtable_true_6)(void);
    int (*vtable_true_7)(void);
    int (*vtable_true_8)(void);
    int (*vtable_true_9)(void);
    int (*vtable_true_10)(void);
    uint (*idb_stub_check_options)(struct c1xx_idb_stub *, int, uint *);
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
    uint (*idb_stub_clear_third_out_2)(struct c1xx_idb_stub *, uint, uint, uint *);
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
    int (*idb_stub_true_3)(struct c1xx_idb_stub *, int, int, int);
    int (*vtable_true_arg2_9)(int, int);
    int (*vtable_false_3)(void);
    int (*idb_stub_region_none)(int, int *);
    int (*vtable_true_21)(void);
    int (*vtable_true_22)(void);
    void (*vtable_nop_arg1)(int);
    int (*vtable_false_4)(void);
    int (*vtable_true_arg2_10)(int, int);
    int (*vtable_true_23)(void);
};

struct c1xx_idb_stub {
    struct c1xx_idb_stub_vtbl *vtbl;
};

typedef struct c1xx_il_emitter_browse c1xx_il_emitter_browse, *Pc1xx_il_emitter_browse;

typedef struct c1xx_il_emitter_browse_vtbl c1xx_il_emitter_browse_vtbl, *Pc1xx_il_emitter_browse_vtbl;

struct c1xx_il_emitter_browse_vtbl {
    void (*finish)(struct c1xx_il_emitter_browse *);
    void (*flush)(void);
    void (*end_block)(struct c1xx_il_emitter_browse *);
    void (*begin_block)(struct c1xx_il_emitter_browse *);
    void (*end_module)(struct c1xx_il_emitter_browse *);
    void (*end_module_if)(struct c1xx_il_emitter_browse *, int);
    void (*begin_module)(struct c1xx_il_emitter_browse *);
    void (*reference_symbol)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    void (*define_symbol)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    void (*reference_macro)(struct c1xx_il_emitter_browse *, int *);
    void (*define_macro)(struct c1xx_il_emitter_browse *, struct fe_macro *);
    void (*input_refilled)(struct c1xx_il_emitter_browse *);
    void (*set_owner)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    void (*record_11)(struct c1xx_il_emitter_browse *);
    void (*abort)(struct c1xx_il_emitter_browse *);
    void (*pch_name)(char *);
    void (*pch_mark)(void);
    void (*begin_instantiation)(struct c1xx_il_emitter_browse *, int *);
    void (*end_instantiation)(struct c1xx_il_emitter_browse *);
    void (*record_c)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    void (*record_d)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    int (*mark_definition)(struct c1xx_il_emitter_browse *, int, int);
    void (*open)(struct c1xx_il_emitter_browse *);
    char (*reopen)(struct c1xx_il_emitter_browse *);
    void (*region_boundary)(struct c1xx_il_emitter_browse *);
    uint (*entity_id)(struct c1xx_il_emitter_browse *, struct c1_symbol *);
    uint * (*assign_entity_id)(struct c1xx_il_emitter_browse *, uint *, uint);
    void (*discard)(struct c1xx_il_emitter_browse *);
    void (*begin_region)(struct c1xx_il_emitter_browse *);
};

struct c1xx_il_emitter_browse {
    struct c1xx_il_emitter_browse_vtbl *vtbl;
    char *sbr_name;
    int region_offset;
};

typedef struct c1xx_ilmod c1xx_ilmod, *Pc1xx_ilmod;

typedef struct c1xx_ilmod_vtbl c1xx_ilmod_vtbl, *Pc1xx_ilmod_vtbl;

struct c1xx_ilmod_vtbl {
    void *release;
    void *slot04;
    void *get_record;
    void *slot0c;
    void *put_record;
    void *slot14;
    void *slot18;
    void *get_space;
    void *delete_record;
};

struct c1xx_ilmod {
    struct c1xx_ilmod_vtbl *vtbl;
};

typedef struct c1xx_init_level c1xx_init_level, *Pc1xx_init_level;

struct c1xx_init_level {
    struct c1_symbol *sym;
    c1_u32 unk04;
    void *detail;
    struct c1_type *type;
    int count;
    c1_u8 flags;
    c1_u8 string_seen;
    c1_u8 pad16[2];
};

typedef struct c1xx_intrinsic_row c1xx_intrinsic_row, *Pc1xx_intrinsic_row;

struct c1xx_intrinsic_row {
    c1_u16 number;
    c1_u16 pad02;
    c1_u16 return_code;
    c1_u16 return_layer;
    c1_u16 attributes;
    c1_u16 x0a;
};

typedef struct c1xx_label_cell c1xx_label_cell, *Pc1xx_label_cell;

struct c1xx_label_cell {
    struct c1xx_label_cell *next;
    struct c1_node *label;
};

typedef struct c1xx_macro_frame c1xx_macro_frame, *Pc1xx_macro_frame;

struct c1xx_macro_frame {
    c1_u8 *saved_input;
    short *args;
    c1_u8 *text;
    struct fe_macro *macro;
    char arg_count;
    char next_arg;
    c1_u8 pad12[2];
    int active;
};

typedef struct c1xx_misc_string c1xx_misc_string, *Pc1xx_misc_string;

struct c1xx_misc_string {
    c1_u32 id;
    char *text;
};

typedef struct c1xx_namespace_scope c1xx_namespace_scope, *Pc1xx_namespace_scope;

typedef struct c1xx_namespace_scope_vtbl c1xx_namespace_scope_vtbl, *Pc1xx_namespace_scope_vtbl;

struct c1xx_namespace_scope {
    struct c1xx_namespace_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    struct c1_sym_link **buckets;
    c1_u32 mask;
    struct c1_using_cell **using_list;
    struct c1_symbol *ns;
};

struct c1xx_namespace_scope_vtbl {
    int (*has_entries)(struct c1xx_hash_scope *);
    c1_u8 (*has_usings)(void *);
    void (*insert)(struct c1xx_hash_scope *, struct c1_symbol *);
    c1_lookup_result * (*lookup)(struct c1xx_hash_scope *, struct fe_name *, int);
    c1_u8 * (*lookup_tag)(void *, void *);
    c1_lookup_result * (*lookup_by_kind)(struct c1xx_hash_scope *, struct fe_name *, uint, byte *);
    void (*lookup_anonymous_member)(struct c1xx_hash_scope *, void *, struct c1_symbol **);
    int * (*find_link)(void *, int *);
    void (*pch_fixup)(struct c1xx_namespace_scope *);
    void (*emit_il)(struct c1xx_hash_scope *);
    void (*link)(struct c1xx_hash_scope *, struct c1_symbol *);
};

typedef struct c1xx_nheap_object_base c1xx_nheap_object_base, *Pc1xx_nheap_object_base;

typedef struct c1xx_nheap_object_base_vtbl c1xx_nheap_object_base_vtbl, *Pc1xx_nheap_object_base_vtbl;

typedef void *HANDLE;

typedef struct c1xx_pch_image c1xx_pch_image, *Pc1xx_pch_image;

typedef struct c1xx_pch_stream_reader c1xx_pch_stream_reader, *Pc1xx_pch_stream_reader;

typedef struct c1xx_pch_stream_reader_vtbl c1xx_pch_stream_reader_vtbl, *Pc1xx_pch_stream_reader_vtbl;

struct c1xx_nheap_object_base_vtbl {
    void *slot00;
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
    void (*pch_segment_write_base_header)(struct c1xx_nheap_object_base *, HANDLE);
    void *slot1c;
    void *slot20;
    void *slot24;
    void *slot28;
    void *slot2c;
    void *slot30;
    void *slot34;
    void *slot38;
};

struct c1xx_pch_stream_reader_vtbl {
    int (*pch_segment_map_view)(struct c1xx_pch_stream_reader *, void *, char, void *);
    int (*pch_segment_alloc_at_base)(struct c1xx_pch_stream_reader *, void *);
    int (*pch_segment_alloc_anywhere)(struct c1xx_pch_stream_reader *, void *, int);
    void (*pch_segment_release)(struct c1xx_pch_stream_reader *);
    void (*pch_segment_append_to_file)(struct c1xx_pch_stream_reader *, void *);
    void (*pch_segment_write_contents)(struct c1xx_pch_stream_reader *, uint);
    void (*pch_arena_segment_write_header)(struct c1xx_pch_stream_reader *, HANDLE);
    void (*pch_segment_create_reloc_bitmap)(struct c1xx_pch_stream_reader *, int);
    char (*pch_segment_open_reloc_bitmap)(struct c1xx_pch_stream_reader *, struct c1xx_pch_stream_reader *);
    void (*pch_segment_apply_relocations)(struct c1xx_pch_stream_reader *, struct c1xx_pch_image *);
    c1xx_pch_stream_reader * (*pch_segment_self)(struct c1xx_pch_stream_reader *);
    uint (*pch_segment_descriptor_word)(struct c1xx_pch_stream_reader *);
    void * (*pch_segment_base)(struct c1xx_pch_stream_reader *);
    void * (*qualname_resolved_symbol)(struct c1_declarator *);
    uint (*pch_segment_size)(struct c1xx_pch_stream_reader *);
};

struct c1xx_nheap_object_base {
    struct c1xx_nheap_object_base_vtbl *vtbl;
    c1_u32 header_offset;
    int kind;
    int state;
    struct c1xx_pch_image *owner;
};

struct c1xx_pch_stream_reader {
    struct c1xx_pch_stream_reader_vtbl *vtbl;
    c1_u32 header_offset;
    int kind;
    int state;
    struct c1xx_pch_image *owner;
    c1_u32 file_offset;
    c1_u8 *base;
    c1_u32 size;
    c1_u8 *saved_bitmap;
    c1_u32 desc_word;
    c1_u8 *address;
    void *mapping;
    void *file;
    void *view;
    c1_u8 allocated;
    c1_u8 pad39[3];
    struct c1xx_bitvec *bitmap;
    int delta;
    c1_u8 *saved_end;
    c1_u8 *loaded_end;
};

struct c1xx_pch_image {
    int count;
    struct c1xx_pch_stream_reader *bitmap_segment;
    struct c1xx_pch_stream_reader **segments;
    c1_u32 directory_end;
    char *file_name;
    c1_u32 directory_offset;
    void *file;
    void *mapping;
    void *mapping_to_close;
    void *handle24;
    void *handle28;
    void *handle2c;
    void *handle30;
    int next_index;
    struct c1_arena *arena;
    struct c1xx_pch_stream_reader **saved_page_map;
    struct c1xx_pch_stream_reader **loaded_page_map;
};

typedef struct c1xx_obj_104bcbcc c1xx_obj_104bcbcc, *Pc1xx_obj_104bcbcc;

typedef struct c1xx_vtbl_104bcbcc c1xx_vtbl_104bcbcc, *Pc1xx_vtbl_104bcbcc;

struct c1xx_obj_104bcbcc {
    struct c1xx_vtbl_104bcbcc *vtbl;
};

struct c1xx_vtbl_104bcbcc {
    void (*pch_fixup_tree_list_object)(struct c1xx_obj_104bcbcc *);
};

typedef struct c1xx_obj_104c4c3c c1xx_obj_104c4c3c, *Pc1xx_obj_104c4c3c;

typedef struct c1xx_vtbl_104c4c3c c1xx_vtbl_104c4c3c, *Pc1xx_vtbl_104c4c3c;

struct c1xx_vtbl_104c4c3c {
    void (*pch_fixup_list_object)(struct c1xx_obj_104c4c3c *);
};

struct c1xx_obj_104c4c3c {
    struct c1xx_vtbl_104c4c3c *vtbl;
};

typedef struct c1xx_obj_104c4c44 c1xx_obj_104c4c44, *Pc1xx_obj_104c4c44;

typedef struct c1xx_vtbl_104c4c44 c1xx_vtbl_104c4c44, *Pc1xx_vtbl_104c4c44;

struct c1xx_obj_104c4c44 {
    struct c1xx_vtbl_104c4c44 *vtbl;
};

struct c1xx_vtbl_104c4c44 {
    void (*tmpl_instance_members_run)(struct c1_tmpl_work_item *);
    void (*slot04)(struct c1_tmpl_work_item *);
};

typedef struct c1xx_obj_104c58e8 c1xx_obj_104c58e8, *Pc1xx_obj_104c58e8;

typedef struct c1xx_vtbl_104c58e8 c1xx_vtbl_104c58e8, *Pc1xx_vtbl_104c58e8;

struct c1xx_obj_104c58e8 {
    struct c1xx_vtbl_104c58e8 *vtbl;
};

struct c1xx_vtbl_104c58e8 {
    char (*source_tracker_stub_true_0)(void *, int);
    char (*source_tracker_stub_true_1)(void *, int);
    void (*source_tracker_stub_nop_2)(void *);
    void (*source_tracker_stub_nop_3)(void *);
    void (*source_tracker_stub_delete)(struct c1xx_obj_104c58e8 *);
    void (*source_tracker_stub_nop_5)(void *, void *, int);
};

typedef struct c1xx_obj_104ca9b4 c1xx_obj_104ca9b4, *Pc1xx_obj_104ca9b4;

typedef struct c1xx_vtbl_104ca9b4 c1xx_vtbl_104ca9b4, *Pc1xx_vtbl_104ca9b4;

struct c1xx_obj_104ca9b4 {
    struct c1xx_vtbl_104ca9b4 *vtbl;
};

struct c1xx_vtbl_104ca9b4 {
    void (*pch_mark_object_links)(int);
};

typedef struct c1xx_obj_104cb248 c1xx_obj_104cb248, *Pc1xx_obj_104cb248;

typedef struct c1xx_vtbl_104cb248 c1xx_vtbl_104cb248, *Pc1xx_vtbl_104cb248;

struct c1xx_vtbl_104cb248 {
    void (*diag_note_elided_copy_constructor)(struct c1xx_obj_104cb248 *);
};

struct c1xx_obj_104cb248 {
    struct c1xx_vtbl_104cb248 *vtbl;
};

typedef struct c1xx_obj_104cee7c c1xx_obj_104cee7c, *Pc1xx_obj_104cee7c;

typedef struct c1xx_vtbl_104cee7c c1xx_vtbl_104cee7c, *Pc1xx_vtbl_104cee7c;

struct c1xx_obj_104cee7c {
    struct c1xx_vtbl_104cee7c *vtbl;
};

struct c1xx_vtbl_104cee7c {
    void (*tmpl_deferred_report_c2896)(struct c1xx_obj_104cee7c *);
};

typedef struct c1xx_obj_104cee90 c1xx_obj_104cee90, *Pc1xx_obj_104cee90;

typedef struct c1xx_vtbl_104cee90 c1xx_vtbl_104cee90, *Pc1xx_vtbl_104cee90;

struct c1xx_vtbl_104cee90 {
    void (*vtable_nop)(void);
};

struct c1xx_obj_104cee90 {
    struct c1xx_vtbl_104cee90 *vtbl;
};

typedef struct c1xx_obj_104cee94 c1xx_obj_104cee94, *Pc1xx_obj_104cee94;

typedef struct c1xx_vtbl_104cee94 c1xx_vtbl_104cee94, *Pc1xx_vtbl_104cee94;

struct c1xx_obj_104cee94 {
    struct c1xx_vtbl_104cee94 *vtbl;
};

struct c1xx_vtbl_104cee94 {
    void (*tmpl_deferred_report_c2780)(struct c1xx_obj_104cee94 *);
};

typedef struct c1xx_obj_104cee98 c1xx_obj_104cee98, *Pc1xx_obj_104cee98;

typedef struct c1xx_vtbl_104cee98 c1xx_vtbl_104cee98, *Pc1xx_vtbl_104cee98;

struct c1xx_obj_104cee98 {
    struct c1xx_vtbl_104cee98 *vtbl;
};

struct c1xx_vtbl_104cee98 {
    void (*tmpl_deferred_report_c2782)(struct c1xx_obj_104cee98 *);
};

typedef struct c1xx_obj_104cee9c c1xx_obj_104cee9c, *Pc1xx_obj_104cee9c;

typedef struct c1xx_vtbl_104cee9c c1xx_vtbl_104cee9c, *Pc1xx_vtbl_104cee9c;

struct c1xx_vtbl_104cee9c {
    void (*tmpl_deferred_report_c2784)(struct c1xx_obj_104cee9c *);
};

struct c1xx_obj_104cee9c {
    struct c1xx_vtbl_104cee9c *vtbl;
};

typedef struct c1xx_obj_104ceea0 c1xx_obj_104ceea0, *Pc1xx_obj_104ceea0;

typedef struct c1xx_vtbl_104ceea0 c1xx_vtbl_104ceea0, *Pc1xx_vtbl_104ceea0;

struct c1xx_obj_104ceea0 {
    struct c1xx_vtbl_104ceea0 *vtbl;
};

struct c1xx_vtbl_104ceea0 {
    void (*tmpl_deferred_report_c2785)(struct c1xx_obj_104ceea0 *);
};

typedef struct c1xx_obj_104ceea4 c1xx_obj_104ceea4, *Pc1xx_obj_104ceea4;

typedef struct c1xx_vtbl_104ceea4 c1xx_vtbl_104ceea4, *Pc1xx_vtbl_104ceea4;

struct c1xx_obj_104ceea4 {
    struct c1xx_vtbl_104ceea4 *vtbl;
    struct c1_symbol *tmpl;
    struct c1_deferred_action *next;
    struct c1_symbol *specialization;
    struct c1_arg_list *args;
};

struct c1xx_vtbl_104ceea4 {
    void (*tmpl_deferred_report_c2893)(struct c1xx_obj_104ceea4 *);
};

typedef struct c1xx_obj_104ceea8 c1xx_obj_104ceea8, *Pc1xx_obj_104ceea8;

typedef struct c1xx_vtbl_104ceea8 c1xx_vtbl_104ceea8, *Pc1xx_vtbl_104ceea8;

struct c1xx_vtbl_104ceea8 {
    void (*tmpl_deferred_report_c2975)(struct c1xx_obj_104ceea8 *);
};

struct c1xx_obj_104ceea8 {
    struct c1xx_vtbl_104ceea8 *vtbl;
};

typedef struct c1xx_obj_104ceeac c1xx_obj_104ceeac, *Pc1xx_obj_104ceeac;

typedef struct c1xx_vtbl_104ceeac c1xx_vtbl_104ceeac, *Pc1xx_vtbl_104ceeac;

struct c1xx_obj_104ceeac {
    struct c1xx_vtbl_104ceeac *vtbl;
};

struct c1xx_vtbl_104ceeac {
    void (*tmpl_deferred_report_c2783)(struct c1xx_obj_104ceeac *);
};

typedef struct c1xx_obj_104ceec4 c1xx_obj_104ceec4, *Pc1xx_obj_104ceec4;

typedef struct c1xx_vtbl_104ceec4 c1xx_vtbl_104ceec4, *Pc1xx_vtbl_104ceec4;

struct c1xx_obj_104ceec4 {
    struct c1xx_vtbl_104ceec4 *vtbl;
};

struct c1xx_vtbl_104ceec4 {
    void (*tmpl_deferred_report_c2901)(struct c1xx_obj_104ceec4 *);
};

typedef struct c1xx_obj_104cf058 c1xx_obj_104cf058, *Pc1xx_obj_104cf058;

typedef struct c1xx_vtbl_104cf058 c1xx_vtbl_104cf058, *Pc1xx_vtbl_104cf058;

struct c1xx_obj_104cf058 {
    struct c1xx_vtbl_104cf058 *vtbl;
};

struct c1xx_vtbl_104cf058 {
    void *slot00;
    void (*slot04)(struct c1_tmpl_work_item *);
};

typedef struct c1xx_obj_104cf060 c1xx_obj_104cf060, *Pc1xx_obj_104cf060;

typedef struct c1xx_vtbl_104cf060 c1xx_vtbl_104cf060, *Pc1xx_vtbl_104cf060;

struct c1xx_obj_104cf060 {
    struct c1xx_vtbl_104cf060 *vtbl;
};

struct c1xx_vtbl_104cf060 {
    void (*pch_mark_object_links)(int);
};

typedef struct c1xx_ovl_set_iter c1xx_ovl_set_iter, *Pc1xx_ovl_set_iter;

typedef struct c1xx_ovl_set_iter_vtbl c1xx_ovl_set_iter_vtbl, *Pc1xx_ovl_set_iter_vtbl;

struct c1xx_ovl_set_iter {
    struct c1xx_ovl_set_iter_vtbl *vtbl;
    struct c1_sym_link *next;
    struct c1_sym_link *current;
    struct c1_sym_link *start;
};

struct c1xx_ovl_set_iter_vtbl {
    char (*ovl_set_iter_next)(struct c1xx_ovl_set_iter *);
};

typedef struct c1xx_pool c1xx_pool, *Pc1xx_pool;

struct c1xx_pool {
    c1_u8 *cur;
    c1_u32 left;
    c1_u32 min_pages;
    struct c1_arena *arena;
};

typedef struct c1xx_pragma_optimize_letter c1xx_pragma_optimize_letter, *Pc1xx_pragma_optimize_letter;

struct c1xx_pragma_optimize_letter {
    char letter;
    c1_u8 on_value;
    c1_u8 pad02[2];
    c1_u8 *flag;
};

typedef struct c1xx_source_tracker c1xx_source_tracker, *Pc1xx_source_tracker;

typedef struct c1xx_source_tracker_vtbl c1xx_source_tracker_vtbl, *Pc1xx_source_tracker_vtbl;

struct c1xx_source_tracker {
    struct c1xx_source_tracker_vtbl *vtbl;
    struct c1xx_source_tracker_iface iface;
};

struct c1xx_source_tracker_vtbl {
    char (*source_tracker_push)(struct c1xx_source_tracker *, int);
    char (*source_tracker_pop)(struct c1xx_source_tracker *, int);
    void (*source_tracker_accumulate)(struct c1xx_source_tracker *);
    void (*source_tracker_mark)(struct c1xx_source_tracker *);
    void (*source_tracker_delete)(struct c1xx_source_tracker *);
    void (*source_tracker_add_bytes)(struct c1xx_source_tracker *, void *, int);
};

typedef struct c1xx_symbol_cell c1xx_symbol_cell, *Pc1xx_symbol_cell;

struct c1xx_symbol_cell {
    struct c1xx_symbol_cell *next;
    struct c1_symbol *sym;
};

typedef struct c1xx_template_parameter_scope c1xx_template_parameter_scope, *Pc1xx_template_parameter_scope;

typedef struct c1xx_template_parameter_scope_vtbl c1xx_template_parameter_scope_vtbl, *Pc1xx_template_parameter_scope_vtbl;

struct c1xx_template_parameter_scope {
    struct c1xx_template_parameter_scope_vtbl *vtbl;
    struct c1xx_scope *outer;
    c1_u8 kind;
    c1_u8 pad09[3];
    struct c1xx_scope *parent;
    struct c1_using_directive *usings;
    struct c1_sym_list *symbols;
};

struct c1xx_template_parameter_scope_vtbl {
    bool (*has_entries)(struct c1xx_block_scope *);
    byte (*has_usings)(void);
    void (*insert)(void *, struct c1_symbol *);
    c1_u8 * (*lookup)(void *, int, int);
    c1_u8 * (*lookup_tag)(struct c1xx_block_scope *, int);
    c1_u8 * (*lookup_by_kind)(struct c1xx_block_scope *, int, uint, byte *);
    void (*lookup_anonymous_member)(struct c1xx_block_scope *, void *, int *);
    void * (*find_link)(struct c1xx_block_scope *, int);
    void (*pch_fixup)(struct c1xx_hash_scope *);
    void (*emit_il)(struct c1xx_block_scope *);
    void (*link)(struct c1xx_template_parameter_scope *, struct c1_symbol *);
};

typedef struct c1xx_tmpl_function_item c1xx_tmpl_function_item, *Pc1xx_tmpl_function_item;

typedef struct c1xx_tmpl_function_item_vtbl c1xx_tmpl_function_item_vtbl, *Pc1xx_tmpl_function_item_vtbl;

struct c1xx_tmpl_function_item {
    struct c1xx_tmpl_function_item_vtbl *vtbl;
    struct c1_symbol *sym;
    c1_u8 armed;
    c1_u8 pad09[3];
    struct c1_tmpl_work_item *next;
    struct c1_symbol *tmpl;
    struct c1_arg_list *args;
    void *parameter_scope;
    int runs;
    int function_word;
    int position;
};

struct c1xx_tmpl_function_item_vtbl {
    void (*tmpl_function_item_run)(struct c1xx_tmpl_function_item *);
    void (*slot04)(struct c1xx_tmpl_function_item *);
};

typedef struct c1_message msg;

typedef struct c1_node node;

typedef short int16_t;

typedef int int32_t;

typedef longlong int64_t;

typedef char int8_t;

typedef ushort uint16_t;

typedef uint uint32_t;

typedef ulonglong uint64_t;

typedef uchar uint8_t;

typedef struct fe_arena fe_arena, *Pfe_arena;

typedef struct fe_arena_desc fe_arena_desc, *Pfe_arena_desc;

struct fe_arena_desc {
    uint id;
    uint reserve_size;
    uint granule;
    uchar flags;
    uchar pad0d[3];
    uint pch_word;
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

typedef struct fe_message fe_message, *Pfe_message;

typedef union fe_message_arg fe_message_arg, *Pfe_message_arg;

union fe_message_arg {
    void *sym;
    void *type;
    char *text;
    uint value;
    char ch;
    uint half[2];
    struct fe_name *name;
};

struct fe_diag_cell {
    struct fe_message *msg;
    struct fe_diag_cell *next;
};

struct fe_message {
    ushort base;
    ushort id;
    char *text;
    union fe_message_arg args[8];
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

typedef struct fe_function_record fe_function_record, *Pfe_function_record;

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

typedef struct fe_function_record_block fe_function_record_block, *Pfe_function_record_block;

struct fe_function_record_block {
    struct fe_function_record_block *next;
    struct fe_function_record records[20];
};

typedef struct fe_idb_browse_entry fe_idb_browse_entry, *Pfe_idb_browse_entry;

struct fe_idb_browse_entry {
    ushort old_first_line;
    ushort old_last_line;
    ushort first_line;
    ushort last_line;
    int sbr_offset;
};

typedef struct fe_idb_browse_table fe_idb_browse_table, *Pfe_idb_browse_table;

struct fe_idb_browse_table {
    struct fe_idb_browse_entry *data;
    uint count;
    uint capacity;
};

typedef struct fe_idb_class_record fe_idb_class_record, *Pfe_idb_class_record;

struct fe_idb_class_record {
    uint class_ni;
    uint first_region;
    uint unk08;
    uint depth;
    uint change;
};

typedef struct fe_idb_include_stack fe_idb_include_stack, *Pfe_idb_include_stack;

typedef struct fe_idb_include_state fe_idb_include_state, *Pfe_idb_include_state;

typedef struct fe_idb_region_array fe_idb_region_array, *Pfe_idb_region_array;

typedef struct fe_idb_region fe_idb_region, *Pfe_idb_region;

typedef struct MREFile MREFile, *PMREFile;

typedef struct MREFile_vtbl MREFile_vtbl, *PMREFile_vtbl;

typedef struct MREBag MREBag, *PMREBag;

typedef ulong NI;

typedef struct MREBag_vtbl MREBag_vtbl, *PMREBag_vtbl;

struct MREFile {
    struct MREFile_vtbl *vtbl;
};

struct fe_idb_region_array {
    struct fe_idb_region *data;
    uint count;
    uint capacity;
};

struct fe_idb_include_stack {
    struct fe_idb_include_state *data;
    uint count;
    uint capacity;
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

struct MREBag {
    struct MREBag_vtbl *vtbl;
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

struct MREBag_vtbl {
    void *FAddDep;
    int (*FClose)(struct MREBag *);
};

typedef struct fe_il_buffer fe_il_buffer, *Pfe_il_buffer;

typedef struct Buffer Buffer, *PBuffer;

typedef struct Stream Stream, *PStream;

typedef uchar *PB;

typedef long CB;

typedef struct Stream_vtbl Stream_vtbl, *PStream_vtbl;

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

struct Stream {
    struct Stream_vtbl *vtbl;
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

typedef struct fe_line_map fe_line_map, *Pfe_line_map;

typedef struct fe_line_map_row fe_line_map_row, *Pfe_line_map_row;

struct fe_line_map {
    struct fe_line_map_row *rows;
    uint count;
    uint capacity;
};

struct fe_line_map_row {
    int position;
    int line;
    struct fe_file_record *file;
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

typedef struct fe_pdb_blob_entry fe_pdb_blob_entry, *Pfe_pdb_blob_entry;

struct fe_pdb_blob_entry {
    struct fe_pdb_blob_entry *next;
    char *name;
    uint size;
    void *data;
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

typedef struct fe_pdb_blob_table fe_pdb_blob_table, *Pfe_pdb_blob_table;

struct fe_pdb_blob_table {
    struct Stream *stream;
    uchar dirty;
    uchar pad05[3];
    struct fe_pdb_blob_entry *entries;
    int count;
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

typedef ulong AGE;

typedef struct Array_DWORD Array_DWORD, *PArray_DWORD;

struct Array_DWORD {
    ulong *rgt;
    uint itMac;
    uint itMax;
};

typedef enum DBGTYPE {
    dbgtypeFPO=0,
    dbgtypeException=1,
    dbgtypeFixup=2,
    dbgtypeOmapToSrc=3,
    dbgtypeOmapFromSrc=4,
    dbgtypeSectionHdr=5
} DBGTYPE;

typedef struct DBI DBI, *PDBI;

typedef struct DBI_vtbl DBI_vtbl, *PDBI_vtbl;

typedef ulong IMPV;

typedef ulong INTV;

typedef struct Mod Mod, *PMod;

typedef struct GSI GSI, *PGSI;

typedef struct SO SO, *PSO;

typedef struct Enum Enum, *PEnum;

typedef uchar ITSM;

typedef struct TPI TPI, *PTPI;

typedef ulong TI;

typedef long EC;

typedef struct Dbg Dbg, *PDbg;

typedef struct PDB PDB, *PPDB;

typedef struct LinkInfo LinkInfo, *PLinkInfo;

typedef struct Mod_vtbl Mod_vtbl, *PMod_vtbl;

typedef struct GSI_vtbl GSI_vtbl, *PGSI_vtbl;

typedef struct EnumThunk EnumThunk, *PEnumThunk;

typedef struct Enum_vtbl Enum_vtbl, *PEnum_vtbl;

typedef struct TPI_vtbl TPI_vtbl, *PTPI_vtbl;

typedef ushort TI16;

typedef struct Dbg_vtbl Dbg_vtbl, *PDbg_vtbl;

typedef struct PDB_vtbl PDB_vtbl, *PPDB_vtbl;

typedef ulong SIG;

typedef int (*PFNfReadPDBRawBytes)(void *, long);

typedef int (*PfnFindDebugInfoFile)(void *);

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

struct Dbg {
    struct Dbg_vtbl *vtbl;
};

struct DBI {
    struct DBI_vtbl *vtbl;
};

struct TPI {
    struct TPI_vtbl *vtbl;
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

struct GSI {
    struct GSI_vtbl *vtbl;
};

struct SO {
    long off;
    ushort isect;
    ushort pad;
};

struct EnumThunk {
    struct EnumThunk_vtbl *vtbl;
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

struct LinkInfo {
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

typedef struct ISet ISet, *PISet;

struct ISet {
    struct Array_DWORD rgw;
};

typedef struct MRECmp MRECmp, *PMRECmp;

typedef struct MRECmp_vtbl MRECmp_vtbl, *PMRECmp_vtbl;

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

struct MRECmp {
    struct MRECmp_vtbl *vtbl;
};

typedef struct MREDrv MREDrv, *PMREDrv;

typedef struct MREDrv_vtbl MREDrv_vtbl, *PMREDrv_vtbl;

struct MREDrv {
    struct MREDrv_vtbl *vtbl;
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

typedef struct MREUtil MREUtil, *PMREUtil;

typedef struct MREUtil_vtbl MREUtil_vtbl, *PMREUtil_vtbl;

struct MREUtil {
    struct MREUtil_vtbl *vtbl;
};

struct MREUtil_vtbl {
    int (*FRelease)(struct MREUtil *);
    void *slot04;
    void *slot08;
    void *slot0c;
    void *slot10;
    void *slot14;
};

typedef struct MREngine MREngine, *PMREngine;

typedef struct MREngine_vtbl MREngine_vtbl, *PMREngine_vtbl;

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

struct MREngine {
    struct MREngine_vtbl *vtbl;
};

typedef struct Map_DWORD_DWORD Map_DWORD_DWORD, *PMap_DWORD_DWORD;

struct Map_DWORD_DWORD {
    struct Array_DWORD rgd;
    struct Array_DWORD rgr;
    struct ISet isetPresent;
    struct ISet isetDeleted;
    uint cdr;
};

typedef struct MreToPdb MreToPdb, *PMreToPdb;

typedef struct NameMap NameMap, *PNameMap;

typedef struct NameMap_vtbl NameMap_vtbl, *PNameMap_vtbl;

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

struct NameMap {
    struct NameMap_vtbl *vtbl;
};

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


c1_symbol * __cdecl class_current_definition(void);
char __fastcall class_name_is_current_class(c1_declarator * d);
void __cdecl class_check_unnamed_class_member(c1xx_decl_specifiers * spec);
uint __fastcall class_member_iter_matches(c1_member_iter * iter);
c1_symbol * __thiscall class_lookup_member_set(c1_scope_stack * scope, c1_symbol * cls, void * name, uint flags, int error_number);
c1_symbol * __thiscall class_lookup_member_set_tail(c1_keyed_list * paths, c1_symbol * cls, void * name, char ambiguous, c1_keyed_list * result, uint flags, int err);
c1_keyed_list * __cdecl class_lookup_member_name(c1_symbol * cls, void * name, uint flags);
int __thiscall class_member_table_find(void * table, uint name);
c1_symbol * __thiscall class_find_member_function(c1_symbol * cls, void * name);
void __cdecl access_check_member(c1_symbol * sym);
c1_keyed_list * __cdecl class_member_lookup_record(c1_keyed_list * path, c1_member_lookup_ctx * ctx);
int __cdecl class_first_constructor(int cls);
c1_symbol * __thiscall class_lookup_qualified_member(c1_scope_stack * scope, c1_symbol * cls, c1_symbol * base, uint flags);
void __cdecl class_conversion_functions_begin(c1_conversion_type_iter * iter, c1_symbol * cls);
char __cdecl class_lookup_is_new_result(byte * sym, c1_vector * found);
char __cdecl access_check_member_path(c1_symbol * sym);
void __cdecl access_clear_report_context(void);
void __cdecl access_record_inaccessible_member(char access, c1_symbol * member, c1_symbol * cls);
char __cdecl access_get_special_member_context(void);
void * __cdecl class_friend_table_lookup(void * key);
int __cdecl access_is_friend(c1_symbol * sym, c1_symbol * cls);
int __cdecl access_is_friend_template_match(int * friend_entry, c1_symbol * tmpl, c1_symbol * sym_class, c1_symbol * func);
char __cdecl access_compose(byte path, byte member);
int __cdecl class_vtable_vptr_offset(c1_vtable_record * rec);
void __fastcall default_argument_parse_finish(c1_deferred_parse * rec);
void __cdecl class_note_vtable_built(c1_symbol * sym);
void __cdecl class_find_special_members(c1_symbol * cls);
void __cdecl class_walk_members_matching(c1_symbol * cls, void * name);
void __cdecl class_mark_used_and_count_vbases(c1_symbol * cls, c1_symbol * unused);
void __cdecl class_init_table_pointers(int cls, int kind, char mode);
void __cdecl class_init_virtual_base_members(c1_symbol * sym, char init_adjustor);
void __cdecl access_set_special_member_context(char on);
void __cdecl class_dtor_prologue(c1_symbol * cls);
c1_keyed_list * __cdecl class_lookup_member_name_thunk(c1_symbol * cls, void * name, uint flags);
char __cdecl class_build_destructor_call_of_kind(c1_symbol * cls, c1_node * object, int kind, char flag, int do_delete);
c1_symbol * __cdecl class_find_conversion_function(c1_type * type, c1_symbol * cls);
void __cdecl class_redeclare_member_with_access(int decl, int cls);
char __cdecl class_check_override_return_type(c1_sym_link * fn, c1_sym_link * base_fn, c1_symbol * cls, char report);
void __cdecl class_declare_deleting_destructors(c1_symbol * cls, c1_symbol * dtor);
void __cdecl class_collect_conversion_types(c1_symbol * cls);
short * __cdecl class_share_base_conversion_type_set(short * set, c1_symbol * cls);
void __cdecl class_map_vector_to_scalar_deleting_dtor(c1_symbol * vdd, c1_symbol * sdd);
void __cdecl class_declare_local_vftable_ctor_closure(c1_symbol * cls, c1_symbol * ctor);
void __cdecl class_add_friend(c1_symbol * cls, c1xx_decl_specifiers * spec, c1_symbol * friend_sym);
void __cdecl class_friend_table_add(void * rec);
void __cdecl class_declare_default_ctor_closure(c1_symbol * cls, c1_symbol * ctor);
void __cdecl class_member_init_by_copy(int * member, c1_node * value);
void __cdecl class_build_vector_helper_tokens(void);
char __cdecl class_define_pending_special_members(void);
void __cdecl class_queue_special_member_definition(byte * key, c1_symbol * sym);
void __cdecl class_synthesize_special_member_tokens(c1_symbol * key, c1_symbol * sym);
void __cdecl class_build_scalar_deleting_dtor_body(c1_symbol * cls);
void __cdecl class_build_destroy_and_delete(c1_symbol * cls);
byte __fastcall class_type_needs_destructor_call(c1_type * type);
int __cdecl class_complete_for_use(c1_symbol * cls);
byte __cdecl class_has_special_member_kind(c1_symbol * cls, byte kind);
int __cdecl class_best_inheritance_model(c1_symbol * cls);
uint __cdecl class_is_single_inheritance(int cls);
void __cdecl class_layout_bitfield_member(c1_symbol * sym, c1_u16 type_code, c1_u8 append);
void __cdecl class_close_bit_field_unit(void);
void __thiscall class_member_iter_init(c1_member_iter * iter, void * cls_entry, int filter);
int __fastcall class_member_iter_step(c1_list_cursor * cursor);
char __fastcall class_member_iter_next(c1_member_iter * iter);
c1xx_class_scope * __thiscall class_scope_new(c1_scope_stack * stack, int arena, c1_u8 kind, c1_symbol * tag);
c1_u8 * __thiscall class_scope_lookup_by_kind(c1xx_class_scope * class_scope, int * name, uint flags, char * found);
c1_u8 * __cdecl class_record_new_kind5(void);
c1_u8 * __cdecl class_special_member_parameters(int key, int kind, c1_symbol * sym);
int __cdecl class_is_innermost_being_defined(int cls);
c1_u8 * __cdecl class_scan_head_tokens(ushort key_code, c1_u8 * spec);
byte __thiscall class_head_take_name(void * head, c1_u8 * token);
c1_symbol * __cdecl class_check_tag_redefinition(void * name, undefined4 kind, undefined4 * insert_fn);
void __cdecl class_check_member_pointer_representation(c1_symbol * sym);
c1_symbol * __cdecl class_check_tag_kind_consistency(c1_symbol * sym, c1_u16 tag_code);
void __cdecl class_check_uuid_redefinition(c1_symbol * sym, c1_u8 * spec);
c1_symbol * __cdecl class_begin_definition(c1_symbol * cls, c1_type * type);
void __stdcall class_end_member_list(void);
void __cdecl class_layout_direct_bases(c1_symbol * cls);
void __cdecl class_note_pragma_vtordisp_off(void);
void __cdecl class_finish_layout_flags(c1_symbol * cls);
void * __cdecl class_current_definition_name(void);
char __thiscall class_begin_member_list(c1_declarator * d, c1xx_decl_specifiers * spec, c1_symbol * * out);
c1_symbol * __cdecl class_current_member_lookup(void * name);
undefined4 __cdecl class_check_zero_sized_array_member(c1_symbol * sym);
uint __thiscall class_member_natural_alignment(c1_type * type, uint pack);
void __cdecl class_warn_packing_sensitive_alignment(uint alignment);
uint __cdecl class_member_padding(uint alignment);
uint __cdecl class_padding_for_offset(uint alignment, uint offset);
uint __cdecl class_member_offset_add(uint offset, uint delta);
void __cdecl class_append_member(c1_symbol * sym);
c1_type * __stdcall class_end_definition(void);
void __cdecl class_layout_vptrs(c1_symbol * cls);
void __cdecl class_reset_vtable_records(c1_symbol * cls);
void __cdecl class_add_vptr_members(c1_symbol * cls);
void __cdecl class_end_member_layout(c1_symbol * cls);
void __cdecl class_declare_implicit_special_members(c1_symbol * cls);
void __cdecl class_merge_base_special_member_states(c1_symbol * cls, c1_u8 * states);
void __cdecl class_merge_member_special_member_states(c1_symbol * cls, c1_u8 * states);
int __cdecl class_member_is_const_or_reference(c1_symbol * member);
void __cdecl class_warn_multiple_special_members(c1_symbol * cls, c1_u8 * states, int * ctor_count, int * assign_count);
void __cdecl class_declare_implicit_member_by_state(c1_symbol * cls, c1_u8 * states, int kind, int warning, char allowed);
c1_symbol * __cdecl class_declare_implicit_member(c1_symbol * cls, int kind, char need, char flag);
void * __cdecl class_special_member_name(int kind);
void __fastcall class_declare_special_member(c1_declarator * d);
void __cdecl class_check_copy_constructor_signature(c1_symbol * sym);
char __cdecl class_overrides_base_virtual(c1_sym_link * fn, c1_symbol * cls, char report);
void __cdecl class_complete_layout_and_tables(c1_symbol * cls);
void __cdecl class_complete_layout(c1_symbol * cls);
void __cdecl class_reset_previous_vbase(void);
void __cdecl class_merge_direct_base_records(c1_symbol * cls);
void __cdecl class_set_size(c1_symbol * cls);
void __cdecl class_assign_vbase_table_slots(c1_symbol * cls);
void __cdecl class_assign_vftable_slots(c1_symbol * cls);
void __cdecl class_member_assign_vftable_slot(c1_sym_link * fn, c1_symbol * cls);
void __cdecl class_check_ambiguous_inherited_member(int sym2);
void __cdecl class_disambiguate_vtable_names(c1_symbol * cls);
void __cdecl class_copy_layout_records_to_arena0(c1_symbol * cls);
char __cdecl class_vtables_have_pure_virtual(c1_symbol * cls);
void __cdecl class_declare_vtable_symbols(c1_symbol * cls);
void __cdecl class_declare_constructor_closures(c1_symbol * cls);
void __cdecl class_declare_deleting_destructors_if_dtor(c1_symbol * cls);
void __cdecl class_sort_members(c1_symbol * cls);
int __cdecl class_compare_members_by_name(c1_sym_link * * a, c1_sym_link * * b);
void __stdcall class_begin_deferred_member_bodies(void);
void __cdecl class_reset_member_function_class(void);
int __cdecl class_check_subobject_special_members(c1_symbol * cls, c1_symbol * sub, c1_u8 * rows);
c1_u8 * __thiscall class_lookup_qualified_name(void * scope, void * name);
c1_u8 * __thiscall class_parse_head(void * head, c1_u8 * token, undefined4 edx);
void __cdecl class_apply_tag_declspecs(c1_symbol * cls, c1_u8 * spec);
c1_u8 * __cdecl param_list_new_copy_parameter(c1_symbol * tag, c1_u16 cv);
int * __thiscall class_scope_find_link(c1xx_class_scope * class_scope, int * entry);
void __cdecl class_mark_copy_assignment_operator(c1_symbol * fn);
void __thiscall class_scope_insert(c1xx_class_scope * class_scope, c1_symbol * sym2);
void __cdecl class_append_alignment_member(int size);
c1_u8 * __thiscall class_scope_lookup(c1xx_class_scope * class_scope, int name, int kind);
c1_u8 * __thiscall class_scope_lookup_tag(c1xx_class_scope * class_scope, void * name);
c1_symbol * __cdecl class_check_base_defined(int access, int is_virtual, fe_name * name, int unused);
c1_symbol * __cdecl class_check_base_class(int access, char is_virtual, c1_symbol * sym);
c1_u8 __cdecl class_check_duplicate_base(char is_virtual, c1_symbol * base, c1_symbol * cls);
int __cdecl class_base_overlap_kind(char is_virtual, c1_symbol * base, c1_symbol * cls, char direct, c1_symbol * * through_base);
c1_symbol * __cdecl class_append_base_entry(int access, c1_u8 is_virtual, c1_symbol * base);
int __cdecl class_layout_nonvirtual_base(c1_symbol * base, c1_symbol * * prev_base, c1_symbol * cls);
void __cdecl class_note_base_table_pointers(c1_symbol * cls, c1_symbol * base_entry, char * has_virtual_base);
void __cdecl class_share_base_table_pointers(c1_symbol * cls, c1_symbol * base, int base_offset, int unused);
void __cdecl class_inherit_base_tables(c1_symbol * base_entry, c1_symbol * cls);
void __cdecl class_merge_base_vbases(c1_vbase_vector * vbases, c1_vbase_vector * base_vbases, c1_symbol * cls, c1_symbol * base_entry);
void __cdecl class_set_current_access(c1_u8 access);
int __cdecl class_subobject_special_member_usable(c1_symbol * cls, c1_symbol * sub, c1_u8 * rows, int kind);
c1_vtable_record * __cdecl class_vtable_record_copy(c1_vtable_record * src, int unused);
void __cdecl class_vtable_record_set_path(c1_vtable_record * rec, c1_symbol * base_entry, c1_vtable_record * outer);
void __cdecl class_vtable_record_rebase(c1_vtable_record * rec, c1_symbol * base_entry, int offset);
void __stdcall class_vtable_record_rebase_return(void);
void __cdecl class_vtable_slot_path_through_base(int * path, c1_symbol * base_entry);
void __cdecl class_vtable_slot_path_add_offset(int * path, int offset);
void __cdecl class_override_vtable_slots(int * fn_link, c1_vtable_record * rec, c1_symbol * cls, c1_u8 needs_vtordisp);
void __cdecl class_vtable_slot_path_set(int * path, int offset);
c1_vtable_record * __cdecl class_vtable_record_move_to_arena0(c1_vtable_record * src);
void __cdecl class_vtable_record_free_slots(c1_vtable_record * rec);
c1_symbol * __cdecl class_declare_vtable_symbol(int table_kind, c1_vtable_record * rec, c1_symbol * cls);
void __thiscall class_vtable_declarator_set_decorated_name(c1_declarator * d, c1_symbol * cls);
void __cdecl class_vtable_record_append_slot(c1_vtable_record * rec, c1_vtable_slot * slot);
int __cdecl class_vtable_record_reserve_bytes(c1_vtable_record * rec, int size);
c1_vtable_record * __cdecl class_first_vftable_record(c1_symbol * cls);
void __cdecl class_vtable_slot_init(c1_vtable_slot * slot, int * fn_link);
void __cdecl class_vtable_record_grow_slots(c1_vtable_record * rec, int extra);
void __cdecl class_default_args_on_tokens_end(void);
void __cdecl class_default_args_begin_next_member(void);
c1_deferred_parse * __thiscall class_default_args_parse_init(c1_deferred_parse * rec, c1_symbol * fn, c1_deferred_parse * prev);
char __fastcall class_default_args_push_next(c1_deferred_parse * rec);
c1_symbol * __cdecl class_declare_table_pointer_member(c1_symbol * cls, int kind);
void __cdecl class_prepend_member(c1_symbol * sym);
void __cdecl class_shift_member_offsets(c1_symbol * cls, int delta, c1_u32 from_offset);
c1_vtable_record * __cdecl class_vtable_record_new(int kind, c1_symbol * cls, int vptr_offset, c1_symbol * vptr_member);
uint __cdecl class_vtable_entry_iterator_next(int * iter);
c1_vbase_record * __cdecl class_find_base_record(c1_symbol * base, c1_vbase_vector * vbases);
int __fastcall class_debug_type_in_pdb(c1_symbol * cls);
void * __cdecl class_scalar_deleting_dtor_of(c1_symbol * vdd);
byte * __thiscall class_find_member_function_walk_overloads(c1_symbol * cls, void * name, void * pred);
byte * __cdecl class_find_vector_deleting_dtor(c1_type * type);
byte * __cdecl class_find_member_function_matching(c1_type * type, int name, void * predicate);
int __cdecl class_vbtable_entry_offset(int * path, c1_symbol * cls, c1_vtable_record * rec);
int __cdecl class_vbase_offset(int vbase, int cls);
int __cdecl class_complete_type_of(c1_type * mptype);
byte * __cdecl class_find_complete_destructor(c1_type * type);
byte * __cdecl class_find_default_constructor(c1_type * type);
int __cdecl class_member_may_be_declared(c1_symbol * tag);
void __thiscall class_conversion_iter_init(c1_member_iter * iter, c1_symbol * cls);
c1_type * __fastcall class_conversion_iter_result_type(c1_member_iter * iter);
void __thiscall class_declare_friend_function(c1_declarator * d, c1_u8 * spec, c1_symbol * cls);
char __cdecl class_check_union_member(c1_symbol * union_sym, c1_symbol * member);
void __cdecl class_check_anonymous_union(byte * specs);
void __cdecl class_add_anonymous_member(c1_type * type);
c1_symbol * __cdecl class_new_tag_record(void * name, c1_u16 type_code);
byte __fastcall class_head_compose_qualified_name(void * head, c1_u8 * unused_edx);
byte __thiscall class_head_take_qualified_name(void * head, c1_u8 * token);
void __thiscall class_check_dll_interface_member(c1_declarator * d, int specs);
int * __cdecl base_path_skip_base_entries(int * cell);
char __cdecl class_base_access(int base, c1_symbol * cls);
char __cdecl class_base_access_from_members(int base, c1_symbol * cls);
char __cdecl class_base_access_from_members_tail(char best);
int __cdecl class_nonvirtual_bases_end(c1_symbol * cls);
c1_vtable_record * __cdecl class_new_vbtable_record(c1_symbol * cls, c1_symbol * vbptr_member);
void __cdecl class_vbtable_slot_init(c1_vtable_slot * slot, c1_symbol * cls, c1_symbol * vbase);
c1_vbase_record * __cdecl class_new_vbase_record(c1_symbol * base_entry, c1_symbol * cls, int arena);
c1_vtable_record * __cdecl class_vtable_record_copy_for_vbase(c1_vtable_record * src);
void __cdecl class_vtable_vector_link_copies(c1_vtable_vector * copies, c1_vtable_vector * originals, c1_symbol * base_entry);
void __cdecl class_add_vbase_record(c1_vbase_vector * vbases, c1_vbase_record * rec, c1_symbol * cls, c1_symbol * base_entry);
char __cdecl class_vbase_needs_vtordisp(c1_symbol * cls, c1_symbol * vbase);
char __cdecl class_bases_have_vtordisp_for_vbase(c1_symbol * cls, c1_symbol * vbase);
char __cdecl class_has_virtual_other_than_dtor(c1_symbol * cls);
char __cdecl class_vbase_needs_empty_gap(c1_symbol * vbase, c1_symbol * cls);
void __cdecl class_vbase_record_rebase(c1_vbase_record * rec, c1_symbol * base_entry, int offset);
void __cdecl class_vtable_slot_path_set_vbase(int * path, c1_symbol * vbase);
char __cdecl class_vbase_find_vbtable_slot(c1_vbase_record * vbase_rec, c1_symbol * cls);
c1_vtable_record * __cdecl class_first_vbtable_record(c1_symbol * cls);
void __cdecl class_vbase_add_vbtable_slot(c1_vbase_record * vbase_rec, c1_symbol * cls);
c1_vbase_record * __cdecl class_vbase_record_move_to_arena(c1_vbase_record * src, int arena);
void __cdecl class_virtual_base_info(c1_symbol * base, c1_symbol * cls, int * vbptr_offset, int * vbase_index, c1_type * * base_type);
c1_u8 __cdecl class_vbase_get_info(c1_symbol * base, c1_symbol * cls, int * vbptr_offset, int * vbase_index, c1_type * * base_type);
char __cdecl class_has_direct_base(c1_symbol * cls, c1_symbol * base);
byte __cdecl class_has_direct_base_stop(void);
c1_vbase_record * __cdecl class_vbase_record_inherit(c1_vbase_record * src, c1_symbol * base_entry, int arena);
c1_vbase_record * __cdecl class_vbase_record_copy(c1_vbase_record * src, int arena);
c1_vtable_vector * __cdecl class_vtable_vector_copy(c1_vtable_vector * src, int arena);
int __cdecl class_vtable_slot_byte_offset(c1_vtable_slot * slot, c1_vtable_record * rec);
void __cdecl class_vbase_merge_vftable_slots(c1_symbol * cls, c1_vbase_record * existing, c1_vbase_record * rec);
void __cdecl class_vtable_slot_merge(c1_vtable_slot * slot, c1_vtable_slot * other);
char __cdecl class_is_same_or_derived(c1_symbol * cls, c1_symbol * base);
void __cdecl class_vbase_record_free_slot_arrays(c1_vbase_record * rec);
void __cdecl class_vtable_slot_take_first_candidate(c1_vtable_slot * slot);
void __cdecl class_build_vbase_loop(c1_symbol * sym, int * mem_initializers);
void __cdecl class_mark_member_list_used_all(c1_symbol * sym);
void __cdecl class_build_vbase_dtor_body(c1_symbol * cls);
void __cdecl class_build_vbase_destructor_calls(c1_symbol * cls, c1_node * object);
c1_u8 * __stdcall class_check_local_class_extern(void * ret_addr, c1_u8 token_code, c1_decl_spec_scan * state);
void __thiscall class_head_insert_in_enclosing_scope(void * holder, c1_symbol * sym);
c1_symbol * __fastcall class_check_access_redeclaration(int class_depth, uint sym_flags2, c1_symbol * sym);
c1_symbol * __stdcall class_check_tag_kind_consistency_return_null(void);
uint __cdecl class_check_member_array_size(c1_type * t);
void __stdcall class_check_ctor_dtor_this_qualifiers(c1_declarator * d);
void __stdcall class_check_pure_on_unnamed(c1_declarator * d);
void __stdcall class_check_union_virtual(c1_declarator * d);
void __cdecl class_check_base_of_symbol(int p1, int p2, c1_symbol * sym, int p4);
c1_symbol * __cdecl class_add_dependent_base_entry(int access, c1_u8 is_virtual, c1_symbol * base);
c1_symbol * __cdecl class_warn_dll_interface_base(c1_symbol * base, int access, char is_virtual);
char __cdecl class_is_pure_interface(c1_symbol * cls);
void __cdecl class_for_each_member(int key, void * fn, int arg);
void __cdecl class_warn_access_declaration(c1_symbol * cls, c1_overload_set * qualified_name);
c1_u8 __cdecl access_member_through_path(c1_keyed_cell * cell);
c1_symbol * __fastcall class_member_iter_base_class(c1_member_iter * iter);
char * __cdecl access_specifier_name(char access);
char * __cdecl access_entity_kind_text(byte * sym);
void __cdecl access_record_inaccessible_via_base(c1_symbol * member, c1_symbol * cls, char inherit_access, char access, c1_symbol * base);
int __cdecl access_is_friend_fragment(c1_symbol * friend_sym, int * friend_entry, c1_symbol * tmpl, int result, c1_symbol * sym_class, c1_symbol * func);
void __cdecl class_synth_append_base_init(c1_symbol * base, int * count);
c1_u8 __cdecl class_synth_each_base_init(c1_symbol * member, int * count);
int __cdecl class_synth_copy_ctor_member_init_tokens(c1_symbol * member, int * count);
void __cdecl class_synth_append_base_assign(c1_symbol * base);
c1_u8 __cdecl class_synth_each_base_assign(c1_symbol * member);
char __cdecl class_synth_assign_member_tokens(c1_symbol * member);
void __cdecl class_synth_assign_array_member_tokens(c1_symbol * member);
byte __cdecl class_type_needs_destructor_call_none(void);
c1_symbol * __thiscall class_check_static_member_definition(c1_symbol * sym, byte storage_class, byte mask_8, c1_declarator * d, byte * spec);
void __thiscall class_scope_lookup_anonymous_member(c1xx_class_scope * class_scope, void * name, int * found);
char __cdecl mre_class_name_index(c1_symbol * cls);
char __thiscall mre_mark_class_untracked(c1_mre_tracker * tracker, c1_symbol * cls);
int __thiscall mre_note_class_type_index(c1_mre_tracker * tracker, c1_symbol * cls);
c1_node * __cdecl class_check_operator_global_form(uint op, c1_node * node2);
void __cdecl mre_note_member_lookup_in_bases(c1_symbol * cls, void * name);
c1_keyed_list * __cdecl class_collect_base_paths(c1_symbol * cls, c1_symbol * base);
int * __cdecl class_find_base_paths(void * path, int * state);
c1_u8 __cdecl access_least_member_through_path(c1_symbol * entity, c1_keyed_cell * cell, c1_u8 * least);
void __stdcall class_warn_dominance(undefined4 edi);
void __cdecl class_check_abstract_instantiation(c1_symbol * cls);
char __cdecl class_ctor_and_dtor_are_implicit(c1_symbol * cls);
char __cdecl class_not_ending_in_zero_sized_array(c1_symbol * cls);
char __cdecl class_overrides_vbase_virtual(c1_symbol * cls, c1_symbol * vbase);
void __cdecl class_init_virtual_base_members_fragment(c1_symbol * cls, c1_vbase_record * base_record, c1_vbase_vector * bases, short index, char init_adjustor);
c1_node * __cdecl class_build_base_adjustor(c1_symbol * cls, c1_vbase_record * vbase);
c1_keyed_cell * __cdecl class_vtordisp_access_path(c1_symbol * cls, c1_vbase_record * vbase);
c1_node * __cdecl class_build_vptr_stores(c1_node * src, c1_symbol * sym);
void __cdecl class_vbptr_layout(int cls, int * vbptr_offset, int * first);
int __cdecl class_vbptr_offset(c1_symbol * cls);
c1_node * __cdecl class_layout_vtable_this(void);
c1_node * __cdecl class_build_vbtable_pointer_test(c1_node * this_ptr);
c1_u8 __cdecl class_is_polymorphic(c1_symbol * cls);
c1_keyed_cell * __cdecl class_first_vfptr_path(c1_symbol * cls);
void __cdecl class_set_member_pointer_representation(char model);
void __cdecl class_set_member_pointer_inheritance(int model);
void __cdecl pm_vi_member_offset_adjust(c1_symbol * cls, int node, int value, int value2, int * offset_out, int * index_out);
c1_node * __cdecl class_path_vbase_index_map_ref(c1_keyed_cell * path, int reverse);
c1_symbol * __cdecl class_vbase_map_declare_vdispmap(c1_vbase_map_key * key);
void * __cdecl class_vbase_map_decorated_name(c1_symbol * sym, c1_vbase_map_key * key);
c1_vbase_map_key * __cdecl class_vbase_map_key_new(c1_symbol * cls_a, c1_symbol * cls_b, c1_u8 reverse, int arena);
c1_vbase_map_key * __cdecl class_vbase_map_key_copy(c1_vbase_map_key * key, int arena);
void __cdecl class_build_vbase_index_map(c1_vbase_map_key * entry, c1_symbol * table);
c1_keyed_cell * __cdecl class_path_first_reindexing_step(c1_keyed_cell * cell);
c1_keyed_cell * __cdecl class_path_outermost_reindexing_parent(c1_keyed_cell * cell);
byte __cdecl class_path_step_same_vbase_indices(c1_keyed_cell * cell);
byte __cdecl class_vbase_indices_match(c1_symbol * cls, c1_symbol * other);
void __cdecl class_declare_copy_ctor_closure_fragment(c1_symbol * copy_ctor, c1_symbol * cls);
void __cdecl class_build_default_ctor_closure_body(c1_symbol * cls);
void __cdecl class_build_local_vftable_ctor_closure_body(c1_symbol * cls);
c1_symtab * __cdecl class_ensure_copy_ctor_closure_table(void);
void __cdecl class_declare_copy_ctor_closure(c1_symbol * cls, c1_symbol * copy_ctor);
c1_symbol * __cdecl class_copy_ctor_closure_of(c1_symbol * copy_ctor);
void __cdecl class_build_copy_ctor_closure_body(c1_symbol * cls);
void __cdecl class_declare_placement_delete_closure(c1_symbol * op_delete);
void __cdecl class_build_placement_delete_closure_body(c1_symbol * closure);
void __cdecl class_build_vector_deleting_dtor_body(c1_symbol * cls);

void __thiscall block_scope_link(c1xx_block_scope * block_scope, c1_symbol * sym);
ulonglong __fastcall _aullshr(byte count, uint hi, uint lo);
int __cdecl counted_array_size(short count);
longlong __fastcall _allshl(byte count, uint lo, uint hi);
longlong __stdcall _allmul(uint a_lo, int a_hi, uint b_lo, int b_hi);
longlong __fastcall _allshr(byte count, int hi, uint lo);
ushort __cdecl counted_array_count(ushort * array);
ulonglong __stdcall _aulldiv(uint lo, uint hi, uint dlo, uint dhi);
void __thiscall default_argument_store_and_advance(c1_deferred_parse * rec, c1_node * expr);
c1_symbol * __cdecl param_list_add_compiler_formal_front_or_back(int at_tail, c1_sym_list * * list, void * name, c1_type * type);
void * __cdecl dtor_kind_name(int kind);
void __cdecl special_member_need_definition(c1_symbol * fn);
void __thiscall param_list_add_compiler_formal(void * list, void * name, c1_type * type);
void __thiscall deferred_body_list_add(c1_deferred_body_list * * list_slot, c1_symbol * fn);
int __cdecl fclose_if_open(FILE * file);
void __cdecl emit_version_string_literal(void);
int __cdecl member_is_copied_data(c1_symbol * member);
void * __cdecl segment_lookup_or_declare(void * name, void * seg_class, char cls);
longlong __stdcall _alldiv(uint lo, int hi, uint dlo, int dhi);
void __cdecl buffer_chain_append_bytes(void * src, int count, int size, c1_byte_block_list * chain);
void __cdecl block_list_rewind(int * list);
wchar_t * __cdecl multibyte_to_wide_arena(char * text);
char * __cdecl int64_to_string(int * value, char * buf, int radix, int is_unsigned);
ulonglong __stdcall _aullrem(uint lo, uint hi, uint dlo, uint dhi);
int * __thiscall dlist_insert_before(void * this, int * iter, int * pos, int * value);
void __cdecl block_list_open_or_rewind(c1_byte_block_list * * slot);
void __cdecl _chkstk(uint size);
int __thiscall iset_contains(c1xx_pdb_iset * set, uint bit);
int __thiscall iset_add(c1xx_pdb_iset * set, uint bit);
char __thiscall mre_note_member_use(c1_mre_tracker * tracker, c1_symbol * cls, void * member_name);
char __thiscall mre_note_class_layout_use(c1_mre_tracker * tracker, c1_symbol * cls);
char __thiscall mre_note_class_use(c1_mre_tracker * tracker, c1_symbol * cls);
c1_u8 * __cdecl base_path_text_for_diag(int * path, int with_kinds);
longlong __stdcall _allrem(uint lo, int hi, uint dlo, int dhi);

int __cdecl vtable_true(void);
byte * __cdecl browse_ring_pop_front(void);
void __cdecl browse_add_record(uint kind, int * sym);
void __cdecl browse_ring_push(byte kind, int * sym);
void __cdecl browse_record_fill(c1xx_browse_record * rec, int * sym);
byte * __cdecl browse_ring_front(void);
byte * __cdecl browse_ring_second(void);
c1xx_browse_record * __cdecl browse_ring_from_back(int n);
void __cdecl browse_record_type(c1xx_browse_record * rec);
void __cdecl browse_record_write(c1xx_browse_record * rec);
void __cdecl browse_record_write_return(void);
void __cdecl browse_record_fill_definition(c1xx_browse_record * rec, c1_symbol * sym);
void __cdecl browse_record_assign_entity_id(void * pos, c1_symbol * sym);
void __cdecl browse_record_fill_reference(byte * rec, byte * sym);
void __cdecl browse_record_fill_kind12(c1xx_browse_record * rec, fe_macro * macro);
void __cdecl browse_record_fill_member_reference(byte * rec, c1_symbol * sym);
void __cdecl browse_record_set_access(ushort * attrs, char access);
byte * __cdecl browse_ring_pop_back(void);
char * __cdecl decorate_name(c1_symbol * sym, c1_symbol * sym2);
char * __cdecl decorate_name_body(char * out, c1_symbol * sym, c1_symbol * sym2);
uint __cdecl decorate_symbol_codes(c1_symbol * sym);
byte * __cdecl decorate_name_operator_or_name(byte * out, c1_symbol * sym, uint codes);
char * __cdecl decorate_scope_chain(char * out, byte * sym);
char * __cdecl decorate_name_with_backreference(char * out, int name, int first_char_flag);
byte * __cdecl decorate_storage_code(byte * out, c1_symbol * sym, c1_symbol * sym2, uint codes);
byte * __cdecl decorate_storage_code_function_tail(byte * out, c1_symbol * sym);
char * __cdecl decorate_type_into(char * out, c1_type * type, int innermost);
char * __cdecl decorate_function_symbol_type(char * out, c1_symbol * sym);
char * __cdecl decorate_calling_convention(char * out, int type);
char * __cdecl decorate_argument_list(char * out, c1_type * type);
char * __cdecl decorate_put_Z(char * out);
char * __cdecl decorate_return_type(char * out, c1_type * type, int mode);
byte * __cdecl decorate_pointer_target(char * out, c1_type * type, int mode);
byte * __cdecl decorate_pointer_code(byte * out, c1_type * type);
byte * __cdecl decorate_pointer_code_unsigned_letter(byte letter, c1_type * type, byte * out);
byte * __cdecl decorate_pointer_code_case10_fragment(c1_type * type, byte * out);
char * __cdecl decorate_type_by_kind(char * out, c1_type * type);
char * __cdecl decorate_type_code(char * out, c1_type * type);
char * __cdecl decorate_array_type(char * out, c1_type * type);
char * __cdecl decorate_scope_prefix(char * out, c1_symbol * sym);
char * __cdecl decorate_type_full(char * out, c1_type * type);
char * __cdecl decorate_put_4(char * out);
char * __cdecl decorate_number(char * out, uint n);
void __cdecl browse_define_symbol_as_defined(c1_symbol * sym);
void __fastcall esumem_ice(c1_declarator * d);
void __cdecl esumem_register_copy(c1_symbol * member, c1_symbol * copy);
char * __cdecl decorate_name_2(c1_symbol * tmpl, int * args);
char * __cdecl decorate_backreference(char * out, int arg);
char * __cdecl decorate_type_code_2(char * out, c1_type * type);
int __cdecl debug_type_record_arglist(int fn_info);
int __cdecl debug_cv_calling_convention(ushort type_flags);
int __cdecl debug_type_record_procedure_leaf(c1_type * type, uint return_index);
int __cdecl debug_type_record_array(c1_type * type, uint element_index);
uint __cdecl debug_type_pad_to_4(char * out, char length);
c1_u32 __cdecl debug_type_index(c1_type * type);
int __cdecl vtable_false(void);
uint __thiscall idb_stub_function_begin(c1xx_idb_stub * stub, uint a, uint b, int c, uint * out_status, int * d, ushort * e, uint * out_zero);
uint __thiscall idb_stub_function_end(c1xx_idb_stub * stub, uint a, uint b, uint c, uint * out_status, uint * out_zero);
int __cdecl debug_type_record_class_forward(c1_symbol * sym);
int __cdecl debug_emit_class_type(c1_symbol * sym);
c1_u32 __cdecl debug_type_index_derived(c1_type * type);
uint __cdecl debug_cv_primitive_pointer_index(c1_type * type);
int __cdecl cvserver_emit_type(ushort length);
ushort __cdecl debug_cv_unsigned_numeric_leaf(ushort * out, uint lo, int hi);
int __cdecl debug_type_record_pointer(c1_type * type, uint target_index);
c1_u32 __cdecl debug_type_index_compute(c1_type * type);
uint __cdecl debug_cv_primitive_type_index(ushort code);
void __stdcall vtable_nop_arg1(int a);
int __cdecl debug_identifier_length(byte * out, char * name);
byte * __cdecl debug_put_length_prefixed_name(byte * out, char * name);
short __cdecl debug_identifier_length_of_type(byte * out, c1_symbol * sym);
c1_u32 __cdecl debug_type_record_modifier(c1_type * type);
char * __cdecl decorate_function_type_prefix(char * out, c1_type * type);
char * __cdecl decorate_function_type_prefix_none(char * out);
char * __cdecl debug_type_name_text(char * out, c1_type * type);
void __cdecl browse_flush_queue(void);
int __stdcall vtable_true_arg2(int a, int b);
int __stdcall vtable_true_arg1(int a);
char __fastcall pdb_source_file_pop(c1_mre_tracker * tracker);
char __thiscall pdb_source_file_push(c1_mre_tracker * tracker, char * name, int fd, byte tracked);
void __cdecl browse_record_finish_kind13(c1xx_browse_record * rec, fe_macro * macro);
byte * __cdecl browse_ring_find_definition(int sym);
c1_symbol * __cdecl esu_check_tag_and_begin_enum(c1_symbol * sym, uint tag_code);
uint __thiscall idb_stub_clear_third_out(c1xx_idb_stub * stub, uint a, uint b, uint * out_zero);
int __cdecl browse_end_global_block(void);
void __cdecl browse_record_finish_base_class(c1xx_browse_record * rec, c1_symbol * entry);
char * __cdecl decorate_vftable_for_list(char * out, c1_symbol * sym);
void * __cdecl vftable_base_path_list(int rec);
int __cdecl debug_type_record_class_full(c1_symbol * sym);
int __cdecl debug_emit_types_twice(c1_symbol * cls, int * count, ushort * property);
int __cdecl debug_type_record_class_fieldlist(int pass, c1_symbol * cls, int * count, ushort * property);
int __cdecl debug_is_vbase_or_scalar_deleting_dtor(c1_symbol * sym);
uint __cdecl debug_field_method(int pass, byte * set, ushort * out, int * count, ushort * property);
uint __cdecl debug_field_member(int pass, byte * member, ushort * out);
ushort __cdecl pdb_numeric_leaf(ushort * out, uint lo, int hi);
char * __cdecl decorate_array_dims(char * out, c1_type * type);
int __cdecl debug_type_record_enum(c1_symbol * sym);
int __cdecl debug_type_record_enum_fieldlist(int * sym);
int __cdecl debug_type_record_mfunction(c1_type * type, uint this_adjust);
uint __cdecl debug_method_field_attributes(int method, ushort * attr, uint * vtable_offset);
int __cdecl debug_identifier_length_2(byte * out, c1_symbol * member, char qualified);
char * __cdecl debug_symbol_name(c1_symbol * sym, char qualified);
ushort __cdecl debug_field_bclass(int pass, int base, c1_symbol * sym, ushort * out);
ushort __cdecl debug_member_field_attributes(c1_symbol * member);
int __cdecl debug_type_record_vtshape(c1_symbol * cls);
void __cdecl vtable_entry_iterator_init(c1_vtable_slot_iter * it, c1_vtable_record * table);
int __cdecl debug_type_record_methodlist(byte * set);
c1xx_ovl_set_iter * __thiscall debug_method_iterator_init(c1xx_ovl_set_iter * iter, int * set_entry);
int __cdecl debug_methodlist_entry(int method, int record, uint offset);
uint __cdecl debug_field_vfunctab(int pass, int member, int sym, ushort * out);
char * __cdecl decorate_template_constant_argument(char * out, c1_node * node);
uint __cdecl debug_field_nesttype(int pass, c1_symbol * member, ushort * out);
uint __cdecl debug_field_stmember(int pass, c1_symbol * member, ushort * out);
void * __fastcall pch_arena_writer_clear(void * obj);
void __cdecl pch_set_name(char * name);
int __stdcall vtable_set_out_true(int * out);
void __cdecl debug_type_emit_if_needed(c1_type * type);
int __cdecl debug_type_record_bitfield(c1_symbol * member);
char * __cdecl decorate_string_literal_name(int * literal, char wide);
char * __cdecl decorate_string_literal_name_body(char * out, byte * bytes, uint length, char wide);
uint __stdcall crc16_update(byte * data, int length, uint crc);
byte * __cdecl decorate_string_literal_char(byte * out, byte c);
char * __cdecl decorate_scope_prefix_2(char * out, c1_symbol * sym);
void __cdecl pch_hdrstop(void);
void __cdecl pch_check_after_options(void);
int __fastcall idb_stub_release(c1xx_idb_stub * idb_stub);
char __thiscall pdb_gi_end_unit(c1_mre_tracker * tracker, char commit);
void __thiscall pdb_session_close_gi(c1_pdb_session * session, char commit);
void __fastcall debug_finish(void);
void __fastcall pdb_session_close_types(int * session);
void __fastcall pdb_close(c1_pdb_session * session);
void __cdecl pch_finish_files(void);
void __fastcall pch_image_close(c1xx_pch_image * image);
void __fastcall pch_segment_release(c1xx_pch_stream_reader * pch_stream_reader);
void __cdecl pdb_open(void);
int __cdecl pdb_open_file(c1xx_pdb * pdb, int arg2, c1_pdb_namemap * name_map, char * source_file, char * object_file, void * tracker, int incremental, int arg8, int arg9, c1xx_idb * * out);
uint __thiscall idb_stub_check_options(c1xx_idb_stub * stub, int a, uint * out_status);
char __thiscall pdb_open_for_minimal_rebuild(c1_mre_tracker * tracker, char * source_file);
uint __fastcall pdb_source_file_register_name(c1_source_file_record * rec);
void __cdecl debug_begin(char no_header);
void __cdecl pch_use(char * header_name, char read_pch);
void __cdecl pch_open(void);
char __cdecl pch_check_options(char quiet);
void __cdecl pch_read(void);
void __cdecl pch_reload_il_streams(char with_db);
byte __cdecl pch_reload_arenas(char * file_name, uint offset);
void __thiscall pch_image_index_read(c1xx_pch_image * image, char * file_name, uint offset);
c1xx_pch_stream_reader * __cdecl pch_image_read_segment(void * file, c1xx_pch_image * image);
c1xx_pch_stream_reader * __thiscall pch_stream_reader_new(c1xx_pch_stream_reader * reader, void * file, int kind, c1xx_pch_image * owner);
byte __fastcall pch_image_map_segments(c1xx_pch_image * image);
byte __cdecl os_is_windows_nt(void);
void * __thiscall pch_image_create_mapping(c1xx_pch_image * image, uint protect, uint * handle);
int __thiscall pch_segment_map_view(c1xx_pch_stream_reader * pch_stream_reader, void * mapping, char keep, void * file);
void __cdecl pch_rebind_include_stack_files(void);
void __fastcall browse_resume_after_pch_read(c1xx_il_emitter * il_emitter);
void __cdecl debug_begin_file(char * name);
void __cdecl pch_check_defines(void);
char __fastcall pdb_gi_restore_pch_blob(void * tracker);
byte * __cdecl decorate_put_A(byte * out);
char * __cdecl decorate_name_3(char * out, char * buffer, c1_type * type, char dot_prefix);
char * __cdecl decorate_signed_number(char * out, int value);
ushort __cdecl debug_field_vbclass(int pass, int base, int vbase, c1_symbol * cls, ushort * out);
ushort __cdecl debug_field_vbclass_body(int pass, ushort * out, c1_symbol * base, c1_type * type);
int __cdecl decorate_cv_text(int buf, ushort quals);
ushort __cdecl debug_field_ivbclass(int pass, int base, c1_symbol * cls, ushort * out);
ushort __cdecl debug_ivbclass_attributes(int base, c1_symbol * cls);
char __fastcall pdb_blob_stream_flush(c1_pdb_blob_table * table);
void __fastcall pch_image_write_directory(c1xx_pch_image * image);
void __thiscall pch_arena_segment_write_header(c1xx_pch_stream_reader * obj, HANDLE file);
void __thiscall pch_segment_write_base_header(c1xx_nheap_object_base * obj, HANDLE file);
byte __fastcall pdb_stream_table_close(void * table);
void __fastcall pdb_blob_stream_destroy(int * table);
ushort __cdecl debug_cv_signed_numeric_leaf(ushort * out, uint lo, uint hi);
int __cdecl pch_creation_point(void);
void __cdecl pch_write(void);
int __cdecl pdb_gi_read_blob_for_pch(void);
void __thiscall pdb_record_pch_contribution(void * this, char * file, int value);
char __fastcall pdb_open_pch_contrib_stream(c1_pdb_session * session);
char __cdecl pdb_blob_stream_open(c1xx_pdb * pdb, char * name, c1_pdb_blob_table * * out);
c1_pdb_blob_table * __fastcall pdb_blob_stream_init(c1_pdb_blob_table * table);
char __fastcall pdb_blob_stream_load(c1_pdb_blob_table * table);
char __thiscall named_blob_list_store(c1_pdb_blob_table * table, char * name, c1_u8 * data, uint size);
void __cdecl pch_write_file(void);
void __cdecl pch_save_il(void);
void __cdecl pch_write_finish(void);
bool __cdecl browse_seek_to_saved_offset(void);
void __cdecl pch_rle_begin(int * counter);
byte __fastcall pdb_commit_session(c1_pdb_session * session);
int __cdecl pch_rle_write_bytes(byte * bytes, long n);
void __stdcall pch_rle_flush_run(void);
int __cdecl builtin_operator_candidate_count(void);
int __cdecl pch_write_blocks(int * list, FILE * f, int dst);
void __cdecl pch_write_arenas(char * file_name, int offset);
void __thiscall pch_image_init(c1xx_pch_image * image, int count);
void __thiscall pch_arena_record_append(void * this, c1_arena * a);
c1xx_pch_stream_reader * __thiscall pch_arena_segment_ctor(c1xx_pch_stream_reader * segment, c1_arena * a, c1xx_pch_image * owner);
void __thiscall pch_heap_write_parts(c1xx_pch_image * image, char * name, int offset);
void __thiscall pch_segment_append_to_file(c1xx_pch_stream_reader * pch_stream_reader, void * file);
void __thiscall pch_segment_write_bytes(void * pch_stream_reader, void * file);
byte __thiscall pdb_open_validated(c1_pdb_session * session, char * pdb_name, c1_u32 * signature, c1_u32 * age, long page_size, char * mode);
char __thiscall pdbmgr_open(c1_pdb_session * session, char * pdb_name, c1xx_pdb * * out, char delete_and_retry, long page_size, char * mode);
void __cdecl pdb_make_idb_name(char * out);
char __thiscall pdb_open_minimal_rebuild_engine(c1_pdb_session * session, c1_pdb_session * types_session);
char __fastcall pdb_open_type_info(c1_pdb_session * session);
char __cdecl pch_auto_check_usable(char * header_name);
void __cdecl pch_record_environment(void);
void __fastcall pch_relocate_slot(uint slot);
void __fastcall pch_relocate_token_chunks(void * stream);
void __cdecl pch_relocate_line_map(void);
void __cdecl pch_fixup_line_map(void);
void __thiscall line_map_set_cached_row(c1_line_map_state * map, void * file);
void __fastcall line_map_clear_cached_row(c1_line_map_state * map);
void __fastcall pch_relocate_token(c1_u8 * token);
void __cdecl pch_relocate_list_1444(void);
void __cdecl pch_relocate_pack_stack(void);
char * __cdecl pch_default_name(char * path);
int __cdecl debug_emit_symbol_type_2(c1_symbol * sym);
__noreturn noreturn void __cdecl debug_field_list_overflow_tail(void);
int __cdecl debug_tag_reference_record(short * rec, c1_symbol * based_var);
void __cdecl debug_pad_record(int length, c1_u16 * record);
char __fastcall debug_member_iter_next(c1xx_debug_method_iter * iter);
c1_arg_item * __thiscall pch_fixup_list_object_ctor(c1_arg_item * item, c1_type * type, c1_u8 given_explicitly);
void __cdecl pch_check_include_with_Yc(void);
void __cdecl browse_record_set_kind14(byte * rec);
void __cdecl browse_record_finish_kind11(byte * rec);
void __cdecl browse_next_region_id(void);
void __fastcall browse_emit_records(c1xx_il_emitter_browse * browse);
void __cdecl pch_relocate_scope_vector(void);
void __cdecl pch_fixup_friend_chain(int node);
void __cdecl pch_relocate_symtab_15d4(void);
byte __cdecl block_list_equals_bytes(c1_byte_block_list * list, char * bytes, uint n);
char * __cdecl pdb_relative_path(char * file);
uint __cdecl decorate_symbol_codes_member_tail(byte name_code, byte bits35, byte flags1, c1_symbol * sym, void * local_static_dtor_name);
byte * __cdecl decorate_storage_code_dollar_a_fragment(byte * out, uint codes, uint code, uint code7f, c1_symbol * sym);
byte * __cdecl decorate_based_code(byte * out, byte flags, c1_symbol * base_sym);
byte * __cdecl decorate_type_text(byte * out, c1_type * type);
byte * __cdecl decorate_string_literal_char_case9_fragment(byte * out);
char * __cdecl decorate_special_name(byte * sym, char kind);
char * __cdecl decorate_rtti_locator_name(c1_symbol * vftable_sym);
void * __cdecl decorate_rtti_base_class_descriptor_name(byte * cls, int mdisp, int pdisp, int vdisp, uint attributes);
char * __cdecl decorate_function_string_literal(void);
void * __cdecl decorate_name_RTTI0(c1_type * type);
char * __cdecl decorate_name_swapped(int scope, c1_symbol * sym);
void __cdecl pch_relocate_symtab_15dc(void);
void * __cdecl debug_segment_symbol_name(c1_symbol * sym);
void __cdecl pch_relocate_symtab_16c8(void);
void __cdecl pch_relocate_symtab_14ac(void);
void __cdecl pch_relocate_symtab_15d8(void);
void __cdecl pch_fixup_pair_record(int rec);
void __cdecl pch_relocate_segment_table(void);
void __cdecl pch_relocate_symtab_1b50(void);
void __cdecl pch_relocate_symtab_1b58(void);
void __cdecl pch_relocate_attribute_tables(void);
void __cdecl pch_relocate_symtab_15c8(void);
void __cdecl pch_relocate_redeclaration_value(uint * slot);
uint __cdecl pdb_namemap_symbol_name(c1_symbol * sym);
void __cdecl pch_relocate_function_records(void);
int __cdecl decorate_based_text(uchar flags, int base);
void __cdecl pdb_open_idb(uint incremental_flag, int options_result);
int __cdecl pch_record_entry(int kind, int key, char * text);
int __cdecl pch_record_macro_definition(byte * name, byte * body, short key);
int __cdecl pch_record_or_replay_if_value(int value);
void __cdecl pch_directive_reopen_source(void);
int __cdecl pch_record_or_match_directive(void);
int __cdecl pch_record_include(byte * file);
void __cdecl pch_auto_start_recording(void);
int __cdecl pch_auto_match_end(void);
int __cdecl pch_read_options(void);
void __cdecl pch_auto_begin(void);
void __cdecl pch_extract_file_rle(char * file, int n);
void __cdecl pch_close_and_delete(char pch_read_open, char pch_write_open, char pch_is_ex_file);
uint __cdecl pch_check_recorded_entry(uint kind, uint key, char * text, char current_only);
char * __cdecl pch_stream_name(char * out, char * file, char * ext);
void __cdecl pch_declare_marker_variable(void);
void __cdecl pch_emit_pchsym_include_directive(void);
void __cdecl pch_relocate_misc_globals(void);
void __cdecl pch_relocate_global_tables(void);
void __cdecl pch_relocate_current_scope(void);
void __cdecl pch_relocate_warning_state(void);
void __fastcall pch_relocate_tagged_list(uint * link);
void __cdecl pch_relocate_value_nop(void * value);
void __cdecl pch_relocate_hook_empty(void);
void __fastcall pch_relocate_warning_state_chain(int state);
void __fastcall pch_relocate_list_1b6c(int node);
void __cdecl pch_relocate_list_15bc(void);
void __cdecl pch_relocate_symbol_free_lists(void);
void __cdecl pch_relocate_global_1b70(void);
void __fastcall pch_fixup_scope_common(c1xx_hash_scope * scope);
void __fastcall pch_fixup_hash_scope(c1xx_hash_scope * scope);
void __fastcall pch_fixup_block_scope(c1xx_hash_scope * scope);
void __fastcall pch_fixup_namespace_scope(c1xx_namespace_scope * hash_scope);
void __fastcall pch_relocate_member_list_head(int * head_slot);
void __fastcall pch_relocate_template_header(int rec);
void __fastcall pch_relocate_token_record_list(int node);
void __cdecl pch_relocate_symbol_chain(byte * sym);
void __cdecl pch_relocate_symbol(byte * sym);
void __cdecl pch_relocate_class_layout(int sym);
void __cdecl pch_relocate_class_slot_24(int sym);
void __cdecl pch_relocate_type_hash(void);
void __cdecl pch_relocate_type_chain(void * entry);
void __cdecl pch_relocate_type_descriptor(ushort * type);
void __cdecl pch_relocate_hash_142c_16cc(void);
void __cdecl pch_relocate_hash_142c_chain(void * entry);
void __cdecl pch_relocate_token_records(void);
void __cdecl pch_relocate_pragma_comment_list(void);
void __cdecl pch_relocate_vector_helper_tokens(void);
void __cdecl pch_relocate_hash_142c_record(int record);
void __cdecl pch_relocate_tree_list(void * * list);
void __cdecl pch_relocate_tree_list_list(void * * list);
void __cdecl pch_relocate_hash_16cc_chain(void * entry);
void __cdecl pch_relocate_counted_slot_array(int * array);
void __cdecl pch_relocate_tree(c1_node * node);
void __cdecl pch_relocate_pair(void * p);
void __cdecl pch_relocate_name_hash(void);
void __cdecl pch_relocate_name_chain(void * entry);
void __cdecl pch_relocate_pointer_array(uint slots, int count);
void __cdecl pch_mark_vector_slots(c1_vector * vec, void * callback);
void __cdecl pch_fixup_counted_pointer_array(short * arr, void * callback);
void __cdecl pch_relocate_symtab_entries(c1_symtab * tab, void * key_fn, void * value_fn);
void __cdecl pch_fixup_symtab_chain(void * entry, void * key_fn, void * value_fn, char fix_key, char fix_value);
void __cdecl pch_relocate_dynamic_initializer_vector(void);
void __cdecl pch_relocate_vector_1448(void);
void __cdecl pch_relocate_vector_144c(void);
void __cdecl pch_fixup_global_roots(void);
void __fastcall pch_fixup_pair_list(uint node);
void __fastcall pch_fixup_scope_record_chain(int rec);
void __fastcall pch_relocate_symbol_list(int entry);
void __fastcall pch_relocate_symbol_list_simple(int entry);
void __fastcall pch_relocate_class_member_list(int entry);
void __fastcall pch_relocate_symbol_list_c(int entry);
void __fastcall pch_relocate_class_scope_list(int cell);
void __fastcall pch_relocate_record_chain(int record);
void __thiscall pch_read_into_buffer(c1_il_buffer * buf, void * f, int n);
char * __cdecl pch_and_pdb_names(void);
void __cdecl pch_finish_il(void);
void __cdecl pch_begin_write(void);
void __cdecl pch_reload_il(char with_db);
int __thiscall array16_save(c1_idb_region_array * array, c1_byte_buffer * buf);
int __thiscall idb_region_array_reload(c1_idb_region_array * regions, c1_u32 * * cursor);
char * __thiscall idb_header_file_name(void * include_state, void * name_map);
c1xx_idb * __thiscall idb_construct(c1xx_idb * idb, c1xx_pdb * pdb, c1xx_pdb * pdb_backup, c1_pdb_namemap * name_map, c1xx_source_tracker_iface * source_tracker, int incremental, int backup_on_write, int read_from_backup);
int __thiscall pdb_open_module_stream(void * idb, int unused, char * object_file);
int __fastcall idb_commit(c1xx_idb * idb);
int __fastcall idb_write_dependencies(c1xx_idb * idb);
int __fastcall idb_write_regions(c1xx_idb * idb);
int __thiscall idb_read_dependencies(c1xx_idb * idb, int * stream, int * complete_out);
int __thiscall idb_read_regions(c1xx_idb * idb, int * stream);
uint __thiscall idb_save_header_regions(c1xx_idb * idb, c1_idb_include_state * include_state);
uint __thiscall idb_load_header_regions(c1xx_idb * idb, c1_idb_include_state * include_state);
char * __thiscall idb_header_stream_name(void * idb, void * include_state, char * buf, uint size);
uint __fastcall idb_release(c1xx_idb * idb);
int __thiscall idb_begin_unit(c1xx_idb * idb, int * state_out);
int __thiscall idb_begin_unit_no_check(c1xx_idb * idb, int * state_out);
int __fastcall idb_begin_source_file(c1xx_idb * idb);
int __fastcall idb_check_file_times(c1xx_idb * idb);
uint __thiscall idb_check_next_region(c1xx_idb * idb, int check, int unused);
int __thiscall gi_region_record_begin(c1xx_idb * idb, byte kind);
uint __thiscall idb_function_begin(c1xx_idb * idb, uint class_ni, uint line, int macro_depth, int * state_out, int * length_out, short * line_count_out, int * matched_out);
uint __thiscall idb_function_end(c1xx_idb * idb, uint class_ni, uint line, int macro_depth, int * state_out, int * changed_out);
void __fastcall idb_note_macro_change(c1xx_idb * idb);
int __thiscall idb_note_pragma(c1xx_idb * idb, int pragma_kind);
int __thiscall idb_note_pragma_output(c1xx_idb * idb, int pragma_kind);
int __fastcall idb_conditional_enter(c1xx_idb * idb);
int __fastcall idb_conditional_leave(c1xx_idb * idb);
int __thiscall idb_include_enter(c1xx_idb * idb, char * file, byte untracked);
int __thiscall idb_include_leave(c1xx_idb * idb, uint line);
int __thiscall idb_class_begin(c1xx_idb * idb, uint line, int class_ni);
int __thiscall idb_class_end(c1xx_idb * idb, uint line, int class_ni, uint * changed_out);
int __thiscall idb_function_body_begin(c1xx_idb * idb, uint line, int macro_depth);
uint __thiscall idb_function_body_end(c1xx_idb * idb, uint line, int macro_depth, int * changed_out);
int __thiscall idb_function_region_in_header(c1xx_idb * idb, uint class_ni, uint line, int macro_depth);
uint __thiscall idb_function_region_end(c1xx_idb * idb, int class_ni, uint line, int macro_depth, int * changed_out);
int __thiscall idb_tracker_note(c1xx_idb * idb, int class_ni, char * member_name);
int __thiscall idb_scope_kind3_to_4(c1xx_idb * idb, uint line, int macro_depth);
int __thiscall idb_scope_kind4_end(c1xx_idb * idb, uint line, int macro_depth);
int __thiscall idb_set_tracker(c1xx_idb * idb, c1_mre_file * tracker);
int __thiscall idb_close_region_changed(c1xx_idb * idb, uint line);
int __thiscall idb_close_region(c1xx_idb * idb, uint line, int consume_following);
uint __thiscall idb_region_close(c1xx_idb * idb, uint line, int consume_following, int * changed, int * layout_changed);
int __fastcall idb_note_layout_dependency(c1xx_idb * idb);
int __fastcall idb_note_pragma_begin(c1xx_idb * idb);
int __thiscall idb_scope_kind3_to_2(c1xx_idb * idb, uint line, int macro_depth);
int __thiscall idb_scope_kind2_to_3(c1xx_idb * idb, uint line, int macro_depth);
void __fastcall idb_note_access_declaration(c1xx_idb * idb);
void __fastcall idb_note_decl_specifier(c1xx_idb * idb);
void __fastcall idb_note_sizeof(c1xx_idb * idb);
int __fastcall idb_note_warning(c1xx_idb * idb);
int __fastcall idb_note_error(c1xx_idb * idb);
int __fastcall idb_note_global_il_record(c1xx_idb * idb);
int __fastcall idb_note_line_dependency(c1xx_idb * idb);
int __fastcall idb_note_predefined_macro(c1xx_idb * idb);
int __thiscall idb_check_options(c1xx_idb * idb, int options_signature, int * result_out);
int __thiscall idb_set_pdb_signature(c1xx_idb * idb, int signature, uint age);
uint __thiscall idb_pch_written(c1xx_idb * idb, int * state_out);
uint __thiscall idb_pch_read(c1xx_idb * idb, int * state_out);
int __fastcall idb_note_dependency_64(c1xx_idb * idb);
int __fastcall idb_note_special_members(c1xx_idb * idb);
int __fastcall idb_note_first_use(c1xx_idb * idb);
int __thiscall idb_add_name(c1xx_idb * idb, char * name);
int __thiscall idb_has_name(c1xx_idb * idb, char * name);
int __thiscall idb_browse_set_lines(c1xx_idb * idb, short first_line, short last_line);
int __thiscall idb_browse_set_region(c1xx_idb * idb, int first_line, int last_line, int sbr_offset);
int __fastcall idb_browse_region_count(c1xx_idb * idb);
int __thiscall idb_browse_region(c1xx_idb * idb, uint index, c1_idb_browse_entry * * entry_out);
int __fastcall idb_browse_truncate(c1xx_idb * idb);
int __fastcall idb_browse_table_reset(c1xx_idb * idb);
int __fastcall idb_invalidate(c1xx_idb * idb);
int __fastcall idb_in_function(c1xx_idb * idb);
void __fastcall idb_note_helper_call(c1xx_idb * idb);
int __fastcall idb_helper_called(c1xx_idb * idb);
int __thiscall idb_stub_true_3(c1xx_idb_stub * stub, int first_line, int last_line, int sbr_offset);
int __stdcall idb_stub_region_none(int region, int * out);
void __thiscall gi_region_entry_init(c1_idb_region * region, byte kind);
void __thiscall idb_browse_set_size(c1xx_idb * idb, int size);
int __fastcall idb_browse_size(c1xx_idb * idb);
void __fastcall idb_force_recompile(c1xx_idb * idb);
void __fastcall idb_disable_incremental(c1xx_idb * idb);
int __thiscall iset_remove(c1xx_pdb_array * set, uint n);
int __thiscall iset_ensure_room(c1xx_pdb_array * set, uint n);
c1_idb_region * __thiscall gi_region_entry_set(c1_idb_region * region, byte kind, int signature, int length, short start_line, byte no_reuse);
c1_idb_include_state * __thiscall idb_include_state_assign(c1_idb_include_state * state, c1_idb_include_state * src);
c1_idb_include_state * __thiscall idb_include_state_init(c1_idb_include_state * state, byte untracked);
c1xx_pdb_array * __thiscall array_init_count(c1xx_pdb_array * array, uint count);
void __thiscall dword_array_fill(c1xx_pdb_array * array, c1_u32 * value);
c1_idb_region_array * __thiscall region_array_assign(c1_idb_region_array * regions, c1_idb_region_array * src);
c1xx_pdb_map * __thiscall map_init(c1xx_pdb_map * map, uint size);
void * __thiscall pdb_ipm_elem48_vector_deleting_dtor(c1_idb_include_state * states, byte flags);
int __thiscall array_set_size(c1xx_pdb_array * array, uint count);
int __thiscall array_save(c1xx_pdb_array * array, c1_byte_buffer * buf);
int __thiscall array_reload(c1xx_pdb_array * array, c1_u32 * * cursor);
int __thiscall region_array_set_size(c1_idb_region_array * regions, uint count);
int __thiscall idb_include_stack_set_size(c1_idb_include_stack * stack, uint count);
int __thiscall map_save(c1xx_pdb_map * map, c1_byte_buffer * buf);
int __thiscall array12_set_size(c1xx_pdb_array * array, uint n);
int __thiscall map_arrays_set_size(c1xx_pdb_map * map, uint size);
int __fastcall map_grow_2(c1xx_pdb_map * map);
void __fastcall map_destroy(c1xx_pdb_map * map);
int __thiscall pdb_map_find(c1xx_pdb_map * map, uint key, uint * slot);
int __fastcall map_grow(c1xx_pdb_map * map);
void __thiscall array_swap(c1xx_pdb_array * array, c1xx_pdb_array * other);
void __cdecl pch_relocate_using_entry(int value);
c1xx_bitvec * __fastcall bitvec_init_empty(c1xx_bitvec * bv);
int __thiscall bitvec_alloc(c1xx_bitvec * bv, int nbits, c1_arena * a);
char __thiscall bitvec_attach(c1xx_bitvec * bv, int nbits, c1_u8 * bits);
c1_u8 * __fastcall bitvec_release_bits(c1xx_bitvec * bv);
void __thiscall pch_block_mark_visited(c1xx_bitvec * visited, int bit);
byte __thiscall pch_block_is_visited(c1xx_bitvec * visited, int bit);
char __fastcall bitvec_iter_first(c1xx_bitvec * bv);
char __fastcall bitvec_iter_next(c1xx_bitvec * bv);
int __fastcall bitvec_iter_index(c1xx_bitvec * bv);
int __thiscall pch_segment_alloc_at_base(c1xx_pch_stream_reader * pch_stream_reader, void * file);
int __thiscall pch_segment_alloc_anywhere(c1xx_pch_stream_reader * pch_stream_reader, void * file, int unused);
void __thiscall pch_segment_read_bytes(c1xx_pch_stream_reader * pch_stream_reader, void * file);
void __fastcall pch_segment_force_relocation(c1xx_pch_stream_reader * pch_stream_reader);
void __thiscall pch_segment_write_contents(c1xx_pch_stream_reader * pch_stream_reader, uint file);
void __fastcall pch_segment_compute_delta(int pch_stream_reader);
void __thiscall pch_segment_create_reloc_bitmap(c1xx_pch_stream_reader * pch_stream_reader, int a);
char __thiscall pch_segment_open_reloc_bitmap(c1xx_pch_stream_reader * pch_stream_reader, c1xx_pch_stream_reader * holder);
void __thiscall pch_segment_apply_relocations(c1xx_pch_stream_reader * pch_stream_reader, c1xx_pch_image * image);
void __thiscall pch_page_table_fill(c1xx_pch_stream_reader * * page_map, c1xx_pch_stream_reader * segment, uint base, int size);
void __thiscall pch_image_init_from_loaded(c1xx_pch_image * image, c1xx_pch_image * loaded, int extra);
byte __fastcall pch_image_map_blocks(int asked, int * index, int zero, byte result, int moved);
void __thiscall pch_image_relocate(c1xx_pch_image * image, int unused);
c1xx_pch_stream_reader * * __thiscall pch_image_page_table_new(c1xx_pch_image * image, void * address_getter);
void __fastcall pch_heap_write_file(c1xx_pch_image * image);
char __thiscall pch_relocate_slot_once(void * pch_image, uint * slot);
char __thiscall pch_relocate_pointer(void * pch_image, uint * slot);
c1xx_pch_stream_reader * __fastcall pch_segment_self(c1xx_pch_stream_reader * pch_stream_reader);
void * __fastcall pch_segment_base(c1xx_pch_stream_reader * pch_stream_reader);
uint __fastcall pch_segment_size(c1xx_pch_stream_reader * pch_stream_reader);
uint __fastcall pch_segment_descriptor_word(c1xx_pch_stream_reader * pch_stream_reader);
void * __fastcall pch_segment_vcall_base(c1xx_pch_stream_reader * seg);
void * __fastcall pch_segment_vcall_loaded_address(c1xx_pch_stream_reader * seg);
char __thiscall pdb_file_stack_top_object(c1_mre_tracker * tracker, c1_mre_file * * out);
void __cdecl pch_relocate_stub_16(void);
void __cdecl pch_relocate_declarator_record_value(uint * slot);
void __cdecl pch_relocate_symtab_1b40(void);
void __cdecl pch_fixup_pair_element(int elem);
void __cdecl pch_relocate_vector_1b4c(void);
void __fastcall pdb_session_close(c1_pdb_session * session);
byte __thiscall pdb_contrib_lookup_file(c1_pdb_session * session, char * file, int * value);
byte __thiscall pdb_contrib_find_entry(c1_pdb_blob_table * table, char * file, void * * data, c1_u32 * size);
void __cdecl pch_relocate_imported_library_entry(int entry);
void __cdecl pch_relocate_vector_1b54(void);
void __fastcall pdb_array_destroy(c1xx_pdb_array * array);
void __cdecl pch_relocate_symtab_15c4(void);
void __cdecl pch_relocate_adjustor_thunk_key(int key);
void __cdecl pch_mark_vtable_record(int * rec);
void __cdecl pch_fixup_vtable_slot_word0(uint slot);
void __cdecl pch_fixup_vtable_slot_word1(int slot);
void __cdecl pch_relocate_vbase_record(c1_vbase_record * rec);
void __cdecl pch_relocate_pending_vtables(void);
void __fastcall pch_relocate_counted_pointer_array(uint * array);
void __cdecl pch_relocate_symtab_15d0(void);
void __cdecl pch_fixup_symtab_key_pair(int key);
void __cdecl pch_relocate_inline_instance_table(void);
void __cdecl pch_relocate_vcall_thunk_key(uint * slot);
void __cdecl pch_relocate_symtab_16f4(void);
void __cdecl pch_relocate_symtab_16f8(void);
void __cdecl pch_relocate_copy_ctor_closure_table(void);
void __cdecl pch_relocate_symtab_1700_1704(void);
void __cdecl pch_relocate_pending_special_members(void);
void __cdecl pch_mark_rtti_type_descriptor_nop(void * item);
void __cdecl pch_mark_rtti_type_descriptors(void);
void __cdecl pch_relocate_template_work_queue(void);
void __cdecl pch_relocate_symtab_160c(void);
void __cdecl pch_relocate_symtab_15f0(void);
void __cdecl pch_relocate_symtab_15f4(void);
void __cdecl pch_relocate_symtab_15f8(void);
void __cdecl pch_relocate_tmpl_definition_table(void);
void __cdecl pch_relocate_symtab_1600(void);
void __cdecl pch_relocate_symtab_1604(void);
void __cdecl pch_relocate_symtab_1608(void);
void __cdecl pch_relocate_template_argument_list(uint * slot);
void __fastcall pch_fixup_list_object(c1xx_obj_104c4c3c * obj);
void __fastcall pch_fixup_tree_list_object(c1xx_obj_104bcbcc * obj);
void __fastcall pch_mark_object_links(int obj);

c1_symbol * __cdecl sym_take_free_record(byte kind, void * name, int arena);
c1_symbol * __thiscall sym_init_kind(c1_symbol * sym, c1_u8 kind, void * name, int unused);
void __thiscall decl_append_function_layer(int * rec, void * params);
void __fastcall decl_pop_declarator_state(c1_param_clause * clause);
void __thiscall decl_append_derived_check(c1_decl_record * rec, c1_type * layer);
void __fastcall decl_finish_declarator(c1_decl_record * rec);
void __fastcall decl_check_declarator_modifiers(c1_decl_record * rec);
c1_symbol * __fastcall decl_member_function_class(c1_decl_record * rec);
c1_node * __cdecl decl_chain_default_arguments(c1_arg_list * args);
void __thiscall decl_set_parameter_type(c1_type * fn, int params, c1_node * defaults, c1_type * this_type);
int * __cdecl decl_intern_parameter_list(int params, int fflags, int defaults, int this_type);
void __fastcall decl_assign_calling_conventions(int rec);
int __thiscall decl_default_calling_convention(void * type, byte * type2);
void __fastcall decl_warn_modifiers_on_data(c1_decl_record * rec);
c1_decl_record * __thiscall decl_record_init_default(c1_decl_record * rec, void * name, c1_overload_set * qualifier);
void __fastcall decl_process_declaration(c1_declarator * d);
void __fastcall decl_process_declaration_case0_fragment(c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __stdcall decl_process_declaration_storage_fragment(undefined4 eax, c1_declarator * d);
c1_symbol * __thiscall sym_new_from_declarator(c1_declarator * d, uint mode);
c1_symbol * __thiscall sym_finish_new(c1_symbol * sym, c1_declarator * d);
c1_symbol * __cdecl sym_alloc_record(int unused, uint kind, int arena);
void __thiscall sym_attach_declspec_record(c1_symbol * key, uint * spec);
void __thiscall decl_check_conversion_return_type(c1_decl_record * rec, c1xx_decl_specifiers * spec);
c1_symbol * __thiscall decl_declare_and_check(c1_declarator * d, byte * spec);
c1_symbol * __thiscall decl_declare_in_current_scope(c1_declarator * d, c1xx_decl_specifiers * specs);
void __fastcall decl_enter_declaration_context(c1_declarator * d);
void __fastcall decl_check_missing_type_specifier(c1_declarator * d);
c1_symbol * __fastcall scope_current_namespace(c1_scope_stack * stack);
int * __thiscall scope_lookup_for_declaration_innermost(c1_scope_stack * stack, c1_declarator * d);
c1xx_scope * __thiscall scope_innermost_declaration_record(c1_scope_stack * stack, char skip_binding);
c1_lookup_result * __thiscall hash_scope_lookup(c1xx_hash_scope * scope, fe_name * name, int mode);
c1_symbol * __cdecl scope_lookup_skip_type_aliases(c1_sym_link * chain, void * name);
c1_symbol * __thiscall decl_redeclare_or_new(c1_declarator * d, c1_symbol * sym);
void __thiscall hash_scope_insert(c1xx_hash_scope * scope, c1_symbol * sym);
c1_symbol * __stdcall sym_insert_check_alias(c1_symbol * sym2);
void __thiscall hash_scope_link(c1xx_hash_scope * scope, c1_symbol * sym);
void __cdecl decl_check_operator_function(c1_symbol * sym, int at_definition);
c1_type_list * __cdecl param_type_list_intern(int count, c1_sym_list * params);
void __fastcall decl_assign_data_segment_and_check(c1_declarator * d);
char * __fastcall decl_scan_specifier_tokens(c1_decl_spec_scan * state);
char * __fastcall decl_scan_specifier_tokens_case_1a(int * state);
char * __stdcall decl_check_typename_outside_template(undefined4 state);
void __cdecl decl_position_set_symbol(c1xx_browse_record * rec, c1_symbol * sym);
c1_type * __cdecl sym_resolved_type_mark_used(c1_symbol * sym);
void __fastcall decl_check_type_unexpected(int state);
void __fastcall decl_check_qualifier_position(c1_type * named_type, c1_decl_spec_scan * state);
c1_u8 * __thiscall decl_scan_make_specifier_token(c1_decl_spec_scan * state, c1_u8 token_code);
void __thiscall scope_push_child(c1_scope_stack * stack, c1xx_scope * scope);
void __thiscall scope_push_block(c1_scope_stack * stack, c1xx_scope * scope);
void __fastcall decl_combine_type_specifiers(undefined4 * state);
void __stdcall decl_check_illegal_token_pair_fragment(void);
int __fastcall decl_check_type_before_constructor(int * state);
c1_type * __cdecl decl_basic_specifier_type(ushort basic_type, c1_u16 cv);
byte * __cdecl decl_qualified_name_make_token(c1_u8 * cur_tok, c1_keyed_list * scope, void * name, c1_keyed_list * scope_saved, int leading_global, int has_ctor, int has_dtor, void * saved_name, int pair_second, int set_flags1_80, int set_flags3_01, char * token, int p2);
c1_declarator * __cdecl decl_declarator_alloc(void);
c1_declarator * __thiscall decl_declarator_init(c1_declarator * d, fe_name * name, c1_u32 kind, c1_overload_set * qualifier);
c1_lookup_entry * __thiscall lookup_name_in_context(c1_scope_stack * ctx, void * name, uint mask);
c1_u8 * __stdcall lookup_name_in_context_return_zero(void);
c1_symbol * __fastcall decl_declarator_symbol(c1_declarator * d);
c1xx_decl_specifiers * __stdcall decl_specifiers_current(void);
c1_lookup_entry * __thiscall lookup_check_ambiguous_symbol(c1_lookup_result * result, char report);
void * __fastcall decl_declarator_record(c1_declarator * d);
void __thiscall decl_declarator_set_specifiers(c1_declarator * d, c1xx_decl_specifiers * spec);
char __cdecl sym_check_owner_scope(char * out, c1_symbol * sym);
void __fastcall decl_specifier_set_class_type(int * state);
void __thiscall scope_pop_to_kind_if_needed(c1_scope_stack * stack, char p2);
void __fastcall sym_mark_referenced(c1_symbol * sym);
c1_lookup_result * __thiscall hash_scope_lookup_by_kind(c1xx_hash_scope * scope, fe_name * name, uint flags, byte * found);
uint __cdecl sym_kind_in_lookup_mask(c1_u8 * entry, uint flags);
void __thiscall scope_new_block_record(c1_scope_stack * stack, c1_sym_list * params);
void __fastcall scope_pop_child(c1_scope_stack * stack);
void __fastcall scope_pop_block(c1_scope_stack * stack);
c1_symbol * __thiscall decl_declare_from_declarator(c1_declarator * d, byte * spec);
void __thiscall decl_declarator_append_pointer_op(c1_decl_record * rec, c1_ptr_operator * op);
c1_type * __cdecl sym_type_of(c1_symbol * sym);
void __thiscall decl_set_local_key_flag(c1_declarator * d, c1_u8 value);
c1_sym_list * __fastcall scope_symbol_list(c1xx_scope * scope);
c1_sym_list * __fastcall scope_pop_if_kind1(c1_scope_stack * stack);
c1_symbol * __thiscall decl_check_overload_linkage(c1_declarator * d, c1_symbol * sym);
void __thiscall decl_append_array_layer(c1_decl_record * rec, int * bound);
c1_symbol_vector * __cdecl symtab_record_new(int count);
c1_symtab * __cdecl symtab_new(int nbuckets, int arena, int hash, int compare, c1_u8 flag0, c1_u8 flag1);
void __cdecl symtab_insert(c1_symtab * tab, void * key, void * value);
int __cdecl sym_element_size(int sym);
int __fastcall sym_is_data_or_function_2(c1_symbol * sym);
uint __cdecl hash_table_bucket(c1_symtab * tab, void * key);
uint __cdecl symtab_hash_pointer_0(uint key);
c1_symtab_entry * __cdecl symtab_find_in_bucket(c1_symtab * tab, void * key, int bucket);
c1_decl_state * __thiscall decl_state_snapshot(c1_decl_state * rec, c1_scope_stack * stack, c1_decl_state * next, char copy);
int __fastcall hash_scope_has_entries(c1xx_hash_scope * scope);
int __cdecl sym_is_static_data_member(c1_symbol * sym);
c1_symbol * __cdecl sym_class_type_of(c1_symbol * sym);
void __thiscall decl_state_restore(c1_scope_stack * stack, char unused);
void __fastcall decl_state_pop(c1_scope_stack * stack);
c1_symbol * __cdecl sym_class_needing_init(c1_symbol * sym);
c1xx_hash_scope * __thiscall scope_enclosing_namespace(c1_scope_stack * stack, char null_if_global);
undefined4 __fastcall sym_name(c1_symbol * sym);
char __cdecl symtab_equal_2(int a, int b);
char __thiscall decl_check_redeclaration(c1_declarator * d, c1_symbol * sym);
int __thiscall decl_compare_redeclared_type(c1_declarator * d, c1_symbol * sym);
int __thiscall decl_compare_type_level(int level, c1_type * old_type, c1_type * new_type, c1_declarator * d, c1_symbol * sym_reg, c1_symbol * sym);
char __thiscall decl_check_storage_compatible(c1_declarator * d, c1_symbol * sym);
void __thiscall decl_merge_attributes(c1_declarator * d, c1_symbol * sym);
void __cdecl decl_check_default_argument_redefinition(c1_function_params * newp, c1_function_params * oldp, c1_symbol * sym, int mode);
void * __cdecl symtab_lookup(c1_symtab * tab, void * key);
uint __cdecl symtab_hash_pointer_7(uint key);
char __cdecl symtab_equal_6(int a, int b);
c1_node * __cdecl sym_is_data_or_function(c1_symbol * sym);
c1_u8 * __cdecl symtab_record_new_kind4(void);
void __cdecl sym_list_remove_matching(int * paths, c1_symtab * seen);
c1_type * __thiscall lookup_class_pointer_type(void * lookup, c1_u32 qualifiers);
void __thiscall scope_note_visited_namespace(void * scope, int ns);
int __cdecl lookup_adl_class_and_bases(int cls, int name, int found);
int __cdecl lookup_adl_class_namespace(int cls, int name, int found);
void __cdecl sym_mark_enclosing_scopes(c1_symbol * sym);
uint __cdecl symtab_hash_pointer_2(uint key);
char __cdecl symtab_equal_1(int a, int b);
void * __cdecl sym_static_member_stand_in(c1_symbol * key);
c1_u8 * __thiscall lookup_name_mask_121(c1_scope_stack * ctx, fe_name * name);
c1_keyed_list * __cdecl lookup_qualified_name(c1_keyed_list * qualifier, void * name, c1_type * conv_type, char p4);
c1_overload_set * __cdecl sym_new_overload_set_record(c1_keyed_list * list, fe_name * name, int arena);
c1_keyed_cell * __cdecl lookup_qualifier_chain_splice(c1_keyed_cell * chain, c1_keyed_cell * item);
int __cdecl symtab_hash_first_word(int * key);
char __cdecl symtab_equal_first_word(int * a, int * b);
int __cdecl lookup_in_enclosing_scopes(char p1, int cls, int member, int * owner);
int __cdecl lookup_operator_function(c1_symbol * sym, int scope_cls);
c1xx_decl_specifiers * __cdecl decl_specifiers_default(void * mods);
void __thiscall lookup_check_symbol_kind(c1_scope_stack * stack, byte * key, int name, char p4);
void __thiscall scope_stack_promote_class_scopes(c1_scope_stack * stack);
c1_symbol * __cdecl sym_new_kind1_placeholder(fe_name * name);
void __cdecl lookup_check_symbol_kinds_reversed(int * list);
void __thiscall decl_record_set_qualifying_class(c1_declarator * d, c1_symbol * owner);
byte * __fastcall decl_resolve_function_in_overload_set(c1_declarator * d);
byte * __cdecl sym_alloc_record_fragment(c1_symbol * sym2, c1_type * list, void * sym_slot, c1_type * list_slot);
uint __cdecl sym_new_local_key(void);
uint __cdecl sym_list_has_flagged_scope_entry(int paths_rec);
int __thiscall decl_type_modifiers_compatible(c1_declarator * d, ushort old_flags, ushort new_flags, c1_symbol * sym);
void __cdecl decl_compare_parameter_lists(int newp, int oldp);
fe_name * __fastcall sym_name_of_ref(c1_symbol * * ref);
void __thiscall decl_check_missing_default_parameter(c1_function_params * params, c1_symbol * sym);
void __thiscall sym_attrs_set_segment_record(c1_symbol_attrs * attrs, c1_symbol * segment);
void __thiscall sym_attrs_set_declspec_record(c1_symbol_attrs * attrs, void * declspec);
void __thiscall sym_attrs_set_function_position(c1_symbol_attrs * attrs, int earlier_entity);
uint __cdecl symtab_hash_name(int name);
void __cdecl sym_set_this_adjustment(c1_symbol * fn, void * adj);
c1_symtab * __cdecl symtab_ensure_16f8(void);
c1_symtab * __cdecl symtab_ensure_16f4(void);
int * __thiscall hash_scope_find_link(void * this, int * entry);
c1_keyed_cell * __cdecl scope_list_from_class(c1_vtable_record * rec, c1_symbol * cls);
void __cdecl lookup_member_pointer_class(c1_symbol * * out_class, c1_overload_set * qualifier);
c1_arg_item * __fastcall decl_finish_declarator_record(c1_declarator * d);
void * __cdecl symtab_15f4_lookup(void * key);
void * __cdecl symtab_160c_lookup(void * key);
void * __cdecl symtab_1608_lookup(void * key);
void * __cdecl symtab_1600_lookup(void * key);
char __fastcall sym_not_written_to_il(c1_symbol * sym);
void __thiscall decl_set_has_initializer(c1_declarator * d, c1_u8 value);
void __thiscall decl_record_set_symbol(void * this, c1_symbol * sym);
int __cdecl decl_begin_initialized_definition(c1_symbol * sym);
void __cdecl decl_finish_initialization(c1_symbol * sym, c1_node * node);
int __cdecl sym_has_scalar_type(c1_symbol * sym);
int __fastcall sym_kind_is_alias_or_using(c1_symbol * sym);
void __stdcall local_keys_reset(void);
c1_node * __cdecl label_new(int label_kind);
void __cdecl label_register(c1_symbol * label);
void __fastcall scope_cleanup_record_new(c1_scope_stack * stack);
void __cdecl scope_end_block(void);
void __cdecl scope_end_block_tail(int scope);
void __thiscall scope_link_closed_block(c1_scope_stack * stack, c1xx_scope * block);
void __cdecl label_emit_definition(c1_node * labelref);
void __fastcall hash_scope_emit_il(c1xx_hash_scope * scope);
void __cdecl sym_clear_global_helper_key(void);
char __cdecl decl_check_default_argument_expression(c1_symbol * sym);
int __cdecl sym_has_reference_type(c1_symbol * sym);
void __cdecl sym_set_nesting_depth(c1_symbol * sym);
c1_u8 * __thiscall decl_bind_block_declaration(c1_scope_stack * stack, c1_declarator * d);
c1_symbol * __fastcall sym_from_table_entry(int entry);
c1_u32 __fastcall sym_decl_position(c1_symbol * sym);
ushort __cdecl decl_apply_default_calling_convention(uint kind, ushort flags);
c1_symbol * __cdecl decl_new_compiler_formal(void * name, c1_type * type);
void __thiscall decl_set_is_constructor(c1_declarator * d, c1_u8 value);
void __thiscall decl_set_is_destructor(c1_declarator * d, c1_u8 value);
void __thiscall decl_set_bitfield_width(c1_declarator * d, c1_u8 width);
c1_type_list * __cdecl global_scope_record(void);
char __fastcall sym_overload_iter_next(c1xx_ovl_set_iter * iter);
void __thiscall sym_overload_iter_init(c1xx_ovl_set_iter * iter, c1_u8 * entry);
int __cdecl symtab_equal_0(int a, int b);
c1_u8 * __thiscall hash_scope_lookup_tag(void * scope, void * name);
c1xx_class_scope * __thiscall lookup_overload_member(c1_scope_stack * stack, c1_symbol * sym, int kind);
char __cdecl lookup_is_type_or_member_of_type(c1_symbol * sym);
char __cdecl vtable_true_al(void);
void __thiscall sym_list_append_2(void * list, c1_symbol * sym);
void __stdcall scope_enter_symbol_scope(c1_symbol * sym);
void __thiscall scope_enter_class(c1_scope_stack * stack, c1_symbol * sym);
c1_symbol * __cdecl sym_new_alias_record(c1_symbol * sym);
void __cdecl decl_specifiers_merge(byte * spec, byte storage_class, char kind, int value);
void __stdcall decl_specifiers_merge_return(void);
void __fastcall decl_specifiers_add_storage_class(int * spec_rec, int value);
byte * __thiscall decl_redeclare_beside_class_name(c1_declarator * d, byte * old);
c1_symbol * __thiscall sym_copy_unlinked(c1_symbol * dst, c1_symbol * sym, int arena);
void __thiscall sym_list_append(void * list, c1_symbol * sym);
ushort __thiscall decl_check_varargs_calling_convention(void * rec, c1_type * type, ushort flags);
void __cdecl decl_push_linkage_specification(int linkage);
void __thiscall scope_insert_through_object(void * holder, c1_symbol * sym);
void __thiscall scope_pop_to_kind(c1_scope_stack * stack, char p2);
undefined4 __fastcall decl_specifier_add_qualifier(undefined4 * state, undefined4 eax);
void * __thiscall decl_set_name(c1_declarator * d, void * name);
void __thiscall decl_check_modifier_over_reference(c1_decl_record * rec, c1_type * layer);
void __fastcall decl_specifiers_add_modifier(int * spec_rec, int value);
void __cdecl decl_check_empty_declaration(byte * spec);
void __thiscall decl_add_pointer_modifier(void * decl, ushort * mods, ushort * extra);
int __fastcall decl_scan_class_specifier(c1_decl_spec_scan * state);
c1_symbol * __cdecl decl_tag_definition_lookup(int name, int kind, void * * insert_fn);
c1_u8 * __thiscall scope_lookup_tag_current_or_namespace(c1_scope_stack * stack, fe_name * name, char in_namespace);
c1_symbol * __cdecl decl_tag_declare(fe_name * name, c1_u16 tag_code, void * * insert_fn, char is_definition);
void __thiscall decl_tag_declarator_set_kind(c1_declarator * d, c1_u16 tag_code, void * * insert_fn, char is_definition);
c1_u8 * __thiscall scope_lookup_for_declaration(void * scope, c1_declarator * d, int flags);
void __thiscall scope_vector_add(c1_symbol * sym, char kind);
void __cdecl decl_check_default_parameters_of(c1_symbol * sym);
int __fastcall iterator_begin_from_record(c1_decl_spec_scan * state);
c1_symbol * __cdecl decl_tag_check_kind_and_browse(c1_symbol * sym, int kind);
c1_symbol * __cdecl decl_tag_lookup_qualified_or_declare(fe_name * name, int tag_code, void * * insert_fn);
void __thiscall decl_add_reference_modifier(void * decl, ushort * mods);
void __cdecl ns_using_declare_target(c1_symbol * * result, c1_symbol * sym);
c1_symbol * __thiscall decl_new_using_alias(c1_scope_stack * scope, c1_symbol * using_sym, c1_symbol * target);
c1_symbol * __thiscall decl_new_using_alias_of_alias(c1_scope_stack * scope, byte * name, c1_symbol * target, c1_symbol * using_sym, c1_type * using_entry);
int __thiscall scope_stack_lookup_name(void * stack, void * name, char functions);
void __thiscall sym_inherit_scope_index(c1_symbol * sym, byte * from);
longlong __cdecl enum_warn_value_wrapped(longlong value, void * name);
void __thiscall scope_insert_into_enclosing_namespace(c1_scope_stack * stack, c1_symbol * sym);
c1_u8 __fastcall sym_flags3_bit0(c1_symbol * sym);
void __cdecl enum_declare(fe_name * name, c1_type * enum_type, c1_u32 value_lo, int value_hi);
char __cdecl decl_check_function_style_initializer(c1_symbol * sym);
void __cdecl symtab_iterator_init(c1_symtab_iter * it, c1_symtab * tab);
c1_u8 __cdecl symtab_iterator_next(c1_symtab_iter * it);
int __cdecl symtab_entry_count(c1_symtab * tab);
int __cdecl sym_compare_by_entity_id(c1_symbol * * a, c1_symbol * * b);
c1_symbol * __cdecl sym_new_scoped_copy(c1_symbol * qualified, int arena);
int __cdecl sym_ensure_debug_type(c1_symbol * sym);
void * __cdecl symtab_15ec_lookup_by_id(c1_symbol * sym);
uint __cdecl symtab_hash_identity_3(uint key);
c1_symbol * __cdecl sym_first_function_of_overload_set(c1_symbol * sym, char flag);
void * __thiscall decl_record_init(void * rec, c1_type * type, void * spec);
c1_symbol * __cdecl sym_new_in_current_scope(void);
void __cdecl symtab_21f4_insert(c1_symbol * key, void * value);
void * __cdecl sym_inline_instance_of(c1_symbol * key);
void __fastcall decl_allow_variable_array_bound(c1_decl_record * rec);
c1_node * __fastcall decl_record_new_array_bound(c1_decl_record * rec);
void * __cdecl symtab_1700_lookup(c1_symbol * key);
c1_symtab * __cdecl symtab_ensure_1700(void);
char __cdecl sym_should_defer_emission(c1_symbol * sym);
char __cdecl sym_is_deferrable(c1_symbol * sym);
void __cdecl sym_defer_emission(c1_symbol * sym);
void __thiscall scope_construct(c1xx_scope * scope, c1_u8 kind, c1xx_scope * parent);
void __cdecl sym_emit_deferred(void);
void __cdecl sym_list_emit_deferred(int * list);
void __cdecl scope_table_init(void);
c1_scope_stack * __fastcall scope_stack_new_global(c1_scope_stack * stack);
void __cdecl symtab_new_global_16(void);
c1_type * __cdecl sym_new_builtin_helper(ushort convention, c1_type * type);
c1_symbol * __cdecl sym_new_object(void * name, char local);
void __cdecl sym_set_segment_from(c1_symbol * sym, void * segment);
void __thiscall sym_copy_record(c1_symbol * dst, c1_symbol * sym, void * class_record, int arena);
void * __cdecl symtab_14ac_lookup_by_name(c1_symbol * sym);
c1_symbol * __cdecl decl_merge_redeclaration(c1_symbol * sym, void * name, c1_symbol * p3);
c1_symbol * __cdecl sym_segment_record(c1_symbol * sym);
void __cdecl sym_queue_destructible_object(c1_symbol * sym);
byte * __thiscall scope_lookup_segment(void * stack, void * name);
c1_symbol * __cdecl sym_new_static_in_segment(void * name, c1_type * type, void * segment);
void __cdecl sym_set_segment(c1_symbol * sym, void * value);
c1_symbol * __cdecl decl_new_compiler_variable(byte storage, c1_type * type);
c1_symbol * __cdecl sym_new_builtin(void * name, void * seg_class, uint id, c1_u8 cls);
void __cdecl decl_static_with_destructor_register(c1_symbol * sym);
int __cdecl label_find_in_function(int name);
c1_u8 * __cdecl label_new_user(int name);
int __cdecl symtab_hash_vcall_key_6(int key);
c1_symbol * __cdecl sym_new_vcall_thunk(c1_vcall_thunk_key * key);
void __cdecl sym_set_attribute_15e8(c1_symbol * sym, void * value);
void * __cdecl sym_get_attribute_15e8(c1_symbol * sym);
c1_u8 __cdecl sym_is_default_constructor(c1_symbol * fn);
int __cdecl decl_parse_linkage_specification(c1xx_decl_specifiers * spec, c1_node * string);
c1_u8 __cdecl decl_warn_unexpected_specifiers_1(c1xx_decl_specifiers * spec);
c1_u8 __cdecl decl_warn_unexpected_specifiers_2(c1xx_decl_specifiers * spec, c1_u8 report);
char __cdecl decl_specifiers_merge_modifiers(byte * spec, uint mods);
void __cdecl decl_pop_linkage_specification(void);
void __cdecl decl_parse_declspec(byte * spec, undefined4 value);
void __fastcall sym_detail_set_flag3f_bit3(c1_symbol * tag);
c1_u8 __fastcall decl_tag_parse_declspec(void * tag);
c1_symbol * __cdecl sym_new_of_kind(c1_u8 kind, fe_name * name, int arena);
void __fastcall sym_mark_ellipsis_parameter(c1_symbol * sym);
int __fastcall sym_kind_is_declared_entity(c1_symbol * sym);
void __cdecl decl_conversion_function_declarator(c1xx_decl_specifiers * spec, c1_decl_record * rec);
fe_name * __cdecl decl_conversion_function_name(c1_type * type);
void __thiscall decl_record_set_conversion_type(c1_decl_record * rec, c1xx_decl_specifiers * spec);
void __fastcall decl_check_conversion_syntax(void * d);
void __cdecl decl_qualified_conversion_function_name(c1_symbol * sym, c1_type * type);
void __cdecl sym_attach_extra(c1_symbol * sym, void * value);
c1_sym_list * __fastcall scope_pop_template_parameter_scope(c1_scope_stack * stack);
void __cdecl symtab_1604_insert(c1_symbol * key, void * value);
void __cdecl symtab_15f4_insert(c1_symbol * key, void * value);
void __fastcall scope_push_instantiation_context(c1_parse_state * inst);
void __cdecl symtab_1608_insert(void * key, void * value);
void __thiscall decl_state_unwind_to(c1_scope_stack * stack, c1_decl_state * entry);
void __cdecl sym_recycle_record(c1_symbol * sym);
void * __cdecl sym_this_adjustment(c1_symbol * sym);
void __cdecl symtab_15ec_insert_by_id(c1_symbol * sym, void * value);
char __cdecl sym_emission_must_wait(c1_symbol * sym);
void __cdecl decl_vector_iterator_helpers(void);
void __cdecl decl_vector_iterator_helper(void * name, int kind, int flag);
void __cdecl decl_builtin_helper_function(void * name, int pointee, int modifier, int unused, int helper_kind, char not_eh);
c1_symbol * __cdecl sym_new_kind12(void);
void __cdecl sym_init_purecall(void);
c1_symbol * __cdecl sym_builtin_helper_function(int index);
void __cdecl decl_parse_property_declspec(byte * spec);
void __stdcall decl_parse_declspec_arguments(undefined4 spec);
void __stdcall decl_check_illegal_token_pair(undefined4 code, undefined4 code2);
void __thiscall decl_combine_type_specifiers_long_int(c1_u8 int_merged, uint current_code, uint new_code, uint sign_bits);
void __fastcall decl_record_reset_default_int(c1_decl_spec_scan * scan);
void __stdcall decl_check_type_unexpected_ignore_qualifiers(c1_decl_spec_scan * state, uint code);
byte * __cdecl decl_qualified_name_scan_part_2(c1_u8 * next_tok, c1_keyed_list * scope, char first_lookup_hit, int leading_global, byte * template_tok, c1_u8 saved_access_op, c1_u8 saved_reported, c1_u8 saved_access_op_2, c1_u8 saved_reported_2, char * token, int p2);
byte * __cdecl decl_qualified_name_destructor_cold(c1_symbol * cls, void * name, c1_keyed_list * scope, char op_byte, char first_lookup_hit, c1_u8 * cur_tok, c1_keyed_list * scope_saved, int leading_global, int nerrors, int has_ctor, int has_dtor, byte * template_tok, int pair_second, int set_flags1_80, int set_flags3_01, c1_u8 saved_access_op, c1_u8 saved_reported, c1_u8 saved_access_op_2, c1_u8 saved_reported_2, char * token, int p2);
byte * __cdecl decl_qualified_name_scan_part_1(int * tmpl_rec, void * name, c1_keyed_list * scope, char op_byte, char first_lookup_hit, c1_u8 * cur_tok, c1_keyed_list * scope_saved, int leading_global, int nerrors, int has_ctor, int has_dtor, void * saved_name, byte * template_tok, int set_flags1_80, int set_flags3_01, c1_u8 saved_access_op, c1_u8 saved_reported, c1_u8 saved_access_op_2, c1_u8 saved_reported_2, char * token, int p2);
byte * __cdecl decl_lookup_qualified_template_name_fragment(c1_symbol * cls, c1_keyed_list * scope, char op_byte, char first_lookup_hit, c1_u8 * cur_tok, c1_keyed_list * scope_saved, int leading_global, int nerrors, int has_ctor, int has_dtor, void * saved_name, byte * template_tok, int pair_second, int set_flags1_80, int set_flags3_01, c1_u8 saved_access_op, c1_u8 saved_reported, c1_u8 saved_access_op_2, c1_u8 saved_reported_2, char * token, int p2);
byte * __cdecl decl_qualified_name_errors_cold(c1_type * scope, void * name, char op_byte, c1_u8 * cur_tok, c1_type * scope_saved, int leading_global, int nerrors, int has_ctor, int has_dtor, void * saved_name, int pair_second, int set_flags1_80, int set_flags3_01, char * token, int p2);
byte * __cdecl decl_declarator_name_mark_fragment(c1_symbol * sym, byte * new_tok, int has_ctor, int has_dtor, int set_flags1_80, int set_flags3_01);
void __stdcall decl_check_multiple_storage_classes(undefined4 ebx, undefined4 spec);
c1_symbol * __cdecl scope_vector_get(short index);
uint * __cdecl decl_specifiers_of_symbol(uint * spec, c1_symbol * sym);
int __fastcall sym_scope_index(c1_symbol * sym);
c1_symbol * __thiscall sym_scope_by_index(c1_symbol * sym, int unused);
c1_symbol * __cdecl sym_new_of_kind_free_list_fragment(c1_u32 kind_x4, c1_sym_link * cell, c1_u8 kind, int size_class, fe_name * name, int arena);
void __thiscall sym_tag_set_member_list(void * sym_link, c1_sym_list * members);
void __cdecl decl_declare_anonymous_union(c1xx_decl_specifiers * spec);
c1_symbol * __cdecl decl_declare_anonymous_union_object(c1xx_decl_specifiers * spec);
void __cdecl sym_apply_specifier_block(c1_symbol * sym, uint storage_flags, void * segment, void * property, c1_guid * uuid);
void __cdecl decl_declare_anonymous_union_member(c1_symbol * object, c1_symbol * member, c1xx_decl_specifiers * spec);
void __cdecl decl_anonymous_union_done_nop(c1_symbol * object);
void __thiscall scope_insert_through_object_pointer(void * * holder, c1_symbol * sym);
int __fastcall sym_is_member_function_or_class_alias(c1_symbol * sym);
void __stdcall enum_declare_enumerator(void);
c1_symbol * __cdecl sym_resolve_single_function(char kind, c1_symbol * sym, char flag);
char __cdecl lookup_check_qualifier_path_fragment(c1_keyed_cell * cell, c1_symbol * member, c1_symbol * scope_class, char at_context_class, char static_like_member, uint access, c1_symbol * context_class, int friend_result, c1_symbol * scope_class_local, uint base_access, c1_symbol * naming_class, int restricted_step, uint prev_access, c1_symbol * member_local, c1_symbol * prev_qualifier, int naming_class_friend, int restricted_friend, byte * sym);
c1_symbol * __stdcall decl_check_function_definition_head(c1_declarator * d);
c1_symbol * __stdcall decl_check_definition_dllimport(c1_symbol * sym, c1_declarator * d);
void __cdecl decl_function_type_add_default_arguments(c1_symbol * sym, c1_node * new_defaults, c1_function_params * old_params, c1_function_params * new_params, c1_node * new_last);
void * * __cdecl lookup_member_match_overload_part_1(byte kind, uint cc_flags, int zero, c1_symbol * probe_reg, c1_sym_link * cell, c1_symbol * cand, int * old_params, int new_params, c1_type * new_this_type, c1_sym_link * next_cell, c1_sym_link * cur_cell, c1_sym_link * cursor, int * deduction_args, int * deduction2_args, c1_type * type, char complain, char skip_templates, c1_symbol * probe, c1_declarator * d, int mode);
void * * __cdecl lookup_member_match_overload_part_2(int zero, c1_symbol * probe_reg, c1_sym_link * cell, c1_symbol * cand, int * old_params, int new_params, c1_type * new_this_type, c1_sym_link * next_cell, c1_sym_link * cur_cell, c1_sym_link * cursor, int * deduction_args, int * deduction2_args, c1_type * type, char complain, char skip_templates, c1_symbol * probe, c1_declarator * d, int mode);
c1_symbol * __thiscall sym_new_from_declarator_arena4_block(c1_declarator * d);
c1_symbol * __thiscall sym_finish_new_with_line(void * qualifier, c1_symbol * new_sym, c1_symbol * sym, c1_declarator * d);
c1_symbol * __thiscall sym_finish_new_member_fragment(void * tmpl, c1_symbol * sym, c1_declarator * d);
c1_symbol * __thiscall sym_finish_new_static_member_fragment(void * tmpl_datum, c1_symbol * sym, c1_declarator * d);
c1_symbol * __thiscall sym_new_from_declarator_reuse_kind_b(int free_index, void * * free_cell, c1_declarator * d, uint mode, void * * free_cell_copy, void * name);
c1_symbol * __cdecl sym_record_from_free_list_tail(int size_class, int arena_index, void * * free_cell, void * name);
c1_symbol * __cdecl decl_new_compiler_variable_inline_block(c1_symbol * func, c1_declarator * d, byte spec_byte0, byte storage, c1_type * type);
c1_symbol * __cdecl decl_new_compiler_variable_hoisted(byte storage, c1_type * type);
c1_node * __thiscall decl_finish_declarator_then_type(void * value, byte * spec);
void __cdecl decl_static_object_destructor_helper(c1_symbol * sym);
void __fastcall decl_process_declaration_member_type_block(c1_type * type, byte type_code, c1_declarator * d, int slot_c, char is_member, c1_u8 keyword_code);
void __fastcall decl_check_void_variable(c1_declarator * d, int slot_c, char is_member, c1_u8 keyword_code);
void __fastcall decl_check_abstract_class_object_block(c1_symbol * cls, c1_declarator * d, int slot_c, char is_member, c1_u8 keyword_code);
void __fastcall decl_check_variable_type(c1_symbol * cls, c1_declarator * d, int slot_c, char is_member, c1_u8 keyword_code);
void __fastcall decl_check_linkage_and_virtual(c1_symbol * ret_class, c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __fastcall decl_check_virtual_function(c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __fastcall decl_check_friend_context(c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __fastcall decl_check_member_storage_class(byte spec0, char had_error, c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __fastcall decl_check_function_storage_class(char had_error, c1_declarator * d, byte * spec_flags, int slot_c, char is_member);
void __fastcall decl_check_storage_class(char keyword, c1_declarator * d, byte * spec_flags, int slot_c, char is_member, c1_u8 keyword_code);
void __stdcall decl_check_parameter_storage_class(c1_declarator * d);
void __stdcall decl_check_export_linkage(undefined4 eax, c1_declarator * d);
void __stdcall typesym_check_declaration(undefined4 eax, c1_declarator * d);
c1_node * __cdecl decl_variable_initializer_fragment(int init, c1_node * alloc, c1_node * count_expr, c1_type * ptr_type, char is_array, char class_41_bit1_clear, char has_placement, c1_symbol * opnew, c1_symbol * cls, c1_node * iter_args, c1_node * iter_list, c1_node * iter_current, c1_node * iter_next, c1_type * ptr_type_cell, int elem_size, int temp_key, int cell_4c, int cell_54, c1_node * count_assign, c1_node * call_info, c1_node * call_info_4, int call_info_10, void * call_info_18, byte call_info_24, int cell_94, int cell_98, c1_symbol * cell_a4, c1_node * cell_ac, char kind, int placement);
void __cdecl decl_check_operator_function_block_a(c1_symbol * sym, int nparams, uint ndefaults);
void __cdecl decl_check_operator_function_block_b(int op, c1_symbol * sym, int nparams, uint ndefaults);
void __cdecl decl_check_operator_function_arrow_fragment(uint pointee_code, int count, c1_symbol * cls, c1_type * ret_type, c1_symbol * sym, int nparams, uint ndefaults);
void __cdecl decl_check_operator_params_tail(c1_symbol * sym, int nparams, uint ndefaults);
void __cdecl decl_check_operator_new_fragment(c1_symbol * sym, int nparams, uint ndefaults);
void __cdecl decl_define_variable(c1_symbol * sym);
c1_symbol * __cdecl decl_report_C2530_tail(c1_symbol * p3, c1_symbol * stand_in, void * name);
c1_symbol * __thiscall decl_declare_in_scope(char pop_scope, c1_symbol * prev, c1_declarator * d, c1xx_decl_specifiers * spec);
c1_symbol * __thiscall decl_check_extern_block_initializer(c1_symbol * sym, byte mask_8, c1_declarator * d, byte * spec);
c1_symbol * __thiscall decl_check_reference_initialized(byte type_code, c1_declarator * d);
c1_symbol * __thiscall decl_based_variable_tail(c1_symbol * sym, c1_declarator * d);
c1_symbol * __thiscall decl_note_namespace_owner_block(c1_symbol * cur_fn, c1_u8 * spec, c1_declarator * d, c1_symbol * cls);
c1_symbol * __thiscall decl_check_function_declaration(c1_u8 * spec, c1_declarator * d, c1_symbol * cls);
c1_symbol * __thiscall decl_check_auto_variable(c1_u8 * spec, c1_declarator * d, int kind3, c1_symbol * cls, char is_member);
c1_symbol * __thiscall decl_check_declspec_applicability(c1_u32 kind, c1_u8 * spec, c1_declarator * d, int kind3, char is_member);
c1_symbol * __thiscall decl_check_conversion_syntax_2(c1_u8 * spec, c1_declarator * d, char is_member);
c1_symbol * __thiscall scope_lookup_in_list_fragment(c1_u8 * spec, c1_declarator * d, int zero);
c1_symbol * __thiscall decl_declare_parameters(int scope_vector, c1_symbol * scope_sym, c1_u8 * spec, c1_declarator * d, uint cc_mask);
void __fastcall decl_check_const_auto_initialization(c1_declarator * d, c1_type * t, uint storage, c1_symbol * cls);
void __thiscall decl_check_linkage_consistency(c1_type * new_type, byte flags5_mask, c1_declarator * d, c1_symbol * sym);
void __thiscall decl_merge_attributes_fragment(c1_declarator * d, c1_symbol * sym, uint c4_bit_200);
void __thiscall decl_merge_attributes_fragment2(byte flags22, char changed, c1_symbol * sym, byte spec3);
void __thiscall decl_merge_attributes_tail_thread(byte flags23, c1_symbol * sym);
int __thiscall decl_resolve_declarator_type_fragment(int level, c1_type * old_type, c1_type * new_type, c1_declarator * d, c1_symbol * sym);
uint __cdecl symtab_hash_pointer_14(uint key);
int __cdecl symtab_equal_13(int a, int b);
void __cdecl symtab_15dc_insert(void * value, void * key);
c1_symbol * __cdecl sym_hiding_partner_link(c1_symbol * sym);
void * __cdecl sym_hiding_partner(void * key);
void __cdecl sym_new_segment_function(c1_symbol * segment);
c1_symbol * __cdecl sym_find_c_linkage_function(c1_symbol * sym);
void __cdecl sym_pair_table_insert(char local, c1_symbol * key, c1_symbol * first, void * second);
c1_symbol * __cdecl sym_lookup_pair_local_then_global(c1_symbol * key, uint * second);
c1_u8 * __cdecl sym_pair_new(void * first, void * second, int arena);
void * __cdecl sym_extra_record(c1_symbol * key);
void __cdecl sym_list_1b58_insert(c1_symbol * sym, int value);
void * __cdecl sym_list_1b58_lookup(c1_symbol * key);
int __cdecl sym_list_1b58_value(c1_symbol * key);
void __cdecl sym_set_or_clear_attribute(c1_symbol * sym, void * value);
void * __cdecl sym_get_attribute(c1_symbol * sym);
void __fastcall sym_note_reference_from_function(c1_symbol * func, c1_symbol * init_sym, c1_symbol * sym);
c1_symbol * __cdecl sym_new_dependent_name_placeholder(fe_name * name, char is_type);
c1_symbol * __fastcall sym_ensure_declarator_symbol(c1_declarator * d);
uint __fastcall decl_dll_linkage_kind(void * spec);
char * __cdecl sym_namespace_member_dotted_name(c1_symbol * sym);
char * __cdecl sym_format_scope_key_name(c1_symbol * sym, c1_symbol * scope_owner);
char * __cdecl sym_format_qualified_function_name(c1_symbol * sym, char * buf, uint size);
c1_type * __cdecl sym_word_14(c1_symbol * sym);
void __cdecl sym_set_or_clear_segment(c1_symbol * sym, int value);
void __cdecl sym_set_segment_checked(c1_symbol * sym, void * segment);
c1_decl_record * __thiscall decl_record_init_for_symbol(c1_decl_record * rec, c1_symbol * sym);
void __thiscall decl_append_derived_check_case80_fragment(c1_type * tail, int * rec, c1_type * layer);
void __thiscall decl_apply_declspec_based_fragment(c1_type * layer, int * rec, int zero);
void __thiscall decl_append_function_layer_modifiers_fragment(int * rec, c1_type * fn_layer, void * params, char chain_was_empty);
void __stdcall decl_check_modifier_over_reference_case80_fragment(c1_decl_record * rec, c1_type * layer);
void __fastcall decl_check_declarator_void_fragment(int * rec);
void __fastcall decl_finish_declarator_modifiers_fragment(byte storage_class, c1_decl_record * rec);
void __fastcall decl_scan_declarator_chain_reference_fragment(c1_type * chain_end, int rec, c1_type * layer);
void __cdecl decl_emit_prototype_text(c1_symbol * fn, FILE * out);
void __cdecl decl_emit_prototype_specifiers(c1_symbol_attrs attrs, FILE * out);
void * __cdecl decl_format_parameter_list(void * buf, c1_function_params * params, c1_type * fntype);
void __fastcall scope_pop_using_directives(c1xx_scope * scope);
void __fastcall hash_scope_make_table_and_push(void * scope);
void __thiscall ns_add_using_namespace(c1xx_hash_scope * scope, c1_namespace_symbol * ns, c1_namespace_symbol * skip);
void __thiscall using_list_deactivate(void * scope, int ns);
void __thiscall hash_scope_lookup_anonymous_member(c1xx_hash_scope * scope, void * name, c1_symbol * * result);
void __thiscall using_list_add(c1_using_cell * * list, c1_namespace_symbol * ns);
void __thiscall using_cell_release(void * list, int ns);
void __thiscall using_list_lookup_by_kind(c1_using_cell * * list, fe_name * name, uint mask, c1_u8 * found, c1_lookup_result * result);
void __thiscall using_list_lookup(c1_using_cell * * list, fe_name * name, c1_lookup_result * result);
c1_lookup_entry * __fastcall sym_new_kind1b(c1_lookup_result * result);
int __fastcall lookup_unique_symbol(void * result);
int __fastcall scope_parent_skipping_kind_fa(void * holder);
int * __cdecl scope_lookup_unique(int * scope, void * name);
int __cdecl hash_scope_entry_pick(int entry);
c1_symbol * __cdecl sym_chain_find_name(c1_symbol * sym, void * name);
c1_symbol * __thiscall scope_stack_lookup_anonymous_member(c1_scope_stack * scopes, void * name);
void __thiscall ns_enter_enclosing_namespaces(void * stack, c1_symbol * ns);
void __thiscall ns_propagate_using_directive(c1_scope_stack * stack, c1_namespace_symbol * ns, c1_namespace_symbol * nominated, c1_namespace_symbol * skip);
c1_lookup_entry * __thiscall lookup_namespace_in_enclosing_scopes(c1_scope_stack * stack, c1_namespace_symbol * ns);
void __stdcall ns_check_definition_scope(byte * sym, int scope);
void __cdecl sym_emit_deferred_list(int * list);
void __thiscall scope_link_unimplemented(c1xx_scope * scope, c1_symbol * sym);
void __thiscall scope_emit_il_unimplemented(void * this);
c1_u8 __fastcall hash_scope_has_usings(void * scope);
uint __stdcall sym_namemap_key(uint name_index);
uint __fastcall sym_assign_namemap_key(int * file_rec);
c1_u8 __cdecl sym_is_copy_constructor(c1_symbol * fn);
void __cdecl symtab_1b40_insert(c1_symbol * key, void * value);
void * __cdecl symtab_1b40_lookup(c1_symbol * key);
void * __thiscall decl_finish_declarator_uuidof(void * value, byte * spec);
void __thiscall sorted_list_insert(void * this, uint value);
void __thiscall sym_redeclaration_group_add(void * list, c1_symbol * sym);
void __cdecl sym_ensure_global_helper_function(void);
void __cdecl global_helper_name_decorated(char unique);
void __cdecl global_helper_name_plain(void);
void __stdcall sym_init_global_helper_name(void);
c1_symbol * __cdecl lookup_adl_result_symbol(c1_vector * vec);
c1_symbol_vector * __cdecl lookup_adl_in_namespace(c1xx_scope * scope, void * name, c1_symbol_vector * vec);
int __cdecl sym_is_kind_6_7_through_alias(c1_symbol * sym);
int __cdecl sym_is_member_function_via_alias(c1_symbol * sym);
void __cdecl scope_end_and_flush_pending_top(char end_scope);
int __cdecl base_path_has_seen_virtual_base(int * path, c1_symtab * seen);
c1_symbol * __thiscall sym_record_reuse_tail(int size_class, void * * free_cell, void * name, char ambiguous, int * result, int arena_index);
byte * __cdecl ns_define_namespace(void * name);
c1_symbol * __cdecl ns_new_namespace(fe_name * name, c1_u8 unnamed);
void __cdecl ns_end_definition(int ns_type);
byte * __cdecl sym_record_from_free_list_tail_2(int size_class, int arena_index, void * * free_cell, void * name, c1_type * list);
void __cdecl ns_using_directive(c1_symbol * target, fe_name * name, int depth, c1_u8 implicit);
void __cdecl ns_using_declaration(c1_symbol * sym);
c1_symbol * __cdecl symtable_ice_2(void * name, c1_symbol * sym, c1_symbol * qualified);
void __cdecl ns_member_using_declaration(byte * result);
void __cdecl ns_check_using_multiple_declaration(c1_symbol * sym, c1_symbol * qualified);
void __thiscall ns_define_alias(c1_declarator * target, fe_name * alias);
c1_u8 * __cdecl scope_pool_or_arena_alloc(uint n, int arena);
c1xx_hash_scope * __thiscall hash_scope_construct(c1xx_hash_scope * scope, c1_u32 mask, c1_u8 kind, c1xx_scope * parent);
int __cdecl symtab_hash_thunk_key_5(int * key);
int __cdecl symtab_equal_4_words(int * a, int * b);
int __cdecl sym_clone_return_null(void);
c1_symbol * __cdecl sym_clone_with_new_id(c1_thunk_key * thunk_key);
int __cdecl symtab_hash_pointer_pair_15(ushort * key);
int __cdecl symtab_equal_pointer_pair(int * a, int * b);
int __cdecl symtab_equal_vcall_key(int a, int b);
void * __cdecl symtab_16f4_lookup(void * key);
void * __cdecl symtab_16f8_lookup(void * key);
c1_symtab * __cdecl symtab_ensure_1704(void);
c1_symbol * __cdecl sym_purecall_symbol(void);
void __cdecl decl_check_redefinition_3(c1_sym_list * * template_params, c1_symbol * sym);
char __cdecl sym_names_function_template(c1_symbol * sym);
c1_lookup_result * __thiscall scope_lookup_by_kind_unimplemented(c1xx_scope * scope, void * name, uint mask, c1_u8 * found);
c1_lookup_result * __thiscall scope_lookup_unimplemented(c1xx_scope * scope, void * name, int mode);
c1_lookup_entry * __thiscall scope_lookup_tag_unimplemented(c1xx_scope * scope, void * name);

byte __cdecl diag_warning(int level, int n, ...);
void __cdecl diag_begin_global(int position);
void __thiscall diag_begin(c1_diag_context * ctx, int position);
void __cdecl diag_end_global(void);
int __fastcall diag_end(c1_diag_context * ctx);
void __thiscall diag_message_collect_args(void * this, int * id);
void __thiscall diag_format_message(c1_message * msg, c1_message_buffer * out);
void __stdcall diag_format_message_append_fragment(char * piece, c1_message_buffer * out, int index, c1_diag_format_frame * frame);
void __cdecl diag_extension_warning_or_error(int warning, int error, ...);
void __cdecl diag_write_stderr(char * text);
char * __cdecl diag_symbol_display_name(c1_symbol * sym);
void __cdecl diag_error_once_per_symbol(short n, c1_symbol * sym);
void __cdecl diag_error_C2296_or_C2297(c1_u8 op, int operand, c1_type * type);
void __stdcall _AbortCompilerPass@4(void);
void __cdecl diag_error(short n, ...);
void __cdecl diag_error_emit(short n, ...);
int __cdecl diag_fatal_file_errno(int n, int what, char * file);
void __cdecl diag_fatal_file_lasterror(int n, int what, char * file);
int __cdecl diag_fatal_file(int err, int n, int what, char * file);
__noreturn noreturn void __cdecl diag_fatal_simple(int n);
void __cdecl diag_write_fatal_C1063(char print_message);
__noreturn noreturn void __cdecl diag_fatal(int n, ...);
uint __cdecl diag_warning_is_enabled(uint level, int n);
void __cdecl diag_note_candidates(c1_symbol * sym, char * context);
void __cdecl diag_note(int n, ...);
void __fastcall diag_context_mark_warning(c1_diag_context * ctx);
void __thiscall diag_message_list_add(c1_diag_context * ctx, int kind, short number, char * args);
void __thiscall diag_format_report_line(c1_diag_context * ctx, c1_message_buffer * out, c1_message * msg);
void __fastcall diag_queue_print(c1_diag_context * ctx);
void __cdecl diag_write_line_stderr(char * line);
void __fastcall diag_queue_release_pending(int * queue);
void __fastcall diag_run_context_notes(c1_diag_context * ctx);
c1_message_buffer * __fastcall diag_message_buffer_new(c1_message_buffer * buf);
char __fastcall diag_message_buffer_grow(c1_message_buffer * buf);
void __fastcall diag_message_buffer_rewind(c1_message_buffer * buf);
msg * __stdcall diag_message_alloc(void);
void __cdecl diag_message_from_format(ushort * msg, char * format, ...);
void __thiscall diag_message_load(c1_message * msg, short kind, short number, char * args);
void __thiscall diag_message_collect_args_dollar_fragment(c1_message * msg, int * * ap, char * fmt, int index);
void __stdcall diag_format_message_body(byte * cursor, byte * literal, c1_message_buffer * out, c1_message * msg, int index, c1_diag_format_frame * frame);
void __stdcall diag_format_directive_fragment(char * piece, c1_message_buffer * out, c1_message * msg, int index, c1_diag_format_frame * frame);
void __thiscall diag_message_buffer_fill(int * buf, char c, uint n);
void __thiscall diag_message_buffer_append_n(int * buf, char * s, uint n);
c1xx_obj_104cb248 * __thiscall diag_elided_copy_constructor_note_init(c1xx_obj_104cb248 * note, c1_type * from, c1_type * to, c1_symbol * ctor);
void __fastcall diag_note_elided_copy_constructor(c1xx_obj_104cb248 * note);
void __fastcall diag_note_conversion_reason(c1_conversion * conv);
void __fastcall diag_note_followed_by_1(c1_conversion * conv);
void __fastcall diag_note_followed_by_2(c1_conversion * conv);
void __fastcall diag_note_overload_resolved(c1_conversion * conv);
void __fastcall diag_note_constructor_call(c1_conversion * conv);
void __fastcall diag_note_conversion_call(c1_conversion * conv);
void __fastcall diag_note_no_copy_constructor(c1_conversion * conv);
void __fastcall diag_note_conversion_record(c1_conversion * conv);

void __cdecl file_put_string_with_nul(char * text, FILE * file);
int __cdecl file_read_or_fatal(void);
void __fastcall source_tracker_stub_nop_2(void * tracker);
void __fastcall source_tracker_stub_nop_3(void * tracker);
int __cdecl file_read_source_block(void * buffer);
void __thiscall source_tracker_stub_nop_5(void * tracker, void * p, int n);
char __thiscall source_tracker_stub_true_1(void * tracker, int arg);
char * __cdecl file_make_canonical_path(char * out, char * file, uint size);
byte * __cdecl file_name_canonicalize(byte * name);
int __cdecl file_open_or_fatal(char * file, uint hash, int mode, int arg, int report);
int __thiscall file_record_find_canonical(void * scope, int name);
int __cdecl file_open_read_retry(char * file);
char * __cdecl file_name_for_FAT(char * file);
char __thiscall source_tracker_stub_true_0(void * tracker, int arg);
void __cdecl file_skip_header(HANDLE h, char * file_name);
void * __cdecl static_init_pch_image(void);
char __cdecl file_name_equal(byte * a, byte * b);
fe_file_record * __thiscall file_record_lookup_or_new(c1_scope_stack * scope, char * file, uint hash);
int __cdecl file_copy_contents(void * from, void * to, uint n);
void __cdecl file_write_or_fatal(FILE * f);
void __fastcall source_tracker_stub_delete(c1xx_obj_104c58e8 * tracker);
void __cdecl c1xx_cleanup(void);
void __cdecl text_buffers_free(void);
void __cdecl block_lists_free(void);
int __cdecl c1xx_run_exit_handlers(void);
void __cdecl c1xx_main_exit_handler(void);
int __stdcall _InvokeCompilerPass@12(int argc, char * * argv, char last_in_batch);
int __stdcall c1xx_reset_data_section(void);
void __cdecl static_init_token_save_frame(void);
void __cdecl static_init_token_source(void);
void __cdecl static_init_token_stream_queues(void);
void __cdecl static_init_instantiation_position(void);
void __cdecl static_init_il_db_buffer(void);
void __cdecl static_ctor_il_db_buffer(void);
int __cdecl c1xx_atexit(void * handler);
void __cdecl static_init_il_sy_buffer(void);
void __cdecl static_ctor_il_sy_buffer(void);
void __cdecl static_init_il_gl_buffer(void);
void __cdecl static_ctor_il_gl_buffer(void);
void __cdecl static_init_il_ex_buffer(void);
void __cdecl static_ctor_il_ex_buffer(void);
void __cdecl static_init_il_in_buffer(void);
void __cdecl static_ctor_il_in_buffer(void);
void __cdecl static_init_il_pending_init_buffer(void);
void __cdecl static_ctor_il_pending_init_buffer(void);
void __cdecl static_init_il_gi_buffer(void);
void __cdecl static_ctor_il_gi_buffer(void);
void __cdecl static_init_il_gi_fdef_buffer(void);
void __cdecl static_ctor_il_gi_fdef_buffer(void);
void __cdecl static_init_104de3b0(void);
void __cdecl static_ctor_104de3b0(void);
void __cdecl static_init_yylval_save(void);
void __cdecl static_init_options_signature(void);
void __cdecl static_init_pdb_state(void);
void __cdecl static_ctor_pdb_state(void);
void __cdecl static_init_pdb_state_2(void);
void __cdecl static_ctor_pdb_state_2(void);
void __cdecl static_init_pool_104dce50(void);
void __cdecl static_init_pool_104dce40(void);
void __cdecl static_init_pool_104dce30(void);
void __cdecl static_init_pool_104dce20(void);
void __cdecl static_init_pool_104dce10(void);
void __cdecl static_init_name_pool(void);
void __cdecl static_init_pool_104dcdf0(void);
void __cdecl static_init_pool_default(void);
void __cdecl static_init_scope_pool(void);
void __cdecl static_init_pool_104dcdc0(void);
void __cdecl static_init_char_tables(void);
char __cdecl static_ctor_char_tables(void);
void __cdecl static_init_format_template_args(void);
void __cdecl static_init_msvcrt_handle(void);
void __cdecl static_ctor_msvcrt_handle(void);
void __cdecl static_init_undname(void);
void __cdecl static_init_position_104e33d8(void);
void __cdecl idb_clear_empty_class_record(void);
void __cdecl static_init_104e47b0(void);
void __cdecl static_init_header_banner(void);
void __cdecl static_ctor_header_banner(void);
void __cdecl static_init_deferred_actions(void);
int __cdecl c1xx_main_guarded(int argc, char * * argv);
int __cdecl c1xx_main(int argc, char * * argv);
void __cdecl opt_prescan_memory_switches(char * * argv);
char * __cdecl opt_prescan_Bm_ZB_Zm(char * word, char * pending);
void __cdecl c1xx_main_stub(void);
void __cdecl opt_parse_command_line(int argc, char * * argv);
void __cdecl crc16_tables_init(void);
void __cdecl file_name_case_table_init(void);
void __cdecl opt_parse_switch_string(byte * s);
char * __cdecl option_next_argument(void);
int __cdecl opt_match_switch(c1_switch_row * table, char * word, void * next_arg, int dup);
void __cdecl opt_set_switch_value(c1_switch_row * row, char * value, int dup);
int __cdecl opt_match_suffix(char * pattern, char * word);
long __cdecl opt_parse_number(char * text);
int __cdecl c1xx_compile(void);
void __cdecl c1xx_compile_begin(void);
char __cdecl source_tracker_new(char incremental, void * * tracker, void * * iface);
void __cdecl opt_set_target_cpu_mask(void);
c1_u8 * __cdecl cwd_string(void);
void __cdecl compile_begin_stub_a(void);
void __cdecl compile_begin_stub_b(void);
void __cdecl c1xx_new_builtin_labels(void);
void __cdecl opt_unpack_optimize_flags(int flags);
uint __cdecl file_mtime_or_zero(int fd);
bool __cdecl guid_parse_string(char * text, c1_guid * guid);
uint __cdecl opt_float_consistency_enabled(void);
void __cdecl file_skip_header_2(void * h, int arg);
int __cdecl fpu_store_constant_rounded(float10 value, float10 * out);
void __cdecl fpu_store_st0_tbyte_esi(float10 value, float10 * out);
int __cdecl fpu_compare_abs(float10 limit, float10 value);
c1_u8 __cdecl file_current_at_eof(void);
long __cdecl file_tell_current_source(void);
long __cdecl file_seek_current_source(long offset);
char * __cdecl path_make_default_pch_name(char * path);
ulong __cdecl opt_parse_number_2(char * item);
char * * __cdecl opt_check_switch_count(void);
int __cdecl file_mtime_of_handle(int fd, int * mtime);
char * __cdecl file_copy_name_canonical(char terminator, char * file, char * out);
char * __cdecl path_make_relative(char * out, char * base_dir, char * path, size_t size);
void __cdecl opt_resolve_pch_switches(char * yc_header, char * yu_header, int zero);
byte * __cdecl opt_check_switch_length(byte * s, byte * out, int size);
void __cdecl c1xx_abort_cleanup(void);
void __cdecl c1xx_abort_if_running(void);
void __cdecl c1xx_set_phase(int phase);
__noreturn noreturn void __cdecl c1xx_raise_exit(uint code);
uint __cdecl file_mtime(char * file);
char * __cdecl misc_string_find(int id);
void __cdecl misc_strings_load(void);
char * __cdecl misc_string_get(int id);
char __thiscall source_tracker_stub_iface_false_0(void * iface, uint * signature, int * count);
char __thiscall source_tracker_stub_iface_false_1(void * iface, int n, uint * signature, int * count);
char __thiscall source_tracker_push(c1xx_source_tracker * tracker, int arg);
char __thiscall source_tracker_pop(c1xx_source_tracker * tracker, int arg);
void __fastcall source_tracker_mark(c1xx_source_tracker * tracker);
void __fastcall source_tracker_accumulate(c1xx_source_tracker * tracker);
void __fastcall source_tracker_delete(c1xx_source_tracker * tracker);
char __thiscall source_tracker_take(c1xx_source_tracker_iface * iface, uint * signature, int * count);
char __thiscall file_tell_seek_or_fatal(c1xx_source_tracker_iface * iface, int n, uint * signature, int * count);
void __thiscall source_tracker_add_bytes(c1xx_source_tracker * tracker, void * p, int n);
void __fastcall source_tracker_reset(c1xx_source_tracker_iface * iface);
int * __thiscall file_record_find(void * scope, int name);
void * __cdecl guid_format(char * format, c1_guid * guid);
void * __cdecl guid_format_registry(void * guid);
fe_name * __cdecl guid_format_symbol_name(c1_guid * guid);
int __cdecl fpu_store_float_if_in_range(float10 * value, float * out);
int __cdecl fpu_store_float_constant(float * value, c1xx_float_const * out);
float10 __cdecl fpu_round_st0(float10 value);

longlong __cdecl expr_eval_constant_expression(c1_node * node);
int __cdecl fold_add_overflows(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
c1_symbol * __cdecl expr_resolve_overload_set_member(c1_symbol * sym, c1_symbol * decl);
c1_node * __cdecl tree_new_constant(c1_type * type, void * value, int arena);
c1_node * __cdecl expr_resolve_address_of_overload(c1_node * node);
c1_node * __cdecl expr_warn_no_effect(c1_node * expr, char statement);
c1_node * __cdecl fold_static_const_member(c1_node * node);
c1_node * __cdecl tree_new_node(c1_u8 op, c1_node * left, c1_node * right, c1_type * type);
c1_keyed_list * __cdecl tree_new_list_cell(c1_keyed_list * list, int key, c1_symbol * sym);
int __cdecl expr_fold_string_intrinsic(c1_node * call);
c1_node * __cdecl tree_new_value_constant(c1_symbol * sym);
c1_node * __cdecl expr_build_builtin_unary(uint op, c1_node * operand);
c1_node * __cdecl tree_new_unary(c1_u8 op, c1_type * type, c1_node * operand);
c1_node * __cdecl expr_lookup_name_expression(void * name);
c1_node * __cdecl expr_reference_named_entity(c1_symbol * sym, int in_class_scope);
c1_node * __cdecl conv_convert_expression(c1_u8 op, c1_type * target, c1_node * node, c1_u8 mode, c1_u8 flags);
void __fastcall conv_compute_conversion(c1_conversion * conv);
c1_node * __thiscall conv_apply_conversion(c1_conversion * conv, c1_node * node);
c1_node * __cdecl tree_append_list_item(c1_node * list, c1_node * item, int flag);
void __fastcall conv_rule_integral_to_integral(c1_conversion * conv);
char __fastcall conv_constant_warnings_enabled(c1_conversion * conv);
c1_node * __thiscall conv_build_integral_constant(c1_conversion * conv, c1_node * dest);
int __cdecl conv_constant_out_of_range(uint size, int target_unsigned, int source_unsigned, uint lo, uint hi);
ulonglong __cdecl conv_cast_constant(byte op, c1_node * k, c1_type * target);
int __cdecl expr_build_unary(uint node2, c1_node * list);
void __cdecl tree_clear_value_link(c1_node * node);
char __cdecl expr_check_operand_type_illegal(c1_u8 op, c1_type * type);
c1_type * __cdecl expr_check_based_void_pointer(c1_type * type);
void __thiscall conv_compare_level_qualifiers(c1_conversion * conv, c1_type * to, c1_type * from, char outer_const);
c1_node * __cdecl expr_lvalue_address(c1_node * e, uint mode);
c1_node * __thiscall conv_build_identity(c1_conversion * conv, c1_node * dest);
void __fastcall conv_rule_enum_to_pointer(c1_conversion * conv);
void __fastcall conv_rule_integral_to_pointer(c1_conversion * conv);
int __cdecl expr_check_illegal_for_type(c1_u8 op, int arity, c1_node * left, c1_node * right);
c1_node * __cdecl expr_build_binary(c1_u8 op, c1_node * left, c1_node * right);
void __cdecl tree_list_arena_set(int arena);
void __cdecl tree_list_arena_restore(void);
c1_node * __cdecl expr_build_builtin_binary(c1_u8 op, c1_node * left, c1_node * right);
c1_node * __cdecl expr_build_builtin_binary_pointer_add(c1_type * ptr_type, int swapped, c1_type * other_type, c1_node * node, c1_u8 op, c1_node * right);
c1_node * __cdecl expr_build_builtin_binary_bitwise_case(c1_node * node, uint op, c1_node * left_orig, uint op_index, c1_node * right_orig, c1_node * left, c1_node * right);
void __cdecl conv_apply_integral_promotion_2(c1_node * * left, c1_node * * right);
c1_type * __cdecl conv_integral_promotion_target(c1_type * other, c1_node * * operand);
c1_type * __cdecl conv_usual_arithmetic(c1_u8 op, c1_type * left, c1_type * right);
c1_node * __cdecl fold_binary_constants(c1_node * node, c1_node * left, c1_node * right);
c1_node * __cdecl fold_float_arithmetic_set_flag_fragment(byte left_code, byte right_code, c1_type * left_type, c1_node * right_const, c1_node * left_const, char long_result, c1_u8 op, uint left_size, c1_type * right_type, uint right_size, int right_hi, c1_node * node, c1_type * result_type);
c1_node * __cdecl fold_binary_constants_integer_part(uint op_index, int is_unsigned, c1_node * left_const, c1_node * right_const, char long_result, uint size, c1_u8 op, uint left_size, uint op_word, uint right_size, int right_hi, c1_node * node, c1_type * result_type, int is_unsigned_copy);
c1_node * __cdecl fold_binary_constants_tail(c1_type * type);
char __cdecl expr_check_member_pointer_operand(c1_node * node);
void __fastcall conv_rule_reference_target(c1_conversion * conv);
void __fastcall conv_bind_reference(c1_conversion * conv);
void __cdecl conv_bind_reference_to_rvalue(c1_conversion * conv, c1_type * ref_type, c1_symbol * source_class, char related, int ref_category, c1_symbol * ref_class);
void __fastcall conv_rule_converting_constructor(c1_conversion * conv);
c1_node * __cdecl expr_apply_overloaded_operator(c1_u8 op, c1_node * left, c1_node * right, uint flag4, uint report, byte * failed);
c1_node * __cdecl expr_apply_overloaded_operator_body(char op_byte, uint op, c1_node * left, c1_type_chain_cell * chain_tail, c1_type_chain_cell * chain_head, char frame_empty, char frame_op, c1_node * frame_right, uint op_slot, c1_symbol * left_cell, c1_node * right, uint flag4, uint report, byte * failed);
c1_node * __cdecl expr_build_selected_operator(int * winner, c1_node * left, c1_node * right);
c1_symbol * __cdecl expr_find_base_symbol(c1_node * node);
char __thiscall conv_find_base_class_path(c1_conversion * conv, c1_symbol * source_class, c1_symbol * target_class, char flag);
c1_node * __cdecl expr_build_address_of(c1_node * e, uint mode);
int __cdecl expr_is_adjusted_this(c1_node * node);
c1_node * __cdecl expr_find_lvalue_symbol_node(c1_node * node);
bool __cdecl expr_builtin_operator_valid_for_class(byte op, char arity, int class_on_left);
void __fastcall conv_rule_conversion_function(c1_conversion * conv);
c1_node * __cdecl expr_convert_operands_to_common_type(c1_node * node, c1_node * left, c1_node * right);
c1_type * __cdecl conv_check_conditional_operands(c1_u8 op, c1_node * * a, c1_node * * b);
void __cdecl expr_check_operand_conversion_unless_null(uint op, c1_node * left, c1_node * right);
int __cdecl conv_check_conversion_to_type(uint op, c1_type * target, c1_node * e);
int __cdecl expr_check_void_in_conditional_return(int result);
int __cdecl conv_check_assignment_compatibility(uint op, c1_type * target, c1_type * source);
void __cdecl conv_warn_possible_loss_of_data(uint op, c1_node * e, c1_type * target);
void __cdecl conv_warn_possible_loss_of_data_fragment_ecx(ushort target_code, char opt_J_unsigned_char, uint const_hi, uint const_lo, c1_type * target, uint op, c1_type * source_type);
void __cdecl conv_warn_possible_loss_of_data_fragment_eax(int source_unsigned, uint const_hi, uint const_lo, c1_type * target, uint op, c1_type * source_type);
c1_node * __cdecl expr_build_cast(c1_u8 op, c1_symbol * type_id, c1_node * node);
c1_node * __cdecl conv_convert_cast(c1_u8 op, c1_type * target, c1_node * node);
c1_node * __thiscall conv_build_to_bool(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_build_null_pointer(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_store_converted_value(c1_conversion * conv, c1_node * dest, c1_node * value);
c1_node * __cdecl expr_build_member_access(c1_u8 op, c1_node * obj, c1_node * name);
c1_node * __cdecl expr_access_checked_member(uint op, c1_node * obj, c1_symbol * member, int sign, c1_type * type);
c1_node * __cdecl expr_member_offset(uint op, c1_node * obj, int * path, char sign, c1_type * type);
c1_node * __cdecl tree_new_offset(c1_node * left, int value, c1_type * type);
c1_node * __thiscall expr_prepare_member_access_object(c1_scope_stack * scope, char op, c1_node * object, char no_arrow);
int __cdecl expr_member_call_object_known(c1_node * access);
void __cdecl expr_set_overload_target_and_check_access(c1_symbol * sym, int target);
c1_node * __cdecl expr_adjust_this_for_member_call(c1_node * obj, c1_symbol * fn, c1_symbol * qualifier, int * path);
c1_node * __cdecl expr_bound_member_function(c1_symbol * fn, c1_node * obj, c1_node * args);
char * __cdecl expr_address_of_through_casts(c1_node * node);
c1_type * __fastcall conv_operand_type_for_common_type(c1_type * type);
void __fastcall conv_rule_pointer_to_integral(c1_conversion * conv);
c1_node * __cdecl expr_build_conditional(c1_node * node, c1_node * node2, c1_node * node3);
c1_node * __cdecl expr_check_type_as_expression_4(uint op, c1_node * node);
char __cdecl expr_full_expression_in_eh_state(uint flags);
char __cdecl expr_member_lookup_return_false(void);
byte __cdecl expr_warn_bool_mix(c1_node * left, c1_node * right, byte op);
c1_node * __cdecl expr_build_sizeof(c1_node * operand);
int __cdecl expr_build_generated_operator_delete_call(c1_node * p, char is_array);
void __cdecl tree_attach_typed_link(c1_node * n, c1_type * type);
int __cdecl expr_finish_full_expression(int tree);
c1_value_cell * __cdecl expr_take_pending_destructor_list(void);
void __cdecl expr_collect_temporary_leaves(int * list, c1_node * node);
void __cdecl expr_count_evaluated_operator(void);
c1_node * __cdecl expr_build_this(c1_symbol * this_param);
c1_node * __cdecl expr_this_pointer(c1_symbol * sym);
c1_node * __cdecl tree_copy_to_arena(c1_node * src, int arena);
c1_node * __stdcall expr_check_this_usage(void);
c1_node * __cdecl tree_append_expression_list_item(c1_node * right, c1_node * node);
c1_node * __cdecl expr_check_member_reference_context(c1_symbol * sym, byte * sym2);
char __thiscall tree_has_side_effects(c1_tree_visitor * visitor, c1_node * node);
uint __stdcall tree_node_has_side_effect(c1_node * node);
c1_node * __cdecl expr_build_call_of(c1_symbol * fn, c1_symbol * cls, c1_node * object, c1_node * args, char emit, int dtor_kind, char register_dtor);
int __cdecl expr_build_constructor_call(c1_symbol * cls, c1_node * obj, int args, char emit, char keep_vbase_flag);
c1_node * __cdecl tree_new_deleting_dtor_flags_arg(int kind, char do_delete);
c1_node * __cdecl expr_build_destructor_call(c1_symbol * cls, c1_node * obj, int kind, int flag, int do_delete);
c1_node * __cdecl expr_build_eh_state_update(c1_node * left, c1_node * right, c1_symbol * sym);
c1_node * __cdecl tree_new_binary_typed_right(c1_u8 op, c1_node * left, c1_node * right);
c1_node * __cdecl tree_new_node_with_fields(c1_u8 op, ushort unwind_count, void * state, ushort marker_flags);
c1_node * __thiscall conv_build_base_pointer(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_convert_along_base_path(c1_conversion * conv, c1_node * obj);
c1_node * __cdecl tree_new_offset_cast(c1_node * left, int value, c1_type * type);
c1_node * __cdecl tree_new_cast(c1_type * type, c1_node * operand);
void __fastcall conv_rule_void_target(c1_conversion * conv);
c1_node * __cdecl expr_this_plus_offset(int sym2, int qualifiers, int value);
int __cdecl tree_is_this_read(c1_node * node);
int __cdecl conv_check_copy_conversion(c1_node * target, c1_node * source);
c1_u8 * __thiscall expr_build_member_access_implicit(c1_scope_stack * scope, void * name);
void __fastcall conv_rank_implicit_object_exact(c1_conversion * conv);
char __thiscall conv_constructor_ice_check(c1_conversion * conv, c1_conversion * seq);
c1_node * __thiscall conv_build_conversion_function_call(c1_conversion * conv, c1_node * dest);
int __thiscall conv_compare_sequences_2(c1_conversion * conv_a, c1_conversion * conv_b, char source_side);
c1_node * __cdecl tree_new_leaf_9c(int entity, c1_type * type);
int __cdecl conv_apply_integral_promotion(c1_type * type, c1_node * node);
c1_node * __cdecl expr_construct_result_in_place(c1_symbol * ctor, c1_node * object, c1_node * source);
char __cdecl expr_find_result_temporary(c1_node * expr, c1_node * * found);
void __fastcall conv_rule_array_to_array(c1_conversion * conv);
c1_node * __cdecl expr_build_class_operator_delete_call(c1_symbol * delete_set, c1_node * pointer, c1_symbol * cls);
c1_node * __thiscall conv_build_same_class(c1_conversion * conv, c1_node * dest);
char __cdecl expr_build_constructor_reference(c1_node * callee);
c1_node * __thiscall conv_build_base_reference(c1_conversion * conv, c1_node * dest);
void __thiscall conv_check_nonlvalue_to_reference(c1_conversion * conv, c1_type * type, char is_target);
c1_node * __thiscall conv_build_bind_class_rvalue(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_build_converting_constructor(c1_conversion * conv, c1_node * dest);
void __cdecl tree_list_cache_tail(c1_node * node);
c1_node * __thiscall conv_register_target_destructor(c1_conversion * conv, c1_node * dest, c1_node * call);
c1_node * __stdcall expr_new_reference_temporary(c1_type * type);
char __thiscall conv_pointer_levels_dissimilar(c1_conversion * conv, c1_type * to, c1_type * from, char top_level);
char __stdcall conv_pointer_levels_dissimilar_return_true(void);
void __cdecl conv_rule_reference_target_return(void);
c1_node * __thiscall conv_build_reference_cast(c1_conversion * conv, c1_node * dest);
uint __cdecl fold_check_multiply_overflow(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
void __fastcall conv_rule_function_pointer_to_function_pointer(c1_conversion * conv);
void __fastcall conv_rule_array_source(c1_conversion * conv);
c1_node * __thiscall conv_build_decayed_conversion(c1_conversion * conv, c1_node * dest);
int __thiscall conv_compare_sequences(c1_conversion * conv_a, c1_conversion * conv_b, int source_side);
int __thiscall conv_compare_class_derivation(char flip, c1_symbol * class_a, c1_symbol * class_b);
c1_type * __cdecl conv_array_to_pointer_type(c1_node * node);
c1_node * __cdecl fold_float_conversion(c1_u8 op, c1_type * t, c1_node * node);
uint __cdecl fold_check_subtract_overflow(uint a_lo, int a_hi, uint b_lo, int b_hi, int is_unsigned, uint size);
void __fastcall conv_rule_pointer_to_function_pointer(c1_conversion * conv);
c1_node * __cdecl tree_new_int_constant(int value);
c1_node * __cdecl tree_new_int_constant_raw(int value);
c1_node * __cdecl tree_new_symbol_ref(c1_symbol * sym, char use_type);
c1_node * __cdecl tree_new_binary(c1_u8 op, c1_node * left, c1_node * right);
c1_node * __cdecl tree_new_three_fields_flagged(uint lo, int hi, int size);
c1_node * __cdecl tree_new_sized_int_constant(uint lo, int hi, int size);
void __cdecl expr_reset_shared_temporary(void);
c1_node * __cdecl expr_member_value(c1_symbol * sym, c1_node * n);
c1_node * __cdecl tree_new_rvalue(c1_node * n);
void __fastcall conv_rule_pointer_to_pointer(c1_conversion * conv);
c1_node * __thiscall conv_apply_standard_conversion(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl expr_condition_guarded(c1_node * node, int want_value);
c1_node * __cdecl expr_unwind_actions(c1_node * left);
c1_node * __cdecl expr_unwind_actions_return_arg(byte * frame);
c1_node * __cdecl expr_unwind_actions_tail(c1_node * result, byte * frame);
int __cdecl expr_build_call(c1_node * callee, c1_node * args);
int __cdecl expr_count_call_arguments(c1_node * node2);
c1_node * __cdecl expr_build_call_node(c1_symbol * sym, c1_node * left, int args, int conversions, int argc, int nonvirtual);
c1_node * __cdecl expr_build_call_with_temporaries(c1_node * node, c1_symbol * fn, ushort ret_code);
c1_node * __cdecl expr_sizeof_type(c1_type * type);
c1_node * __cdecl expr_resolve_function_address(c1_type * target, c1_node * node);
uint __cdecl expr_refers_to_local_variable(c1_node * node);
c1_node * __cdecl tree_strip_casts_and_segment_bases(c1_node * node);
c1_node * __thiscall conv_build_integral_conversion(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl expr_check_binary_operand_types(c1_node * node);
c1_node * __cdecl expr_check_pointer_arithmetic_zero_edx_fragment(c1_node * left, char opt_J, c1_node * right, c1_type * left_type, c1_node * right_cell, c1_node * left_cell, uint op_cell, c1_type * right_type, int op_code, c1_node * node);
c1_node * __cdecl expr_check_binary_operand_types_signed_compare(char left_signed, c1_node * left, c1_node * right, c1_type * left_type, c1_node * right_cell, c1_node * left_cell, uint op_cell, c1_type * right_type, int op_code, c1_node * node);
c1_node * __cdecl expr_full_expression_guarded(c1_node * node, uint flags);
int __cdecl expr_apply_implicit_conversion(c1_node * node);
void __fastcall conv_rule_impossible(c1_conversion * conv);
c1_node * __thiscall conv_build_reference_binding(c1_conversion * conv, c1_node * dest);
void __thiscall operator_id_set(c1_decl_modifier * mod, short bits, void * based);
byte __cdecl expr_is_zero_constant(c1_node * node);
void __fastcall conv_rule_integral_to_enum(c1_conversion * conv);
void __fastcall conv_rule_class_to_class(c1_conversion * conv);
c1_node * __cdecl expr_build_new(char kind, int placement, c1_symbol * type_sym, int init, c1_node * args, int bound);
c1_node * __cdecl tree_new_unsigned_constant(int value);
c1_node * __cdecl expr_build_new_initializer(char may_be_null, char vptr_stores, c1_symbol * cls, c1_node * object, c1_node * args, c1_symbol * target);
c1_node * __cdecl expr_assignment_as_lvalue(c1_node * left);
char * __cdecl tree_find_template_parameter_use(char * node);
void __fastcall conv_rule_function_name_to_pointer(c1_conversion * conv);
c1_node * __cdecl expr_strip_to_function_ref(c1_node * node, uint * how);
c1_node * __thiscall conv_build_resolved_function_address(c1_conversion * conv, c1_node * dest);
void __cdecl expr_make_reusable(c1_node * * copy, c1_node * * expr);
c1_node * __cdecl expr_build_null_guarded(c1_node * ptr, c1_node * expr);
c1_node * __cdecl expr_spill_to_temporary(c1_node * * expr);
c1_node * __cdecl expr_build_new_or_placeholder(char kind, int placement, c1_symbol * type_sym, int init, int bound);
c1_node * __cdecl tree_new_comma(c1_node * left, c1_node * right);
c1_node * __cdecl expr_spill_for_eh_state(c1_node * value);
char __stdcall expr_call_needs_eh_cleanup(c1_node * expr);
void __fastcall expr_call_info_decode_callee(c1_call_record * info);
c1_symbol * __cdecl expr_select_operator_new(int * name, int arg_types, c1_symbol * cls);
c1_node * __fastcall expr_new_build_call_node(void * call);
void __cdecl expr_new_mark_eh_state(void);
c1_node * __cdecl expr_build_delete(char kind, c1_node * operand, c1_node * bound, char is_array);
c1_node * __cdecl expr_string_literal(c1_node * node);
int __cdecl expr_string_pooling_enabled(void);
void __fastcall conv_rule_integral_to_ellipsis(c1_conversion * conv);
void __fastcall conv_rule_pattern_target(c1_conversion * conv);
c1_node * __thiscall conv_build_pattern_operand(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl expr_lvalue_through_both_arms(c1_node * src, uint mode);
void __cdecl operator_names_init(void);
c1_node * __cdecl expr_address_of_member(c1_symbol * sym);
void __fastcall conv_rule_integral_to_member_pointer(c1_conversion * conv);
c1_node * __thiscall conv_build_null_member_pointer(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl expr_member_pointer_null_constant(c1_type * type);
c1_node * __cdecl expr_null_member_pointer_value(c1_type * type);
c1_node * __cdecl tree_new_null_member_pointer(c1_type * type);
c1_node * __cdecl expr_member_pointer_cast(c1_type * type, c1_node * node, c1_node * right2);
void __fastcall conv_rule_compound_to_ellipsis(c1_conversion * conv);
c1_node * __thiscall conv_build_member_pointer_along_base_path(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl pm_convert_along_base_path(c1_node * expr, c1_type * target, c1_symbol * base_path, char keep_sign);
byte __cdecl member_path_offset(int * path, int * vbase, int * offset);
byte __cdecl member_path_offset_tail(byte result);
char __thiscall conv_function_cast_is_unsafe(c1_conversion * conv, c1_type * from, c1_type * to, char strict);
char __stdcall conv_function_cast_is_unsafe_parameters(c1_type_list * from_params, c1_type_list * to_params, int count, c1_conversion * conv);
char __stdcall conv_function_cast_is_unsafe_return_false(void);
c1_node * __fastcall conv_build_class_argument_in_slot(c1_conversion * conv);
c1_node * __cdecl tree_new_argument_slot_intrinsic(c1_type * type, int size, c1_node * slot);
c1_node * __cdecl tree_new_node_typed(c1_u8 op, void * left, c1_type * type);
void * __cdecl vcall_thunk_lookup_or_new(c1_symbol * member);
c1_vcall_thunk_key * __cdecl vcall_thunk_key_new(c1_symbol * member, int arena);
c1_node * __cdecl expr_build_array_new_construction(c1_node * ptr, char may_be_null, int vptr, int cookie, c1_node * count, int elem_size);
c1_node * __cdecl expr_build_vector_ctor_iterator_call(c1_node * array, int size, c1_node * count, int no_closure);
c1_node * __cdecl expr_default_ctor_reference(c1_type * type, char vector_form);
c1_node * __cdecl expr_destructor_address(c1_type * type);
c1_node * __cdecl expr_build_helper_call_4(c1_node * item, int value, c1_node * item2, c1_node * item3, c1_node * item4, c1_node * left);
c1_node * __cdecl expr_array_destroy_elements(c1_node * array);
c1_node * __cdecl expr_build_vector_dtor_call(c1_node * array, int elem_size, c1_node * count, c1_type * type);
int __cdecl intrinsic_lookup_by_name(fe_name * name);
void __fastcall conv_rule_floating_to_floating(c1_conversion * conv);
void __thiscall conv_warn_possible_loss_of_data_2(void * this, undefined4 node);
void __fastcall conv_rule_integral_to_floating(c1_conversion * conv);
void __fastcall conv_rule_floating_to_integral(c1_conversion * conv);
int __cdecl intrinsic_is_enabled(int index);
void __cdecl intrinsic_mark_function(c1_symbol * sym, int index);
c1_node * __cdecl tree_new_default_arg_key_list(c1_node * tree, void * keys);
c1_node * __cdecl tree_copy_replacing_temporary(c1_node * tree, int temp_key, c1_node * src, int eh_state);
c1_node * __thiscall conv_build_integral_constant_to_floating(c1_conversion * conv, c1_node * dest);
void __cdecl conv_warn_float_truncation_1(uint op, c1_node * e, c1_type * target, c1xx_float_const * out, char warn);
uint __cdecl float_const_from_string(char * text, c1xx_float_const * out);
int __cdecl fold_float_to_double_checked(byte * value, double * out);
int __cdecl float_const_set_double(double * value, c1xx_float_const * out);
c1xx_float_const * __thiscall conv_float_constant_for_target(c1_conversion * conv, c1xx_float_const * value);
void __cdecl conv_warn_float_truncation_2(byte op, c1_node * node, c1_type * target);
c1_node * __thiscall conv_build_integral_to_floating(c1_conversion * conv, c1_node * dest);
int __cdecl float_const_compare_mask(ushort mask, void * a, void * b);
void __thiscall conv_warn_possible_loss_of_data_3(void * this, undefined4 node);
void __fastcall conv_rule_floating_to_ellipsis(c1_conversion * conv);
c1_node * __cdecl fold_float_constant(c1_node * node, void * a, void * b);
undefined4 __cdecl float_fold_multiply_constants(float10 * a, float10 * b, float10 * out);
int __cdecl fold_float_store_result_3(c1_u8 * a, c1_u8 * b, c1_u8 * out);
void __fastcall conv_rule_reference_source(c1_conversion * conv);
c1_node * __cdecl expr_member_access_via_vbase(uint op, c1_node * object, int * path, c1_type * type, int member_offset);
c1_node * __cdecl expr_member_offset_access(uint op, c1_node * node, c1_type * type, int offset, int slot, int offset2, c1_type * vbtable_type);
int __cdecl conv_check_pointer_qualifiers(uint op, ushort target_quals, ushort source_quals, int rank_flag);
void __fastcall conv_rule_function_name_source(c1_conversion * conv);
void __fastcall conv_rule_function_pointer_to_pointer(c1_conversion * conv);
void __cdecl tree_new_type_token_node(c1xx_token * token, c1_type * type);
int __cdecl tree_zero_second_operand(int node);
c1_node * __thiscall conv_build_reference_temporary(c1_conversion * conv, c1_node * dest);
char * __cdecl tree_new_from_token(byte * next_token, char * token);
c1_u8 * __cdecl expr_lookup_identifier_tail(c1_u8 * token);
c1_type * __cdecl tree_new_scope_chain_list(int sym);
int __cdecl fold_float_to_int64_checked(void * value, c1_u32 * out);
c1_node * __cdecl expr_based_pointer_fixup(c1_node * node);
bool __cdecl expr_same_based_base(c1_node * a, char * b);
int __cdecl expr_find_based_base(c1_node * node);
c1_node * __cdecl tree_new_string_literal(char * text);
c1_node * __thiscall conv_warn_negative_to_unsigned(void * this, undefined4 ebx, c1_node * node);
c1_node * __stdcall fold_float_constant_logical_and(void);
c1_node * __cdecl conv_report_inaccessible_conversion(uint op, c1_node * obj, uint op_byte, c1_type * type, int * path, int sign);
c1_node * __cdecl expr_virtual_base_offset(c1_node * left, int vbptr_offset, int slot, c1_type * vbtable_type);
c1_node * __cdecl expr_member_access_via_vbase_spilled(uint op, c1_node * object, c1_type * type, int vbptr_offset, int vbase_slot, int member_offset, c1_type * vbtable_type);
c1_node * __cdecl expr_check_qualified_pseudo_destructor(c1_u8 op, c1_node * object, c1xx_decl_specifiers * scope_type, c1xx_decl_specifiers * dtor_type);
c1_node * __cdecl expr_build_pseudo_destructor_call(char op, c1_node * node, int name);
c1_symbol * __cdecl expr_lookup_pseudo_destructor_name(fe_name * name, c1_symbol * cls);
c1_node * __cdecl expr_build_member_access_select(c1_symbol * member, c1_type * obj_type, c1_node * obj, c1_symbol * member_local, int result_kind_0x20, int obj_is_address, c1_type * obj_type_local, c1_type type_desc, c1_u8 op, c1_symbol * name_sym, c1_node * name);
int __cdecl expr_build_call_return_null(void);
c1_node * __cdecl expr_check_call_context_tail(c1_node * vfptr, c1_node * thisarg, c1_symbol * sym, c1_node * call, char object_first, void * visitor_vtable, int visitor_mask, c1_node * object, int nonvirtual);
c1_node * __cdecl expr_build_call_with_temporaries_retype(c1_symbol * fn, c1_node * node, c1_type * ret_type);
c1_node * __cdecl expr_build_call_with_temporaries_based_return(c1_symbol * fn, c1_node * node);
c1_node * __cdecl expr_check_rvalue_operand(c1_node * node);
c1_node * __cdecl tree_strip_address_of(c1_node * node);
c1_node * __cdecl expr_member_function_address_for_type(c1_type * type, int sym);
c1_node * __cdecl expr_report_function_operand(c1_u8 op, c1_node * node);
c1_node * __cdecl expr_strip_value_conversions_check_name(byte mark, c1_node * node, c1_node * operand);
c1_node * __stdcall expr_check_sizeof_operand(c1_type * type);
c1_symbol * __cdecl expr_report_undeclared_identifier(void * name);
c1_node * __cdecl expr_check_namespace_in_expression_1(c1_symbol * sym, void * * set_entry, c1_symbol * entry_sym);
c1_node * __cdecl expr_check_namespace_in_expression_2(byte kind, c1_node * bound, char in_class, c1_symbol * ovl_set, c1_symbol * target, c1_symbol * sym, int in_class_scope);
c1_node * __cdecl expr_resolve_member_or_overload_fragment(void);
c1_node * __cdecl expr_member_value_mark_constant(c1_node * folded, c1_node * load, c1_symbol * sym);
c1_type * __cdecl expr_typeid_return_type(void);
c1_node * __cdecl expr_build_static_typeid(c1_type * type);
c1_node * __cdecl expr_warn_rtti_disabled(c1_node * e, c1_symbol * cls);
c1_node * __cdecl expr_build_typeid_expression(c1_node * operand);
void __cdecl intrinsic_unmark_function(c1_symbol * sym);
c1_node * __cdecl expr_build_new_cold_blocks(c1_node * alloc, c1_type * ptr_type, c1_symbol * cls, c1_node * count_expr, char is_array, char class_41_bit1_clear, char cookie_needed, c1_node * alloc_cell, char has_placement, c1_node * assign, c1_symbol * opnew, c1_symbol * cls_cell, c1_node * cell_28, c1_node * cell_2c, c1_node * cell_30, c1_node * cell_34, c1_type * ptr_type_cell, int elem_size, int temp_key, int cell_4c, int cell_54, c1_node * count_assign, c1_type * cell_60, c1_u32 cell_64, c1_u32 cell_68, c1_node * call_info, c1_node * call_info_4, int call_info_10, c1_node * call_info_18, byte call_info_24, int cell_94, int cell_98, c1_symbol * cell_a4, c1_node * cell_ac, char kind, int placement, c1_symbol * type_sym, int init, c1_node * args);
c1_node * __cdecl expr_build_new_eh_delete(char is_array, c1_node * alloc_call, c1_node * alloc, char has_placement, c1_node * assign, c1_symbol * cls, c1_node * cell_28, c1_node * cell_2c, c1_node * cell_30, c1_node * cell_34, c1_type * ptr_type, int temp_key, int cell_4c, int cell_54, c1_node * count_assign, c1_node * call_info, c1_node * call_info_4, int call_info_10, c1_node * call_info_18, byte call_info_24, int cell_94, int cell_98, c1_symbol * cell_a4, c1_node * cell_ac, char kind);
c1_symbol * __cdecl expr_member_call_candidates_cold_blocks(int * name, c1_symbol * fn_set, c1_symbol * member_set, c1_type * fn_type, int arg_types);
void __cdecl expr_resolve_function_operand(uint op, c1_node * * operand, c1_node * other);
c1_node * __cdecl tree_new_zero_flagged(void);
c1_node * __cdecl tree_new_zero_constant(void);
int * __cdecl tree_copy_node_cell_list(int * list, int arena);
int * __cdecl tree_copy_node_cell_list_list(int * list, int arena);
c1_type * __cdecl conv_check_conditional_operands_tail(c1_type * result);
c1_node * __cdecl expr_new_shared_temporary(c1_node * right);
c1_node * __cdecl expr_build_bool_increment(c1_u8 op, c1_node * operand, c1_node * rhs);
c1_node * __cdecl expr_build_binary_return_null(void);
c1_node * __cdecl expr_build_subscript_and_lvalue_ops_return_null(void);
c1_node * __cdecl expr_build_unary_return_null(void);
c1_node * __cdecl expr_build_address_of_tail(c1_node * e);
c1_node * __cdecl expr_build_address_of_retype(byte storage, c1_symbol * sym, c1_node * node, c1_type * type);
c1_node * __cdecl expr_check_lvalue(c1_node * node, c1_type * type);
c1_node * __cdecl expr_warn_signed_unsigned_compare(c1_node * right_cell, c1_node * left_cell, uint op_cell, int op_code, c1_node * node);
c1_node * __cdecl expr_check_pointer_arithmetic_push_fragment(c1_type * right_type, uint op_cell);
int __cdecl expr_check_void_in_conditional_return_true(void);
int __cdecl conv_report_indirection_levels(uint op, c1_type * type, c1_type * type2);
int __cdecl conv_report_indirection_types(uint op);
int __cdecl conv_check_qualifiers(uint op, uint target_quals, uint source_quals, int rank_flag);
void __cdecl conv_warn_different_bases(int op, byte * type, byte * type2);
c1_node * __cdecl tree_new_initializer_dtor_list(c1_node * item, c1_value_cell * dtors);
c1_node * __cdecl tree_new_default_arg_dtor_list(c1_node * tree, c1_value_cell * dtors);
c1_node * __cdecl tree_new_eh_states_list(c1_node * tree, void * states);
c1_node * __cdecl tree_new_node_typed_from_right(c1_u8 op, c1_symbol * sym);
c1_node * __cdecl expr_array_to_pointer_tail(c1_symbol * sym, c1_node * node);
c1_node * __cdecl trees_check_lvalue_cast(int mode_sel, c1_node * e, char no_load, uint mode);
c1_node * __cdecl expr_check_based_operator(c1_node * right, c1_node * left);
c1_node * __cdecl expr_member_select_by_index(c1_node * src, uint flags);
c1_node * __cdecl expr_spill_and_comma(c1_node * e);
void __thiscall expr_save_operand_for_reuse(c1_call_record * view, c1_node * args);
void __fastcall expr_call_view_find_first_arg_slot(c1_call_record * view);
void __fastcall expr_saved_operand_split_pair(int * rec);
c1_node * __thiscall expr_copy_placement_argument(c1_arg_iter * arg_iter, char from_new_expression);
void __thiscall expr_saved_operand_init(c1_saved_operand * rec, c1_node * expr);
int __fastcall expr_saved_operand_rebind(int * rec);
void __thiscall expr_clone_for_reuse(c1_saved_operand * rec, c1_node * value);
int __fastcall expr_saved_operand_slot1(int * rec);
void __thiscall expr_saved_operand_replace_slot1(void * rec, c1_node * node);
int __fastcall expr_saved_operand_slot2(int * rec);
void __thiscall expr_saved_operand_replace_slot2(c1_saved_operand * rec, c1_node * node);
int __cdecl expr_is_intrinsic_0xdf_call(char * node);
void * __thiscall expr_call_view_init(void * view, char * expr);
int __cdecl tree_list_length(int item);
c1_u8 * __thiscall expr_build_arrow_member_implicit(c1_scope_stack * scope, fe_name * name);
void __cdecl conv_warn_constant_conversion(uint const_hi, uint const_lo, c1_type * target, uint op, c1_type * source_type);
ulonglong __cdecl conv_warn_cast_truncates(c1_type * src_type, uint value_lo, int value_hi, int value_hi_local, byte op, int target_size, c1_type * target);
ulonglong __cdecl conv_warn_constant_truncation(c1_type * src_type, uint value_lo, int value_hi, int value_hi_local, byte op, int target_size, c1_type * target);
c1_node * __cdecl expr_vfptr_subobject_address(uint op, c1_node * obj, c1_symbol * cls);
c1_node * __cdecl expr_build_dynamic_cast_call(c1_node * node, c1_type * target, c1_symbol * target_class, c1_symbol * source_class, c1_u8 is_reference);
c1_node * __cdecl expr_build_rt_cast_to_void_call(c1_node * node, c1_type * target, c1_symbol * source_class);
c1_node * __cdecl conv_check_named_cast(c1_type * target, c1_node * node);
void __cdecl conv_bind_reference_loses_qualifiers(c1_conversion * conv);
void __fastcall conv_based_pointer_conversion(c1_conversion * conv);
void __fastcall conv_rule_member_pointer_to_integral(c1_conversion * conv);
char __stdcall conv_function_cast_is_unsafe_ellipsis(c1_type * from, c1_type * to);
void __fastcall conv_rule_function_source(c1_conversion * conv);
void __fastcall conv_rule_pointer4086_to_reference84(c1_conversion * conv);
void __fastcall conv_rule_template_parameter_source(c1_conversion * conv);
c1_node * __thiscall conv_build_template_parameter_operand(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl conv_apply_standard_conversion_bool_argument(c1_node * operand, c1_type * target, c1_conversion * conv, c1_node * dest);
c1_node * __cdecl conv_build_integral_constant_warn_signed_unsigned(c1_conversion * conv, c1_type * target, c1_type * source, uint value_lo, int value_hi, c1_node * dest);
c1_node * __cdecl conv_build_integral_constant_warn_truncation(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_build_floating_constant_to_integral(c1_conversion * conv, c1_node * dest);
void __stdcall conv_warn_possible_loss_of_data_4(undefined4 esi);
c1_node * __thiscall conv_build_floating_constant(c1_conversion * conv, c1_node * dest);
c1_node * __cdecl conv_check_virtual_base_conversion(c1_conversion * conv);
c1_node * __thiscall conv_build_based_pointer(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_build_integral_to_based_pointer(c1_conversion * conv, c1_node * dest);
c1_node * __thiscall conv_new_temporary_variable_address(c1_conversion * conv, c1_type * type, c1_symbol * * out);
c1_node * __stdcall tree_new_init_assign(c1_node * target, c1_node * value);
c1_node * __cdecl conv_warn_forcing_bool(uint op, c1_node * left, c1_type * type);
c1_node * __thiscall conv_build_member_pointer_to_bool(c1_conversion * conv, c1_node * dest);
void __cdecl conv_note_none(void);
void __thiscall conv_report_cannot_convert(c1_conversion * conv, char report);
int __thiscall conv_compare_sequences_case6(char flip, c1_type * type_a, c1_type * type_b);
c1_node * __cdecl property_build_access(c1_u8 op, c1_node * node, c1_node * value);
c1_node * __cdecl expr_build_uuidof_expression(c1_node * operand);
c1_node * __cdecl expr_build_uuidof_null(void);
c1_node * __cdecl expr_uuidof_guid_value(c1_symbol * guid_sym);
c1_type * __cdecl expr_uuidof_return_type(void);
c1_symbol * __cdecl expr_uuidof_guid_symbol(fe_name * name, c1_guid * guid);
c1_type * __cdecl expr_guid_object_type(void);
c1_node * __cdecl expr_build_uuidof(c1_type * type);
c1_guid * __cdecl expr_check_uuidof_unique(c1_symbol * cls, c1_u8 * reported);
int __cdecl fold_float_round_to_width(int out, int width);
undefined4 __cdecl float_fold_add_constants(float10 * a, float10 * b, float10 * out);
int __cdecl float_fold_subtract_constants(c1xx_float_const * a, c1xx_float_const * b, c1xx_float_const * out);
int __cdecl fold_float_to_int32_checked(float10 * value, int * out);
c1_u8 __cdecl operator_unary_form(c1_u8 token);
c1_u8 __cdecl operator_binary_form(c1_u8 token);
c1_node * __cdecl expr_apply_overloaded_arrow_fragment(byte * failed);
void __cdecl expr_note_destructor_lookup_failure(int sym2);
c1_node * __cdecl expr_condition_guarded_error_exit(void * null_guard, byte * frame);
c1_node * __cdecl expr_guard_collect_pending_actions(int operator_depth, int * rec, c1_node * result, byte * frame);
c1_node * __cdecl expr_unwind_actions_case5_fragment(int walking, int * rec, c1_node * result, byte * frame);
c1_node * __cdecl expr_unwind_actions_guard_exit_fragment(int zero, byte * frame);
c1_node * __cdecl expr_unwind_actions_guard_exit_fragment_2(int zero, byte * frame);
c1_node * __cdecl expr_operand_guarded_tail_case5_fragment(int zero, int * rec, c1_node * result, byte * frame);
c1_node * __cdecl expr_unwind_actions_walk(int zero, int * rec, c1_node * result, byte * frame);
c1_node * __cdecl expr_build_throw_intrinsic_call(c1_node * object, c1_node * throw_info);
c1_node * __cdecl expr_build_zero_pair(void);
c1_node * __cdecl expr_build_throw(c1_node * node);
c1_symbol * __cdecl member_path_class(int * path);
byte __cdecl member_path_offset_end(byte result);
c1_node * __cdecl pm_spill_mi_function_pointer(c1_type * type, c1_node * right, c1_node * right2);
c1_node * __cdecl pm_build_vi_function_pointer_constant(c1_type * type, c1_node * function, c1_node * offset, void * vbase);
c1_node * __cdecl pm_spill_vi_function_pointer(c1_type * type, c1_node * right, c1_node * right2, c1_node * right3);
c1_node * __cdecl pm_spill_general_function_pointer(c1_type * type, c1_node * right, c1_node * right2, int value, c1_node * right3);
c1_node * __cdecl pm_spill_vi_data_pointer(c1_type * type, c1_node * right, c1_node * right2);
c1_node * __cdecl pm_spill_general_data_pointer(c1_type * type, c1_node * right, int value, c1_node * right2);
c1_node * __cdecl expr_build_member_pointer_dereference(c1_node * node);
c1_node * __cdecl pm_build_simple_data_member_access(c1_node * operand);
c1_node * __cdecl pm_build_vi_data_member_access(c1_node * node);
c1_node * __cdecl pm_build_vbase_adjusted_pointer(c1_node * left, c1_node * left2, c1_node * right, c1_node * right2, c1_type * type);
c1_node * __cdecl pm_build_vbase_adjusted_pointer_dynamic(c1_node * left, int node, c1_node * right, c1_node * src, c1_node * right2);
c1_node * __cdecl pm_build_general_data_member_access(c1_node * node);
void __cdecl pm_spill_object_for_data_member(c1_node * node, c1_node * * object_out, c1_node * * member_out);
c1_node * __cdecl pm_lower_member_function_call(c1_node * left, c1_node * * spilled);
c1_node * __cdecl pm_lower_mi_member_call(c1_node * left, c1_node * node, c1_type * type, c1_node * * spilled);
c1_node * __cdecl pm_lower_vi_member_call(c1_node * node, c1_node * node2, c1_type * type, c1_node * * spilled);
int __cdecl pm_lower_general_member_call(c1_node * node, c1_node * node2, c1_type * type, c1_node * left);
void __cdecl pm_spill_object_for_member_call(c1_node * node, c1_node * * object_out, c1_node * * member_out, c1_node * * spilled);
c1_node * __cdecl tree_new_member_offset_load(c1_node * left, c1_node * operand, c1_type * type);
int __cdecl pm_convert_object_to_member_class(c1_node * node);
c1_node * __cdecl tree_new_null_data_member_pointer(c1_type * type);
c1_node * __cdecl pm_null_vi_data_pointer(c1_type * type);
c1_node * __cdecl pm_null_general_data_pointer(c1_type * type);
c1_node * __cdecl pm_null_vi_function_pointer(c1_type * type);
c1_node * __cdecl pm_null_general_function_pointer(c1_type * type);
c1_node * __cdecl expr_expand_member_pointer_compare(c1_node * node);
c1_node * __cdecl expr_member_pointer_compare_dispatch(c1_node * node, void * builder);
c1_node * __cdecl pm_compare_mi_function(c1_node * node, int op, int join, int join2);
void __cdecl pm_compare_two_part(c1_node * node, int op, int op2);
c1_node * __cdecl pm_compare_general_data(c1_node * node, int op, int join);
c1_node * __cdecl pm_compare_vi_function(c1_node * node, int op, int join, int join2);
c1_node * __cdecl pm_compare_general_function(c1_node * node, int op, int join, int join2);
c1_node * __cdecl pm_spill_member_pointer_operand(c1_node * node, int part, c1_node * * spill);
int __cdecl expr_is_reusable_lvalue(c1_node * node);
c1_node * __cdecl member_pointer_data_part_0(c1_node * mp);
c1_node * __cdecl member_pointer_data_part_1(c1_node * mp);
c1_node * __cdecl member_pointer_data_part_0b(c1_node * mp);
c1_node * __cdecl member_pointer_data_part_1b(c1_node * mp);
c1_node * __cdecl member_pointer_data_part_2(c1_node * mp);
c1_node * __cdecl member_pointer_data_part(c1_node * mp, int k);
c1_node * __cdecl pm_code_part(c1_node * left, c1_node * node);
c1_node * __cdecl pm_this_adjustment_part(c1_node * left, c1_node * node);
c1_node * __cdecl member_pointer_function_part_1(c1_node * mp, int unused);
c1_node * __cdecl member_pointer_function_part_0(c1_node * mp, int unused);
c1_node * __cdecl member_pointer_function_part_1b(c1_node * mp, int unused);
c1_node * __cdecl member_pointer_function_part_2(c1_node * mp, int unused);
c1_node * __cdecl member_pointer_function_part(c1_node * mp, int unused, int k);
int __cdecl pm_value_may_be_null(char * node);
c1_node * __cdecl expr_build_null_checked_member_pointer(c1_node * adjusted, c1_node * orig, c1_type * type);
c1_node * __cdecl expr_build_null_checked_member_offset(c1_node * adjusted, c1_node * orig);
c1_node * __cdecl expr_build_null_checked_member_offset_thunk(c1_node * adjusted, c1_node * orig);
c1_node * __cdecl tree_add_offset_if_nonzero(c1_node * left, int value);
c1_node * __cdecl tree_add_offset_when_zero(c1_node * test, c1_node * base, int value);
c1_node * __cdecl expr_build_class_operator_delete_call_alias(void * * next_cell, void * * set_cell, void * * cell, c1_node * args, char one_param_found, c1_symbol * cls);
int __cdecl expr_build_operator_delete_call_not_found(c1_node * p);

void __cdecl il_emit_line_record(void);
int __thiscall il_buffer_reserve(c1_byte_buffer * buf, int n);
c1xx_il_emitter * __cdecl il_emitter_get_default(void);
c1_u8 * __cdecl record_pos_new(short a, short b, int * p);
void __thiscall il_buffer_put_compact_u16_unchecked(c1_il_buffer * buf, ushort value);
uint * __thiscall il_emitter_browse_assign_entity_id(c1xx_il_emitter_browse * this, uint * out, uint entity);
void __thiscall il_emitter_browse_define_symbol(c1xx_il_emitter_browse * this, c1_symbol * sym);
void __thiscall il_emitter_browse_reference_symbol(c1xx_il_emitter_browse * this, c1_symbol * sym);
char __cdecl tu_has_pending_special_members(void);
void __thiscall il_emitter_browse_reference_macro(c1xx_il_emitter_browse * this, int * macro);
void __thiscall il_emitter_browse_set_owner(c1xx_il_emitter_browse * this, c1_symbol * sym);
uint __thiscall il_emitter_browse_entity_id(c1xx_il_emitter_browse * this, c1_symbol * sym);
void __cdecl il_emit_symbol(int kind, c1_symbol * sym);
void __cdecl il_emit_symbol_record_body(c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __thiscall il_buffer_put_id(c1_il_buffer * buf, uint id);
void __cdecl il_emit_pragma_or_segment_record(int sub);
void __cdecl il_emit_byte_record(c1_u8 b);
int __cdecl il_line_number_emit_limit(void);
int __cdecl il_line_limit_disabled(void);
void __thiscall il_emitter_browse_begin_block(c1xx_il_emitter_browse * this);
void __thiscall il_emitter_browse_end_block(c1xx_il_emitter_browse * this);
void __thiscall il_buffer_put_compact_value(c1_il_buffer * buf, uint value);
void __thiscall il_emitter_browse_record_d(c1xx_il_emitter_browse * this, c1_symbol * sym);
void __fastcall il_buffer_flush(c1_il_buffer * buf);
void __cdecl il_emit_tuple(int op, node * n);
c1_u8 __thiscall il_buffer_reserve_ok(c1_il_buffer * buf, int n);
int __thiscall il_buffer_put_byte7(c1_il_buffer * buf, uint value);
uint __cdecl il_function_option_word(void);
void __thiscall il_emitter_begin_region_at_top_level(c1xx_il_emitter * this, char use_preferred);
void __cdecl il_emit_global_symbol(int * symref);
void __cdecl il_emit_global_symbol_tail(char mode, c1_symbol * sym, int * symref);
void __cdecl il_emit_symbol_if_needed(int * symref);
void __cdecl il_emit_symbol_with_mode(int kind, int symref, char mode);
void __thiscall il_buffer_put_string(c1_il_buffer * buf, char * s);
void __cdecl il_emit_symbol_reference(c1_il_buffer * buf, c1_symbol * sym, uint id);
void __cdecl il_begin_function_body(int generated);
void __cdecl il_emit_expression_tree(c1_node * node);
int __cdecl il_key_is_global_helper_function(int key);
uint __cdecl il_symbol_key(byte * sym);
void __stdcall il_emit_line_record_24(void);
void __fastcall il_emit_function_symbols(int * scope);
void __cdecl il_emit_function_labels(void);
void __cdecl il_emit_type_descriptor(int op, c1_node * n, int is_constant);
void __cdecl il_emit_type_descriptor_kind_fragment(c1_type * t, uint agg_size, int op, uint cv_flags, int is_constant);
void __cdecl il_emit_integer_constant(uint lo, int hi, int size);
int __thiscall il_buffer_put_bytes(c1_il_buffer * buf, uint * src, uint n);
c1xx_il_emitter * __cdecl il_emitter_get_preferred(void);
void __fastcall il_emitter_browse_begin_region(c1xx_il_emitter_browse * il_emitter_browse);
int __thiscall il_buffer_grow(c1_byte_buffer * buf, int n);
void __thiscall il_emitter_browse_end_module(c1xx_il_emitter_browse * this);
void __thiscall il_emitter_browse_begin_module(c1xx_il_emitter_browse * this);
void __thiscall il_emitter_browse_end_module_if(c1xx_il_emitter_browse * this, int force);
uint __fastcall il_symbol_key_2(fe_file_record * file);
void __thiscall il_emitter_plain_define_symbol(c1xx_il_emitter * this, c1_symbol * sym);
void __thiscall il_emitter_browse_define_macro(c1xx_il_emitter_browse * this, fe_macro * macro);
int __thiscall il_emitter_browse_mark_definition(c1xx_il_emitter_browse * this, int set, int sym);
void __thiscall il_emitter_browse_record_c(c1xx_il_emitter_browse * this, c1_symbol * sym);
void __thiscall il_file_open(c1_il_buffer * buf, char * prefix, char * suffix, char * mode);
void __cdecl il_globals_rewind(void);
void __cdecl il_emit_debug_record(uint kind);
void __cdecl il_emit_in_marker(void);
void __cdecl il_buffer_put_int_sized(uint * value, int size, c1_il_buffer * buf);
void __fastcall tu_end_emit_global_scope(c1_scope_stack * scope_stack);
void __cdecl tu_emit_function_records(void);
void __cdecl il_emit_source_file(int ni);
void __cdecl tu_end_flush(void);
void __cdecl vtable_record_emit(c1_vtable_record * rec, c1_symbol * cls);
void __cdecl vtable_record_make_slot_thunks(c1_vtable_record * rec, c1_symbol * cls);
c1_symbol * __cdecl vtable_slot_target(c1_vtable_slot * slot, c1_symbol * cls, c1_vtable_record * rec);
int __cdecl vtable_slot_this_delta(c1_vtable_slot * slot, c1_symbol * cls, c1_vtable_record * rec);
int __cdecl vtable_slot_subobject_offset(int * path, c1_symbol * cls);
void __cdecl vtable_record_write_data(c1_vtable_record * rec, c1_symbol * table, c1_symbol * cls);
void __cdecl tu_emit_vcall_thunks(void);
void __cdecl tu_emit_pending_table_15d0(void);
void __cdecl tu_emit_pending_vtables(void);
void __fastcall il_emitter_browse_finish(c1xx_il_emitter_browse * il_emitter_browse);
void __cdecl il_emitters_free(void);
void __fastcall il_buffer_close(c1_il_buffer * buf);
int __fastcall il_buffer_close_file(c1_il_buffer * buf);
void __fastcall il_buffer_destroy(c1_il_buffer * buf);
void __cdecl il_emitters_create(char * browse_file);
void __cdecl il_open_ex(void);
void __thiscall il_emitter_plain_define_macro(c1xx_il_emitter * this, int * macro);
void __fastcall il_emitter_browse_open(c1xx_il_emitter_browse * il_emitter_browse);
void __thiscall il_buffer_put_byte(c1_il_buffer * buf, c1_u8 b);
void __cdecl il_emit_debug_record_10(void);
void __cdecl vtable_nop_2(void);
void __cdecl il_emitter_select(char keep);
char __fastcall il_emitter_browse_reopen(c1xx_il_emitter_browse * il_emitter_browse);
void __stdcall il_emitter_browse_pch_name(char * name);
void __cdecl il_emit_end_of_globals(void);
void __cdecl tu_emit_dynamic_initializers(void);
int __cdecl tu_pending_function_slot(uint slot);
void __cdecl tu_emit_pending_functions(void);
void __cdecl tu_emit_guarded_static_destructor(c1_symbol * sym);
c1_u8 * __cdecl record3_copy(int * src, int arena);
void __thiscall il_emitter_browse_begin_instantiation(c1xx_il_emitter_browse * this, int * point);
void __thiscall il_emitter_browse_end_instantiation(c1xx_il_emitter_browse * this);
void * __cdecl record3_new_from(int * src, int arena);
c1_u8 * __cdecl record3_new(int a, int b, int c, int arena);
void __fastcall il_emit_global_symbol_chain(byte * sym);
void __cdecl tu_end_scope(void);
void __cdecl il_emitter_browse_pch_mark(void);
int __thiscall il_buffer_reserve_advance(c1_byte_buffer * buf, int n, c1_u8 * * pos);
int __thiscall il_buffer_set_memory(c1_byte_buffer * buf, c1_u8 * start, c1_u8 * cur);
void __fastcall il_emitter_suspend_enter(char * state);
void __cdecl il_emit_debug_record_fragment(uint value, int * args, char * fmt, uint kind);
void __cdecl il_emitter_begin_unit(void);
void __cdecl il_emitters_discard(void);
void __fastcall il_emitter_browse_discard(c1xx_il_emitter_browse * il_emitter_browse);
void __fastcall il_emitter_browse_region_boundary(c1xx_il_emitter_browse * il_emitter_browse);
void __cdecl il_emitter_plain_region_boundary(void);
void __thiscall il_emitter_browse_abort(c1xx_il_emitter_browse * this);
void __thiscall il_emitter_browse_record_11(c1xx_il_emitter_browse * this);
void __thiscall il_emitter_browse_input_refilled(c1xx_il_emitter_browse * this);
uint __thiscall il_emitter_plain_entity_id(c1xx_il_emitter * this, c1_symbol * sym);
int * __thiscall il_emitter_plain_assign_entity_id(c1xx_il_emitter * this, int * out, int unused);
void __thiscall il_emitter_plain_open(c1xx_il_emitter * this);
char __thiscall il_emitter_plain_reopen(c1xx_il_emitter * this);
void __cdecl il_emit_global_symbol_debug_fragment(c1_symbol * sym, int * symref, char mode);
void __cdecl il_emit_symbol_fragment(c1_symbol * sym, int kind_b, int zero, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_part(c1_type * type, uint size, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_size_fragment(uint size, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_ref_flag_80_fragment(byte sym_kind, byte sym_flags5, uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_mode3_fragment(byte sym_kind, byte sym_flags5, byte sym_flags4, uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_ref_flag_1000_fragment(byte sym_kind, byte sym_flags4, uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_ref_flag_40_fragment(byte sym_flags22, byte sym_flags4, uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_ref_base_type_fragment(byte sym_flags22, uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_storage_fragment(uint ref_flags, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_type_fragment(c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_function_storage_fragment(char storage_class, c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_function_line_fragment(c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_symbol_inline_fragment(c1_symbol * sym, c1_il_buffer * buf, char fdef_mode, uint part_scratch, byte is_inline, c1_type * sym_type, c1_type * derived_type, c1_type * fn_type, c1_symbol * pair_sym, char * tmpl, uint base_code, uint rec_word0, uint rec_word1, uint rec_word2, int is_array, uint type_flags, uint * out_cell, c1_symbol * iter_sym, void * * ref_cell, void * * ref_list, int kind, c1_symbol * sym_arg);
void __cdecl il_emit_tuple_aliased_function_fragment(c1_node * n, c1_symbol * sym, int one, uint pair_key1, uint pair_key2, uint pair_flags, char * shape, int op, int n_slot);
void __cdecl il_emit_tuple_long_value_fragment(c1_node * n, uint value, int one, uint pair_key1, uint pair_key2, uint pair_flags, char * shape, int op, int n_slot);
void __cdecl il_emit_key_fragment(uint key, c1_node * n, int one, uint pair_key1, uint pair_key2, uint pair_flags, char * shape, int op, int n_slot);
void __cdecl il_emit_based_symbol_fragment(c1_node * n, int one, uint pair_key1, uint pair_key2, uint pair_flags, char * shape, int op, int n_slot);
void __cdecl il_emit_eh_try(void);
void __cdecl il_emit_eh_trymap(void);
void __cdecl il_emit_eh_catch(c1_node * catch_node);
void __cdecl il_emit_goto(c1_node * label);
uint __cdecl il_symbol_key_assign(c1_symbol * sym);
void __thiscall il_buffer_put_compact_u16(c1_il_buffer * buf, ushort value);
void __cdecl il_emit_source_file_change(int sub, int sub_arg);
void __thiscall il_buffer_append_buffer(c1_il_buffer * src, c1_il_buffer * dst);
void __cdecl il_emit_in_item_fragment(uint value, c1_il_buffer * buf, c1_node * node, int addr_offset, c1_symbol * addr_sym, int is_string, char * fmt, float float_value, uint type_code, uint const_lo, int const_hi, uint dbl_lo, uint dbl_hi, uint value0, uint value1, c1_x87_tail value2, c1_symbol * sym, c1_node * node_param, char value_is_integer);
void __cdecl ilstore_open(c1xx_pdb * pdb);
void __cdecl ilstore_report_error(void);
void __cdecl ilstore_release(void);
void __cdecl ilstore_open_streams(char * module_name);
void __cdecl ilstore_release_module(void);
void __thiscall ilstore_put_record(c1_il_buffer * buf, int key, int value);
void __thiscall ilstore_delete_record(c1_il_buffer * buf, int key);
void __thiscall ilstore_open_stream(c1_il_buffer * buf, char * prefix, char * suffix);
void __fastcall ilstore_flush(c1_il_buffer * buf);
void __fastcall ilstore_close(c1_il_buffer * buf);
c1_u8 * __thiscall il_buffer_put_pch_reference(c1_il_buffer * buf, int * out_length);
void __cdecl ilstore_query_record(int key, int space, void * * data);
void __cdecl ilstore_fatal_write_error(int space, c1_ilstore_blob * out);
void __cdecl ilstore_open_for_gi(void);
void __cdecl il_files_close(char keep_db);
void __stdcall il_files_open(void);
size_t __cdecl il_file_write_buffer(size_t buf);
void __fastcall il_buffer_init_empty(int * buf);
void __fastcall il_buffer_free(c1_byte_buffer * buf);
int __thiscall il_buffer_reserve_get_cur(c1_byte_buffer * buf, int n, c1_u8 * * cur);
int __thiscall il_buffer_append(c1_byte_buffer * buf, void * src, uint n, c1_u8 * * pos);
void __cdecl tu_emit_guid_object(int * item);
void __thiscall il_symbol_pair_operand_keys(c1_catch_handler * handler, uint * key1, uint * key2, uint * flags);
c1_node * __cdecl vtable_purecall_slot_value(int slot);
c1_u8 * __cdecl record4_new(int a, int b, int c, int d, int arena);
c1_u8 * __cdecl record4_copy(int * src, int arena);
c1_symbol * __cdecl adjustor_thunk_lookup_or_new(int kind, c1_symbol * target, int delta, int vtordisp);

byte * __fastcall token_next(c1_token_reader * reader);
c1_u8 * __fastcall lex_source_next_token(c1xx_lex_source_stream * stream);
byte * __cdecl yylex_cpp(void);
c1_u8 * __cdecl lex_scan_line_start(void);
c1_u8 * __cdecl token_new_newline(c1_u8 * token);
void * __cdecl name_intern(char * s);
int __cdecl lex_scan_identifier(byte first);
void __thiscall lex_source_unget_token(c1xx_lex_source_stream * stream, c1_u8 * token);
char * __cdecl lex_lookahead_decl_specifiers(char * token);
c1xx_token * __cdecl lex_classify_type_name(c1xx_token * token);
byte * __cdecl lex_compose_qualified_name(char * token, int p2);
c1_u8 __fastcall lex_token_code(c1xx_token * tok);
char __cdecl lex_fetch_pending_input(void);
int __cdecl lex_end_of_input(void);
void __cdecl lex_skip_line_comment(void);
void * __cdecl name_intern_hashed(c1_u8 * text, uint hash, uint len, byte * is_new);
int __cdecl lex_skip_line_start_comment(void);
int __cdecl lex_buffer_refill(void);
c1_u8 * __cdecl lex_scan_integer_literal(byte first, int asm_mode);
byte __cdecl lex_getc(void);
longlong __cdecl lex_scan_integer_constant(byte * digits, int count, int base);
int __cdecl lex_hex_digit_value(uint c);
c1_type * __cdecl lex_decimal_literal_type(uint * value);
c1_u8 * __fastcall lex_source_peek_token(c1xx_lex_source_stream * stream);
c1_type * __cdecl lex_hex_octal_literal_type(uint * value);
uint __cdecl lex_scan_identifier_slow(c1_u8 * start, uint hash, byte c);
uint __cdecl name_bucket_insert_fragment(fe_name * entry, uint hash16, uint len, fe_name * * bucket, uint hash16_cell, uint marker, fe_name * * bucket_cell);
byte __cdecl lex_get_char(void);
int __cdecl lex_trigraph(void);
int __cdecl lex_trigraph_replace(byte * input, char qmark);
int __cdecl lex_line_splice(void);
int __fastcall lex_line_number_of_position(int * pos);
void __cdecl lex_scan_string_literal_body(byte wide, char quote);
void __stdcall lex_scan_string_literal(undefined4 ebx, undefined4 edi, undefined4 esi);
void __cdecl lex_copy_text_to_arena(c1_string_value * out, c1_u8 * text, uint len, int arena);
char * __fastcall lex_peek_token(uint * stream);
byte __cdecl lex_skip_comment(byte c);
byte __cdecl lex_skip_comment_return(byte ch);
void __cdecl lex_skip_to_char(byte quote);
void __fastcall token_list_clear_saved_state(int * list);
c1_type * __cdecl lex_long_literal_type(uint * value);
void __cdecl token_stream_put_function_header(c1_symbol * sym, c1xx_token_stream * stream, int arena_index);
c1_u8 __fastcall token_source_reads_source_file(c1_token_reader * reader);
void * __cdecl name_new_S(void);
void * __cdecl name_intern_symbol_decorated_in(c1_symbol * scope_sym, c1_symbol * sym);
c1_u8 * __cdecl token_new_decl_specifiers(int p1, byte storage, byte * spec, int p4);
void * __cdecl name_intern_decorated_quiet(c1_symbol * sym, int * args);
char * __fastcall token_stream_peek_non_marker(c1xx_token_stream * token_stream);
c1_u8 * __cdecl lex_scan_character_constant(int wide, ushort * chars, ushort count);
uint __cdecl lex_scan_escape_sequence(byte c, int wide);
undefined1 __stdcall lex_scan_escape_sequence_return_char(undefined4 ebx);
c1_u8 * __cdecl lex_operator_function_id(void);
c1_u8 * __cdecl lex_make_operator_name_token(byte * token);
char * __cdecl lex_mark_paren_candidate(char * token);
void __cdecl lex_record_paren_run(char * token);
void __cdecl lex_record_balanced_tokens(int depth);
void * __thiscall token_stream_copy(c1xx_token_stream * this, c1xx_token_stream * src);
void __cdecl lex_record_paren_run_on_pop(void);
void * __thiscall token_stream_init(c1xx_token_stream * this, int arena, byte from_source);
void * __thiscall token_buffer_init(c1xx_token_cursor * cursor, int arena);
void __thiscall token_source_push(c1_token_reader * reader, c1xx_token_stream * owner, int arena, int kind, void * on_pop, int * restore_position);
c1_u8 * __cdecl token_new_position_marker(int arena);
void __thiscall token_stream_append(c1xx_token_stream * this, int token);
void __fastcall token_reader_mark_position(c1xx_token_stream * stream);
int __fastcall token_stream_next_raw(c1xx_token_stream * token_stream);
void __thiscall token_stream_unget(c1xx_token_stream * token_stream, char * token);
void __cdecl lex_check_end_of_file(void);
void __cdecl lex_skip_whitespace(void);
void * __cdecl name_intern_file_name(char * file);
int __cdecl lex_unget_token(c1xx_token * tok);
void * __thiscall token_init(void * tok, char code, void * value);
c1_yy_value * __fastcall token_value_address(c1xx_token * token);
byte __cdecl lex_next_significant_char(byte c);
void * __cdecl name_intern_symbol_decorated(c1_symbol * sym);
void __cdecl lex_concatenate_strings(c1_string_value * dst, c1_string_value * src);
c1_type * __cdecl lex_unsigned_literal_type(uint * value);
void __cdecl token_buffers_free(void);
void __cdecl token_buffers_init(void);
void * __cdecl virtual_reserve_commit_or_fatal(uint reserve_size, uint commit_size);
void __cdecl lex_mark_mbcs_lead_bytes(void);
void __cdecl token_static_records_init(void);
void __cdecl name_table_init(void);
void __cdecl keywords_configure(void);
void __cdecl name_intern_keyword(byte * text);
void __stdcall name_intern_keyword_fragment(undefined4 eax, undefined4 edi, undefined4 esi);
void __cdecl keyword_unreserve(byte * name);
void __cdecl keyword_mark_reserved_future_use(byte * text);
void __cdecl keyword_mark_obsolete(byte * text);
void __cdecl keyword_mark_obsolete_export(byte * name);
void __cdecl keyword_mark_not_supported(byte * text);
void __cdecl token_arena_reset(void);
void __cdecl keywords_intern(void);
void __cdecl lex_begin_source_file(ushort * defines);
void __cdecl lex_reset_buffers(void);
void * __cdecl name_intern_operator(uchar op);
void * __cdecl name_new_E(void);
c1_u8 __cdecl lex_check_end_of_file_2(void * parameter_table);
void __cdecl lex_skip_to_closing_brace(char before_open_brace);
void __cdecl lex_warn_comment_continuation(void);
c1_u8 * __cdecl lex_scan_floating_literal(byte * digits_end);
void __cdecl token_set_kind_24(char * tok);
char __cdecl lex_at_buffer_start(void);
char __cdecl lex_begin_primary_file(void);
void __cdecl lex_push_builtin_prelude(void);
void __cdecl lex_push_injected_text(int arg);
char __cdecl lex_push_next_forced_include(void);
c1xx_token * __cdecl token_static_for_code(uint code);
void __cdecl lex_clear_lead_byte_classes(void);
void __stdcall lex_check_end_of_file_4(void);
c1_u8 * __cdecl lex_classify_typedef_name_fragment(uint flags_c8, c1_symbol * sym);
c1_u8 * __cdecl lex_operator_function_id_fail(void);
int __cdecl lex_end_of_input_clear_vector(c1_vector * vec, c1xx_il_emitter * saved_il_emitter, int saved_opt_Binl, char saved_c8_bit7, int saved_token_position);
c1xx_lex_source_stream * __thiscall token_stream_scalar_deleting_dtor(c1xx_lex_source_stream * stream, byte flags);
uint __cdecl lex_scan_identifier_slow_overflow(void);
void * __cdecl lex_input_base_ptr(void);
int __cdecl lex_input_bytes_left(void);
char __cdecl lex_skip_unchanged_function_body(int byte_count, uint position_delta);
int __cdecl lex_trigraph_replace_refill(byte * input, char qmark);
void * __cdecl lex_source_input_ptr(void);
void __cdecl token_io_noop(void);
void __cdecl token_io_release_record(int rec);
void __cdecl lex_skip_whitespace_refill(uint comment_flag, uint comment_mask);
void __cdecl lex_skip_line_comment_fragment(void);
char * __cdecl lex_check_string_length(char * mbchar, size_t mb_len);
void __cdecl lex_warn_pascal_string_length(int * lit);
c1_u8 * __cdecl lex_scan_line_start_part(int one, c1_fputc_fn put_char);
c1_u8 * __cdecl lex_pch_stop_token(void);
uint __cdecl lex_scan_pp_number_text(byte * buffer);
c1_u8 * __cdecl lex_check_hex_digits(byte next_char, byte * digits_end, int radix, c1_type * type, longlong value);
c1_u8 * __cdecl lex_scan_integer_literal_radix_suffix(uint suffix, byte next_char, byte * digits_end, int radix, c1_type * type, longlong value);
c1_type * __cdecl lex_scan_sized_int_suffix(char is_unsigned);
c1_type * __cdecl lex_sized_literal_type(uint * value);
c1_type * __cdecl lex_unsigned_long_literal_type(uint * value);
c1_type * __cdecl lex_sized_unsigned_literal_type(uint * value);
byte __stdcall lex_skip_mbcs_trail_byte(void);
char __fastcall token_stream_is_source_text(c1xx_token_stream * stream);
c1xx_token_stream * __fastcall token_reader_current_stream(c1_token_reader * reader);
int __fastcall token_reader_top_kind(c1_token_reader * reader);
void __thiscall token_source_unget(c1_token_reader * reader, c1xx_token * tok);
void __cdecl lex_put_string_byte(byte c, int * buf);
void * __cdecl name_intern_numbered(int n);
void * __cdecl name_intern_special_32(c1_symbol * sym);
void * __cdecl name_intern_special_33(void * sym);
void * __cdecl name_intern_rtti_locator_name(int vftable_sym);
void * __cdecl name_intern_decorated_in_scope_2(c1_symbol * sym2, c1_symbol * sym, char other_owner);
void * __cdecl name_intern_decorated_in_scope(void * sym2, c1_symbol * sym);
char * __cdecl name_encode_for_stream(char * out, byte * name);
void __cdecl lex_line_comment_copy_or_skip(void);

void * __thiscall arena_alloc(arena * a, int n);
void __cdecl mem_free(void * p);
void __cdecl arena_reset(int arena);
void __fastcall arena_reset_ptr(c1_arena * a);
void * __cdecl mem_xmalloc(uint n);
char * __cdecl mem_xstrdup(char * s);
void __thiscall pool_reserve(c1xx_pool * pool, uint n);
c1_u8 * __thiscall pool_commit_pages(c1_arena * a, int npages, c1_u32 * size_out);
c1_vector * __cdecl vector_new(c1_u16 capacity, int arena);
int __fastcall arena_grow(c1_arena * a);
void __fastcall pair_clear(c1_decl_modifier * mod);
c1_u8 * __cdecl arena5_alloc_1c(void);
void __cdecl vector_push(c1_vector * v, void * item);
void __thiscall list_cursor_init(void * cursor, void * first);
short * __cdecl vector_find_or_add(short * set, int value);
void __cdecl vector_release(int sym);
void __cdecl vector_iterator_init(c1_symbol_vector_iter * it, c1_symbol_vector * v);
char __cdecl vector_iter_next(int * it);
char __cdecl vector_contains_type(short * v, void * item);
c1_u8 * __cdecl arena_alloc_n_aligned(uint n, int arena);
void __cdecl arena_select_for_expressions(void);
void __cdecl arena_set_expression_index(int index);
void __cdecl free_list_push_124c(c1_symbol * sym);
void __cdecl free_list_pop_124c(void);
void __cdecl vector_for_each(c1_vector * vec, void * callback);
int __cdecl list_push_in_arena(int * head, int arena);
void __cdecl list_pop_head(int * head);
void __thiscall vector_push_triple(int * v, int a, int b, int c);
c1_line_map_row * __fastcall vector_push_12(c1_line_map * map);
c1_u8 * __cdecl arena_or_pool_alloc(uint n, int arena);
void __thiscall list_cursor_init_from_head(c1_list_cursor * cursor, c1_sym_list * head);
c1_pack_cell * __fastcall list_alloc_cell(c1_pack_stack * stack);
c1_u8 * __cdecl arena_alloc_copy(c1_u8 * src, int arena, uint n);
c1_u8 * __thiscall pool_alloc_raw(void * pool, uint n);
int __cdecl vector_iterator_next(uint * iter);
c1_vector * __cdecl vector_copy(c1_vector * src, int arena, void * copy_fn);
c1_vector * __cdecl vector_copy_shallow(c1_vector * src, int arena);
c1_vector * __cdecl vector_copy_shallow_reserve(c1_vector * src, short extra, int arena);
c1_vector * __cdecl vector_grow(c1_vector * v);
c1_vector * __cdecl vector_copy_shallow_to_arena(c1_vector * src, int arena);
void * __cdecl mem_xrealloc(void * p, uint n);
void * __cdecl vector_grow_checked(c1_symbol_vector * v);
void * __thiscall arena_alloc_copy_bytes(c1_arena * a, void * src, uint src_size, uint new_size);
void __thiscall deferred_body_list_append(c1_deferred_body_list * list, c1_symbol * fn);
c1_u8 * __cdecl list_copy_with_header(int * list, int arena);
c1_u8 * __cdecl list_copy_nodes(int * node, int arena);
void __thiscall list_append_tail(c1_arg_list * list, c1_arg_item * item);
int __stdcall DllMain(void * module, int reason);
void __thiscall nheap_object_base_ctor(c1xx_pch_stream_reader * obj, int kind, c1xx_pch_image * image);
void __fastcall arena_release(c1_arena * a);
void __cdecl arenas_free_all(void);
void __cdecl free_list_destroy(c1_byte_block_list * * list);
void __thiscall pool_construct(c1xx_pool * pool, c1_u32 min_pages);
void __cdecl arenas_init_all(void);
void __stdcall arenas_init_all_fragment(c1_arena * a, undefined4 esi);
void __cdecl arenas_init(void);
byte __thiscall arena_reserve(c1_arena * a, c1_arena_desc * descriptor, void * address);
uint __cdecl arena_scaled_reserve_size(c1_arena_desc * descriptor);
void __fastcall arena_reset_to_base(c1_arena * a);
void __cdecl pools_init_all(void);
void __thiscall pool_init_on_arena(void * pool, int arena);
c1_u8 * __cdecl arena_alloc_aligned(uint n);
void __fastcall vector_new_main_arena(int * v);
void __cdecl arenas_free_flagged(void);
void __cdecl pools_reset(void);
void __fastcall pool_clear(int * pool);
byte * __cdecl str_find_trailing_space(byte * s, byte * end);
int __cdecl str_differ_n(char * a, char * b, int n);
void __cdecl list_cell_clear(int * cell);
void __fastcall list_pop_cell(int * list);
void __cdecl free_list_mark_block_end(int * list);
short * __cdecl vector_remove_type(short * set, c1_type * type);
char __cdecl vector_equal(c1_vector * a, c1_vector * b);
c1_u8 * __cdecl str_dup_arena(char * s, int arena);
int __cdecl mem_chain_read(int * cursor, void * dest, uint n);
int __cdecl str_compare_nocase(char * a, char * b);
fe_name * __cdecl pair_init_zero_value(fe_name * out, char * text);
void __stdcall vector_constructor_iterator(void * array, int size, int count, void * ctor);
void __thiscall list_push_front(void * * head, void * * cell);
char * __cdecl str_concat_malloc(char * prefix, char * suffix);
short * __cdecl vector_find_or_add_return_fragment(short * set);
char __cdecl vector_contains(c1_vector * v, void * item);
int __cdecl str_ends_with(char * s, char * suffix);
c1_u8 * __cdecl arena_or_heap_object_new(int size, char in_arena, c1_arena * a);
void * __cdecl nheap_record_new_4c(void * tmpl, int p2);
c1xx_pch_stream_reader * __thiscall nheap_record_init_4c(c1xx_pch_stream_reader * obj, c1xx_pch_stream_reader * from, c1xx_pch_image * image);
void __stdcall mem_alloc_or_fatal_6(void);
void __cdecl arenas_init_fatal_fragment(c1_arena * arena, void * descriptor);

int __stdcall _DllMainCRTStartup(void * hinst, int reason, void * reserved);
int __stdcall _DllMainCRTStartup_chunk(void * hinst, void * reserved, int reason, int * frame);
int __stdcall _CRT_INIT(void * hinst, int reason, void * reserved);
void __cdecl msvcrt_handle_destroy(void);
void __cdecl static_dtor_pdb_state_2(void);
void __cdecl static_dtor_pdb_state(void);
void __cdecl static_dtor_104de3b0(void);
void __cdecl static_dtor_il_gi_fdef_buffer(void);
void __cdecl static_dtor_il_db_buffer(void);
void __cdecl static_dtor_il_gi_buffer(void);
void __cdecl static_dtor_il_pending_init_buffer(void);
void __cdecl static_dtor_il_in_buffer(void);
void __cdecl static_dtor_il_ex_buffer(void);
void __cdecl static_dtor_il_gl_buffer(void);
void __cdecl static_dtor_il_sy_buffer(void);
int __cdecl pm_convert_by_complete_kind(c1_node * node, c1_type * type, int path, int keep_sign, int value);
void __stdcall __tailMerge_ole32(void);
void * __stdcall __delayLoadHelper(void * pidd, void * * ppfnIATEntry);
void __cdecl int64_to_digits(int * value, char * buf, uint radix, int negative);
void __thiscall gi_region_entry_init_empty(c1_idb_region * region);
uint __fastcall bitvec_iter_scan_to_set_bit(c1xx_bitvec * vec);
void __fastcall bitvec_iter_from_bit(int bit, c1xx_bitvec * vec);
c1_u8 * __cdecl base_path_text(int * path);
void __cdecl pm_convert_two_part_offset(c1_node * node, c1_type * type, int unused3, int unused4, int value);
int __cdecl pm_match_address_of_member_tree(char * node, char * * inner);
void __cdecl pm_convert_data_via_vbase(c1_node * node, c1_node * type, int unused3, int unused4, int value, int value2);
int __cdecl pm_convert_function_by_repr(c1_node * node, c1_type * type, int unused3, int unused4, int value, int value2);
void __stdcall __tailMerge_OLEAUT32(void);
void __stdcall ?OverlayIAT@@YGXPAU_IMAGE_THUNK_DATA32@@PBU1@@Z(int * param_1, int * param_2);

int __cdecl ovl_find_function_with_type(c1_symbol * sym, c1_type * type, int complain, int skip_templates, c1_symbol * probe, c1_declarator * d, int mode);
void * * __cdecl ovl_chain_find_function_with_type(c1_symbol * sym, c1_type * type, char complain, char skip_templates, c1_symbol * probe, c1_declarator * d, int mode);
c1_ovl_candidate * __cdecl ovl_resolve_call(c1_symbol * set, c1_node * object, c1_node * args, int argc, int * template_args, byte flags);
c1_ovl_resolution * __thiscall ovl_resolution_begin(c1_ovl_resolution * res, c1_symbol * set, c1_node * args, c1_u32 nargs, int * template_args, byte flags);
void __thiscall ovl_resolution_init(c1_ovl_resolution * res, c1_symbol * set, c1_u32 nargs, byte op, byte flags);
int __cdecl ovl_count_nontemplate_functions(c1_symbol * sym);
void __fastcall ovl_candidates_alloc(c1_ovl_resolution * res);
void __thiscall ovl_add_candidates(c1_ovl_resolution * res, c1_symbol * sym, c1_symbol * overload_set);
void __thiscall ovl_add_candidate_entry_fragment(void * res, byte * sym, int naming_class);
void __thiscall ovl_add_candidate_entry(c1_ovl_resolution * ctx, c1_symbol * sym, c1_symbol * overload_set);
void * __thiscall ovl_candidate_init(void * cand, byte * sym, int p3, int conv, int p5, int prev);
char __thiscall ovl_prune_candidates_by_arity(void * ctx, void * node);
void __thiscall ovl_set_failure_reason(c1_ovl_resolution * res, int reason, int argument);
char __thiscall ovl_match_arguments(void * ctx, c1_node * object);
uint __thiscall ovl_check_argument_conversion(c1_ovl_resolution * ctx, c1_conversion * conv, c1_ovl_candidate * cand, int index, c1_node * arg, uint code);
int __fastcall ovl_unique_candidate(int ctx);
int * __thiscall ovl_select_best_candidate(void * ctx, byte * ambiguous_out, void * fallback);
int __fastcall ovl_first_live_candidate(int ctx);
void __thiscall ovl_add_overload_set_candidates(c1_ovl_resolution * ctx, c1_symbol * sym, c1_symbol * overload_set);
char __thiscall ovl_candidate_remove(c1_ovl_resolution * ctx, c1_ovl_candidate * cand, c1_node * node);
c1_ovl_resolution * __thiscall ovl_collect_operator_candidates(c1_ovl_resolution * res, int op, c1_node * left, c1_node * right, c1_type * left_type);
c1_builtin_operator_row * __cdecl ovl_builtin_candidates_for_operator(char op);
int __cdecl ovl_count_builtin_operator_candidates(char * rows, c1_node * left, c1_node * right);
uint __fastcall ovl_rank_operator_candidates(c1_ovl_resolution * res);
void __thiscall ovl_add_builtin_operator_candidates(void * frame, char * rows, c1_node * left, c1_node * right, int * count);
void __thiscall ovl_builtin_operand_types_begin(c1_builtin_operand_iter * iter, c1_node * node, c1_type * pattern, uint need_lvalue);
char __fastcall ovl_builtin_operand_types_next(int * iter);
char __cdecl ovl_type_matches_builtin_pattern(c1_type * type, c1_type * pattern, char need_lvalue, char via_conversion);
char __cdecl ovl_conversion_types_next(c1_conversion_type_iter * iter);
void __thiscall ovl_report_call_failure(c1_ovl_resolution * res, c1_ovl_candidate * cand, c1_node * node);
int __thiscall ovl_compare_conversion_sequences(c1_conversion * conv_a, c1_conversion * conv_b, int source_side);
int __thiscall ovl_compare_conversion_rank(c1_conversion * conv_a, c1_conversion * conv_b);
char __thiscall ovl_eliminate_worse_candidates(c1_ovl_resolution * res, int reason, int unused);
char __thiscall ovl_candidate_eliminate(void * ctx, int cand);
void __cdecl default_argument_parse_deferred(c1_symbol * fn, int arg3, int scope_rec);
byte * __cdecl ovl_first_function_of_set(c1_symbol * sym);
byte * __cdecl ovl_make_set_of_two(c1_symbol * sym, c1_symbol * sym2);
char __cdecl ovl_builtin_types_equal(c1_type * t, c1_type * type);
void __thiscall ovl_collect_template_candidates(void * result, c1_symbol * sym);
void __thiscall ovl_collect_template_candidates_one(void * result, c1_symbol * sym);
c1_node * __cdecl ovl_convert_call_arguments(c1_symbol * fn, c1_type * type, c1_node * args, c1_conversion * conversions, int argc);
c1xx_ovl_set_iter * __thiscall ovl_set_iter_init(c1xx_ovl_set_iter * iter, void * set);
char __fastcall ovl_set_iter_next(c1xx_ovl_set_iter * iter);
char __fastcall ovl_set_iter_current_is_visible_non_instance(c1xx_ovl_set_iter * iter);
c1_symbol * __fastcall ovl_set_iter_current_symbol(c1xx_ovl_set_iter * iter);
void __thiscall ovl_add_builtin_candidate(c1_ovl_resolution * res, c1_builtin_operator_row * row, c1_type * type, c1_type * type2, int * count);
c1_ovl_candidate * __thiscall ovl_builtin_candidate_init(c1_ovl_candidate * entry, c1_builtin_operator_row * row, c1_type * type, c1_type * type2, c1_conversion * conv_slots, c1_ovl_candidate * prev);
c1_node * __cdecl ovl_apply_argument_conversion(c1_ovl_candidate * cand, int index);
void __fastcall default_argument_parse_in_class(c1_deferred_parse * rec);
c1_symbol * __cdecl ovl_select_function_for_target_type(c1_symbol * sym, c1_type * type, int report_errors, char skip_single_check);
char __cdecl ovl_names_single_function(c1_symbol * sym, char flag);
uint __cdecl ovl_name_function_count(c1_symbol * sym, char exclude_templates);
char __cdecl ovl_check_c_call_argument_count(c1_type * callee_type, c1_type * fn_type, uint argc);
uint __cdecl ovl_set_has_single_function(char kind, c1_symbol * sym, char exclude_templates);
c1_symbol * __cdecl ovl_select_function_template_part(char report_errors, c1_symbol * fn, c1_type * type);
c1_node * __cdecl ovl_report_parameter_conversion(int argno, c1_conversion * conv, c1_node * arg, c1_type * param_type, c1_type * * param_cursor, int param_index, c1_node * result, c1_symbol * fn, c1_type * type, c1_node * args, char compute_here);
void __fastcall ovl_add_deduced_specializations(c1_ovl_resolution * res);
c1_ovl_candidate * __fastcall ovl_reeliminate_survivors(c1_ovl_resolution * res);
c1_ovl_candidate * __fastcall ovl_prefer_by_object_qualifier(c1_ovl_resolution * res);
int __stdcall ovl_report_ambiguous_flag(char * flag);
c1_ovl_candidate * __fastcall ovl_resolve_call_no_best(c1_ovl_resolution * res);
c1_ovl_candidate * __fastcall ovl_operator_no_best(c1_ovl_resolution * res);
void __thiscall ovl_add_deduced_template_candidates(void * this, c1_symbol * sym);
int * __cdecl ovl_resolve_call_fail_exit(int * best);

void __fastcall yy_copy_token_value(void * dst, void * token);
char __fastcall declarator_flags56_bit0(c1_declarator * d);
void __stdcall parse_paren_depth_pop(void);
void __thiscall param_clause_set_cv_qualifiers(c1_param_clause * clause, c1_decl_modifier * cv);
void __thiscall param_clause_set_exception_spec(c1_param_clause * clause, int exception_spec);
void __cdecl parse_external_declaration_end(void);
undefined4 __stdcall parse_error_recovery_count(void);
c1_decl_modifier * __thiscall u16_value_init(c1_decl_modifier * mod, ushort bits);
void __thiscall declarator_set_kind(c1_declarator * d, c1_u32 kind);
c1_param_clause * __thiscall optional_value_init(c1_param_clause * clause, c1_u32 tag, c1_sym_list * params, char pop_scope);
c1_symbol * __fastcall value_word0(c1_symbol * * cell);
void __cdecl default_argument_store_and_advance_top(c1_node * expr);
void __cdecl yyparse_set_lookahead(byte * token);
void __thiscall parser_set_lookahead(c1_yy_parser * parser, byte * token);
char __fastcall value_byte1_bit4(c1_symbol * sym);
void __cdecl parse_resolve_candidate_token(char * token);
void __cdecl parse_default_argument_begin(c1_type * param_type);
char __cdecl parse_default_argument_needs_saving(void);
c1_arg_item * __thiscall arg_expression_item_init(c1_arg_item * item, c1_node * expr, c1_u8 given_explicitly, char keep_tree);
void __thiscall qualified_name_record_init(c1_ptr_operator * op, c1_overload_set * qual, c1_decl_modifier * mods, c1_decl_modifier * cv);
int __cdecl parse_translation_unit(void);
void __cdecl parse_translation_unit_cleanup(c1_parse_translation_unit_frame * frame);
void * __fastcall parser_stack_construct(int * stack);
void __fastcall parser_stack_zero_header(int * stack);
int __thiscall yyparse_cpp(c1_yy_parser * parser);
int __cdecl yyparse_cpp_ellipsis_parameter_arena0(c1_yy_value * value_base, c1_yy_parser * parser, int * state_sp, byte * saved_lookahead, int saved_rule);
int __cdecl parse_yacc_return_tail(byte * saved_lookahead, int saved_rule);
void __stdcall parser_stack_destruct(void);
void * * __fastcall parse_context_push(void * * saved);
void __cdecl parse_context_reset(void);
c1_arg_list * __cdecl parse_reparse_template_arguments(void * substream);
void __cdecl paren_depth_leave(int value);
char __cdecl parse_begin_compound_value(c1_node * node);
c1_symbol * __thiscall parse_type_id_declarator(c1_declarator * d, c1xx_decl_specifiers * spec);
c1_u8 * __cdecl parse_classify_candidate_token(char allow_decl);
char * __cdecl parse_resolve_candidate_token_if_flagged(char * token);
uint __stdcall parse_run_lookahead_classifier(void);
void * __fastcall lookahead_parser_construct(void * parser);
void __fastcall lookahead_parser_init(c1_yy_lookahead_parser * parser);
uint __fastcall yyparse_lookahead(c1_yy_lookahead_parser * parser);
uint __fastcall yyparse_lookahead_push(c1_yy_lookahead_parser * parser);
uint __fastcall yyparse_lookahead_return_1(void);
uint __fastcall yyparse_lookahead_case_1(c1_yy_value * value_top, c1_yy_lookahead_parser * parser);
void __stdcall lookahead_parser_destruct(void);
void __thiscall value_set_byte30(c1_declarator * d, c1_u8 op_token);
void __cdecl vtable_nop(void);
c1_u8 * __fastcall parse_check_missing_token(int * head, undefined4 param_2, char * token);
c1_declarator * __fastcall declarator_set_position(c1_declarator * declarator);
void __thiscall declarator_set_flags56_bit1(c1_declarator * d, char value);
c1xx_token * __cdecl parse_lookahead_token(void);
c1xx_token * __thiscall parse_record_tokens_to_delimiter(c1xx_token_stream * stream, c1_u32 stop_set, char keep_delimiter);
c1xx_token * __cdecl parse_save_default_argument_tokens(void);
void __thiscall value_set_field4(void * this, c1_type * type);
void __cdecl parse_paren_depth_push(int context);
char __fastcall value_byte1_bit5(c1_symbol * sym);
void __thiscall declarator_set_flags56_bit0(c1_declarator * d, c1_u8 bit);
byte __cdecl parse_no_saved_declspecs_below(int depth);
void __cdecl parse_scan_parenthesized_candidates(void);
void __cdecl asm_block_emit(void);
void __stdcall asm_instruction_reset(void);
int * __cdecl asm_operand_reset(int operand);
int __cdecl yyparse_asm(void);
byte * __stdcall asm_yylex(void);
int __cdecl asm_is_statement_end(c1_u8 token);
c1xx_token * __cdecl asm_classify_name(c1xx_token * token);
short __cdecl asm_lookup_instruction(fe_name * name);
void __cdecl asm_instruction_begin(short op);
short __cdecl asm_lookup_operand_keyword(fe_name * name);
c1_u8 * __cdecl asm_check_register_1(short reg);
c1_u8 * __cdecl asm_check_symbol(int name);
c1_symbol * __cdecl asm_lookup_name(fe_name * name, int labels_allowed);
int __cdecl asm_symbol_operand_size(c1_symbol * sym);
char __cdecl asm_size_class_of_bytes(int size);
c1_u8 * __cdecl asm_check_register_2(short reg);
void __cdecl asm_operand_add_displacement(int value);
void __cdecl asm_check_operand_count(void);
int __cdecl asm_operand_count_valid(void);
int __cdecl asm_operand_kinds_valid(void);
void __stdcall asm_finalize_instruction(void);
char __cdecl asm_instruction_size_class(void);
char __cdecl asm_operands_size_class(void);
char __stdcall asm_operands_size_class_fragment(short instruction_code, int operand_count);
void __cdecl asm_encode_operand_registers(void);
void __stdcall asm_build_instruction_record(void);
c1_u8 __cdecl asm_operand_mode(int * operand);
c1_u16 * __cdecl asm_record_put_symbol_key(c1_u16 * out, c1_u32 key);
void __cdecl asm_check_ptr_type(char size_code);
short * __cdecl asm_operand_node_new(int value);
short * __cdecl asm_check_constant_expression(short op, short * left, short * right);
short * __cdecl asm_check_segment_override(short seg_reg, short * operand);
void __thiscall declarator_set_flags54_bit5(c1_declarator * d, char value);
void __cdecl parse_template_argument_list_save_tail(byte * next_token, int paren_depth, uint c8_mask, int angle_depth, int cond_depth, byte * token);
void __cdecl parse_template_argument_list_overload_token(byte * overload_token, int paren_depth, uint c8_mask, int angle_depth, int cond_depth, byte * token);
c1_u8 * __cdecl parse_classify_candidate_token_exit(c1_u8 * result);
char * __cdecl parse_action_tail_ee16(char * name_token);
void __thiscall parse_record_asm_statement_tokens(c1xx_token_stream * stream);
int __fastcall yyparse_cpp_error_recovery(c1_yy_parser * parser);
int __cdecl yyparse_cpp_error_entry(int action, c1_yy_value * value_sp, int * state_sp, int state, c1_yy_parser * parser, c1_yy_action_slot action_slot, byte * saved_lookahead, int saved_rule);
int __cdecl yyparse_cpp_template_member_declaration_tail(c1_scope_stack * scopes, c1_u8 scope_kind, c1_symbol * sym, c1_yy_value * value_base, c1_yy_parser * parser, int * state_sp, byte * saved_lookahead, int saved_rule);
int __cdecl yyparse_cpp_zero_array_bound_error(c1_yy_value * value_base, c1_yy_parser * parser, int * state_sp, longlong bound, byte * saved_lookahead, int saved_rule);
int __cdecl yyparse_cpp_class_template_parameter_error(c1_symbol * param, c1_yy_value * value_base, c1_yy_parser * parser, int * state_sp, byte * saved_lookahead, int saved_rule);
int __cdecl yyparse_cpp_address_of_member_leaf(c1_node * leaf, c1_yy_value * value_base, c1_yy_value * value_top, c1_yy_parser * parser, int * state_sp, byte * saved_lookahead, int saved_rule);
int __cdecl yyparse_cpp_named_cast_expected_gt(c1_u8 close_code, c1_yy_value * value_base, c1_yy_parser * parser, int * state_sp, byte * saved_lookahead, int saved_rule);
void __fastcall parse_yyerrok(c1_yy_parser * parser);
void __cdecl parse_report_inserted_token(c1_u8 * lookahead, int terminal);
void * __cdecl parse_make_inserted_token_value(void * out, int terminal);
void __cdecl yyerror_cpp(char * msg);
c1xx_token * __cdecl parse_skip_tokens_to_one_of(c1xx_token * token, ...);
void __cdecl parse_error_resync_token(void);
void * __fastcall value_fieldc(void * record);
c1_u16 __fastcall value_u16_at2(c1_type * type);
void __thiscall qualified_type_merge(c1_decl_modifier * mods, c1_decl_modifier * other, c1_u32 eax_high);
void __cdecl parse_report_specifier_error(int n, c1_u32 * token_value);
void __cdecl asm_check_label_redefinition(int name);
void * __fastcall qualname_resolved_symbol(c1_declarator * d);
uint __fastcall parse_action_tail_e1(int errflag, int * parser);
uint __fastcall parse_action_tail_e3(int * parser);
uint __fastcall parse_action_tail_e2(uint * value_top, int * parser);
int __cdecl yyparse_lookahead_stack_overflow(void);
uint __cdecl yyparse_lookahead_return_0(void);
void __cdecl parse_table_yyerror_nop(char * msg);
void __cdecl pending_top_mark(void);
void __cdecl asm_report_syntax_error(char * message, int state);
c1_yy_value * __cdecl asm_parser_value_for_token(c1_yy_value * value, int kind);
void __cdecl asm_check_parser_stack(char * message);
void __stdcall asm_check_end_of_file(void);
void __cdecl asm_warn_ptr_operator(short size_keyword);
int __cdecl asm_symbol_length(c1_symbol * sym);
int __cdecl asm_check_member_operand(fe_name * name);
int __cdecl asm_operand_description_id(void);
void __cdecl asm_warn_directive(short directive, uint value);
void __cdecl asm_swap_words(int * a, int * b);
int __cdecl asm_complete_float_operands(void);
void __cdecl asm_report_operand_error(int n, int operand_count);
void __stdcall asm_encode_operand_registers_fragment(c1_u8 esp_code, int operand_count, c1_asm_operand_slot * slot);
void __stdcall asm_finalize_instruction_fragment(undefined4 esi);
int __cdecl asm_value_fits_bits(char bits, int value);
int __cdecl asm_slot_symbol_type_test(c1_asm_operand_slot * slot, short flag);
int __cdecl asm_slot_size_matches(c1_asm_operand_slot * slot, char size_class);
int __cdecl asm_operand_kinds_valid_fragment(void);
short * __cdecl asm_check_constant_operand(short op, short * left, short * right);
int __cdecl asm_check_scale(uint scale);
short * __cdecl asm_check_index_register(short op, short * left, short * right);
c1_u8 * __cdecl asm_check_constant_operand_2(short op, short * operand);
c1_u8 * __cdecl asm_check_operand_type(c1_u8 * operand);
short * __cdecl asm_check_register_3(short * operand);
c1_u8 * __cdecl asm_check_float_register(short reg, int st_index);

c1_line_map_row * __thiscall pp_line_map_find_entry(void * line_map, uint position);
void __cdecl pp_output_copy_comment(void);
int __cdecl pp_skip_blanks_in_macro_text(void);
int __cdecl pp_macro_invoke(fe_macro * macro);
int __cdecl pp_macro_copy_case_sentinel(byte c, int expanded, uint slash_next, uint after_slash, uint macro_slot);
int __cdecl pp_macro_expand(int expanded, uint slash_next, uint after_slash, uint macro_slot);
char __cdecl pp_macro_is_being_expanded(fe_macro * macro);
void __cdecl pp_macro_check_nesting(fe_macro * macro);
void __cdecl pp_macro_begin_replacement(void);
int __cdecl pp_macro_expansion_end(void);
char __cdecl pp_macro_scan_identifier(uint first_char);
char __cdecl pp_macro_scan_identifier_return_false(void);
void __cdecl pp_macro_text_append_string(uchar * text);
c1_line_map_row * __thiscall include_line_map_find(c1_line_map_state * state, int position);
byte __cdecl pp_directive_lookup_name(char * name);
c1_u8 * __cdecl pp_directive(void);
char __cdecl pp_skip_to_next_directive(void);
void __cdecl pp_warn_extra_tokens(char * directive);
int __cdecl pp_check_expected_endif(int mode);
byte * __cdecl pp_copy_quoted_text(byte * out, uint * limit, byte quote);
void __cdecl pp_macro_collect_arguments_text(fe_macro * macro, int nformals);
void __cdecl pp_macro_collect_arguments_formal_case(uchar * arg_start, char pasted, int paren_depth, uint cur_char, uint saved_c14, uint saved_c10, uint saved_c0c, uint saved_c08, uchar * saved_level, int macro, int nformals);
void __cdecl pp_macro_collect_arguments(uchar * text_cursor, byte ch, uchar * arg_start, char pasted, int paren_depth, uint cur_char, uint saved_c14, uint saved_c10, uint saved_c0c, uint saved_c08, uchar * saved_level, int macro, int nformals);
void __cdecl pp_macro_next_text_segment(void);
void __cdecl pp_macro_save_expansion(uint * start, int end);
short * __cdecl pp_macro_formal_argument_text(char * pasted);
int __cdecl pp_macro_formal_is_pasted(void);
int __cdecl pp_include_search_parents(byte * file, char quoted, byte * file2);
char __cdecl pragma_pointers_to_members_default(int * model_out);
void __cdecl pragma_warning_state_emit(byte code);
char * __fastcall pp_position_file_name(int * position);
void __cdecl include_record_set_name(c1xx_browse_record * rec);
int __cdecl pragma_process_saved_tokens(byte * token);
int __cdecl pragma_dispatch(void);
int __cdecl pragma_dispatch_return_zero_tail(void);
char __cdecl pragma_expect_dash_token(void);
uchar * __cdecl pragma_warn_expected_token(uchar want);
int __cdecl pp_include_pop_file(void);
c1_u8 * __cdecl pp_pragma_directive(void);
int __cdecl pragma_lookup_name(char * name);
void __cdecl pp_block_comment_dispatch(void);
void __cdecl pp_skip_block_comment(void);
void __cdecl pp_define_finish(c1_u8 * text, uint length, int kind);
uint __cdecl pp_cond_stack_push(void);
void __cdecl pp_include_push_file(int * file_record, int mode, int handle, byte browse);
c1_u8 * __cdecl include_record_new(int a, int b);
char * __cdecl pp_include_parse_filename(char report, char * angle);
c1_u8 * __cdecl pp_include_open_and_push(byte * file, char angle);
int __cdecl pp_include_open_file_2(byte * name, char angle);
char * __thiscall pp_include_alias_lookup(void * list, char * name, char * angle);
int __cdecl pp_include_search_path(byte * name, byte * dir, char parent_mode, char report, byte * out);
c1_u8 * __cdecl pp_include_directive_token(int value);
void __cdecl pragma_pack_push(int value, int ident);
void __cdecl pp_define_parse(uint from_directive);
void __stdcall pp_define_directive(void);
uint __cdecl pp_define_body(void);
void __cdecl pragma_pack_parse(void);
int __cdecl pragma_check_pack_value(int n);
short * __cdecl pp_macro_argument_text(void);
void __cdecl pp_macro_stringize(uint quote, byte * text);
void __cdecl pragma_hdrstop(char * * name);
int __fastcall include_path_try_next(int * iter);
void __cdecl import_ole_uninitialize(void);
void __cdecl include_alias_table_new(void);
void __cdecl pragma_pack_stack_init(void);
void __cdecl pp_time_now(void * t);
char * __cdecl pp_format_date_time_strings(uint timestamp);
void __cdecl pp_define_from_switch(byte * s);
void __cdecl pp_define_from_switch_copy_value_loop(void * is_space, byte * cursor, byte * value, char * name);
longlong __cdecl pp_if_evaluate_expression(void);
void * __cdecl pp_if_parse_conditional(void);
void * __cdecl pp_if_parse_logical_or(void);
void * __cdecl pp_if_parse_logical_and(void);
void * __cdecl pp_if_parse_bit_or(void);
void * __cdecl pp_if_parse_bit_xor(void);
void * __cdecl pp_if_parse_bit_and(void);
void * __cdecl pp_if_parse_equality(void);
void * __cdecl pp_if_parse_relational(void);
void * __cdecl pp_if_parse_shift(void);
void * __cdecl pp_if_parse_additive(void);
void * __cdecl pp_if_parse_multiplicative(void);
c1_pp_value * __cdecl pp_if_parse_primary(void);
int __cdecl pp_if_accept_token(byte token);
c1_pp_value * __cdecl pp_if_fold_operator(byte op, c1_pp_value * left, c1_pp_value * right);
char * __cdecl pp_include_parse_angle_name(char report);
int __cdecl pp_include_check_path(char * name, int report, char * found);
void __cdecl pp_undef_directive(void);
void __cdecl pp_define_parse_formals(void);
int __cdecl pp_define_find_formal(byte * name);
void __cdecl pragma_section_record(int kind, int id, char * text);
void __cdecl pragma_section_attribute(char * file, int fd);
int __cdecl pp_if_parse_defined(int name);
void __cdecl pragma_pack_pop(int value, int name);
void __cdecl pragma_warning_check_number(uint n, byte state);
c1_u8 * __cdecl pragma_string_argument(void);
void __cdecl pragma_on_off_option(void);
c1_u8 * __cdecl pragma_check_on_off(void);
void __cdecl pragma_on_off_value(void);
void __cdecl pragma_once(void);
bool __cdecl pp_include_top_is_pseudo_file(void);
void __cdecl pragma_message_text(void * stream, int message);
void __cdecl pragma_component(void);
void __cdecl pragma_parse_list(void * each);
void __cdecl pragma_component_set_name_references(fe_name * name);
void __cdecl pragma_function_one(fe_name * name);
void __cdecl pp_output_skip_comment(void);
int __cdecl pp_current_file_mtime(void);
char __cdecl include_close_outer_handle(void);
void __cdecl pp_line_output_reset(void);
void __cdecl include_close_all(void);
byte * __cdecl pp_quote_file_name(byte * dst, byte * name);
void __cdecl pp_emit_line_directive(void);
void __stdcall pp_define_finish_text_fragment(void);
uint __cdecl pp_input_file_flag8(void);
int __cdecl pragma_lookup_unknown(void);
void __cdecl pp_undef_macro_with_pch_check(void);
void __cdecl pp_define_check_token(uint ch);
void __cdecl pp_define_check_formals_token(uint ch, byte cur_ch);
void __cdecl pp_define_install(fe_name * name, int kind, fe_macro * binding, uint length, c1_u8 * text);
uint __cdecl pp_define_check_paste(byte ch, byte * out, int stringize, uint ch_cell, int charize);
void __cdecl pp_define_check_size(uint cursor, int base, int * limit);
int __cdecl pp_macro_mark_not_expandable(int expanded, uint slash_next, uint after_slash, uint macro_slot);
int __cdecl pp_macro_expand_defined_in_if(byte * cursor, int expanded, uint slash_next, uint after_slash, uint macro_slot);
void __cdecl pp_macro_location(int n);
c1xx_token * __cdecl pragma_parse_argument(int kind);
c1xx_token * __cdecl pragma_parse_identifier(int kind);
void __cdecl pragma_warning_push(void);
void __cdecl pragma_warning_pop(void);
int __cdecl pragma_check_integral_constant(void);
int __cdecl pragma_start_map_region(void);
int __cdecl pragma_implementation_key(void);
void __cdecl pragma_skip_to_dash(byte * token);
int __cdecl pragma_warn_unknown(char * token);
void __cdecl pragma_include_alias(void);
int __cdecl pp_pragma_directive_to_output(void);
void __cdecl pp_capture_directive_text(void);
void __cdecl pragma_message_indent(int indent, char * file);
int __cdecl pp_pragma_directive_pch(void);
c1_u8 * __cdecl pp_line_directive(void);
int __cdecl pp_check_expected_endif_pragma_tail(byte last, int mode, int depth);
void __cdecl pp_output_copy_literal(byte first, char wide);
void __cdecl pp_output_skip_comment_slow_char(uint c, byte * input, void * put_char_to, void * put_char);
void __cdecl pp_skip_line_tokens(char lead_class, c1_fputc_fn fputc_fn);
void __cdecl pp_skip_line_whitespace_fragment_newline(char lead_class, c1_fputc_fn fputc_fn);
void __cdecl pp_line_after_pch_options(void);
void __cdecl pragma_init_seg_set_atexit(int name);
void __cdecl pragma_intrinsic_one(fe_name * name);
void __cdecl pragma_alloc_text_name(fe_name * name);
void __cdecl pp_run_preprocess_only(void);
void __cdecl pp_import_record_dependency(char * file);
void __cdecl pp_warn_include_depth(void);
void __thiscall mre_note_queue_push(c1_mre_note * * pending, int kind, c1_symbol * cls, void * member);
int __cdecl mre_class_ensure_records(c1_symbol * cls);
char __thiscall mre_note_queue_drain(c1_mre_tracker * tracker);
char __thiscall mre_note_class_records(c1_mre_tracker * tracker, c1_symbol * cls);
void * __thiscall import_map_take_implementation_key(c1_import_key_list * list, uint key, char no_open);
char * __cdecl pp_expand_line_macro(void);
void __fastcall import_init_ole(char * done);
void __thiscall import_text_putc(c1_il_buffer * buf, int c);
void __thiscall import_text_puts(c1_il_buffer * buf, char * s);
void __cdecl import_text_printf(c1_il_buffer * buf, char * format, ...);
void __thiscall import_flush_text_to_file(c1_il_buffer * buf, void * stream, char * path);
void __thiscall import_text_append(c1_il_buffer * src, c1_il_buffer * dst);
c1_import_depgraph * __thiscall import_depgraph_init(c1_import_depgraph * graph, int n);
void __thiscall import_depgraph_add_edge(c1_import_depgraph * graph, int from, int to);
byte __thiscall import_depgraph_is_ready(void * graph, int item);
int __fastcall import_depgraph_first_pending(void * graph);
int __fastcall import_depgraph_next_ready(void * graph);
void __thiscall import_depgraph_mark_emitted(c1_import_depgraph * graph, int item);
void __thiscall import_depgraph_force_emit(c1_import_depgraph * graph, int item);
c1_u8 * __cdecl wide_to_multibyte_arena(wchar_t * wide);
wchar_t * __cdecl import_apply_rename(wchar_t * name);
byte __cdecl import_exclude_unless_included(wchar_t * name);
byte __cdecl import_is_excluded(wchar_t * name, int typekind);
byte __cdecl import_typedesc_equal(void * a, void * b);
byte __cdecl import_typedesc_differ(void * a, void * b);
void __cdecl import_write_guid_string(c1_il_buffer * buf, c1_guid * guid);
void __cdecl import_write_guid_initializer(c1_il_buffer * buf, c1_guid * guid);
void __cdecl import_write_named_guid(void * guid, char * prefix, wchar_t * name);
wchar_t * __cdecl import_namespace_for_typeinfo(int * buf3, char qualify_own);
bool __cdecl import_typeinfo_in_current_library(void * typeinfo, uint * index);
byte __cdecl import_get_ref_type_info(void * typeinfo, uint hreftype, void * * result);
bool __cdecl import_coclass_default_interface(c1_itypeinfo * typeinfo, void * typeattr, c1_itypeinfo * * out_typeinfo, c1_typeattr * * out_typeattr);
void __cdecl import_write_typedesc(c1_il_buffer * buf, void * typedesc, void * typeinfo, wchar_t * name, int qualify_own);
void __cdecl import_write_typedesc_comment(c1_il_buffer * buf, c1_typedesc * typedesc, void * typeinfo);
int __cdecl import_write_wrapper_type(c1_il_buffer * buf, void * typedesc, void * typeinfo, int qualify_own);
void __cdecl import_write_wrapper_param_type(c1_il_buffer * buf, c1_typedesc * typedesc, void * typeinfo, wchar_t * name);
void __cdecl import_write_raw_param_type(c1_il_buffer * buf, void * typedesc, void * typeinfo, wchar_t * name);
byte __cdecl import_vt_by_const_ref(ushort vt);
byte __cdecl import_vt_is_bstr_wrapper(short vt);
ushort __cdecl import_typedesc_to_vartype(c1_itypeinfo * typeinfo, void * typedesc);
ushort __cdecl import_vartype_or_invalid(void * typeinfo, void * typedesc);
void __cdecl import_write_vartype_name(c1_il_buffer * buf, ushort vt);
void __cdecl import_write_dispid(c1_il_buffer * buf, int dispid);
void __cdecl import_write_dispid_number(c1_il_buffer * buf, int dispid);
void __cdecl import_emit_dispatch_property(void * typeinfo, void * vardesc, wchar_t * class_name, wchar_t * name);
void __cdecl import_emit_record_fields(void * typeinfo, void * typeattr, wchar_t * class_name);
void __cdecl import_write_calling_convention(c1_il_buffer * buf, int callconv);
wchar_t * * __cdecl import_rename_param_names(wchar_t * * names, int n, int count);
wchar_t * __cdecl import_param_name(int index, wchar_t * * names);
void __cdecl import_emit_vtable_method(void * typeinfo, void * funcdesc, wchar_t * class_name);
bool __cdecl import_emit_dispatch_method(void * typeinfo, void * funcdesc, wchar_t * class_name);
void __cdecl import_emit_property_declspec(void * typeinfo, void * get_funcdesc, void * put_funcdesc, wchar_t * class_name);
void __cdecl import_emit_vtable_gap(int n);
void __cdecl import_emit_functions(void * typeinfo, void * typeattr, wchar_t * class_name, int next_vft_offset);
void * __fastcall import_enum_table_init(void * table);
void __fastcall import_enum_table_free(void * table);
byte __thiscall import_enum_table_find(void * table, wchar_t * name);
void __thiscall import_enum_table_get(void * table, char * * enum_name, int * value);
void __thiscall import_name_list_push(c1_import_enum_table * table, wchar_t * enum_name, int value);
void __cdecl import_emit_enum(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_emit_struct_or_union(char * keyword, void * typeinfo, c1_typeattr * typeattr, wchar_t * name);
void __cdecl import_emit_interface_struct(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_emit_dispinterface_struct(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_emit_coclass(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_write_forward_reference(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_emit_type_item(void * typeinfo, void * typeattr, wchar_t * name);
void __cdecl import_write_file_banners(int syskind);
void __cdecl import_write_pragma_once_pack(void);
void __cdecl import_write_pack_pop(void);
void __cdecl import_write_cross_referenced_libraries(void);
int __cdecl import_count_wrapper_functions(void * typelib, uint count);
void __cdecl import_collect_dependencies(void * typeinfo, void * typeattr, int index, void * graph);
void __cdecl import_emit_deferred_item(void * typelib, int index);
byte __cdecl import_emit_typelib(c1_itypelib * typelib);
void __cdecl import_register_library(char * path);
c1_u8 * __cdecl pp_import_parse_line(c1_vector * * out, char * angle);
uint __cdecl import_attributes_signature(void * attributes, char * tlb, char * tlh, char * tli);
void __cdecl pp_import_parse_attributes(c1_vector * attributes);
char * __cdecl env_path_next_dir(char * list, char * buf, int size);
byte __cdecl import_search_env_path(char * file, char * variable, char * result);
char * __cdecl import_find_typelib_file(char * file, char angle);
void __cdecl import_make_output_names(char * tlb, char * * tlh, char * * tli);
byte __cdecl import_output_is_current(char * tlb, char * output, int * tlb_mtime);
char __cdecl pp_import_directive(char * file, c1_vector * attributes, char angle, char * * tlh_out, char * * tli_out, byte * regenerated);
int __fastcall map_pair_grow_if_full(void * map);
void * __thiscall array8_init_count(void * array, uint n);
int __thiscall array8_set_size(c1_pair_array * array, uint n);

void __cdecl func_flow_state_reset_if_used(void);
void __cdecl stmt_emit_condition(c1_node * node, c1_node * n, uint jump_if_true);
void __cdecl func_flow_state_note_3e(void);
byte __cdecl init_emit_initializer_expression(c1_node * node, c1_conversion * conv);
void __cdecl eh_mark_state_nodes_in_tree(c1_node * node);
void __cdecl eh_collect_state_markers(int * list_head, c1_node * tree, char no_stamp);
void __cdecl eh_register_local_destructor(c1_symbol * sym);
int __cdecl init_member_initializer(c1_symbol * sym, c1_node * mem_initializers);
void __cdecl eh_enter_try(void);
void __cdecl eh_leave_try(void);
void __cdecl func_emit_return_this(int is_ctor);
void __cdecl eh_flush_pending_state_c2(void);
void __cdecl eh_push_state(void);
void __cdecl eh_pop_state(void);
void __cdecl eh_flush_pending_state(void);
c1_node * __cdecl init_take_base_initializer(int * list, byte * base);
int __cdecl eh_check_state_count(c1_symbol * cls);
int __cdecl eh_state_of_entry(int index);
c1_node * __cdecl eh_build_state_table(c1_node * list, c1_node * src);
void __cdecl func_begin_definition_state(int * pos);
void __cdecl eh_register_temporary_destructor(c1_node * node, c1_type * type);
int __cdecl eh_release_temporary_state(int temp);
c1_parse_state * __fastcall func_parse_state_save(c1_parse_state * rec);
void __fastcall func_parse_state_pop(c1_u8 * * saved);
void __fastcall func_parse_state_restore(c1_parse_state * rec);
int __cdecl init_member_initializer_store(int offset, ushort * type, c1_node * value, byte * member);
int __cdecl init_is_char_array_string_init(c1_symbol * sym, c1_node * node);
c1_symbol * __cdecl init_begin_variable(c1_symbol * sym);
void __cdecl eh_push_array_init_state(c1_symbol * sym);
void __cdecl init_simple_initializer(c1_symbol * sym, c1_node * value);
c1_node * __cdecl init_record_constant_value(c1_symbol * sym, c1_node * init);
void __stdcall init_end_declaration(c1_symbol * sym);
void __cdecl eh_pop_array_init_state(void);
c1_node * __cdecl eh_walk_handler_states(c1_node * left, c1_flow_state * rec, int mode, c1_node * flag);
void __cdecl func_flow_state_note_11(void);
void __cdecl stmt_if_condition_begin_flow_state(void);
c1_node * __cdecl stmt_check_controlling_expression(c1_node * cond, int is_switch);
void __cdecl stmt_if_then_begin_flow_state(void);
void __cdecl stmt_if_condition_end_flow_state(void);
void __cdecl stmt_if_then_end_flow_state(int end_of_if);
void __cdecl stmt_if_end_flow_state(void);
void __cdecl func_check_flow_state_complexity(c1_u8 * record, uint size);
void __cdecl func_flow_state_release(c1_flow_state * rec);
void __stdcall func_flow_state_pop_record(void);
c1_flow_state * __cdecl flow_state_alloc_from_free_list(byte size_class);
void __stdcall func_flow_state_reset(void);
c1_symbol * __cdecl func_body_begin(c1_symbol * fn);
void __cdecl func_reset_line_markers(void);
void __cdecl func_record_alloc(c1_symbol * sym);
void __stdcall func_begin_definition_frame(void);
void __cdecl func_body_begin_emit(void);
void __cdecl func_flow_state_push(c1_symbol * fn, void * param_scope);
void __cdecl func_flow_state_note(void);
void __cdecl eh_register_destructible_object(c1_symbol * sym, byte flag);
void __cdecl func_flow_state_note_3(void);
void __cdecl func_begin_compound_statement(void);
void __cdecl func_flow_state_note_f(void);
void __cdecl stmt_emit_return_value(c1_node * node, int kind);
void __cdecl func_end_compound_statement(c1_node * block, char begun);
void __cdecl func_flow_state_pop(void);
void __cdecl func_finish_eh(int member_class);
void __cdecl eh_check_try_with_unwinding(void);
void __cdecl stmt_check_missing_return_value(void);
void __cdecl stmt_emit_pending_destructors(void);
void __stdcall funcs_check_incremental(void);
void __cdecl func_emit_end(int flag);
void __cdecl func_end_emit_il(c1_symbol * sym);
void __thiscall func_in_write_key(c1_il_buffer * buf, uint key);
void __cdecl func_clear_local_side_tables(void);
void __cdecl eh_flush_function_data(void);
void __cdecl eh_emit_pending_data_objects(void);
c1_symbol * __thiscall func_begin_member_definition(c1_declarator * d, byte * specs);
void __cdecl func_emit_function_symbol(void);
void __cdecl func_flow_state_note_8(void);
c1_flow_state * __cdecl func_flow_state_find(c1_flow_state * rec, int kind, char longjmp_if_missing);
void __cdecl eh_merge_state_markers(c1_node * node);
void __cdecl stmt_emit_merged_expression(c1_node * tree);
int __cdecl func_has_unreferenced_label(void);
void __cdecl eh_check_goto_targets(void);
void __cdecl eh_enter_new_expression_region(void);
c1_node * __cdecl eh_leave_new_expression_region(void);
void __cdecl init_set_target_symbol(c1_symbol * sym);
void __cdecl inline_function_instance_new(c1_symbol * sym);
void __cdecl stmt_emit_expression(c1_node * node);
void __cdecl func_parse_definition_or_skip(c1_symbol * sym, char skip_local_member_check);
void __stdcall func_parse_definition_or_skip_return(void);
void __cdecl func_flow_state_pop_unless_sizeof(void);
void __cdecl init_construct_class_object(c1_symbol * sym, int args);
void __cdecl init_begin_dynamic_initializer(c1_symbol * sym);
void __cdecl init_warn_local_static_thread_safety(c1_symbol * sym);
c1_node * __cdecl init_collect_destructible_item(void * obj_type, c1_node * item);
ushort __cdecl init_check_array_bounds(c1_symbol * sym, c1_node * node);
void __cdecl init_emit_data(c1_symbol * sym);
int __cdecl init_string_array_room(c1_symbol * sym, uint str);
void __cdecl func_flow_state_note_43(void);
void __cdecl init_emit_symbol_data(c1_symbol * key, c1_node * node, c1_il_buffer * buf);
void __cdecl init_emit_initializer(c1_symbol * sym, c1_node * node, c1_il_buffer * buf);
void __cdecl init_emit_item_by_format(int kind, c1_il_buffer * buf, c1_node * node, int addr_offset, c1_symbol * addr_sym, int is_string, float float_value, uint type_code, uint const_lo, int const_hi, uint dbl_lo, uint dbl_hi, uint value0, uint value1, c1_x87_tail value2, c1_symbol * sym, c1_node * node_param, char value_is_integer);
void __cdecl stmt_else_begin_flow_state(void);
void __cdecl stmt_else_end_flow_state(void);
int __cdecl func_wants_inline(c1_symbol * fn);
c1_node * __cdecl func_new_compiler_generated(c1_node * str, void * literal_name, byte pooled, char in_inline_function);
void __cdecl init_emit_relocations_to_buffer(c1_symbol * key, c1_node * node);
void __cdecl stmt_new_loop_label(c1xx_label_cell * * stack, int role);
c1_flow_state * __cdecl func_flow_state_find_next(c1_flow_state * rec, int kind, char longjmp_if_missing);
void __cdecl stmt_loop_end(void);
void __cdecl func_flow_state_note_31(void);
void __cdecl stmt_switch_selector_begin_flow_state(void);
void __cdecl stmt_switch_head(int node);
void __cdecl stmt_switch_body_begin_flow_state(c1_type * selector_type);
void __cdecl stmt_switch_selector_end_flow_state(void);
void __cdecl stmt_case_label(c1_node * node);
void __cdecl stmt_case_label_flow_state(c1_node * case_value);
void __cdecl stmt_check_case_skips_initialization(int is_case);
void __cdecl stmt_switch_end(void);
void __stdcall stmt_warn_switch_without_cases(void);
void __cdecl stmt_switch_body_end_flow_state(void);
void __stdcall stmt_jump_flow_state(void);
void __stdcall stmt_default_label_flow_state(void);
void __cdecl func_flow_state_note_25(void);
void __cdecl stmt_for_test_begin_flow_state(void);
void __cdecl func_flow_state_note_27(void);
void __cdecl stmt_for_step_begin_flow_state(void);
void __cdecl stmt_for_head(c1_node * node, c1_node * node2, c1_node * node3);
void __cdecl func_flow_state_note_2a(void);
void __cdecl stmt_for_step_end_flow_state(void);
void __stdcall stmt_for_end_flow_state(void);
void __cdecl stmt_for_body_end_flow_state(void);
int __cdecl init_split_address_constant(c1_node * node, void * * base, int * offset);
int __cdecl init_split_address_constant_offset_case(c1_node * node, int * offset, int zero, void * * base);
int __cdecl init_split_address_constant_case2_fragment(c1_node * node, void * * base);
void __cdecl func_check_argument_bytes(int sym);
int __cdecl func_parameter_bytes(c1_type * fntype);
void __cdecl func_emit_definition_record(c1xx_function_record * rec);
int __cdecl init_aggregate_element(c1_symbol * sym, int * value, int conv);
int __fastcall init_check_member_kind(c1_conversion * conv);
void __cdecl init_begin(c1_symbol * sym, char force_selectany_check);
void __cdecl init_push_brace_level(c1_symbol * sym);
void __cdecl init_process_initializer(c1_node * value, int no_dynamic);
int __cdecl init_aggregate_members(c1_node * value);
uint __cdecl init_descend_to_member(int value);
int * __cdecl init_next_member_to_initialize(c1_symbol * obj, int * member);
int __cdecl init_advance_member(void);
int __cdecl init_never_too_many(void);
int __cdecl init_level_mark_complete_tail(byte * level, int one);
void __cdecl init_finish(c1_symbol * sym);
void __cdecl init_finish_variable(c1_symbol * sym);
void __cdecl init_pop_brace_level(void);
int __cdecl init_count_remaining_elements(void);
void __cdecl init_construct_remaining_elements(void);
int __cdecl init_unsized_array_count(void);
void __cdecl func_flow_state_note_19(void);
void __cdecl stmt_while_condition_begin_flow_state(void);
void __stdcall stmt_while_head(void);
void __cdecl stmt_emit_loop_test(c1_node * cond);
void __cdecl func_flow_state_note_1c(void);
void __cdecl stmt_while_condition_end_flow_state(void);
void __cdecl stmt_while_end_flow_state(void);
void __cdecl stmt_while_body_end_flow_state(void);
c1_node * __cdecl init_member_select_by_index(c1_node * src, uint mode);
c1_node * __cdecl eh_build_exit_state_change(c1_node * left, int name, c1_flow_state * rec, c1_node * flag);
void __stdcall init_check_too_many_2(void);
c1_node * __cdecl eh_state_marker(c1_node * expr, int unused, c1_flow_state * rec);
void __stdcall stmt_jump_flow_state_2(void);
void __cdecl func_body_begin_generated(c1_symbol * fn);
c1_symbol * __cdecl func_new_dynamic_initializer(void);
void __cdecl func_definition_end(char push_dynamic_init);
void __cdecl func_emit_atexit_registration(c1_symbol * fn);
void __cdecl init_emit_crt_initializer_pointer(c1_symbol * fn);
void __cdecl init_static_guard_begin(void);
void __cdecl func_abandon_definition(void);
void __cdecl func_flow_state_note_1f(void);
void __cdecl stmt_do_body_begin_flow_state(void);
void __stdcall stmt_do_head(void);
void __cdecl func_flow_state_note_22(void);
void __cdecl stmt_do_body_end_flow_state(void);
void __cdecl stmt_do_end_flow_state(void);
void __cdecl stmt_do_condition_end_flow_state(void);
void __cdecl stmt_define_label(int name);
void __cdecl stmt_label_definition_flow_state(c1_symbol * label);
void __cdecl stmt_goto_flow_state(c1_symbol * label, int defined);
c1_flow_state * __cdecl stmt_find_label_flow_state(c1_symbol * label);
void __cdecl eh_scope_setjmp_guard(c1_flow_state * from_rec, c1_flow_state * to_rec, int mode);
c1_flow_state * __cdecl stmt_jump_unwind_step(c1_node * * expr, c1_flow_state * rec, int mode, int target);
uint __cdecl stmt_check_goto_skips_initialization_return_fragment(uint * rec);
void __cdecl func_emit_vcall_thunk_body(c1_vcall_thunk_key * key, c1_symbol * thunk);
void __cdecl init_set_array_dimension(c1_symbol * align_member);
uint __cdecl func_takes_void_parameters(c1_symbol * fn);
c1_node * __cdecl init_template_static_member(c1_node * left, c1_node * item, int value, c1_node * item2);
void __cdecl init_write_reloc_record(int kind, int key, int length);
int __cdecl func_argument_bytes(int scope);
int __cdecl flow_record_names_temporary(char * node, int temp);
void __cdecl func_reset_state(void);
void __cdecl func_emit_end_reset_state(int zero);
void __cdecl init_member_memcpy_string(c1_type * t, int offset, c1_node * str);
void __cdecl init_member_array_elements(c1_symbol * member, c1_symbol * elem_class, c1_node * inits, int offset, char copy_mode);
int __cdecl init_member_initializer_fragment_c2439(c1_symbol * member, uint member_flag, int * member_link, c1_symbol * sym, c1_node * mem_initializers);
int __cdecl init_member_initializer_fragment_c2758(c1_symbol * member, uint member_flag, int * member_link, c1_symbol * sym, c1_node * mem_initializers);
uint __cdecl init_value_is_class_call(c1_node * value);
int __cdecl func_check_naked_and_setjmp(c1_symbol * fn, c1_symbol * leaf_sym, char object_known, c1_symbol * access_sym, c1_node * object, int callee_right, int argc, c1_node * args);
c1_node * __cdecl init_collect_destructible_item_member(c1_symbol * cls_tag, c1_node * item, void * obj_type);
void __cdecl stmt_report_undefined_label(c1_symbol * label);
void __cdecl stmt_warn_unreferenced_label(c1_symbol * label);
void __stdcall eh_labels_leave_try_scope(void);
c1_node * __cdecl init_element_lvalue(c1_type * type);
void __cdecl init_emit_zero_fill(void);
void __cdecl stmt_emit_intrinsic_call(int intrinsic, c1_node * args);
void __cdecl init_emit_element_store(c1_symbol * sym, c1_node * node, c1_u8 * node2);
void __cdecl func_static_guard_variable(c1_node * node32);
void __cdecl init_check_string_initializer(char type_code_lo, c1_type * sym_type, c1_type * array_type, c1_symbol * sym, c1_node * value);
void __cdecl init_check_non_aggregate(c1_symbol * sym, c1_symbol * level_sym, int scalar_flag);
int __cdecl init_aggregate_members_fail_tail(void);
int * __cdecl init_find_member_for_offset(int offset, int * member, c1_member_walk * walk);
uint __cdecl init_partial_array_remainder(void);
void __cdecl init_end_declaration_static_dtor_fragment(c1_symbol * sym);
void __cdecl init_record_reset_fragment(c1_symbol * sym);
void __cdecl init_finish_array(int sym);
void __cdecl func_define_dynamic_initializer(c1_symbol * sym, int init, c1_node * item);
void __cdecl init_emit_placement_construct(c1_symbol * sym);
int __cdecl init_element_access(c1_node * node, c1_node * list);
c1_node * __cdecl init_chain_as_comma_list(c1_node * list);
void __cdecl stmt_check_return_in_constructor(c1_node * node, int kind);
void __cdecl stmt_return(int kind);
void __stdcall stmt_check_switch_expression(undefined4 edi, c1_node * node);
void __cdecl stmt_check_duplicate_case(void * * found, void * * prev, uint value_lo, int value_hi, void * * rec);
void __stdcall eh_check_leave(void);
void __cdecl eh_except_emit_filter(c1_node * filter);
void __cdecl eh_finally_begin(void);
void __cdecl eh_try_begin(void);
void __cdecl eh_try_block_end(void);
void __cdecl eh_except_end(void);
void __cdecl eh_finally_end(void);
void __cdecl eh_except_filter_begin(void);
void __cdecl eh_except_filter_end(void);
void __cdecl stmt_report_jump_into_try(c1_symbol * label);
void __cdecl init_write_in_record_fields(c1_type * type, uint code_word, c1_il_buffer * buf, c1_node * node, int addr_offset, c1_symbol * addr_sym, int is_string, char * fmt, float float_value, uint type_code, uint const_lo, int const_hi, uint dbl_lo, uint dbl_hi, uint value0, uint value1, c1_x87_tail value2, c1_symbol * sym, c1_node * node_param, char value_is_integer);
void __cdecl init_check_illegal(c1_il_buffer * buf, c1_node * node, int addr_offset, c1_symbol * addr_sym, int is_string, char * fmt, float float_value, uint type_code, uint const_lo, int const_hi, uint dbl_lo, uint dbl_hi, uint value0, uint value1, c1_x87_tail value2, c1_symbol * sym, c1_node * node_param, char value_is_integer);
void __cdecl p1inl_new_key_default(int str);
char * __cdecl mre_qualified_name_text(byte * sym);
byte * __cdecl mre_member_name_text(void * sym2, int key);
void __cdecl eh_catch_handler_flow_state(c1_symbol * handler_sym);
void __cdecl eh_register_named_object_destructor(c1_symbol * sym, c1_type * type);
int __cdecl sizeof_is_active(void);
void __cdecl node_list_push(int * head, int value);
int __cdecl eh_state_find_by_source_number(int number);
void __cdecl eh_build_throw_info(uint * list, int by_number);
void __stdcall func_flow_state_drop_kind_d(void);
void __thiscall stmt_check_switch_type(void * this, undefined4 edi, undefined4 conv);
void __stdcall stmt_warn_switch_default(c1_flow_state * prev_case, c1_flow_state * sw, c1_flow_state * case_rec, void * * subject_slot);
void __cdecl stmt_switch_constant_selector_flow_state(int value);
void __cdecl func_flow_state_release_innermost(int kind);
c1_node * __cdecl flow_walk_object_state_change_fragment(int zero, int * rec, c1_node * result, byte * frame);
c1_flow_state * __cdecl func_flow_state_find_not_found(char longjmp_if_missing);
uint __cdecl stmt_jump_unwind_step_case5_fragment(uint * rec, c1_node * * expr, int mode);
c1_flow_state * __cdecl func_flow_state_skip_kind_d(c1_flow_state * rec);
c1_flow_state * __cdecl func_flow_state_last_of_kind_d_run(c1_flow_state * rec);
c1_catch_handler * __thiscall eh_exception_type_init(c1_catch_handler * rec, c1_type * type);
char * __thiscall eh_append_cv_letters(c1_catch_handler * type_rec, char * out);
void __cdecl eh_catchable_type_path(int * value);
void __cdecl eh_warn_throw_type_access(c1_catchable_type * ct);
c1_symbol * __cdecl eh_new_compiler_data_object(void * name, c1_type * * type_cache, char * type_name, int segment_kind);
void * __cdecl eh_intern_prefixed_type_name(c1_type * type, char * prefix);
c1_symbol * __cdecl eh_catchable_type_symbol(c1_catchable_type * ct, int * pmd, c1_symbol * copy_fn);
c1_catchable_type * __cdecl eh_catchable_type_init(c1_catchable_type * rec, c1_type * type, char no_members);
uint __cdecl eh_catchable_type_access_flags(c1_catchable_type * ct, char no_members);
int __cdecl eh_catchable_type_register(c1_catchable_type * ct, char rtti_walk);
uint * __cdecl eh_next_catchable_type(uint * value, int flag);
c1_symbol * __cdecl eh_catchable_type_array_symbol(c1_type * type, c1_vector * catchables, int count);
c1_vector * __cdecl eh_collect_catchable_types(ushort * type, int flag);
int __cdecl eh_count_usable_catchable_types(c1_vector * catchables);
c1_symbol * __cdecl eh_throw_info_symbol(c1_type * type, c1_vector * * catchables);
void __cdecl init_emit_address_or_zero(int sym);
void __cdecl init_emit_pmfn_item(c1_symbol * sym);
void __cdecl eh_emit_catchable_type(int * item);
void __cdecl eh_emit_catchable_type_array(int * item);
void __cdecl eh_emit_throw_info(c1_throw_info_item * item);
c1_catch_handler * __cdecl eh_add_catch_handler(c1_symbol * catch_param);
char __cdecl eh_check_catch_type_count(c1_param_clause * clause);
void __stdcall eh_check_handling_enabled(void);
void __stdcall eh_check_try_has_catch(void);
void __cdecl init_emit_int_table(c1_symbol * sym, int * values, int count);
c1_arg_list * __thiscall eh_handler_list_copy(c1_arg_list * list, c1_arg_list * src);

bool __fastcall block_scope_has_entries(c1xx_block_scope * scope);
char __cdecl tmpl_queue_used_member_bodies(void);
c1_u8 * __thiscall block_scope_lookup_by_kind(c1xx_block_scope * scope, int name, uint kind_mask, byte * found);
c1_u8 * __thiscall block_scope_lookup(void * this, int name, int kind);
void __thiscall block_scope_insert(void * type2, c1_symbol * sym2);
c1_symbol * __thiscall block_scope_find_name(c1_sym_list * list, int name);
void * __thiscall tmpl_argument_list_init(void * iter, void * list);
void * __cdecl tmpl_lookup_parameter_list(void * key);
void __thiscall tmpl_argument_list_prepend(c1_arg_list * list, c1_arg_item * item);
void __cdecl tmpl_resolve_template_name_token(c1_u8 * * token, c1_symbol * qualifier, char leading_global);
c1_symbol * __cdecl tmpl_parse_arguments(c1_symbol * tmpl, c1_arg_list * args, char dependent);
byte __cdecl tmpl_check_argument_list(c1_symbol * tmpl, c1_sym_list * params, c1_arg_list * * args);
byte __cdecl tmpl_complete_argument_list(c1_symbol * tmpl, c1_sym_list * params, c1_arg_list * * args, uint * count);
byte __cdecl tmpl_check_arguments(c1_symbol * tmpl, c1_sym_list * param_list, c1_arg_list * * args, uint unused4);
ushort __cdecl tmpl_type_find_parameter(c1_type * type, int skip_template_template, int param_id);
ushort __cdecl tmpl_param_type_id_matches(c1_type * type, int param_id);
char __cdecl tmpl_arguments_are_concrete(int * args);
void * __cdecl tmpl_template_of_instance(c1_symbol * key);
void __cdecl tmpl_pending_push(void * item);
void __cdecl tmpl_work_queue_add(c1_symbol * sym, int * args);
void __thiscall tmpl_work_queue_add_item(void * queue, c1_symbol * sym, int * args);
c1_tmpl_work_item * __thiscall tmpl_work_queue_find(c1_tmpl_work_item * * queue, c1_symbol * sym);
void __cdecl tmpl_pending_pop(void);
void __fastcall block_scope_emit_il(c1xx_block_scope * scope);
void __fastcall tmpl_instantiate_if_needed(c1_symbol * cls);
void __fastcall tmpl_instantiate_if_incomplete(c1_symbol * cls);
void __cdecl tmpl_prune_instance_list(c1_symbol * sym);
c1_deferred_parse * __thiscall tmpl_instantiation_context_init(c1_deferred_parse * rec, c1_symbol * fn, c1_type * * param_type, c1_node * default_arg, c1_deferred_parse * prev);
c1_arg_item * __cdecl tmpl_argument_from_expression(c1_node * expr);
void __cdecl tmpl_parse_queued_definition(c1_template_header_record * header);
void __fastcall tmpl_work_queue_run(c1_tmpl_work_item * * queue);
void __fastcall tmpl_instance_members_run(c1_tmpl_work_item * item);
void __fastcall tmpl_instance_members_loop_fragment(int end, c1_tmpl_work_item * item, char pushed_state, uint explicit_flag, int member_link, int member_next);
char __cdecl tmpl_instantiate_instance_member(c1_symbol * instance, c1_symbol * member, char explicit_inst);
void __cdecl tmpl_instantiate_member(c1_symbol * tmpl, c1_symbol * instance, c1_symbol * tmpl_member, int * inst_args, c1_symbol * member);
void * __cdecl tmpl_definition_table_lookup(void * key);
void __stdcall tmpl_check_nested_definition(void);
void __thiscall template_parameter_scope_push(c1_scope_stack * stack, c1_sym_list * params);
c1_symbol * __cdecl tmpl_declare_type_parameter(fe_name * name);
void __thiscall template_parameter_scope_link(c1xx_template_parameter_scope * template_parameter_scope, c1_symbol * sym);
void * __cdecl tmpl_header_end(void * parameter_table);
c1_arg_list * __cdecl tmpl_header_take_parameter_list(void);
void __cdecl tmpl_close_parameter_scope(void);
void __cdecl tmpl_set_parameter_list(c1_sym_list * params, c1_symbol * tmpl);
void __cdecl tmpl_set_warning_state(c1_symbol * tmpl, int * warning_snapshot);
void __cdecl tmpl_set_definition_tokens(c1xx_token_stream * tokens, c1_symbol * tmpl);
void __cdecl tmpl_finish_nonclass_template_declaration(c1_yy_value * head, c1_symbol * sym);
void __cdecl tmpl_finish_function_template_declaration(c1_yy_value * head, c1_symbol * fn);
void __cdecl tmpl_record_definition(c1_symbol * tmpl, c1_sym_list * params, c1xx_token_stream * decl_tokens, c1xx_token_stream * body_tokens);
void __cdecl tmpl_definition_table_insert(void * value, c1_symbol * key);
void * __stdcall tmpl_record_class_body_tokens(void);
void __cdecl tmpl_finish_class_template_declaration(c1_yy_value * head, c1xx_decl_specifiers * spec);
void __cdecl tmpl_check_parameter_lists_match(int value, void * key);
void __cdecl tmpl_check_class_redefinition(undefined4 value, int key);
c1_symbol * __cdecl tmpl_instantiate_generic_instance_untracked(c1_symbol * tmpl);
c1_symbol * __cdecl tmpl_instantiate_generic_instance(c1_symbol * tmpl);
c1_arg_list * __cdecl tmpl_arguments_from_parameters(c1_sym_list * params);
void __cdecl tmpl_instantiate(c1_symbol * tmpl, c1_symbol * instance);
void __fastcall deferred_body_list_push(c1_deferred_body_list * * head);
c1xx_block_scope * __cdecl tmpl_bind_arguments(c1_sym_list * params, c1_arg_list * args, c1_symbol * tmpl, char in_block, char prefix, int prefix_count);
c1xx_block_scope * __thiscall tmpl_binding_scope_new(c1_scope_stack * stack, c1_sym_list * symbols);
int __cdecl tmpl_argument_is_local_extern(c1_symbol * sym);
void * __fastcall tmpl_enclosing_class_scope(void * scope);
undefined4 __stdcall tmpl_check_specialization_after_instantiation(undefined4 ebx, undefined4 state);
int __cdecl tmpl_check_declaration_scope(void);
c1_arg_item * __thiscall tmpl_list_item_construct(c1_arg_item * item, byte kind, byte flag);
void __thiscall tmpl_explicit_instantiation_without_specifiers(c1_declarator * d, int storage_class);
c1_symbol * __cdecl tmpl_find_overload_by_signature(c1_symbol * set, c1_symbol * member, c1_arg_list * inst_args);
void __thiscall tmpl_argument_copy_base(c1_arg_item * copy, c1_arg_item * src);
c1_arg_item * __thiscall tmpl_argument_copy_nontype(c1_arg_item * copy, c1_arg_item * src);
c1_symbol * __thiscall tmpl_check_reference_parameter(c1_symbol * sym, c1_declarator * d);
c1_symbol * __thiscall tmpl_check_typedef_redefinition(void * name, int zero);
c1_symbol * __cdecl tmpl_declare_type_parameter_alloc_record(undefined4 saved_ebp, undefined4 saved_ebx, c1_u16 proto_code, int zero);
short __cdecl tmpl_expression_parameter_id(char * expr, short param_id);
c1_symbol * __thiscall block_scope_find_tag(c1_sym_list * list, int name);
void * __thiscall block_scope_find_link_unimplemented(c1xx_block_scope * scope, int entry);
void __thiscall block_scope_lookup_anonymous_member(c1xx_block_scope * scope, void * name, int * found);
byte __cdecl vtable_false_al(void);
c1_u8 * __thiscall block_scope_lookup_tag(c1xx_block_scope * scope, int name);
c1_symbol * __cdecl tmpl_match_explicit_arguments(c1_symbol * sym, c1_arg_list * args);
c1_tmpl_deduction * __cdecl tmpl_deduce_from_overloaded_argument(c1_tmpl_deduction * deduction, c1_symbol * sym, c1_arg_list * explicit_args, c1_type * type, c1_symbol * * specialization);
void __cdecl tmpl_push_member_class_context(c1_symbol * cls);
c1_tmpl_deduction * __stdcall tmpl_deduce_from_function_name_argument(c1_tmpl_deduction * deduction, c1_type * type, c1_node * arg);
c1_tmpl_deduction * __thiscall tmpl_deduce_from_call(c1_ovl_resolution * res, c1_symbol * sym);
c1_tmpl_deduction * __thiscall tmpl_deduce_from_operands(c1_ovl_resolution * res, c1_symbol * sym);
c1_tmpl_deduction * __thiscall tmpl_deduction_begin(c1_tmpl_deduction * deduction, c1_symbol * sym, c1_arg_list * explicit_args, byte member_match, char require_all);
c1_tmpl_deduction * __thiscall tmpl_deduction_copy(c1_tmpl_deduction * copy, c1_tmpl_deduction * src);
c1_type * __cdecl tmpl_normalize_argument_type(c1_type * type);
char __thiscall tmpl_unify_parameter(c1_tmpl_deduction * this, c1_type * t, c1_type * type);
int __thiscall tmpl_unify_constant_argument(c1_tmpl_deduction * deduction, c1_node * pattern, c1_node * src);
char __thiscall tmpl_unify_types(c1_tmpl_deduction * deduction, c1_type * type, c1_type * type2, char top_level);
byte __thiscall tmpl_deduce_from_argument_type(c1_tmpl_deduction * deduction, c1_type * type, c1_node * arg);
char __fastcall tmpl_specialize_function(c1_tmpl_deduction * deduction);
char __fastcall tmpl_check_explicit_argument_kinds(c1_tmpl_deduction * deduction);
char __fastcall tmpl_check_deduced_arguments(uint * deduction);
byte __thiscall tmpl_compare_argument_lists(c1_tmpl_deduction * deduction, c1_symbol * fn);
c1_symbol * __cdecl tmpl_deduce_from_target_type(c1_type * type, c1_symbol * sym, byte resolve_flags);
void __cdecl tmpl_deduce_from_function(c1_type * type, c1_symbol * sym, short * * specializations, byte resolve_flags);
void __fastcall tmpl_deferred_report_c2780(c1xx_obj_104cee94 * action);
void __fastcall tmpl_deferred_report_c2896(c1xx_obj_104cee7c * action);
void __fastcall tmpl_deferred_report_c2784(c1xx_obj_104cee9c * action);
void __fastcall tmpl_deferred_report_c2782(c1xx_obj_104cee98 * action);
void __fastcall tmpl_deferred_report_c2783(c1xx_obj_104ceeac * action);
void __fastcall tmpl_deferred_report_c2785(c1xx_obj_104ceea0 * action);
void __fastcall tmpl_deferred_report_c2901(c1xx_obj_104ceec4 * action);
void __fastcall tmpl_deferred_report_c2893(c1xx_obj_104ceea4 * action);
void __fastcall tmpl_deferred_report_c2975(c1xx_obj_104ceea8 * action);
void __fastcall tmpl_instantiate_function_definition(c1xx_tmpl_function_item * item);
void __fastcall tmpl_function_item_run(c1xx_tmpl_function_item * item);
void __fastcall tmpl_instance_static_member_fragment(int member, int end, c1_tmpl_work_item * item, char pushed_state, uint explicit_flag, int member_link, int member_current, int member_next);
void __fastcall tmpl_work_item_pch_relocate(c1_tmpl_work_item * item);
void __fastcall tmpl_function_item_pch_relocate(c1xx_tmpl_function_item * item);
void __stdcall tmpl_check_declaration_context(void);
void __thiscall tmpl_explicit_instantiation(c1_declarator * d, c1_u8 prefix_keyword, c1xx_decl_specifiers * spec);
void __cdecl tmpl_resolve_function_template_name_token(c1_u8 * * token, c1_symbol * qualifier);
int * __cdecl tmpl_default_arguments_lookup(void * tmpl);
c1_type * __cdecl tmpl_substitute_type(c1_type * type, c1_arg_list * args);
void __cdecl tmpl_merge_default_arguments(c1_arg_list * defaults, c1_symbol * tmpl);
void __cdecl tmpl_set_default_arguments(c1_arg_list * defaults, c1_symbol * tmpl);
c1_arg_item * __cdecl tmpl_evaluate_default_argument(c1_symbol * tmpl, c1_sym_list * params, c1_arg_list * args, c1_node * saved_default, int known_count);
void __fastcall tmpl_context_note(c1_tmpl_context_note * ctx);
int __cdecl tmpl_parameters_equal(int a, int b);

c1_type * __cdecl type_intern(c1_type * proto);
c1_function_params * __cdecl type_function_intern(c1_function_params * params);
c1_type * __thiscall type_rebuild_chain(c1_type * proto, c1_type * stop);
void __fastcall type_check_declarator_kind(c1_declarator * d);
void __fastcall type_check_function_cast_and_bitfield(c1_declarator * d);
c1_type_list * __cdecl type_list_intern(int * list, uint hash);
void __fastcall type_check_based_allocation_return_case(void);
void __thiscall type_pair_record_init(c1_ptr_operator * op, c1_decl_modifier * mods, c1_decl_modifier * cv);
void __thiscall type_check_array_declarator(c1_decl_record * rec, c1_type * layer);
void __fastcall type_check_array_bound_constant(c1_declarator * d);
c1_type * __fastcall type_skip_arrays(c1_type * t);
c1_type * __thiscall type_reference_to(c1_type * type, char variant_4000);
int __cdecl type_argument_size(c1_type * t, char promote);
int __fastcall type_size(c1_type * t);
int __fastcall type_size_scalar(c1_type * t);
int __fastcall type_size_derived(c1_type * t);
int __cdecl type_compare_template_instance_chain(c1_type * a, c1_type * b);
int __fastcall type_is_class_or_enum(c1_type * type);
int __fastcall type_is_template_type_parameter(c1_type * type);
c1_type * __fastcall type_function_return(c1_type * type);
c1_node * __cdecl type_fold_integer_constant_fragment(c1_type * type, uint value_lo, int value_hi, c1_node * k, c1_node * unary);
int __fastcall type_category(c1_type * type);
c1_type * __cdecl type_get_base(c1_type * type);
c1_type * __fastcall type_base(c1_type * type);
uint __cdecl type_function_arity_match(c1_type * fn_type, uint arg_count);
int __cdecl type_set_find(short * set, int value, int * index_out);
c1_type * __fastcall type_strip_cv_qualifiers(c1_type * type);
c1_type * __thiscall type_pointer_with_qualifiers(c1_type * type, ushort pointer_flags);
c1_type * __thiscall type_without_flags(c1_type * type, ushort clear_bits);
int __cdecl type_size_checked(c1_type * type);
c1_symbol * __cdecl type_require_complete(c1_symbol * sym);
byte __thiscall type_derivations_equal(c1_type * type, c1_type * type2);
char __cdecl type_set_equal(short * a, short * b);
c1_type * __cdecl type_function_map_parameters(c1_type * type, void * callback);
c1_function_params * __cdecl type_params_make_static(c1_function_params * params);
short * __cdecl type_set_union(short * set, short * other);
int __cdecl type_member_pointer_size_kind(c1_type * t);
c1_u16 __thiscall type_check_based_member_pointer(c1_decl_record * rec, c1_u16 modifiers, c1_u16 cv);
char __fastcall type_has_linkage_for_template(c1_type * type);
c1_type * __cdecl type_with_storage_bits(c1_type * type, byte bits);
void __cdecl type_check_destructible(c1_symbol * sym);
uint __cdecl type_classify_class_form(c1_type * type, int * cls_out);
void __cdecl type_check_destructible_2(c1_symbol * sym);
int __cdecl type_function_param_count(c1_function_params * fn_params);
char __thiscall type_compare_function(c1_type * a, c1_type * b, uint flags);
c1_type * __cdecl type_promoted_integral(c1_type * type);
void __cdecl format_options_set(uint bits);
void __cdecl format_qualified_name(int buf, byte * sym);
void __cdecl format_buffer_append_string(int buf, char * s);
char * __cdecl format_buffer_reserve(int buf, int at_end, uint n);
char * __cdecl format_buffer_text(int handle);
void __cdecl format_options_clear(uint bits);
c1_type * __fastcall type_skip_arrays_and_functions(c1_type * type);
uint * __cdecl type_strip_modifier_bits(uint * type);
c1_u8 __cdecl type_check_bitfield_width(c1_symbol * member, uint width_lo, int width_hi);
c1_type * __cdecl type_this_pointer(c1_symbol * cls, c1_u16 pointer_flags, ushort cv);
int __cdecl format_buffer_acquire(void);
int __cdecl format_buffer_alloc(void);
c1_text_buffer * __cdecl format_buffer_find(int handle);
void __cdecl format_buffer_leave(void);
void __cdecl format_buffer_free(int handle);
c1_type * __thiscall type_with_base(c1_type * type, c1_type * base);
uint __cdecl type_compare_parameter_lists(int * a, int * b);
c1_type * __thiscall type_with_added_qualifiers(c1_type * type, ushort bits);
c1_type * __thiscall type_replace_in_chain(c1_type * type, c1_type * layer, c1_type * replacement);
void __thiscall type_check_based_form(c1_decl_record * rec, c1_decl_modifier * mod);
uint __cdecl type_merge_qualifiers(uint first, uint second);
c1_type * __cdecl type_descriptor_copy_transient(c1_type * desc);
ushort __thiscall type_check_based_reference(c1_decl_record * decl, ushort modifiers);
void __fastcall type_check_reference_to_bitfield(c1_declarator * d);
void __thiscall type_warn_qualifiers_on_reference(c1_ptr_operator * op, c1_decl_modifier * mods, c1_decl_modifier * cv);
c1_type * __cdecl type_intern_basic_parts(c1_u16 code, c1_u16 flags, c1_u32 extra);
char __thiscall type_compare(c1_type * a, c1_type * b, uint flags);
int __cdecl format_vsnprintf(char * buf, char * fmt, int size, char * args);
void __thiscall format_args_init(c1_message * message, char * format, int * args);
int __cdecl format_snprintf(char * buf, char * fmt, int size, ...);
c1_type * __cdecl type_chain_rebuild(c1_type * type, void * keep, void * map, int arg);
bool __cdecl type_is_not_array(c1_type * type);
c1_type * __cdecl type_strip_cv(c1_type * type);
int __cdecl type_debug_member_function_index(c1_symbol * sym);
void __cdecl format_class_template_instance_name(int buf, c1_symbol * cls);
int __cdecl format_undecorated_name(int buf, fe_name * name);
c1_u8 * __cdecl format_undname_alloc(int size);
c1_type * __thiscall type_member_pointer_to_2(c1_type * type, char variant);
c1_type * __cdecl type_member_pointer_to_3(c1_type * type, int plain);
char __cdecl type_compare_function_types(c1_function_params * fn1, c1_function_params * fn2, uint mode);
char __thiscall type_compare_member_pointer(c1_type * a, c1_type * b, uint flags);
c1_type * __cdecl type_pointer_to(c1_u16 pointer_flags);
c1_type * __cdecl type_record_new_45f0(int void_ptr_flags, ushort modifier);
int __cdecl type_chain_is_cv_qualified(c1_type * t);
c1_u8 __fastcall type_is_void(c1_type * type);
void __cdecl type_string_literal_array(c1_node * literal);
c1_type * __fastcall type_as_function_code(c1_type * type);
uint __fastcall type_calling_convention_bits(ushort * type);
void __cdecl type_tables_init(void);
void __fastcall type_descriptor_clear(c1_type * t);
c1_type * __cdecl type_basic(ushort code);
c1_type * __cdecl type_intern_from_parts(c1_type * type, c1_u16 code, c1_u16 flags, c1_u32 * extra);
c1_u32 __cdecl type_member_pointer_class(c1_type * type);
c1_type * __cdecl type_member_pointer_to(c1_type * type);
void __thiscall type_check_array_bound_constant_2(void * d, c1_node * node);
char __fastcall type_code_is_201(c1_type * type);
char __fastcall type_code_is_202(c1_type * type);
c1_type * __cdecl type_int(void);
int __cdecl type_int_size(void);
int __cdecl format_symbol_declaration_text(c1_symbol * sym, c1_type * type);
int __cdecl format_type_name_text(int buf, c1_type * type, char trailing_space);
char * __cdecl type_keyword_text(ushort code);
void __cdecl format_buffer_append_char(int buf, char c);
int __cdecl format_symbol_name_and_declarator(c1_symbol * sym, c1_type * type);
int __cdecl format_declarator_suffix_text(int buf, ushort * type);
int __cdecl format_pointer_declarator_text(int buf, c1_type * type);
void __cdecl format_buffer_prepend_char(int buf, char c);
int __cdecl format_calling_convention_text(int ctx, void * emit, ushort modifier, int based, c1_type * type);
void __cdecl format_buffer_prepend_string(int buf, char * s);
int __cdecl type_pointer_attributes_compatible(ushort flags, ushort target_flags);
c1_symbol * __cdecl type_emission_stack_top(void);
byte __fastcall type_code_high_bit(c1_type * type);
c1_u8 __fastcall type_is_cv_qualified_stripped(c1_declarator * d);
c1_type * __fastcall type_innermost_base(c1_type * type);
uint __cdecl type_based_on_pointer_variable(c1_type * type);
c1_symbol * __cdecl type_parse_based_specifier(void * name);
c1_node * __cdecl type_based_base(c1_type * type);
c1_node * __cdecl type_based_pointer_from_node(c1_type * type, c1_node * value);
uint __cdecl type_compare_parameter_lists_tail(void);
c1_type * __cdecl type_as_member_function(c1_type * type);
void __cdecl type_check_size_known(c1_type * type);
int __fastcall type_size_fragment(c1_type * elem);
int __cdecl type_argument_size_promoted(c1_type * t, char derived);
int __cdecl type_codes_equal(short a, short b);
char __fastcall type_is_class_or_template_parameter(c1_type * type);
c1_type * __cdecl type_member_pointer_checked(c1_type * type);
c1_function_params * __cdecl type_params_drop_this(c1_function_params * params);
int __cdecl type_array_element_count(c1_type * type, c1_type * * element);
c1_type * __cdecl type_array_to_pointer(c1_type * array_type);
c1_type * __fastcall type_array_innermost_element(c1_type * array_type);
c1_type * __fastcall type_strip_based(c1_type * type);
c1_type * __thiscall type_member_function_pointer_for_set(c1_type * function_type, c1_symbol * set);
c1_type * __thiscall type_with_qualifier_bits(c1_type * type, ushort bits);
c1_type * __thiscall type_strip_qualifiers_unless_all(c1_type * type, c1_u16 bits);
c1_type * __fastcall type_strip_code_variant_bits(c1_type * type);
byte __thiscall type_derivations_equal_tail(c1_type * type);
void __thiscall type_function_with_return(c1_type * layer, c1_type * this_type);
int __cdecl format_declspec_prefix(int buf, uint bits, void * segment, int spec_08, int uuid, int spec_10, byte class_flags);
int __cdecl format_decl_specifiers_text(int buf, uint bits, void * segment, uint spec_08, uint uuid, uint spec_10, uint class_flags);
int * __cdecl format_buffer_find_miss(void);
char * __cdecl format_buffer_text_trimmed(int buf);
char * __cdecl format_template_parameter_name(short code);
int __cdecl format_class_name(c1_symbol * cls);
int __cdecl format_cv_suffix(int buf, c1_type * this_type);
int __cdecl format_symbol_name_text(int buf, c1_symbol * sym);
c1_dlist_node * __cdecl dlist_node_new(c1_dlist_node * next, c1_dlist_node * prev);
c1_symbol * __cdecl type_class_symbol(c1_type * type);
c1_u8 * __cdecl rtti_base_displacement_pmd(int * path);
uint __cdecl type_member_pointer_class_has_vfptr(c1_type * type);
byte __cdecl type_member_pointers_same_null(c1_type * a, c1_type * b);
byte __cdecl type_member_pointer_is_aggregate(c1_type * type);
int __cdecl type_data_member_pointer_size(c1_type * t);
int __cdecl rtti_base_class_descriptor_symbol(c1_symbol * cls, c1_u8 * * record_out, int * path);
int __cdecl rtti_collect_base_class_descriptors(int cls, c1_vector * v, uint * attributes, int parent, int * path_cursor);
int __cdecl rtti_base_class_array_symbol(c1_symbol * cls, int * count_out, uint * attributes);
int __cdecl rtti_class_hierarchy_descriptor_symbol(int cls);
c1_symbol * __cdecl rtti_type_descriptor_symbol(int type);
c1_symbol * __cdecl rtti_symbol_new(c1_symbol * cls, int vptr_offset, int cd_offset, void * name);
void __cdecl rtti_emit_base_class_descriptor(int * item);
void __cdecl rtti_emit_base_class_array(int * item);
void __cdecl rtti_emit_class_hierarchy_descriptor(int * item);
c1_symbol * __stdcall rtti_type_info_vftable_symbol(void);
void __cdecl rtti_emit_type_descriptor(int * item);
void __cdecl rtti_emit_complete_object_locator(int * item);
void __cdecl rtti_emit_pending_descriptors(void);
void __cdecl rtti_reset_pending_descriptors(void);

extern undefined DAT_104bc268;
extern undefined4 DAT_104bc284;
extern undefined1 DAT_104bc288;
extern undefined g_type_rank_table;
extern undefined1 DAT_104bc2ad;
extern undefined1 DAT_104bc2ae;
extern undefined1 DAT_104bc2af;
extern undefined1 DAT_104bc2b0;
extern undefined1 DAT_104bc2b3;
extern undefined DAT_104bc2c2;
extern undefined DAT_104bc2cc;
extern undefined DAT_104bc2d0;
extern c1_il_code_row g_il_symbol_record_templates[25];
extern undefined DAT_104bc3b0;
extern undefined DAT_104bc3b4;
extern undefined DAT_104bc3b8;
extern undefined DAT_104bc3bc;
extern undefined DAT_104bc3c0;
extern undefined DAT_104bc3c6;
extern undefined DAT_104bc3ca;
extern undefined DAT_104bc3d0;
extern undefined DAT_104bc3d8;
extern undefined DAT_104bc3e4;
extern undefined DAT_104bc3e8;
extern undefined DAT_104bc3fa;
extern undefined DAT_104bc400;
extern undefined DAT_104bc408;
extern undefined DAT_104bc40c;
extern undefined DAT_104bc414;
extern undefined DAT_104bc420;
extern undefined DAT_104bc430;
extern undefined DAT_104bc438;
extern undefined DAT_104bc444;
extern undefined DAT_104bc44c;
extern undefined DAT_104bc45c;
extern c1_u32 g_browse_record_zero[6];
extern c1_u32 g_tree_op_to_il_op[250];
extern byte g_browse_symbol_types[28];
extern byte g_browse_excluded_kinds[32];
extern undefined DAT_104bcaec;
extern c1_seh_scope g_pp_position_file_name_scopetable;
extern undefined DAT_104bcb04;
extern undefined DAT_104bcb8c;
extern undefined DAT_104bcb90;
extern undefined DAT_104bcb94;
extern byte g_browse_base_access_bits[4];
extern undefined DAT_104bcbb6;
extern c1_seh_scope g_diag_format_message_scopetable;
extern undefined DAT_104bcbd8;
extern undefined DAT_104bcbe0;
extern undefined DAT_104bcbe4;
extern undefined DAT_104bcbe8;
extern undefined DAT_104bcbec;
extern undefined g_pragma_subop_codes;
extern undefined DAT_104bcd44;
extern undefined DAT_104bcd48;
extern undefined1 DAT_104bcd56;
extern undefined1 DAT_104bcd57;
extern c1_u32 g_op_flags_table[249];
extern undefined g_directive_letter_index_base;
extern char * g_directive_names[15];
extern sbyte g_directive_letter_index[29];
extern int g_directive_codes[15];
extern undefined DAT_104bd1d8;
extern undefined DAT_104bd1e8;
extern undefined DAT_104bd1ec;
extern undefined DAT_104bd1f2;
extern undefined DAT_104bd1f4;
extern undefined DAT_104bd214;
extern undefined DAT_104bd218;
extern undefined DAT_104bd21c;
extern undefined DAT_104bd224;
extern char g_pp_if_elif_spelling;
extern pointer g_il_op_shapes;
extern undefined DAT_104bd844;
extern undefined DAT_104bd890;
extern undefined g_flow_kind_partner_biased;
extern pointer g_side_effect_visitor_vtable;
extern c1_u32 g_flow_kind_partner[40];
extern undefined DAT_104bda60;
extern undefined DAT_104bda64;
extern undefined DAT_104bda66;
extern undefined DAT_104bda6a;
extern pointer g_debug_record_formats;
extern undefined DAT_104bdb18;
extern undefined DAT_104bdb1c;
extern undefined DAT_104bdb20;
extern undefined1 DAT_104bdb30;
extern undefined1 DAT_104bdb31;
extern undefined1 DAT_104bdb32;
extern undefined1 DAT_104bdb33;
extern undefined1 DAT_104bdb34;
extern undefined1 DAT_104bdb35;
extern undefined DAT_104bdb44;
extern c1_conversion_rule g_conversion_rules[256];
extern char * g_pragma_names[0];
extern undefined g_pragma_name_first_by_char;
extern undefined g_pragma_name_end_by_char;
extern int g_pragma_codes[58];
extern undefined DAT_104be548;
extern undefined DAT_104be578;
extern undefined DAT_104be5c8;
extern undefined DAT_104be5cc;
extern undefined DAT_104be5e4;
extern undefined DAT_104be5e8;
extern undefined DAT_104be600;
extern undefined DAT_104be618;
extern undefined DAT_104be628;
extern c1_declspec_attribute g_declspec_attribute_table[13];
extern undefined DAT_104be8f8;
extern undefined1 DAT_104be93c;
extern undefined1 DAT_104be93e;
extern undefined1 DAT_104be93f;
extern undefined4 DAT_104be940;
extern undefined DAT_104be946;
extern c1_builtin_helper g_builtin_helper_table[1];
extern ImgDelayDescr __DELAY_IMPORT_DESCRIPTOR_ole32;
extern ImgDelayDescr __DELAY_IMPORT_DESCRIPTOR_OLEAUT32;
extern undefined __NULL_DELAY_IMPORT_DESCRIPTOR;
extern undefined * g_calling_convention_names;
extern short g_lookahead_yy_exca[64];
extern byte g_lookahead_yy_exca_index[264];
extern short g_lookahead_yy_action[1638];
extern short g_lookahead_yy_pact[302];
extern short g_lookahead_yy_pgo[62];
extern byte g_lookahead_yy_r1[184];
extern byte g_lookahead_yy_r2[184];
extern short g_lookahead_yy_chk[302];
extern short g_lookahead_yy_def[302];
extern undefined1 DAT_104c01fb;
extern undefined DAT_104c01fc;
extern undefined DAT_104c021c;
extern undefined DAT_104c0220;
extern undefined DAT_104c03e8;
extern undefined DAT_104c0498;
extern undefined DAT_104c04d8;
extern undefined DAT_104c0540;
extern undefined DAT_104c0548;
extern undefined DAT_104c054c;
extern undefined DAT_104c0554;
extern undefined DAT_104c0568;
extern undefined DAT_104c0570;
extern undefined DAT_104c0580;
extern undefined DAT_104c05a0;
extern undefined DAT_104c05a8;
extern undefined DAT_104c05be;
extern undefined DAT_104c05c0;
extern undefined DAT_104c05c4;
extern undefined DAT_104c05c6;
extern undefined DAT_104c05ca;
extern char * g_token_spelling[248];
extern undefined DAT_104c0d00;
extern undefined DAT_104c0d04;
extern undefined DAT_104c0d9c;
extern undefined DAT_104c0d9e;
extern undefined DAT_104c0dbe;
extern undefined DAT_104c0e5e;
extern undefined DAT_104c0e74;
extern undefined DAT_104c0e78;
extern undefined DAT_104c0e7a;
extern undefined DAT_104c0e80;
extern undefined DAT_104c0e84;
extern undefined DAT_104c0e86;
extern undefined DAT_104c0e8a;
extern undefined DAT_104c0e8e;
extern undefined DAT_104c0e90;
extern undefined DAT_104c0e92;
extern undefined DAT_104c0e96;
extern undefined DAT_104c0e9a;
extern undefined DAT_104c0e9c;
extern undefined DAT_104c0ea0;
extern undefined DAT_104c0ea4;
extern undefined DAT_104c0eaa;
extern undefined DAT_104c0eb0;
extern undefined DAT_104c0eb4;
extern undefined DAT_104c0eb8;
extern undefined DAT_104c0ebc;
extern undefined DAT_104c0ebe;
extern undefined DAT_104c0ec2;
extern undefined DAT_104c0ec6;
extern undefined DAT_104c0ec8;
extern undefined DAT_104c0ecc;
extern undefined DAT_104c0ed0;
extern undefined DAT_104c0ed2;
extern undefined DAT_104c0ed6;
extern undefined DAT_104c0ee2;
extern undefined DAT_104c0ee6;
extern undefined DAT_104c0eea;
extern undefined DAT_104c0f40;
extern c1_seh_scope g_parse_translation_unit_scopetable;
extern short g_yy_exca[146];
extern byte g_yy_exca_index[768];
extern short g_yy_action[4060];
extern short g_yy_pact[802];
extern short g_yy_pgo[202];
extern byte g_yy_r1[496];
extern byte g_yy_r2[496];
extern short g_yy_chk[802];
extern short g_yy_def[802];
extern undefined g_arena_descriptors;
extern undefined1 g_arena_pch_flags;
extern undefined1 DAT_104c4c70;
extern undefined DAT_104c4d18;
extern undefined DAT_104c4d24;
extern undefined DAT_104c4d30;
extern undefined1 DAT_104c4d34;
extern undefined1 DAT_104c4d35;
extern c1_seh_scope g_run_exit_handlers_scope_table;
extern c1_seh_scope g_reset_data_section_scope_table;
extern void * g_static_initializer_table[38];
extern void * g_static_initializer_table_end;
extern undefined DAT_104c4f58;
extern undefined4 DAT_104c4f64;
extern c1_seh_scope g_main_guarded_scope_table;
extern undefined1 DAT_104c4f98;
extern undefined1 DAT_104c4f99;
extern undefined1 DAT_104c4f9c;
extern undefined1 DAT_104c4f9d;
extern undefined1 DAT_104c4fa0;
extern undefined1 DAT_104c4fa1;
extern undefined DAT_104c4fa8;
extern c1_switch_letter_row g_switch_table_Z_letters[13];
extern c1_switch_row g_switch_table[106];
extern undefined DAT_104c5554;
extern undefined DAT_104c55a4;
extern undefined DAT_104c55ac;
extern undefined DAT_104c55b4;
extern undefined DAT_104c55b8;
extern undefined DAT_104c55c8;
extern undefined DAT_104c55d8;
extern undefined DAT_104c55e0;
extern undefined DAT_104c55e4;
extern undefined DAT_104c55ec;
extern undefined DAT_104c55f4;
extern undefined DAT_104c55f8;
extern undefined DAT_104c55fc;
extern undefined DAT_104c5604;
extern undefined DAT_104c5608;
extern undefined DAT_104c5610;
extern undefined DAT_104c5618;
extern undefined DAT_104c5620;
extern undefined DAT_104c5628;
extern undefined DAT_104c5630;
extern undefined DAT_104c5638;
extern undefined DAT_104c5640;
extern undefined DAT_104c5648;
extern undefined DAT_104c5650;
extern undefined DAT_104c5658;
extern undefined DAT_104c565c;
extern undefined DAT_104c5660;
extern undefined DAT_104c5668;
extern undefined DAT_104c5670;
extern undefined DAT_104c5684;
extern undefined DAT_104c5688;
extern undefined DAT_104c568c;
extern undefined DAT_104c5690;
extern undefined DAT_104c5694;
extern undefined DAT_104c5698;
extern undefined DAT_104c569c;
extern undefined DAT_104c56a0;
extern undefined DAT_104c56a4;
extern undefined DAT_104c56a8;
extern undefined DAT_104c56b0;
extern undefined DAT_104c56c0;
extern undefined DAT_104c56c4;
extern undefined DAT_104c56c8;
extern undefined DAT_104c56d0;
extern undefined DAT_104c56d8;
extern undefined DAT_104c56e0;
extern undefined DAT_104c56e8;
extern undefined DAT_104c56f0;
extern undefined DAT_104c56f4;
extern undefined DAT_104c56fc;
extern undefined DAT_104c5704;
extern undefined DAT_104c5708;
extern undefined DAT_104c570c;
extern undefined DAT_104c5710;
extern undefined DAT_104c5714;
extern undefined DAT_104c5718;
extern undefined DAT_104c571c;
extern undefined DAT_104c5720;
extern undefined DAT_104c5724;
extern undefined DAT_104c5728;
extern undefined DAT_104c573c;
extern undefined DAT_104c5744;
extern undefined DAT_104c5748;
extern undefined DAT_104c5750;
extern undefined DAT_104c5758;
extern undefined DAT_104c5760;
extern undefined DAT_104c5764;
extern undefined DAT_104c5768;
extern undefined DAT_104c576c;
extern undefined DAT_104c5770;
extern undefined DAT_104c577c;
extern undefined DAT_104c5784;
extern undefined DAT_104c578c;
extern undefined DAT_104c5794;
extern undefined DAT_104c579c;
extern undefined DAT_104c57a0;
extern undefined DAT_104c57a4;
extern undefined DAT_104c57a8;
extern undefined DAT_104c57b0;
extern undefined DAT_104c57b4;
extern undefined DAT_104c57bc;
extern undefined DAT_104c57c0;
extern undefined DAT_104c57c4;
extern undefined DAT_104c57c8;
extern undefined DAT_104c57cc;
extern undefined DAT_104c57d0;
extern undefined DAT_104c57d4;
extern undefined DAT_104c57dc;
extern undefined DAT_104c57ec;
extern undefined4 g_default_warning_levels;
extern undefined4 DAT_104c57fc;
extern undefined4 DAT_104c5800;
extern undefined4 DAT_104c5804;
extern undefined4 DAT_104c5808;
extern int g_crc16_feedback_bits[8];
extern undefined1 DAT_104c5898;
extern undefined1 DAT_104c5899;
extern undefined DAT_104c58a0;
extern undefined DAT_104c58b0;
extern undefined DAT_104c58d0;
extern undefined DAT_104c58d4;
extern undefined DAT_104c58d8;
extern undefined g_token_has_static_record;
extern undefined1 DAT_104c590d;
extern undefined1 DAT_104c590e;
extern undefined1 DAT_104c590f;
extern undefined1 DAT_104c5910;
extern undefined DAT_104c5a08;
extern c1_keyword_row g_keyword_token_table[130];
extern undefined DAT_104c5f2a;
extern pointer g_keyword_table;
extern void * * g_entry_point_name_slots[6];
extern undefined DAT_104c6270;
extern undefined DAT_104c6552;
extern undefined * g_idb_stub_vtbl;
extern undefined DAT_104c6640;
extern undefined1 DAT_104c6645;
extern undefined1 DAT_104c6646;
extern undefined1 DAT_104c6647;
extern undefined DAT_104c6660;
extern undefined DAT_104c6738;
extern undefined DAT_104c6740;
extern pointer g_builtin_prelude_lines;
extern undefined DAT_104c68c0;
extern short g_asm_yy_exca[22];
extern byte g_asm_yy_exca_index[12];
extern short g_asm_yy_action[260];
extern short g_asm_yy_pact[136];
extern short g_asm_yy_pgo[24];
extern byte g_asm_yy_r1[84];
extern byte g_asm_yy_r2[84];
extern short g_asm_yy_chk[136];
extern short g_asm_yy_def[136];
extern byte g_asm_size_keyword_class[9];
extern char * g_asm_mnemonic_names[449];
extern short g_asm_mnemonic_first[29];
extern c1_asm_code_row g_asm_mnemonic_codes[449];
extern undefined DAT_104c85d8;
extern undefined DAT_104c85dc;
extern undefined DAT_104c85e0;
extern undefined DAT_104c85e8;
extern undefined DAT_104c85f0;
extern undefined DAT_104c85fc;
extern undefined DAT_104c8604;
extern undefined DAT_104c8608;
extern undefined DAT_104c860c;
extern undefined DAT_104c8610;
extern undefined DAT_104c8614;
extern undefined DAT_104c8618;
extern undefined DAT_104c861c;
extern undefined DAT_104c8620;
extern undefined DAT_104c8628;
extern undefined DAT_104c8630;
extern undefined DAT_104c8638;
extern undefined DAT_104c863c;
extern undefined DAT_104c8644;
extern undefined DAT_104c8648;
extern undefined DAT_104c8650;
extern undefined DAT_104c8654;
extern undefined DAT_104c8658;
extern undefined DAT_104c865c;
extern undefined DAT_104c8664;
extern undefined DAT_104c8668;
extern undefined DAT_104c8670;
extern undefined DAT_104c8680;
extern undefined DAT_104c8690;
extern undefined DAT_104c8698;
extern undefined DAT_104c86a0;
extern undefined DAT_104c86b0;
extern undefined DAT_104c86c0;
extern undefined DAT_104c86c8;
extern undefined DAT_104c86d0;
extern undefined DAT_104c86d8;
extern undefined DAT_104c86e0;
extern undefined DAT_104c86e4;
extern undefined DAT_104c86e8;
extern undefined DAT_104c86f0;
extern undefined DAT_104c86f8;
extern undefined DAT_104c86fc;
extern undefined DAT_104c8700;
extern undefined DAT_104c8704;
extern undefined DAT_104c8708;
extern undefined DAT_104c870c;
extern undefined DAT_104c8714;
extern undefined DAT_104c871c;
extern undefined DAT_104c8722;
extern undefined DAT_104c8726;
extern undefined DAT_104c872a;
extern undefined DAT_104c8730;
extern undefined DAT_104c8738;
extern undefined DAT_104c8740;
extern undefined DAT_104c8746;
extern undefined DAT_104c874c;
extern undefined DAT_104c8750;
extern undefined DAT_104c8758;
extern undefined DAT_104c8760;
extern undefined DAT_104c8764;
extern undefined DAT_104c8768;
extern undefined DAT_104c876c;
extern undefined DAT_104c8770;
extern undefined DAT_104c879c;
extern undefined DAT_104c87a4;
extern undefined DAT_104c87ac;
extern undefined DAT_104c87e4;
extern undefined DAT_104c87ec;
extern undefined DAT_104c87f4;
extern undefined DAT_104c886c;
extern undefined DAT_104c8870;
extern undefined DAT_104c8878;
extern undefined DAT_104c887c;
extern undefined DAT_104c8884;
extern undefined DAT_104c8888;
extern undefined DAT_104c8890;
extern undefined DAT_104c8898;
extern undefined DAT_104c88a0;
extern undefined DAT_104c88a4;
extern undefined DAT_104c88ac;
extern undefined DAT_104c88b4;
extern undefined DAT_104c88b8;
extern undefined DAT_104c88c0;
extern undefined DAT_104c88c8;
extern undefined DAT_104c88d0;
extern undefined DAT_104c88d8;
extern undefined DAT_104c88e0;
extern undefined DAT_104c8918;
extern undefined DAT_104c8978;
extern undefined DAT_104c8988;
extern undefined DAT_104c8996;
extern undefined DAT_104c899c;
extern undefined DAT_104c89a0;
extern undefined DAT_104c89a8;
extern undefined DAT_104c89b0;
extern undefined DAT_104c89b8;
extern undefined DAT_104c89be;
extern undefined DAT_104c89c4;
extern undefined DAT_104c89d0;
extern undefined DAT_104c89d4;
extern undefined DAT_104c89d8;
extern undefined DAT_104c89e0;
extern undefined DAT_104c89e8;
extern undefined DAT_104c89f0;
extern undefined DAT_104c89f8;
extern undefined DAT_104c8a00;
extern undefined DAT_104c8a06;
extern undefined DAT_104c8a0c;
extern undefined DAT_104c8a10;
extern undefined DAT_104c8a14;
extern undefined DAT_104c8a18;
extern undefined DAT_104c8a1e;
extern undefined DAT_104c8a22;
extern undefined DAT_104c8a28;
extern undefined DAT_104c8a2c;
extern undefined DAT_104c8a30;
extern undefined DAT_104c8a34;
extern undefined DAT_104c8a38;
extern undefined DAT_104c8a3c;
extern undefined DAT_104c8a40;
extern undefined DAT_104c8a44;
extern undefined DAT_104c8a4c;
extern undefined DAT_104c8a54;
extern undefined DAT_104c8a5c;
extern undefined DAT_104c8a64;
extern undefined DAT_104c8a68;
extern undefined DAT_104c8a80;
extern undefined DAT_104c8a86;
extern undefined DAT_104c8a8a;
extern undefined DAT_104c8a8e;
extern undefined DAT_104c8a90;
extern undefined DAT_104c8a94;
extern undefined DAT_104c8a98;
extern undefined DAT_104c8a9c;
extern undefined DAT_104c8aa0;
extern undefined DAT_104c8aa6;
extern undefined DAT_104c8aa8;
extern undefined DAT_104c8aac;
extern undefined DAT_104c8ab0;
extern undefined DAT_104c8ab4;
extern undefined DAT_104c8ab8;
extern undefined DAT_104c8abc;
extern undefined DAT_104c8ac0;
extern undefined DAT_104c8ac4;
extern undefined DAT_104c8ac8;
extern undefined DAT_104c8acc;
extern undefined DAT_104c8ad0;
extern undefined DAT_104c8ad4;
extern undefined DAT_104c8ad8;
extern undefined DAT_104c8adc;
extern undefined DAT_104c8ade;
extern undefined DAT_104c8ae2;
extern undefined DAT_104c8ae6;
extern undefined DAT_104c8ae8;
extern undefined DAT_104c8aea;
extern undefined DAT_104c8aee;
extern undefined DAT_104c8af4;
extern undefined DAT_104c8af8;
extern undefined DAT_104c8afc;
extern undefined DAT_104c8b00;
extern undefined DAT_104c8b04;
extern undefined DAT_104c8b08;
extern undefined DAT_104c8b14;
extern undefined DAT_104c8b18;
extern undefined DAT_104c8b1e;
extern undefined DAT_104c8b24;
extern undefined DAT_104c8b2c;
extern undefined DAT_104c8b30;
extern undefined DAT_104c8b38;
extern undefined DAT_104c8b3c;
extern undefined DAT_104c8b44;
extern undefined DAT_104c8b48;
extern undefined DAT_104c8b90;
extern undefined DAT_104c8b94;
extern undefined DAT_104c8ba4;
extern undefined DAT_104c8bbc;
extern undefined DAT_104c8bc4;
extern undefined DAT_104c8bc8;
extern undefined DAT_104c8bd0;
extern undefined DAT_104c8be0;
extern undefined DAT_104c8be4;
extern undefined DAT_104c8bec;
extern undefined DAT_104c8bf4;
extern undefined DAT_104c8c04;
extern undefined DAT_104c8c14;
extern undefined DAT_104c8c18;
extern undefined DAT_104c8c28;
extern undefined DAT_104c8c30;
extern undefined DAT_104c8c34;
extern undefined DAT_104c8c3c;
extern undefined DAT_104c8c4c;
extern undefined DAT_104c8c50;
extern undefined DAT_104c8c80;
extern undefined DAT_104c8c88;
extern undefined DAT_104c8c8c;
extern undefined DAT_104c8c90;
extern undefined DAT_104c8ca8;
extern undefined DAT_104c8cb8;
extern undefined DAT_104c8ce4;
extern undefined DAT_104c8cf4;
extern undefined DAT_104c8d0c;
extern undefined DAT_104c8d2c;
extern undefined DAT_104c8d32;
extern undefined DAT_104c8d38;
extern undefined DAT_104c8d48;
extern undefined DAT_104c8d4c;
extern undefined DAT_104c8d54;
extern undefined DAT_104c8d58;
extern undefined DAT_104c8d60;
extern undefined DAT_104c8d70;
extern undefined DAT_104c8d74;
extern undefined DAT_104c8d9c;
extern undefined DAT_104c8da4;
extern undefined DAT_104c8da8;
extern undefined DAT_104c8db4;
extern undefined DAT_104c8dc4;
extern undefined DAT_104c8dc8;
extern undefined DAT_104c8dce;
extern undefined DAT_104c8dd4;
extern undefined DAT_104c8dd8;
extern undefined DAT_104c8ddc;
extern undefined DAT_104c8de0;
extern undefined DAT_104c8de4;
extern undefined DAT_104c8de8;
extern undefined DAT_104c8dec;
extern undefined DAT_104c8df0;
extern undefined DAT_104c8df4;
extern undefined DAT_104c8df8;
extern undefined DAT_104c8dfc;
extern undefined DAT_104c8e00;
extern undefined DAT_104c8e04;
extern undefined DAT_104c8e14;
extern undefined DAT_104c8e24;
extern undefined DAT_104c8e2c;
extern undefined DAT_104c8e34;
extern undefined DAT_104c8e44;
extern undefined DAT_104c8ec4;
extern undefined DAT_104c8ecc;
extern undefined DAT_104c8ee4;
extern undefined DAT_104c8eec;
extern undefined DAT_104c8ef2;
extern undefined DAT_104c8ef8;
extern undefined DAT_104c8efc;
extern undefined DAT_104c8f04;
extern undefined DAT_104c8f0c;
extern undefined DAT_104c8f14;
extern undefined DAT_104c8f30;
extern undefined DAT_104c8f36;
extern undefined DAT_104c8f3c;
extern undefined DAT_104c8f40;
extern undefined DAT_104c8f48;
extern undefined DAT_104c8f4e;
extern undefined DAT_104c8f52;
extern undefined DAT_104c8f58;
extern undefined DAT_104c8f5e;
extern undefined DAT_104c8f62;
extern undefined DAT_104c8f66;
extern undefined DAT_104c8f6a;
extern undefined DAT_104c8f6e;
extern undefined DAT_104c8f72;
extern undefined DAT_104c8f76;
extern undefined DAT_104c8f7a;
extern undefined DAT_104c8f80;
extern undefined DAT_104c8f88;
extern undefined DAT_104c8fb0;
extern undefined DAT_104c9000;
extern undefined DAT_104c9050;
extern undefined DAT_104c9058;
extern undefined DAT_104c905e;
extern undefined DAT_104c9062;
extern undefined DAT_104c9066;
extern undefined DAT_104c906a;
extern undefined DAT_104c906e;
extern undefined DAT_104c9070;
extern undefined DAT_104c9074;
extern undefined DAT_104c9076;
extern undefined DAT_104c9078;
extern c1_asm_instruction_row g_asm_instructions[269];
extern char * g_asm_keyword_names[84];
extern short g_asm_keyword_first[29];
extern c1_asm_code_row g_asm_keyword_codes[84];
extern undefined DAT_104c9bc4;
extern undefined DAT_104c9bc8;
extern undefined DAT_104c9bce;
extern undefined DAT_104c9bd2;
extern undefined DAT_104c9bd8;
extern undefined DAT_104c9bdc;
extern undefined DAT_104c9be4;
extern undefined DAT_104c9bf0;
extern undefined DAT_104c9bf4;
extern undefined DAT_104c9bf8;
extern undefined DAT_104c9bfc;
extern undefined DAT_104c9c00;
extern undefined DAT_104c9c04;
extern undefined DAT_104c9c08;
extern undefined DAT_104c9c0c;
extern undefined DAT_104c9c10;
extern undefined DAT_104c9c14;
extern undefined DAT_104c9c20;
extern undefined DAT_104c9c24;
extern undefined DAT_104c9c28;
extern undefined DAT_104c9c2c;
extern undefined DAT_104c9c30;
extern undefined DAT_104c9c34;
extern undefined DAT_104c9c38;
extern undefined DAT_104c9c3c;
extern undefined DAT_104c9c40;
extern undefined DAT_104c9c44;
extern undefined DAT_104c9c48;
extern undefined DAT_104c9c4c;
extern undefined DAT_104c9c50;
extern undefined DAT_104c9c56;
extern undefined DAT_104c9c5a;
extern undefined DAT_104c9c5e;
extern undefined DAT_104c9c64;
extern undefined DAT_104c9c68;
extern undefined DAT_104c9c6a;
extern c1_u16 g_asm_registers[54];
extern c1_u16 g_asm_forms[69];
extern byte g_asm_mode_class[12];
extern byte g_asm_kind_mode[32];
extern char * g_asm_mode_formats[21];
extern undefined DAT_104c9df0;
extern undefined DAT_104c9df4;
extern undefined DAT_104c9df8;
extern undefined DAT_104c9dfa;
extern undefined DAT_104c9dfe;
extern undefined DAT_104c9e02;
extern undefined DAT_104c9e08;
extern undefined DAT_104c9e24;
extern undefined DAT_104c9e2c;
extern undefined DAT_104c9e32;
extern undefined DAT_104c9e36;
extern char * g_intrinsic_names[64];
extern byte g_intrinsic_letter_index[29];
extern undefined DAT_104c9f60;
extern undefined DAT_104c9f64;
extern undefined DAT_104c9f68;
extern undefined DAT_104c9f6c;
extern undefined DAT_104c9f96;
extern undefined DAT_104c9f9c;
extern undefined DAT_104c9fa0;
extern undefined DAT_104c9fa8;
extern undefined DAT_104c9fc6;
extern undefined DAT_104c9fcc;
extern undefined DAT_104c9fd2;
extern undefined DAT_104c9fd8;
extern undefined DAT_104c9fdc;
extern undefined DAT_104c9fe0;
extern undefined DAT_104c9fe4;
extern undefined DAT_104c9fe8;
extern undefined DAT_104c9fec;
extern undefined DAT_104c9ff0;
extern undefined DAT_104c9ff4;
extern undefined DAT_104c9ff8;
extern undefined DAT_104c9ffc;
extern undefined DAT_104ca000;
extern undefined DAT_104ca004;
extern undefined DAT_104ca148;
extern undefined DAT_104ca14c;
extern undefined DAT_104ca154;
extern undefined DAT_104ca16c;
extern undefined DAT_104ca184;
extern undefined DAT_104ca18c;
extern c1xx_intrinsic_row g_intrinsic_table[64];
extern undefined DAT_104ca51a;
extern c1xx_pragma_optimize_letter g_pragma_optimize_letters[10];
extern undefined DAT_104ca678;
extern undefined DAT_104ca680;
extern undefined DAT_104ca6fc;
extern undefined DAT_104ca708;
extern c1_yy_correction g_yy_corrections[102];
extern int g_implicit_member_kind_names[5];
extern int g_pdb_error_messages[20];
extern undefined DAT_104caa80;
extern undefined1 DAT_104caa88;
extern undefined1 DAT_104caa89;
extern undefined DAT_104caa8c;
extern undefined DAT_104caafa;
extern undefined DAT_104caafc;
extern undefined DAT_104cab14;
extern undefined DAT_104cab50;
extern undefined DAT_104cab86;
extern undefined DAT_104cac04;
extern undefined DAT_104cac6c;
extern undefined DAT_104cac74;
extern undefined DAT_104cac78;
extern undefined DAT_104cad4c;
extern undefined DAT_104cad54;
extern undefined4 DAT_104cad64;
extern pointer g_pch_relocation_table;
extern undefined DAT_104cae90;
extern undefined g_ipm_stream_name;
extern byte g_lowest_set_bit_table[256];
extern c1_arena_desc g_pch_relocation_arena_desc;
extern undefined DAT_104cb1e8;
extern undefined4 g_import_guid_null;
extern undefined4 DAT_104cb304;
extern undefined4 g_import_libid_stdole;
extern undefined4 DAT_104cb314;
extern undefined4 g_import_libid_excel5;
extern undefined4 DAT_104cb324;
extern pointer g_import_attribute_table;
extern undefined4 DAT_104cb334;
extern wchar_t * g_import_midl_auto_exclude[4];
extern wchar_t * g_import_auto_exclude_interfaces[139];
extern wchar_t * g_import_auto_exclude_records[114];
extern wchar_t * g_import_auto_exclude_enums[12];
extern wchar_t * g_import_auto_exclude_aliases[11];
extern undefined DAT_104cd8d4;
extern undefined DAT_104cd8f8;
extern undefined DAT_104cd97c;
extern undefined DAT_104cd980;
extern undefined DAT_104cd984;
extern undefined DAT_104cd9b0;
extern undefined DAT_104cda5c;
extern undefined DAT_104cda64;
extern undefined DAT_104cda78;
extern undefined DAT_104cda7c;
extern undefined DAT_104cda84;
extern undefined DAT_104cda88;
extern undefined DAT_104cda90;
extern undefined DAT_104cda98;
extern undefined DAT_104cdaa8;
extern undefined DAT_104cdac8;
extern undefined DAT_104cdace;
extern undefined DAT_104ce1bc;
extern undefined DAT_104ce284;
extern undefined DAT_104ce2c4;
extern undefined DAT_104ce2d4;
extern undefined DAT_104ce31e;
extern undefined DAT_104ce3ac;
extern undefined DAT_104ce3f4;
extern undefined DAT_104ce3f8;
extern undefined DAT_104ce438;
extern undefined DAT_104ce4ac;
extern undefined DAT_104ce4b2;
extern undefined DAT_104ce4f4;
extern undefined DAT_104ce4f8;
extern undefined DAT_104ce6a8;
extern undefined DAT_104ce6b8;
extern undefined DAT_104ce74e;
extern undefined DAT_104ce826;
extern undefined DAT_104ce82c;
extern undefined DAT_104ce886;
extern undefined DAT_104ce98c;
extern undefined DAT_104ce990;
extern undefined DAT_104ce9b4;
extern undefined DAT_104ce9cc;
extern undefined DAT_104cea34;
extern undefined DAT_104cebe8;
extern undefined DAT_104cedfc;
extern undefined DAT_104cee14;
extern undefined DAT_104cee20;
extern undefined DAT_104cee24;
extern undefined DAT_104cee30;
extern undefined DAT_104cee38;
extern undefined DAT_104cee40;
extern undefined DAT_104cee48;
extern undefined DAT_104cee50;
extern undefined DAT_104cee58;
extern undefined DAT_104cee5e;
extern undefined DAT_104ceee0;
extern int g_member_pointer_model_names[5];
extern short g_asm_yy_corrections[7];
extern c1_asm_code_row g_asm_mnemonic_aliases[178];
extern char * g_asm_token_spelling[50];
extern undefined DAT_104cf47c;
extern undefined DAT_104cf484;
extern undefined DAT_104cf48c;
extern undefined DAT_104cf490;
extern undefined DAT_104cf49c;
extern undefined DAT_104cf4a8;
extern undefined DAT_104cf4b0;
extern undefined DAT_104cf4b4;
extern undefined DAT_104cf4b8;
extern undefined DAT_104cf4bc;
extern undefined DAT_104cf4c0;
extern undefined DAT_104cf4c4;
extern undefined DAT_104cf4c8;
extern undefined DAT_104cf4cc;
extern undefined DAT_104cf4d0;
extern undefined DAT_104cf4d4;
extern undefined DAT_104cf4d8;
extern undefined DAT_104cf4dc;
extern undefined DAT_104cf4e0;
extern undefined DAT_104cf4ee;
extern ImageBaseOffset32 DAT_104cf568;
extern ImageBaseOffset32 DAT_104cf570;
extern int g_data_section_begin;
extern undefined1 DAT_104d1004;
extern byte g_pp_if_lookahead;
extern int g_pp_if_paren_depth;
extern int g_parse_block_record_depth;
extern c1_u8 g_eof_terminal_returned;
extern c1_u8 g_source_exhausted;
extern int g_instantiation_feed_count;
extern fe_input_file * g_input_file;
extern fe_input_file * g_main_input_file;
extern fe_input_file * g_input_file_free_list;
extern int g_include_depth;
extern undefined4 g_source_handle;
extern undefined4 g_default_argument_parse_stack;
extern int g_token_buffers_freed;
extern int g_comment_record_kind;
extern char * g_comment_record_text;
extern char * g_pch_name_buffer;
extern c1_u32 g_pp_cond_capacity;
extern uint g_cv_zero_attributes;
extern c1_type_emission_cell * * g_type_emission_stack;
extern byte g_debug_begun;
extern c1_u32 g_cv_real_type_by_size_table[11];
extern c1_u32 g_cv_uint_type_by_size_table[17];
extern c1_u32 g_cv_int_type_by_size_table[17];
extern c1_u32 g_cv_unsigned_type_by_size_table[17];
extern c1_u32 g_cv_signed_type_by_size_table[17];
extern uint * g_debug_index_queue;
extern char * * g_switch_words;
extern int g_parse_resync_end_position;
extern int g_parse_resync_brace_position;
extern int g_yy_result;
extern c1_yy_parser * g_yy_parser;
extern c1_u8 g_use_instantiation_position;
extern int g_browse_suspended;
extern int g_browse_last_line;
extern byte g_browse_line_absolute;
extern int g_emitter_region_mode;
extern long g_browse_sbr_header_end;
extern c1xx_il_emitter * g_il_emitter;
extern c1xx_il_emitter_browse * g_il_emitter_browse;
extern c1xx_il_emitter * g_il_emitter_plain;
extern int g_browse_block_depth;
extern byte g_eh_declarations_injected;
extern int g_ilstore_status;
extern undefined1 g_vector_helper_tokens_built;
extern c1_symbol_vector * g_pending_special_members;
extern c1_symbol * g_builtin_label_1;
extern c1_symbol * g_builtin_label_10;
extern c1_function_record_block * g_function_record_first_block;
extern c1_function_record_block * g_function_record_block;
extern int g_lex_unread_word;
extern c1_type * g_current_enum_type;
extern uint * * g_function_params_hash;
extern fe_name * * g_name_hash;
extern void * g_unused_hash_table;
extern c1_vector * g_dynamic_initializer_functions;
extern c1_pack_stack * g_pack_stack;
extern void * g_include_alias_table;
extern fe_name * g_last_name;
extern undefined4 g_name_operator_call;
extern undefined4 g_name_operator_arrow;
extern void * g_name_alignment_member;
extern void * g_name_operator_assign;
extern void * g_name_abstract_declarator;
extern fe_name * g_name_defined;
extern fe_name * g_name_dollar;
extern void * g_name_drectve;
extern void * g_name_local_size;
extern void * g_name_ellipsis;
extern fe_name * g_name_formal;
extern void * g_name_local_static_guard;
extern void * g_name_main;
extern void * g_name_setjmp;
extern void * g_name_Catch;
extern void * g_name_WinMain;
extern void * g_name_DllMain;
extern void * g_name_wmain;
extern void * g_name_wWinMain;
extern fe_name * g_name_unnamed;
extern c1_type * g_function_return_type;
extern void * g_alloc_text_segment;
extern c1_symtab * g_esumem_copy_table;
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
extern c1_type * g_type_bool;
extern c1_type * g_type_any_integral;
extern c1_type * g_type_long;
extern c1_type * g_type_unsigned_long;
extern c1_type * g_type_segment;
extern c1_type * g_type_short;
extern c1_type * g_type_unsigned_short;
extern c1_type * g_type_char;
extern c1_type * g_type_unsigned_char;
extern c1_type * g_type_unsigned_int;
extern c1_type * g_type_none;
extern c1_type * g_type_void;
extern c1_type * g_builtin_int_function;
extern c1_symbol * g_purecall_symbol;
extern c1_scope_stack * g_current_scope;
extern uint * g_symbol_free_lists[32];
extern c1_pragma_comment * g_pragma_comment_list;
extern c1_class_instance_cell * * g_class_template_instances;
extern c1_symbol_vector * g_scope_vector;
extern c1_symtab * g_adjustor_thunk_table;
extern c1_symtab * g_vector_to_scalar_deleting_dtor_table;
extern c1_symtab * g_vcall_thunk_table;
extern c1_symtab * g_pointer_pair_table;
extern c1_symtab * g_friend_table;
extern c1_symtab * g_sym_pair_table_global;
extern c1_symtab * g_hiding_pair_table;
extern c1_symtab * g_clone_attribute_table;
extern c1_symtab * g_vcall_attribute_table;
extern c1_symtab * g_debug_type_by_id_table;
extern c1_symtab * g_instance_arguments_table;
extern c1_symtab * g_template_default_arguments;
extern c1_symtab * g_tmpl_definition_table;
extern c1_symtab * g_instance_template_table;
extern c1_tmpl_work_queue * g_template_work_queue;
extern undefined4 g_init_seg_name;
extern void * g_name_ctor;
extern void * g_name_scalar_deleting_dtor;
extern void * g_name_delete;
extern void * g_name_dtor;
extern void * g_name_local_static_destructor;
extern void * g_name_template_static_member_ctor;
extern void * g_name_template_static_member_dtor;
extern void * g_name_new;
extern void * g_name_array_new;
extern void * g_name_array_delete;
extern undefined4 g_name_this;
extern void * g_name_vbase_dtor;
extern void * g_name_vbptr;
extern void * g_name_vbtable;
extern void * g_name_vfptr;
extern void * g_name_vdispmap;
extern void * g_name_vector_deleting_dtor;
extern void * g_name_vector_ctor_iterator;
extern void * g_name_vector_vbase_ctor_iterator;
extern void * g_name_vector_dtor_iterator;
extern void * g_name_eh_vector_ctor_iterator;
extern void * g_name_eh_vector_vbase_ctor_iterator;
extern void * g_name_eh_vector_dtor_iterator;
extern void * g_name_vftable;
extern void * g_name_local_vftable;
extern void * g_name_new_target;
extern undefined4 g_atexit_name;
extern undefined DAT_104d16a0;
extern void * g_name_global_namespace;
extern void * g_name_bool;
extern c1_type_list * g_void_parameter_list_record;
extern void * g_crt_initializer_segment;
extern c1_symbol * g_atexit_symbol;
extern c1_symbol * g_init_seg_atexit_function;
extern c1_node * g_tree_zero_constant;
extern c1_symbol_vector * g_empty_symbol_vector;
extern short * g_pending_vtable_classes;
extern uint * * g_type_list_hash;
extern void * g_bss_seg_name;
extern void * g_const_seg_name;
extern void * g_data_seg_name;
extern void * g_code_seg_name;
extern void * g_name_default_ctor_closure;
extern void * g_name_local_vftable_ctor_closure;
extern void * g_name_copy_ctor_closure;
extern c1_symtab * g_special_member_alias_table_a;
extern c1_symtab * g_special_member_alias_table_b;
extern c1_symtab * g_copy_ctor_closure_table;
extern c1_symtab * g_placement_delete_closure_table;
extern c1_symtab * g_placement_delete_target_table;
extern void * g_name_placement_delete_closure;
extern void * g_name_placement_array_delete_closure;
extern void * g_name_most_derived;
extern void * g_default_data_segment;
extern void * g_default_code_segment;
extern void * g_default_segment_3;
extern undefined4 g_token_static_records;
extern undefined4 g_token_newline;
extern void * g_token_pragma_hdrstop;
extern c1_u8 * g_token_line_directive_for_pch;
extern void * g_token_pch_creation_point;
extern c1xx_token * g_token_end_of_file;
extern void * g_token_inline;
extern void * g_token_char;
extern void * g_token_int;
extern void * g_token_void;
extern void * g_token_unsigned;
extern c1_u8 * g_token_directive_end;
extern c1xx_token * g_token_ampersand;
extern c1xx_token * g_token_logical_and;
extern c1xx_token * g_token_and_assign;
extern void * g_token_assign;
extern void * g_token_colon;
extern void * g_token_comma;
extern void * g_token_minus_minus;
extern c1xx_token * g_token_slash;
extern c1xx_token * g_token_div_assign;
extern c1xx_token * g_token_equal_equal;
extern c1xx_token * g_token_exclaim;
extern void * g_token_greater;
extern void * g_token_greater_equal;
extern c1xx_token * g_token_plus_plus;
extern void * g_token_lbracket;
extern c1xx_token * g_token_shl_assign;
extern c1xx_token * g_token_shl;
extern c1xx_token * g_token_less;
extern c1xx_token * g_token_less_equal;
extern c1xx_token * g_token_minus;
extern c1xx_token * g_token_sub_assign;
extern c1xx_token * g_token_percent;
extern c1xx_token * g_token_mod_assign;
extern void * g_token_star;
extern c1xx_token * g_token_mul_assign;
extern c1xx_token * g_token_not_equal;
extern c1xx_token * g_token_bar;
extern c1xx_token * g_token_or_assign;
extern c1xx_token * g_token_logical_or;
extern void * g_token_dot;
extern void * g_token_plus;
extern c1xx_token * g_token_add_assign;
extern c1xx_token * g_token_arrow;
extern c1xx_token * g_token_question;
extern c1xx_token * g_token_shr_assign;
extern c1xx_token * g_token_shr;
extern c1xx_token * g_token_tilde;
extern c1xx_token * g_token_caret;
extern c1xx_token * g_token_xor_assign;
extern c1xx_token * g_token_colon_greater;
extern c1xx_token * g_token_end_of_input;
extern void * g_token_for;
extern void * g_token_if;
extern void * g_token_lbrace;
extern undefined4 g_token_lparen;
extern void * g_token_rbracket;
extern void * g_token_rbrace;
extern void * g_token_return;
extern undefined4 g_token_rparen;
extern void * g_token_semicolon;
extern void * g_token_stdcall;
extern void * g_token_while;
extern c1xx_token * g_token_internal;
extern c1xx_token * g_token_dot_star;
extern c1xx_token * g_token_arrow_star;
extern void * g_token_colon_colon;
extern void * g_token_operator;
extern void * g_token_end_parse;
extern void * g_token_thiscall;
extern void * g_token_template_args;
extern c1xx_token * g_token_template_open;
extern c1xx_token * g_token_template_close;
extern void * g_token_template_defn;
extern void * g_token_default_argument;
extern void * g_token_template_decl;
extern undefined4 g_token_end_of_stream;
extern undefined DAT_104d1b00;
extern fe_name * g_name_RTDynamicCast;
extern fe_name * g_name_RTCastToVoid;
extern fe_name * g_name_RTtypeid;
extern fe_name * g_name_RTtypeidReturnType;
extern fe_name * g_name_type_info_vftable;
extern c1_vector * g_rtti_type_descriptors;
extern uint * g_pdb_gi_pch_blob;
extern c1xx_token_stream * g_vec_helper_prefix_tokens;
extern c1xx_token_stream * g_vec_iterator_params_tokens;
extern c1xx_token_stream * g_vec_ctor_iterator_body_tokens;
extern c1xx_token_stream * g_vec_ctor_vb_body_tokens;
extern c1xx_token_stream * g_vec_dtor_body_tokens;
extern fe_name * g_name_line_var;
extern c1_symtab * g_segment_record_table;
extern c1_symtab * g_declarator_record_table;
extern fe_name * g_name_COMuuidofReturnType;
extern fe_name * g_name_s_GUID;
extern c1_symtab * g_declspec_record_table;
extern c1_vector * g_imported_libraries;
extern c1_symtab * g_redeclaration_table;
extern fe_name * g_map_region_name;
extern c1xx_warning_state * g_warning_state;
extern c1_warning_record * g_warning_record_free_list;
extern int * g_tmpl_warning_state_snapshot;
extern int * g_push_macro_stack;
extern c1_symbol * g_empty_list_sentinel;
extern undefined4 g_type_hash;
extern int g_builtin_operator_candidate_count;
extern int g_function_record_index;
extern c1_u8 g_ptm_full_generality;
extern c1_u8 g_member_pointer_representation_fixed;
extern int g_ptm_inheritance_model;
extern int g_init_seg_kind;
extern undefined4 g_next_entity_id;
extern undefined4 g_next_local_key;
extern undefined4 g_max_namemap_key;
extern undefined4 g_next_global_key;
extern undefined4 g_next_dollar_name;
extern int g_pch_sy_file_offset;
extern int g_cv_next_type_index;
extern uint g_cv_precomp_signature;
extern c1_u32 g_cv_type_stream_size;
extern byte g_pragma_vtordisp;
extern uint g_warning_state_emit_min;
extern uint g_warning_state_emit_max;
extern undefined4 g_compile_flags_c4;
extern undefined4 g_compile_flags_c8;
extern c1_u32 g_compile_flags_cc;
extern c1_u32 g_compile_flags_d0;
extern c1_u32 g_pdb_age;
extern c1_u32 g_pdb_gi_age;
extern byte g_pch_object_has_code;
extern byte g_browse_id_module_byte;
extern int g_lex_position;
extern c1_line_map g_line_map;
extern c1_line_map_row g_line_map_cached_row;
extern undefined4 g_pch_option_block;
extern c1_u8 g_ms_extensions;
extern c1_u8 g_opt_ZBe;
extern int g_integral_max_bytes;
extern undefined1 g_opt_Gr;
extern undefined1 g_opt_Jd;
extern c1_u8 g_opt_J_unsigned_char;
extern undefined1 g_opt_vmb;
extern undefined1 g_opt_vmg;
extern undefined1 g_opt_vms;
extern undefined1 g_opt_vmm;
extern undefined1 g_opt_vmv;
extern undefined1 g_opt_vd;
extern undefined4 g_opt_MD;
extern undefined g_opt_MT;
extern undefined1 g_opt_Gc;
extern c1_u8 g_opt_Zi;
extern char g_pch_debug_in_object;
extern c1_pch_name_lengths g_pch_name_lengths;
extern undefined1 g_opt_EP_no_line;
extern undefined g_opt_pf;
extern undefined4 g_autoinline_tuple_limit;
extern byte g_opt_Brepro;
extern undefined1 g_opt_Oi;
extern undefined1 g_opt_stack_probes;
extern undefined4 g_opt_Gd;
extern int g_default_stdcall;
extern undefined1 g_opt_Gf;
extern c1_u8 g_string_pooling;
extern char g_string_pooling_readonly;
extern char g_string_pooling_readonly_state;
extern undefined1 g_opt_cbstring;
extern undefined4 g_opt_G_cpu;
extern undefined1 g_opt_GM;
extern undefined4 g_inline_level;
extern byte g_browse_info;
extern byte g_browse_info_full;
extern c1_u32 g_pch_function_option_word;
extern undefined1 g_opt_eh;
extern char g_rtti;
extern undefined1 g_opt_noBool;
extern c1_u8 g_pragma_mintypeinfo;
extern undefined1 g_opt_FD;
extern char g_minimal_rebuild;
extern byte g_pragma_check_stack;
extern undefined g_opt_Ot;
extern undefined1 g_opt_Oa;
extern undefined1 g_opt_Ow;
extern undefined1 g_opt_Og;
extern undefined1 g_opt_Op;
extern undefined g_opt_Oy;
extern char g_debug_types_in_pdb;
extern undefined1 g_opt_Oq;
extern char g_pragma_optimize_q;
extern undefined g_opt_Ov;
extern c1_u32 g_pdb_signature;
extern c1_u32 g_pdb_gi_signature;
extern undefined1 g_c9il_mode;
extern undefined1 g_incremental;
extern undefined1 g_opt_GI;
extern undefined1 g_opt_GFR;
extern char g_split_pdbs;
extern undefined1 g_opt_NoEHForNew;
extern char g_gm_forced_incremental;
extern undefined1 g_opt_EHc;
extern undefined1 g_opt_ZI;
extern undefined4 g_opt_Bm;
extern char g_use_pch;
extern undefined4 g_opt_Yu_header;
extern char g_pch_create;
extern char * g_create_pch_header_name;
extern char g_pch_automatic;
extern undefined4 g_opt_YX_header;
extern undefined4 g_opt_Yl;
extern char * g_pch_file_name;
extern char * g_il_pch_name;
extern char g_pch_create_header_seen;
extern byte g_pch_written;
extern byte g_pch_creating;
extern byte g_pch_in_ex_file;
extern undefined1 g_opt_pch_types_in_pdb;
extern byte g_pch_precomp_types;
extern char g_function_in_pch;
extern char g_function_il_reused;
extern char g_function_uses_line_helper;
extern c1_symbol * g_tmpl_current_template;
extern c1_symbol * g_tmpl_current_instance;
extern c1xx_block_scope * g_tmpl_bound_scope;
extern c1_symbol * g_last_declared_symbol;
extern c1_arg_list * g_reparsed_template_args;
extern c1xx_token_stream * g_tmpl_definition_tokens;
extern c1xx_token_stream * g_tmpl_definition_tail_tokens;
extern int g_parse_context_depth;
extern undefined g_opt_NV;
extern c1_symbol * g_member_function_class;
extern int g_trial_error_count;
extern int g_pp_cond_depth;
extern char g_opt_Ct;
extern char g_dlp;
extern undefined1 g_opt_BforceInst;
extern undefined4 g_opt_Fo_object;
extern char * g_object_file_name;
extern char * g_opt_Fd_pdb;
extern int g_class_depth;
extern ushort g_pragma_inline_depth;
extern ushort g_pragma_inline_recursion;
extern undefined4 g_pragma_auto_inline;
extern undefined4 g_function_auto_inline;
extern int g_function_has_body;
extern undefined4 g_function_not_inlinable;
extern longlong g_enum_value;
extern short g_block_number;
extern char * g_string_literal_cur;
extern char * g_opt_pc;
extern char * g_opt_il_prefix;
extern int g_opt_Zp;
extern int g_seh_try_depth;
extern int g_seh_except_depth;
extern int g_seh_finally_depth;
extern int g_linkage_depth;
extern int g_sizeof_depth;
extern c1_static_guard * g_static_guard_current;
extern uchar g_member_access_op;
extern int g_format_buffer_depth;
extern c1_symbol * g_init_pending_data_symbol;
extern undefined1 g_opt_noexpinl;
extern c1xx_float_const g_float_zero;
extern c1xx_float_const g_float_one;
extern c1_mre_tracker * g_minimal_rebuild_tracker;
extern undefined4 g_compile_phase;
extern int g_template_parameter_index;
extern int g_template_depth;
extern int g_dependent_name_count;
extern c1_symbol * g_function_labels;
extern c1_type * g_rt_typeid_return_type;
extern undefined4 g_opt_unrecognized;
extern undefined1 g_opt_Z7;
extern undefined4 g_opt_W_level;
extern char g_pdb_directory_split;
extern int g_decorate_outermost;
extern int g_decorate_error_name_counter;
extern int g_decorate_arglist_depth;
extern int g_init_brace_depth;
extern byte g_init_remaining_error;
extern int g_init_remaining_offset;
extern int g_init_remaining_count;
extern int g_crt_segments_to_declare;
extern c1_symtab * g_inline_instance_table;
extern c1_symtab * g_sym_pair_table_local;
extern c1_u32 g_symbol_size_table[28];
extern undefined g_symbol_size_label;
extern undefined g_symbol_size_alias;
extern undefined g_symbol_size_member_alias;
extern undefined g_symbol_size_overload_set;
extern undefined g_symbol_size_namespace;
extern undefined g_symbol_size_using_entry;
extern int g_symbol_size_class_table[28];
extern undefined g_symbol_class_of_label;
extern undefined g_symbol_class_of_overload_set;
extern char g_il_emit_mode;
extern int g_il_last_source_file_ni;
extern uint g_il_last_line_offset;
extern uint g_il_line_base;
extern uint g_il_last_file_key;
extern c1_u8 g_il_line_numbers_in_range;
extern c1_u32 g_shared_temporary_key;
extern int g_type_category_basic_codes[16];
extern int g_type_category_derived_codes[20];
extern char * g_prototype_unnamed_tag_keyword;
extern int g_format_params_with_names;
extern int g_format_conversion_by_name;
extern undefined1 g_format_name_flags;
extern int * g_text_buffers;
extern int g_text_buffer_count;
extern int g_format_buffer_next_handle;
extern int g_abort_requested;
extern c1_system_info g_system_info;
extern undefined g_page_size;
extern undefined g_pch_segment_alignment;
extern HANDLE g_abort_semaphore;
extern int g_first_compiler_pass;
extern fe_pch_header g_pch_header;
extern undefined g_pch_sy_size;
extern undefined g_pch_gl_size;
extern undefined g_pch_ex_size;
extern undefined g_pch_in_size;
extern undefined g_pch_db_size;
extern undefined g_pch_browse_size;
extern undefined4 g_pch_record_list;
extern undefined4 g_pch_directive_text_blocks;
extern c1_pch_include_count g_pch_include_count;
extern byte g_pch_file_time_changed;
extern byte g_pch_auto_never_recreate;
extern char * g_pch_auto_note;
extern int * g_pch_rle_counter;
extern int g_pch_rle_byte;
extern int g_pch_rle_run_length;
extern byte g_pch_file_unfinished;
extern byte g_pch_write_file_unfinished;
extern int g_pch_files_closed;
extern char * g_pch_symbol_prefix;
extern char * g_pch_symbol_include_option;
extern int g_expr_arena_index;
extern int g_context_arena_index;
extern c1xx_misc_string g_misc_strings[91];
extern char g_misc_strings_loaded;
extern FILE * g_browse_out_file;
extern c1_u32 g_pragma_optimize_on_mask;
extern c1_u32 g_pragma_optimize_off_mask;
extern pointer g_option_flag_pointers;
extern undefined4 DAT_104d2770;
extern undefined DAT_104d2774;
extern undefined DAT_104d27c0;
extern c1xx_pdb * g_ilstore_pdb;
extern c1_ilstore * g_ilstore;
extern c1xx_ilmod * g_ilmod;
extern int g_ilstore_module_ni;
extern byte g_pch_db_reloaded;
extern byte g_il_files_opened;
extern int g_source_tracker_depth;
extern char g_source_signature_eof_byte;
extern c1_u8 * g_source_signature_buffer;
extern c1_u8 g_idb_outside_function;
extern c1_sym_list * g_list_cell_free_list;
extern undefined1 g_opt_BMOVE;
extern int g_zm_percent;
extern byte g_os_is_windows_nt;
extern undefined4 g_mre_engine;
extern int g_conv_bind_class_rvalue_depth;
extern c1_type * g_com_uuidof_return_type;
extern c1_type * g_s_guid_type;
extern c1_u32 g_global_helper_key;
extern c1_builtin_operator_row g_builtin_operator_candidates[51];
extern c1_flow_state * g_flow_state_bottom;
extern c1_flow_state * g_flow_state_top;
extern c1_flow_state * g_flow_state_free_list;
extern c1_u32 g_flow_state_units_allocated;
extern int g_flow_operator_depth;
extern int g_flow_state_depth;
extern int g_flow_goto_count;
extern c1_u8 g_init_target_is_reference;
extern int g_init_member_store_active;
extern int g_brace_init_active;
extern int g_eh_current_state;
extern int g_eh_last_state;
extern int g_init_declaration_depth;
extern int g_eh_try_depth;
extern c1_u8 g_eh_ctor_return_flushed;
extern c1_eh_state * g_eh_state_table;
extern int g_eh_context_kind;
extern int g_eh_state_capacity;
extern c1_u8 g_eh_unwind_form;
extern c1_flow_state * g_defined_label_flow_states;
extern uint * g_pending_goto_list;
extern c1_flow_state * g_flow_switch_record;
extern c1_flow_state * g_flow_state_function_record;
extern int g_flow_error_count_at_start;
extern char g_flow_state_abandoned;
extern void * g_flow_error_jmpbuf;
extern int * g_lookahead_parser;
extern c1_symtab * g_catchable_type_table;
extern pointer g_eh_segment_names;
extern c1_type * g_pmfn_type;
extern int g_list_cell_arena;
extern int g_list_cell_arena_saved;
extern int g_member_set_retry_guard;
extern c1_u8 g_unnamed_namespace_name_made;
extern c1_symbol * g_class_previous_vbase;
extern c1_vector * g_rtti_catchable_types;
extern c1_vector * g_rtti_base_class_descriptor_queue;
extern c1_vector * g_rtti_base_class_arrays;
extern c1_vector * g_rtti_class_hierarchy_descriptors;
extern c1_vector * g_rtti_object_locator_queue;
extern void * g_rtti_object_locator_name;
extern c1_type * g_rtti_base_class_descriptor_type;
extern undefined1 g_tmpl_binding_in_progress;
extern c1xx_token * g_asm_yy_lookahead;
extern int g_asm_yy_nerrs;
extern short g_asm_yy_errflag;
extern undefined DAT_104d2d14;
extern int g_bss_section_begin;
extern undefined1 DAT_104d2d1c;
extern undefined1 g_idb_file_name;
extern int g_pp_if_suppress_depth;
extern c1_pp_value g_pp_if_constant;
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
extern c1xx_macro_frame g_macro_expansion_frames[256];
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
extern c1_type * g_yylval_spec_type;
extern c1_symbol * g_yylval_spec_type_sym;
extern void * g_yylval_spec_insert_fn;
extern c1xx_emitter_suspend * g_emitter_suspend;
extern c1_token_reader g_token_stream_queues[10];
extern undefined g_pending_instantiation_streams;
extern undefined g_record_context_stack;
extern int g_token_position;
extern c1_token_source_frame * g_token_source;
extern int g_token_record_position;
extern c1_token_source_frame * g_token_save_frame;
extern uint * g_pp_cond_states;
extern undefined4 DAT_104d4714;
extern undefined1 DAT_104d4718;
extern undefined1 DAT_104d4719;
extern ushort * g_cv_record_body;
extern ushort * g_debug_record_buffer;
extern char * g_switch_word;
extern undefined1 g_crc16_byte_table;
extern undefined1 g_crc16_table_lo;
extern undefined1 DAT_104dc625;
extern undefined1 g_crc16_table_hi;
extern undefined1 DAT_104dc725;
extern int g_parse_resync_end_feed;
extern c1_u8 g_parse_resync_statics_guard;
extern int g_yy_rule;
extern int g_yy_n;
extern int g_yy_state;
extern int * g_yy_ps;
extern c1_yy_value * g_yy_pv;
extern byte * g_yy_lookahead;
extern c1_yy_value g_yy_val;
extern c1_u16 g_region_start_line;
extern int g_browse_ring_count;
extern int g_browse_ring_head;
extern c1xx_browse_record g_browse_ring[32];
extern undefined4 DAT_104dcb80;
extern int g_macro_text_pending;
extern int g_region_source_position;
extern c1_u8 g_browse_pch_marked;
extern c1_symbol * g_browse_skip_symbol;
extern undefined1 DAT_104dcb94;
extern undefined1 DAT_104dcb95;
extern c1_class_def_entry g_class_def_stack[16];
extern c1_u8 g_access_special_member_context;
extern c1_u8 g_access_report_access;
extern c1_u8 g_access_report_inherit_access;
extern c1_symbol * g_access_report_base;
extern undefined4 g_access_report_member;
extern int g_access_report_via_virtual_base;
extern c1_symbol * g_access_report_class;
extern int g_warned_fastcall_stack_check;
extern c1_type * g_return_object_pointer_type;
extern byte g_pch_create_explicit;
extern byte g_pch_use_only;
extern void * g_deferred_symbols;
extern byte * g_function_record_pool;
extern c1_u32 g_function_record_pool_left;
extern uchar * g_scope_pool;
extern uint g_scope_pool_left;
extern c1_u8 * g_pool_default;
extern c1_u32 g_pool_default_left;
extern fe_macro * g_macro_definition_pool;
extern c1_u32 g_macro_definition_pool_left;
extern uchar * g_name_pool;
extern uint g_name_pool_left;
extern c1_symtab_entry * g_symtab_entry_pool;
extern uint g_symtab_entry_pool_left;
extern uint * g_function_params_pool;
extern uint g_function_params_pool_left;
extern uint * g_type_list_pool;
extern uint g_type_list_pool_left;
extern c1xx_pool g_unused_pool;
extern undefined4 g_type_entry_pool;
extern uint g_type_entry_pool_left;
extern c1xx_idb * g_idb;
extern undefined4 g_source_tracker;
extern c1_node * g_ctor_mem_initializers;
extern char g_function_compile_it;
extern uint g_options_signature;
extern int g_source_file_ni;
extern uint g_function_start_line;
extern undefined4 g_function_tuple_count;
extern byte g_paren_level_flags[60];
extern c1_symbol * g_pending_access_check[52];
extern undefined g_paren_level_declspecs_prev_base;
extern undefined DAT_104dcf90;
extern c1xx_decl_specifiers g_paren_level_declspecs[60];
extern int g_paren_depth;
extern c1_symbol * g_current_enum;
extern c1xx_decl_specifiers g_conversion_type_specifiers;
extern c1_arg_list * g_paren_level_arg_lists[61];
extern c1_static_guard g_static_guard_record;
extern int g_static_guard_count;
extern int g_declarator_paren_base;
extern undefined4 g_injected_text_list;
extern int g_linkage_stack[10];
extern undefined4 g_target_cpu_mask;
extern c1_u8 g_il_pragma_byte_operand;
extern c1_u16 g_asm_align_size;
extern char * g_pp_time_text;
extern char * g_pp_date_text;
extern undefined g_opt_Zc;
extern undefined4 g_opt_Binl;
extern char * g_pragma_optimize_list;
extern undefined4 g_opt_FAT;
extern undefined1 g_string_literal_buffer;
extern undefined1 DAT_104dda55;
extern undefined1 DAT_104dda56;
extern undefined1 DAT_104dda57;
extern undefined1 DAT_104dda58;
extern undefined1 DAT_104dda59;
extern undefined DAT_104de254;
extern c1xx_token g_asm_empty_token;
extern byte * g_input_ptr;
extern c1_u8 g_il_block_level;
extern c1_u8 g_block_depth;
extern c1_asm_record g_asm_instruction_record;
extern int g_warnings_as_errors;
extern undefined1 g_opt_Zf;
extern undefined1 g_opt_FC;
extern c1_u8 g_symbol_scope_level;
extern int g_loop_label_count;
extern undefined g_opt_Zn;
extern undefined4 g_opt_Fr_browse;
extern undefined4 g_opt_FR_browse;
extern char * g_browse_file;
extern FILE * g_browse_sbr_file;
extern undefined g_opt_int2enum;
extern undefined1 g_opt_BnoWorkList;
extern undefined1 g_opt_Bshow_incl;
extern int g_opt_E_preprocess;
extern c1_u8 g_opt_Zg;
extern int g_pragma_optimize_on;
extern int g_flow_analysis_active;
extern int g_error_count;
extern int g_class_syntax_error_count;
extern int g_macro_expansion_depth;
extern int g_function_context_word;
extern int g_pending_function_word;
extern undefined4 g_opt_ZX;
extern undefined4 g_qualified_lookup_found_overloads;
extern int g_prototype_scope_depth;
extern int g_file_scope_decl_since_body;
extern undefined4 g_opt_xc;
extern undefined g_opt_Bd;
extern undefined1 g_opt_nologo;
extern byte g_opt_C_keep_comments;
extern undefined4 g_opt_V_string;
extern undefined4 g_opt_Fi_output;
extern undefined4 g_opt_source_file;
extern undefined4 g_constant_value;
extern int g_constant_value_high;
extern c1_node * g_function_exit_label;
extern c1_node * g_case_label;
extern c1_symbol * g_static_guard_variable;
extern undefined4 g_forced_include_files;
extern int g_forced_include_index;
extern byte * g_forced_include_current;
extern c1_vector * g_forced_include_list;
extern c1_vector * g_define_list;
extern c1_vector * g_include_path_list;
extern c1_deferred_body_list * g_deferred_member_bodies;
extern c1_sym_list * g_function_parameter_scope;
extern c1_sym_list * g_pending_parameter_scope;
extern int g_function_formal_count;
extern int g_function_sy_offset;
extern int g_function_ex_offset;
extern c1_u32 g_function_string_literal_count;
extern c1_symbol * g_current_function;
extern c1xx_label_cell * g_loop_top_label_stack;
extern c1_value_cell * g_pending_destructor_list;
extern c1xx_label_cell * g_seh_try_label_stack;
extern c1xx_label_cell * g_default_label_stack;
extern c1xx_label_cell * g_continue_label_stack;
extern c1_switch_cases_cell * g_switch_case_stack;
extern void * g_break_label_stack;
extern c1_il_buffer g_il_gi_fdef;
extern undefined g_il_gi_record_cur;
extern undefined g_il_gi_record_ok;
extern c1_il_buffer g_il_gi_buffer;
extern c1_il_buffer g_il_pending_init;
extern undefined g_il_pending_init_cur;
extern c1_il_buffer g_il_in;
extern undefined g_il_in_cur;
extern undefined g_il_in_open;
extern c1_il_buffer g_il_ex;
extern undefined g_il_ex_cur;
extern undefined g_il_ex_size;
extern undefined g_il_ex_file;
extern undefined g_il_ex_ok;
extern c1_il_buffer g_il_gl;
extern c1_il_buffer g_il_sy;
extern c1_il_buffer g_il_db;
extern undefined g_il_db_cur;
extern undefined g_il_db_open;
extern undefined4 g_pp_output_stream;
extern FILE * g_fi_output_file;
extern char g_auto_pch_saved_use_pch;
extern char * g_auto_pch_saved_yu_header;
extern byte g_auto_pch_using;
extern byte g_auto_pch_creating;
extern FILE * g_pch_file;
extern undefined DAT_104dee95;
extern char * * g_option_argv_cursor;
extern int g_option_args_left;
extern c1_u16 g_file_name_case_table[256];
extern undefined g_opt_Zm;
extern undefined g_opt_response_arg;
extern undefined1 g_opt_debugBreak;
extern uint g_decorate_template_arg_backref_count;
extern undefined4 g_decorate_template_arg_backrefs;
extern undefined4 DAT_104df1b8;
extern int g_decorate_name_backref_count;
extern undefined4 g_decorate_name_backrefs;
extern undefined4 DAT_104df1e4;
extern int g_decorate_arg_backref_count;
extern undefined4 g_decorate_arg_backrefs;
extern undefined4 DAT_104df210;
extern char * g_decorate_output_base;
extern int g_init_turned_dynamic;
extern c1_node * g_static_guard_skip_label;
extern int g_bitfield_word_needs_reset;
extern int g_init_dynamic_offset;
extern int g_init_offset;
extern int g_init_bitfield_unit_offset;
extern c1_u32 g_init_bitfield_value;
extern c1_u32 g_init_bitfield_value_high;
extern int g_init_bitfield_unit_open;
extern int g_init_too_many_reported;
extern c1xx_init_level * g_init_level;
extern c1_symbol * g_init_symbol;
extern c1xx_init_level g_init_levels[32];
extern undefined4 g_pending_destructor_helpers;
extern uint g_il_line_offset;
extern c1_u8 g_bool_pointer_type_guard;
extern char g_type_category_tables_built;
extern c1_u32 g_default_decl_specifiers[6];
extern undefined4 g_undecorate_hook;
extern HMODULE g_msvcrt_module;
extern c1_u8 g_msvcrt_module_borrowed;
extern c1_dlist_node * g_format_template_arg_stack;
extern c1_dlist_node g_format_template_arg_anchor;
extern int g_format_template_arg_depth;
extern int g_atexit_count;
extern undefined g_atexit_table;
extern int g_set_phase_count;
extern undefined4 g_pch_write_file;
extern fe_pch_header g_pch_header_read;
extern int g_pch_directive_mode;
extern int * g_pch_record_cursor;
extern int * g_pch_records_buffer;
extern void * g_file_copy_buffer;
extern c1_pch_option_block g_pch_option_block_read;
extern undefined g_io_result;
extern c1_diag_context g_diag_message_list;
extern char * g_opt_ef;
extern undefined1 DAT_104e33e4;
extern c1_u32 g_command_line_option_word;
extern c1xx_source_tracker * g_source_tracker_stack[1024];
extern c1_idb_class_record g_idb_empty_class_record;
extern undefined g_coff_current_section_data;
extern undefined4 g_source_tracker_iface;
extern HANDLE g_pch_mapping_handle;
extern c1xx_pch_image g_pch_image;
extern c1_arena g_arenas[10];
extern undefined g_arena_main_end;
extern undefined g_arena_permanent;
extern undefined g_arena1_end;
extern undefined g_arena_2;
extern undefined g_arena_3;
extern undefined g_arena_top_decl;
extern undefined g_arena_top_decl_end;
extern undefined g_arena_temp;
extern undefined g_arena_temp_end;
extern undefined g_arena_parse_state;
extern undefined g_arena_diag;
extern byte g_pch_image_map_guard;
extern c1_guid g_uuidof_null_guid;
extern c1_u8 g_uuidof_null_guid_guard;
extern c1_map_region_queue g_map_region_queue;
extern undefined4 g_import_implementation_keys;
extern c1_import_enum_table * g_import_enum_table;
extern undefined g_import_arg_name_buffer;
extern char g_import_ole_initialized;
extern c1_vector * g_import_cross_referenced_libs;
extern c1_u32 g_import_libid[4];
extern byte g_import_function_mapping_default;
extern byte g_import_function_mapping;
extern byte g_import_dual_interfaces;
extern byte g_import_no_dual_interfaces;
extern char * g_import_bstr_type;
extern char * g_import_variant_type;
extern char * g_import_smartptr_suffix;
extern byte g_import_raw_native_types;
extern char * g_import_high_putref_prefix;
extern char * g_import_high_put_prefix;
extern char * g_import_high_get_prefix;
extern char * g_import_raw_putref_prefix;
extern char * g_import_raw_put_prefix;
extern char * g_import_raw_get_prefix;
extern char * g_import_high_method_prefix;
extern char * g_import_raw_method_prefix;
extern byte g_import_high_method_prefix_given;
extern byte g_import_raw_method_prefix_given;
extern byte g_import_implementation_only;
extern byte g_import_no_implementation;
extern byte g_import_named_guids;
extern byte g_import_no_auto_exclude;
extern c1_vector * g_import_renames;
extern c1_vector * g_import_injected_statements;
extern c1_vector * g_import_includes;
extern c1_vector * g_import_excludes;
extern wchar_t * g_import_namespace;
extern byte g_import_raw_dispinterfaces;
extern byte g_import_raw_interfaces_only;
extern byte g_import_no_namespace;
extern c1_il_buffer * g_import_member_implementations;
extern c1_il_buffer * g_import_member_raw_methods;
extern c1_il_buffer * g_import_member_wrappers;
extern c1_il_buffer * g_import_member_property_data;
extern c1_il_buffer * g_import_mapping;
extern c1_il_buffer * g_import_named_guid_inits;
extern c1_il_buffer * g_import_smartptr_typedefs;
extern c1_il_buffer * g_import_tli_implementations;
extern c1_il_buffer * g_import_items;
extern c1_il_buffer * g_import_forward_refs;
extern byte g_import_missing_typelib_reported;
extern int g_import_banner_length;
extern int g_import_banner_signature_offset;
extern undefined4 g_import_banner;
extern FILE * g_import_tli_file;
extern FILE * g_import_tlh_file;
extern char * g_import_tli_path;
extern char * g_import_tlh_path;
extern char * g_import_file_as_written;
extern int g_import_implementation_key;
extern int g_eh_pending_unwind_state;
extern int g_eh_pending_unwind_count;
extern c1xx_symbol_cell * g_eh_init_target_stack;
extern c1_value_cell * g_eh_new_region_base_stack;
extern c1_value_cell * g_eh_state_stack;
extern c1_symbol * g_eh_unresolved_dtor_class;
extern c1_symbol * g_eh_array_init_symbol;
extern int g_eh_region_base_state;
extern int g_eh_new_region_base_state;
extern int g_eh_array_init_state;
extern int g_eh_previous_state;
extern c1_yy_value g_yyval;
extern c1_deferred_action * g_deferred_actions_head;
extern c1_deferred_action * g_deferred_actions_tail;
extern int g_tmpl_deduction_depth;
extern undefined g_eh_segment_records;
extern char * g_unnamed_namespace_name;
extern c1_u8 g_class_vtordisp_off;
extern short g_asm_yy_states[150];
extern undefined g_asm_yy_states_end;
extern c1_yy_value g_asm_yy_values[150];
extern c1_u16 g_asm_record_code;
extern c1_u8 g_asm_size_class;
extern c1_u8 g_asm_condition_code;
extern c1_asm_operand * g_asm_emit_records[3];
extern c1_asm_operand g_asm_operand_records[3];
extern c1_symbol * g_asm_member_class;
extern c1_asm_operand_slot * g_asm_current_operand;
extern c1_asm_operand_slot g_asm_operand_slots[3];
extern c1_asm_operand_slot * g_asm_emit_slots[3];
extern short g_asm_mnemonic_code;
extern short g_asm_instruction_code;
extern int g_asm_unread_reset_word;
extern int g_asm_operand_form;
extern int g_asm_operand_index;
extern int g_asm_at_block_start;
extern int g_asm_operands_begun;
extern int g_asm_distance_operator;
extern c1_u8 g_asm_ptr_written;
extern int g_asm_period_seen;
extern int g_asm_in_brackets;
extern int g_asm_brace_depth;
extern undefined DAT_104e62e8;
extern c1_pdb_session * g_pdb_gi;
extern c1_pdb_session g_pdb;
extern undefined g_pdb_tpi;
extern c1_pdb_session g_pdb_split;
extern uint * g_data_section_copy;
extern undefined1 g_last_in_batch;
extern char g_batch_continuing;
extern undefined __hmod__OLE32;
extern undefined4 __pfnDliNotifyHook;
extern int _adjust_fdiv;
extern float10 g_fpu_double_limit;
extern c1_u16 g_fpu_status_word;
extern undefined4 __proc_attached;
extern undefined4 _pRawDllMain;
extern undefined __xc_a;
extern undefined __xc_z;
extern undefined4 __onexitend;
extern undefined4 __onexitbegin;
extern HINSTANCE g_module_handle;
extern float g_fpu_scratch;
extern float10 g_fpu_float_limit;
extern float10 g_fpu_long_double_limit;
extern float10 g_fpu_int32_limit;
extern c1_u16 g_fpu_saved_control_word;
extern c1_u16 g_fpu_chop_control_word;
extern undefined __hmod__OLEAUT32;
extern undefined4 __puiHead;
extern undefined4 __pfnDliFailureHook;
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

c1_keyed_list * __cdecl class_lookup_member_name(c1_symbol *cls,void *name,uint flags)

{
  char cVar1;
  c1_type *pcVar2;
  c1_keyed_list *pcVar3;
  int arena;
  c1_member_lookup_ctx *ctx;
  fe_name *local_14;
  uint local_10;
  int result;
  c1_symtab *local_8;
  c1_vector *local_4;
  
  if ((*(uint *)((int)name + 8) & 0x40000) != 0) {
    if (((g_compile_flags_c8 & 0x40000000) == 0) && (((byte)g_compile_flags_cc & 0x10) == 0)) {
      arena = 5;
    }
    else {
      arena = 3;
    }
    tree_list_arena_set(arena);
    local_14 = name;
    local_10 = flags;
    result = 0;
    local_8 = (c1_symtab *)0x0;
    local_4 = vector_new(1,5);
    ctx = (c1_member_lookup_ctx *)&stack0xffffffec;
    pcVar3 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
    pcVar3 = class_member_lookup_record(pcVar3,ctx);
    sym_list_remove_matching((int *)pcVar3,local_8);
    tree_list_arena_restore();
    return pcVar3;
  }
  if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
    if ((cls->flags2 & 0x10) != 0) {
      pcVar2 = cls->type;
      cVar1 = (char)pcVar2->code;
      while (cVar1 < '\0') {
        pcVar2 = pcVar2->base;
        cVar1 = (char)pcVar2->code;
      }
      if ((pcVar2->code & 0x100) != 0) {
        return (c1_keyed_list *)0x0;
      }
    }
    if ((((cls->detail).cls)->flags3e & 0x40) == 0) {
      mre_note_member_lookup_in_bases(cls,name);
    }
  }
  return (c1_keyed_list *)0x0;
}


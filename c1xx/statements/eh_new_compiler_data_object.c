c1_symbol * __cdecl
eh_new_compiler_data_object(void *name,c1_type **type_cache,char *type_name,int segment_kind)

{
  c1_symbol *sym;
  void *pvVar1;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  c1_type *pcVar3;
  void *name_00;
  char cls;
  
  sym = sym_new_object(name,'\0');
  sym->flags1 = sym->flags1 & 0xfe | 2;
  sym->storage = sym->storage | 0x40;
  sym->flags3 = sym->flags3 | 1;
  sym->flags2 = sym->flags2 | 4;
  if (*type_cache == (c1_type *)0x0) {
    pvVar1 = name_intern(type_name);
    result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,pvVar1,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar2 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar2 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    pcVar3 = sym_word_14(pcVar2->sym);
    *type_cache = pcVar3;
  }
  sym->type = *type_cache;
  pcVar3 = *type_cache;
  if ((pcVar3->code & 0x8f) == 0x83) {
    pcVar3 = type_skip_arrays(pcVar3->base);
  }
  if (((byte)pcVar3->flags >> 5 & 1) != 0) {
    if (*(int *)(&g_eh_segment_records + segment_kind * 4) == 0) {
      cls = '\x04';
      pvVar1 = name_intern("CONST");
      name_00 = name_intern((&g_eh_segment_names)[segment_kind]);
      pvVar1 = segment_lookup_or_declare(name_00,pvVar1,cls);
      *(void **)(&g_eh_segment_records + segment_kind * 4) = pvVar1;
    }
    pvVar1 = *(void **)(&g_eh_segment_records + segment_kind * 4);
    if (pvVar1 == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
      return sym;
    }
    sym_set_segment(sym,pvVar1);
  }
  return sym;
}


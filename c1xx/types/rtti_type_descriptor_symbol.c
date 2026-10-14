c1_symbol * __cdecl rtti_type_descriptor_symbol(int type)

{
  c1_u8 *item;
  int iVar1;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  c1_symbol *pcVar3;
  
  iVar1 = type;
  if (type == 0) {
    return (c1_symbol *)0x0;
  }
  name = decorate_name_RTTI0((c1_type *)type);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar2 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar2 != (c1_lookup_entry *)0x0) {
      return pcVar2->sym;
    }
  }
  type = 0;
  pcVar3 = eh_new_compiler_data_object(name,(c1_type **)&type,"_TypeDescriptor",1);
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0xc;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)item = pcVar3;
  *(int *)(item + 4) = iVar1;
  item[8] = '\0';
  if (g_rtti_type_descriptors == (c1_vector *)0x0) {
    g_rtti_type_descriptors = vector_new(0,0);
  }
  vector_push(g_rtti_type_descriptors,item);
  return pcVar3;
}


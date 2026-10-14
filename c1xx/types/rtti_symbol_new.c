c1_symbol * __cdecl rtti_symbol_new(c1_symbol *cls,int vptr_offset,int cd_offset,void *name)

{
  c1_u8 *item;
  void *name_00;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  
  name_00 = name;
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar1 != (c1_lookup_entry *)0x0) {
      return pcVar1->sym;
    }
  }
  name = (void *)0x0;
  g_rtti_object_locator_name = name_00;
  pcVar2 = eh_new_compiler_data_object(name_00,&name,"__RTTICompleteObjectLocator",1);
  g_rtti_catchable_types = eh_collect_catchable_types(&cls->type->code,1);
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x18;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)item = pcVar2;
  item[4] = '\0';
  item[5] = '\0';
  item[6] = '\0';
  item[7] = '\0';
  *(int *)(item + 8) = vptr_offset;
  *(int *)(item + 0xc) = cd_offset;
  pcVar3 = rtti_type_descriptor_symbol((int)cls->type);
  *(c1_symbol **)(item + 0x10) = pcVar3;
  iVar4 = rtti_class_hierarchy_descriptor_symbol((int)cls);
  *(int *)(item + 0x14) = iVar4;
  if (g_rtti_object_locator_queue == (c1_vector *)0x0) {
    g_rtti_object_locator_queue = vector_new(0,0);
  }
  vector_push(g_rtti_object_locator_queue,item);
  return pcVar2;
}


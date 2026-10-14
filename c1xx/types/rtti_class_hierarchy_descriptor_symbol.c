int __cdecl rtti_class_hierarchy_descriptor_symbol(int cls)

{
  c1_u8 *item;
  int cls_00;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  int iStack_8;
  c1_type *pcStack_4;
  
  cls_00 = cls;
  name = name_intern_special_33((void *)cls);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar1 != (c1_lookup_entry *)0x0) {
      return (int)pcVar1->sym;
    }
  }
  pcStack_4 = (c1_type *)0x0;
  iStack_8 = 0;
  cls = 0;
  pcVar2 = eh_new_compiler_data_object(name,&pcStack_4,"__RTTIClassHierarchyDescriptor",1);
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x14;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)item = pcVar2;
  item[4] = '\0';
  item[5] = '\0';
  item[6] = '\0';
  item[7] = '\0';
  iVar3 = rtti_base_class_array_symbol((c1_symbol *)cls_00,&iStack_8,(uint *)&cls);
  *(int *)(item + 0x10) = iVar3;
  *(int *)(item + 0xc) = iStack_8;
  *(int *)(item + 8) = cls;
  if (((*(byte *)(*(int *)(cls_00 + 0x24) + 0x3b) & 0x10) != 0) && ((cls & 1U) != 0)) {
    *(uint *)(item + 8) = cls | 2;
  }
  if (g_rtti_class_hierarchy_descriptors == (c1_vector *)0x0) {
    g_rtti_class_hierarchy_descriptors = vector_new(0,0);
  }
  vector_push(g_rtti_class_hierarchy_descriptors,item);
  return (int)pcVar2;
}


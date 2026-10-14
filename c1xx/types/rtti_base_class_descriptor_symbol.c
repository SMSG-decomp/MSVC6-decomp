int __cdecl rtti_base_class_descriptor_symbol(c1_symbol *cls,c1_u8 **record_out,int *path)

{
  uint uVar1;
  c1_u8 *item;
  int *piVar2;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  int iVar6;
  int *piVar7;
  int aiStack_1c [7];
  
  if (path != (int *)0x0) {
    piVar2 = (int *)rtti_base_displacement_pmd(path);
    if (piVar2 == (int *)0x0) {
      aiStack_1c[3] = 0;
      aiStack_1c[4] = -1;
      aiStack_1c[5] = 0;
    }
    else {
      aiStack_1c[3] = *piVar2;
      aiStack_1c[4] = piVar2[1];
      aiStack_1c[5] = piVar2[2];
    }
    uVar1 = path[1];
    aiStack_1c[6] = 0;
    if ((uVar1 & 0x2000) != 0) {
      aiStack_1c[6] = 0x10;
    }
    if ((uVar1 & 0x400) != 0) {
      aiStack_1c[6] = aiStack_1c[6] | 9;
    }
    if ((uVar1 & 0x200) != 0) {
      aiStack_1c[6] = aiStack_1c[6] | 2;
    }
  }
  name = decorate_rtti_base_class_descriptor_name
                   (&cls->kind,aiStack_1c[3],aiStack_1c[4],aiStack_1c[5],aiStack_1c[6]);
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar3 != (c1_lookup_entry *)0x0) {
      return (int)pcVar3->sym;
    }
  }
  pcVar4 = eh_new_compiler_data_object
                     (name,&g_rtti_base_class_descriptor_type,"__RTTIBaseClassDescriptor",1);
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x1c;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *record_out = item;
  piVar2 = aiStack_1c;
  piVar7 = (int *)item;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar7 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
  }
  *(c1_symbol **)item = pcVar4;
  pcVar5 = rtti_type_descriptor_symbol((int)cls->type);
  *(c1_symbol **)(item + 4) = pcVar5;
  if (g_rtti_base_class_descriptor_queue == (c1_vector *)0x0) {
    g_rtti_base_class_descriptor_queue = vector_new(0,0);
  }
  vector_push(g_rtti_base_class_descriptor_queue,item);
  return (int)pcVar4;
}


int __cdecl lookup_adl_class_namespace(int cls,int name,int found)

{
  c1_symbol_vector **ppcVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  char cVar4;
  c1xx_hash_scope *pcVar5;
  c1_symbol_vector *pcVar6;
  
  if (*(short *)(cls + 6) == 0) {
    pcVar5 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar5 != (c1xx_hash_scope *)0x0) {
      if ((g_current_scope->visited_namespaces == (c1_symbol_vector *)0x0) ||
         (cVar4 = vector_contains_type
                            ((short *)g_current_scope->visited_namespaces,g_current_scope->global_ns
                            ), cVar4 == '\0')) {
        pcVar3 = g_current_scope->global_ns;
        ppcVar1 = &g_current_scope->visited_namespaces;
        if (g_current_scope->visited_namespaces == (c1_symbol_vector *)0x0) {
          pcVar6 = (c1_symbol_vector *)symtab_record_new_kind4();
          *ppcVar1 = pcVar6;
        }
        pcVar6 = (c1_symbol_vector *)vector_find_or_add((short *)*ppcVar1,(int)pcVar3);
        *ppcVar1 = pcVar6;
        pcVar6 = lookup_adl_in_namespace
                           (g_current_scope->global_scope,(void *)name,(c1_symbol_vector *)found);
        return (int)pcVar6;
      }
    }
  }
  else {
    pcVar3 = g_scope_vector->entries[*(short *)(cls + 6)];
    bVar2 = pcVar3->kind;
    while ((bVar2 & 0x1f) != 0x19) {
      pcVar3 = g_scope_vector->entries[(short)pcVar3->scope_index];
      if (pcVar3 == (c1_symbol *)0x0) {
        return found;
      }
      bVar2 = pcVar3->kind;
    }
    if ((g_current_scope->visited_namespaces == (c1_symbol_vector *)0x0) ||
       (cVar4 = vector_contains_type((short *)g_current_scope->visited_namespaces,pcVar3),
       cVar4 == '\0')) {
      ppcVar1 = &g_current_scope->visited_namespaces;
      if (g_current_scope->visited_namespaces == (c1_symbol_vector *)0x0) {
        pcVar6 = (c1_symbol_vector *)symtab_record_new_kind4();
        *ppcVar1 = pcVar6;
      }
      pcVar6 = (c1_symbol_vector *)vector_find_or_add((short *)*ppcVar1,(int)pcVar3);
      *ppcVar1 = pcVar6;
      pcVar6 = lookup_adl_in_namespace
                         (*(c1xx_scope **)pcVar3->type,(void *)name,(c1_symbol_vector *)found);
      return (int)pcVar6;
    }
  }
  return found;
}


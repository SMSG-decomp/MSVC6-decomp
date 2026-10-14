c1_symbol * rtti_type_info_vftable_symbol(void)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  c1_u8 *params;
  ushort auStack_5c [6];
  undefined4 uStack_50;
  c1_decl_record cStack_4c;
  
  result = (*g_current_scope->global_scope->vtbl->lookup)
                     (g_current_scope->global_scope,g_name_type_info_vftable,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar1 != (c1_lookup_entry *)0x0) {
      return pcVar1->sym;
    }
  }
  pcVar2 = sym_new_object(g_name_type_info_vftable,'\0');
  pcVar2->flags1 = pcVar2->flags1 & 0xfe | 2;
  pcVar2->flags3 = pcVar2->flags3 | 0x81;
  decl_record_init_for_symbol(&cStack_4c,(c1_symbol *)0x0);
  auStack_5c[0] = 0;
  auStack_5c[1] = 0;
  auStack_5c[2] = 0;
  auStack_5c[3] = 0;
  decl_append_array_layer(&cStack_4c,(int *)auStack_5c);
  auStack_5c[0] = 0x20;
  auStack_5c[2] = 0;
  auStack_5c[3] = 0;
  auStack_5c[4] = 0;
  uStack_50 = 0;
  decl_add_pointer_modifier(&cStack_4c,auStack_5c + 4,auStack_5c);
  params = class_record_new_kind5();
  decl_append_function_layer((int *)&cStack_4c,params);
  cStack_4c.spec_type = g_type_void;
  decl_finish_declarator(&cStack_4c);
  pcVar2->type = cStack_4c.type;
  return pcVar2;
}


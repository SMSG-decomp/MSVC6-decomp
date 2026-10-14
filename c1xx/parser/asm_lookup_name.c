c1_symbol * __cdecl asm_lookup_name(fe_name *name,int labels_allowed)

{
  byte bVar1;
  char cVar2;
  c1_lookup_entry *pcVar3;
  int iVar4;
  c1_symbol *pcVar5;
  
  if (name == g_name_dollar) {
    return g_builtin_label_1;
  }
  if (name != g_name_local_size) {
    pcVar3 = lookup_name_in_context(g_current_scope,name,0x132);
    if (pcVar3 == (c1_lookup_entry *)0x0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = pcVar3->sym;
    }
    if (pcVar5 == (c1_symbol *)0x0) {
      if (labels_allowed == 0) {
        iVar4 = asm_operand_description_id();
        diag_error(0x196,name,iVar4);
        pcVar5 = sym_new_object(name,g_block_depth);
      }
      else {
        pcVar5 = (c1_symbol *)label_find_in_function((int)name);
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = (c1_symbol *)label_new_user((int)name);
          label_register(pcVar5);
        }
      }
    }
    bVar1 = pcVar5->kind & 0x1f;
    if (((((bVar1 == 0x10) || (bVar1 == 7)) || (bVar1 == 6)) ||
        (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))) ||
       ((bVar1 == 0x1a &&
        (((bVar1 = **(byte **)pcVar5->type & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) ||
         ((bVar1 == 6 || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))))) {
      cVar2 = ovl_names_single_function(pcVar5,'\x01');
      if (cVar2 != '\0') {
        pcVar5 = sym_first_function_of_overload_set(pcVar5,'\x01');
        return pcVar5;
      }
      diag_error(0xf4,pcVar5);
      pcVar5 = sym_new_object(name,g_block_depth);
    }
    return pcVar5;
  }
  if ((g_current_function->flags22 & 1) == 0) {
    diag_error(0x1e6);
  }
  return g_builtin_label_10;
}


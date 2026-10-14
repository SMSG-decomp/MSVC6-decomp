c1_symbol * __thiscall tmpl_check_typedef_redefinition(void *name,int zero)

{
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar1 = lookup_name_in_context(g_current_scope,name,0x20);
  if (pcVar1 == (c1_lookup_entry *)zero) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = pcVar1->sym;
  }
  if (g_block_depth != '\0') {
    diag_error(0x3ac,pcVar2);
    return (c1_symbol *)0x0;
  }
  if (g_class_depth == -1) {
    diag_error(0x3a9,pcVar2);
    return (c1_symbol *)0x0;
  }
  diag_error(0x3a5,pcVar2,g_class_def_stack[g_class_depth].cls);
  return (c1_symbol *)0x0;
}


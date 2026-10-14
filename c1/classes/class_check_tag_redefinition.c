c1_tag_symbol * __cdecl class_check_tag_redefinition(void *name,ushort kind,int *insert)

{
  c1_tag_symbol *pcVar1;
  c1_tag_lookup *pcVar2;
  
  if (name != (void *)0x0) {
    pcVar2 = scope_lookup_tag_here(g_current_scope,(int)name,'\0');
    if (pcVar2 != (c1_tag_lookup *)0x0) {
      pcVar1 = pcVar2->tag;
      *insert = 0;
      if ((pcVar1->flags1 & 1) != 0) {
        pcVar1 = decl_report_type_redefinition(pcVar1);
        return pcVar1;
      }
      goto LAB_1060f41b;
    }
  }
  pcVar1 = decl_warn_type_definition_in_parentheses(name,kind,insert,1);
  if (pcVar1 == (c1_tag_symbol *)0x0) {
    return (c1_tag_symbol *)0x0;
  }
LAB_1060f41b:
  pcVar1 = esu_check_tag_and_begin_enum(pcVar1,kind);
  return pcVar1;
}


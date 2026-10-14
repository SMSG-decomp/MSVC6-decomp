c1_tag_symbol * __cdecl decl_tag_reference_lookup(int name,ushort kind,void **insert_fn)

{
  c1_tag_lookup *found;
  c1_tag_symbol *pcVar1;
  
  found = scope_stack_lookup_tag(g_current_scope,name);
  if (found == (c1_tag_lookup *)0x0) {
    pcVar1 = decl_warn_type_definition_in_parentheses((void *)name,kind,(int *)insert_fn,0);
    pcVar1 = decl_tag_check_kind_and_browse(pcVar1,kind);
    return pcVar1;
  }
  pcVar1 = found->tag;
  *insert_fn = (void *)0x0;
  pcVar1 = decl_tag_check_kind_and_browse(pcVar1,kind);
  return pcVar1;
}


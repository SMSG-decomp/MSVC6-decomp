c1_symbol * __cdecl
decl_tag_lookup_qualified_or_declare(fe_name *name,int tag_code,void **insert_fn)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar1 = class_lookup_qualified_name(g_current_scope,name);
  if (pcVar1 != (c1_u8 *)0x0) {
    pcVar2 = *(c1_symbol **)pcVar1;
    *insert_fn = (void *)0x0;
    pcVar2 = decl_tag_check_kind_and_browse(pcVar2,tag_code);
    return pcVar2;
  }
  pcVar2 = decl_tag_declare(name,(c1_u16)tag_code,insert_fn,'\0');
  pcVar2 = decl_tag_check_kind_and_browse(pcVar2,tag_code);
  return pcVar2;
}


c1_tag_symbol * __cdecl decl_tag_definition_lookup(int name,ushort kind,void **insert_fn)

{
  c1_tag_symbol *pcVar1;
  
  *insert_fn = scope_insert_through_object;
  pcVar1 = class_check_tag_redefinition((void *)name,kind,(int *)insert_fn);
  return pcVar1;
}


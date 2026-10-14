c1_keyed_list * __cdecl class_lookup_member_name_thunk(c1_symbol *cls,void *name,uint flags)

{
  c1_keyed_list *pcVar1;
  
  pcVar1 = class_lookup_member_name(cls,name,flags);
  return pcVar1;
}


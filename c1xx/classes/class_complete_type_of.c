int __cdecl class_complete_type_of(c1_type *mptype)

{
  c1_symbol *cls;
  int iVar1;
  
  cls = (c1_symbol *)type_member_pointer_class(mptype);
  iVar1 = class_complete_for_use(cls);
  return iVar1;
}


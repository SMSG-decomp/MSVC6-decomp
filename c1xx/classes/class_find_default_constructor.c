byte * __cdecl class_find_default_constructor(c1_type *type)

{
  byte *pbVar1;
  
  pbVar1 = class_find_member_function_matching(type,(int)g_name_ctor,sym_is_default_constructor);
  return pbVar1;
}


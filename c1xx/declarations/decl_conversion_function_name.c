fe_name * __cdecl decl_conversion_function_name(c1_type *type)

{
  ushort uVar1;
  fe_name *pfVar2;
  char local_1800 [6140];
  undefined4 uStack_4;
  
  uStack_4 = 0x1044e72f;
  if ((g_compile_flags_cc & 0x100000) != 0) {
    uVar1 = tmpl_type_find_parameter(type,0,0);
    if (uVar1 != 0) {
      return g_name_unnamed;
    }
  }
  decorate_name_3(local_1800,local_1800,type,'\x01');
  pfVar2 = name_intern(local_1800);
  return pfVar2;
}


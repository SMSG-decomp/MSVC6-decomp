void __cdecl decl_qualified_conversion_function_name(c1_symbol *sym,c1_type *type)

{
  ushort uVar1;
  fe_name *name;
  c1_type *pcVar2;
  
  if ((((g_compile_flags_cc & 0x200000) == 0) || (type == (c1_type *)0x0)) ||
     (uVar1 = tmpl_type_find_parameter(type,0,0), name = g_name_unnamed, uVar1 == 0)) {
    name = decl_conversion_function_name(type);
  }
  pcVar2 = (c1_type *)lookup_qualified_name((c1_keyed_list *)sym->type,name,type,'\0');
  sym->name = name;
  sym->type = pcVar2;
  return;
}


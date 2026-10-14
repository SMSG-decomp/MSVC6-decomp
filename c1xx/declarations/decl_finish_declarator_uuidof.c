void * __thiscall decl_finish_declarator_uuidof(void *value,byte *spec)

{
  c1_node *pcVar1;
  
  decl_check_conversion_return_type
            (*(c1_decl_record **)((int)value + 4),(c1xx_decl_specifiers *)spec);
  decl_finish_declarator(*(c1_decl_record **)((int)value + 4));
  pcVar1 = expr_build_uuidof(*(c1_type **)(*(int *)((int)value + 4) + 0x38));
  return pcVar1;
}


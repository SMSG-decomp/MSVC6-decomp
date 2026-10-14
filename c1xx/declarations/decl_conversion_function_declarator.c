void __cdecl decl_conversion_function_declarator(c1xx_decl_specifiers *spec,c1_decl_record *rec)

{
  fe_name *name;
  c1_symbol *pcVar1;
  
  if (rec != (c1_decl_record *)0x0) {
    name = decl_conversion_function_name(spec->type);
    pcVar1 = sym_alloc_record(0x38,3,5);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = (c1_symbol *)0x0;
    }
    else {
      pcVar1 = sym_init_kind(pcVar1,'\x03',name,5);
    }
    pcVar1->flags1 = pcVar1->flags1 | 0x40;
    rec->sym = pcVar1;
    decl_check_conversion_return_type(rec,spec);
    decl_finish_declarator(rec);
    spec->type = rec->type;
  }
  return;
}


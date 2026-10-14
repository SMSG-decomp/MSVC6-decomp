c1_symbol * __thiscall parse_type_id_declarator(c1_declarator *d,c1xx_decl_specifiers *spec)

{
  c1_symbol *pcVar1;
  int iVar2;
  c1_u32 *spec_dst;
  
  d->flags57 = d->flags57 | 0x20;
  spec->spec[0] = spec->spec[0] & 0x7f;
  decl_check_conversion_return_type(d->decl,spec);
  decl_finish_declarator(d->decl);
  spec_dst = (c1_u32 *)d->spec;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *spec_dst = *(c1_u32 *)spec->spec;
    spec = (c1xx_decl_specifiers *)(spec->spec + 4);
    spec_dst = spec_dst + 1;
  }
  decl_process_declaration(d);
  pcVar1 = sym_new_from_declarator(d,0xffffffff);
  return pcVar1;
}


void __thiscall decl_declarator_set_specifiers(c1_declarator *d,c1xx_decl_specifiers *spec)

{
  int iVar1;
  c1_u32 *spec_dst;
  
  spec_dst = (c1_u32 *)d->spec;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *spec_dst = *(c1_u32 *)spec->spec;
    spec = (c1xx_decl_specifiers *)(spec->spec + 4);
    spec_dst = spec_dst + 1;
  }
  return;
}


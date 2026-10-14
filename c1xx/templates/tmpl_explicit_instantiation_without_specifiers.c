void __thiscall tmpl_explicit_instantiation_without_specifiers(c1_declarator *d,int storage_class)

{
  int iVar1;
  c1xx_decl_specifiers *pcVar2;
  c1xx_decl_specifiers local_24;
  
  local_24.spec[0] = local_24.spec[0] & 0xf8;
  pcVar2 = &local_24;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->spec[0] = '\0';
    pcVar2->spec[1] = '\0';
    pcVar2->spec[2] = '\0';
    pcVar2->spec[3] = '\0';
    pcVar2 = (c1xx_decl_specifiers *)(pcVar2->spec + 4);
  }
  local_24.spec[0] = local_24.spec[0] & 7 ^ local_24.spec[0] | 0x30;
  local_24.type = g_type_none;
  local_24.type_sym = (c1_symbol *)0x0;
  decl_check_conversion_return_type(d->decl,&local_24);
  decl_finish_declarator(d->decl);
  tmpl_explicit_instantiation(d,(c1_u8)storage_class,&local_24);
  return;
}


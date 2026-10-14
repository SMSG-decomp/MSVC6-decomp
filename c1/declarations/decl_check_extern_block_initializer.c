c1_symbol * __cdecl
decl_check_extern_block_initializer
          (c1_u8 storage_class,c1_symbol *sym,c1_declaration *decl,c1_decl_specifiers *spec)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  
  sym->flags2 = sym->flags2 | storage_class;
  pcVar2 = decl->sym;
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = sym_new_from_declarator(decl,3);
  }
  diag_error(0xcd,pcVar2);
  pcVar2 = decl->sym;
  if ((((pcVar2->flags22 & 8) != 0) && (((pcVar2->flags1 & 1) != 0 || ((decl->flags2c & 4) != 0))))
     && (((g_compile_flags_c4 & 0x20000) == 0 ||
         (((g_current_function->flags22 & 8) == 0 || ((g_current_function->flags21 & 1) == 0)))))) {
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x1eb,pcVar2,0x179);
  }
  pcVar2 = decl->sym;
  bVar1 = pcVar2->storage & 7;
  if ((((bVar1 != 0) && (bVar1 != 7)) && (((spec->words).storage & 7) != 1)) &&
     (((decl->flags2c & 4) == 0 && ((pcVar2->kind & 0x1f) == 10)))) {
    pcVar3 = pcVar2->type;
    while ((bVar1 = (byte)pcVar3->code, (bVar1 & 0x8f) == 0x83 || ((bVar1 & 0x83) == 0x81))) {
      pcVar3 = pcVar3->base;
    }
    if (((byte)pcVar3->flags >> 5 & 1) != 0) {
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = sym_new_from_declarator(decl,3);
      }
      diag_warning(4,0x84,pcVar2);
    }
    if ((decl->sym->flags22 & 2) != 0) {
      pcVar2 = decl_based_variable_tail(decl->sym,decl);
      return pcVar2;
    }
  }
  type_check_based_allocation(decl);
  g_file_scope_decl_since_body = 1;
  return decl->sym;
}


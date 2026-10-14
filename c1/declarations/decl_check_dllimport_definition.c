c1_symbol * __cdecl
decl_check_dllimport_definition
          (c1_u8 storage_class,c1_symbol *sym,c1_declaration *decl,c1_decl_specifiers *spec)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_symbol *pcVar3;
  c1_type *pcVar4;
  
  if (((sym->flags4 & 4) == 0) || ((storage_class & sym->flags4) == 0)) {
    sym->flags1 = sym->flags1 | 1;
    if ((g_pch_use_only != 0) &&
       (((decl->sym->kind & 0x20) == 0 && (cVar2 = sym_is_deferrable(decl->sym), cVar2 != '\0')))) {
      sym_defer_emission(decl->sym);
    }
  }
  pcVar3 = decl->sym;
  if ((((pcVar3->flags22 & 8) != 0) && (((pcVar3->flags1 & 1) != 0 || ((decl->flags2c & 4) != 0))))
     && (((g_compile_flags_c4 & 0x20000) == 0 ||
         (((g_current_function->flags22 & 8) == 0 || ((g_current_function->flags21 & 1) == 0)))))) {
    if (pcVar3 == (c1_symbol *)0x0) {
      pcVar3 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x1eb,pcVar3,0x179);
  }
  pcVar3 = decl->sym;
  bVar1 = pcVar3->storage & 7;
  if ((((bVar1 != 0) && (bVar1 != 7)) && (((spec->words).storage & 7) != 1)) &&
     (((decl->flags2c & 4) == 0 && ((pcVar3->kind & 0x1f) == 10)))) {
    pcVar4 = pcVar3->type;
    while ((bVar1 = (byte)pcVar4->code, (bVar1 & 0x8f) == 0x83 || ((bVar1 & 0x83) == 0x81))) {
      pcVar4 = pcVar4->base;
    }
    if (((byte)pcVar4->flags >> 5 & 1) != 0) {
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(decl,3);
      }
      diag_warning(4,0x84,pcVar3);
    }
    if ((decl->sym->flags22 & 2) != 0) {
      pcVar3 = decl_based_variable_tail(decl->sym,decl);
      return pcVar3;
    }
  }
  type_check_based_allocation(decl);
  g_file_scope_decl_since_body = 1;
  return decl->sym;
}


c1_symbol * __thiscall
decl_declare_function_or_variable(c1_declaration *decl,c1_decl_specifiers *spec)

{
  uint uVar1;
  c1_u8 cVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  c1_type *pcVar5;
  uint uVar6;
  
  pcVar3 = decl_declare_declarator(decl,spec);
  decl->sym = pcVar3;
  if (pcVar3 == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((pcVar3->flags2 & 1) != 0) {
    return (c1_symbol *)0x0;
  }
  if ((pcVar3->kind & 0x1f) != 4) {
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      if ((pcVar3->entity & 0xffffff) == 0) {
        if (0x7ffffffe < g_next_entity_id) {
          diag_fatal_simple(0x37);
        }
        uVar1 = decl->sym->entity;
        uVar6 = uVar1 ^ g_next_entity_id;
        g_next_entity_id = g_next_entity_id + 1;
        decl->sym->entity = uVar6 & 0xffffff ^ uVar1;
      }
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,decl->sym);
    }
    pcVar3 = decl->sym;
    bVar4 = pcVar3->kind & 0x1f;
    if (((bVar4 != 7) && (bVar4 != 8)) && (bVar4 != 6)) {
      if ((pcVar3->flags22 & 8) == 0) {
        if ((decl->flags2c & 4) == 0) {
          if (((decl->spec).storage & 7) == 1) {
            if (((decl->spec).inlining & 0x10) == 0) {
              pcVar3 = decl_check_dllimport_definition('\x01',pcVar3,decl,spec);
              return pcVar3;
            }
            goto LAB_106077bd;
          }
        }
        else if ((g_block_depth != '\0') && ((pcVar3->storage & 7) == 1)) {
          pcVar3 = decl_check_extern_block_initializer('\x01',pcVar3,decl,spec);
          return pcVar3;
        }
        pcVar3->flags1 = pcVar3->flags1 | 1;
        if (((g_pch_use_only != 0) && ((decl->sym->kind & 0x20) == 0)) &&
           (cVar2 = sym_is_deferrable(decl->sym), cVar2 != '\0')) {
          sym_defer_emission(decl->sym);
        }
      }
LAB_106077bd:
      pcVar3 = decl->sym;
      if ((((pcVar3->flags22 & 8) != 0) &&
          (((pcVar3->flags1 & 1) != 0 || ((decl->flags2c & 4) != 0)))) &&
         (((g_compile_flags_c4 & 0x20000) == 0 ||
          (((g_current_function->flags22 & 8) == 0 || ((g_current_function->flags21 & 1) == 0))))))
      {
        if (pcVar3 == (c1_symbol *)0x0) {
          pcVar3 = sym_new_from_declarator(decl,3);
        }
        diag_error(0x1eb,pcVar3,0x179);
      }
      pcVar3 = decl->sym;
      bVar4 = pcVar3->storage & 7;
      if ((((bVar4 != 0) && (bVar4 != 7)) && (((spec->words).storage & 7) != 1)) &&
         (((decl->flags2c & 4) == 0 && ((pcVar3->kind & 0x1f) == 10)))) {
        pcVar5 = pcVar3->type;
        while ((bVar4 = (byte)pcVar5->code, (bVar4 & 0x8f) == 0x83 || ((bVar4 & 0x83) == 0x81))) {
          pcVar5 = pcVar5->base;
        }
        if (((byte)pcVar5->flags >> 5 & 1) != 0) {
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
    if ((decl->flags2c & 4) != 0) {
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x48,pcVar3);
      return (c1_symbol *)0x0;
    }
    if ((pcVar3->flags3 & 0x10) != 0) {
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x88,pcVar3);
    }
    if (((spec->words).declspec & 1) != 0) {
      pcVar3 = decl->sym;
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x1e8,pcVar3);
    }
    pcVar3 = decl->sym;
  }
  return pcVar3;
}


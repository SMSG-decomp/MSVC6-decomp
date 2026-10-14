c1_symbol * __cdecl
decl_check_variable_attributes(char is_member,c1_specifier_words *spec,c1_declaration *decl)

{
  uint *puVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  int *piVar4;
  c1_symbol *pcVar5;
  c1_scope_lookup *pcVar6;
  uint uVar7;
  
  bVar3 = spec->storage & 7;
  if (((3 < bVar3) && (bVar3 < 7)) && ((decl->flags2c & 4) != 0)) {
    pcVar5 = decl_symbol_or_new(decl);
    diag_error(0x1e9,pcVar5);
  }
  if (((g_declare_statics_thread != '\0') && (decl->context == 3)) &&
     ((bVar3 = spec->storage & 7, bVar3 != 0 && (bVar3 < 4)))) {
    pcVar2 = &(decl->spec).declspec;
    *pcVar2 = *pcVar2 | 2;
  }
  if (((decl->spec).declspec & 2) != 0) {
    if (((decl->context != 3) || (bVar3 = spec->storage & 7, bVar3 == 0)) || (3 < bVar3)) {
      pcVar5 = decl->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x1e0,pcVar5);
      (decl->spec).declspec = (decl->spec).declspec & 0xfd;
    }
    uVar7 = decl_dll_linkage_kind(spec);
    if ((char)uVar7 != '\0') {
      pcVar5 = decl_symbol_or_new(decl);
      diag_error(0x1ec,pcVar5);
    }
  }
  if ((((decl->spec).allocate & 1) != 0) &&
     (((decl->context != 3 || (bVar3 = spec->storage & 7, bVar3 == 0)) || (3 < bVar3)))) {
    pcVar5 = decl->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x1df,pcVar5);
    spec->allocate = spec->allocate & 0xfe;
  }
  if (((decl->spec).declspec & 0x40) != 0) {
    if ((decl->context == 3) && ((decl->flags2c & 4) != 0)) {
      bVar3 = spec->storage & 7;
      if (((bVar3 == 1) || (bVar3 == 2)) || ((bVar3 == 3 && ((spec->storage & 0x20) != 0)))) {
        pcVar2 = &(decl->spec).inlining;
        *pcVar2 = *pcVar2 | 0x80;
        goto LAB_10607925;
      }
    }
    pcVar5 = decl_symbol_or_new(decl);
    diag_error(0x1f0,pcVar5);
    bVar3 = spec->storage;
    (decl->spec).declspec = (decl->spec).declspec & 0xbf;
    spec->storage = bVar3 & 0xbf;
  }
LAB_10607925:
  if ((spec->storage & 7) == 7) {
    decl->flags2d = decl->flags2d | 4;
    if (decl->name != (void *)0x0) {
      puVar1 = (uint *)((int)decl->name + 8);
      *puVar1 = *puVar1 | 0x20000;
    }
    if (((g_opt_Zg == '\0') && ((decl->type->code & 0x200) != 0)) &&
       (pcVar5 = (decl->type->extra).sym, pcVar5->name == g_name_unnamed)) {
      pcVar5->name = decl->name;
    }
  }
  if (is_member != '\0') {
    if ((g_block_depth != '\0') && ((g_compile_flags_c4 & 0x20000) == 0)) {
      pcVar5 = sym_new_from_declarator(decl,0);
      return pcVar5;
    }
    pcVar5 = sym_new_from_declarator(decl,-1);
    return pcVar5;
  }
  piVar4 = decl_find_redeclared_symbol(g_current_scope->current,decl);
  if (piVar4 == (int *)0x0) {
    pcVar5 = (c1_symbol *)0x0;
  }
  else {
    pcVar5 = (c1_symbol *)*piVar4;
  }
  if (pcVar5 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->level == '\x01')) {
        pcVar6 = scope_stack_lookup(g_current_scope,(int)decl->name);
        if (pcVar6 == (c1_scope_lookup *)0x0) {
          pcVar5 = (c1_symbol *)0x0;
        }
        else {
          pcVar5 = pcVar6->sym;
        }
        if ((pcVar5 != (c1_symbol *)0x0) && ((pcVar5->flags1 & 4) != 0)) {
          pcVar5 = decl->sym;
          if (pcVar5 == (c1_symbol *)0x0) {
            pcVar5 = sym_new_from_declarator(decl,3);
          }
          diag_warning(1,0xe0,pcVar5);
        }
      }
    }
    else {
      piVar4 = (int *)decl_declare_formal_parameter((int *)g_current_scope,decl);
      if (piVar4 == (int *)0x0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = (c1_symbol *)*piVar4;
      }
      if (pcVar5 != (c1_symbol *)0x0) goto LAB_10607a73;
    }
    pcVar5 = sym_new_from_declarator(decl,-1);
    decl->sym = pcVar5;
    if ((pcVar5->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar7 = pcVar5->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar5->entity = uVar7 & 0xffffff ^ pcVar5->entity;
    }
    if (1 < g_block_depth) {
      decl_hoist_to_file_scope(decl->sym);
    }
    (*g_current_scope->current->vtbl->insert)(g_current_scope->current,decl->sym);
    pcVar5 = decl->sym;
  }
  else {
LAB_10607a73:
    if ((decl->flags2d & 8) != 0) {
      pcVar5->flags3 = pcVar5->flags3 | 0x80;
      return pcVar5;
    }
  }
  return pcVar5;
}


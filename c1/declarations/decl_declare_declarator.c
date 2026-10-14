c1_symbol * __thiscall decl_declare_declarator(c1_declaration *decl,c1_decl_specifiers *spec)

{
  c1_specifier_words *spec_00;
  c1_u8 *pcVar1;
  uint *puVar2;
  int iVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  int *piVar6;
  c1_scope_lookup *pcVar7;
  uint uVar8;
  
  if (decl->name == (void *)0x0) {
    return (c1_symbol *)0x0;
  }
  if (spec->type == (c1_type *)0x0) {
    return (c1_symbol *)0x0;
  }
  spec_00 = &decl->spec;
  if (((decl->spec).storage & 7) == 1) {
    pcVar1 = &(decl->spec).inlining;
    *pcVar1 = *pcVar1 | 0x10;
  }
  if ((decl->declarator->flags30 & 8) != 0) {
    decl_warn_old_style_declarator(decl);
  }
  iVar3 = decl->context;
  if ((iVar3 == 1) || (spec._0_1_ = '\0', iVar3 == 2)) {
    spec._0_1_ = '\x01';
  }
  if (iVar3 == 0) {
    decl->context = 3;
  }
  decl_abstract_declarator(decl);
  if (((decl->spec).declspec & 1) == 0) {
    if (((g_block_depth == '\x02') && (g_current_function != (c1_symbol *)0x0)) &&
       ((g_current_function->flags22 & 1) != 0)) {
      pcVar5 = decl_check_variable_attributes((char)spec,spec_00,decl);
      return pcVar5;
    }
  }
  else if (((((decl->spec).inlining & 1) == 0) || ((decl->flags2c & 0x40) == 0)) &&
          (((decl->context != 7 && (decl->context != 8)) || (-1 < g_class_depth)))) {
    pcVar5 = decl->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(decl,3);
    }
    decl_error_once_per_symbol(0x1e8,pcVar5);
  }
  if (((g_declare_statics_thread != '\0') && (decl->context == 3)) &&
     ((bVar4 = spec_00->storage & 7, bVar4 != 0 && (bVar4 < 4)))) {
    pcVar1 = &(decl->spec).declspec;
    *pcVar1 = *pcVar1 | 2;
  }
  if (((decl->spec).declspec & 2) != 0) {
    if (((decl->context != 3) || (bVar4 = spec_00->storage & 7, bVar4 == 0)) || (3 < bVar4)) {
      pcVar5 = decl->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x1e0,pcVar5);
      (decl->spec).declspec = (decl->spec).declspec & 0xfd;
    }
    uVar8 = decl_dll_linkage_kind(spec_00);
    if ((char)uVar8 != '\0') {
      pcVar5 = decl_symbol_or_new(decl);
      diag_error(0x1ec,pcVar5);
    }
  }
  if ((((decl->spec).allocate & 1) != 0) &&
     (((decl->context != 3 || (bVar4 = spec_00->storage & 7, bVar4 == 0)) || (3 < bVar4)))) {
    pcVar5 = decl->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x1df,pcVar5);
    (decl->spec).allocate = (decl->spec).allocate & 0xfe;
  }
  if (((decl->spec).declspec & 0x40) != 0) {
    if ((decl->context == 3) && ((decl->flags2c & 4) != 0)) {
      bVar4 = spec_00->storage & 7;
      if (((bVar4 == 1) || (bVar4 == 2)) || ((bVar4 == 3 && ((spec_00->storage & 0x20) != 0)))) {
        pcVar1 = &(decl->spec).inlining;
        *pcVar1 = *pcVar1 | 0x80;
        goto LAB_10607925;
      }
    }
    pcVar5 = decl_symbol_or_new(decl);
    diag_error(0x1f0,pcVar5);
    (decl->spec).declspec = (decl->spec).declspec & 0xbf;
    spec_00->storage = spec_00->storage & 0xbf;
  }
LAB_10607925:
  if ((spec_00->storage & 7) == 7) {
    decl->flags2d = decl->flags2d | 4;
    if (decl->name != (void *)0x0) {
      puVar2 = (uint *)((int)decl->name + 8);
      *puVar2 = *puVar2 | 0x20000;
    }
    if (((g_opt_Zg == '\0') && ((decl->type->code & 0x200) != 0)) &&
       (pcVar5 = (decl->type->extra).sym, pcVar5->name == g_name_unnamed)) {
      pcVar5->name = decl->name;
    }
  }
  if ((char)spec != '\0') {
    if ((g_block_depth != '\0') && ((g_compile_flags_c4 & 0x20000) == 0)) {
      pcVar5 = sym_new_from_declarator(decl,0);
      return pcVar5;
    }
    pcVar5 = sym_new_from_declarator(decl,-1);
    return pcVar5;
  }
  piVar6 = decl_find_redeclared_symbol(g_current_scope->current,decl);
  if (piVar6 == (int *)0x0) {
    pcVar5 = (c1_symbol *)0x0;
  }
  else {
    pcVar5 = (c1_symbol *)*piVar6;
  }
  if (pcVar5 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->level == '\x01')) {
        pcVar7 = scope_stack_lookup(g_current_scope,(int)decl->name);
        if (pcVar7 == (c1_scope_lookup *)0x0) {
          pcVar5 = (c1_symbol *)0x0;
        }
        else {
          pcVar5 = pcVar7->sym;
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
      piVar6 = (int *)decl_declare_formal_parameter((int *)g_current_scope,decl);
      if (piVar6 == (int *)0x0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = (c1_symbol *)*piVar6;
      }
      if (pcVar5 != (c1_symbol *)0x0) goto LAB_10607a73;
    }
    pcVar5 = sym_new_from_declarator(decl,-1);
    decl->sym = pcVar5;
    if ((pcVar5->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar8 = pcVar5->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar5->entity = uVar8 & 0xffffff ^ pcVar5->entity;
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


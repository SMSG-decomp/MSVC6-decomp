c1_symbol * __thiscall decl_declare_in_current_scope(c1_declarator *d,c1xx_decl_specifiers *specs)

{
  c1_u8 *spec;
  uint *puVar1;
  c1_u32 cVar2;
  fe_name *pfVar3;
  c1_param_clause *pcVar4;
  c1_class_record *pcVar5;
  byte bVar6;
  c1_u16 cVar7;
  c1_symbol *pcVar8;
  int *piVar9;
  c1xx_scope *pcVar10;
  c1_overload_set *pcVar11;
  void *pvVar12;
  int iVar13;
  c1xx_hash_scope *scope;
  char *pcVar14;
  c1_type *pcVar15;
  c1_lookup_result *result;
  void **sym_cell;
  c1_lookup_entry *pcVar16;
  uint uVar17;
  char cVar18;
  c1_u8 *pcVar19;
  void **sym_cell_2;
  uint spec_copy [6];
  c1_declarator *cls;
  
  if (d->name == (fe_name *)0x0) {
    return (c1_symbol *)0x0;
  }
  if (specs->type == (c1_type *)0x0) {
    return (c1_symbol *)0x0;
  }
  spec = d->spec;
  specs->spec[0] = specs->spec[0] & 0x7f;
  bVar6 = *spec;
  *spec = bVar6 & 0x7f;
  if (((bVar6 & 7) == 1) && (d->spec[1] = d->spec[1] | 0x10, g_current_function != (c1_symbol *)0x0)
     ) {
    pcVar8 = decl_note_namespace_owner_block(g_current_function,spec,d,(c1_symbol *)d);
    return pcVar8;
  }
  cls = d;
  if (d->qualifier != (c1_overload_set *)0x0) {
    spec_copy[5] = (uint)d->qualifier->list->head->sym;
    spec_copy[4] = 0x104042b4;
    iVar13 = sym_is_static_data_member((c1_symbol *)spec_copy[5]);
    if (iVar13 != 0) {
      if (((((*spec & 0x20) == 0) || ((d->spec[1] & 6) != 0)) || ((d->spec[2] & 8) != 0)) ||
         ((d->spec[3] & 0x80) != 0)) {
        spec_copy[5] = 0x10479178;
        spec_copy[5] = format_buffer_acquire();
        spec_copy[4] = 0x1047917e;
        format_buffer_free(spec_copy[5]);
        pcVar19 = spec;
        sym_cell_2 = (void **)spec_copy;
        for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
          *sym_cell_2 = *(void **)pcVar19;
          pcVar19 = pcVar19 + 4;
          sym_cell_2 = sym_cell_2 + 1;
        }
        iVar13 = format_decl_specifiers_text
                           (0,spec_copy[0],(void *)spec_copy[1],spec_copy[2],spec_copy[3],
                            spec_copy[4],spec_copy[5]);
        pcVar14 = format_buffer_text(iVar13);
        diag_error(0x2d0,d->qualifier->list->head->sym,pcVar14);
        spec_copy[5] = 0x104791b8;
        format_buffer_leave();
        *spec = *spec & 0xf8;
        pcVar19 = spec;
        for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
          pcVar19[0] = '\0';
          pcVar19[1] = '\0';
          pcVar19[2] = '\0';
          pcVar19[3] = '\0';
          pcVar19 = pcVar19 + 4;
        }
        bVar6 = *spec & 7 ^ *spec;
        *spec = bVar6;
        *spec = bVar6 | 8;
        d->flags54 = d->flags54 | 0x40;
      }
      else if ((d->spec[0x14] & 2) != 0) {
        pcVar8 = decl_check_function_declaration(spec,d,(c1_symbol *)cls);
        return pcVar8;
      }
    }
  }
  if ((d->decl->flags & 8) != 0) {
    spec_copy[5] = 0x104042fc;
    decl_enter_declaration_context(d);
    pcVar4 = d->decl->params;
    if (pcVar4 != (c1_param_clause *)0x0) {
      iVar13 = *(int *)(pcVar4->pad15 + 3);
      if (iVar13 == 1) {
        d->spec[3] = d->spec[3] | 0x10;
      }
      else if (iVar13 != 2) goto LAB_10404090;
      d->spec[3] = d->spec[3] | 0x20;
    }
  }
LAB_10404090:
  cVar2 = d->kind;
  if ((cVar2 == 1) || (specs._0_1_ = '\0', cVar2 == 2)) {
    specs._0_1_ = '\x01';
  }
  if (cVar2 == 0) {
    d->kind = 3;
  }
  spec_copy[5] = 0x104040be;
  decl_process_declaration(d);
  cVar2 = d->kind;
  if ((((((cVar2 != 2) && (cVar2 != 1)) &&
        ((cVar2 != 8 && (((cVar2 != 7 || (g_class_depth < 0)) || ((d->spec[1] & 4) != 0)))))) &&
       ((*spec & 7) != 7)) && ((cVar2 != 7 || ((d->flags55 & 0xc0) == 0)))) &&
     ((pfVar3 = d->name, pfVar3 != (fe_name *)0x0 && ((pfVar3->flags & 0x2000000) != 0)))) {
    spec_copy[5] = 0x20;
    spec_copy[3] = 0x10479209;
    spec_copy[4] = (uint)pfVar3;
    pcVar16 = lookup_name_in_context(g_current_scope,pfVar3,0x20);
    if (pcVar16 == (c1_lookup_entry *)0x0) {
      spec_copy[5] = 0;
    }
    else {
      spec_copy[5] = (uint)pcVar16->sym;
    }
    if ((d->kind == 7) || (d->kind == 8)) {
      spec_copy[4] = 0x3a7;
    }
    else if ((g_compile_flags_c8 & 0x10000000) == 0) {
      if ((((*spec & 7) == 0) || (3 < (*spec & 7))) && (g_block_depth != '\0')) {
        if (g_block_depth == '\x01') {
          spec_copy[4] = 0x3ae;
        }
        else {
          spec_copy[4] = 0x3ab;
        }
      }
      else {
        spec_copy[4] = 0x3a8;
      }
    }
    else {
      spec_copy[4] = 0x3b0;
    }
    spec_copy[3] = 0x10479227;
    diag_error((short)spec_copy[4]);
  }
  spec_copy[5] = 0x10404107;
  decl_check_missing_type_specifier(d);
  if ((d->spec[2] & 1) == 0) {
    if (((g_block_depth == '\x02') && (g_current_function != (c1_symbol *)0x0)) &&
       ((g_current_function->flags22 & 1) != 0)) {
      pcVar8 = decl_check_auto_variable(spec,d,3,(c1_symbol *)cls,(char)specs);
      return pcVar8;
    }
  }
  else if ((((d->spec[1] & 1) == 0) || ((d->flags54 & 0x40) == 0)) &&
          (((d->kind != 7 && (d->kind != 8)) || (-1 < g_class_depth)))) {
    pcVar8 = d->sym;
    if (pcVar8 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x104792b1;
      pcVar8 = sym_new_from_declarator(d,5);
    }
    if ((pcVar8->flags3 & 4) == 0) {
      spec_copy[4] = 0x1e8;
      spec_copy[3] = 0x104792c8;
      spec_copy[5] = (uint)pcVar8;
      diag_error(0x1e8);
      pcVar8->flags3 = pcVar8->flags3 | 4;
    }
  }
  if ((d->spec[2] & 2) != 0) {
    if ((((d->kind == 3) || (d->kind == 2)) && ((*spec & 7) != 0)) && ((*spec & 7) < 4)) {
      spec_copy[4] = (uint)d->type;
      spec_copy[5] = (uint)&stack0xfffffffc;
      spec_copy[3] = 0x10479350;
      uVar17 = type_classify_class_form((c1_type *)spec_copy[4],(int *)spec_copy[5]);
      if (((uVar17 & 3) != 0) && ((*(byte *)(cls->position + 0x3c) & 1) == 0)) {
        spec_copy[5] = (uint)d->sym;
        if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
          spec_copy[5] = 5;
          spec_copy[4] = 0x10479374;
          spec_copy[5] = (uint)sym_new_from_declarator(d,5);
        }
        spec_copy[4] = 0x1e3;
        spec_copy[3] = 0x1047937f;
        diag_error_once_per_symbol(0x1e3,(c1_symbol *)spec_copy[5]);
      }
    }
    else {
      spec_copy[5] = (uint)d->sym;
      if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
        spec_copy[5] = 5;
        spec_copy[4] = 0x104793bb;
        spec_copy[5] = (uint)sym_new_from_declarator(d,5);
      }
      spec_copy[4] = 0x1e0;
      spec_copy[3] = 0x104793c6;
      diag_error(0x1e0);
      d->spec[2] = d->spec[2] & 0xfd;
    }
    spec_copy[5] = 0x10479389;
    uVar17 = decl_dll_linkage_kind(spec);
    if ((char)uVar17 != '\0') {
      spec_copy[5] = 0x10479398;
      spec_copy[5] = (uint)sym_ensure_declarator_symbol(d);
      spec_copy[4] = 0x1ec;
      spec_copy[3] = 0x104793a3;
      diag_error(0x1ec);
    }
  }
  if (((d->spec[3] & 1) != 0) &&
     (((d->kind != 3 && (d->kind != 2)) || (((*spec & 7) == 0 || (3 < (*spec & 7))))))) {
    spec_copy[5] = (uint)d->sym;
    if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x104793ff;
      spec_copy[5] = (uint)sym_new_from_declarator(d,5);
    }
    spec_copy[4] = 0x1df;
    spec_copy[3] = 0x1047940a;
    diag_error(0x1df);
    d->spec[3] = d->spec[3] & 0xfe;
  }
  if (((d->spec[3] & 0x10) != 0) && (d->kind != 7)) {
    pcVar8 = decl_check_declspec_applicability(d->kind,spec,d,3,(char)specs);
    return pcVar8;
  }
  if ((d->spec[2] & 0x40) != 0) {
    if ((d->kind == 3) && ((d->flags54 & 4) != 0)) {
      bVar6 = *spec & 7;
      if (((bVar6 == 1) || (bVar6 == 2)) || ((bVar6 == 3 && ((*spec & 0x20) != 0)))) {
        d->spec[1] = d->spec[1] | 0x80;
        goto LAB_10404146;
      }
    }
    spec_copy[5] = (uint)d->sym;
    if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x10479495;
      spec_copy[5] = (uint)sym_new_from_declarator(d,5);
    }
    spec_copy[4] = 0x1f0;
    spec_copy[3] = 0x104794a0;
    diag_error(0x1f0);
    bVar6 = *spec;
    d->spec[2] = d->spec[2] & 0xbf;
    *spec = bVar6 & 0xbf;
  }
LAB_10404146:
  if ((d->spec[3] & 0x80) != 0) {
    if ((d->kind == 2) && ((*spec & 7) != 3)) {
      if ((d->type->code & 0x8f) == 0x83) {
        do {
          spec_copy[5] = 0x104794de;
          pcVar15 = type_base(d->type);
          d->type = pcVar15;
        } while ((pcVar15->code & 0x8f) == 0x83);
        d->flags54 = d->flags54 & 0x7f;
        d->flags55 = d->flags55 & 0xfe;
      }
    }
    else {
      spec_copy[5] = (uint)d->sym;
      if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
        spec_copy[5] = 5;
        spec_copy[4] = 0x1047950f;
        spec_copy[5] = (uint)sym_new_from_declarator(d,5);
      }
      spec_copy[4] = 0x30b;
      spec_copy[3] = 0x1047951a;
      diag_error(0x30b);
      d->spec[3] = d->spec[3] & 0x7f;
    }
  }
  if ((((d->spec[0x14] & 1) != 0) && (d->kind != 7)) && (d->kind != 8)) {
    pcVar8 = d->sym;
    if (pcVar8 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x1047954f;
      pcVar8 = sym_new_from_declarator(d,5);
    }
    if ((pcVar8->flags3 & 4) == 0) {
      spec_copy[4] = 0x1f1;
      spec_copy[3] = 0x10479566;
      spec_copy[5] = (uint)pcVar8;
      diag_error(0x1f1);
      pcVar8->flags3 = pcVar8->flags3 | 4;
    }
  }
  if (((d->spec[0x14] & 2) != 0) && (pcVar8 = d->sym, (pcVar8->kind & 0x1f) != 4)) {
    if (pcVar8 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x10479594;
      pcVar8 = sym_new_from_declarator(d,5);
    }
    spec_copy[4] = 0x1f2;
    spec_copy[3] = 0x1047959f;
    spec_copy[5] = (uint)pcVar8;
    diag_error_once_per_symbol(0x1f2,pcVar8);
  }
  if (((d->flags56 & 1) != 0) && ((d->decl->flags & 4) != 0)) {
    pcVar8 = decl_check_conversion_syntax_2(spec,d,(char)specs);
    return pcVar8;
  }
  if ((d->flags54 & 0x40) != 0) {
    cVar2 = d->kind;
    if ((cVar2 == 2) || (cVar2 == 1)) {
      cVar18 = '\x01';
    }
    else {
      cVar18 = '\0';
    }
    if (((((char)specs != cVar18) && (cVar2 != 7)) && (cVar2 != 8)) && (cVar2 != 0xc))
    goto LAB_10404280;
  }
  if (d->qualifier != (c1_overload_set *)0x0) {
    spec_copy[5] = 0x104043a3;
    pcVar11 = (c1_overload_set *)decl_resolve_function_in_overload_set(d);
    d->qualifier = pcVar11;
    if (pcVar11 == (c1_overload_set *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar8 = pcVar11->list->head->sym;
    spec_copy[5] = (uint)pcVar8;
    if ((d->kind == 7) || (d->kind == 8)) {
      spec_copy[4] = 0x104043cb;
      decl_check_redeclaration(d,pcVar8);
      return pcVar8;
    }
    if (((pcVar8->flags4 & 0x40) == 0) || ((pcVar8->kind & 0x1f) != 3)) {
      if ((g_compile_flags_c4 & 0x200) != 0) {
        spec_copy[4] = 0x10479632;
        decl_check_redeclaration(d,pcVar8);
        return pcVar8;
      }
      if ((pcVar8->scope_index != 0) &&
         (pcVar8 = g_scope_vector->entries[(short)pcVar8->scope_index],
         (pcVar8->kind & 0x1f) == 0x19)) {
        d->owner = pcVar8;
        spec_copy[4] = (uint)d->name;
        spec_copy[5] = 1;
        spec_copy[3] = 0x10479676;
        result = (c1_lookup_result *)(**(code **)(**(int **)pcVar8->type + 0xc))();
        if (result == (c1_lookup_result *)0x0) {
          spec_copy[3] = 0;
          spec_copy[2] = 0x104796c5;
          pcVar8 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
          if (pcVar8 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = 0xc;
          spec_copy[2] = 0x104796d7;
          sym_cell = arena_alloc(g_arenas + 5,0xc);
        }
        else {
          spec_copy[3] = 1;
          spec_copy[2] = 0x10479683;
          pcVar16 = lookup_check_ambiguous_symbol(result,'\x01');
          if (pcVar16 == (c1_lookup_entry *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = (uint)pcVar16->sym;
          spec_copy[2] = 0x10479691;
          pcVar8 = decl_redeclare_or_new(d,(c1_symbol *)spec_copy[3]);
          if (pcVar8 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = 0xc;
          spec_copy[2] = 0x104796a3;
          sym_cell = arena_alloc(g_arenas + 5,0xc);
        }
        if (sym_cell != (void **)0x0) {
          *sym_cell = pcVar8;
          sym_cell[1] = (void *)0x0;
          sym_cell[2] = (void *)0x0;
          if (sym_cell != (void **)0x0) {
            return *sym_cell;
          }
        }
        return (c1_symbol *)0x0;
      }
      goto LAB_104044bc;
    }
    if ((g_compile_flags_cc & 0x200000) != 0) {
      return pcVar8;
    }
    spec_copy[4] = 0x10404403;
    pvVar12 = sym_static_member_stand_in(pcVar8);
    d->name = *(fe_name **)((int)pvVar12 + 8);
    *spec = *spec & 0xfa | 2;
  }
  if ((*spec & 7) == 7) {
    d->flags55 = d->flags55 | 4;
    if (d->name != (fe_name *)0x0) {
      puVar1 = &d->name->flags;
      *puVar1 = *puVar1 | 0x20000;
    }
    pcVar15 = d->type;
    if (((pcVar15->code & 0x300) != 0) ||
       (((bVar6 = (byte)pcVar15->code, (char)bVar6 < '\0' && ((bVar6 & 0x8f) == 0x80)) &&
        (pcVar15 = pcVar15->base, (pcVar15->code & 0x300) != 0)))) {
      pcVar8 = (pcVar15->extra).cls;
      if (pcVar8 == (c1_symbol *)0x0) {
        d->flags54 = d->flags54 | 0x40;
        return d->sym;
      }
      if ((pcVar8->flags3 & 1) != 0) {
        if (d->kind == 2) {
          puVar1 = &d->name->flags;
          *puVar1 = *puVar1 | 0x40000;
        }
        pcVar8->name = d->name;
        pcVar8->flags3 = pcVar8->flags3 & 0xfe;
        ((pcVar8->detail).cls)->layout_flags3c = ((pcVar8->detail).cls)->layout_flags3c | 8;
        if (g_c9il_mode == '\0') {
          d->flags54 = d->flags54 | 0x10;
        }
      }
    }
    pfVar3 = d->name;
    if ((pfVar3 != (fe_name *)0x0) && ((pfVar3->flags & 0x2000000) != 0)) {
      pcVar8 = tmpl_check_typedef_redefinition(pfVar3,0);
      return pcVar8;
    }
  }
  if ((char)specs != '\0') {
LAB_104044bc:
    spec_copy[5] = 0xffffffff;
    spec_copy[4] = 0x104044c5;
    pcVar8 = sym_new_from_declarator(d,0xffffffff);
    return pcVar8;
  }
  if ((g_compile_flags_cc & 1) != 0) {
    if (d->kind == 7) {
      d->flags56 = d->flags56 | 0x20;
    }
    else if (d->kind == 8) {
      pcVar8 = scope_lookup_in_list_fragment(spec,d,0);
      return pcVar8;
    }
  }
  spec_copy[5] = 0x104041b5;
  pcVar8 = scope_current_namespace(g_current_scope);
  if (pcVar8 != (c1_symbol *)0x0) {
    d->owner = pcVar8;
  }
  if (d->qualifier == (c1_overload_set *)0x0) {
LAB_104041cd:
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((g_class_depth < 0) || ((d->spec[1] & 4) == 0)) goto LAB_104041e6;
      spec_copy[5] = 0;
      spec_copy[3] = 0;
      spec_copy[2] = 0x1040455c;
      spec_copy[4] = (uint)d;
      scope = scope_enclosing_namespace(g_current_scope,'\0');
      spec_copy[3] = 0x10404563;
      piVar9 = (int *)scope_lookup_for_declaration(scope,(c1_declarator *)spec_copy[4],spec_copy[5])
      ;
      goto LAB_104041f2;
    }
LAB_104041fa:
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    spec_copy[5] = (uint)d->qualifier->list->head->sym;
    spec_copy[4] = 0x104044f5;
    iVar13 = sym_is_static_data_member((c1_symbol *)spec_copy[5]);
    if (iVar13 == 0) goto LAB_104041cd;
    if (g_scope_vector->entries[(short)d->qualifier->list->head->key->sym->scope_index] !=
        (c1_symbol *)0x0) {
      pcVar8 = decl_declare_parameters
                         ((int)g_scope_vector,
                          g_scope_vector->entries
                          [(short)d->qualifier->list->head->key->sym->scope_index],spec,d,0x100000);
      return pcVar8;
    }
LAB_104041e6:
    spec_copy[4] = 0x104041f2;
    spec_copy[5] = (uint)d;
    piVar9 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar9 == (int *)0x0) goto LAB_104041fa;
    pcVar8 = (c1_symbol *)*piVar9;
  }
  if (pcVar8 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
        spec_copy[4] = (uint)d->name;
        spec_copy[5] = 0x132;
        spec_copy[3] = 0x1047985a;
        pcVar16 = lookup_name_in_context(g_current_scope,(void *)spec_copy[4],0x132);
        if (pcVar16 == (c1_lookup_entry *)0x0) {
          pcVar8 = (c1_symbol *)0x0;
        }
        else {
          pcVar8 = pcVar16->sym;
        }
        if ((pcVar8 != (c1_symbol *)0x0) && ((pcVar8->flags2 & 0x10) != 0)) {
          spec_copy[5] = (uint)d->sym;
          if ((c1_symbol *)spec_copy[5] == (c1_symbol *)0x0) {
            spec_copy[5] = 5;
            spec_copy[4] = 0x10479882;
            spec_copy[5] = (uint)sym_new_from_declarator(d,5);
          }
          spec_copy[4] = 0xe0;
          spec_copy[3] = 1;
          spec_copy[2] = 0x1047988f;
          diag_warning(1,0xe0);
        }
      }
    }
    else {
      spec_copy[4] = 0x1040457b;
      spec_copy[5] = (uint)d;
      piVar9 = (int *)decl_bind_block_declaration(g_current_scope,d);
      if (piVar9 == (int *)0x0) {
        pcVar8 = (c1_symbol *)0x0;
      }
      else {
        pcVar8 = (c1_symbol *)*piVar9;
      }
      if (pcVar8 != (c1_symbol *)0x0) goto LAB_1040458f;
    }
    spec_copy[5] = 0xffffffff;
    spec_copy[4] = 0x10404229;
    pcVar8 = sym_new_from_declarator(d,0xffffffff);
    d->sym = pcVar8;
    if ((pcVar8->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        spec_copy[5] = 0x37;
        spec_copy[4] = 0x104798ae;
        diag_fatal_simple(0x37);
      }
      uVar17 = g_next_entity_id ^ pcVar8->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar8->entity = uVar17 & 0xffffff ^ pcVar8->entity;
    }
    if (1 < g_block_depth) {
      spec_copy[5] = (uint)d->sym;
      spec_copy[4] = 0x104045b6;
      inline_function_instance_new((c1_symbol *)spec_copy[5]);
    }
    if (d->kind == 3) {
      if (((g_compile_flags_c4 & 0x20) != 0) || (cVar7 = g_block_number, (*spec & 7) == 1)) {
        cVar7 = 0;
      }
      (d->sym->x28).block_number = cVar7;
    }
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((d->spec[1] & 0x20) != 0) {
        spec_copy[5] = (uint)d->sym;
        spec_copy[4] = 0x104799b1;
        (*g_current_scope->global_scope->vtbl->insert)();
        return d->sym;
      }
      pcVar8 = d->sym;
      spec_copy[5] = 1;
      spec_copy[4] = 0x10404278;
      pcVar10 = scope_innermost_declaration_record(g_current_scope,'\x01');
      spec_copy[4] = 0x10404280;
      spec_copy[5] = (uint)pcVar8;
      (*pcVar10->vtbl->insert)();
    }
LAB_10404280:
    return d->sym;
  }
LAB_1040458f:
  if ((d->flags55 & 8) != 0) {
    pcVar8->flags4 = pcVar8->flags4 | 0x80;
  }
  if ((d->spec[3] & 0x40) == 0) {
    return pcVar8;
  }
  bVar6 = pcVar8->kind & 0x1f;
  if (bVar6 == 4) {
    if ((((pcVar8->detail).cls)->flags3f & 1) != 0) {
      return pcVar8;
    }
    spec_copy[5] = (uint)pcVar8->name;
    spec_copy[4] = 0x38f;
    spec_copy[3] = 0x1047982c;
    diag_error(0x38f);
    return pcVar8;
  }
  spec_copy[5] = (uint)pcVar8;
  if (bVar6 == 7) {
    bVar6 = *(byte *)((int)&pcVar8->tail + 9);
    if ((bVar6 & 0x80) != 0) {
      return pcVar8;
    }
    if ((bVar6 & 0x40) == 0) {
      spec_copy[4] = 0x390;
      spec_copy[3] = 0x1047990b;
      diag_error(0x390);
      return pcVar8;
    }
    spec_copy[4] = 0x44;
    spec_copy[3] = 0x38c;
    spec_copy[2] = 0x104798f4;
    diag_error(0x38c);
    return pcVar8;
  }
  if (bVar6 != 10) {
    return pcVar8;
  }
  spec_copy[4] = 0x10479926;
  spec_copy[5] = (uint)symtab_14ac_lookup_by_name(pcVar8);
  if ((void *)spec_copy[5] == (void *)0x0) {
    if (d->sym != (c1_symbol *)0x0) {
      return d->sym;
    }
    spec_copy[5] = 5;
    spec_copy[4] = 0x10479941;
    pcVar8 = sym_new_from_declarator(d,5);
    return pcVar8;
  }
  pcVar5 = (g_scope_vector->entries[*(short *)(spec_copy[5] + 6)]->detail).cls;
  if ((pcVar5->flags3f & 1) != 0) {
    return pcVar8;
  }
  if ((pcVar5->flags3e & 1) != 0) {
    if ((pcVar8->key_ref & 3) == 0) {
      return pcVar8;
    }
    spec_copy[4] = 0x44;
    spec_copy[3] = 0x38c;
    spec_copy[2] = 0x10479981;
    diag_error(0x38c);
    return pcVar8;
  }
  spec_copy[4] = 0x38b;
  spec_copy[3] = 0x10479999;
  diag_error(0x38b);
  return pcVar8;
}


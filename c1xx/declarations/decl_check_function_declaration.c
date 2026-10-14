c1_symbol * __thiscall decl_check_function_declaration(c1_u8 *spec,c1_declarator *d,c1_symbol *cls)

{
  c1_u32 cVar1;
  fe_name *pfVar2;
  c1_param_clause *pcVar3;
  c1_class_record *pcVar4;
  byte bVar5;
  c1_u16 cVar6;
  c1_symbol *pcVar7;
  int *piVar8;
  c1xx_scope *pcVar9;
  c1_overload_set *pcVar10;
  void *pvVar11;
  c1xx_hash_scope *scope;
  char *pcVar12;
  c1_type *pcVar13;
  c1_lookup_result *result;
  uint *cursor;
  c1_lookup_entry *pcVar14;
  uint uVar15;
  byte bVar16;
  char cVar17;
  int iVar18;
  uint *puVar19;
  uint *cursor_2;
  c1_u8 *pcVar20;
  char is_member;
  uint spec_copy [6];
  
  spec_copy[5] = 0x10479178;
  spec_copy[5] = format_buffer_acquire();
  spec_copy[4] = 0x1047917e;
  format_buffer_free(spec_copy[5]);
  puVar19 = (uint *)spec;
  cursor_2 = spec_copy;
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    *cursor_2 = *puVar19;
    puVar19 = puVar19 + 1;
    cursor_2 = cursor_2 + 1;
  }
  iVar18 = format_decl_specifiers_text
                     (0,spec_copy[0],(void *)spec_copy[1],spec_copy[2],spec_copy[3],spec_copy[4],
                      spec_copy[5]);
  pcVar12 = format_buffer_text(iVar18);
  diag_error(0x2d0,d->qualifier->list->head->sym,pcVar12);
  spec_copy[5] = 0x104791b8;
  format_buffer_leave();
  *spec = *spec & 0xf8;
  pcVar20 = spec;
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    pcVar20[0] = '\0';
    pcVar20[1] = '\0';
    pcVar20[2] = '\0';
    pcVar20[3] = '\0';
    pcVar20 = pcVar20 + 4;
  }
  bVar16 = *spec & 7 ^ *spec;
  *spec = bVar16;
  bVar5 = d->flags54;
  *spec = bVar16 | 8;
  d->flags54 = bVar5 | 0x40;
  if ((d->decl->flags & 8) != 0) {
    spec_copy[5] = 0x104042fc;
    decl_enter_declaration_context(d);
    pcVar3 = d->decl->params;
    if (pcVar3 != (c1_param_clause *)0x0) {
      iVar18 = *(int *)(pcVar3->pad15 + 3);
      if (iVar18 == 1) {
        d->spec[3] = d->spec[3] | 0x10;
      }
      else if (iVar18 != 2) goto LAB_10404090;
      d->spec[3] = d->spec[3] | 0x20;
    }
  }
LAB_10404090:
  cVar1 = d->kind;
  if ((cVar1 == 1) || (is_member = '\0', cVar1 == 2)) {
    is_member = '\x01';
  }
  if (cVar1 == 0) {
    d->kind = 3;
  }
  spec_copy[5] = 0x104040be;
  decl_process_declaration(d);
  cVar1 = d->kind;
  if (((((((cVar1 != 2) && (cVar1 != 1)) && (cVar1 != 8)) &&
        (((cVar1 != 7 || (g_class_depth < 0)) || ((d->spec[1] & 4) != 0)))) &&
       (((*spec & 7) != 7 && ((cVar1 != 7 || ((d->flags55 & 0xc0) == 0)))))) &&
      (pfVar2 = d->name, pfVar2 != (fe_name *)0x0)) && ((pfVar2->flags & 0x2000000) != 0)) {
    spec_copy[5] = 0x20;
    spec_copy[3] = 0x10479209;
    spec_copy[4] = (uint)pfVar2;
    pcVar14 = lookup_name_in_context(g_current_scope,pfVar2,0x20);
    if (pcVar14 == (c1_lookup_entry *)0x0) {
      spec_copy[5] = 0;
    }
    else {
      spec_copy[5] = (uint)pcVar14->sym;
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
      pcVar7 = decl_check_auto_variable(spec,d,3,cls,is_member);
      return pcVar7;
    }
  }
  else if ((((d->spec[1] & 1) == 0) || ((d->flags54 & 0x40) == 0)) &&
          (((d->kind != 7 && (d->kind != 8)) || (-1 < g_class_depth)))) {
    pcVar7 = d->sym;
    if (pcVar7 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x104792b1;
      pcVar7 = sym_new_from_declarator(d,5);
    }
    if ((pcVar7->flags3 & 4) == 0) {
      spec_copy[4] = 0x1e8;
      spec_copy[3] = 0x104792c8;
      spec_copy[5] = (uint)pcVar7;
      diag_error(0x1e8);
      pcVar7->flags3 = pcVar7->flags3 | 4;
    }
  }
  if ((d->spec[2] & 2) != 0) {
    if ((((d->kind == 3) || (d->kind == 2)) && ((*spec & 7) != 0)) && ((*spec & 7) < 4)) {
      spec_copy[4] = (uint)d->type;
      spec_copy[5] = (uint)&cls;
      spec_copy[3] = 0x10479350;
      uVar15 = type_classify_class_form((c1_type *)spec_copy[4],(int *)spec_copy[5]);
      if (((uVar15 & 3) != 0) && ((((cls->detail).cls)->layout_flags3c & 1) == 0)) {
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
    uVar15 = decl_dll_linkage_kind(spec);
    if ((char)uVar15 != '\0') {
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
    spec[3] = spec[3] & 0xfe;
  }
  if (((d->spec[3] & 0x10) != 0) && (d->kind != 7)) {
    pcVar7 = decl_check_declspec_applicability(d->kind,spec,d,3,is_member);
    return pcVar7;
  }
  if ((d->spec[2] & 0x40) != 0) {
    if ((d->kind == 3) && ((d->flags54 & 4) != 0)) {
      bVar5 = *spec & 7;
      if (((bVar5 == 1) || (bVar5 == 2)) || ((bVar5 == 3 && ((*spec & 0x20) != 0)))) {
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
    bVar5 = *spec;
    d->spec[2] = d->spec[2] & 0xbf;
    *spec = bVar5 & 0xbf;
  }
LAB_10404146:
  if ((d->spec[3] & 0x80) != 0) {
    if ((d->kind == 2) && ((*spec & 7) != 3)) {
      if ((d->type->code & 0x8f) == 0x83) {
        do {
          spec_copy[5] = 0x104794de;
          pcVar13 = type_base(d->type);
          d->type = pcVar13;
        } while ((pcVar13->code & 0x8f) == 0x83);
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
    pcVar7 = d->sym;
    if (pcVar7 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x1047954f;
      pcVar7 = sym_new_from_declarator(d,5);
    }
    if ((pcVar7->flags3 & 4) == 0) {
      spec_copy[4] = 0x1f1;
      spec_copy[3] = 0x10479566;
      spec_copy[5] = (uint)pcVar7;
      diag_error(0x1f1);
      pcVar7->flags3 = pcVar7->flags3 | 4;
    }
  }
  if (((d->spec[0x14] & 2) != 0) && (pcVar7 = d->sym, (pcVar7->kind & 0x1f) != 4)) {
    if (pcVar7 == (c1_symbol *)0x0) {
      spec_copy[5] = 5;
      spec_copy[4] = 0x10479594;
      pcVar7 = sym_new_from_declarator(d,5);
    }
    spec_copy[4] = 0x1f2;
    spec_copy[3] = 0x1047959f;
    spec_copy[5] = (uint)pcVar7;
    diag_error_once_per_symbol(0x1f2,pcVar7);
  }
  if (((d->flags56 & 1) != 0) && ((d->decl->flags & 4) != 0)) {
    pcVar7 = decl_check_conversion_syntax_2(spec,d,is_member);
    return pcVar7;
  }
  if ((d->flags54 & 0x40) != 0) {
    cVar1 = d->kind;
    if ((cVar1 == 2) || (cVar1 == 1)) {
      cVar17 = '\x01';
    }
    else {
      cVar17 = '\0';
    }
    if ((((is_member != cVar17) && (cVar1 != 7)) && (cVar1 != 8)) && (cVar1 != 0xc))
    goto LAB_10404280;
  }
  if (d->qualifier != (c1_overload_set *)0x0) {
    spec_copy[5] = 0x104043a3;
    pcVar10 = (c1_overload_set *)decl_resolve_function_in_overload_set(d);
    d->qualifier = pcVar10;
    if (pcVar10 == (c1_overload_set *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar7 = pcVar10->list->head->sym;
    spec_copy[5] = (uint)pcVar7;
    if ((d->kind == 7) || (d->kind == 8)) {
      spec_copy[4] = 0x104043cb;
      decl_check_redeclaration(d,pcVar7);
      return pcVar7;
    }
    if (((pcVar7->flags4 & 0x40) == 0) || ((pcVar7->kind & 0x1f) != 3)) {
      if ((g_compile_flags_c4 & 0x200) != 0) {
        spec_copy[4] = 0x10479632;
        decl_check_redeclaration(d,pcVar7);
        return pcVar7;
      }
      if ((pcVar7->scope_index != 0) &&
         (pcVar7 = g_scope_vector->entries[(short)pcVar7->scope_index],
         (pcVar7->kind & 0x1f) == 0x19)) {
        d->owner = pcVar7;
        spec_copy[4] = (uint)d->name;
        spec_copy[5] = 1;
        spec_copy[3] = 0x10479676;
        result = (c1_lookup_result *)(**(code **)(**(int **)pcVar7->type + 0xc))();
        if (result == (c1_lookup_result *)0x0) {
          spec_copy[3] = 0;
          spec_copy[2] = 0x104796c5;
          pcVar7 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
          if (pcVar7 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = 0xc;
          spec_copy[2] = 0x104796d7;
          cursor = arena_alloc(g_arenas + 5,0xc);
        }
        else {
          spec_copy[3] = 1;
          spec_copy[2] = 0x10479683;
          pcVar14 = lookup_check_ambiguous_symbol(result,'\x01');
          if (pcVar14 == (c1_lookup_entry *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = (uint)pcVar14->sym;
          spec_copy[2] = 0x10479691;
          pcVar7 = decl_redeclare_or_new(d,(c1_symbol *)spec_copy[3]);
          if (pcVar7 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          spec_copy[3] = 0xc;
          spec_copy[2] = 0x104796a3;
          cursor = arena_alloc(g_arenas + 5,0xc);
        }
        if (cursor != (uint *)0x0) {
          *cursor = (uint)pcVar7;
          cursor[1] = 0;
          cursor[2] = 0;
          if (cursor != (uint *)0x0) {
            return (c1_symbol *)*cursor;
          }
        }
        return (c1_symbol *)0x0;
      }
      goto LAB_104044bc;
    }
    if ((g_compile_flags_cc & 0x200000) != 0) {
      return pcVar7;
    }
    spec_copy[4] = 0x10404403;
    pvVar11 = sym_static_member_stand_in(pcVar7);
    d->name = *(fe_name **)((int)pvVar11 + 8);
    *spec = *spec & 0xfa | 2;
  }
  if ((*spec & 7) == 7) {
    d->flags55 = d->flags55 | 4;
    if (d->name != (fe_name *)0x0) {
      puVar19 = &d->name->flags;
      *puVar19 = *puVar19 | 0x20000;
    }
    pcVar13 = d->type;
    if (((pcVar13->code & 0x300) != 0) ||
       (((bVar5 = (byte)pcVar13->code, (char)bVar5 < '\0' && ((bVar5 & 0x8f) == 0x80)) &&
        (pcVar13 = pcVar13->base, (pcVar13->code & 0x300) != 0)))) {
      pcVar7 = (pcVar13->extra).cls;
      if (pcVar7 == (c1_symbol *)0x0) {
        d->flags54 = d->flags54 | 0x40;
        return d->sym;
      }
      if ((pcVar7->flags3 & 1) != 0) {
        if (d->kind == 2) {
          puVar19 = &d->name->flags;
          *puVar19 = *puVar19 | 0x40000;
        }
        pcVar7->name = d->name;
        pcVar7->flags3 = pcVar7->flags3 & 0xfe;
        ((pcVar7->detail).cls)->layout_flags3c = ((pcVar7->detail).cls)->layout_flags3c | 8;
        if (g_c9il_mode == '\0') {
          d->flags54 = d->flags54 | 0x10;
        }
      }
    }
    pfVar2 = d->name;
    if ((pfVar2 != (fe_name *)0x0) && ((pfVar2->flags & 0x2000000) != 0)) {
      pcVar7 = tmpl_check_typedef_redefinition(pfVar2,0);
      return pcVar7;
    }
  }
  if (is_member != '\0') {
LAB_104044bc:
    spec_copy[5] = 0xffffffff;
    spec_copy[4] = 0x104044c5;
    pcVar7 = sym_new_from_declarator(d,0xffffffff);
    return pcVar7;
  }
  if ((g_compile_flags_cc & 1) != 0) {
    if (d->kind == 7) {
      d->flags56 = d->flags56 | 0x20;
    }
    else if (d->kind == 8) {
      pcVar7 = scope_lookup_in_list_fragment(spec,d,0);
      return pcVar7;
    }
  }
  spec_copy[5] = 0x104041b5;
  pcVar7 = scope_current_namespace(g_current_scope);
  if (pcVar7 != (c1_symbol *)0x0) {
    d->owner = pcVar7;
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
      piVar8 = (int *)scope_lookup_for_declaration(scope,(c1_declarator *)spec_copy[4],spec_copy[5])
      ;
      goto LAB_104041f2;
    }
LAB_104041fa:
    pcVar7 = (c1_symbol *)0x0;
  }
  else {
    spec_copy[5] = (uint)d->qualifier->list->head->sym;
    spec_copy[4] = 0x104044f5;
    iVar18 = sym_is_static_data_member((c1_symbol *)spec_copy[5]);
    if (iVar18 == 0) goto LAB_104041cd;
    if (g_scope_vector->entries[(short)d->qualifier->list->head->key->sym->scope_index] !=
        (c1_symbol *)0x0) {
      pcVar7 = decl_declare_parameters
                         ((int)g_scope_vector,
                          g_scope_vector->entries
                          [(short)d->qualifier->list->head->key->sym->scope_index],spec,d,0x100000);
      return pcVar7;
    }
LAB_104041e6:
    spec_copy[4] = 0x104041f2;
    spec_copy[5] = (uint)d;
    piVar8 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar8 == (int *)0x0) goto LAB_104041fa;
    pcVar7 = (c1_symbol *)*piVar8;
  }
  if (pcVar7 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
        spec_copy[4] = (uint)d->name;
        spec_copy[5] = 0x132;
        spec_copy[3] = 0x1047985a;
        pcVar14 = lookup_name_in_context(g_current_scope,(void *)spec_copy[4],0x132);
        if (pcVar14 == (c1_lookup_entry *)0x0) {
          pcVar7 = (c1_symbol *)0x0;
        }
        else {
          pcVar7 = pcVar14->sym;
        }
        if ((pcVar7 != (c1_symbol *)0x0) && ((pcVar7->flags2 & 0x10) != 0)) {
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
      piVar8 = (int *)decl_bind_block_declaration(g_current_scope,d);
      if (piVar8 == (int *)0x0) {
        pcVar7 = (c1_symbol *)0x0;
      }
      else {
        pcVar7 = (c1_symbol *)*piVar8;
      }
      if (pcVar7 != (c1_symbol *)0x0) goto LAB_1040458f;
    }
    spec_copy[5] = 0xffffffff;
    spec_copy[4] = 0x10404229;
    pcVar7 = sym_new_from_declarator(d,0xffffffff);
    d->sym = pcVar7;
    if ((pcVar7->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        spec_copy[5] = 0x37;
        spec_copy[4] = 0x104798ae;
        diag_fatal_simple(0x37);
      }
      uVar15 = g_next_entity_id ^ pcVar7->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar7->entity = uVar15 & 0xffffff ^ pcVar7->entity;
    }
    if (1 < g_block_depth) {
      spec_copy[5] = (uint)d->sym;
      spec_copy[4] = 0x104045b6;
      inline_function_instance_new((c1_symbol *)spec_copy[5]);
    }
    if (d->kind == 3) {
      if (((g_compile_flags_c4 & 0x20) != 0) || (cVar6 = g_block_number, (*spec & 7) == 1)) {
        cVar6 = 0;
      }
      (d->sym->x28).block_number = cVar6;
    }
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((d->spec[1] & 0x20) != 0) {
        spec_copy[5] = (uint)d->sym;
        spec_copy[4] = 0x104799b1;
        (*g_current_scope->global_scope->vtbl->insert)();
        return d->sym;
      }
      pcVar7 = d->sym;
      spec_copy[5] = 1;
      spec_copy[4] = 0x10404278;
      pcVar9 = scope_innermost_declaration_record(g_current_scope,'\x01');
      spec_copy[4] = 0x10404280;
      spec_copy[5] = (uint)pcVar7;
      (*pcVar9->vtbl->insert)();
    }
LAB_10404280:
    return d->sym;
  }
LAB_1040458f:
  if ((d->flags55 & 8) != 0) {
    pcVar7->flags4 = pcVar7->flags4 | 0x80;
  }
  if ((d->spec[3] & 0x40) == 0) {
    return pcVar7;
  }
  bVar5 = pcVar7->kind & 0x1f;
  if (bVar5 == 4) {
    if ((((pcVar7->detail).cls)->flags3f & 1) != 0) {
      return pcVar7;
    }
    spec_copy[5] = (uint)pcVar7->name;
    spec_copy[4] = 0x38f;
    spec_copy[3] = 0x1047982c;
    diag_error(0x38f);
    return pcVar7;
  }
  spec_copy[5] = (uint)pcVar7;
  if (bVar5 == 7) {
    bVar5 = *(byte *)((int)&pcVar7->tail + 9);
    if ((bVar5 & 0x80) != 0) {
      return pcVar7;
    }
    if ((bVar5 & 0x40) == 0) {
      spec_copy[4] = 0x390;
      spec_copy[3] = 0x1047990b;
      diag_error(0x390);
      return pcVar7;
    }
    spec_copy[4] = 0x44;
    spec_copy[3] = 0x38c;
    spec_copy[2] = 0x104798f4;
    diag_error(0x38c);
    return pcVar7;
  }
  if (bVar5 != 10) {
    return pcVar7;
  }
  spec_copy[4] = 0x10479926;
  spec_copy[5] = (uint)symtab_14ac_lookup_by_name(pcVar7);
  if ((void *)spec_copy[5] == (void *)0x0) {
    if (d->sym != (c1_symbol *)0x0) {
      return d->sym;
    }
    spec_copy[5] = 5;
    spec_copy[4] = 0x10479941;
    pcVar7 = sym_new_from_declarator(d,5);
    return pcVar7;
  }
  pcVar4 = (g_scope_vector->entries[*(short *)(spec_copy[5] + 6)]->detail).cls;
  if ((pcVar4->flags3f & 1) != 0) {
    return pcVar7;
  }
  if ((pcVar4->flags3e & 1) != 0) {
    if ((pcVar7->key_ref & 3) == 0) {
      return pcVar7;
    }
    spec_copy[4] = 0x44;
    spec_copy[3] = 0x38c;
    spec_copy[2] = 0x10479981;
    diag_error(0x38c);
    return pcVar7;
  }
  spec_copy[4] = 0x38b;
  spec_copy[3] = 0x10479999;
  diag_error(0x38b);
  return pcVar7;
}


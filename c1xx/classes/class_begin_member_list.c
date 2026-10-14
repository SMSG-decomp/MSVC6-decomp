char __thiscall class_begin_member_list(c1_declarator *d,c1xx_decl_specifiers *spec,c1_symbol **out)

{
  c1_u8 *pcVar1;
  ushort uVar2;
  fe_name *pfVar3;
  c1_u32 cVar4;
  c1_class_record *pcVar5;
  c1_symbol *pcVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  c1_symbol *pcVar10;
  int iVar11;
  c1_symbol_detail cVar12;
  c1_lookup_entry *pcVar13;
  c1_type *pcVar14;
  c1xx_decl_specifiers *pcVar15;
  c1_symbol *pcVar16;
  c1_u32 *spec_dst;
  c1_u8 spec_copy [24];
  
  if (g_class_depth < 0) {
    diag_error(0x1c);
    return '\0';
  }
  pfVar3 = d->name;
  pcVar14 = spec->type;
  if (pfVar3 == (fe_name *)0x0) {
    if ((d->spec[1] & 4) != 0) {
      if ((pcVar14->code & 0x800) != 0) {
        return '\0';
      }
      class_add_friend(g_class_def_stack[g_class_depth].cls,spec,(c1_symbol *)0x0);
      if (g_browse_file == (char *)0x0) {
        return '\0';
      }
      (*g_il_emitter->vtbl->record_d)((spec->type->extra).count);
      return '\0';
    }
    uVar2 = pcVar14->code;
    if ((((uVar2 & 0x200) == 0) || (pcVar16 = (pcVar14->extra).cls, pcVar16 == (c1_symbol *)0x0)) ||
       ((pcVar16->flags3 & 1) == 0)) {
      if (((uVar2 & 0x300) == 0) && (((char)uVar2 < '\0' || ((uVar2 & 0xfff) != 0x801)))) {
        pcVar16 = spec->type_sym;
        if ((pcVar16 != (c1_symbol *)0x0) && ((pcVar16->kind & 0x1f) == 0x12)) {
          ns_member_using_declaration(&pcVar16->kind);
          return '\0';
        }
      }
      else if ((d->spec[0] & 0x80) == 0) {
        return '\0';
      }
      diag_error(0xd0,pcVar14);
      return '\0';
    }
    if ((uVar2 & 0x20f) != 0x203) {
      diag_extension_warning_or_error(0xc9,0x1d3,pcVar14);
    }
    if (((pcVar16->flags2 & 4) == 0) &&
       (tmpl_instantiate_if_needed(pcVar16), (pcVar16->flags2 & 4) == 0)) {
      if (g_opt_Zg != '\0') {
        return '\0';
      }
      diag_error(0x1b,pcVar16);
      return '\0';
    }
    class_check_anonymous_union(spec->spec);
    class_add_anonymous_member(pcVar14);
    return '\0';
  }
  bVar8 = d->spec[0];
  d->spec[0] = bVar8 & 0x7f;
  if ((d->flags55 & 0x80) == 0) {
    if ((g_class_depth < 0) || (pfVar3 != (g_class_def_stack[g_class_depth].cls)->name)) {
      if ((((bVar8 & 7) == 0) && ((d->spec[1] & 4) == 0)) &&
         ((((pfVar3 == g_name_new || (pfVar3 == g_name_delete)) || (pfVar3 == g_name_array_new)) ||
          (pfVar3 == g_name_array_delete)))) {
        d->spec[0] = d->spec[0] & 0xfb | 3;
        spec->spec[0] = spec->spec[0] & 0xfb | 3;
      }
    }
    else {
      if ((d->decl->flags & 8) == 0) {
        pcVar16 = d->sym;
        if (pcVar16 == (c1_symbol *)0x0) {
          pcVar16 = sym_new_from_declarator(d,5);
        }
        diag_error(0x244,pcVar16);
        d->spec[0] = d->spec[0] | 8;
        d->flags54 = d->flags54 | 0x40;
        return '\0';
      }
      d->name = g_name_ctor;
      d->flags55 = d->flags55 | 0x40;
      d->owner = g_class_def_stack[g_class_depth].cls;
      if ((g_paren_level_flags[g_paren_depth] & 1) != 0) {
        if ((spec->spec[0] & 0x10) == 0) {
          pcVar14 = g_class_def_stack[g_class_depth].type;
          cVar9 = (char)pcVar14->code;
          while (cVar9 < '\0') {
            pcVar14 = pcVar14->base;
            cVar9 = (char)pcVar14->code;
          }
          iVar11 = type_is_class_or_enum(pcVar14);
          if ((char)iVar11 == '\0') {
            pcVar16 = (c1_symbol *)0x0;
          }
          else {
            pcVar16 = (pcVar14->extra).cls;
          }
          pcVar14 = spec->type;
          cVar9 = (char)pcVar14->code;
          while (cVar9 < '\0') {
            pcVar14 = pcVar14->base;
            cVar9 = (char)pcVar14->code;
          }
          iVar11 = type_is_class_or_enum(pcVar14);
          if ((char)iVar11 == '\0') {
            pcVar10 = (c1_symbol *)0x0;
          }
          else {
            pcVar10 = (pcVar14->extra).cls;
          }
          if (pcVar16 != pcVar10) {
            diag_error(0x215,g_class_def_stack[g_class_depth].cls);
            goto LAB_10434d2c;
          }
        }
        pcVar16 = g_class_def_stack[g_class_depth].cls;
        pcVar15 = spec;
        spec_dst = (c1_u32 *)spec_copy;
        for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
          *spec_dst = *(c1_u32 *)pcVar15->spec;
          pcVar15 = (c1xx_decl_specifiers *)(pcVar15->spec + 4);
          spec_dst = spec_dst + 1;
        }
        if (((spec_copy[1] & 6) != 0) || ((spec_copy[0] & 7) != 0)) {
          diag_error(0x279,pcVar16);
        }
      }
    }
  }
  else {
    d->name = g_name_dtor;
  }
LAB_10434d2c:
  if ((d->spec[1] & 4) != 0) {
    class_declare_friend_function(d,spec->spec,g_class_def_stack[g_class_depth].cls);
    return '\0';
  }
  pcVar16 = (c1_symbol *)0x0;
  if (d->qualifier != (c1_overload_set *)0x0) {
    if ((((d->spec[0] & 0x10) != 0) && ((d->spec[0] & 0x20) != 0)) && ((d->decl->flags & 4) != 0)) {
      bVar8 = g_current_scope->current->kind;
      if ((0xfa < bVar8) && (bVar8 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_warn_access_declaration(g_class_def_stack[g_class_depth].cls,d->qualifier);
      return '\x01';
    }
    if (d->qualifier->list->head->key->sym != g_class_def_stack[g_class_depth].cls) {
      diag_error(0x346);
      bVar8 = g_current_scope->current->kind;
      if ((0xfa < bVar8) && (bVar8 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      return '\x01';
    }
  }
  if ((((g_class_def_stack[g_class_depth].cls)->flags22 & 0xc) != 0) &&
     (((((d->spec[0] & 7) == 3 || (bVar8 = d->decl->flags, (bVar8 & 8) != 0)) ||
       (((bVar8 & 4) != 0 && ((spec->type->code & 0x83) == 0x81)))) &&
      (((pfVar3 = d->name, pfVar3 != g_name_scalar_deleting_dtor &&
        (pfVar3 != g_name_vector_deleting_dtor)) && (pfVar3 != g_name_local_vftable_ctor_closure))))
     )) {
    class_check_dll_interface_member(d,(int)spec);
  }
  d->owner = g_class_def_stack[g_class_depth].cls;
  if ((d->qualifier != (c1_overload_set *)0x0) && (d->qualifier->list == (c1_keyed_list *)0x0)) {
    d->qualifier = (c1_overload_set *)0x0;
  }
  pcVar10 = decl_declare_in_current_scope(d,spec);
  d->sym = pcVar10;
  if (pcVar10 != (c1_symbol *)0x0) {
    d->qualifier = (c1_overload_set *)0x0;
    if ((d->kind == 7) || (d->kind == 8)) {
      if (((d->flags55 & 0x80) != 0) && ((pcVar10->type->flags & 0x4000) == 0)) {
        diag_error(0x20c,g_class_def_stack[g_class_depth].cls);
        return '\0';
      }
      if ((d->name->flags & 0x2000000) != 0) {
        pcVar13 = lookup_name_in_context(g_current_scope,d->name,0x20);
        if (pcVar13 == (c1_lookup_entry *)0x0) {
          pcVar16 = (c1_symbol *)0x0;
        }
        else {
          pcVar16 = pcVar13->sym;
        }
        diag_error(0x3a3,pcVar16,g_class_def_stack[g_class_depth].cls);
        return '\0';
      }
      pcVar10->flags1 = pcVar10->flags1 | 4;
    }
    else {
      if ((d->flags55 & 0x80) != 0) {
        diag_error(0x20c,g_class_def_stack[g_class_depth].cls);
        return '\0';
      }
      if ((d->flags55 & 0x40) != 0) {
        diag_error(0x1cd,g_class_def_stack[g_class_depth].cls);
        return '\0';
      }
      if (((d->spec[0] & 0x10) != 0) && ((d->spec[0] & 0x20) != 0)) {
        return '\0';
      }
      if ((d->flags56 & 2) != 0) {
        diag_error(0xfc,pcVar10);
        return '\0';
      }
      if (((d->flags54 & 0x20) == 0) && (d->name->text != (char *)0x0)) {
        pcVar5 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
        pcVar5->layout_flags3c = pcVar5->layout_flags3c | 0x40;
        if ((d->name->flags & 0x2000000) != 0) {
          pcVar13 = lookup_name_in_context(g_current_scope,d->name,0x20);
          if (pcVar13 == (c1_lookup_entry *)0x0) {
            pcVar16 = (c1_symbol *)0x0;
          }
          else {
            pcVar16 = pcVar13->sym;
          }
          diag_error(0x3a4,pcVar16,g_class_def_stack[g_class_depth].cls);
          return '\0';
        }
        if ((g_compile_flags_c8 & 0x1000000) != 0) {
          deferred_body_list_add(&g_deferred_member_bodies,d->sym);
          g_compile_flags_c8 = g_compile_flags_c8 & 0xfeffffff;
        }
      }
    }
    if ((g_class_def_stack[g_class_depth].flags & 3) < 3) {
      g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags | 4;
    }
    pcVar10 = class_current_member_lookup(d->name);
    if (pcVar10 != (c1_symbol *)0x0) {
      if ((pcVar10->kind & 0x1f) == 0xf) {
        diag_error(0x56);
        return '\0';
      }
      pcVar16 = decl_redeclare_or_new(d,pcVar10);
      pcVar6 = d->sym;
      if (((*(byte *)((int)&pcVar6->tail + 9) & 0x40) != 0) && (pcVar16 != pcVar6)) {
        *out = pcVar16;
        return '\0';
      }
      if (pcVar16 == (c1_symbol *)0x0) {
        if ((pcVar6->flags3 & 4) != 0) {
          return '\0';
        }
        if ((pcVar10->flags3 & 4) != 0) {
          return '\0';
        }
      }
      else {
        if ((pcVar16->flags3 & 4) != 0) {
          return '\0';
        }
        if ((pcVar6->flags3 & 4) != 0) {
          return '\0';
        }
      }
    }
    bVar8 = d->spec[0] & 7;
    if (bVar8 == 7) {
      d->sym->kind = d->sym->kind & 0xea | 10;
      if (pcVar16 == (c1_symbol *)0x0) {
        class_append_member(d->sym);
      }
    }
    else {
      pcVar14 = d->type;
      while ((bVar7 = (byte)pcVar14->code, (bVar7 & 0x8f) == 0x83 || ((bVar7 & 0x83) == 0x81))) {
        pcVar14 = pcVar14->base;
      }
      if ((((((byte)pcVar14->flags >> 5 & 1) != 0) && (d->kind != 7)) && (d->kind != 8)) &&
         (bVar8 != 3)) {
        pcVar1 = &(((g_class_def_stack[g_class_depth].cls)->detail).cls)->layout_flags3c;
        *pcVar1 = *pcVar1 | 0x10;
      }
      if ((d->spec[3] & 4) != 0) {
        pcVar1 = &(((g_class_def_stack[g_class_depth].cls)->detail).cls)->flags3f;
        *pcVar1 = *pcVar1 | 0x10;
      }
      cVar4 = d->kind;
      if (cVar4 == 1) {
        pcVar14 = d->type;
        cVar9 = (char)pcVar14->code;
        while (cVar9 < '\0') {
          pcVar14 = pcVar14->base;
          cVar9 = (char)pcVar14->code;
        }
        class_layout_bitfield_member(d->sym,pcVar14->code,pcVar16 == (c1_symbol *)0x0);
      }
      else if ((cVar4 == 7) || (cVar4 == 8)) {
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_alias_record(d->sym);
        }
        if ((d->flags55 & 0x40) == 0) {
          if ((d->flags55 & 0x80) != 0) {
            pcVar10->flags1 = pcVar10->flags1 | 0x20;
            pcVar1 = &(g_class_def_stack[g_class_depth].cls)->flags1;
            *pcVar1 = *pcVar1 | 0x20;
          }
        }
        else {
          pcVar10->flags1 = pcVar10->flags1 | 0x10;
          pcVar1 = &(g_class_def_stack[g_class_depth].cls)->flags1;
          *pcVar1 = *pcVar1 | 0x10;
        }
        class_declare_special_member(d);
        if (pcVar16 == (c1_symbol *)0x0) {
          class_append_member(pcVar10);
        }
      }
      else {
        pcVar14 = (g_class_def_stack[g_class_depth].cls)->type;
        cVar9 = (char)pcVar14->code;
        while (cVar9 < '\0') {
          pcVar14 = pcVar14->base;
          cVar9 = (char)pcVar14->code;
        }
        if (((pcVar14->code & 0x20f) == 0x203) &&
           (cVar9 = class_check_union_member(g_class_def_stack[g_class_depth].cls,d->sym),
           cVar9 == '\0')) {
          return '\0';
        }
        if ((((((g_class_def_stack[g_class_depth].cls)->flags22 & 0xc) != 0) &&
             (pcVar10 = sym_class_type_of(d->sym), pcVar10 != (c1_symbol *)0x0)) &&
            ((pcVar10->flags22 & 0xc) == 0)) && ((((pcVar10->detail).cls)->layout_flags3c & 1) == 0)
           ) {
          diag_warning(2,0xfb,d->sym,pcVar10->type,pcVar10,
                       (g_class_def_stack[g_class_depth].cls)->type,
                       g_class_def_stack[g_class_depth].cls);
        }
        pcVar10 = d->sym;
        if (pcVar10->name != g_name_alignment_member) {
          if ((pcVar10->flags23 & 0x80) == 0) {
            iVar11 = sym_is_static_data_member(pcVar10);
            if (iVar11 == 0) {
              cVar12 = (c1_symbol_detail)class_check_zero_sized_array_member(d->sym);
              d->sym->detail = cVar12;
            }
            else {
              (d->sym->detail).cls = (c1_class_record *)0x0;
              if (g_block_depth != '\0') {
                pcVar10 = d->sym;
                if (pcVar10 == (c1_symbol *)0x0) {
                  pcVar10 = sym_new_from_declarator(d,5);
                }
                diag_error(0xf6,pcVar10);
              }
            }
          }
          else {
            (pcVar10->detail).cls = (c1_class_record *)0x0;
          }
        }
        if ((d->spec[0] & 7) == 3) {
          esumem_ice(d);
        }
        if (pcVar16 == (c1_symbol *)0x0) {
          class_append_member(d->sym);
        }
        if ((d->spec[0] & 7) != 3) {
          bVar8 = (g_class_def_stack[g_class_depth].cls)->flags5;
          (g_class_def_stack[g_class_depth].cls)->flags5 = (d->sym->flags5 ^ bVar8) & 1 ^ bVar8;
          g_class_def_stack[g_class_depth].bitfield_type = 0;
        }
      }
    }
    if (((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) &&
       (((g_class_def_stack[g_class_depth].cls)->flags3 & 1) == 0)) {
      pcVar16 = d->sym;
      bVar8 = pcVar16->kind & 0x1f;
      if (((bVar8 != 7) && (bVar8 != 8)) || ((pcVar16->entity & 0xff000000) == 0)) {
        (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar16);
      }
    }
    return '\0';
  }
  return '\0';
}


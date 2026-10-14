void __fastcall class_declare_special_member(c1_declarator *d)

{
  byte *pbVar1;
  c1_u8 *pcVar2;
  uint *puVar3;
  fe_name *pfVar4;
  c1_class_record *pcVar5;
  int iVar6;
  char cVar7;
  c1_type *pcVar8;
  c1_symbol *pcVar9;
  uint uVar10;
  c1_u32 *pcVar11;
  
  pcVar11 = &d->sym->entity;
  if ((*pcVar11 & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar10 = *pcVar11 ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    *pcVar11 = uVar10 & 0xffffff ^ *pcVar11;
  }
  d->sym->flags1 = d->sym->flags1 | 4;
  if ((d->flags56 & 1) != 0) {
    pcVar2 = &(((g_class_def_stack[g_class_depth].cls)->detail).cls)->flags3f;
    *pcVar2 = *pcVar2 | 2;
  }
  pfVar4 = d->name;
  if ((((pfVar4 == g_name_new) || (pfVar4 == g_name_delete)) || (pfVar4 == g_name_array_new)) ||
     ((pfVar4 == g_name_array_delete || ((d->spec[0] & 7) == 3)))) {
    *(byte *)((int)&d->sym->tail + 8) = *(byte *)((int)&d->sym->tail + 8) & 0xfe;
    pcVar8 = type_function_map_parameters(d->sym->type,type_params_make_static);
    d->sym->type = pcVar8;
  }
  else {
    pbVar1 = (byte *)((int)&d->sym->tail + 8);
    *pbVar1 = *pbVar1 | 1;
  }
  if ((d->flags55 & 0x40) == 0) {
    if ((d->flags55 & 0x80) == 0) {
      if (d->name == g_name_operator_assign) {
        if ((d->spec[0] & 7) == 3) {
          diag_error(0x245,g_class_def_stack[g_class_depth].cls);
        }
        else {
          class_mark_copy_assignment_operator(d->sym);
        }
      }
      else if (((d->spec[1] & 2) != 0) && ((g_class_def_stack[g_class_depth].flags & 8) == 0)) {
        class_check_union_virtual(d);
        return;
      }
    }
    else {
      pcVar9 = d->sym;
      iVar6 = *(int *)(**(int **)(((uint)pcVar9->type & -(uint)((pcVar9->type->code & 0x80) != 0)) +
                                 8) + 4);
      if ((*(byte *)(iVar6 + 2) & 0x20) != 0) {
        if (pcVar9 == (c1_symbol *)0x0) {
          pcVar9 = sym_new_from_declarator(d,5);
        }
        diag_error(0x247,pcVar9,0x2f);
      }
      if ((*(byte *)(iVar6 + 2) & 0x40) != 0) {
        pcVar9 = d->sym;
        if (pcVar9 == (c1_symbol *)0x0) {
          pcVar9 = sym_new_from_declarator(d,5);
        }
        diag_error(0x247,pcVar9,0x30);
      }
      if (((d->spec[1] & 2) != 0) && ((g_class_def_stack[g_class_depth].flags & 8) == 0)) {
        class_check_pure_on_unnamed(d);
        return;
      }
    }
  }
  else {
    class_check_copy_constructor_signature(d->sym);
    pcVar9 = d->sym;
    iVar6 = *(int *)(**(int **)(((uint)pcVar9->type & -(uint)((pcVar9->type->code & 0x80) != 0)) + 8
                               ) + 4);
    if ((*(byte *)(iVar6 + 2) & 0x20) != 0) {
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar9 = sym_new_from_declarator(d,5);
      }
      diag_error(0x247,pcVar9,0x2f);
    }
    if ((*(byte *)(iVar6 + 2) & 0x40) != 0) {
      class_check_ctor_dtor_this_qualifiers(d);
      return;
    }
  }
  if ((d->spec[1] & 2) != 0) {
    puVar3 = &d->name->flags;
    *puVar3 = *puVar3 | 0x100000;
  }
  if (((*(byte *)((int)&d->sym->tail + 8) & 1) != 0) &&
     (cVar7 = class_overrides_base_virtual
                        ((c1_sym_link *)&d->sym->name,g_class_def_stack[g_class_depth].cls,'\x01'),
     cVar7 != '\0')) {
    d->sym->flags21 = d->sym->flags21 | 2;
    puVar3 = &d->sym->name->flags;
    *puVar3 = *puVar3 | 0x100000;
  }
  if ((d->flags56 & 2) != 0) {
    pcVar9 = d->sym;
    if ((pcVar9->flags21 & 2) == 0) {
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar9 = sym_new_from_declarator(d,5);
      }
      diag_error(0xfd,pcVar9);
    }
    else if (((g_class_def_stack[g_class_depth].cls)->flags3 & 1) == 0) {
      pcVar5 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
      pcVar5->layout_flags3b = pcVar5->layout_flags3b | 0x80;
      pbVar1 = (byte *)((int)&d->sym->tail + 8);
      *pbVar1 = *pbVar1 | 4;
    }
    else {
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar9 = sym_new_from_declarator(d,5);
      }
      diag_error(0x11b,pcVar9,(g_class_def_stack[g_class_depth].cls)->type);
    }
  }
  decl_check_operator_function(d->sym,0);
  decl_check_default_parameters_of(d->sym);
  if ((g_compile_flags_c4 & 0x4000000) == 0) {
    func_parse_definition_or_skip(d->sym,d->spec[1] >> 2 & 1);
  }
  else if ((((g_class_def_stack[g_class_depth].flags & 0x10) == 0) &&
           (g_current_function != (c1_symbol *)0x0)) &&
          (pcVar9 = d->sym, (*(byte *)((int)&pcVar9->tail + 9) & 0x10) == 0)) {
    *(byte *)((int)&pcVar9->tail + 8) = *(byte *)((int)&pcVar9->tail + 8) & 0xf7;
    class_synthesize_special_member_tokens(g_class_def_stack[g_class_depth].cls,d->sym);
    return;
  }
  return;
}


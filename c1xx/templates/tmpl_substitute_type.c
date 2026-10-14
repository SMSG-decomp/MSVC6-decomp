c1_type * __cdecl tmpl_substitute_type(c1_type *type,c1_arg_list *args)

{
  c1_arg_value cVar1;
  bool bVar2;
  bool bVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_u8 cVar6;
  c1_u8 *pcVar7;
  ushort uVar8;
  c1_type *pcVar9;
  c1_type *pcVar10;
  int *piVar11;
  c1_arg_item *pcVar12;
  c1_type *pcVar13;
  c1_symbol *pcVar14;
  uint uVar15;
  c1_type_extra cVar16;
  int iVar17;
  uint *puVar18;
  c1_arg_item *pcVar19;
  uint *param_slot;
  c1_arg_list *local_30;
  c1_type_list *local_2c;
  c1_type local_20;
  c1_type local_10;
  c1_function_params *fparams;
  
  pcVar13 = type;
  uVar8 = type->code;
  if ((char)uVar8 < '\0') {
    pcVar9 = tmpl_substitute_type(type->base,args);
    uVar8 = type->code;
    switch(uVar8 & 0x8f) {
    case 0x80:
      if (pcVar9 != (c1_type *)0x0) {
        if (type->base == pcVar9) {
          return type;
        }
        local_20.code = type->code;
        local_20.flags = type->flags;
        local_20.extra = type->extra;
        local_20.debug_index = type->debug_index;
        local_20.base = pcVar9;
        pcVar13 = type_intern(&local_20);
        return pcVar13;
      }
      break;
    case 0x81:
    case 0x85:
      fparams = (type->extra).params;
      type = (c1_type *)0x0;
      if ((fparams->this_type != (c1_type *)0x0) &&
         ((uVar8 = tmpl_type_find_parameter(fparams->this_type,1,0), uVar8 == 0 ||
          (type = tmpl_substitute_type(fparams->this_type,args), type == (c1_type *)0x0)))) {
        type = fparams->this_type;
      }
      pcVar7 = g_arenas[5].cur;
      local_2c = (c1_type_list *)0x0;
      iVar17 = fparams->list->count;
      if (0 < iVar17) {
        g_arenas[5].cur = g_arenas[5].cur + iVar17 * 4 + 8;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        local_30 = (c1_arg_list *)0x0;
        *(int *)pcVar7 = iVar17;
        param_slot = (uint *)fparams->list->types;
        puVar18 = (uint *)(pcVar7 + 8);
        do {
          uVar8 = tmpl_type_find_parameter((c1_type *)*param_slot,1,0);
          if (uVar8 == 0) {
            *puVar18 = *param_slot;
          }
          else {
            pcVar10 = tmpl_substitute_type((c1_type *)*param_slot,args);
            if (pcVar10 == (c1_type *)0x0) {
              *puVar18 = *param_slot;
            }
            else {
              *puVar18 = (uint)pcVar10;
            }
          }
          param_slot = param_slot + 1;
          local_30 = (c1_arg_list *)((int)local_30 + (((ushort)*puVar18 & 0x3ffc) >> 2));
          puVar18 = puVar18 + 1;
          iVar17 = iVar17 + -1;
        } while (0 < iVar17);
        local_2c = type_list_intern((int *)pcVar7,(uint)local_30);
      }
      pcVar7 = g_arenas[5].cur;
      g_arenas[5].cur = g_arenas[5].cur + 0x10;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      *(c1_type **)pcVar7 = fparams->this_type;
      cVar4 = fparams->flags;
      cVar5 = fparams->pad06[0];
      cVar6 = fparams->pad06[1];
      pcVar7[4] = fparams->default_count;
      pcVar7[5] = cVar4;
      pcVar7[6] = cVar5;
      pcVar7[7] = cVar6;
      *(c1_node **)(pcVar7 + 8) = fparams->defaults;
      *(c1_type_list **)(pcVar7 + 0xc) = fparams->list;
      *(c1_type_list **)(pcVar7 + 0xc) = local_2c;
      *(c1_type **)pcVar7 = type;
      pcVar14 = (c1_symbol *)type_function_intern((c1_function_params *)pcVar7);
      if (((pcVar13->extra).cls != pcVar14) &&
         (cVar16.params = type_function_intern((c1_function_params *)pcVar14),
         (pcVar13->extra).cls != cVar16.cls)) {
        local_10.code = pcVar13->code;
        local_10.flags = pcVar13->flags;
        local_10.base = pcVar13->base;
        local_10.debug_index = pcVar13->debug_index;
        local_10.extra.params = cVar16.params;
        pcVar13 = type_intern(&local_10);
      }
      if (pcVar9 == (c1_type *)0x0) {
        return pcVar13;
      }
      if (pcVar13->base == pcVar9) {
        return pcVar13;
      }
      local_20.code = pcVar13->code;
      local_20.flags = pcVar13->flags;
      local_20.extra = pcVar13->extra;
      local_20.debug_index = pcVar13->debug_index;
      local_20.base = pcVar9;
      pcVar13 = type_intern(&local_20);
      return pcVar13;
    case 0x82:
      if (pcVar9 != (c1_type *)0x0) {
        if (type->base == pcVar9) {
          return type;
        }
        local_20.code = type->code;
        local_20.flags = type->flags;
        local_20.extra = type->extra;
        local_20.debug_index = type->debug_index;
        local_20.base = pcVar9;
        pcVar13 = type_intern(&local_20);
        return pcVar13;
      }
      break;
    case 0x83:
      if (pcVar9 != (c1_type *)0x0) {
        if (type->base == pcVar9) {
          return type;
        }
        local_20.code = type->code;
        local_20.flags = type->flags;
        local_20.extra = type->extra;
        local_20.debug_index = type->debug_index;
        local_20.base = pcVar9;
        pcVar13 = type_intern(&local_20);
        return pcVar13;
      }
      break;
    default:
      goto switchD_104b6ab7_caseD_84;
    case 0x8a:
    case 0x8e:
      pcVar14 = (type->extra).cls;
      cVar16.cls = (c1_symbol *)0x0;
      uVar8 = tmpl_type_find_parameter(pcVar14->type,1,0);
      if (((uVar8 != 0) &&
          (pcVar13 = tmpl_substitute_type(pcVar14->type,args), pcVar13 != (c1_type *)0x0)) &&
         ((pcVar13->code & 0x300) != 0)) {
        cVar16 = (c1_type_extra)(pcVar13->extra).cls;
      }
      if (pcVar9 == (c1_type *)0x0) {
        if (cVar16.cls == (c1_symbol *)0x0) {
          return (c1_type *)0x0;
        }
      }
      else {
        if (type->base != pcVar9) {
          local_20.code = type->code;
          local_20.flags = type->flags;
          local_20.extra = type->extra;
          local_20.debug_index = type->debug_index;
          local_20.base = pcVar9;
          type = type_intern(&local_20);
        }
        if (cVar16.cls == (c1_symbol *)0x0) {
          return type;
        }
      }
      if ((type->extra).cls == cVar16.cls) {
        return type;
      }
      local_10.code = type->code;
      local_10.flags = type->flags;
      local_10.base = type->base;
      local_10.debug_index = type->debug_index;
      local_10.extra = cVar16;
      pcVar13 = type_intern(&local_10);
      return pcVar13;
    }
    return (c1_type *)0x0;
  }
switchD_104b6ab7_caseD_84:
  if ((uVar8 >> 9 & 1) == 0) {
    if ((char)uVar8 < '\0') {
      return (c1_type *)0x0;
    }
    if ((uVar8 & 0xfff) != 0x801) {
      return (c1_type *)0x0;
    }
    uVar15 = (uint)*(byte *)&type->extra;
    pcVar19 = args->first;
    while (uVar15 = uVar15 - 1, 0 < (int)uVar15) {
      if (pcVar19 == (c1_arg_item *)0x0) {
        return (c1_type *)0x0;
      }
      pcVar19 = pcVar19->next;
    }
    if (pcVar19 == (c1_arg_item *)0x0) {
      return (c1_type *)0x0;
    }
    if ((pcVar19->kind & 3) == 1) {
      return (c1_type *)0x0;
    }
    return (pcVar19->value).type;
  }
  pcVar14 = (type->extra).cls;
  if ((((pcVar14->detail).cls)->flags3f & 0x80) == 0) {
    return (c1_type *)0x0;
  }
  piVar11 = symtab_15f4_lookup(pcVar14);
  local_30 = (c1_arg_list *)g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0xc;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (local_30 == (c1_arg_list *)0x0) {
    local_30 = (c1_arg_list *)0x0;
  }
  else {
    *(c1_u8 *)((int)local_30 + 0) = '\0';
    *(c1_u8 *)((int)local_30 + 1) = '\0';
    *(c1_u8 *)((int)local_30 + 2) = '\0';
    *(c1_u8 *)((int)local_30 + 3) = '\0';
    *(c1_u8 *)((int)local_30 + 4) = '\0';
    *(c1_u8 *)((int)local_30 + 5) = '\0';
    *(c1_u8 *)((int)local_30 + 6) = '\0';
    *(c1_u8 *)((int)local_30 + 7) = '\0';
    pcVar19 = (c1_arg_item *)*piVar11;
    if ((*(byte *)(piVar11 + 2) & 1) != 0) {
      *(byte *)((int)local_30 + 8) = *(byte *)((int)local_30 + 8) | 1;
    }
    do {
      if ((pcVar19->kind & 3) == 0) {
        pcVar12 = arena_alloc(g_arenas,0x14);
        if (pcVar12 == (c1_arg_item *)0x0) {
LAB_104b6fc4:
          pcVar12 = (c1_arg_item *)0x0;
        }
        else {
          tmpl_argument_copy_base(pcVar12,pcVar19);
          cVar1 = pcVar19->value;
          pcVar12->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
          pcVar12->value = cVar1;
        }
      }
      else {
        pcVar12 = arena_alloc(g_arenas,0x14);
        if (pcVar12 == (c1_arg_item *)0x0) goto LAB_104b6fc4;
        pcVar12 = tmpl_argument_copy_nontype(pcVar12,pcVar19);
      }
      if (*(int *)local_30 == 0) {
        local_30->first = pcVar12;
      }
      else {
        *(c1_arg_item **)(*(int *)((int)local_30 + 4) + 4) = pcVar12;
        pcVar12->prev = *(c1_arg_item **)((int)local_30 + 4);
      }
      *(c1_arg_item **)((int)local_30 + 4) = pcVar12;
      pcVar19 = pcVar19->next;
    } while (pcVar19 != (c1_arg_item *)0x0);
  }
  iVar17 = *piVar11;
  bVar2 = false;
  pcVar19 = local_30->first;
  bVar3 = false;
  do {
    if ((*(byte *)(iVar17 + 0xc) & 3) != 0) {
      return (c1_type *)0x0;
    }
    pcVar13 = *(c1_type **)(iVar17 + 0x10);
    uVar8 = tmpl_type_find_parameter(pcVar13,1,0);
    if (uVar8 != 0) {
      pcVar13 = tmpl_substitute_type(pcVar13,args);
      if (pcVar13 == (c1_type *)0x0) {
        bVar3 = true;
      }
      else {
        (pcVar19->value).type = pcVar13;
        bVar2 = true;
      }
    }
    iVar17 = *(int *)(iVar17 + 4);
    pcVar19 = pcVar19->next;
  } while (iVar17 != 0);
  if (!bVar2) {
    return (c1_type *)0x0;
  }
  if (bVar3) {
    return (c1_type *)0x0;
  }
  pcVar14 = tmpl_template_of_instance(pcVar14);
  pcVar14 = tmpl_parse_arguments(pcVar14,local_30,(char)iVar17);
  return pcVar14->type;
}


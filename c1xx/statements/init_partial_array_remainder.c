uint __cdecl init_partial_array_remainder(void)

{
  char cVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  byte *pbVar4;
  c1_type *pcVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  c1_type *pcVar9;
  c1_sym_link *pcVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  c1_u32 *member;
  short n;
  c1_symbol *local_c;
  int member_cursor;
  c1_sym_link *local_4;
  
  pcVar2 = g_init_level->sym;
  if (g_init_brace_depth < 0) {
    return 0;
  }
  pcVar9 = pcVar2->type;
  bVar6 = (byte)pcVar9->code;
  pcVar5 = pcVar9;
  if ((bVar6 & 0x8f) == 0x83) {
    pcVar3 = (pcVar9->extra).cls;
    if (pcVar3 == (c1_symbol *)0x0) {
      return 0;
    }
    iVar7 = type_size_derived(pcVar9);
    uVar13 = iVar7 * ((int)pcVar3 - g_init_level->count);
    if (uVar13 == 0) {
      return 0;
    }
    uVar8 = type_classify_class_form(pcVar9,(int *)&local_c);
    if (((uVar8 & 3) == 0) || ((local_c->flags1 & 0x10) != 0x10)) {
      pcVar9 = type_skip_arrays_and_functions(pcVar9);
      if (((byte)pcVar9->flags >> 5 & 1) == 0) {
        return uVar13;
      }
      bVar6 = pcVar2->storage & 7;
      if (bVar6 < 4) {
        return uVar13;
      }
      if (6 < bVar6) {
        return uVar13;
      }
      if (g_init_remaining_error != 0) {
        return uVar13;
      }
      n = 0x93;
    }
    else {
      if ((((local_c->detail).cls)->implicit_state41 & 2) != 0) {
        return uVar13;
      }
      tmpl_instantiate_if_incomplete(local_c);
      if (((((local_c->detail).cls)->implicit_state41 & 2) != 0) ||
         ((((local_c->detail).cls)->implicit_state43 & 2) != 0)) {
        if (g_init_remaining_count == 0) {
          g_init_remaining_offset = g_init_offset;
        }
        cVar1 = (char)pcVar9->code;
        while (cVar1 < '\0') {
          pcVar9 = pcVar9->base;
          cVar1 = (char)pcVar9->code;
        }
        uVar8 = type_size_scalar(pcVar9);
        g_init_remaining_count = g_init_remaining_count + uVar13 / uVar8;
        return uVar13;
      }
      if (g_init_remaining_error != 0) {
        return uVar13;
      }
      n = 0x49;
    }
    diag_error(n,g_init_symbol);
    g_init_remaining_error = 1;
    return uVar13;
  }
  while ((char)bVar6 < '\0') {
    bVar6 = (byte)pcVar5->base->code;
    pcVar5 = pcVar5->base;
  }
  if ((pcVar5->code & 0x200) == 0) {
    uVar13 = type_size(pcVar9);
    return uVar13;
  }
  if (g_init_bitfield_unit_open != 0) {
    g_constant_value = g_init_bitfield_value;
    g_constant_value_high = g_init_bitfield_value_high;
    init_finish_array(((pcVar2->x28).enumerators)->compare - 8);
  }
  iVar7 = 0;
  local_c = (c1_symbol *)0x0;
  if ((pcVar2->x28).members == (c1_sym_list *)0x0) {
    pcVar10 = (c1_sym_link *)0x0;
  }
  else {
    pcVar10 = ((pcVar2->x28).members)->head;
  }
  member_cursor._0_1_ = pcVar10 != (c1_sym_link *)0x0;
  while (pcVar10 != (c1_sym_link *)0x0) {
    member = &pcVar10[-1].position;
    bVar6 = (byte)pcVar10[-1].position & 0x1f;
    local_4 = pcVar10;
    if (bVar6 == 0) {
LAB_10476459:
      if ((iVar7 < 1) &&
         ((pcVar10->name == g_name_alignment_member ||
          (iVar11 = member_is_copied_data((c1_symbol *)member), (char)iVar11 != '\0')))) {
        if ((*member & 0x1f) == 2) {
          for (piVar12 = init_find_member_for_offset
                                   ((int)pcVar10[1].type,(int *)pcVar10->next,
                                    (c1_member_walk *)&member_cursor); piVar12 != (int *)0x0;
              piVar12 = init_find_member_for_offset
                                  ((int)local_4[1].type,(int *)piVar12[1],
                                   (c1_member_walk *)&member_cursor)) {
            if (local_4 != (c1_sym_link *)0x0) {
              local_4 = local_4->next;
            }
            member = &local_4[-1].position;
          }
          if (g_init_bitfield_unit_open == 0) {
            pbVar4 = (byte *)member[5];
            bVar6 = *pbVar4;
            while ((char)bVar6 < '\0') {
              pbVar4 = *(byte **)(pbVar4 + 4);
              bVar6 = *pbVar4;
            }
            pcVar9 = (c1_type *)(int)(char)(&g_type_rank_table)[*pbVar4 & 0xf];
          }
          else {
            g_init_bitfield_unit_open = 0;
            pcVar9 = (c1_type *)0x0;
          }
        }
        else if (pcVar10->name == g_name_alignment_member) {
          pcVar9 = pcVar10[1].type.type;
        }
        else {
          pcVar9 = (c1_type *)type_size((pcVar10->type).type);
        }
LAB_1047640e:
        local_c = (c1_symbol *)((int)&pcVar9->code + (int)&local_c->kind);
      }
    }
    else if (((bVar6 < 0xf) && (bVar6 != 5)) && ((*(byte *)((int)&pcVar10[-1].type + 1) & 8) != 0))
    {
      iVar7 = iVar7 + 1;
      if (iVar7 < 2) {
        pcVar9 = (c1_type *)type_size((pcVar10->type).type);
        goto LAB_1047640e;
      }
    }
    else {
      if (((bVar6 == 0) || (0xe < bVar6)) ||
         ((bVar6 == 5 || ((*(byte *)((int)&pcVar10[-1].type + 1) & 0x10) == 0)))) goto LAB_10476459;
      iVar7 = iVar7 + -1;
      if (iVar7 < 0) break;
    }
    if (local_4 == (c1_sym_link *)0x0) break;
    pcVar10 = local_4->next;
  }
  (pcVar2->x28).members = (c1_sym_list *)0x0;
  g_init_bitfield_unit_open = 0;
  return (uint)local_c;
}


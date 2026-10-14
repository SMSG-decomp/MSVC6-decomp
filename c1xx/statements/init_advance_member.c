int __cdecl init_advance_member(void)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int *rec;
  ushort uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  int *rec_2;
  
  while( true ) {
    if (g_init_brace_depth < 0) {
      return 0;
    }
    if ((g_init_level->flags & 0x20) != 0) {
      if (g_init_brace_depth < 0) {
        return 1;
      }
      g_init_brace_depth = g_init_brace_depth + -1;
      g_init_level = g_init_levels + g_init_brace_depth;
      return 1;
    }
    if ((g_init_level->flags & 1) != 0) {
      g_init_level->flags = g_init_level->flags | 8;
      iVar7 = init_never_too_many();
      return iVar7;
    }
    if (g_init_brace_depth < 0) break;
    g_init_brace_depth = g_init_brace_depth + -1;
    g_init_level = g_init_levels + g_init_brace_depth;
    if (g_init_brace_depth < 0) {
      return 0;
    }
    pcVar8 = g_init_level->sym;
    if ((pcVar8->flags5 & 4) == 0) {
      pcVar2 = pcVar8->type;
      cVar1 = (char)pcVar2->code;
      while (cVar1 < '\0') {
        pcVar2 = pcVar2->base;
        cVar1 = (char)pcVar2->code;
      }
      uVar6 = pcVar2->code & 0xfff;
      if (uVar6 < 0x201) {
        return 1;
      }
      if (uVar6 < 0x203) {
        if ((g_init_levels[g_init_brace_depth].flags & 0x80) == 0) {
          if ((g_init_levels[g_init_brace_depth].flags & 1) != 0) {
            g_init_levels[g_init_brace_depth].flags = g_init_levels[g_init_brace_depth].flags | 2;
            return 1;
          }
        }
        else {
          piVar4 = (int *)((pcVar8->x28).enumerators)->compare;
          pcVar8 = (c1_symbol *)(piVar4 + -2);
          bVar3 = *(byte *)(piVar4 + -2) & 0x1f;
          if ((((bVar3 != 0) && (bVar3 < 0xf)) && (bVar3 != 5)) &&
             ((*(byte *)((int)piVar4 + -3) & 8) != 0)) {
            iVar7 = 1;
            do {
              piVar4 = (int *)piVar4[1];
              pcVar8 = (c1_symbol *)(piVar4 + -2);
              bVar3 = *(byte *)(piVar4 + -2) & 0x1f;
              if (((bVar3 != 0) && (bVar3 < 0xf)) &&
                 ((bVar3 != 5 && ((void *)*piVar4 == g_name_alignment_member)))) {
                if ((*(byte *)((int)piVar4 + -3) & 8) == 0) {
                  if ((*(byte *)((int)piVar4 + -3) & 0x10) != 0) {
                    iVar7 = iVar7 + -1;
                  }
                }
                else {
                  iVar7 = iVar7 + 1;
                }
              }
            } while (iVar7 != 0);
          }
          piVar4 = init_next_member_to_initialize(pcVar8,(int *)piVar4[1]);
          if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0x8)) {
            if ((g_init_bitfield_unit_open != 0) && (g_init_bitfield_unit_offset != piVar4[7])) {
              g_constant_value = g_init_bitfield_value;
              g_constant_value_high = g_init_bitfield_value_high;
              init_finish_array((int)pcVar8);
              g_init_bitfield_unit_open = 0;
            }
            if ((g_init_level->sym->x28).members == (c1_sym_list *)0x0) {
              rec = arena_alloc(g_arenas + 1,0xc);
              if (rec == (int *)0x0) {
                rec = (int *)0x0;
              }
              else {
                *rec = 1;
                rec[1] = 0;
                rec[2] = 0;
              }
              (g_init_level->sym->x28).members = (c1_sym_list *)rec;
            }
            rec_2 = (int *)(g_init_level->sym->x28).members;
            rec_2[2] = (int)piVar4;
            rec_2[1] = (int)piVar4;
            return 1;
          }
          if (g_init_bitfield_unit_open != 0) {
            g_constant_value = g_init_bitfield_value;
            g_constant_value_high = g_init_bitfield_value_high;
            init_finish_array((int)pcVar8);
            g_init_bitfield_unit_open = 0;
          }
        }
      }
      else {
        if (uVar6 != 0x203) {
          return 1;
        }
        if (g_init_bitfield_unit_open != 0) {
          g_constant_value = g_init_bitfield_value;
          g_constant_value_high = g_init_bitfield_value_high;
          init_finish_array(((g_init_level->sym->x28).enumerators)->compare - 8);
          g_init_bitfield_unit_open = 0;
        }
        pcVar2 = g_init_level->sym->type;
        iVar7 = type_size((((((pcVar2->extra).cls)->x28).members)->head->type).type);
        iVar5 = type_size(pcVar2);
        g_constant_value = iVar5 - iVar7;
        g_constant_value_high = 0;
        if (g_constant_value != 0) {
          init_emit_data((c1_symbol *)0x0);
        }
        if (-1 < g_init_brace_depth) {
          g_init_brace_depth = g_init_brace_depth + -1;
          g_init_level = g_init_levels + g_init_brace_depth;
        }
        if ((g_init_level->flags & 1) != 0) {
          iVar7 = init_level_mark_complete_tail((byte *)g_init_level,1);
          return iVar7;
        }
      }
    }
    else {
      if ((g_init_levels[g_init_brace_depth].string_seen != '\0') && (g_init_too_many_reported == 0)
         ) {
        g_init_too_many_reported = 1;
        diag_error(0x4e);
      }
      g_init_level->count = g_init_level->count + 1;
      pcVar2 = g_init_level->sym->type;
      if (g_init_level->count != *(int *)(((uint)pcVar2 & -(uint)((pcVar2->code & 0x80) != 0)) + 8))
      {
        return 1;
      }
      g_init_level->flags = g_init_level->flags | 2;
      if ((g_init_level->flags & 1) != 0) {
        return 1;
      }
    }
  }
  return 0;
}


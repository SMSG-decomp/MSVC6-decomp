int __cdecl init_advance_member(void)

{
  char cVar1;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  void *pvVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  uint *record;
  ushort uVar8;
  int iVar9;
  int *sym;
  
joined_r0x106212ce:
  do {
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
        iVar9 = init_advance_member_fragment();
        return iVar9;
      }
      if (g_init_brace_depth < 0) {
        return 0;
      }
      g_init_brace_depth = g_init_brace_depth + -1;
      g_init_level = g_init_levels + g_init_brace_depth;
      if (g_init_brace_depth < 0) {
        return 0;
      }
      pcVar2 = g_init_level->cursor;
      if ((pcVar2->flags4 & 4) == 0) break;
      if ((g_init_levels[g_init_brace_depth].from_string != '\0') && (g_init_too_many_reported == 0)
         ) {
        g_init_too_many_reported = 1;
        diag_error(0x4e);
      }
      g_init_level->count = g_init_level->count + 1;
      pcVar3 = g_init_level->cursor->type;
      if (g_init_level->count !=
          *(c1_u32 *)(((uint)pcVar3 & -(uint)((pcVar3->code & 0x80) != 0)) + 8)) {
        return 1;
      }
      g_init_level->flags = g_init_level->flags | 2;
      if ((g_init_level->flags & 1) != 0) {
        return 1;
      }
    }
    pcVar3 = pcVar2->type;
    cVar1 = (char)pcVar3->code;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    uVar8 = pcVar3->code & 0xfff;
    if (uVar8 < 0x201) {
      return 1;
    }
    if (uVar8 < 0x203) {
      bVar5 = g_init_levels[g_init_brace_depth].flags;
      if ((bVar5 & 0x80) != 0) {
        piVar6 = *(int **)((int)pcVar2->tag_members + 4);
        sym = piVar6 + -2;
        bVar5 = *(byte *)(piVar6 + -2) & 0x1f;
        if ((((bVar5 != 0) && (bVar5 < 0xf)) && (bVar5 != 5)) && ((*(byte *)(piVar6 + -1) & 8) != 0)
           ) {
          iVar9 = 1;
          do {
            piVar6 = (int *)piVar6[1];
            sym = piVar6 + -2;
            bVar5 = *(byte *)(piVar6 + -2) & 0x1f;
            if (((bVar5 != 0) && (bVar5 < 0xf)) &&
               ((bVar5 != 5 && ((void *)*piVar6 == g_name_alignment_member)))) {
              if ((*(byte *)(piVar6 + -1) & 8) == 0) {
                if ((*(byte *)(piVar6 + -1) & 0x10) != 0) {
                  iVar9 = iVar9 + -1;
                }
              }
              else {
                iVar9 = iVar9 + 1;
              }
            }
          } while (iVar9 != 0);
        }
        piVar6 = init_skip_padding_members((int)sym,(int *)piVar6[1]);
        if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0x8)) {
          if ((g_init_bitfield_unit_open != 0) && (g_init_bitfield_unit != piVar6[7])) {
            g_constant_value = g_init_bitfield_value;
            g_constant_value_high = g_init_bitfield_value_high;
            init_finish_array((int)sym);
            g_init_bitfield_unit_open = 0;
          }
          if (g_init_level->cursor->tag_members == (void *)0x0) {
            record = arena_alloc(g_arenas + 1,0xc);
            if (record == (uint *)0x0) {
              record = (uint *)0x0;
            }
            else {
              *record = 1;
              record[1] = 0;
              record[2] = 0;
            }
            g_init_level->cursor->tag_members = record;
          }
          pvVar4 = g_init_level->cursor->tag_members;
          *(int **)((int)pvVar4 + 8) = piVar6;
          *(int **)((int)pvVar4 + 4) = piVar6;
          return 1;
        }
        if (g_init_bitfield_unit_open != 0) {
          g_constant_value = g_init_bitfield_value;
          g_constant_value_high = g_init_bitfield_value_high;
          init_finish_array((int)sym);
          g_init_bitfield_unit_open = 0;
        }
        goto joined_r0x106212ce;
      }
    }
    else {
      if (uVar8 != 0x203) {
        return 1;
      }
      if (g_init_bitfield_unit_open != 0) {
        g_constant_value = g_init_bitfield_value;
        g_constant_value_high = g_init_bitfield_value_high;
        init_finish_array(*(int *)((int)g_init_level->cursor->tag_members + 4) + -8);
        g_init_bitfield_unit_open = 0;
      }
      pcVar3 = g_init_level->cursor->type;
      iVar9 = type_size(*(c1_type **)(*(int *)((int)((pcVar3->extra).sym)->tag_members + 4) + 0xc));
      iVar7 = type_size(pcVar3);
      g_constant_value = iVar7 - iVar9;
      g_constant_value_high = 0;
      if (g_constant_value != 0) {
        init_emit_data(0);
      }
      if (-1 < g_init_brace_depth) {
        g_init_brace_depth = g_init_brace_depth + -1;
        g_init_level = g_init_levels + g_init_brace_depth;
      }
      bVar5 = g_init_level->flags;
    }
    if ((bVar5 & 1) != 0) {
      g_init_level->flags = g_init_level->flags | 2;
      return 1;
    }
  } while( true );
}


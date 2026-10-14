uint __cdecl init_descend_to_member(int value)

{
  c1_symbol *sym;
  byte bVar1;
  int iVar2;
  c1_sym_link *pcVar3;
  c1_symbol *pcVar4;
  c1_sym_list *pcVar5;
  
  if ((-1 < g_init_brace_depth) && ((g_init_level->flags & 0x20) == 0)) {
    pcVar4 = g_init_level->sym;
    iVar2 = sym_has_scalar_type(pcVar4);
    if (iVar2 != 0) {
      return ((byte)~g_init_level->flags & 8) >> 3;
    }
    iVar2 = init_is_char_array_string_init(pcVar4,(c1_node *)value);
    if (iVar2 != 0) {
      return 1;
    }
    bVar1 = g_init_level->flags;
    if ((bVar1 & 2) == 0) {
      if ((pcVar4->flags5 & 4) != 0) {
        if ((((pcVar4->flags5 & 1) == 0) || ((g_init_level->type->code & 0x8f) != 0x83)) ||
           ((g_init_level->type->extra).cls != (c1_symbol *)0x0)) {
          bVar1 = 0;
        }
        else {
          bVar1 = 1;
        }
        init_push_brace_level(pcVar4);
        pcVar4 = g_init_level->sym;
        g_init_level->type = pcVar4->type->base;
        PTR_104e0a40 = (c1_type *)(-(uint)bVar1 & (uint)g_init_level->type);
        pcVar4->type = g_init_level->type;
        if ((pcVar4->type->code & 0x8f) == 0x83) {
          pcVar4->flags5 = pcVar4->flags5 | 4;
          return 1;
        }
        pcVar4->flags5 = pcVar4->flags5 & 0xfb;
        return 1;
      }
      if ((pcVar4->type->code & 0x200) != 0) {
        sym = (pcVar4->type->extra).cls;
        if ((bVar1 & 0x80) == 0) {
          if ((sym->flags2 & 4) == 0) {
            if (-1 < g_init_brace_depth) {
              g_init_brace_depth = g_init_brace_depth + -1;
              g_init_level = g_init_levels + g_init_brace_depth;
              if (-1 < g_init_brace_depth) {
                diag_error(0x4f,g_init_level->sym,pcVar4->type,pcVar4);
              }
            }
            g_init_brace_depth = -1;
            return 0;
          }
          if ((((sym->detail).cls)->layout_flags3c & 1) == 0) {
            if (value != 0) {
              g_init_level->flags = bVar1 | 0x10;
              return 1;
            }
            diag_error(0x228,pcVar4);
            g_init_level->flags = g_init_level->flags | 0x20;
            return 0;
          }
          init_push_brace_level(sym);
          g_init_level->flags = g_init_level->flags | 0x80;
          bVar1 = pcVar4->kind & 0x1f;
          if (((bVar1 == 0) || (0xe < bVar1)) ||
             ((bVar1 == 5 ||
              ((pcVar4->name != g_name_alignment_member || ((pcVar4->flags5 & 8) == 0)))))) {
            pcVar4 = g_init_level->sym;
          }
        }
        bVar1 = pcVar4->kind & 0x1f;
        if ((((bVar1 == 0) || (0xe < bVar1)) || (bVar1 == 5)) ||
           ((pcVar4->name != g_name_alignment_member || ((pcVar4->flags5 & 8) == 0)))) {
          pcVar4 = (c1_symbol *)((pcVar4->x28).members)->head;
        }
        else {
          pcVar4 = pcVar4->next;
        }
        pcVar3 = (c1_sym_link *)init_next_member_to_initialize((c1_symbol *)0x0,(int *)pcVar4);
        pcVar5 = (c1_sym_list *)g_arenas[1].cur;
        if ((pcVar3 != (c1_sym_link *)0x0) && (&pcVar3[-1].position != (c1_u32 *)0x0)) {
          if ((g_init_level->sym->x28).members == (c1_sym_list *)0x0) {
            g_arenas[1].cur = g_arenas[1].cur + 0xc;
            if (g_arenas[1].end < g_arenas[1].cur) {
              arena_grow(g_arenas + 1);
            }
            if (pcVar5 == (c1_sym_list *)0x0) {
              pcVar5 = (c1_sym_list *)0x0;
            }
            else {
              *(c1_u8 *)((int)pcVar5 + 0) = '\x01';
              *(c1_u8 *)((int)pcVar5 + 1) = '\0';
              *(c1_u8 *)((int)pcVar5 + 2) = '\0';
              *(c1_u8 *)((int)pcVar5 + 3) = '\0';
              *(c1_u8 *)((int)pcVar5 + 4) = '\0';
              *(c1_u8 *)((int)pcVar5 + 5) = '\0';
              *(c1_u8 *)((int)pcVar5 + 6) = '\0';
              *(c1_u8 *)((int)pcVar5 + 7) = '\0';
              *(c1_u8 *)((int)pcVar5 + 8) = '\0';
              *(c1_u8 *)((int)pcVar5 + 9) = '\0';
              *(c1_u8 *)((int)pcVar5 + 10) = '\0';
              *(c1_u8 *)((int)pcVar5 + 0xb) = '\0';
            }
            (g_init_level->sym->x28).members = pcVar5;
          }
          pcVar5 = (g_init_level->sym->x28).members;
          pcVar5->tail = pcVar3;
          pcVar5->head = pcVar3;
          init_push_brace_level((c1_symbol *)&pcVar3[-1].position);
          pcVar4 = g_init_level->sym;
          iVar2 = init_is_char_array_string_init(pcVar4,(c1_node *)value);
          if ((iVar2 != 0) && ((pcVar4->flags5 & 1) != 0)) {
            PTR_104e0a40 = pcVar4->type->base;
          }
          return 1;
        }
        g_init_brace_depth = g_init_brace_depth + -1;
        g_init_level->flags = g_init_level->flags | 0x50;
        return 1;
      }
      g_init_level->flags = bVar1 | 0x20;
    }
  }
  return 0;
}


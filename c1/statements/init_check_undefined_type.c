int __cdecl init_check_undefined_type(c1_node *element)

{
  c1_symbol *sym;
  void *pvVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  c1_symbol *pcVar5;
  c1_sym_link *member;
  uchar *puVar6;
  
  if ((-1 < g_init_brace_depth) && ((g_init_level->flags & 0x20) == 0)) {
    pcVar5 = g_init_level->cursor;
    iVar3 = sym_has_scalar_type(pcVar5);
    if (iVar3 != 0) {
      return ((byte)~g_init_level->flags & 8) >> 3;
    }
    iVar3 = init_is_char_array_string_init(pcVar5,element);
    if (iVar3 != 0) {
      return 1;
    }
    bVar2 = g_init_level->flags;
    if ((bVar2 & 2) == 0) {
      if ((pcVar5->flags4 & 4) != 0) {
        if ((((pcVar5->flags4 & 1) == 0) || ((g_init_level->type->code & 0x8f) != 0x83)) ||
           ((g_init_level->type->extra).sym != (c1_symbol *)0x0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        init_push_brace_level(pcVar5);
        pcVar5 = g_init_level->cursor;
        g_init_level->type = pcVar5->type->base;
        PTR_1066b8ec = (c1_type *)(-(uint)bVar2 & (uint)g_init_level->type);
        pcVar5->type = g_init_level->type;
        if ((pcVar5->type->code & 0x8f) == 0x83) {
          pcVar5->flags4 = pcVar5->flags4 | 4;
          return 1;
        }
        pcVar5->flags4 = pcVar5->flags4 & 0xfb;
        return 1;
      }
      if ((pcVar5->type->code & 0x200) != 0) {
        sym = (pcVar5->type->extra).sym;
        if ((bVar2 & 0x80) == 0) {
          if ((sym->flags1 & 1) == 0) {
            if (-1 < g_init_brace_depth) {
              g_init_brace_depth = g_init_brace_depth + -1;
              g_init_level = g_init_levels + g_init_brace_depth;
              if (-1 < g_init_brace_depth) {
                diag_error(0x4f,g_init_level->cursor,pcVar5->type,pcVar5);
              }
            }
            g_init_brace_depth = -1;
            return 0;
          }
          init_push_brace_level(sym);
          g_init_level->flags = g_init_level->flags | 0x80;
          bVar2 = pcVar5->kind & 0x1f;
          if (((bVar2 == 0) || (0xe < bVar2)) ||
             ((bVar2 == 5 ||
              ((pcVar5->name != g_name_alignment_member || ((pcVar5->flags4 & 8) == 0)))))) {
            pcVar5 = g_init_level->cursor;
          }
        }
        bVar2 = pcVar5->kind & 0x1f;
        if ((((bVar2 == 0) || (0xe < bVar2)) || (bVar2 == 5)) ||
           ((pcVar5->name != g_name_alignment_member || ((pcVar5->flags4 & 8) == 0)))) {
          member = *(c1_sym_link **)((int)pcVar5->tag_members + 4);
        }
        else {
          member = pcVar5->next;
        }
        piVar4 = init_skip_padding_members(0,(int *)member);
        puVar6 = g_arenas[1].cur;
        if ((piVar4 != (int *)0x0) && ((c1_symbol *)(piVar4 + -2) != (c1_symbol *)0x0)) {
          if (g_init_level->cursor->tag_members == (void *)0x0) {
            g_arenas[1].cur = g_arenas[1].cur + 0xc;
            if (g_arenas[1].end < g_arenas[1].cur) {
              arena_grow(g_arenas + 1);
            }
            if (puVar6 == (uchar *)0x0) {
              puVar6 = (uchar *)0x0;
            }
            else {
              puVar6[0] = '\x01';
              puVar6[1] = '\0';
              puVar6[2] = '\0';
              puVar6[3] = '\0';
              puVar6[4] = '\0';
              puVar6[5] = '\0';
              puVar6[6] = '\0';
              puVar6[7] = '\0';
              puVar6[8] = '\0';
              puVar6[9] = '\0';
              puVar6[10] = '\0';
              puVar6[0xb] = '\0';
            }
            g_init_level->cursor->tag_members = puVar6;
          }
          pvVar1 = g_init_level->cursor->tag_members;
          *(int **)((int)pvVar1 + 8) = piVar4;
          *(int **)((int)pvVar1 + 4) = piVar4;
          init_push_brace_level((c1_symbol *)(piVar4 + -2));
          pcVar5 = g_init_level->cursor;
          iVar3 = init_is_char_array_string_init(pcVar5,element);
          if ((iVar3 != 0) && ((pcVar5->flags4 & 1) != 0)) {
            PTR_1066b8ec = pcVar5->type->base;
          }
          return 1;
        }
        g_init_brace_depth = g_init_brace_depth + -1;
        g_init_level->flags = g_init_level->flags | 0x50;
        return 1;
      }
      g_init_level->flags = bVar2 | 0x20;
    }
  }
  return 0;
}


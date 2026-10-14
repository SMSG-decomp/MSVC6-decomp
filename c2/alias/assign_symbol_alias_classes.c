uint32_t __fastcall assign_symbol_alias_classes(int oa,int overflow)

{
  uint8_t uVar1;
  byte bVar2;
  c2_fe_symbol *pcVar3;
  c2_bitset *bs;
  c2_symbol_cell *pcVar4;
  c2_alias_sym_info *pcVar5;
  c2_alias_ref *pcVar6;
  c2_symbol *pcVar7;
  uint32_t uVar8;
  uint32_t n;
  c2_symbol *s;
  uint32_t local_14;
  c2_symbol_u34 local_10;
  c2_symbol_chunk *local_c;
  
  n = 1;
  local_14 = 0;
  local_10.refs = 0;
  g_alias_special_symbol = arena_alloc(1,0x54);
  g_alias_special_symbol->cls = '\f';
  g_alias_scope_symbols = arena_alloc(1,0x54);
  g_alias_scope_symbols->cls = '\f';
  g_aliased_syms = bitset_new(1);
  uVar8 = 1;
  g_alias_symbol_number_count = 1;
  local_c = g_symbol_chunks;
  if (g_symbol_chunks == (c2_symbol_chunk *)0x0) {
    g_alias_symbol_number_end = 1;
    return 1;
  }
  do {
    s = local_c->syms;
    if (s < local_c->cursor) {
      do {
        uVar1 = s->cls;
        if (uVar1 != '\x10') {
          bVar2 = s->flags5;
          (s->u34).refs = 0;
          if ((bVar2 & 2) == 0) {
            if (((uVar1 == '\x04') || (uVar1 == '\x05')) ||
               ((uVar1 == '\x03' && (s->def == (c2_tuple *)0x0)))) {
              if (((uVar1 != '\x03') || (s->def != (c2_tuple *)0x0)) && (s->storage == s)) {
                (s->u34).refs = uVar8;
                (s->fe->u3e).alias_class = (uint16_t)g_alias_class_count;
                g_alias_class_count = g_alias_class_count + 1;
                g_alias_symbol_number_count = uVar8 + 1;
              }
              if (overflow == 0) {
                s->flags5 = bVar2 | 8;
                pcVar5 = arena_alloc(4,0x14);
                (s->u30).alias_info = pcVar5;
                bs = bitset_new(6);
                pcVar5->ref_nodes = bs;
                bitset_set(bs,n);
                pcVar5->node = n;
                n = n + 1;
              }
              else {
                (s->u30).order_prev = (c2_symbol *)0x0;
              }
            }
            else {
              (s->u30).order_prev = (c2_symbol *)0x0;
              if ((s->storage == s) && ((uVar1 == '\a' || (uVar1 == '\b')))) {
                if ((bVar2 & 4) == 0) {
                  pcVar4 = symbol_list_add_unique((g_alias_special_symbol->u30).members,s,1);
                  uVar8 = s->id;
                  (g_alias_special_symbol->u30).members = pcVar4;
                  bitset_set(g_aliased_syms,uVar8);
                }
                if (oa != 0) {
                  pcVar5 = arena_alloc(4,0x14);
                  (s->u30).alias_info = pcVar5;
                  pcVar6 = arena_alloc(4,0x14);
                  pcVar5->points_to = pcVar6;
                }
                pcVar3 = s->fe;
                if (pcVar3->name == (char *)0x0) {
                  if (local_14 == 0) {
                    local_14 = g_alias_class_count;
                    g_alias_class_count = g_alias_class_count + 1;
                    local_10.refs = g_alias_symbol_number_count;
                    g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
                  }
                  (pcVar3->u3e).alias_class = (uint16_t)local_14;
                  s->u34 = local_10;
                }
                else {
                  (pcVar3->u3e).alias_class = (uint16_t)g_alias_class_count;
                  g_alias_class_count = g_alias_class_count + 1;
                  (s->u34).refs = g_alias_symbol_number_count;
                  g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
                }
              }
            }
          }
          else {
            (s->u30).order_prev = (c2_symbol *)0x0;
            if (((s->storage == s) && (uVar1 != '\n')) && (uVar1 != '\v')) {
              bitset_set(g_aliased_syms,s->id);
              pcVar3 = s->fe;
              if (((pcVar3->name == (char *)0x0) && (uVar1 != '\x04')) && (uVar1 != '\x05')) {
                if (local_14 == 0) {
                  local_14 = g_alias_class_count;
                  g_alias_class_count = g_alias_class_count + 1;
                  local_10.refs = g_alias_symbol_number_count;
                  g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
                }
                (pcVar3->u3e).alias_class = (uint16_t)local_14;
                s->u34 = local_10;
              }
              else {
                (pcVar3->u3e).alias_class = (uint16_t)g_alias_class_count;
                g_alias_class_count = g_alias_class_count + 1;
                (s->u34).refs = g_alias_symbol_number_count;
                g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
              }
              if (oa != 0) {
                pcVar5 = arena_alloc(4,0x14);
                (s->u30).alias_info = pcVar5;
                pcVar6 = arena_alloc(4,0x14);
                pcVar5->points_to = pcVar6;
              }
              if (uVar1 == '\x05') {
                pcVar4 = symbol_list_add_unique((g_alias_scope_symbols->u30).members,s,1);
                pcVar7 = g_alias_scope_symbols;
              }
              else {
                if ((uVar1 != '\a') && (uVar1 != '\b')) goto LAB_1072e3b3;
                pcVar4 = symbol_list_add_unique((g_alias_special_symbol->u30).members,s,1);
                pcVar7 = g_alias_special_symbol;
              }
              (pcVar7->u30).members = pcVar4;
            }
          }
        }
LAB_1072e3b3:
        s = s + 1;
        uVar8 = g_alias_symbol_number_count;
      } while (s < local_c->cursor);
    }
    local_c = local_c->next;
    if (local_c == (c2_symbol_chunk *)0x0) {
      g_alias_symbol_number_end = uVar8;
      return n;
    }
  } while( true );
}


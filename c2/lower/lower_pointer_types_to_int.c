void __fastcall lower_pointer_types_to_int(c2_tuple *first)

{
  uint32_t uVar1;
  c2_tuple_u14 cVar2;
  void *pvVar3;
  c2_tuple *t;
  ushort uVar4;
  int iVar5;
  c2_symbol *sym;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  uint16_t type;
  uint16_t uVar9;
  c2_operand *local_c;
  c2_tuple *local_8;
  c2_operand *local_4;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_cursor;
  
joined_r0x1072cfb7:
  do {
    while( true ) {
      t = first;
      if (t == (c2_tuple *)0x0) {
        chunk = g_symbol_chunks;
        if (g_lower_ptr_types_depth == 0) {
          for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
            chunk_cursor = chunk->cursor;
            for (sym = chunk->syms; sym < chunk_cursor; sym = sym + 1) {
              if ((sym->cls != '\x10') && ((sym->type & 0xf000) == 0x3000)) {
                sym->type = 0x2004;
              }
            }
          }
        }
        return;
      }
      local_8 = t->next;
      if ((t->flags & 1) != 0) break;
      first = local_8;
      if (t->kind == '\x17') {
        for (pcVar7 = t->src; first = local_8, pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if ((pcVar7->type & 0xf000) == 0x3000) {
            pcVar7->type = 0x1004;
          }
        }
      }
    }
    uVar1 = t->op;
    uVar9 = 0x1004;
    if (uVar1 == 0x17d) {
      uVar9 = 0x2004;
    }
    else {
      if (uVar1 == 0x1a0) {
        pcVar6 = ((t->u20).default_label)->next;
      }
      else {
        if (uVar1 != 0x1ab) goto LAB_1072d0c4;
        pcVar6 = (t->u20).default_label;
      }
      g_lower_ptr_types_depth = g_lower_ptr_types_depth + 1;
      lower_pointer_types_to_int(pcVar6);
      g_lower_ptr_types_depth = g_lower_ptr_types_depth + -1;
    }
LAB_1072d0c4:
    uVar4 = t->type & 0xf000;
    if (uVar4 == 0x3000) {
      t->type = uVar9;
    }
    else if (uVar4 == 0x4000) {
      g_floats_used = '\x01';
    }
    for (pcVar7 = t->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
      if (((pcVar7->type & 0xf000) == 0x3000) &&
         (pcVar7->type = uVar9, (1 << (pcVar7->kind & 0x1f) & 6U) != 0)) {
        sym = pcVar7->sym;
        if ((sym->type & 0xf000) == 0x3000) {
          sym->type = uVar9;
          sym->flags6 = sym->flags6 | 8;
        }
        else {
          iVar5 = types_compatible(sym->type,uVar9);
          if (iVar5 == 0) {
            sym = symbol_get_part(sym,uVar9,0,0);
            pcVar7->sym = sym;
          }
        }
      }
    }
    for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
      if ((pcVar7->type & 0xf000) == 0x3000) {
        if ((pcVar7->flags & 0x20) == 0) {
          pcVar7->type = uVar9;
          if ((1 << (pcVar7->kind & 0x1f) & 6U) != 0) {
            sym = pcVar7->sym;
            if ((sym->type & 0xf000) == 0x3000) {
              sym->type = uVar9;
              sym->flags6 = sym->flags6 | 8;
            }
            else {
              iVar5 = types_compatible(sym->type,uVar9);
              type = uVar9;
              if (iVar5 == 0) {
LAB_10784c0c:
                sym = symbol_get_part(sym,type,0,0);
                pcVar7->sym = sym;
              }
            }
          }
        }
        else {
          pcVar7->type = 0x1004;
          if ((1 << (pcVar7->kind & 0x1f) & 6U) != 0) {
            sym = pcVar7->sym;
            if ((sym->type & 0xf000) == 0x3000) {
              sym->type = 0x1004;
              sym->flags6 = sym->flags6 | 8;
            }
            else {
              iVar5 = types_compatible(sym->type,0x1004);
              if (iVar5 == 0) {
                type = 0x1004;
                goto LAB_10784c0c;
              }
            }
          }
        }
      }
    }
    first = local_8;
  } while (((g_opt_dlp == 0) || (first = local_8, t->op != 0x16d)) ||
          (first = local_8, ((uint)(t->u14).arg & 0x3ffff) == 0));
  pcVar6 = find_next_use_of_dst(t,&local_c);
  if (((local_c->type ^ g_ptr_type) & 0xfff) == 0) {
    if ((local_c->flags & 0x20) != 0) {
      pcVar7 = find_mem_operand_using(pcVar6,local_c,&local_4);
      cVar2 = t->u14;
      (t->u14).arg = (void *)0x0;
      pcVar7->sym = (c2_symbol *)cVar2;
      first = local_8;
      goto joined_r0x1072cfb7;
    }
    uVar1 = pcVar6->op;
    if (uVar1 == 0x16d) {
      pvVar3 = (t->u14).arg;
      (pcVar6->u14).arg = pvVar3;
      pcVar7 = pcVar6->src->next;
      if (pcVar7->kind == '\a') {
        uVar1 = (pcVar7->u18).lo;
        (t->u14).arg = (void *)0x0;
        (pcVar6->u14).arg =
             (void *)((uVar1 * 0x40000 + ((uint)pvVar3 & 0xfffc0000) ^ (uint)pvVar3) & 0x3ffc0000 ^
                     (uint)pvVar3);
        first = local_8;
        goto joined_r0x1072cfb7;
      }
    }
    else if (((uVar1 == 0x15a) || (uVar1 == 0x16c)) || (uVar1 == 0x15b)) {
      pcVar7 = operand_new_addr(0x14c,uVar9,(c2_symbol *)0x0,0,local_c,(c2_operand *)0x0);
      pcVar7->sym = (c2_symbol *)t->u14;
      pcVar7->base->type = uVar9;
      pcVar8 = tuple_new_unary_temp(0x15b,uVar9,pcVar7,tuple_insert_before,pcVar6);
      uVar9 = local_c->type;
      local_c = tuple_replace_src(pcVar6,local_c,pcVar8->dst);
      local_c->type = uVar9;
    }
  }
  (t->u14).arg = (void *)0x0;
  first = local_8;
  goto joined_r0x1072cfb7;
}


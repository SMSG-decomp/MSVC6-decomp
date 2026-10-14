c2_alias_call_effect * __fastcall
alias_attach_call_memory_effects
          (c2_block *first,c2_alias_call_effect *intrin_effects,uint32_t first_call_bit,
          c2_bitset *escaped,c2_bitset *in_scope,c2_symbol **syms,c2_bitset *excluded)

{
  uint16_t uVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  c2_bitset *dst;
  c2_symbol *pcVar3;
  c2_bitset *bs;
  c2_block **ppcVar4;
  c2_bitset *pcVar5;
  uint32_t uVar6;
  c2_operand *pcVar7;
  int iVar8;
  c2_symbol_cell *pcVar9;
  uint uVar10;
  c2_alias_call_effect *pcVar11;
  c2_symbol *pcVar12;
  uint32_t local_18;
  c2_alias_call_effect *local_10;
  c2_block *local_c;
  c2_symbol *part;
  c2_symbol *storage_sym;
  c2_list_cell *local_cell;
  
  pcVar11 = (c2_alias_call_effect *)0x0;
  local_10 = (c2_alias_call_effect *)0x0;
  local_18 = first_call_bit;
  local_c = first;
  if (first == (c2_block *)0x0) {
    return (c2_alias_call_effect *)0x0;
  }
  do {
    pcVar2 = local_c->end;
    dst = (local_c->avail_in).set;
    for (t = local_c->head; t != pcVar2; t = t->next) {
      if ((t->flags & 1) == 0) {
        if (t->kind == '\x16') {
          if (t->op == 0x1b4) {
            for (local_cell = (t->u14).scope_locals; local_cell != (c2_list_cell *)0x0;
                local_cell = local_cell->next) {
              storage_sym = ((local_cell->u04).sym)->storage;
              if ((storage_sym != (c2_symbol *)0x0) && ((storage_sym->u34).refs != 0)) {
                for (part = storage_sym->storage; part != (c2_symbol *)0x0; part = part->part_next)
                {
                  bitset_set(in_scope,(part->u34).refs);
                }
              }
            }
          }
          else if (t->op == 0x1b5) {
            for (local_cell = (c2_list_cell *)(t->u14).block; local_cell != (c2_list_cell *)0x0;
                local_cell = local_cell->next) {
              pcVar3 = ((local_cell->u04).sym)->storage;
              if ((pcVar3 != (c2_symbol *)0x0) && ((pcVar3->u34).refs != 0)) {
                for (pcVar3 = pcVar3->storage; pcVar3 != (c2_symbol *)0x0;
                    pcVar3 = pcVar3->part_next) {
                  bitset_clear(in_scope,(pcVar3->u34).refs);
                }
              }
            }
          }
        }
      }
      else {
        for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if (pcVar7->kind == '\x02') {
            uVar6 = (pcVar7->sym->u34).refs;
            if (uVar6 != 0) {
              bitset_set(dst,uVar6);
            }
          }
          else if (pcVar7->kind == '\x06') {
            bitset_or(dst,escaped);
          }
        }
        for (pcVar7 = t->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if (pcVar7->kind == '\x02') {
            pcVar3 = pcVar7->sym;
            uVar6 = (pcVar3->u34).refs;
            if (uVar6 != 0) {
              pcVar12 = pcVar3->storage;
              if (pcVar12 != (c2_symbol *)0x0) {
                iVar8 = pcVar3->offset;
                do {
                  if ((iVar8 <= pcVar12->offset) &&
                     (pcVar12->size + pcVar12->offset <= pcVar3->size + iVar8)) {
                    bitset_clear(dst,(pcVar12->u34).refs);
                  }
                  pcVar12 = pcVar12->part_next;
                } while (pcVar12 != (c2_symbol *)0x0);
              }
              bitset_set(dst,uVar6);
            }
          }
        }
        if (t->kind == '\x0e') {
          bitset_or(dst,escaped);
          pcVar5 = bitset_new(6);
          for (pcVar11 = intrin_effects; pcVar11 != (c2_alias_call_effect *)0x0;
              pcVar11 = pcVar11->next) {
            bs = pcVar11->live_across;
            uVar6 = bitset_test(bs,local_18);
            if (uVar6 != 0) {
              bitset_or(pcVar5,bs);
            }
          }
          bitset_and(pcVar5,dst);
          bitset_and(pcVar5,in_scope);
          bitset_andnot(pcVar5,excluded);
          if (pcVar5->chunks != (c2_bitset_chunk *)0x0) {
            pcVar11 = arena_alloc(4,0x14);
            pcVar7 = operand_new_memeffect(g_alias_class_count);
            tuple_append_src(t,pcVar7);
            pcVar11->cls = g_alias_class_count;
            g_alias_class_count = g_alias_class_count + 1;
            iVar8 = bitset_iter_next(pcVar5);
            while (iVar8 != -1) {
              pcVar3 = syms[iVar8]->storage;
              for (pcVar12 = pcVar3; pcVar12 != (c2_symbol *)0x0; pcVar12 = pcVar12->part_next) {
                pcVar12->flags5 = pcVar12->flags5 | 2;
              }
              pcVar9 = symbol_list_add_unique(pcVar11->members,pcVar3,1);
              pcVar11->members = pcVar9;
              iVar8 = bitset_iter_next((c2_bitset *)0x0);
            }
            pcVar11->next = local_10;
            local_10 = pcVar11;
          }
          bitset_free(pcVar5);
          local_18 = local_18 + 1;
        }
        else if (t->kind == '\x12') {
          bitset_or(dst,escaped);
          uVar1 = (t->u20).intrinsic.id;
          pcVar11 = intrin_effects;
          if ((uVar1 == 0xdb) || (uVar1 == 0x11e)) {
            for (; (pcVar11 != (c2_alias_call_effect *)0x0 && (pcVar11->intrin != t));
                pcVar11 = pcVar11->next) {
            }
            pcVar5 = bitset_clone(pcVar11->live_across);
            bitset_or(pcVar5,dst);
            if (pcVar5->chunks != (c2_bitset_chunk *)0x0) {
              pcVar7 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(t,pcVar7);
              pcVar11->cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              uVar10 = bitset_iter_next(pcVar5);
              while ((uVar10 != 0xffffffff && (uVar10 < first_call_bit))) {
                pcVar3 = syms[uVar10]->storage;
                pcVar9 = symbol_list_add_unique(pcVar11->members,pcVar3,1);
                uVar6 = (pcVar3->u34).refs;
                pcVar11->members = pcVar9;
                uVar6 = bitset_test(excluded,uVar6);
                if (uVar6 == 0) {
                  for (; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next) {
                    pcVar3->flags5 = pcVar3->flags5 | 2;
                  }
                }
                uVar10 = bitset_iter_next((c2_bitset *)0x0);
              }
            }
            bitset_free(pcVar5);
          }
        }
      }
      pcVar11 = local_10;
    }
    bitset_free(local_c->de);
    local_c->de = (c2_bitset *)0x0;
    bitset_free(local_c->ue);
    local_c->ue = (c2_bitset *)0x0;
    bitset_free(local_c->kill);
    local_c->kill = (c2_bitset *)0x0;
    bitset_free(dst);
    (local_c->avail_in).set = (c2_bitset *)0x0;
    bitset_free((local_c->avail_out).set);
    (local_c->avail_out).set = (c2_bitset *)0x0;
    bitset_free(local_c->live_in);
    local_c->live_in = (c2_bitset *)0x0;
    bitset_free(local_c->live_out);
    ppcVar4 = &local_c->next;
    local_c->live_out = (c2_bitset *)0x0;
    local_c = *ppcVar4;
  } while (*ppcVar4 != (c2_block *)0x0);
  return pcVar11;
}


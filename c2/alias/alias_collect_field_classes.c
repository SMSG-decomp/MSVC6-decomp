c2_bitset * __fastcall
alias_collect_field_classes(c2_tuple *first,uint32_t nbase_cls,uint32_t nsym_cls,int oa)

{
  byte bVar1;
  c2_symbol_cell *pcVar2;
  c2_bitvec *a;
  c2_alias_field_range *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_alias_field_range *pcVar6;
  c2_bitvec **ppcVar7;
  c2_symbol_cell **ppcVar8;
  c2_alias_field_range **ranges;
  c2_alias_field_range *range;
  c2_alias_class_canon *canon;
  uint32_t uVar9;
  c2_alias_field_class *field_classes;
  c2_bitset *bs;
  int iVar10;
  c2_alias_field_range *class_ranges;
  c2_bitset *bs_00;
  c2_alias_field_range *sibling;
  int32_t iVar11;
  uint32_t uVar12;
  uint32_t n;
  c2_alias_field_class *field;
  c2_symbol *pcVar13;
  uint32_t pass;
  uint32_t nrecords;
  uint32_t field_size;
  int field_offset;
  c2_bitset *written_classes;
  uint32_t local_c;
  uint32_t *canon_map;
  c2_tuple *local_4;
  c2_alias_class_canon *canon_scan;
  
  nrecords = 0;
  local_c = nbase_cls;
  local_4 = first;
  ranges = arena_alloc(4,nbase_cls * 4);
  written_classes = bitset_new(6);
  for (; canon_map = (uint32_t *)first, first != (c2_tuple *)0x0; first = first->next) {
    if ((first->flags & 1) != 0) {
      if (first->op == 0x16a) {
LAB_1072b5d3:
        if (((first->src->kind == '\x02') &&
            (pcVar13 = first->src->sym, pcVar13->def == (c2_tuple *)0x0)) &&
           ((pcVar13->cls != '\x03' ||
            ((pcVar13->def != (c2_tuple *)0x0 || ((pcVar13->flags7 & 4) == 0)))))) {
          for (pcVar13 = pcVar13->storage; pcVar13 != (c2_symbol *)0x0; pcVar13 = pcVar13->part_next
              ) {
            pcVar13->flags5 = pcVar13->flags5 | 2;
          }
        }
      }
      else if (first->op == 0x16b) {
        for (pcVar5 = first->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          if ((pcVar5->kind == '\x02') && (pcVar5->sym->def == (c2_tuple *)0x0)) {
            for (pcVar13 = pcVar5->sym->storage; pcVar13 != (c2_symbol *)0x0;
                pcVar13 = pcVar13->part_next) {
              pcVar13->flags5 = pcVar13->flags5 | 2;
            }
          }
        }
        goto LAB_1072b5d3;
      }
      if (nrecords < 0x400 - g_alias_class_count) {
        pass = 0;
        do {
          if (pass == 0) {
            pcVar5 = first->dst;
          }
          else {
            pcVar5 = first->src;
          }
          for (; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if ((((pcVar5->kind == '\x06') && ((pcVar5->u18).reg = (c2_symbol *)0x0, oa == 0)) &&
                (nsym_cls <= pcVar5->tag)) &&
               (((pcVar5->flags & 0x80) == 0 &&
                (iVar10 = memory_operand_field_range(pcVar5,&field_offset,&field_size), iVar10 != 0)
                ))) {
              uVar12 = pcVar5->tag;
              iVar10 = 0;
              pcVar3 = ranges[uVar12];
              range = pcVar3;
              if (pcVar3 == (c2_alias_field_range *)0x0) {
LAB_1072b71c:
                range = arena_alloc(4,0x10);
                range->offset = field_offset;
                range->next = pcVar3;
                range->size = field_size;
                ranges[uVar12] = range;
                nrecords = nrecords + 1;
              }
              else {
                do {
                  if ((range->offset == field_offset) && (range->size == field_size)) break;
                  range = range->next;
                  iVar10 = iVar10 + 1;
                } while (range != (c2_alias_field_range *)0x0);
                if (0x5f < iVar10) goto LAB_1072b633;
                if (range == (c2_alias_field_range *)0x0) goto LAB_1072b71c;
              }
              if (pass == 0) {
                bitset_set(written_classes,uVar12);
              }
            }
LAB_1072b633:
            first = (c2_tuple *)canon_map;
          }
          pass = pass + 1;
        } while (pass < 2);
      }
    }
  }
  uVar12 = 0;
  nrecords = 0;
  pass = 0;
  canon_map = arena_alloc(4,nbase_cls * 4);
  n = 1;
  if (1 < nbase_cls) {
    do {
      if ((n == g_alias_class_skip_index) && (n = nsym_cls, nbase_cls <= nsym_cls)) break;
      if (g_alias_class_symbol_sets[n] != (c2_bitvec *)0x0) {
        pcVar3 = ranges[n];
        if ((pcVar3 != (c2_alias_field_range *)0x0) && (pcVar3->next != (c2_alias_field_range *)0x0)
           ) {
          uVar9 = bitset_test(written_classes,n);
          if (uVar9 != 0) {
            for (; pcVar3 != (c2_alias_field_range *)0x0; pcVar3 = pcVar3->next) {
              uVar9 = nbase_cls + uVar12;
              uVar12 = uVar12 + 1;
              pcVar3->cls = uVar9;
              nrecords = uVar12;
            }
            goto LAB_1072b58c;
          }
          ranges[n] = (c2_alias_field_range *)0x0;
        }
        iVar11 = 0;
        if (oa != 0) {
          for (pcVar2 = g_alias_primary_table[n]; pcVar2 != (c2_symbol_cell *)0x0;
              pcVar2 = pcVar2->next) {
            if ((pcVar2->sym->cls == '\f') && (pcVar2->sym != g_alias_special_symbol)) {
              iVar11 = pcVar2->sym->offset;
              break;
            }
          }
        }
        a = g_alias_class_symbol_sets[n];
        for (canon_scan = (c2_alias_class_canon *)pass; uVar12 = nrecords,
            canon_scan != (c2_alias_class_canon *)0x0; canon_scan = canon_scan->next) {
          iVar10 = bitvec_equal(a,canon_scan->syms);
          ppcVar8 = g_alias_primary_table;
          if ((iVar10 != 0) && (iVar11 == canon_scan->scope)) {
            if (canon_scan != (c2_alias_class_canon *)0x0) {
              canon_map[n] = canon_scan->cls;
              ppcVar7 = g_alias_class_symbol_sets;
              ppcVar8[n] = (c2_symbol_cell *)0x0;
              ppcVar7[n] = (c2_bitvec *)0x0;
              nbase_cls = local_c;
              goto LAB_1072b58c;
            }
            break;
          }
        }
        canon = arena_alloc(4,0x10);
        canon->syms = a;
        canon->cls = n;
        canon->scope = iVar11;
        canon->next = (c2_alias_class_canon *)pass;
        nbase_cls = local_c;
        pass = (uint32_t)canon;
      }
LAB_1072b58c:
      n = n + 1;
    } while (n < nbase_cls);
  }
  bitset_free(written_classes);
  g_alias_class_max = (g_alias_class_count - 1) + uVar12;
  if (uVar12 == 0) {
    g_alias_secondary_records = (c2_alias_field_class *)0x0;
  }
  else {
    field_classes = arena_alloc(1,uVar12 * 0xc);
    pass = nsym_cls;
    written_classes = (c2_bitset *)0x0;
    g_alias_secondary_records = field_classes;
    if (nsym_cls < nbase_cls) {
      oa = (int)(ranges + nsym_cls);
      do {
        pcVar3 = *(c2_alias_field_range **)oa;
        if ((pcVar3 != (c2_alias_field_range *)0x0) && (pcVar3->next != (c2_alias_field_range *)0x0)
           ) {
          uVar12 = 0;
          pcVar6 = pcVar3;
          if (pcVar3 != (c2_alias_field_range *)0x0) {
            field = field_classes + (int)written_classes;
            sibling = pcVar3;
            do {
              field->parent = pass;
              if (0x1f < uVar12) {
                uVar12 = 0x1f;
              }
              sibling = sibling->next;
              field->bit = uVar12;
              uVar12 = uVar12 + 1;
              written_classes = (c2_bitset *)((int)&written_classes->chunks + 1);
              field = field + 1;
            } while (sibling != (c2_alias_field_range *)0x0);
          }
          for (; pcVar6 != (c2_alias_field_range *)0x0; pcVar6 = pcVar6->next) {
            if (pcVar3 != (c2_alias_field_range *)0x0) {
              iVar10 = pcVar6->offset;
              uVar12 = pcVar6->size;
              sibling = pcVar3;
              do {
                if ((sibling->offset < (int)(uVar12 + iVar10)) &&
                   (iVar10 < (int)(sibling->size + sibling->offset))) {
                  field_classes[pcVar6->cls - nbase_cls].overlap =
                       field_classes[pcVar6->cls - nbase_cls].overlap |
                       1 << ((byte)field_classes[sibling->cls - nbase_cls].bit & 0x1f);
                  nbase_cls = local_c;
                }
                sibling = sibling->next;
              } while (sibling != (c2_alias_field_range *)0x0);
            }
          }
        }
        pass = pass + 1;
        oa = oa + 4;
      } while (pass < nbase_cls);
    }
  }
  bs = bitset_new(6);
  g_alias_bitset_all = bitset_new(1);
  g_alias_bitset_symbols = bitset_new(1);
  g_alias_bitset_memory_classes = bitset_new(1);
  pcVar4 = local_4;
  do {
    if (pcVar4 == (c2_tuple *)0x0) {
      bitset_or(g_alias_bitset_all,g_alias_bitset_symbols);
      bitset_or(g_alias_bitset_all,g_alias_bitset_memory_classes);
      return bs;
    }
    if ((pcVar4->flags & 1) != 0) {
      pass = 0;
      do {
        if (pass == 0) {
          pcVar5 = pcVar4->dst;
        }
        else {
          pcVar5 = pcVar4->src;
        }
        for (; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          bVar1 = pcVar5->kind;
          if ((1 << (bVar1 & 0x1f) & 0xeU) == 0) {
            if (bVar1 == 6) {
              if ((ranges[pcVar5->tag] == (c2_alias_field_range *)0x0) ||
                 (ranges[pcVar5->tag]->next == (c2_alias_field_range *)0x0)) {
                if (canon_map[pcVar5->tag] != 0) {
                  pcVar5->tag = canon_map[pcVar5->tag];
                }
              }
              else {
                iVar10 = memory_operand_field_range(pcVar5,&field_offset,&field_size);
                if ((iVar10 != 0) &&
                   (class_ranges = ranges[pcVar5->tag], class_ranges != (c2_alias_field_range *)0x0)
                   ) {
                  do {
                    if ((class_ranges->offset == field_offset) && (class_ranges->size == field_size)
                       ) {
                      if (class_ranges == (c2_alias_field_range *)0x0) goto LAB_1072bada;
                      pcVar13 = (c2_symbol *)class_ranges->cls;
                      pcVar5->tag = (uint32_t)pcVar13;
                      goto LAB_1072badd;
                    }
                    class_ranges = class_ranges->next;
                  } while (class_ranges != (c2_alias_field_range *)0x0);
                  pcVar13 = (c2_symbol *)pcVar5->tag;
                  goto LAB_1072badd;
                }
              }
LAB_1072bada:
              pcVar13 = (c2_symbol *)pcVar5->tag;
            }
            else {
              if (bVar1 != 0xb) goto LAB_1072ba4e;
              if ((c2_symbol *)canon_map[(int)pcVar5->sym] != (c2_symbol *)0x0) {
                pcVar5->sym = (c2_symbol *)canon_map[(int)pcVar5->sym];
              }
              pcVar13 = pcVar5->sym;
            }
LAB_1072badd:
            bitset_set(bs,(uint32_t)pcVar13);
            bs_00 = g_alias_bitset_memory_classes;
LAB_1072baee:
            bitset_set(bs_00,(uint32_t)pcVar13);
          }
          else {
            pcVar13 = pcVar5->sym->storage;
            if (((pcVar13->cls == '\a') || (pcVar13->cls == '\b')) || ((pcVar13->flags5 & 2) != 0))
            {
              pcVar13 = (c2_symbol *)(uint)(pcVar13->fe->u3e).alias_class;
              bitset_set(bs,(uint32_t)pcVar13);
              bs_00 = g_alias_bitset_symbols;
              goto LAB_1072baee;
            }
          }
LAB_1072ba4e:
        }
        pass = pass + 1;
      } while (pass < 2);
    }
    pcVar4 = pcVar4->next;
  } while( true );
}


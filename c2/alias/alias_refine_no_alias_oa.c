uint32_t __fastcall alias_refine_no_alias_oa(uint32_t nrefs)

{
  uint uVar1;
  uint8_t uVar2;
  c2_copy_link *pcVar3;
  c2_symbol *pcVar4;
  c2_alias_ref *new_refs;
  c2_bitset *bs;
  c2_symbol_cell *pointee_cell;
  uint uVar5;
  int iVar6;
  c2_symbol *chunk_sym;
  c2_alias_ref *row;
  c2_alias_ref *pcVar7;
  uint32_t node;
  c2_symbol_chunk *chunk;
  
  uVar1 = g_alias_symbol_number_count + nrefs;
  new_refs = arena_alloc(4,uVar1 * 0x14);
  row = g_alias_ref_table;
  pcVar7 = new_refs;
  g_alias_ref_table = new_refs;
  for (uVar5 = nrefs * 5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    pcVar7->sym = row->sym;
    row = (c2_alias_ref *)&row->pointees;
    pcVar7 = (c2_alias_ref *)&pcVar7->pointees;
  }
  for (iVar6 = 0; chunk = g_symbol_chunks, iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)&pcVar7->sym = *(undefined1 *)&row->sym;
    row = (c2_alias_ref *)((int)&row->sym + 1);
    pcVar7 = (c2_alias_ref *)((int)&pcVar7->sym + 1);
  }
  for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_sym = chunk->syms;
    if (chunk_sym < chunk->cursor) {
      do {
        uVar2 = chunk_sym->cls;
        if (uVar2 != '\x10') {
          if (((chunk_sym->flags5 & 2) == 0) &&
             (((uVar2 == '\x04' || (uVar2 == '\x05')) ||
              ((uVar2 == '\x03' && (chunk_sym->def == (c2_tuple *)0x0)))))) {
            pcVar4 = ((chunk_sym->u30).alias_info)->fields;
            if (pcVar4 != (c2_symbol *)0x0) {
              pcVar4 = pcVar4->part_next;
              iVar6 = bitset_iter_next(((chunk_sym->u30).alias_info)->ref_nodes);
              while (iVar6 != -1) {
                pointee_cell = symbol_list_add_unique(new_refs[iVar6].pointees,pcVar4,4);
                new_refs[iVar6].pointees = pointee_cell;
                iVar6 = bitset_iter_next((c2_bitset *)0x0);
              }
              for (pcVar4 = ((chunk_sym->u30).order_prev)->part_next; pcVar4 != (c2_symbol *)0x0;
                  pcVar4 = pcVar4->part_next) {
                alias_flatten_field_classes(pcVar4);
              }
            }
          }
          else if ((chunk_sym->storage == chunk_sym) && ((chunk_sym->u34).refs != 0)) {
            alias_flatten_field_classes(chunk_sym);
          }
        }
        chunk_sym = chunk_sym + 1;
      } while (chunk_sym < chunk->cursor);
    }
  }
  node = 1;
  row = new_refs;
  if (1 < uVar1) {
    do {
      if ((node != nrefs) && (chunk_sym = row[1].sym, chunk_sym != (c2_symbol *)0x0)) {
        for (chunk_sym = ((chunk_sym->u30).order_prev)->part_next; chunk_sym != (c2_symbol *)0x0;
            chunk_sym = chunk_sym->part_next) {
          iVar6 = (int)&((chunk_sym->u34).source_links)->next_of_source + nrefs;
          bs = new_refs[iVar6].pointee_nodes;
          if (row[1].pointee_nodes != (c2_bitset *)0x0) {
            if (bs == (c2_bitset *)0x0) {
              bs = bitset_new(6);
              new_refs[iVar6].pointee_nodes = bs;
            }
            iVar6 = bitset_iter_next(row[1].pointee_nodes);
            while (iVar6 != -1) {
              pcVar4 = (((new_refs[iVar6].sym)->u30).order_prev)->part_next;
              if (pcVar4 != (c2_symbol *)0x0) {
                bitset_set(bs,(int)&((pcVar4->part_next->u34).source_links)->next_of_source + nrefs)
                ;
              }
              iVar6 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
          if (row[1].pointees != (c2_symbol_cell *)0x0) {
            if (bs == (c2_bitset *)0x0) {
              bs = bitset_new(6);
              new_refs[(int)&((chunk_sym->u34).source_links)->next_of_source + nrefs].pointee_nodes
                   = bs;
            }
            for (pointee_cell = row[1].pointees; pointee_cell != (c2_symbol_cell *)0x0;
                pointee_cell = pointee_cell->next) {
              pcVar3 = (pointee_cell->sym->u34).source_links;
              if (pcVar3 != (c2_copy_link *)0x0) {
                bitset_set(bs,(int)&pcVar3->next_of_source + nrefs);
              }
            }
          }
        }
      }
      node = node + 1;
      row = row + 1;
    } while (node < uVar1);
  }
  return uVar1;
}

